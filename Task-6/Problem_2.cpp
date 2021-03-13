/*
Name: Tushar Goel
NUID: 001356901
*/
/* C++ program to compare the Recursive implementation of the Rod Cutting problem
   with the Dynamic Programming implementation of the same problem. */

#include <stdio.h>
#include <math.h>
#include <limits.h> 
#include <sys/time.h>
#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

// Function for returning maximum value
int maximum(int x, int y) 
{
    if (x > y)
        return x;

    else
       return y;
} 

// Function for calling recursive implementation for the rod cutting problem
int recursive_rod_cutting(int cost[], int num) 
{
    int max_val = INT_MIN;

    if (num <= 0)
        return 0; 
        
    for (int i = 0; i < num; i++) 
        max_val = maximum(max_val, cost[i] + recursive_rod_cutting(cost, num-i-1)); 
  
    return max_val; 
}

// Function for calling dynamic implementation for the rod cutting problem
int dynamic_rod_cutting(int cost[], int num) 
{
    int val[num+1]; 
    val[0] = 0; 

    for (int i = 1; i<=num; i++) 
    { 
        int max_val = INT_MIN; 
    
        for (int j = 0; j < i; j++) 
            max_val = maximum(max_val, cost[j] + val[i-j-1]); 
        val[i] = max_val; 
    } 
  
   return val[num]; 
} 
   
// Driver Function for performing different tasks as mentioned in the Problem-2
int main() 
{ 

    struct timeval start, end; 

    int rod_sizes[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50}; // rod size array declaration and initialization
    int opt=0;
    double time_taken=0.0; // variable for storing calculated time taken
    int max_cost=0; // variable for storing calculated max cost

    // Asking the user input what he wants to implement
    cout << "Enter the option you want to check: " << endl;
    cout << "Enter 1 --> for dynamic implementation " << endl;
    cout << "Enter 2 --> for recursive implementation" << endl;
    cin >> opt;
    cout << endl;


    for (int i = 0; i < 10; i++)
    {
        int size = rod_sizes[i];
        int costs[size];
        int index = 0;

        for (int j = 1; j <= size; j++)
        {

            if (j == 1)
            {
                costs[index] = 2.0;
                index++;
            }

            if ( j > 1 && j < size)
            {
                costs[index] = floor (j * 2.5);
                index++;
            }

            if (j == size)
            {
                costs[index] = (j * 2.5 - 1);
            }
        }

        // calling the dynamic implementation for the rod cutting problem according to user input for calculating maximum cost and time taken
        if (opt == 1)
        {
            gettimeofday(&start, NULL); 
            max_cost = dynamic_rod_cutting(costs, size);
        
            gettimeofday(&end, NULL); 
            time_taken = (end.tv_sec - start.tv_sec) * 1e6; 
            time_taken = (time_taken + (end.tv_usec - start.tv_usec));

            printf("The max revenue (dynamic) for size  = %d is = %d\n", size, max_cost);
            printf("Time Taken in microseconds is = %f\n", time_taken);
        }

        // calling the recursive implementation for the rod cutting problem according to user input for calculating maximum cost and time taken
        if (opt == 2)
        {
            gettimeofday(&start, NULL); 
            max_cost = recursive_rod_cutting(costs, size);
        
            gettimeofday(&end, NULL); 
            time_taken = (end.tv_sec - start.tv_sec) * 1e6; 
            time_taken = (time_taken + (end.tv_usec - start.tv_usec)); 

            printf("The max revenue (recursion) for size  = %d is = %d\n", size, max_cost);
            printf("Time Taken in microseconds is = %f\n", time_taken);
        } 
    }
    return 0; 
} 