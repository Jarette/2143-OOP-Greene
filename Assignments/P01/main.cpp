/*****************************************************************************
*                    
*  Author:           Jarette Greene
*  Email:            jarettegreene09@gmail.com
*  Label:            P01
*  Title:            Linked List Vector Class
*  Course:           CMPS 2143
*  Semester:         Fall 2022
* 
*  Description:
*       	This program is used to create a Linked List based vector class and 
*			demonstrate my ability to create a beginner level class. This is done
*			by creating a linked list class that allow for pushing data (ints) to 
* 			to both ends of the list, at any position and also sort the list and 
* 			place the approipriate position, and push another vector onto another. 
* 			It will also allows you to pop items off the front and rear and at a 
*			position and find the position of an item. This List will also allow you 
* 			create the list using a array, items from an input file, and another vector.
* 
*  Usage:
*        N/A
* 
*  Files:            
*			main.cpp				:driver program
*			input.dat				:file to collect data to make list
*			output.dat				:to display list
*
*****************************************************************************/
//Neccesary Libraries 
#include <iostream>				
#include <fstream>
#include <string>

using namespace std;				//allows for the use of standard library 
/**
 * Node
 * 
 * Description:
 *      Creating struct to create a node to store data and hold pointers 
 * 		for next node and previous node.
 * 
 * Member variables:
 * 				int 				data
 * 				Node*				next
 * 				Node*				prev
 * 
 * Public Method:
 * 				
 * 									Node(int d)
 *  
 * Usage: 
 * 
 *      Node(d)						// creates an instance of a node
 *      
 */
struct Node {
	int data;				// the data that will be stored in the lisrt 
	Node* next;				// node pointing to the new node
	Node* Prev;				// node pointing to previous node 
	Node(int d) {			// constructor to create a new node
		data = d;
		next = NULL;
		Prev = NULL;
	}
};
/**
 * Vector
 * 
 * Description:
 *      This class implements a linked list based class that allows you
 * 		and allows you to add items to the rear and front of the list, at 
 * 		any position you would like, in approipriate order and push another 
 * 		vector class to the front or rear of the current list. It will also 
 * 		allows you to pop items off the rear or front and at any position you 
 * 		would like and also find any item in the list. This will also allow you to 
 * 		create a list using an array, items from a file and another vector.
 * 
 * Public Methods:
 *      						Vector()
 * 								Vector(int* a, int size)
 * 								Vector(string filename)
 * 								Vector(const Vector &V)
 * 		bool					isSorted()
 * 		void					Sort()
 * 		void					Print()
 * 		int size				size()
 * 		void 					Pushfront(int d)
 * 		void					Pushfront(Vector V)
 * 		void 					Pushrear(int d)
 * 		void 					Pushrear(Vector V)
 * 		void 					Pushat(int loc,int d)
 * 		void					Pushinorder(int d)
 * 		int						Popfront()
 * 		int 					Poprear()
 * 		int 					Popat(int loc)
 * 		int 					Find(int d)
 * 		friend ofstream&		<<operator(ofstream&, const Vector&)
 * 				
 * Private Methods:
 *     	Node*					head
 * 		Node*					head
 * 
 * Usage: 
 * 
 *      Vector(a,5) 			//create a vector using an array of size 5
 *      Vector("input.dat")		//creates a vector using data from a file 
 * 		Vector(V)				//creates a vector using another vector
 * 		V1.Pushfont(1)			//pushes 1 to the front of list
 * 		V1.Pushfront(V2)		//Pushes vector to the front of list
 * 		V1.Pushrear(1)			//pushes  1 to the rear of the vector
 * 		V1.Pushrear(V2)			//pushes vector to the rear of list
 * 		V1.Pushat(2,5)			//pushes 5 at the 2nd location in list
 * 		V1.Pushinorder(2)		//sorts list then places 2 in correct order
 * 		V1.Popfront				//pops off the front of the list
 * 		V1.Poprear				//pops off the rear of the list 
 * 		V1.Popat(4)				//pops the item at position 4 in the list 
 * 		V1.Find(2)				//locates the position of 2 in the list 
 * 		cout << V1				// displays entire list
 */
class Vector {
private:
	Node* head;
	Node* tail;
/*
 
         /$$$$$$                                  /$$                                     /$$                                  
        /$$__  $$                                | $$                                    | $$                                  
       | $$  \__/  /$$$$$$  /$$$$$$$   /$$$$$$$ /$$$$$$    /$$$$$$  /$$   /$$  /$$$$$$$ /$$$$$$    /$$$$$$   /$$$$$$   /$$$$$$$
       | $$       /$$__  $$| $$__  $$ /$$_____/|_  $$_/   /$$__  $$| $$  | $$ /$$_____/|_  $$_/   /$$__  $$ /$$__  $$ /$$_____/
       | $$      | $$  \ $$| $$  \ $$|  $$$$$$   | $$    | $$  \__/| $$  | $$| $$        | $$    | $$  \ $$| $$  \__/|  $$$$$$ 
       | $$    $$| $$  | $$| $$  | $$ \____  $$  | $$ /$$| $$      | $$  | $$| $$        | $$ /$$| $$  | $$| $$       \____  $$
       |  $$$$$$/|  $$$$$$/| $$  | $$ /$$$$$$$/  |  $$$$/| $$      |  $$$$$$/|  $$$$$$$  |  $$$$/|  $$$$$$/| $$       /$$$$$$$/
        \______/  \______/ |__/  |__/|_______/    \___/  |__/       \______/  \_______/   \___/   \______/ |__/      |_______/ 
                                                                                                                               
                                                                                                                               
                                                                                                                               
 
*/
public: 
	Vector() {					//default constructor 
		head = NULL;			//setting head and tail to NULL
		tail = NULL;
	}
	Vector(int* a, int size) 	//constructor to accept an array and its size to create a new vector
	{
		head = NULL;			
		tail = NULL;	
		for (int i = 0; i < size; i++) { 	// for loop to push the elements of the array to the rear of the list
			Pushrear(a[i]);
		}
	}
	Vector(string filename) {	// Constructor that accepts data from a file
		head = NULL;
		tail = NULL;
		int data = 0;			// variable to accept data from file
		ifstream infile;
		infile.open(filename);	//opening file
		
		while (!infile.eof()) {	//while loop that repeats until the file is empty and pushes the data to end of list
			infile >> data;		
			Pushrear(data);		
		}
		infile.close();
	}
	Vector(const Vector &V) {	//Constructor to create a vector using another vector 
		head = tail = NULL;
		Node* traverse = V.head;
		while (traverse) {		//while loop that traverses the whole list and pushes the data from the V2 to V1
			Pushrear(traverse->data);
			traverse = traverse->next;
		}
		

	}
	 /**
     * Public : isSorted
     * 
     * Description:
     *      checks to see if the list is sorted
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      Bool 			a true or false if the list is sorted
     */
	bool isSorted() {	
		int count = 0;
		
		Node* traverse = head;
		while (traverse->next != NULL) { 	//while loop to traverse the list until the end 
			if (traverse->data >= traverse->next->data) {	//Checks if current list element is greater than the one ahead of it 
				count++;	// increments count if switch is made

			}


			traverse = traverse->next;
		}
		return count == 0;	//returns true if the count is 0 because that means the if statment never ran 
		
	}
	 /**
     * Public : Sort
     * 
     * Description:
     *      Sorts the Vector list
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      Vector 		returns a sorted list
     */
	void Sort() {
		bool notSorted = true;		//assumes the list is notsorted 
		int i = 0;
		while (notSorted) {			//while loop that runs while the list is still "sorted"
			notSorted = false;		//notSorted to false to leave loop
			Node* traverse = head;
			while (traverse->next != NULL) {	//while loop that runs while not at the end of the loop
				if (traverse->data > traverse->next->data)  { //checks if the current element is greater than future element 
					int temp = traverse->data;				// performs a basic swap
					traverse->data = traverse->next->data;
					traverse->next->data = temp;
					temp = 0;
					notSorted = true;	// then sets notsorted to true so the loops continue repeating until the if statement is neever entered
					
				}
				traverse = traverse->next;
				
				
			}
		}
	}
	 /**
     * Public : Print
     * 
     * Description:
     *      displays the vector list
     * 
     * Params:
     *      N/A
	 * 
     * Returns:
     *      N/A
     */
	void Print() {	
		Node* traverse = head;
		while (traverse) {				// traversing list and displayng data as it traverses
			cout << traverse->data << " ";
			traverse = traverse->next;
		}
	}
	 /**
     * Public : size
     * 
     * Description:
     *      checks the size of the list
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      int 	:the size of the list
     */
	int size() {
		int count = 0;
		Node* traverse = head;
		while (traverse != NULL) {			// traverse entire list
			count++;						// increments count as it traverses
			traverse = traverse->next;
		}
		return count;						//returns size of the list
	}
	 /**
     * Public : Pushfront
     * 
     * Description:
     *      Adds item to the front of the ist 
     * 
     * Params:
     *    
     *      int     :  data to be added
     * 
     * Returns:
     *      N/A
     */
	void Pushfront(int d){
		Node* temp = new Node(d); 	// creating new node
		if (head == NULL) {			// checking if the list is empty 
			head = temp;
			tail = temp;
		}
		else {
			temp->next = head;		//adds node to the front of list and repoints pointers
			head->Prev = temp;
			head = temp;
		}
	}
	 /**
     * Public : Pushfront
     * 
     * Description:
     *      adds another vector class list ot the front of the current list
     * 
     * Params:
     *      Vector		V the vector to be pushed
     * 
     * Returns:
     *      N/A
     */
	void Pushfront(Vector V){ 	
		V.tail->next = head;		// attaching the tail of the new vector to the head of the current vector 
		head->Prev = V.tail;		// attaches the previous head to the point to the tail of the new vector 
		head = V.head;				// approipriately reassigns the head pointers
	}
	 /**
     * Public : Pushrear
     * 
     * Description:
     *      Adds item to the list at the back
     * 
     * Params:
     *     
     *      int     	data: the data to be added 
     * 
     * Returns:
     *      N/A
     */
	void Pushrear(int d){
		Node* temp = new Node(d);	//creating new node
		if (head == NULL) {			// checking if the list is empty 
			
			head = temp;
			tail = temp;
		}
		else {						

			temp->Prev = tail;		// attaches new node to the back of list and move approipriate pointers 
			tail->next = temp;
			tail = temp;
		}
	}
	 /**
     * Public : Pushrear
     * 
     * Description:
     *      Pushes another vector to the back of the current vector 
     * 
     * Params:
     *      Vector			V : the vector to be pushed 
     * 
     * Returns:
     *      N/A
     */
	void Pushrear(Vector V){
		tail->next = V.head;		//assigns tail of current vector to head of new pointer 
		V.head->Prev = tail;		//assigns head of new vector to tail of the current pointer 
		tail = V.tail;				// reassgns tail approipriately 
	}
	 /**
     * Public : Pushat
     * 
     * Description:
     *      adds item to the list at a specified location
     * 
     * Params:
     *      int				d: data to be added 
     * 		int				loc: location to add data
     * Returns:
     *      N/A
     */
	void Pushat(int loc, int d){
		Node* temp = new Node(d);	//create new node
		if (loc == 1) {				//checks if the requested location is the first position and pushes node to the front 
			Pushfront(d);			
		}
		else if (loc >= size()) {  //checks if the requested location is the back of the list and pushes to the rear
			Pushrear(d);
		}
		else {						// if the spot is in the middle 
			Node* traverse = head;
			for (int a = 0; a < loc - 1; a++) {	 //traverses to get to the position 
				traverse = traverse->next;
			}
			temp->next = traverse;				//adds node to the middle of the list 
			temp->Prev = traverse->Prev;
			traverse->Prev->next = temp;
			traverse->Prev = temp;
		}
	}
	 /**
     * Public : Pushinorder
     * 
     * Description:
     *      sorts list then adds item in approipriate position 
     * 
     * Params:
     *      int			d: data to be added 
     * 
     * Returns:
     *      N/A
     */
	void Pushinorder(int d){
		if (!isSorted()) {		// checks if list is sorted if not sorts it 
			Sort();
		}
		if (head == NULL) {		//checks if list is empty 
			cout << "list is empty";
		}
		else {					
			Node* traverse = head;
			if (d < head->data) {		// checks if node data is less than head then pushes to the front 
				Pushfront(d);
			}
			else if (d > tail->data) {
				Pushrear(d);			//checks if node data is greater than the tail then rear pushes 
			}
			else {
				int count = 0;
				while (traverse->data <= d && traverse != NULL) {	//finds where the approipriate position of the node data should be 
					count++;
					traverse = traverse->next;
				}
				Pushat(count, d); 		// pushes data at approipriate spot
			}

		}
	}
 /**
     * Public : Popfront
     * 
     * Description:
     *      removes item from the front of the list and gives you back the item
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      int  	The item that was popped off the list 
     */
	int PopFront(){			
		int num = head->data;   		// gets data from node 
		Node* temp = head;
		if (head == NULL) {				//checks if list is empty
			cout << "list is empty";
			return -1;
		}
		else {							
			head = head->next;			//reassigns the head pointer 
			delete temp;				//deletes old head
			head->Prev = NULL;			//repoints head Prev to NULL
			return num;					// returns the data that was stored in the node 
		}
	}
	 /**
     * Public : Poprear
     * 
     * Description:
     *      Removes item off the back of the list and gives you back the item
     * 
     * Params:
     *      N/A
	 * 
     * Returns:
     *      int 	 : the item that was popped off of the list
     */
	int Poprear(){
		int num = tail->data;			//gets data from node to be removed 
		Node* temp = tail;			
		if (head == NULL) {				//checks if list is empty 
			cout << "list is empty";
			return -1;
		}
		else {
			tail = tail->Prev;			//reassigns new tail
			delete temp;				//delete old node 
			tail->next = NULL;			//reassigns tail next to null
			return num;					//returns the data that was removed from list 
		}
	}
	 /**
     * Public : Popat
     * 
     * Description:
     *      removes the item at a specified location then gives you back that item
     * 
     * Params:
     *      int 	loc: the location of the item you want ot remove
     * 
     * Returns:
     *      int 	:returns the item that was removed
     */
	int Popat(int loc){
		int num;
		if (head == NULL) {				//checks if list is empty 
			cout << "list is empty";
			return -1;
		}
		else if (loc == 1) {			// checks if the location is at the front then pops from front 
			return PopFront();
		}
		else if (loc >= size()) {		// checks if location is in the rear then pushes from the rear 
			return Poprear();
		}
		else {
			Node* traverse = head;
			for (int a = 0; a < loc-1; a++) {	//goes to location of the node to be deleted 
				traverse = traverse->next;
			}
			num = traverse->data;			// gets data from node 
			traverse->Prev->next = traverse->next;	//removes and reassigns nodes
			traverse->next->Prev = traverse->Prev;
			delete traverse;				// deletes removed node 
			return num;						// returns data from node 
		}
	}
	 /**
     * Public : Find 
     * 
     * Description:
     *  	locates the position of the item you request and gives you that position 	
     * 
     * Params:
     *      int 	d: the item you are looking for 
     * 
     * Returns:
     *      int 	:the position of the item you are looking for in the list 
     */
	int Find(int d){
		Node* traverse = head;
		int count = 0;
		if (d == head->data) {			// checks if the data youre looking for is located to the front of list 

			return 1;
		}
		else if (d == tail->data) { 	// checks if the data is at the back of the list 

			return size();
		}
		else {
			while (traverse != NULL && traverse->data != d) {  	// find the location of data in the list 
				count++;
				traverse = traverse->next;
			}
			if (traverse == NULL) {				// if the data is not in the list 
				cout << "Not found";
				return -1;
			}
			else {
				
				return count+1;					// returns te postion of the data 
			}
		}
	}
	
	friend ofstream& operator<<(ofstream&, const Vector&); // allows for class to use this function 

	
};
 /**
     * Public : operator <<
     * 
     * Description:
     *      overloads the << operator to allow to display the entire list at once 
     * 
     * Params:
     *      ofstream&		out:<< the outfile variable that allows for displaying data 
	 * 		const Vector&	V1: the vector that is being displayed 
     * 
     * Returns:
     *      ofstream&	 	ofstream that allows for displaying of data 
     */
ofstream& operator<<(ofstream& outfile, const Vector& V) {
	Node* traverse = V.head;
	while (traverse != NULL) {					//goes through entire list and dispalays as it traverses
		outfile << traverse->data << " ";
		traverse = traverse->next;
	}
	return outfile;
}
/*
 
  /$$      /$$           /$$                 /$$$$$$$            /$$                              
 | $$$    /$$$          |__/                | $$__  $$          |__/                              
 | $$$$  /$$$$  /$$$$$$  /$$ /$$$$$$$       | $$  \ $$  /$$$$$$  /$$ /$$    /$$ /$$$$$$   /$$$$$$ 
 | $$ $$/$$ $$ |____  $$| $$| $$__  $$      | $$  | $$ /$$__  $$| $$|  $$  /$$//$$__  $$ /$$__  $$
 | $$  $$$| $$  /$$$$$$$| $$| $$  \ $$      | $$  | $$| $$  \__/| $$ \  $$/$$/| $$$$$$$$| $$  \__/
 | $$\  $ | $$ /$$__  $$| $$| $$  | $$      | $$  | $$| $$      | $$  \  $$$/ | $$_____/| $$      
 | $$ \/  | $$|  $$$$$$$| $$| $$  | $$      | $$$$$$$/| $$      | $$   \  $/  |  $$$$$$$| $$      
 |__/     |__/ \_______/|__/|__/  |__/      |_______/ |__/      |__/    \_/    \_______/|__/      
                                                                                                  
                                                                                                  
                                                                                                  
 
*/
int main(){

	int a[] = { 4,8,7 };									//creating an array named a 
	ofstream outfile;										//creating out file cariable

	outfile.open("output.dat");								//opening output file

	Vector V1("input.dat");									//creating vector using data from file 

	outfile << "Jarette Greene 2143 OOP" << endl;
	outfile << "Program 1" << endl;
	outfile << endl;

	outfile << "V1 created through input file: ";			// displaying Vector
	outfile << V1;
	outfile << endl;
	outfile << endl;

	V1.Pushfront(10);										//pushes 1o to the front
	V1.Pushfront(3);										//pushes 3	to the fron
	
	outfile << "V1 after front push: ";						//displays Vector after push
	outfile << V1;
	outfile << endl;
	outfile << endl;

	V1.Pushrear(12);										//pushes 12 to the rear
	V1.Pushrear(9);											// pushes 9 to the rear
	
	outfile << "V1 after rear push: ";						//displays vector after rear push
	outfile << V1;
	outfile << endl;
	outfile << endl;

	V1.Pushat(4, 15);										//pushing 15 to the position 4
	outfile << "V1 after pushing 15 to position 4: ";		//displaying list after push 
	outfile << V1;
	outfile << endl;
	outfile << endl;

	Vector V2(a,3);											// creating second vector with a array of size 3
	outfile << "V2 created using array a: ";				// displaying new vector
	outfile << V2;
	outfile << endl;
	outfile << endl;

	V1.Pushfront(V2);										// pushing new vector to the front of old vector 

	outfile << "V1 after pushing V2 to the front: ";		// displaying original vector after pushing the new vector 
	outfile << V1;
	outfile << endl;
	outfile << endl;

	int b[] = {0,11,6};										//creating array named b

	Vector V3(b, 3);										// creating thrid vector using array sized 3
	outfile << "created V3 using an array V3: "; 			// displaying third vector 
	outfile << V3;
	outfile << endl;
	outfile << endl;  
	Vector V4(V3);											//create fourth vector using third vector 
	outfile << "V4 created using V3: "; 					//displaying fourth vector
	outfile << V4;
	outfile << endl;
	outfile << endl;

	V1.Pushrear(V4);										//pushing the fourth vector to the rear of the first 

	outfile << "V1 after Pushing V4 to the rear: "; 		//displaying first vector after pushing the fourth vector
	outfile << V1;
	outfile << endl;
	outfile << endl;


	V1.Pushinorder(5);										// pushing 5 to approipriate spot in first vector

	outfile << "V1 after sorting and pushing 5 in order: "; //displaying sorted vector with 5 in its approipriate spot
	outfile << V1;
	outfile << endl;
	outfile << endl;

	int num = 0;

	num =V1.PopFront();										//popping the front off the Vector 
	
	outfile << "V1 after popping off the front :"; 			// displaying vector after popping the front 
	outfile << V1;
	outfile << endl;
	outfile << "Popped: " << num;							// displaying the data that was popped 
	outfile << endl;
	outfile << endl;

	num = V1.Poprear();										//popping the rear off the vector 

	outfile << "V1 afteer popping off the rear :";			//displaying vector after popping the rear 
	outfile << V1;
	outfile << endl;
	outfile << "popped: " << num;							//displaying the data that was popped off the vector
	outfile << endl;
	outfile << endl;


	num=V1.Popat(5);										// popping the data at the 5th position 

	outfile << "V1 after popping data at position 5: ";		//displaying data after pop
	outfile << V1;
	outfile << endl;
	outfile << "popped: " << num;							//displaying the number that was popped 
	outfile << endl;
	outfile << endl;

	num = V1.Find(7);										//finding the number 7 in the list

	outfile << "7 was at position " << num << " in V1";		//displaying the position of the number 7 in the list 
	outfile << endl;

	outfile.close();
}