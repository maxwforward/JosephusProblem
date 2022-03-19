//####################################################################################################################################
//	Josephus Problem
//	Max Forward
//####################################################################################################################################

// Include header file
#include"LinkedList.h"

//====================================================================================================================================
// Main Method
//====================================================================================================================================
int main()
{
	// Create a linked list to use for the Josephus Problem
	linkedList<int>* circle = new linkedList<int>; // circle is a pointer that points to a linked list object

	// Print Main Menu
	cout << "Welcome!" << endl;
	cout << "Let's solve the Josephus Problem!" << endl << endl;

	// Declare Variables to store user input
	int P; // P = number of people in the circle
	int N; // N = a number between 1 and 20 where every Nth person around the circle is killed each turn

	// Get user Input
	cout << "Enter the number of people in the circle, between zero and one hundred: ";
	cin >> P; // Store user input in P
	while (P < 0 || P > 100) // Check for invalid input
	{
		// Prompt user to enter a different value
		cout << "Please enter a a valid number: ";
		cin >> P; // Store user input in P
	}
	cout << "Every Nth person around the circle will be killed, choose a number for N betwen one and twenty: ";
	cin >> N; // Store user input in N
	while (N < 1 || N > 20) // Check for invalid input
	{
		// Prompt user to enter a different value
		cout << "Please enter a a valid number: ";
		cin >> N; // Store user input in N
	}

	// Build Linked List
	for (int i = 1; i <= P; i++)
	{
		// Add a number for each person to the list
		circle->AddToEnd(i);
	}

	// Eliminate People from the circle to leave one remaining
	while ((circle->Length()) != 1) // While there is still more than one person remaining in the circle...
	{
		// Move the current pointer over every N amount of spots
		for (int i = 0; i < N; i++)
		{
			circle->NextNode(); // Move the current pointer to next node
		}

		// Remove element at the current pointer
		circle->RemoveCurrent();
	}

	// Get the last remaining person and save the number
	int survivor = circle->RetrieveFront(); // Retrieve from front

	// Display the survivor
	cout << endl << "Person #" << survivor << " is the survivor of the mass execution!" << endl << endl;
}