#include "Protein.h"

//default constructor
Protein::Protein(){
}

//copy constructor
Protein::Protein(const Protein& seq):Sequence(seq){
}

//detailed constructor
Protein::Protein(const std::string& seq)
: Sequence(seq)
{
}

//isValid
bool Protein::isValid()const{
    return sequence_.find_first_not_of("ACDEFGHIKLMNPQRSTVWY")==std::string::npos;
}

