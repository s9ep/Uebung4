#ifndef RNA_H
#define RNA_H

#include "NucleicAcid.h"
#include "Sequence.h"


class RNA : public NucleicAcid{
public:

	//defautl constructor
	RNA ();

	//copy constr
	explicit RNA  (const RNA & seq);

	//detailed constr
	RNA (const std::string& seq);

	//is Valid

	virtual bool isValid() const;

};
