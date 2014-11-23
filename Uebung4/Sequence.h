#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <string>

class Sequence
{
	public:
		//Default constructor
		Sequence();

		//Copy constructor
		Sequence(const Sequence& seq);

		// Direct std::string constructor
		Sequence(const std::string& seq);

		//We declare the destructor to be virtual to
		//prevent memory leaks in derived classes
		virtual ~Sequence();

		//Remove contents, virtual because derived classes should be able to override this behavior
		virtual void clear();

		//Assignment operator, make sure to handle self assignments
		//properly
		Sequence& operator=(const Sequence& seq);

		//Equality operator
		bool operator==(const Sequence& seq) const;

		//Inequality operator
		bool operator!=(const Sequence& seq) const;

		//Declare the output operators as friends, as they need to access
		//the internal representation of Sequence.
		//They cannot be methods as the streams must be the first arguments.
		friend std::ostream& operator<<(std::ostream&, const Sequence&);
		friend std::istream& operator>>(std::istream&, Sequence&);

		/*
		 * Compares the sequence with seq starting with an offset i
		 *
		 * this -> ATGCAGTAATGGTCCATC
		 *  seq ->    CAGTAATGGTCCATCTAGTC
		 *            ^             ^
		 *            i             end of comparison
     */
		bool compare(const Sequence& seq, unsigned int i) const;

		//Computes the maximum overlap of a suffix of this sequence
		//with a prefix of seq. In the above example, the overlap is 15.
		unsigned int overlap(const Sequence& seq) const;

		//Returns whether this sequence is valid. This depends
		//on the type of sequence and thus should be handled by
		//a subclass.
		//In this case, there is no specialization, so it always returns true
		virtual bool isValid() const { return true; }

		// return internal string representation
		const std::string& getString() const { return sequence_; }

	protected:
		std::string sequence_;
};

std::ostream& operator<<(std::ostream&, const Sequence&);
std::istream& operator>>(std::istream&, Sequence&);


inline Sequence& Sequence::operator=(const Sequence& seq)
{
    if(this == &seq)
        return *this;

    sequence_ = seq.sequence_;
    // strUpper(sequence_); not necessary, other sequecne was already uppercased in a ctor
    return *this;
}

inline bool Sequence::operator==(const Sequence& seq) const
{
    return sequence_ == seq.sequence_;
}

inline bool Sequence::operator!=(const Sequence& seq) const
{
    return !(*this == seq);
}


#endif //SEQUENCE_H
