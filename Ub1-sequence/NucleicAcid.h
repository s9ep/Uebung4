#ifndef NUCLEICACID_H
#define NUCLEICACID_H

#include "Sequence.h"

class NucleicAcid : public Sequence{
	
public:

	//defautl constructor
	NucleicAcid ();

	//copy constr
	explicit NucleicAcid  (const NucleicAcid & seq);

	//detailed constr
	NucleicAcid (const std::string& seq);

	//is Valid

	virtual bool isValid() const;


};

#endif
