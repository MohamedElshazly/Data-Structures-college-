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
    int x = array[front % cap] ; // same trick as the enqueue, since (any_num % 10) will always yield a number between 0-10, then that ensures that we'd always extract a value from the array with a correct index.  
    //update front and size 
    front +=1; // we move the front to the next element in the line or the "Queue". 
    size -= 1; // and normally, decrease the number of elements by 1.  
    return x;
    }
}
int Queue::print()
{
    int j = 0; // the j here is just an indicator to whether or not we've entered the for loop. 
    for(int i = front; i< (front+size); i++) // to understand the reason behind those bounries, draw a queue using a pen and paper, and try it out. 
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
            // refer to the reference above to understand this syntax, but basically it runs, or "tries" the line of code inside the parentheses and if there's an error msg it "catches" it and displays it using cerr.
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
