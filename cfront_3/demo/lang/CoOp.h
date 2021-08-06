/*ident	"@(#)cls4:demo/lang/CoOp.h	1.1" */
/*#########################################################################
#                       Copyright (c) 1989 AT&T
#                         All Rights Reserved   
#
#                THIS IS PROPRIETARY SOURCE CODE OF AT&T
#       
#                     This code has been published in
#                      C++ Primer by Stanley Lippman
#                    Addison_Wesley Publishing Company
#
#########################################################################*/
#ifndef COOP_H
#define COOP_H

class CoOp {
public:
    CoOp( int, char* );
    double monthlyMaint();
    static void raiseCost(double incr);
    static double getCost() { return costPerShare; }
private:
    static double costPerShare;
    int shares;
    char *owner;
};

#endif
