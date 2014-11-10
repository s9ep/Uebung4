#ifndef DNA_H
#define DNA_H

#include "NucleicAcid.h"
#include "Sequence.h"

class DNA : public NucleicAcid{
public:

	//defautl constructor
	DNA ();

	//copy constr
	explicit DNA  (const DNA & seq);

	//detailed constr
	DNA (const std::string& seq);

	//is Valid

	virtual bool isValid() const;

};
