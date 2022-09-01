
 
/*********************************************************************************
 * 
 * Author:      Jarette Greene
 * Email:       Jarettegreene09@gmail.com
 * Label:       A03
 * Title:       Basic Project Organisation 
 * Course:      CMPS 2143
 * Semester:    Spring 2022 
 * 
 * Description: 
 *      This program is used to practice the the approipraite format for Commenting 
 *      in any of our programming assignments.
 * 
 * Usage: 
 *      - N/A
 * 
 * Files"
 *      main.cpp
 * *******************************************************************************/
#include <iostream>                  // allows access to the iostream library  

using namespace std;                //  allows for the use of standards

/**
 * CircularArrayQue
 * 
 * Description: 
 *      This class implements a circular Array Based Queue. This class allows to store 
 *      data in a dynamic array that can store and remove data through the rules of 
 *      Queue by adding data at rear of the list and removing data from the front of the 
 *      list. This list is also circular that means when the all the space of in the list
 *      it will go back to inserting and removing from the front of list ensuring it will
 *      run out of space.
 * 
 * Public Methods:
 *                                      CircularArrayQue()
 *                                      CircularArrayQue(int size)
 *      void                            Push(int item)
 *      int                             Pop()
 *      friend                          ostream &operator<<(ostream &os, const CircularArrayQue &other)   
 *      
 * Private Methods:
 * 
 *      int                             *Container
 *      int                             Front
 *      int                             Rear
 *      int                             QueSize
 *      int                             CurrentSize
 *      void                            init(int size=0)
 *      bool                            Full()                            
 *  
 * Usage: 
 *      
 *      CircularArrayQue   C1()         // Creates list with the size of 10
 * 
 *                                      // or
 * 
 *      CirculatArrayQue   C1(size)     // allows the user to create the list of whatever
 *                                      // they want
 *      Push(9)                         // adds the number 9 to the list
 *      Pop()                           // removes the front item
 *      cout << C1                      // allows you to display the entire list in one command
 *           
 */
class CircularArrayQue {
private:
    int *Container;                             // Pointer to dynaimically allocate array space 
    int Front;                                  // indicates the front of the array
    int Rear;                                   // indicates the rear of the array 
    int QueSize;                                // items in the queue
    int CurrentSize;                            // stores amount of space of the array currently in use 
    void init(int size = 0) {                   // initializing variables to zero
        Front = Rear = CurrentSize = 0;         
        QueSize = size;
    }
    /**
     * Private: Full
     * 
     * Description: 
     *      Checks to see if the array is full
     * 
     * Params: 
     *      N/A
     * 
     * Returns:
     *      Returns true of falso based on the status of the list 
     */

    bool Full() {                               // checking to see if the array is filled 
        return CurrentSize == QueSize;
    }

public:

    CircularArrayQue() {                        // constructor that sets the size of the array to 10
        Container = new int[10];
        init(10);
    }
    CircularArrayQue(int size) {                // constructor that allows the user set the size of the array 
        Container = new int[size];
        init(size);
    }
/**
 * Public: Push 
 * 
 * Description:
 *      Adds an item to the back of the queue
 * 
 * Param
 * 
 *      int     : the data that will be added to the program
 * 
 * Returns: 
 * 
 *      N/A
 * 
 */
   void Push(int item) {                        // function to add to the queue
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }
/**
 * Public: Pop
 * 
 * Description:
 *      Removes an item from the front of the queue
 * 
 * Param
 *      N/A
 * 
 * Returns:
 *      returns the piece of data that was popped off the list 
 */
    int Pop() {                                 // function that removes from the queue 
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other); // allows class to access this function
};
/**
     * Public: &operator<<
     * 
     * Description:
     *      This Function overloads the cout function allowing you to use cout to display an
     *      entire array without having to cout each individual item in the array 
     * 
     * Params:
     *      ostream                 : access to the cout function     
     *      CircularArrayQue        : circular array class 
     * 
     * Returns:
     *      ostream &os             : allows for the dispaly of the class array 
 */

ostream &operator<<(ostream &os, const CircularArrayQue &other) {  // function that allows for the overloading of cout 

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) { 
        os << other.Container[i] << " "; 
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);                 // creates array with size of 5


    C1.Push(1);                             // adds the number 1 to the array 
    C1.Push(2);                             // adds the number 2 to the array 
    C1.Push(3);                             // adds the number 3 to the array
   
    cout << C1 << endl;                     // displays the whole list 

    
}    