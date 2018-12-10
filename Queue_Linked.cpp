#include<iostream> 
using namespace std; 

// a node struct for a doubly linked list 
struct node
{
    int value; 
    node*next; 
    node*prev; 
};
// keep track of the head of the list and its tail... 
node*head; 
node*tail; 

void Enqueue(int value)
{
    //create a new node and give it a value...
    node* new_node = new node;
    new_node->value = value;
    //if it's the first node of the queue...   
    if(head == NULL)
    {
        head = new_node; // make the head point to the first node...
        new_node->prev = NULL; // make its previous and next pointer point to NULL 
        new_node->next = NULL;
        tail = new_node; // make the tail point to it...
        return;   
    } 
    //if it's not the first node then :
    new_node->prev = tail; // make the prev pointer of the new node point to the last node...
    tail->next = new_node; // make the last node's next point to the new node, which is the last one in the Q now 
    new_node->next = NULL; // since it's now the last one in the Q, then make it's next point to null. 
    tail = new_node;  // and make the tail point to it...
}
int Dequeue()
{
  node* trav; // create a traverse pointer and make it point to the second element of the Q  
  trav = head; 
  trav = trav->next; 
  int x = head->value; // extract the value you wanna dequeue 
  delete(head); // remove the first node, the node head is currently pointing to 
  trav->prev = NULL; // then make the second node the front of the Q 
  head = trav;
  return x;
}
void Print()
{
    node* trav;
    trav = head; 
    while(trav!=NULL)
    {
        cout<<trav->value<<endl;
        trav = trav->next;
    }

}
int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50); 
    Print();
    Dequeue();
    cout<<"------------------------------------"<<endl; 
    Print();
    Dequeue();
    cout<<"------------------------------------"<<endl; 
    Print();
    Enqueue(60);
    cout<<"------------------------------------"<<endl; 
    Print();
}