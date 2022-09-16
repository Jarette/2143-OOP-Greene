#include <iostream>
#include <fstream>
#include <string>

using namespace std;
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
class Vector {
private:
	Node* head;
	Node* tail;
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
	void Print() {
		Node* traverse = head;
		while (traverse) {
			cout << traverse->data << " ";
			traverse = traverse->next;
		}
	}
	int size() {
		int count = 0;
		Node* traverse = head;
		while (traverse != NULL) {
			count++;
			traverse = traverse->next;
		}
		return count;
	}
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
	void Pushfront(Vector V){
		V.tail->next = head;
		head->Prev = V.tail;
		head = V.head;
	}
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
	void Pushrear(Vector V){
		tail->next = V.head;
		V.head->Prev = tail;
		tail = V.tail;
	}
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