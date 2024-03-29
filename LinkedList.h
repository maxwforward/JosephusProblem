//####################################################################################################################################
//	Linked List Header File (Template)
//	Max Forward
//####################################################################################################################################

// Library Imports
#include <iostream>

// Move everything inside of namespace std to the global scope
using namespace std;

// Header guide
#pragma once // only include this file once

//====================================================================================================================================
// Node Class
//====================================================================================================================================
template <class dataType> // alows class to store members of any type
class node
{
	// Private members of node class
	private:
		dataType element; // Declare a variable that can be any data type to use for the element at a node in the linked list
		node<dataType>* next; // Declare a variable to use as a pointer to point to the next node in a linked list

	// Public members of node class
	public:
		node(dataType data) // Constructor for node
		{
			element = data; // Set element at node equal to the data in the parameter
			next = NULL; // Set pointer to next node equal to NULL
		}

	// Setter for pointer to next node
	void setNext(node<dataType>* nextNode)
	{
		next = nextNode; // Sets value of next equal to the value in the parameter
	}

	// Getter for pointer to next node
	node<dataType>* getNext()
	{
		return next; // Return pointer to the next node
	}

	// Getter for element at node
	dataType getElement()
	{
		return element; // Return the element
	}
};

//====================================================================================================================================
// Linked List Class
//====================================================================================================================================
template <class dataType> // alows class to store members of any type
class linkedList
{
	// Private members of linkedList
	private:
		node<dataType>* head; // Declare a variable to use as a pointer to the head (first node) of the linked list
		node<dataType>* current; // Declare a variable to use as a pointer to the current node of the linked list
		node<dataType>* tail; // Declare a variable to use as a pointer to the tail (last node) of the linked list
		int size; // Declare a variable to use for the size of the list

	// Public members of linkedList
	public:
		linkedList() // Constructor for linkedList
		{
			// Initializes a linkedList whithout any nodes
			head = NULL; // Haven't added a node yet so there's no head node
			current = NULL; // Haven't added a node yet so there's no current node
			tail = NULL; // Haven't added a node yet so there's no tail node
			size = 0; // Haven't added a node yet so the size is 0
		}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that creates a node containing data and adds it to the front of the list
	//--------------------------------------------------------------------------------------------------------------------------------
	void AddToFront(dataType data)
	{
		// If there are no nodes (linked list is empty)...
		if (head == NULL) // If the pointer to head has no value...
		{
			// Create a new node with data and add it to the front
			node<dataType>* newNode = new node<dataType>(data); // newNode is a pointer to a node object
			head = newNode; // Set the head equal to the new node added to the front
			tail = newNode; // Set the tail equal to the new node added to the front because it is the only node in the list
			size++; // Increment the size when we add a node
		}
		// If there is already a head in the liked list...
		else
		{
			// Create a new node with data and add it to the front
			node<dataType>* newNode = new node<dataType>(data); // newNode is a pointer to a node object
			newNode->setNext(head); // Set newNode's pointer to the next node equal to the current head to insert it before the head
			head = newNode; // Set the head equal to the new node added to the front
			size++; // Increment the size when we add a node
		}
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that creates a node containing data and adds it to the end of the list
	//--------------------------------------------------------------------------------------------------------------------------------
	void AddToEnd(dataType data)
	{
		// If there are no nodes (linked list is empty)...
		if (tail == NULL) // If the pointer to tail has no value...
		{
			// Create a new node with data and add it to the end
			node<dataType>* newNode = new node<dataType>(data); // newNode is a pointer to a node object
			tail = newNode; // Set the tail equal to the new node added to the end
			head = newNode; // Set the head equal to the new node added to the end because it is the only node in the list
			size++; // Increment the size when we add a node
		}
		// If there is already a tail in the liked list...
		else
		{
			// Create a new node with data and add it to the end
			node<dataType>* newNode = new node<dataType>(data); // newNode is a pointer to a node object
			tail->setNext(newNode); // Set the current tail's pointer to the next node equal to newNode to insert it at the end
			tail = newNode; // set the tail equal to the new node added to the end
			size++; // Increment the size when we add a node
		}
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that creates a node containing data and adds it to the list at a specific index, returns boolean for success or failure
	//--------------------------------------------------------------------------------------------------------------------------------
	bool AddAtIndex(dataType data, int index)
	{
		// If index is invalid (index can't be negative or bigger than the size)...
		if (index < 0 || (index + 1) > size) // index is zero based so add 1 to see if it is greater than the size
		{
			return false; // Return false for failure
		}
		// If index is valid...
		else
		{
			// If index is equal to zero...
			if (index == 0)
			{
				AddToFront(data); // Add node with data to front
			}
			// If index is not equal to zero...
			else
			{
				// Move the current pointer to the node before where we want to add a node
				for (int i = 0; i < index; i++)
				{
					NextNode(); // Move pointer to next node
				}

				// Insert a node after the current pointer
				InsertAfterCurrent(data);
			}
		}
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that moves the current pointer to the next node, wraps to front if it navigates past the end
	//--------------------------------------------------------------------------------------------------------------------------------
	void NextNode()
	{
		// If current pointer is equal to NULL or tail, move it to the front of the list
		if (current == NULL || current == tail)
		{
			current = head; // Set current pointer equal to the head
		}
		// If current pointer is at any other node...
		else
		{
			current = current->getNext(); // Set current pointer to the next node
		}
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that creates a node containing data and inserts it after wherever the current pointer is pointing 
	//--------------------------------------------------------------------------------------------------------------------------------
	void InsertAfterCurrent(dataType data)
	{
		// Create a new node with data and add it after the current pointer
		node<dataType>* newNode = new node<dataType>(data); // newNode is a pointer to a node object
		newNode->setNext(current->getNext()); // Set newNode's next pointer to the current node's next pointer
		current->setNext(newNode); // Set the current node's next pointer to newNode
		size++; // Increment the size when we add a node
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that deletes the node at the current pointer and returns it's contents
	//--------------------------------------------------------------------------------------------------------------------------------
	dataType RemoveCurrent()
	{
		// If the current pointer is equal to the head...
		if (current == head)
		{
			return RemoveFromFront(); // Remove node from front and return it's contents
		}

		// If the current pointer is equal to the tail...
		if (current == tail)
		{
			return RemoveFromEnd(); // Remove node from end and return it's contents
		}

		// Declare a node pointer to store a pointer to the node that's being removed (current)
		node<dataType>* removeNode = current;

		// Move the current pointer to the node before it
		for (int i = 0; i < (size - 1); i++) // perform this (size - 1) times to get to the node before the current pointer
		{
			NextNode(); // Move current pointer to the next node
		}

		// Current pointer is now at the node before the one we are removing
		current->setNext(removeNode->getNext()); // Set the next node after current to be the next node after the removed node

		// Save the contents of the node we are going to remove
		dataType contentsOfRemovedNode = removeNode->getElement();

		// Remove the node
		delete removeNode;
		size--; // Decrement size of the linked list because we have removed a node

		// Return the contents of the removed node
		return contentsOfRemovedNode;
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that deletes the first node in the linked list and returns it's contents
	//--------------------------------------------------------------------------------------------------------------------------------
	dataType RemoveFromFront()
	{
		// Declare a node pointer to store a pointer to the node that's being removed (head)
		node<dataType>* removeNode = head;

		// Set head pointer to the node after the head (because we are removing the head)
		head = removeNode->getNext();

		// Save the contents of the node we are going to remove (head)
		dataType contentsOfRemovedNode = removeNode->getElement();

		// Remove the node
		delete removeNode;
		size--; // Decrement size of the linked list because we have removed a node

		// Set current pointer equal to the tail because it's the node before the one we removed
		current = tail;

		// Return the contents of the removed node
		return contentsOfRemovedNode;
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that deletes last node in the linked list and returns it's contents
	//--------------------------------------------------------------------------------------------------------------------------------
	dataType RemoveFromEnd()
	{
		// Declare a node pointer to store a pointer to the node that's being removed (tail)
		node<dataType>* removeNode = tail;

		// Set the current pointer to the tail
		current = tail;

		// Move the current pointer to the node before the tail
		for (int i = 0; i < (size - 1); i++) // perform this (size - 1) times to get to the node before the tail
		{
			NextNode(); // Move current pointer to the next node
		}

		// Set next node of the node before the tail to next node of the tail (NULL)
		current->setNext(tail->getNext());

		// Set tail to node before the end (because we are removing the tail)
		tail = current;

		// Save the contents of the node we are going to remove (tail)
		dataType contentsOfRemovedNode = removeNode->getElement();

		// Remove the node
		delete removeNode;
		size--; // Decrement size of the linked list because we have removed a node

		// Return the contents of the removed node
		return contentsOfRemovedNode;
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that finds the first instance of some data, specified by input, and removes it
	//--------------------------------------------------------------------------------------------------------------------------------
	void RemoveFirst(dataType data)
	{
		// Set current pointer to head so we can start at the front
		current = head;

		// If first instance of the data is at the front...
		if (current->getElement() == data)
		{
			RemoveFromFront(); // Remove the first node
			return; // Return from the function
		}
		// If first instance of the data is not at the front...
		else
		{
			// Check each node to see if it contains the data
			while (current->getElement() != data) // While the current pointer does not contain the data...
			{
				// Move current pointer to the next node
				NextNode();

				// If the current pointer is at the tail...
				if (current->getNext() == NULL) // If the next node after the current pointer is NULL...
				{
					// If tail contains the data we are looking for...
					if (current->getElement() == data)
					{
						// Remove it
						RemoveFromEnd(); // Remove the last node
						return; // Return from function
					}
					// Else, return from the function because we already searched the whole list for the data
					else
					{
						return; // Return from function
					}
				}

				// If first instance of the data is at the current pointer...
				if (current->getElement() == data)
				{
					RemoveCurrent(); // Remove current node
					return; // Return from function
				}
			}
		}
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that finds each instance of some data, specified by input, and removes it
	//--------------------------------------------------------------------------------------------------------------------------------
	void RemoveAll(dataType data)
	{
		// While the data exists in the list...
		while (ElementExists(data) == true)
		{
			RemoveFirst(data); // Remove first instance of the data
		}

		return; // Return if we don't find the data
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that returns true or false if some data, specified by input, exists in the linked list
	//--------------------------------------------------------------------------------------------------------------------------------
	bool ElementExists(dataType data)
	{
		// Set current pointer to head so we can start at the front
		current = head;

		// Check each node to see if it contains the data
		while (current->getNext() != NULL) // While next node is not NULL...
		{
			// If current node contains the data...
			if (current->getElement() == data)
			{
				return true;
			}

			// Move current pointer to the next node
			NextNode();
		}

		// If last node contains the data...
		if (current->getElement() == data)
		{
			return true;
		}

		// After we have searched the entire list, return false
		return false;
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that looks for some data, specified by input, and if found returns a pointer to the node
	//--------------------------------------------------------------------------------------------------------------------------------
	node<dataType>* Find(dataType data)
	{
		// Declare a pointer to point to the found node
		node<dataType>* foundNode;

		// Set current pointer to head so we can start at the front
		current = head;

		// Keep looping until we find the data
		while (true)
		{
			// If current node contains the data
			if (current->getElement() == data)
			{
				// Return pointer to the node
				foundNode = current;
				return foundNode;
			}

			// Move current pointer to the next node
			NextNode();
		}
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that returns the index of an item in the linked list
	//--------------------------------------------------------------------------------------------------------------------------------
	int IndexOf(dataType data)
	{
		// Create a variable to store index
		int index = 0;

		// Find the item in the list and save a pointer to it
		node<dataType>* foundItem = Find(data);

		// set current pointer to the front of the list
		current = head;

		// Keep looping until we get to the item we found
		while (true)
		{
			// If current node contains item...
			if (current == foundItem)
			{
				return index; // return index
			}

			// Move current pointer to the next node
			NextNode();

			// Increment the index when we move to the next node
			index++;
		}
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that returns the data contained in the first node, does not delete it
	//--------------------------------------------------------------------------------------------------------------------------------
	dataType RetrieveFront()
	{
		// Delcare a pointer to the node we are retrieving
		node<dataType>* retrieveNode;

		// Set node we are retrieving to the head and return it
		retrieveNode = head;
		return retrieveNode->getElement();
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that returns the data contained in the last node, does not delete it
	//--------------------------------------------------------------------------------------------------------------------------------
	dataType RetrieveEnd()
	{
		// Delcare a pointer to point to the node we are retrieving
		node<dataType>* retrieveNode;

		// Set node we are retrieving to the head and return it
		retrieveNode = tail;
		return retrieveNode->getElement();
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that returns a pointer to a node at an index specified by input, does not delete it.
	// Returns null if index is out of bounds or data does not exist
	//--------------------------------------------------------------------------------------------------------------------------------
	node<dataType>* Retrieve(int index)
	{
		// Delcare a pointer to the node we are retrieving
		node<dataType>* retrieveNode;

		// If index is out of bounds...
		if (index < 0 || index >(size - 1))
		{
			// Return NULL
			retrieveNode = NULL; // set pointer to node we are retrieving equal to NULL
			return retrieveNode;
		}
		// Index is not out of bounds...
		else
		{
			// Set current pointer to head to start at the front
			current = head;

			// Move the node to the index
			for (int i = 0; i < index; i++)
			{
				NextNode(); // Moves current pointer to next node
			}

			// Return the contents of the current pointer
			return current->getElement();
		}
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that creates an array from the contents of the linked list and returns it
	//--------------------------------------------------------------------------------------------------------------------------------
	dataType* ToArray()
	{
		// Declare a pointer to the array
		dataType* listArray;

		// Dynamicaly alocate the array based on size
		listArray = new dataType[size];

		// Set current pointer to the head
		current = head;

		// Place each element of the list inside the array
		for (int i = 0; i < size; i++)
		{
			// Set member of the array to the element of the node that current is pointing to
			listArray[i] = current->getElement();

			// Move current pointer to the next node
			NextNode();
		}

		// Return the pointer to the array
		return listArray;
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that empties out the linked list, deleting everything
	//--------------------------------------------------------------------------------------------------------------------------------
	void Empty()
	{
		// While there is at least one node remaining...
		while (size != 0)
		{
			RemoveFromEnd(); // Remove the last node
		}

		// Set all node pointers to NULL because there are no more elements in the list
		current = NULL;
		head = NULL;
		tail = NULL;
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function that returns how many elements are in the linked list
	//--------------------------------------------------------------------------------------------------------------------------------
	int Length()
	{
		return size;
	}

	//--------------------------------------------------------------------------------------------------------------------------------
	// Function for printing contents of the linked list
	//--------------------------------------------------------------------------------------------------------------------------------
	void printList()
	{
		// Save position of the current pointer so we don't lose it
		node<dataType>* savedPosition;
		savedPosition = current;

		// Set current pointer to head in order to start at the beginning of the list
		current = head;

		// While current pointer is not NULL...
		while (current != NULL)
		{
			// Print elemend at node
			cout << current->getElement() << endl;

			// Set current pointer to next node
			current = current->getNext();
		}

		// Restore the current pointer
		current = savedPosition;
	}
};