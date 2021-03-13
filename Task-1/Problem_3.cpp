/* Name: Tushar Goel
Student_id: 001356901
*/

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

// Function for inputting the data of the student from the teacher
void input_data (int s, string n[], int g[])
{
		for (int i=0; i<s; i++)
	{
		cout << "Enter the name of the student --> ";
		cin >> n [i];

		cout << "Enter the grade of the " << n[i] << " --> ";
		cin >> g [i];
	}

}

// Function for the sorting of student's data in the descending order
void insertion_sorting (string n[], int g[], int s)
{
	int temp1,j=0;
	string temp2;

	for (int i=1; i<s; i++)
	{
		temp1=g[i];
		temp2=n[i];
		j=i-1;

		while(j>=0 && g[j] < temp1)
		{
			g[j+1]=g[j];
			n[j+1]=n[j];
			j=j-1;
		}
		g[j+1]=temp1;
		n[j+1]=temp2;

	}
}

// Function for displaying the result
void display (string n[], int g[], int s)
{
	for (int j=0; j<s; j++)
	{
		
		cout << "Name --> " << n[j] << "  Marks --> " << g[j];
		cout <<"\n";

	}

}

// Main function for calling other functions
int main ()
{
	int *grades;
	string *name;
	int size;
	cout << "Enter the size of the class --> ";
	cin >> size;

	 // dynamic creation of the arrays
	grades = new int [size];
	name = new string [size];

	// function call for inputting data of the student
	input_data(size,name,grades);

	cout << "The data entered is as follows: \n ";

	// Function for calling display function for displaying the entered data
	display(name,grades,size);

	// Function call for the sorting of data in the descending order
	insertion_sorting(name,grades,size);

	cout << "The data after sorting in descending order as follows: \n ";

	// Function for calling display function for displaying the sorted data
	display(name,grades,size);
	
	delete[] grades;
	delete[] name;
	return 0;
}