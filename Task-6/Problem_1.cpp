/*
Name: Tushar Goel
NUID: 001356901
*/
/* C++ program for implementing and showing utilization of the Standard Template Library (STL) and the STL Algorithms */

#include <bits/stdc++.h> 
#include <iostream>
#include <queue>
#include <stack> 
using namespace std; 

// Function for printing vector after the required operations are being performed
void displayVector(vector<int> vectnew)
{	
    for (int x : vectnew)
    {
    	cout << x << " ";
    }
    cout << endl;
}

// Function for printing list after the required operations are being performed
void displayList(list<int> listINTnew)
{
	for (int val : listINTnew)
	{
		cout << val << " ";
    }
    cout << endl;
}

// Function for printing stack after the required operations are being performed
void displayStack(stack <int> stackINTnew)
{	
    while (!stackINTnew.empty()) 
    { 
        cout << stackINTnew.top() << " "; 
        stackINTnew.pop(); 
    } 
    cout << endl; 
}

// Function for printing priority queue after the required operations are being performed
void displayPriorityQueue(priority_queue <int> pqueueINTnew)
{
    while (!pqueueINTnew.empty()) 
    { 
        cout << pqueueINTnew.top() << " "; 
        pqueueINTnew.pop(); 
    } 
    cout << endl;    
}

// Driver Function for performing different tasks as mentioned in the Problem-1
int main() 
{ 
    vector<int> vect{ 14, 18, 6, 16, 8, 20, 4, 10, 12, 2 }; // vector declaration and initialization 
    list<int> listINT; // list declaration
    stack <int> stackINT; // stack declaration
    priority_queue <int> pqueueINT; // priority queue declaration

    for (int x : vect)
    {
    	listINT.push_back(x); //list initialization
    	stackINT.push(x); //stack initialization
    	pqueueINT.push(x); //priority queue initialization
    }

    cout << "The Vector is: " << endl;
    displayVector(vect); // calling the display function for vector printing

    cout << "The List is: "<<endl;
    displayList(listINT); // calling the display function for list printing

	cout << "The Stack is: " << endl;
	displayStack(stackINT); // calling the display function for stack printing

	cout << "The Priority Queue is: " << endl;
	displayPriorityQueue(pqueueINT); // calling the display function for priority queue printing

	// Operation for increasing each elements of vector by 40
    for (int i = 0; i < vect.size(); i++)
	{
    	vect[i]=vect[i]+40;
	}

	cout << "The new vector is: " << endl;
    displayVector(vect); // calling the display function for new updated vector printing

    // Operation for increasing each elements of list by 30
	list <int> :: iterator it;
	for(it = listINT.begin(); it != listINT.end(); ++it ) 
	{
    	int &l( *it );
    	l=l+30;
	}
	
	cout << "The new list is: " << endl;
	displayList(listINT); // calling the display function for new updated list printing

	int i=0;
	int s[stackINT.size()];
	while (!stackINT.empty()) 
    { 
    	s[i] = stackINT.top();
    	stackINT.pop();
    	pqueueINT.pop(); 	
        i++;
    }
    
    // Operation for increasing each elements of stack by 20 and priority queue by 10
	for (int j=0;j<i;j++)
    {
    	stackINT.push(s[j]+20);
    	pqueueINT.push(s[j]+10);
    }

    cout << "The new stack is: " << endl;
	displayStack(stackINT); // calling the display function for new updated stack printing

    cout << "The new priority queue is: " << endl;
	displayPriorityQueue(pqueueINT); // calling the display function for new updated priority queue printing

	// Operation for finding location of element 44 in an updated vector
	cout << "The location of 44 in the new vector is: ";
	for (int i = 0; i < vect.size(); i++)
	{
    	if (vect[i]==44)
    	{
    		cout << i+1 <<endl;
    	}
	}

	// Operation for finding location of first element greater than 50 in an updated vector
	cout << "The location of first element greater than 50 in the new vector is: ";
    for (int i = 0; i < vect.size(); i++)
	{
    	if (vect[i]>50)
    	{
    		cout << i+1 <<endl;
    		break;
    	}
	}

	// Operation for finding the number and the elements greater than 45 in an updated vector
	int c=0;
	cout << "The elements greater than 45 in the new vector is: ";
    for (int i = 0; i < vect.size(); i++)
	{
    	if (vect[i]>45)
    	{
    		cout << vect[i] << " ";
    		c++;
    	}
	}
	cout << endl;
	cout << "The total number of elements greater than 45 in the new vector are: " << c << endl;
    return 0;
}