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
template <typename EditDistance> Alignment<EditDistance>::Alignment(){
}

template <typename EditDistance> Alignment<EditDistance>::Alignment(const Sequence& seq1, const Sequence& seq2):seq1_(seq1_),seq2_(seq2_){
}

template <typename EditDistance> Alignment<EditDistance>::Alignment(const Alignment& a){
    seq1_=a.getSequence1();
    seq2_=a.getSequence2();
}


// Destructor
template <typename EditDistance> Alignment<EditDistance>::~Alignment()
{
}

// operator=
template <typename EditDistance> Alignment<EditDistance>& Alignment<EditDistance>::operator=(const Alignment<EditDistance>& a){
    setSequence1(a.getSequence1());
    setSequence1(a.getSequence2());
    // TODO
}

// operator ==, checks if the sequences are equal
template <typename EditDistance> bool Alignment<EditDistance>::operator==(const Alignment<EditDistance> a)
{
    return (seq1_==a.getSequence1() && seq2_==a.getSequence2());
}

//print
template <typename EditDistance> void Alignment<EditDistance>::print (std::ostream& os){
    os << myalignment.first<< "," << myalignment.second << "\n";
}


// set Sequence1
template <typename EditDistance> void Alignment<EditDistance>:: Alignment::setSequence1 (const Sequence& seq){
    seq1_=seq;
}

// set Sequence2
template <typename EditDistance> void Alignment<EditDistance>:: Alignment::setSequence2 (const Sequence& seq){
    seq2_=seq;
}


//getSequence1() --> Alignment.h
//getSequence2() --> Alignment.h
//getAlignment() --> ALignment.h

