//
//  Alignment.cpp
//  
//
//  Created by Eva on 23.11.14.
//
//

#include "Alignment.h"
#include "Sequence.h"

// Constructors
template <typename Distance> Alignment<Distance>::Alignment(){
}

template <typename Distance> Alignment<Distance>::Alignment(const Sequence& seq1, const Sequence& seq2):seq1_(seq1_),seq2_(seq2_){
}

template <typename Distance> Alignment<Distance>::Alignment(const Alignment& a){
    seq1_=a.getSequence1();
    seq2_=a.getSequence2();
}


// Destructor
template <typename Distance> Alignment<Distance>::~Alignment()
{
}

// operator=
template <typename Distance> Alignment<Distance>& Alignment<Distance>::operator=(const Alignment<Distance>& a){
    setSequence1(a.getSequence1());
    setSequence1(a.getSequence2());
    // TODO
}

// operator ==, checks if the sequences are equal
template <typename Distance> bool Alignment<Distance>::operator==(const Alignment<Distance> a)
{
    return (seq1_==a.getSequence1() && seq2_==a.getSequence2());
}

//print
template <typename DIST> void Alignment<DIST>::print (std::ostream& os){
    // TODO
}


// set Sequence1
template <typename Distance> void Alignment<Distance>:: Alignment::setSequence1 (const Sequence& seq){
    seq1_=seq;
}

// set Sequence2
template <typename Distance> void Alignment<Distance>:: Alignment::setSequence2 (const Sequence& seq){
    seq2_=seq;
}


//getSequence1() --> Alignment.h
//getSequence2() --> Alignment.h

