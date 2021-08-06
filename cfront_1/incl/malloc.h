/* @(#) malloc.h 1.3 2/16/87 11:02:21 */
/*ident	"@(#)cfront:incl/malloc.h	1.3"*/

#ifndef MALLOCH
#define MALLOCH

/*
	Constants defining mallopt operations
*/
#define M_MXFAST	1	/* set size of blocks to be fast */
#define M_NLBLKS	2	/* set number of block in a holding block */
#define M_GRAIN		3	/* set number of sizes mapped to one, for
				   small blocks */
#define M_KEEP		4	/* retain contents of block after a free until
				   another allocation */
/*
	structure filled by 
*/
struct mallinfo  {
	int arena;	/* total space in arena */
	int ordblks;	/* number of ordinary blocks */
	int smblks;	/* number of small blocks */
	int hblks;	/* number of holding blocks */
	int hblkhd;	/* space in holding block headers */
	int usmblks;	/* space in small blocks in use */
	int fsmblks;	/* space in free small blocks */
	int uordblks;	/* space in ordinary blocks in use */
	int fordblks;	/* space in free ordinary blocks */
	int keepcost;	/* cost of enabling keep option */
};	

extern char *malloc(unsigned);
extern void free(char*);
extern char *realloc(char*, unsigned);
extern int mallopt(int, int);
extern mallinfo mallinfo(int);
extern char *calloc (unsigned, unsigned);

#endif
