#include "Sequence.h"
#include <string.h>
#include <iostream>
#include <string>
#include <stdio.h>

template <class InputIterator1, class InputIterator2>

//default constructor
Sequence::Sequence(){
	}

//destructor
Sequence::~ Sequence (){
	
	}
//copy constructor
Sequence(const Sequence& seq){
	sequence_ = seq.sequence_;
	}

//detailed constructor
Sequence(const std::string& seq){
	sequence_ = seq;
}

void Sequence::clear(){
	sequence_.clear();
}

//operator
Sequence& Sequence::operator=(const Sequence& seq)
{
    sequence_ = seq.sequence_;
    return *this;
}

bool Sequence::operator==(const Sequence& seq) const
{
    return sequence_ == seq.sequence_;
}

bool Sequence::operator!=(const Sequence& seq) const
{
    return !(*this == seq);
}

std::ostream& operator<<(std::ostream& ostr, const Sequence& seq)
{
    ostr << seq.sequence_ << ' ';
    return ostr;
}

std::istream& operator>>(std::istream& istr, Sequence& seq){
    if (istr.good()){
        char first = istr.get(); //first char
        if (!isspace(first)){ //space??
     //       istr.putback(c);
            istr >> seq.sequence_;
            first = istr.peek(); //Returns the next character in the input sequence, without extracting it: The character is left as the next character to be extracted from the stream.
            if (istr.good() && isspace(first)){
                first = istr.get();
            }
            return istr;
        }
    }


//compare
bool Sequence::compare(const Sequence& seq, unsigned int i) const{
	int begin = sequence_.length() - i;
	if begin <1 {
		return false;
	}
	else {
		std::string first1;
		first1 = sequence_.c_str()+i;
		std::string first2;
		first2 = seq.sequence_.c_str();
		if (strcmp (first1, first2)==0) {
			return true;		
		}else{
			return false;
		}
	}	
}
 if ( memcmp(sequence_.c_str() + i, seq.sequence_.c_str(), begin) == 0) 


