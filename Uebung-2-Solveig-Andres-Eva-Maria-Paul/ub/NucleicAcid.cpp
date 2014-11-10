#include "NucleicAcid.h"

//default constructor
NucleicAcid::NucleicAcid(){
}

//copy constructor
NucleicAcid::NucleicAcid(const NucleicAcid& seq):Sequence(seq){
}

//detailed constructor
NucleicAcid::NucleicAcid(const std::string& seq):Sequence(seq){
}

//isValid
bool NucleicAcid::isValid()const{
    return sequence_.find_first_not_of("GCATgcat")==std::string::npos;
}



