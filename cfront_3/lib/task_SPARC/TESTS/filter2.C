#include <stdio.h>
#include <task.h>
#include <string.h>
#include <stdlib.h>

/*
 * filter2.C
 * Builds on example in "More About Queues:  Cutting and Splicing"
 * section of Stroustrup/Shopiro coroutine memo, Release Notes pp 13-13 - 13-14.
 * Builds on filter.C, but shows a more dynamic use of filters,
 * using "qtail::cut" and "qtail::splice".
 * Producer produces lines, Consumer consumes words, and Line_to_Word
 * converts lines to words.  When Line_to_Word task recognizes a macro,
 * it creates a Macro filter task and diverts its output to a new qtail
 * which macro takes as input, and it puts its massaged output to the
 * old qtail.
 * Requires filter2.in file to provide lines for Producer.
 */

const int MAXLEN = 512;

class Word : public object
{
	char	word[MAXLEN];
public:
		Word(char *);
	char*	get_word()	{ return word; }
	void	print();
};

Word::Word(char *w) {
	(void) strcpy(word, w);
//	printf("Word::Word:\n");
//	this->print();
}
void
Word::print()
{
//	printf("\tWord %x: %s\n", this, word);
	printf("%s\n", word);
}

class Line : public object
{
	char	line[MAXLEN];
	char	*begin;
public:
		Line(char *l);
	char	*get_line()	{ return line; }
	Word	*next_word();
	void	print();
};

Line::Line(char *l)
{
	(void) strcpy(line, l);
	begin = line;
//	printf("Line::Line():");
//	this->print();
}

/* Modifies this Line by moving the begin pointer
 * to point at next non-whitespace character.
 */
Word *
Line::next_word()
{
	char	tmpword[MAXLEN];
	char	*wp = tmpword;
	Word	*w;
	if (begin == NULL) {	// no more words in line
		return 0;
	}
//	printf("Line::next_word:");
//	this->print();
	for (;;) {
		*wp = *begin;
		switch(*wp) {
		case ' ':
		case '\t':
			*wp = '\0';
			// leave begin pointing at next non-whitespace char
			// SAK: ws at end of line will be a problem
			while( (*begin == ' ') || (*begin == '\t') ) {
				begin++;
			}
			w = new Word(tmpword);
//			printf("Line::next_word:\tabout to return Word %x\n", w);
//			w->print();
			return w;
		case '\n':	/* fgets doesn't discard \n; gets does */
		case '\0':	/* end of Line */
			*wp = '\0';
			begin = NULL;
			w = new Word(tmpword);
//			printf("Line::next_word:\tabout to return Word %x\n", w);
//			w->print();
			return w;
			break;
		default:
			begin++;
			wp++;
			break;
		}
	}
}

void
Line::print()
{
	printf("\tLine %x:\t%s\n", this, line);
	printf("\t\t\tbegin: %s\n", begin);
}

class Producer : public task	// produce lines
{
public:
		Producer(qtail *, char *);
};

Producer::Producer(qtail *qt, char *n) : task(n)
{
	FILE	*fp;
	Line	*l;
	char	tmpline[MAXLEN];
	char	*cp;
//	printf("Producer::Producer():	type in lines of characters,\n");
//	printf("			end with a ^D on a line by itself\n");
	if ((fp = fopen("filter2.in", "r")) == NULL) {
		printf("filter:  Cannot open file filter2.in.\n");
		exit(0);
	}
	while ((cp = fgets(tmpline, MAXLEN, fp)) != NULL) {
		l = new Line(tmpline);
//		printf("Producer::Producer():  about to put line %x on qtail %x\n", l, qt);
		qt->put( (object *) l);
	}
	thistask->resultis(0);
}

class Consumer : public task	// consume words
{
public:
		Consumer(qhead *, char *);
};

Consumer::Consumer(qhead *qh, char *n) : task(n)
{
	Word	*w;
	for(;;)	{
		w = (Word *) qh->get();
//		printf("Consumer::Consumer():\n");
		w->Word::print();
	}
	thistask->resultis(0);
}

char * macB_str = "MACRO_B";
char * macP_str = "MACRO_P";
class Macro : private task
{
public:
		Macro(char *, qhead *, qtail *);
};

Macro::Macro(char * name, qhead *inq, qtail *outq) : task(name)
{
	Word *w;
	Word *bold = new Word("\\fB");
	Word *prev = new Word("\\fP");
	int i;
	printf("Macro %s created\n", name);
	for(;;) {
		w = (Word *) inq->get();
		if ((i = strncmp(w->get_word(), macP_str, 7)) == 0) {
			// time to go
			outq->splice(inq);
			cancel(0);
			delete this;
		}
		i = strlen(w->get_word());
		char *tmpword = new char[i+7];
		strcat(tmpword, bold->get_word());
		strcat(tmpword, w->get_word());
		strcat(tmpword, prev->get_word());
		Word *outword = new Word(tmpword);
		outq->put((object *)outword);
	}
	thistask->resultis(0);
}

class Line_to_Word : private task
{
public:
		Line_to_Word(qhead *, qtail *, char *);
//	Word	*next_word(Line *);
};

Line_to_Word::Line_to_Word(qhead *in_q, qtail *out_q, char *n) : task(n)
{
	Line	*l;
	Word	*w;
	for(;;) {
		l = (Line *) in_q->get();
//		printf("%s:\tgot line %x from qhead %x\n", n, l, in_q);
		char *cp = l->get_line();
//		printf("line is %s\n", cp);
		int i;
		if ((i = strncmp(cp, macB_str, 7)) == 0) {
			qtail* new_qtp = out_q->cut();
			qhead* new_qhp = out_q->head();
			printf("Line_to_Word: about to create macro_task\n");
			Macro* macro_task = new Macro("macro_task", new_qhp, new_qtp);
		} else {
			while (w = l->next_word()) {
//				printf("%s:\tabout to put word %x on qtail %x\n", n, w, out_q);
//				w->print();
				out_q->put((object *) w);
			}
		}
	}
	thistask->resultis(0);
}

main()
{
//printf("main:\n");
	qhead		*line_q = new qhead(WMODE, 5);
	qtail		*line_qt = line_q->tail();
//printf("\tqhead line_q is %x, line_qt is %x\n", line_q, line_qt);
	qtail		*word_q = new qtail(WMODE, 15);
	qhead		*word_qh = word_q->head();
//printf("\tqtail word_q is %x, word_qh is %x\n", word_q, word_qh);
	//Producer	*prod = new Producer(line_q->tail(), "prod");
	Producer	*prod = new Producer(line_qt, "prod");
	//Consumer	*cons = new Consumer(word_q->head(), "cons");
	Consumer	*cons = new Consumer(word_qh, "cons");
	Line_to_Word	*filt = new Line_to_Word(line_q, word_q, "filt");
//printf("main: done\n");
	thistask->resultis(0);
}
