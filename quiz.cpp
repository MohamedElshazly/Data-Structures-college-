#include <iostream>
using namespace std;

// creating the node struct...
struct node 
{
	int value; 
	node *next; 
};

// prototyping the functions... 
void Sorted_Add( int num); 
void Print();
void Insert(int num); 

// creating head pointer
node *head;

int main()
{	//TESTING...
	Insert(5);
	Insert(6);
	Insert(7);
	Insert(9);
	Print();
	Sorted_Add(4);
	Sorted_Add(11);
	Sorted_Add(8);
	Sorted_Add(20); 
	Sorted_Add(2); 
	Sorted_Add(10);
	Print();


}

// THE FUNCTION REQUIRED...
void Sorted_Add(int num)
{
	//create new node..
	node *new_node = new node; 
	new_node->value = num ; 
	// create a traverse pointer
	node *trav ; 
	// make it point to where head is pointing to...
	trav = head;
	//if the first node of the list has a bigger value than the one to be inserted, aka, make our node the head of the list
	if( head == NULL || head->value >= num)
	{
		new_node->next = head; 
		head = new_node;
		return;
	}
	// check if we reached the end of the list or we found a node with a value bigger than the value to be added... 
	while(trav->next != NULL && trav->next->value < num)
	{
		// if the conditions aren't met, keep going...
		trav = trav->next; 
	}
	// place your node in the appropriate position...
	new_node->next = trav->next;
	trav->next = new_node;
}

//////////////////////// SOME HELPER FUNCTIONS //////////////////////////
void Print()
{
	node *tmp ;
	tmp = head;
	while(tmp != NULL)
	{
		cout<< tmp->value<<" -> ";
		tmp = tmp -> next;
	}
	if(head == NULL)
	{
		cout<<"List is empty...\n"; 
		return;
	}
	cout<<"EOF"<<endl;
}
void Insert(int num)
{
	node *tmp ;
	node *new_node = new node;
	tmp = head ;  
	new_node->value = num; 
	if(head == NULL)
	{
		head = new_node;
		return; 	
	}
	while(tmp -> next != NULL)
	{
		tmp = tmp->next; 
	}
	tmp->next = new_node; 
	return;
	
} 