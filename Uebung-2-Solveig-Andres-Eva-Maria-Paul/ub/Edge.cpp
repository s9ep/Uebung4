#include "Edge.h"
#include "Node.h"

NucleicAcid n_s("");
NucleicAcid n_t("");
Node node_target(n_t); // neuer Knoten
Node node_source(n_s);
/*
 * Default - Konstruktor
 */
Edge::Edge():source(n_s),target(n_t){
    
}

/*
 * Copy - Konstruktor, setzt Kantengewicht
 */
Edge::Edge(const Edge& edge):target(edge.target),source(edge.source){
    updateEdgeWeight();
 }

/*
 * Detailed - Konstruktor, setzt Kantengewicht
 */
Edge::Edge(const Node& s, const Node& t):target(t),source(s){
    updateEdgeWeight();
}

/*
 * Destruktor
 */
Edge::~Edge(){
}

/*
 * Operator "=="
 */
bool Edge::operator==(const Edge& edge) const {
    return (edge.source==Edge::source && edge.target==Edge::target);
}

/*
 * Operator "!="
 */
bool Edge::operator!=(const Edge& edge) const{
    return !(edge.source==Edge::source && edge.target==Edge::target);
}

/*
 * liefert den Ausgangsknoten der Kante zurueck
 */
const Node& Edge::getSource() const{
    return source;
}
/*
 * liefert den Zielknoten der Kante zurueck
 */
const Node& Edge::getTarget() const{
    return target;
}

/*
 * liefert die Ueberlappung der Knoten zurueck
 */
unsigned int Edge::getOverlap() const{
    return Edge::source.sequence_.overlap(Edge::target.sequence_);
}

/*
 * updated das Gewicht der Kante
 */
void Edge::updateEdgeWeight(){
    edge_weight=getOverlap();
}


/*
 * gibt das Gewicht der Kante zurück
 */
unsigned int Edge::getEdgeWeight(){
    return edge_weight;
}









