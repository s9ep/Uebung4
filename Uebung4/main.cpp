//
//  main.cpp
//  testtest
//
//  Created by Solveig Andres on 24.11.14.
//  Copyright (c) 2014 Solveig Andres, Eva Maria Paul. All rights reserved.
//

#include <iostream>
#include "Alignment.h"
#include "NucleicAcid.h"
#include "Sequence.h"
#include <assert.h>


int main(int argc, const char * argv[]) {
    const Sequence seq1("ATG");
    const Sequence seq2("AAG");
    const Sequence seq3("ACG");

    // Tests
    // check constructor
    /* Alignment myalign(seq1,seq2);
     Alignment myalign2(seq1,seq2);
    Alignment myalign3(seq1,seq3);
    
   // check == operator
    assert(myalign==myalign2);
    //check = operat0r
    //myalign3 = myalign;
   // assert(myalign3==myalign);
    //check setter & getter
    myalign2.setSequence1(seq2);
    Sequence dummy_seq1 = myalign2.getSequence1();
    assert(dummy_seq1==seq2);
    myalign2.setSequence2(seq3);
    Sequence dummy_seq2 = myalign2.getSequence2();
    assert(dummy_seq2==seq3);*/

    return 0;

    
}
