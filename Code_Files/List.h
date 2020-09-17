//Header file for the Linked List with Basic funtions

#include<iostream>
#include"Node.h"
#ifndef LIST
#define LIST
using namespace std;
class List{
public:
	List();
	bool insert(int d);		// d=data
	bool delete_list(int d);
	void print();
	int search(int d);
	Node* search_node(int d);
	int search_index(int d);
	void sort();
	void set_head(Node* h);
	Node* get_head();		// usage will be in main on neeed base
	int node_count = 0;

private:
	Node* head;
	
};

#endif



