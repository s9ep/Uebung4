/*
 * Node.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: s9evpaul
 */

#include "Node.h"
#include "Sequence.h"

class Node{
private:
	 string* newseq;
	 std::list<Edge> praedge; 
	 std::list<Edge> postedge; 
	 Edge edgearray[praedge][postedge];
	 
	
public:
	Node::Node(string* newseq){
		newseq = new string[strlen(newseq)+1];
		
	}

	Node::Node(const Node& n){

	}


	Node::~Node() {
		// TODO Auto-generated destructor stub
	}

	
	
	
};



