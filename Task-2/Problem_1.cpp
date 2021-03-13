/* Name: Tushar Goel
Student_id: 001356901 */

#include<stdlib.h> 
#include<stdio.h> 
#include <iostream>
#include <string>
#include <climits>
#include <limits>
using namespace std;

/* First subarray is A[p..q] 
  Second subarray is A[q+1..r] */
void Merge(int A[], int p, int q, int r) 
{ 
	int i, j, k; 
	int n1 = q - p + 1; 
	int n2 = r - q; 

	/* creating temporary arrays */
	int L[n1+1], R[n2+1]; 

	/* Copy data to the temporary arrays L[] and R[] */
	for (i = 0; i < n1; i++)
	{
		L[i] = A[p + i];
	} 
		 
	for (j = 0; j < n2; j++)
	{
		R[j] = A[q + j + 1];
	} 
	
	// Integers are inherently finite, so declaring the maximum value of int
	int max = std::numeric_limits<int>::max();

	//int max = INT_MAX; // Alternatively, we can also use this for maximum value of int.
	
	/* Declaring the last value of arrays as a sentinel value of infinity to avoid checking whether list is empty or not */
	L[n1] = max;
	R[n2] = max;

	/* Merge the temporary arrays back into A[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 

	for (k = p; k <= r; k++)
	{
		if (L[i] <= R[j]) 
		{ 
			A[k] = L[i]; 
			i++; 
		}

		else
		{ 
			A[k] = R[j]; 
			j++; 
		}
	}		  
} 

/* p is for left index and r is right index of the sub-array of array A to be sorted */
void MergeSort(int A[], int p, int r) 
{ 
	if (p < r) 
	{ 
		// Same as (p+r)/2, but avoids overflow for 
		// large p and r 
		int q = p+(r-p)/2; 

		// Sort first and second halves 
		MergeSort(A, p, q); 
		MergeSort(A, q+1, r); 
		Merge(A, p, q, r); 
	} 
} 

/* Function to print an array */
void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
	{
		printf("%d ", A[i]); 
	}
	printf("\n"); 
} 

/* Main function to test and call above functions */
int main() 
{
	int n=0;

	cout << "Enter the number of integers between 1 and 50, you want to perform merge sort on --> ";
	cin >> n;
	
	int A[n];
	
	for (int i=0; i < n; i++)
	{
		int x = 0;
		/* For generating random values in the range of 1 and 100 */
		x = (rand() % 100) + 1;
		A[i] = x;
	}

	printf("Given array is \n"); 
	printArray(A, n); 

	MergeSort(A, 0, n - 1); 

	printf("\nSorted array is \n"); 
	printArray(A, n); 
	return 0; 
}