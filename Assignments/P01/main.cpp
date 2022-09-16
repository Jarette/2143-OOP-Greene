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
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
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
	int data;
	Node* next;
	Node* Prev;
	Node(int d) {
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
 
                                            /$$                                     /$$                        
                                           | $$                                    | $$                        
   /$$$$$$$  /$$$$$$  /$$$$$$$   /$$$$$$$ /$$$$$$    /$$$$$$  /$$   /$$  /$$$$$$$ /$$$$$$    /$$$$$$   /$$$$$$ 
  /$$_____/ /$$__  $$| $$__  $$ /$$_____/|_  $$_/   /$$__  $$| $$  | $$ /$$_____/|_  $$_/   /$$__  $$ /$$__  $$
 | $$      | $$  \ $$| $$  \ $$|  $$$$$$   | $$    | $$  \__/| $$  | $$| $$        | $$    | $$  \ $$| $$  \__/
 | $$      | $$  | $$| $$  | $$ \____  $$  | $$ /$$| $$      | $$  | $$| $$        | $$ /$$| $$  | $$| $$      
 |  $$$$$$$|  $$$$$$/| $$  | $$ /$$$$$$$/  |  $$$$/| $$      |  $$$$$$/|  $$$$$$$  |  $$$$/|  $$$$$$/| $$      
  \_______/ \______/ |__/  |__/|_______/    \___/  |__/       \______/  \_______/   \___/   \______/ |__/      
                                                                                                               
                                                                                                               
                                                                                                               
 
*/
public: 
	Vector() {
		head = NULL;
		tail = NULL;
	}
	Vector(int* a, int size)
	{
		head = NULL;
		tail = NULL;
		Node* traverse = head;
		for (int i = 0; i < size; i++) {
			Pushrear(a[i]);
		}
	}
	Vector(string filename) {
		head = NULL;
		tail = NULL;
		int data = 0;
		ifstream infile;
		infile.open(filename);
		
		while (!infile.eof()) {
			infile >> data;
			Pushrear(data);
		}
		infile.close();
	}
	Vector(const Vector &V) {
		head = tail = NULL;
		Node* traverse = V.head;
		while (traverse) {
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
		while (traverse->next != NULL) {
			if (traverse->data >= traverse->next->data) {
				count++;

			}


			traverse = traverse->next;
		}
		return count == 0;
		
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
		bool notSorted = true;
		int i = 0;
		while (notSorted) {
			notSorted = false;
			Node* traverse = head;
			while (traverse->next != NULL) {
				if (traverse->data > traverse->next->data)  {
					int temp = traverse->data;
					traverse->data = traverse->next->data;
					traverse->next->data = temp;
					temp = 0;
					notSorted = true;
					
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
		while (traverse) {
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
		while (traverse != NULL) {
			count++;
			traverse = traverse->next;
		}
		return count;
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
		Node* temp = new Node(d);
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			temp->next = head;
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
		V.tail->next = head;
		head->Prev = V.tail;
		head = V.head;
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
		Node* temp = new Node(d);
		if (head == NULL) {
			
			head = temp;
			tail = temp;
		}
		else {

			temp->Prev = tail;
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
		tail->next = V.head;
		V.head->Prev = tail;
		tail = V.tail;
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
		Node* temp = new Node(d);
		if (loc == 1) {
			Pushfront(d);
		}
		else if (loc >= size()) {
			Pushrear(d);
		}
		else {
			Node* traverse = head;
			for (int a = 0; a < loc - 1; a++) {
				traverse = traverse->next;
			}
			temp->next = traverse;
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
		if (!isSorted()) {
			Sort();
		}
		if (head == NULL) {
			cout << "list is empty";
		}
		else {
			Node* traverse = head;
			if (d < head->data) {
				Pushfront(d);
			}
			else if (d > tail->data) {
				Pushrear(d);
			}
			else {
				int count = 0;
				while (traverse->data <= d && traverse != NULL) {
					count++;
					traverse = traverse->next;
				}
				Pushat(count, d);
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
		int num = head->data;
		Node* temp = head;
		if (head == NULL) {
			cout << "list is empty";
			return -1;
		}
		else {
			head = head->next;
			delete temp;
			head->Prev = NULL;
			return num;
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
		int num = tail->data;
		Node* temp = tail;
		if (head == NULL) {
			cout << "list is empty";
			return -1;
		}
		else {
			tail = tail->Prev;
			delete temp;
			tail->next = NULL;
			return num;
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
		if (head == NULL) {
			cout << "list is empty";
			return -1;
		}
		else if (loc == 1) {
			return PopFront();
		}
		else if (loc >= size()) {
			return Poprear();
		}
		else {
			Node* traverse = head;
			for (int a = 0; a < loc-1; a++) {
				traverse = traverse->next;
			}
			num = traverse->data;
			traverse->Prev->next = traverse->next;
			traverse->next->Prev = traverse->Prev;
			delete traverse;
			return num;
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
		if (d == head->data) {

			return 1;
		}
		else if (d == tail->data) {

			return size();
		}
		else {
			while (traverse != NULL && traverse->data != d) {
				count++;
				traverse = traverse->next;
			}
			if (traverse == NULL) {
				cout << "Not found";
				return -1;
			}
			else {
				
				return count+1;
			}
		}
	}
	
	friend ofstream& operator<<(ofstream&, const Vector&);

	
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
	while (traverse != NULL) {
		outfile << traverse->data << " ";
		traverse = traverse->next;
	}
	return outfile;
}
void PrintArray(int* a, int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
}
int main(){

	int a[] = { 4,8,7 };
	ofstream outfile;

	outfile.open("output.dat");

	Vector V1("input.dat");

	outfile << "Jarette Greene 2143 OOP" << endl;
	outfile << "Program 1" << endl;
	outfile << endl;

	outfile << "V1 created through input file: ";
	outfile << V1;
	outfile << endl;
	outfile << endl;

	V1.Pushfront(10);
	V1.Pushfront(3);
	
	outfile << "V1 after front push: ";
	outfile << V1;
	outfile << endl;
	outfile << endl;

	V1.Pushrear(12);
	V1.Pushrear(9);
	
	outfile << "V1 after rear push: ";
	outfile << V1;
	outfile << endl;
	outfile << endl;

	V1.Pushat(4, 15);
	outfile << "V1 after pushing 15 to position 4: ";
	outfile << V1;
	outfile << endl;
	outfile << endl;

	Vector V2(a,3);
	outfile << "V2 created using array a: ";
	outfile << V2;
	outfile << endl;
	outfile << endl;

	V1.Pushfront(V2);

	outfile << "V1 after pushing V2 to the front: ";
	outfile << V1;
	outfile << endl;
	outfile << endl;

	int b[] = {0,11,6};

	Vector V3(b, 3);
	outfile << "created V3 using an array V3: "; 
	outfile << V3;
	outfile << endl;
	outfile << endl;  
	Vector V4(V3);
	outfile << "V4 created using V3: "; 
	outfile << V4;
	outfile << endl;
	outfile << endl;

	V1.Pushrear(V4);

	outfile << "V1 after Pushing V4 to the rear: "; 
	outfile << V1;
	outfile << endl;
	outfile << endl;


	V1.Pushinorder(5);

	outfile << "V1 after sorting and pushing 5 in order: ";
	outfile << V1;
	outfile << endl;
	outfile << endl;

	int num = 0;

	num =V1.PopFront();
	
	outfile << "V1 after popping off the front :"; 
	outfile << V1;
	outfile << endl;
	outfile << "Popped: " << num;
	outfile << endl;
	outfile << endl;

	num = V1.Poprear();

	outfile << "V1 afteer popping off the rear :";
	outfile << V1;
	outfile << endl;
	outfile << "popped: " << num;
	outfile << endl;
	outfile << endl;


	num=V1.Popat(5);

	outfile << "V1 after popping data at position 5: ";
	outfile << V1;
	outfile << endl;
	outfile << "popped: " << num;
	outfile << endl;
	outfile << endl;

	num = V1.Find(7);

	outfile << "7 was at position " << num << " in V1";
	outfile << endl;

	outfile.close();
}