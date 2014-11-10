/*
 * Graph.h
 *
 *  Created on: Nov 7, 2014
 *      Author: s9evpaul
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include "Node.h"
#include "Sequence.h"
class Graph {
/*
 *
 *private:


	std::list<Node> nodelist;
	std::vector<Edge> edgelist;
	Node thisnode;
	Edge thisedge;

public:


	void setterNode(Node& n){
		thisnode = n;
	}

	Node getterNode(){
		return (thisnode);
	}

	void setterEdge(Edge& e){
		thisedge = e;
	}

	Edge getterEdge(){
		return (thisedge);
	}

	void setterNodelist(std::list<Node>& nl){
		nodelist = nl;
	}

	std::list<Node> getterNodelist(){
		return (nodelist);
	}

	void setterEdgelist(std::list<Edge>& el){
		edgelist = el;
	}

	std::list<Edge> getterEdgelist(){
		return (edgelist);
	}

*/
public:
	Graph();
	virtual ~Graph();
	Graph(const Graph& g);
	Graph(const std::string& g);



	//setter,getter
	void setterNode(Node n);
	Node getterNode();
	void setterEdge(Edge e);
	Edge getterEdge();
	void setterNodelist(std::list<Node>& nl);
	std::list<Node> getterNodelist();
	void setterEdgelist(std::list<Edge>& el);
	std::list<Edge> getterEdgelist();

	//methods
	bool hasNode(const Sequence& seq)const;
	Node& getNode(const Sequence& seq);
	void removeNode(Node& node);
	Edge getEdge(Node& src, Node& target);
	Edge getEdge(const Sequence& src, const Sequence& target);
	void addSequence(Sequence& seq);


public:
	// graph
	std::string graph_;
    

};

std::istream& operator>>(std::istream&, Graph&);

#endif /* GRAPH_H_ */
