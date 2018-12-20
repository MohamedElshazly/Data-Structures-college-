#include <iostream> 
using namespace std; 

// DISCLAIMER....
//  I WAS FOLLOWING THIS TUTORIAL : https://www.geeksforgeeks.org/merge-sort/ 
//  ALL CREDIT GOES TO 'GeeksforGeeks'... 

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	// get the appropriate sizes... 
	int n1 = m - l + 1; 
	int n2 = r - m; 
	// create vacant arrays... 
	int A1[n1], A2[n2] ; 

	// fill The arrays... 
	for(i = 0; i < n1; i++)
		A1[i] = arr[l+i]; 
	for(j = 0; j < n2; j++)
		A2[j] = arr[m+1+j]; 

	// sort the arrays... 
	i = 0; // initial index of A1 
	j = 0; // initial index of A2 
	k = l; // initial index of original array 
	while(i < n1 && j < n2)
	{
		if(A1[i] <= A2[j])
		{
			arr[k] = A1[i]; 
			i++;
		}
		else
		{
			arr[k] = A2[j]; 
			j++;
		}
		k++;
	}
	// if there were still remaining elements in either  A1, A2
	while(i < n1)
	{
		arr[k] = A1[i];
		i++;
		k++;
	}
	while(j < n2)
	{
		arr[k] = A2[j]; 
		j++;
		k++;
	}

}
void mergeSort(int arr[], int l, int r)
{
	if(l < r)
	{
		// get the middle point...
		int m = l+ (r-l)/2;

		// split and sort the first half and the second half... 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		// merge them back together after sorting... 
		merge(arr, l, m, r);

	}
}
int main()
{ 
int a[]={10,1,7,5,12,4,3,8};
int n = sizeof(a)/sizeof(a[0]);
mergeSort(a,0,n-1);
for(int i = 0; i<n;i++)
{
	cout<< a[i] << " ";
}
cout<<endl;
}