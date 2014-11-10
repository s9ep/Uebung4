#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include <stdio.h>
#include "Sequence.h"
#include "tools.h"
#include "Protein.h"
#include "NucleicAcid.h"




int main(int argc, char* argv[]){
    
    // Zeiger auf Datei
    FILE *f;
    
    // Datei oeffnen
    f = fopen("graph.dot", "rwb");
    if (f)
    {
        // TODO Grah ausgeben
        fclose(f);
    }
    
    return 0;
    
    
    NucleicAcid a ("gcat");
    NucleicAcid b ("GCAT");
    NucleicAcid c("tagctagc");
    NucleicAcid d("ATGCd");
    NucleicAcid e("AreCA");
    //NucleicAcid f("wATTA");
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
    //ASSERT(!f.isValid()); // not valid
    ASSERT(!g.isValid()); //empty
    ASSERT(h.isValid()); //
    
    ASSERT(i.isValid()); //
    ASSERT(!j.isValid()); // not valid
    ASSERT(!k.isValid()); //
    ASSERT(l.isValid()); //
    ASSERT(m.isValid()); //
    
    
    //compare
    // ASSERT(a.compare(b, 0)); // small, large, true
    ASSERT( b.compare(b, 0)); // true
    ASSERT(!a.compare(c, 0)); // false
    ASSERT( !b.compare(b, 4)); // end,false
    ASSERT(!a.compare(a, 10)); //false, end
    
    //ASSERT(i.compare(n, 3)); // true
    ASSERT( n.compare(n, 0)); // true
    ASSERT(!i.compare(m, 0)); // false
    ASSERT(!i.compare(i, 4)); // end,false
    ASSERT(!n.compare(n, 100)); //false, end
    
    // overlap
    ASSERT(a.overlap(a) == 4);
    
    //std::stringstream str_seq;
    //str_seq << a << b;
    
    //Assignment
    b=a;
    ASSERT(b==a);
    ASSERT((a==a));
    
    // Graph
    Graph graph1("atg");
    Graph graph2("atg");
    Graph graph3("cac");
    
    //new Sequence
    Protein prot1("aaa");
    NucleicAcid n_s("a");
    NucleicAcid n_t("b");
    
    graph1.addSequence(prot1); //fuege Sequenz hinzu
    std::list<Node> nodelist1= graph1.getterNodelist(); //hole nodelist des Graphen1
    ASSERT(nodelist1.size()==1); // hat jetzt die Groesse 2?
    ASSERT(graph1.hasNode(prot1)); // enthaelt Knoten?
    std::list<Node> nodelist= graph1.getterNodelist(); //hole nodelist des Graphen1
    ASSERT(nodelist.size()==2); // hat jetzt die Groesse 2?
    
    Node node(prot1); // neuer Knoten mit node1
    ASSERT(graph1.hasNode(prot1)); // ist der Knoten schon enthalten? --> muesste ja herauskommen
    ASSERT(!graph2.hasNode(prot1)); // sollte nicht enthalten sein
    graph2.addSequence(prot1);
    ASSERT(graph2.hasNode(prot1)); // sollte jetzt aber enthalten sein

    Node node_target(n_t); // neuer Knoten
    Node node_source(n_s); // neuer Knoten
    Edge edge1(node_source,node_target); // Kante erstellt
    std::vector<Edge> outedges =node_source.getOutEdges(); //
    
    //ASSERT(outedges.== edge1);
    bool enthalten=false;
    
    
}



