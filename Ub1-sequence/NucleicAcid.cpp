#include "NucleicAcid.h"

//default constructor
NucleicAcid::NucleicAcid(){
	}

//copy constructor
NucleicAcid::NucleicAcid(const NucleicAcid& seq):Sequence{
	}
	
//detailed constructor
NucleicAcid::NucleicAcid(const std::string& seq):Sequence{
}

bool NucleicAcid::isValid()const{
return sequence_.find_first_not_of("GCATgcat")==std::string::npos;
}

/**
//destructor
NucleicAcid::~NucleicAcid(){
	}
**/
