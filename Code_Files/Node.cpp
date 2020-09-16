//.cpp file of the Node class includes implementaion of funtions

#include<iostream>
#include"Node.h"
using namespace std;


Node::Node()
{
	data = 0;
	next = NULL;
}

Node::Node(int d)
{
	data = d;
	next = NULL;
}

void Node::set_data(int d) { 
	data = d;
}
void Node::set_next(Node* n) {
	next=n; 
}
Node* Node::get_next() {
	return next ;
}
int Node::get_data() { 
	return data; 
}
