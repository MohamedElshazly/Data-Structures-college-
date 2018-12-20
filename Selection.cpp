#include <iostream> 
using namespace std; 


void selectionSort(int x[],int n)
{
	/* Basically we need to iterate through the array find the SMALLEST unsorted element and swap it with the FIRST unsorted element in the array
	   and every time you make a swap the original array gets slightly sorted and the unsorted region gets smaller, in other words 
	   the original unsorted boundry gets reduced everytime till it vanishes all together and we sort the whole array 
	*/	
	int min_idx;
	for(int j = 0; j < n; j++) // loop over the whole array
	{
		min_idx = j; // assume the first element to be the smallest 
		for(int i = j+1; i < n; i++) // we know that we need to reduce the sorted boundry every time we correctly sort a new element 
		{							 // hence we initialize i with j+1 and every time we sort an element the j increses by 1, ergo we reduce the sorted boundry by 1 every time 
			if(x[min_idx] > x[i])// get the smallest unsorted element in the array 
			{
				min_idx = i;
			}
		}
		swap(x[j], x[min_idx]); // swap it with the first unsorted element in the array 
	} 
}





int main()
{
	//TEST....
	int a[]={9,5,7,1};
	int n = sizeof(a)/sizeof(a[0]);
	selectionSort(a,n);
	for(int i = 0; i<n;i++)
	{
		cout<< a[i] << " ";
	}
	cout<<endl;
}