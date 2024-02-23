/********************************************************************************************
Name: Anthony Polese		                                 Z#: Z23582157
Course: Date Structures and Algorithm Analysis (COP3530) Professor: Dr. Lofton Bullard
Due Date: 03/26/2021 	                                 Due Time: 11:59pm
Total Points: 25                                         Assignment 10B: Recursion and lists

Description: Program explores using recursive functions to interact with lists,
			 specifically with the fun() function.
*********************************************************************************************/

#include <iostream>

using namespace std;

class node
{
public:
	int data;
	node* next;
};

//function prototypes
void fun(node* start); //recursive function which prints list's data values in fun pattern 
					   //(all odd-positioned node's data values from front-to-back then back-to-front)
void add_back(node*& front, node*& back, int x); //inserts a node at the back of a list


int main() {

	//initializing empty list
	node* front = 0;
	node* back = 0;
	
	//inserting values into list
	for (int i = 1; i <= 6; i++)
	{
		add_back(front, back, i); //adds i value to a new node in back of list
	}

	//outputs certain values in list in a fun pattern
	fun(front);

	return 0;
}

/**************************************************************************************************
Name:			fun()
Pre-Conditon:	Nothing is displayed to cout
Post-Condition:	Starting with the front node, all odd-positioned (1, 3, 5, ...) node's 
				data values are displayed from front to back and then back to front.
Description:		fun() is a recursive function that outputs all odd-positioned node's data 
				values starting from the front of the list, and then it outputs these values
				again from back to front.
				Explanation of how it works: If an empty list is given, nothing is outputted.
				Then the data of the inputted node is displayed. Then the next-next node
				(if there is one) is recursively inputted into fun(). After each of these
				functions gets a value returned from its recursive fun(), it outputs its 
				parameter's node's data again, thus creating the fun pattern.
**************************************************************************************************/
void fun(node* start)
{
	if (start == NULL)				//base case
		return;
	cout << start->data;
	if (start->next != NULL)			//recursive case
		fun(start->next->next);
	cout << start->data;
}

/**************************************************************************************************
Name:			add_back()
Pre-Conditon:	Given list has n nodes
Post-Condition: Given list has n + 1 nodes, with the new node added at the back.
Description:		add_back() adds a new node with data value x to the back of the given list.
				Works with empty lists too. front and back are updated accordingly.
**************************************************************************************************/
void add_back(node*& front, node*& back, int x)
{
	//declaring and initializing new node
	node* newPtr = new node;
	newPtr->data = x;
	newPtr->next = 0;

	if (front == 0) //empty list
	{		
		front = newPtr;		 //update front and back pointer to new node
		back = newPtr;
	}
	else				//non-empty list
	{
		back->next = newPtr; //original back node points to new back node
		back = newPtr;		 //update back pointer
	}
}
