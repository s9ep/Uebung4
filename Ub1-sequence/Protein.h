#ifndef PROTEIN_H
#define PROTEIN_H

#include "Sequence.h"

class Protein : public Sequence{
public:

	//defautl constructor
	Protein();

	//copy constr
	explicit Protein (const Protein& seq);

	//detailed constr
	Protein(const std::string& seq);

	//is Valid

	virtual bool isValid() const;


};

#endif
