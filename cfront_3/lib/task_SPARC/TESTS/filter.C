#include <stdio.h>
#include <task.h>
#include <string.h>
#include <stdlib.h>

/*
 * filter.C
 * Builds on example in "More About Queues:  Cutting and Splicing"
 * section of Stroustrup/Shopiro coroutine memo, Release Notes pp 13-13 - 13-14.
 * Demonstrates "fairly static" use of filters, creating 3 tasks:
 * Producer produces lines, Consumer consumes words, and Line_to_Word
 * converts lines to words.  Requires filter.in file to provide lines
 * for Producer.
 */

const int MAXLEN = 512;

class Word : public object
{
	char	word[MAXLEN];
public:
		Word(char *);
	void	print(int =0, int =0);
};

Word::Word(char *w) {
	(void) strcpy(word, w);
//	printf("Word::Word:\n");
//	this->print();
}
void
Word::print(int i, int j)
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
	Word	*next_word();
	void	print(int =0, int =0);
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
Line::print(int i, int j)
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
	if ((fp = fopen("filter.in", "r")) == NULL) {
		printf("filter:  Cannot open file filter.in.\n");
		exit(0);
	}
	while ((cp = fgets(tmpline, MAXLEN, fp)) != NULL) {
		l = new Line(tmpline);
//		printf("Producer::Producer():  about to put line %x on qtail %x\n", l, qt);
		qt->put( (object *) l);
	}
	//SAK:  cycle6.1, thistask expanded to this_task() but NOT inlined!
	thistask->resultis(0);
}

class Consumer : public task	// consume words
{
public:
		Consumer(qhead *, char *); };

Consumer::Consumer(qhead *qh, char *n) : task(n)
{
	Word	*w;
	for(;;)	{
		w = (Word *) qh->get();
//		printf("Consumer::Consumer():\n");
//SAK:  default args not picked up for some reason.
//SAK:		w->print();
		w->print(0,0);
	}
	//SAK:  cycle6.1, thistask expanded to this_task() but NOT inlined!
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
		while (w = l->next_word()) {
//			printf("%s:\tabout to put word %x on qtail %x\n", n, w, out_q);
//			w->print();
			out_q->put((object *) w);
		}
	}
	//SAK:  cycle6.1, thistask expanded to this_task() but NOT inlined!
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
	//SAK:  this task expanded to this_task() and properly inlined
	thistask->resultis(0);
}
