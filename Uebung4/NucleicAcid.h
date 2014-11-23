#ifndef NUCLEICACID_H
#define NUCLEICACID_H

#include "Sequence.h"

class NucleicAcid : public Sequence
{
public:
		//Default constructor
		NucleicAcid();

		//Copy constructor, it is marked as explicit such that
		//the compiler will not use it as automatic type conversion
		//constructor
		explicit NucleicAcid(const NucleicAcid& seq);

		// Direct std::string constructor
		NucleicAcid(const std::string& seq);

        virtual bool isValid() const;
};

#endif
