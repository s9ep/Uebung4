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
    
    
    Alignment& operator = (const Alignment& a);
    bool operator == (Alignment a);
    void print (std::ostream& os = std::cout);
    void setSequence1 (const Sequence& seq);
    void setSequence2 (const Sequence& seq);
    const Sequence& getSequence1() const;
    const Sequence& getSequence2() const;
    
    void computeGlobalAlignmnet();
    const std::pair<std::string, std::string>& getAlginment () const;
    
private:
    Distance distance_;
    Sequence seq1_; // Sequence1
    Sequence seq2_; // Sequence2
    
    
    
};
