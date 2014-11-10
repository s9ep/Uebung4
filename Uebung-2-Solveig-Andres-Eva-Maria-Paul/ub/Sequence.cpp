#include "Sequence.h"
#include <string.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>



// Default constructor
Sequence::Sequence(){
}


//Copy Constructor
Sequence::Sequence(const Sequence& seq){
    sequence_ = seq.sequence_;
}

//Detailed Constructor
Sequence::Sequence(const std::string& seq){
    sequence_ = seq;
}

//Destructor
Sequence::~ Sequence (){
    
}


//operator "="
Sequence& Sequence::operator=(const Sequence& seq)
{
    sequence_ = seq.sequence_;
    return *this;
}

//operator "=="
bool Sequence::operator==(const Sequence& seq) const
{
    return sequence_ == seq.sequence_;
}

//operator "!="
bool Sequence::operator!=(const Sequence& seq) const
{
    return !(*this == seq);
}

//operator "<<"
std::ostream& operator<<(std::ostream& ostr, const Sequence& seq)
{
    ostr << seq.sequence_ << ' ';
    return ostr;
}

//operator ">>"
std::istream& operator>>(std::istream& istr, Sequence& seq)
{
    if (istr.good()){
        char first = istr.get(); //first char
        if (!isspace(first)){ //space
            //       istr.putback(c);
            istr >> seq.sequence_;
            first = istr.peek(); //Returns the next character in the input sequence, without extracting it: The character is left as the next character to be extracted from the stream.
            if (istr.good() && isspace(first)){
                first = istr.get();
            }
            return istr;
        }
    }
    return istr;
}



// COMPARE
bool Sequence::compare(const Sequence& seq, unsigned int i) const {
    
    // startpoint
    int begin = sequence_.length()-i;
    
    // empty sequence
    if (begin <1) {
        return false;
    }
    else {
        if ( memcmp(sequence_.c_str() + i, seq.sequence_.c_str(), begin) == 0)
        { return true;}
        else
        {return false;}
    }
}

//OVERLAP
unsigned int Sequence::overlap(const Sequence& seq) const{
    unsigned int max=0;
    // Empty seq
    if (seq.sequence_.length()==0) {
        return max;
    }
    
    // Empty sequence_
    if (sequence_.length()==0) {
        return max;
    }
    // Same length, just compare
    if (compare(seq,0)) {
        return seq.sequence_.length();
    }
    
    unsigned int position_sequence_=sequence_.length()-1;
    unsigned int position_seq =0;
    
    
    return 0;
}





