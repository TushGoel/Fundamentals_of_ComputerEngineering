/* Name: Tushar Goel
Student_id: 001356901
*/

#include<iostream>
#include <stdio.h>
#include<fstream>
#include<stdexcept>
#include<stdlib.h> 
#include <string>

using namespace std;

//global variables
int moves;
int comps;

//function to generate the arrays for best, average and worst for Insertion, Heap and Quick sort algorithms
void arrayGenerator(int bestCI[], int averageCI[], int worstCI[],int bestCH[], int averageCH[], int worstCH[],int bestCQ[], int averageCQ[], int worstCQ[])
{
	for(int i=0;i<1000;i++)
	{
		bestCI[i]=(i+1)*10;
		bestCH[i]=(i+1)*10;
		bestCQ[i]=(i+1)*10;
	}

	for(int i=0;i<1000;i++)
	{
		int x=0;
		x=rand() % 100000 + 1;
		averageCI[i]=x;
		averageCH[i]=x;
		averageCQ[i]=x;
	}

	int count=1000;
	for (int i=0;i<1000;i++)
	{
		worstCI[i]=count*10;
		worstCH[i]=count*10;
		worstCQ[i]=count*10;
		count=count-1;
	}

}

//function to check the array is already sorted or not
int checkingArray (int check[])
{
	for(int i=0;i<999;i++)
	{
		if(check[i]<=check[i+1])
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

//Insertion sorting algorithm
void insertion_sorting (int caseCheck[])
{
	int temp=0;
	int j=0;

	if(checkingArray(caseCheck)) //check to see if an array is already sorted or not
	{
		cout << " Array is sorted already " << endl; 
	}

	else
	{
		cout << " Un-sorted array " << endl;
	}

	//insertion sort algorithm logic
	for (int i=1; i<1000; i++)
	{
		temp=caseCheck[i];
		j=i-1;
		comps=comps+1;

		while(j>=0 && caseCheck[j] > temp)
		{
			comps=comps+1;
			caseCheck[j+1]=caseCheck[j];
			moves=moves+1;
			j=j-1;
		}
		caseCheck[j+1]=temp;
	}
}

/* sub-function of heap sorting algorithm max_heapify to create a proper heap structure 
provided the array, the index of the node at the heap and the heap size */
void max_heapify(int caseCheck[], int i, int heapSize) 
{ 
    int largest = 0; 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
  	int temp=0;
    
    // If left child is larger than root 
    comps=comps+1;
    if (l < heapSize && caseCheck[l] > caseCheck[i])
    {
    	largest = l;
    }

    else
    {
    	largest=i;
    } 
         
    // If right child is larger than largest so far 
    comps=comps+1;
    if (r < heapSize && caseCheck[r] > caseCheck[largest]) 
    {
        largest = r; 
    }
  
    // If largest is not root 
    if (largest != i) 
    { 
        temp = caseCheck[i];
		moves=moves+1;

		caseCheck[i]=caseCheck[largest];
		moves=moves+1;			

		caseCheck[largest]=temp;
		moves=moves+1;			
        
        // Recursively heapify the affected sub-tree 
        max_heapify(caseCheck,largest,heapSize); 
    } 
} 

//sub-function of heap sorting algorithm for building an entire heap structure
void build_max_heap(int caseCheck[])
{
	int heapSize=1000;

	for(int i=((heapSize/2)-1); i>=0; i--)
	{
		max_heapify(caseCheck,i,heapSize);
	}
}

// main function to do heap sorting 
void heap_sorting(int caseCheck[]) 
{
	int temp=0;

	if(checkingArray(caseCheck)) //check to see of the array is already sorted or not
	{
		cout << " Array is sorted already " << endl; 
	}

	else
	{
		cout << " Un-sorted array " << endl;
	}

	build_max_heap(caseCheck);
	
	// One by one extract an element from heap 
    for (int i = 999; i > 0; i--) 
    { 
        // Move current root to end 
        temp = caseCheck[0];
		moves=moves+1;				
		
		caseCheck[0] = caseCheck[i];
		moves=moves+1;				
		
		caseCheck[i] = temp;
		moves=moves+1;
		
		// call max heapify on the reduced heap 
		max_heapify(caseCheck,0,i); 
    } 
} 

/* This function takes last element as pivot, places the pivot element at its correct position in sorted array, 
   and places all smaller than pivot to left of pivot and all greater elements to right of pivot */
int partition_qs (int caseCheck[], int p, int r) 
{ 
    int pivot = caseCheck[r];    // pivot 
    int i = p-1;  // Index of smaller element 
    int temp=0;
  
    for (int j = p; j <= r-1; j++) 
    { 
        // If current element is smaller than or  equal to pivot 
        comps=comps+1;
        if (caseCheck[j] <= pivot) 
        { 
            i=i+1;    // increment index of smaller element 
  			
  			if (i != j)
  			{
  				temp = caseCheck[i];
				moves=moves+1;
								
				caseCheck[i]=caseCheck[j];
				moves=moves+1;	
							
				caseCheck[j]=temp;
				moves=moves+1;					
  			}
             
        } 
    } 
    
    if((i+1)!=r)
    {
    	temp = caseCheck[i+1];
		moves=moves+1;
	
		caseCheck[i+1] = caseCheck[r];
		moves=moves+1;
				
		caseCheck[r] = temp;
		moves=moves+1;	
    }
    
	
    return (i + 1); 
} 
  
/* Quick-sort Sub function that implements QuickSort operations */
void quickSort_operation(int caseCheck[], int p, int r) 
{ 
	int q=0;
    if (p < r) 
    { 
        /* q is partitioning index */
        q = partition_qs(caseCheck, p, r); 
  		// Recursive call to quick_sort operation
        quickSort_operation(caseCheck, p, q-1); 
        quickSort_operation(caseCheck, q+1, r); 
    } 
} 

/* The main function that implements QuickSort */
void quick_sorting(int caseCheck[])
{
	int p=0;
	int r=1000-1;

	if(checkingArray(caseCheck)) //check to see of the array is already sorted or not
	{
		cout << " Array is sorted already " << endl; 
	}

	else
	{
		cout << " Un-sorted array " << endl;
	}

	quickSort_operation(caseCheck, p, r);		
}

// Driver/Main function to make calls to all others 
int main() 
{
	//defining the arrays for Best,Average and Worst case scenarios for all the three algorithms
	int bestCaseI[1000];
	int bestCaseH[1000];
	int bestCaseQ[1000];
	int averageCaseI[1000];
	int averageCaseH[1000];
	int averageCaseQ[1000];
	int worstCaseI[1000];
	int worstCaseH[1000];
	int worstCaseQ[1000];

	arrayGenerator(bestCaseI, averageCaseI, worstCaseI, bestCaseH, averageCaseH, worstCaseH, bestCaseQ, averageCaseQ, worstCaseQ);

	moves=0;
	comps=0;
	cout << "Insertion Sort Best case" << endl;
	insertion_sorting(bestCaseI);

	//code to write the value of 'moves' and 'comps' to the .txt file after each call
	ofstream file;
	file.open("analyze.txt");

	if(file.fail())
	{
		cerr<<"Error: Could not open the output file \n";
		exit(1);
	}

	file << " Insertion Sort: \n" ;

	file << " Best Case scenario: \t\t ";

	file << "Values of moves--> " << moves <<" \t";
	file << "\tValues of comps--> " << comps <<" \n"; 

	moves=0;
	comps=0;
	cout << "Insertion Sort Average case" << endl;
	insertion_sorting(averageCaseI);

	if(file.fail())
	{
		cerr<<"Error: Could not open the output file \n";
		exit(1);
	}
	
	file << " Average Case scenario: \t ";

	file << "Values of moves--> " << moves <<" \t";
	file << "Values of comps--> " << comps <<" \n"; 
	
	moves=0;
	comps=0;
	cout << "Insertion Sort Worst case" << endl;
	insertion_sorting(worstCaseI);

	if(file.fail())
	{
		cerr<<"Error: Could not open the output file \n";
		exit(1);
	}
	
	file << " Worst Case scenario: \t\t ";

	file << "Values of moves--> " << moves <<" \t";
	file << "Values of comps--> " << comps <<" \n"; 

	moves=0;
	comps=0;
	cout << "Heap Sort Best case" << endl;
	heap_sorting(bestCaseH);

	if(file.fail())
	{
		cerr<<"Error: Could not open the output file \n";
		exit(1);
	}

	file << " \nHeap Sort: \n" ;

	file << " Best Case scenario: \t\t ";

	file << "Values of moves--> " << moves <<" \t";
	file << "Values of comps--> " << comps <<" \n"; 
	
	moves=0;
	comps=0;
	cout << "Heap Sort Average case" << endl;
	heap_sorting(averageCaseH);

	if(file.fail())
	{
		cerr<<"Error: Could not open the output file \n";
		exit(1);
	}
	
	file << " Average Case scenario: \t ";

	file << "Values of moves--> " << moves <<" \t";
	file << "Values of comps--> " << comps <<" \n"; 
	
	moves=0;
	comps=0;
	cout << "Heap Sort Worst case" << endl;
	heap_sorting(worstCaseH);

	
	if(file.fail())
	{
		cerr<<"Error: Could not open the output file \n";
		exit(1);
	}
	
	file << " Worst Case scenario: \t\t ";

	file << "Values of moves--> " << moves <<" \t";
	file << "Values of comps--> " << comps <<" \n"; 
	
	moves=0;
	comps=0;
	cout << "Quick Sort Best case" << endl;
	quick_sorting(bestCaseQ);

	if(file.fail())
	{
		cerr<<"Error: Could not open the output file \n";
		exit(1);
	}

	file << " \nQuick Sort: \n" ;

	file << " Best Case scenario: \t\t ";

	file << "Values of moves--> " << moves <<" \t";
	file << "Values of comps--> " << comps <<" \n"; 
	
	moves=0;
	comps=0;
	cout << "Quick Sort Average case" << endl;
	quick_sorting(averageCaseQ);

	if(file.fail())
	{
		cerr<<"Error: Could not open the output file \n";
		exit(1);
	}
	
	file << " Average Case scenario: \t ";

	file << "Values of moves--> " << moves <<" \t";
	file << "\tValues of comps--> " << comps <<" \n"; 

	moves=0;
	comps=0;
	cout << "Quick Sort Worst case" << endl;
	quick_sorting(worstCaseQ);

	if(file.fail())
	{
		cerr<<"Error: Could not open the output file \n";
		exit(1);
	}
	
	file << " Worst Case scenario: \t\t ";

	file << "Values of moves--> " << moves <<" \t";
	file << "\tValues of comps--> " << comps <<" \n"; 
	file.close();

	return 0;
} 

