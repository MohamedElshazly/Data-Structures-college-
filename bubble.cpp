#include <iostream> 
using namespace std; 

void bubbleSort(int x[], int n)
{
	int swaps = 0;
	for(int i = 0; i < n; i++)
	{	
		for(int j = 0; j < n-1; j++)
		{
			if(x[j] > x[j+1])
			{
				swap(x[j], x[j+1]);
				swaps+=1; 
			}
		}
		if(swaps == 0)
		{
			cout<<"Sorted..."<<endl;
			return;
		}
		else
			swaps = 0;
	} 
}

int main()
{
	int a[]={100,20,3,5,14,1,2,1};
	int n = sizeof(a)/sizeof(a[0]);
	bubbleSort(a,n);
	for(int i = 0; i<n;i++)
	{
		cout<< a[i] << " ";
	}
	cout<<endl;
}