For the Task-2, implement the following:

1.) Write a C++ program for sorting an array A of n integers. First you need to implement both the MERGESORT and MERGE algorithms (shown below). The main() function of the program carries out the following functionality:
1. Ask the user to input the value of n, where 1< n ≤ 50.
2. Fill A with random integers in the range 0 to 100. To generate such random numbers, you need to use the <random> header. 
Check the following link for an example: http://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
3. Call the MERGE‐SORT function to sort the contents of A. MERGE‐SORT needs to call the MERGE function.
4. Display on the screen the contents of the sorted array A.

2.) In the above MERGE algorithm and to avoid having to check whether either list is empty in each basic step, a sentinel value is placed at the end of each list.
Rewrite the algorithm (no need to submit any C++ program code) so that it does not use sentinels, instead it stops once either array L or R has had all its elements copied back to A and then copying the remainder of the other array back into A.


