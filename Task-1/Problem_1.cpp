/* Name: Tushar Goel
Student_id: 001356901
*/

#include <iostream>
#include <stdio.h>
using namespace std;

// Swapping function for pass-by-pointer 
void SwapP(int *x, int *y)
{
	int temp1=*x;
	*x=*y;
	*y=temp1;
}

// Swapping function for pass-by-reference
void SwapR(int &x, int &y)
{
	int temp=x;
	x=y;
	y=temp;
}

// main function for calling other functions
int main ()
{
	int i=0; // variable for taking input of user's choice
	int x=0; // Taking input from user for the integer value
	int y=0; // Taking input from user for the integer value
	int a=0; // Taking input from user for the integer value
	int b=0; // Taking input from user for the integer value

	cout << "Swapping of two integer variables is done by two methods \n";
	cout << "Method 1 --> pass-by-pointer \n";
	cout << "Method 2 --> pass-by-reference \n";
	cout << "Enter 1 --> for Method 1 \n";
	cout << "Enter 2 --> for Method 2 \n";
	cout << "Enter 3 --> If you want to swap by both methods \n";
	cout << "Enter your choice --> ";
	cin >> i;
	cout << "\n";

	// Condition for running only pass-by-pointer function according to the user's choice
	if (i==1)
	{
		cout << "Enter the integers you want to swap using method 1 \n";
		cout << "First integer --> ";
		cin >> x;
		cout << "Second integer` --> ";
		cin >> y;
		cout << "\n";

		printf("Values of the integers before swapping \n");
		cout << "First integer --> " << x << " and second integer --> " << y;

		// Calling the pass-by-pointer swapping function
		SwapP(&x,&y);
		cout << "\n";

		printf("Values after swapping operation \n");
		cout << "First integer --> " << x << " and second integer --> " << y;
		cout << "\n";

	}

	// Condition for running only pass-by-reference function according to the user's choice
	else if (i==2)
	{
		cout << "Enter the integers you want to swap using method 2 \n";
		cout << "First integer --> ";
		cin >> x;
		cout << "Second integer` --> ";
		cin >> y;
		cout << "\n";
		
		printf("Values of the integers before swapping \n");
		cout << "First integer --> " << x << " and second integer --> " << y;
		
		// Calling the pass-by-reference swapping function
		SwapR(x,y);
		cout << "\n";

		printf("Values after swapping operation \n");
		cout << "First integer --> " << x << " and second integer --> " << y;
		cout << "\n";
	}

	// Condition for running only both pass-by-pointer and pass-by-reference function according to the user's choice
	else if (i==3)
	{
		cout << "Enter the integers you want to swap using method 1 \n";
		cout << "First integer --> ";
		cin >> x;
		cout << "Second integer` --> ";
		cin >> y;
		cout << "\n";

		cout << "Enter the integers you want to swap using method 2 \n";
		cout << "First integer --> ";
		cin >> a;
		cout << "Second integer` --> ";
		cin >> b;
		cout << "\n";

		printf("Values of the integers before swapping \n");
		cout << "For method 1 \n";
		cout << "First integer --> " << x << " and second integer --> " << y;

		// Calling the pass-by-pointer swapping function
		SwapP(&x,&y);
		cout << "\n";

		printf("Values after swapping operation \n");
		cout << "First integer --> " << x << " and second integer --> " << y;
		cout << "\n";
		
		printf("Values of the integers before swapping \n");
		cout << "For method 2 \n";
		cout << "First integer --> " << a << " and second integer --> " << b;

		// Calling the pass-by-reference swapping function
		SwapR(a,b);
		cout << "\n";

		printf("Values after swapping operation \n");
		cout << "First integer --> " << a << " and second integer --> " << b;
		cout << "\n";
	}
	
	return 0;
}