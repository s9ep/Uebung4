#include "NucleicAcid.h"


NucleicAcid::NucleicAcid()
: Sequence()
{
}

NucleicAcid::NucleicAcid(const NucleicAcid& seq)
: Sequence(seq)
{
}

NucleicAcid::NucleicAcid(const std::string& seq)
: Sequence(seq)
{
}

bool NucleicAcid::isValid() const
{
    return sequence_.find_first_not_of("ATCGatcg") == std::string::npos; // 
}
