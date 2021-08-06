#include <task.h>

/*
 * airport.C
 * From draft Dewhurst/Stark C++ Programming book, proprietary.
 * Simulates air traffic control at an airport.
 * Creates three tasks:  Airport, AirControl, and GroundControl,
 * uses random numbers, delays, queues.
 */

class Plane : object {
	static int fltcount;
	long start;
	int fltno;
    public:
	Plane() { fltno = ++fltcount; }
	long howlong() { return clock - start; }
	void set() { start = clock; }
	int flt() { return fltno; }
};

class PlaneQ {
	qhead *head;
	qtail *tail;
    public:
	PlaneQ() {  head = new qhead( ZMODE, 50 ); tail = head->tail(); }
	void put( Plane * p ) { p->set(); tail->put( (object*)p ); }
	Plane *get() { return (Plane *)head->get(); }
	int isroom() { return tail->rdspace(); }
	int notempty() { return head->rdcount(); }
};

class AirControl : public task  {
	PlaneQ  *landing, *inair;
    public:
	AirControl( PlaneQ *, PlaneQ * );
};

class GroundControl : public task {
	PlaneQ *takingoff, *onground;
    public:
	GroundControl( PlaneQ*, PlaneQ* );
};

class Airport : public task {
	PlaneQ  *takingoff, *landing, *inair, *onground; 
	AirControl *acontrol;
	GroundControl *gcontrol;
    public:
	Airport();
	~Airport();
};

Airport::Airport() {

	takingoff = new PlaneQ;
	inair = new PlaneQ;
	landing = new PlaneQ;
	onground = new PlaneQ;

	acontrol = new AirControl( landing, inair );
	gcontrol = new GroundControl( takingoff, onground );

	Plane *tp=0, *lp=0;

	int maxwait = 30;

	for(;;){
	    delay( 10 );
	    if( !lp ) lp = landing->get();
	    if( !tp ) tp = takingoff->get();
	    if( lp ){
		if( onground->isroom() ) {
		    printf( "flight %d landing \n" , lp ->flt());
		    onground->put( lp );
		    lp = 0;
		}
		else if( lp->howlong() > maxwait ) {
		    printf( "flight %d crash landing!\n", lp ->flt());
		    delete lp;
		    lp = 0;
		}
		else
		    printf( "flight %d landing delayed \n", lp ->flt());
		}
	    if( tp ) {
		if( inair->isroom() ) {
		    printf( "flight %d taking off\n", tp ->flt());
		    inair->put( tp );
		    tp = 0;
		}
		else
		    printf( "flight %d take off delayed \n", lp ->flt());
	    }
	}
}

Airport::~Airport() {
	acontrol->cancel(0);
	while( landing->notempty() ) thistask->delay( 10 );
	gcontrol->cancel(0);
	printf("Airport Closed\n");
	cancel(0);
}

AirControl::AirControl( PlaneQ *landing, PlaneQ *inair ) {

	urand n( 1, 30 );

	for(;;){
	    delay( n.draw() );

	    Plane *p = inair->get();
	    if( !p ) {
		p = new Plane;
	    }

	    if( landing->isroom() ) {
		printf ("flight %d arriving for landing\n", p->flt() );
		landing->put( p );
	    }
	    else {
		printf ("flight %d redirected\n", p->flt() );
		delete p;
	    }
	}
}

GroundControl::GroundControl( PlaneQ *takingoff, PlaneQ *onground ) { 

	urand n( 10, 30 );
	Plane *p = 0;

	for(;;){
		delay( n.draw() );
		if( !p ) p = onground->get();
		if( p ) {
		    if( takingoff->isroom() ) {
			printf ("flight %d leaving gate\n", p->flt() );
			takingoff->put( p );
			p = 0;
		    }
		    else
			printf ("flight %d delayed at gate\n", p->flt() );
		}
	}
}

main() {
	Airport *ap = new Airport;
	thistask->delay( 5000 );
	delete ap;
	thistask->resultis(0);
}

