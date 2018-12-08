#include<iostream> 
using namespace std; 

#define max 1000 

class Stack
{
    private:
        int top;
    public:
        int a[max];
        Stack(){top = -1;} 
        bool push(int data);
        int pop(); 
        bool is_empty();   
};

bool Stack::push(int data)
{
    if(top >= max - 1)
    {
        cout<<"Stack Overflow..."<<endl; 
        return false; 
    }
    a[++top] = data;
    return true;  
}

int Stack::pop()
{
    if(top < 0)
    {
        cout<<"Stack Underflow..."<<endl; 
        return 1;
    }
    int x = a[top--];
    return x;
}   

bool Stack::is_empty()
{
    if(top == 0)
        return true; 
    else
        return false;
}

int main()
{   
    Stack stack1;  
    stack1.push(10); 
    stack1.push(20); 
    stack1.push(30);
    stack1.push(40);
    stack1.is_empty(); 
    for(int i = 0; i < 4; i++)
    {
        cout<< stack1.pop()<< endl;
    }
    

}