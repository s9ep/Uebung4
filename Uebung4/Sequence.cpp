#include <string.h>
#include <iostream>
#include "Sequence.h"
#include "mytools.h"

Sequence::Sequence()
{
}

Sequence::Sequence(const Sequence& seq)
{
    sequence_ = seq.sequence_;
    strUpper(sequence_);
}

Sequence::Sequence(const std::string& seq)
{
    sequence_ = seq;
    strUpper(sequence_);
}

Sequence::~Sequence()
{
}

void Sequence::clear()
{
    sequence_.clear();
}

std::ostream& operator<<(std::ostream& ostr, const Sequence& seq)
{
    ostr << seq.sequence_ << ' '; // whitespace as termination marker
    return ostr;
}

// note: after a sequence, there is always a terminating space character.
// even if the sequence has a length of zero.
// that means first, we have to check if current read position is a space char,
// and if so, remove it.
// bottom line: this function stops AFTER taking the whitespace from the stream.
std::istream& operator>>(std::istream& istr, Sequence& seq)
{
    if(!istr.good()) // only read if stream is readable (this may not be set if we reached the end,
        return istr; // but did not yet try to read PAST the end

    int g = istr.get(); // get first char - int because neg. values indicate failure
    if(g < 0)
        return istr;

    // if we are here, the stream is readable and may or may not contain useful data.
    // in any case, we can safely overwrite existing values now, without causing user confusion

    char c = (char)g;
    if (!isspace(c))     // if its a space, there is nothing to do. don't put back, but clear seq (see below)
    {
        istr.putback(c);                // was no space, we still need it
        istr >> seq.sequence_;          // get full string, this will stop at next whitespace or eof (and does overwrite)
        c = istr.peek();                // look oput for next char, maybe eof, but this case does not have to be handled here
        if (istr.good() && isspace(c))  // if it was eof, good() returns false now
        {
            istr.get();                 // drop the space from the stream, that the next sequence or whatever data follows is immediatly readable
        }
        strUpper(seq.sequence_);        // uppercase, like the ctors do
        return istr;
    }

    // extration should per definition cause seq to be overwritten,
    // which is not the case if the stream contained no readable data/empty sequence,
    // so we have to do it manually here.
    seq.clear();

    return istr;
}

bool Sequence::compare(const Sequence& seq, unsigned int i) const
{
    int rem = sequence_.length() - i; // remaining bytes to check, '\0' excluded
                                      // rem <= 0 means there is no overlap
    return rem > 0 && !memcmp(sequence_.c_str() + i, seq.sequence_.c_str(), rem);
}

unsigned int Sequence::overlap(const Sequence& seq) const
{
    uint i = 0;
    for( ; i < sequence_.length() && !compare(seq, i); ++i) {}
    return sequence_.length() - i;
}
