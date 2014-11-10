#include "Node.h"
#include "Sequence.h"
#include "Edge.h"
#include <string.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>

NucleicAcid n_s("");

/*
 * Default - Konstruktor
 */
Node::Node():sequence_(n_s){
}

/*
 * Copy - Konstruktor
 */
Node::Node(const Node& node):sequence_(node.sequence_),inedges(node.getInEdges()),outedges(node.getOutEdges()){
}

/*
 * Detailed Konstruktor
 */
Node::Node(Sequence& sequence):sequence_(sequence){
}

/*
 * Destruktor
 */
Node::~Node(){}

/*
 * Zuweisungsoperatorator "="
 */
Node& Node::operator=(const Node& node){
    sequence_= node.sequence_;
    inedges=node.getInEdges();
    outedges=node.getOutEdges();
    return *this;
}

/*
 * Operator "=="
 */
bool Node::operator==(const Node &node) const {
    return ((sequence_==node.sequence_)&&(inedges==node.inedges)&&(outedges==node.outedges));
}

/*
 * Operator "!="
 */
bool Node::operator!=(const Node &node) const {
    return !((sequence_==node.sequence_)&&(inedges==node.inedges)&&(outedges==node.outedges));
}
/*
* Gibt die Liste aller ausgehenden Kanten zurueck
*/
std::vector<Edge> Node::getOutEdges() const {
    return outedges;
}
/*
* Gibt die Liste aller eingehenden Kanten zurueck
*/
std::vector<Edge> Node::getInEdges() const {
    return Node::inedges;
}
/*
* erstellt eine Kante von diesem zum uebergebenen Knoten mit korrekten Kantengewicht
*/

Edge Node::buildEdgeTo(Node& node){
    Edge edge = *new Edge(*this,node); // neue Kante
    outedges.push_back(edge);
   //fuege neue Ausgehende Kante hinzu --> Kantengewicht wird in  "Edge" autmatisch geupdatet
    return edge;
}

/*
* falls eine ausgehende Kante zu node besteht, wird diese entfernt
*/
void Node::removeEdgeTo(Node& node){
    outedges.erase(std::remove(outedges.begin(), outedges.end(), node), outedges.end());
    
}

Sequence& Node::getSequence(){
    return sequence_;
}


std::ostream& operator<<(std::ostream& ostr, const Node&){
    
    return ostr;
}






