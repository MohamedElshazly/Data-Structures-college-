#include <iostream>
using namespace std; 

int binary_search(int arr[], int start, int end, int target)
{
	
	if(start <= end)
	{
		//calculate the mid... 
	    int mid = (end + start) / 2;
	    //if mid is target... 
		if(arr[mid] == target)
		{	
			cout<<"Element : "<< arr[mid]<<" found at index : "<<mid<<endl;
			return arr[mid];
		}
		//if target is before mid...
		else if(arr[mid] > target)
		{
			return binary_search(arr, start, mid-1, target);
		}
		//if it's after...
		else
		{
			return binary_search(arr, mid+1, end, target);
		}
	}
	// if it's not in the array...
	cout<<"element not found...."<<endl; 
	exit(1);
}

int main()
{
	//ARRAY MUST BE SORTED...
	int a[] = {2,3,4,5,6,7,8,9,10}; 
	int n = sizeof(a)/sizeof(a[0]);
	int x = binary_search(a, 0, n-1, 5); 
	cout<<x<<endl; 
}