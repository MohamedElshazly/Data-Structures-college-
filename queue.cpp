#include<iostream> 
using namespace std; 

// The capacity of the array...
#define cap 10 

class Queue
{
    private: 
            int front; 
            int size;
    public:
            int array[cap];
            Queue(){front=0; size = 0;}
            void enqueue(int value);
            int dequeue();
            int print();  

};

void Queue::enqueue(int value)
{
    if (size == cap) // if we exceede the capacity of the array then there's no more room in the queue... 
    {
        throw "Queue is full..."; // to understand the throw, try, and catch expressions refer to : https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm 
    }
    else
    {
    array[(front+size)%cap] = value; // here we use the mod operator '%' to wrap around the array 
    size+=1;                         //if we reach the the end of the array but there's room in the 
    }                                // beginning of the array. ex : [_,_,1,2,3] and we want to add a '4' 
}                                    // here the front is index '2' and the number of elements, size, is '3' and we wanna put the '4' in index 0 
                                     // hence (front + size) % cap = (2+3)%5 = 0. and if we wanna add a '5' then (2+4)%5 = 1
                                     //hence index 1. 
int Queue::dequeue()
{   
    if(size == 0)
    {
        throw "The queue is empty..."; 
    }
    else
    {
    int x = array[front % cap] ; // same trick as the enqueue 
    //update front and size 
    front +=1; 
    size -= 1;
    return x;
    }
}
int Queue::print()
{
    int j = 0;
    for(int i = front; i< (front+size); i++)
    {
        cout<< array[i%cap] <<" -> ";
        j+=1;
    }
    if(j != 0)
    {
        cout<<"END"<<endl;
    }else
    {
        cout<<"Queue is empty..."<<endl;
    }
} 

int main()
{
    Queue q; 
    int ch; 
    do{
        cout<<"Do u want to (enqueue, dequeue, print, exit)? ... press(1, 2, 3, 4) accordingly..."<<endl;
        cin>>ch;
        if(ch == 1)
        {
            int value;
            cout<<"Enter value: "<<endl; cin>> value;
            try
                {
                    q.enqueue(value);
                }
            catch (const char* msg) 
                {
                    cerr << msg << endl;
                } 

        }
        else if(ch == 2)
        {
            try
                {
                    int value = q.dequeue();
                    cout<< "The number is : "<< value <<endl;
                    
                }
            catch (const char* msg) 
                {
                    cerr << msg << endl;
                } 

        }
        else if(ch == 3)
        {
            q.print();
        }
        else if(ch == 4)
        {
            return 0;
        }
         

    }while(ch == 1 || ch == 2 || ch == 3 || ch == 4);
    
    
   
}