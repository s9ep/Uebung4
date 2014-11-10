#include "DNA.h"

//default constructor
DNA:DNA(){
	}

//copy constructor
DNA::DNA(const DNA& seq):NucleicAcid{
	}
	
//detailed constructor
DNA::DNA(const std::string& seq):NucleicAcid{
}

bool DNA::isValid()const{
return sequence_.find_first_not_of("GCATgcat")==std::string::npos;
}
