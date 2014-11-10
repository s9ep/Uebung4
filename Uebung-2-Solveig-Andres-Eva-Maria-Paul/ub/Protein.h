#ifndef PROTEIN_H
#define PROTEIN_H

#include "Sequence.h"

class Protein : public Sequence{
    
public:
    //Default Constructor
    Protein();
    
    //Copy Constructor
    explicit Protein (const Protein& seq);
    
    //Detailed Constructor
    Protein(const std::string& seq);
    
    //is Valid
    virtual bool isValid() const;
    
};

#endif
