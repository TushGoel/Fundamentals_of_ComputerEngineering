For accomplishing Task - 4:

Write a C++ program with the following requirements:

1.) Analyze the algorithms by sorting, in ascending order, the BST, AVG, and WST arrays. Each one of these three arrays has 1000 integers where:
a. BST has 1000 integers already sorted in ascending order (e.g., 10, 20, 30, …etc.).
b. AVG has 1000 randomly generated integers, where each integer is between 0 and 100,000.
c. WST has 1000 integers sorted in descending order (e.g., 1000, 990, 980, …etc.).
Note: Make sure that all algorithms are tested with identical arrays. Therefore, at the beginning of your program, create three identical versions of the BST, AVG, and WST arrays where each algorithm sorts its own version.

2.) Define two global integer variables: moves and comps. Initialize these variables to zero before every call to a sorting algorithm. Add any necessary code to the algorithms’ implementation to carry out the following:
a. moves is incremented with each movement operation of the elements to be sorted (in this case they are the integer values in the arrays). Consider that the swap operation requires three movements of two elements.
b. comps is incremented with each comparison operation on the elements to be sorted.
c. After each call to the sorting algorithms functions ( 3 algorithms × 3 arrays = 9 calls), write to a text file, sort.txt, the values of moves and comps correspond to each algorithm.

3.) After calling an algorithm function to sort an array, verify that the array is sorted. One way to do that is to confirm that every element i in the array has a value less than or equal to the value in element i+1 (write a function for this task and re‐check your code if it returns a false verification).

4.) After running your program, copy the numbers in the text file, sort.txt, to an excel sheet. Use these numbers to generate two graphs. One graph compares the number of moves needed by the three algorithms for the three cases: best, average, and worst. Another graph does the same but for the number of comparisons performed by the algorithms.