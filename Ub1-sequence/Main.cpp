#include "Sequence.h"
#include "Protein.h"
#include "NucleicAcid.h"
#include <iostream>

int main(int argc, char* argv[]){

    NucleicAcid a ("gcat");
    NucleicAcid b ("GCAT");
    NucleicAcid c("tagctagc");
    NucleicAcid d("ATGCd");
    NucleicAcid e("AreCA");
    NucleicAcid f("wATTA");
    NucleicAcid g(" ");
    NucleicAcid h;
    
    Protein i("ART");
    Protein j("ABUAAA");
    Protein k(" ");
    Protein l;
    Protein m("ACDEFGHIKLMNPQRSTVWY");
    Protein n("ARTART");
    
    // operators
    ASSERT(a == a); // self-equality, small
    ASSERT(b == b); // self-equality, large
    ASSERT(d == d); // self-equality, not valid
    ASSERT(e == e); // self-equality, not valid
    ASSERT(f == f); // self-equality, not valid
    ASSERT(g == g); // empty equality
    ASSERT(h == h); // empty equality
    ASSERT(a != b); // inequality
    
    ASSERT(i == i); // self-equality
    ASSERT(j == j); // self-equality, not valid
    ASSERT(l == l); // empty equality
    ASSERT(k == k); // empty equality
    ASSERT(a != m); // inequality
    ASSERT(m == m); // self-equality

    // validity
    ASSERT(a.isValid()); //small
    ASSERT(b.isValid()); // large
    ASSERT(c.isValid()); // more
    ASSERT(!d.isValid()); // not valid
    ASSERT(!e.isValid()); // not valid
    ASSERT(!f.isValid()); // not valid
    ASSERT(!g.isValid()); //empty
    ASSERT(h.isValid()); //

    ASSERT(i.isValid()); //
    ASSERT(!j.isValid()); // not valid
    ASSERT(!k.isValid()); //
    ASSERT(l.isValid()); //
    ASSERT(m.isValid()); //
    
    
    //compare
    ASSERT(a.compare(b, 0)); // small, large, true
    ASSERT( b.compare(b, 0)); // true
    ASSERT(!a.compare(c, 0)); // false
    ASSERT( !b.compare(b, 4)); // end,false
    ASSERT(!a.compare(a, 10)); //false, end

    ASSERT(i.compare(n, 3)); // true
    ASSERT( n.compare(n, 0)); // true
    ASSERT(!i.compare(m, 0)); // false
    ASSERT(!i.compare(i, 4)); // end,false
    ASSERT(!n.compare(n, 100)); //false, end
    
	return 0;
	}
