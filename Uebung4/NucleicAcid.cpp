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

// note: this does NOT ensure the protein starts with Met !!
bool NucleicAcid::isValid() const
{
    return sequence_.find_first_not_of("ATCG") == std::string::npos; // uppercase already ensured by ctor
}
