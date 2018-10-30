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
	Print();
	cin>>answer; 
	if(tolower(answer) == 'y')
	{
		cout<<"Enter node number...: ";
		cin>>n3;
	} 
	Delete(n3);
	cout<<"\n\nList after modifications...: "<<endl;
	Print();
	int c1,c2; 
	cin>>c1>>c2;
	Insert_nth(c1, c2);
	Print();

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
	int i = 1;
	node *new_node = new node;
	new_node->data = value;
	node *nxt = NULL; 
	tmp = head;
	while(tmp != NULL)
	{
		if(i == n)
		{
			nxt = tmp->next ;
			tmp->next = new_node; 
			new_node->next = nxt;
			return;
		}
		nxt = tmp; 
		tmp = tmp->next;
		i++;
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
	node *pre = NULL;
	tmp = head; 
	while(tmp != NULL)
	{
		if(n == i)
		{
			if(tmp == head)
			{
				head = tmp->next;
			}
			else
			{
				pre->next = tmp->next;
			}
			free(tmp);
			return;
		}
		pre = tmp; 
		tmp = tmp->next;
		i++;

	}

}
