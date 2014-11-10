/*
 * Graph.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: s9evpaul
 */

#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include "NucleicAcid.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <list>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>



using namespace std;
//template <class Category, class T, class Distance = ptrdiff_t,
//          class Pointer = T*, class Reference = T&>

std::list<Node> nodelist;
std::vector<Edge> edgelist;
Node thisnode;
Edge thisedge;


	/**
	 * Constructor, Destructor
	 */

	// Default - Constructor
Graph::Graph() {
}

//constructor stub
Graph::Graph(const Graph& g) {
    graph_ = g.graph_;
}

//Detailed Constructor
Graph::Graph(const std::string& g){
    graph_ = g;
}

//destructor stub
Graph::~Graph() {
}



void setterNode(Node& n){
	thisnode = n;
}

Node Graph::getterNode(){
    return (thisnode);
}

/*void setterEdge(Edge e){
    thisedge = e;
}*/

Edge Graph::getterEdge(){
	return (thisedge);
}

void Graph::setterNodelist(std::list<Node>& nl){
	nodelist = nl;
}

std::list<Node> Graph::getterNodelist(){
	return (nodelist);
}

void setterEdgelist(std::list<Edge> const &el){
    edgelist.insert(edgelist.begin(), el.begin(),el.end());
}

std::vector<Edge> getterEdgelist(){
	return (edgelist);
}




/**
 * Methods
 */


bool Graph::hasNode(const Sequence& seq)const{
    bool has_node=false;
    
    for(std::list<Node>::iterator node = nodelist.begin(); node != nodelist.end(); node++)
    {
        if (node->getSequence()==seq){ // ist sequence schon vorhanden?
            has_node=true;
        }
    }

    
    return  has_node;
}


//get node
Node& Graph::getNode(const Sequence& seq){
	if (Graph::hasNode(seq)==true){ //wenn sequence einen node hat, gib diesen node zurück
		return thisnode;
	}else{
		Node *newnode = new Node; //wenn sequence keinen node hat, erstelle einen neuen node
		nodelist.push_back(*newnode); //fuege den node in die liste hinzu
		return *newnode; // gib den neuen node zurück
	}
}

//löscht node aus nodelist,liste von eingehenden kanten und ausgehenden kanten
void Graph::removeNode(Node& node){
	nodelist.remove(node);
//	Node::get_InEdge.remove(node);
//	Node::get_OutEdge.remove(node);
}

Edge getEdge(Node& src, Node& target){
    std::vector<Edge>::iterator findEdge = std::find(edgelist.begin(), edgelist.end(), Edge(src, target));
    // gibt es die Kante schon? -> ja, dann gebe sie aus
	if (findEdge !=edgelist.end()){
		return *findEdge;
	}
    // nein, dann erstelle eine neue und gebes sie
     else{
		Edge *newedge = new Edge(src, target);
		edgelist.push_back(*newedge);
		return *newedge;
	}
    return *new Edge();
}

Edge Graph::getEdge(const Sequence& src, const Sequence& target){
	Node srcnode= Graph::getNode(src);
	Node targetnode = Graph::getNode(target);
    if (!Graph::hasNode(src)){//eine der beiden nodes leer? neuen erstellen
		//srcnode = new Node(src);
	}
	if (!Graph::hasNode(target)){
			//targetnode = new Node(target);
		}
	return getEdge(srcnode, targetnode); //edge zw. src und target zurückgeben
}

void Graph::addSequence(Sequence& seq)
{
    Node *newn = new Node(seq);
    nodelist.push_back(*newn);
}

//TODO unvollständig ??
std::istream& operator>>(std::istream& strm, Graph& graph){
    if(!strm.good())
        return strm;

    std::string s;
    char buf[4096];
    unsigned int ctr = 0;

    while(strm.good()){
        strm.getline(&buf[0], 4096);
        s = s+ buf;

        if(strm.fail()){ // lines to long
                 strm.clear();
                 continue;
             }

        if(s.empty()){
            continue;
        }

        NucleicAcid seq(s);
        s.clear();

        if(seq.isValid()==false){
            continue;
        }

        graph.addSequence(seq);
        ++ctr;
    }

    return strm;
}

// Operator <<
/* Beispiel:
*digraph{
*    a->b [label="0.2",weight="0.2"];
* }
*
*/
std::ostream& operator<<(std::ostream& ostr, const Graph&){
    // Kopf
    ostr << 'digraph{' <<endl;
    
    //Ausgabe der Knoten
    // iteriere ueber alle Knoten
   for(std::list<Node>::iterator node = nodelist.begin(); node != nodelist.end(); node++){
        // nehme alle Ausgabekanten
        std::vector<Edge> outedges = node->getOutEdges();
        for(std::vector<Edge>::iterator edge = outedges.begin(); edge != outedges.end(); edge++){
            std::cout<<node->getSequence()<< '->'<< edge->getTarget().sequence_<< '[label="' << edge->getEdgeWeight()<< ',weight="' << edge->getEdgeWeight()<< '"];' <<endl;
        }
    }
    
    // }
    ostr<<'}' <<endl;
    return ostr;
}
