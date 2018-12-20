#include <iostream>
using namespace std; 

int linear_search(int arr[], int n, int k)
{
	for(int i = 0; i < n; i++)
	{
		if(arr[i] == k)
		{	
			cout<<"Element : "<< arr[i]<<" found at index : "<<i<<endl;
			return arr[i];
			 
		}
	}
	cout<<"Element not found..."<<endl;
	exit(1);
}

int main()
{
	int a[] = {5,1,2,3,4}; 
	int n = sizeof(a)/sizeof(a[0]); 
	int x = linear_search(a,n,5);
}