#include <iostream>
using namespace std; 

// DISCLAIMER....
// I'M HEAVILY RELYING ON THIS TUTORIAL : https://www.geeksforgeeks.org/insertion-sort/ 
//  ALL CREDIT GOES TO 'GeeksforGeeks'... 

void insertionSort(int x[], int n)
{
	int key, j;

	for(int i = 1; i < n; i++)
	{
		key = x[i]; 
		j = i-1;

		while(j>=0 && x[j] > key)
		{
			x[j+1] = x[j]; 
			j = j-1; 
		}
		x[j+1] = key;
	} 
}


int main()
{
	int a[]={14,200,30};
	int n = sizeof(a)/sizeof(a[0]);
	insertionSort(a,n);
	for(int i = 0; i<n;i++)
	{
		cout<< a[i] << " ";
	}
	cout<<endl;
}