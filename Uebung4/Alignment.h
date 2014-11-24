//
//  Alignment.h
//  
//
//  Created by Eva on 23.11.14.
//
//

#ifndef ____Alignment__
#define ____Alignment__

#include <stdio.h>
#include <iostream>     // std::cout, std::ostream, std::ios
#include "Sequence.h"
#endif /* defined(____Alignment__) */



class EditDistance

{
public:
    float operator() (char a, char b) const;
};

template <typename Distance>

class Alignment
{
public:
    Alignment ();
    Alignment (const Sequence& seq1, const Sequence& seq2);
    Alignment (const Alignment& a);
    virtual  ~ Alignment();
    
    // operator=
    Alignment& operator = (const Alignment& a);
    // operator ==
    bool operator == (Alignment a);
    // print 
    void print (std::ostream& os = std::cout);
    //setter
    void setSequence1 (const Sequence& seq);
    void setSequence2 (const Sequence& seq);
    //getter
    const Sequence& getSequence1() const{
        return seq1_;
    }
    const Sequence& getSequence2() const{
        return seq2_;
    }
    // TODO
    void computeGlobalAlignmnet();
    
    // getAlginment
    const std::pair<std::string, std::string>& getAlginment () const{
        return myalignment;
    }
    
private:
    Distance distance_;
    Sequence seq1_; // Sequence1
    Sequence seq2_; // Sequence2
    std::pair<std::string, std::string> myalignment;
    
    
};
