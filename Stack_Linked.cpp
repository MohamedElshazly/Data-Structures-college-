#include<iostream> 
using namespace std; 

// a node struct for a doubly linked list 
struct node
{
    int value; 
    node*next; 
    node*prev; 
}; 
// global pointers... 
node*head; 
node*top; 

void Push(int value)
{
    // create a new node 
    node* new_node = new node; 
    //give it a value 
    new_node->value = value; 
    if(head == NULL)
    {
        head = new_node; // make the head point to the first node...
        new_node->prev = NULL; // make its previous and next pointer point to NULL 
        new_node->next = NULL;
        top = new_node; // make the top point to it...
        return;   
    }
    // if it's not the first node then make the first node point to the new node,
    // make the new node's prev pointer point to where top is pointing to,
    // move top to the new node, and lastly make the new node next point to null 
    top->next = new_node; 
    new_node->prev = top; 
    top = new_node; 
    new_node->next = NULL;    
}
int pop()
{
    // a placeholder for the value that we wanna get.
    int x;  
    // if there aren't any nodes in the stack then it's a stack underflow... 
    if(head == NULL)
    {
        cerr<<"Stack Underflow...."<<endl;
        exit(1);
    }
    // if we have only one node is the stack...
    else if(top->prev == NULL)
    {
        x = top->value; 
        delete(top);
        head = NULL;
        return x; 
    }
    // so we have  node1 <-> node2 and we have a pointer 'top' pointing to node2 
    // we make top point to node1 then delete node 2 then make the node1's next pointer point to null 
    x = top->value; 
    top = top->prev; 
    delete(top->next); 
    top->next = NULL;
    return x;
}
void Print()
{
    node* trav;
    trav = head;
    if(trav == NULL)
    {
        cout<<"Stack is empty..."<<endl;
        return;
    }  
    while(trav!=NULL)
    {
        cout<<trav->value<<endl;
        trav = trav->next;
    }

}
int main()
{
    //TEST CASES ...

    // Push(10); 
    // Push(20); 
    // Push(30);
    // Push(40);
    // Push(50); 
    // Print();
    // cout<<"--------------------------------"<<endl;
    // int n = pop(); 
    // cout<< n<<endl;
    // cout<<"--------------------------------"<<endl; 
    // Print();
    //   cout<<"--------------------------------"<<endl; 
    // pop(); 
    // pop(); 
    // n = pop(); 
    // cout<<n<<endl;
    //   cout<<"--------------------------------"<<endl; 
    // Print();
    // pop();
    // cout<<"--------------------------------"<<endl; 
    // Print();
    // n = pop();
    // cout<<n;   
}