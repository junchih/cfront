/* 
Path: sfsup!ulysses!att!alberta!ubc-cs!uw-beaver!mit-eddie!rutgers!bellcore!texbell!killer!convex!iex!ntvax!yang1
From: yang1@ntvax.UUCP (cqyang class)
Newsgroups: comp.lang.c++
Subject: Bug in AT&T C++ compilier ?
Keywords: C++, tasking, bugs
Message-ID: <416@ntvax.UUCP>
Date: 29 Mar 89 19:07:13 GMT
Organization: University of North Texas
Lines: 56



Is this a bug or what?
I am having a problem with the AT&T C++ compilier using its tasking
facility. I am writting a program that implements various algorithms
of the n-queens problem, and am using the tasking facility to create
a number 'taks'. There seems to be a problem that when the tasks complete,
there is still somethinf left over on the stack. The following is a 
program that may help figure out what the compilier's (or my) problem
is. This program should loop forever, but abends after some 48,800
times. It says there has been a stack overflow and dumps some 6.2
megabytes of core. Am I doing something wrong ?
*/

#include <stdio.h>
#include <task.h>

#define  QUEENS 8
#define  QUEENS_M_1 (QUEENS - 1)

   
class Player : task 
{ private :
  static int ply_taks;
  public :
  Player(int Row, int Col);
  char players_piece;
  t_inc() { return(++ply_taks); }
};


Player::Player(int Row, int Col)
{ register int i, j;

  if(Col) Col++;

  resultis(0);
}

main()
{ Player *Aplayer;
  int i, j;

  printf("\nmain: start the players running\n");
  for(i=0;;i++) {
	printf("%d\n", i);
	Aplayer = new Player(i,i);
        j = Aplayer->Player::result(); }

  exit(0);
}
/*

***************************************************************************
*       Jim Stinson             yang1@dept.csci.unt.edu                   *
*       University of                                                     *
*       North Texas                                                       *
***************************************************************************
*/
/*
Path: sfsup!ulysses!att!osu-cis!tut.cis.ohio-state.edu!unmvax!pprg.unm.edu!hc!ames!pasteur!ucbvax!decwrl!decvax!eagle_snax!mrmarx!gra
From: gra@mrmarx.east.sun.com (Gary R. Adams)
Newsgroups: comp.lang.c++
Subject: Re: Bug in AT&T C++ compilier ?
Keywords: C++, tasking, bugs
Message-ID: <509@eagle_snax.UUCP>
Date: 5 Apr 89 17:53:55 GMT
Sender: news@eagle_snax.UUCP
Reply-To: gra@mrmarx.UUCP (Gary R. Adams)
Organization: Sun Microsystems, Billerica MA
Lines: 53
*/


/*

> Is this a bug or what?

 Looks like a bug to me .

> I am having a problem with the AT&T C++ compilier using its tasking
> facility. I am writting a program that implements various algorithms
> of the n-queens problem, and am using the tasking facility to create
> a number 'taks'. There seems to be a problem that when the tasks complete,
> there is still somethinf left over on the stack. The following is a 
> program that may help figure out what the compilier's (or my) problem
> is. This program should loop forever, but abends after some 48,800
 
 Must have been a 4Meg machine, it fails at 8Meg for me.

> times. It says there has been a stack overflow and dumps some 6.2

 My machine gracefully complains forever about not having the memory needed
 to construct the nth task.

> megabytes of core. Am I doing something wrong ?
> 
	.....

>   for(i=0;;i++) {
> 	printf("%d\n", i);
> 	Aplayer = new Player(i,i);
>         j = Aplayer->Player::result(); }
>    }
> 

  You may have stripped down your example a bit too far, because it's
  not clear what you actually intended to do with this program. My guess
  is that you wanted the task object to be removed as part of the result()
  processing. I can not find any reference to that capability in either
  the documentation for "task" or "sched". Since the task is explicitly
  created using the "new" operator, I believe it must be removed explicitly
  using delete. e.g. malloc/free.

  I added the folowing line inside the loop and it runs forever:

        delete Aplayer;

> ***************************************************************************
> *       Jim Stinson             yang1@dept.csci.unt.edu                   *
> *       University of                                                     *
> *       North Texas                                                       *
> ***************************************************************************
> 
Gary R. Adams                           sun!suneast!mrmarx!gra
Window Systems & Applications           (508) 671-0416 "... it only takes a 
Entry Systems Software                  sparc to get a fire going ..."
*/


