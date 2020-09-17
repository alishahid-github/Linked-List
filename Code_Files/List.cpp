//.cpp file to implement the Liked List class

#include<iostream>
#include"List.h"
using namespace std;

List::List()
{
	head = NULL;
}

Node* List::get_head() { return head; }
void  List::set_head(Node* h) { head = h; }

void List::print() {
	
	Node* temp = head;		//traverse the head to nodes...
	while(temp!=NULL){ 
		cout << "The  List value= " << temp->get_data()<<endl;
			temp = temp->get_next();
	}

}

bool List::insert(int d)
{
	Node* new_node = new Node(d);
	Node* temp = head;
	if (temp == NULL)
	{
		head = new_node;
		new_node =NULL;
		delete new_node;
		node_count++;
        return true;
	}
	else
	{
		while (temp->get_next()!=NULL)
		{
			temp = temp->get_next();
		}
		temp->set_next(new_node);
		new_node = NULL;
		delete new_node;
		node_count++;
		return true;

	}
}

int List::search(int d) {

	Node* temp = head; 
	int i=0;
	if (temp == NULL)
		return i;
	else
	{
		if (head->get_data() == d)
			return 1;
	}
	while (temp->get_data() != d) 
	{
		if (temp->get_next() == NULL)
			return i;
		else
		{
			i++; 
			temp = temp->get_next();
		}
	}
	return i;
}

Node* List::search_node(int d)
{
	Node* temp = head;
	int i = 0;
	if (temp == NULL)
		return NULL;
	else
	{
		if (head->get_data() == d)
			return head;
	}
	while (temp->get_data() != d)
	{
		if (temp->get_next() == NULL)
			return NULL;
		else
		{
			i++;
			temp = temp->get_next();
		}
	}
	return temp;
}

int List::search_index(int d)
{
	Node* temp = head;
	int i = 0;

	if (temp == NULL)
		return i;
	else if (d == 0)
		return temp->get_data();
	else
	{ 
		while (i<d)
		{
			if (temp->get_next() == NULL)
				return i;
			else
			{
				i++;
				temp = temp->get_next();
			}
		}
		return temp->get_data();
	}
	
}

bool List::delete_list(int d)
{
	Node* temp = head;
	if (temp == NULL)
		return false;
	else if (temp->get_data() == d)
	{
		head = temp->get_next();
		node_count--;
		return true;
	}
	else 
	{
		Node* prev_node = NULL;
		while (temp->get_data() != d)
		{
			if (temp->get_next() == NULL)
				return false;
			else
				prev_node = temp;
				temp = temp->get_next();
		}
		prev_node->set_next(temp->get_next());
		node_count--;
		return true;
	}
}

void List::sort()
{
	//----------------setting the node value in the array
		int* temp_arr = new int(node_count);
		Node* temp = head;						
		int i = 0;
		while (temp != NULL)
		{

			temp_arr[i] = temp->get_data();
			temp = temp->get_next();
			i++;
		}
	//-----------------------------------sorting algorithm
		for (int i = 0; i < node_count; i++)		
		{
			for (int j = 0; j < i; j++)
			{
				if (temp_arr[i] < temp_arr[j])
				{
					int temp = temp_arr[i];
					temp_arr[i] = temp_arr[j];
					temp_arr[j] = temp;
				}
			}
		}
	//-----------------------------------setting value back in the nodes
		Node* temp1 = head;
		for (int i = 0; i < node_count; i++)		
		{
			if (temp1 != NULL) 
			{
				temp1->set_data(temp_arr[i]);
				temp1 = temp1->get_next();
			}
		}
			cout << "List has been sorted\n";
}



