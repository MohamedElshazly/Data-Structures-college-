#include <iostream>
#include <cctype>
using namespace std; 

struct node{
	int data; 
	node *next; 
}; 

void Insert(int num);
void Insert_nth(int n, int value);
void Print(void);
void Delete(int n);
node *head;
node *tmp;
int main()
{
	// THE MAIN FUNCTION IS VERY MESSY, I ENCOURGE YOU TO MAKE YOUR OWN TESTS ON YOUR MACHINE... 
	int n1,n2,n3;
	char answer;  
	cout<< "Please Enter the initial number of element u want in the linked list: ";
	do{
		cin>>n1;
		for(int i = 0; i<n1; i++)
		{
			cout<<"Element num "<<i+1<<" : "<<endl;
			cin>>n2;
			Insert(n2);
		}
		cout<<"Here are the elements you've entered : "<<endl; 
		Print();
		cout<<"Do u wish to add more elements ?...(Y/N)"<<endl;
		cin >> answer;
		if (tolower(answer) == 'y')
		{
			cout<<"How many more ? : ";
		}
	}while(tolower(answer) == 'y');

	cout<<"Do u want to delete anything? (Y/N)"<<endl;
	cin>>answer;
	if(tolower(answer) == 'y')
	{
		cout<<"Enter node number...: ";
		cin>>n3;
		Delete(n3);
		cout<<"\n\nList after modifications...: "<<endl;
		Print();
		do{
			cout<<"Do u want to delete anything else? (Y/N)"<<endl;
			Print();
			cin>>answer; 
			if(tolower(answer) == 'y')
			{
				cout<<"Enter node number...: ";
				cin>>n3;
			
				Delete(n3);
				cout<<"\n\nList after modifications...: "<<endl;
				Print();
			}
		}while(tolower(answer) == 'y');
	}
	cout<<"Do u wanna add after a particular node? : "<<endl;
	cin>>answer;
	if(tolower(answer) == 'y')
	{
		cout<<"Enter node number: "<<endl;
		cin>>n3;
		cout<<"Enter value: "<<endl;
		cin>>n2;
		Insert_nth(n3,n2);
		Print();
	}

}




void Insert(int num)
{
	node *new_node = new node;
	tmp = head ;  
	new_node->data = num; 
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

void Insert_nth(int n, int value)
{
	node *new_node = new node;
	new_node->data = value;
	tmp = head;
	if(n != 0)
	{
		int i = 1;
		while(tmp != NULL)
		{
			if(i == n)
			{
				new_node->next = tmp->next;
				tmp->next = new_node;
				return;
			}
			tmp = tmp->next;
			i++;
		}
	}
	else
	{
		new_node->next = tmp; 
		head = new_node;
		return;
	}	  

}

void Print(void)
{
	tmp = head;
	while(tmp != NULL)
	{
		cout<< tmp->data<<" -> ";
		tmp = tmp -> next;
	}
	if(head == NULL)
	{
		cout<<"List is empty...\n"; 
		return;
	}
	cout<<"EOF"<<endl;
}
void Delete(int n)
{

	int i = 1; 
	tmp = head; 
	while(tmp != NULL)
	{
		if(n == 1)
		{
			if(tmp == head)
			{
				head = tmp->next;
				free(tmp);
				return;
			}
		}
		else if(n-1 == i)
		{
			if(tmp->next != NULL)
			{
				tmp->next = tmp->next->next;
				free(tmp->next);
				return;
			}
			else
			{
				cout<<"node not found..."<<endl; 
				exit(1);
			}
		}		
		tmp = tmp->next;
		i++;

	}

}
