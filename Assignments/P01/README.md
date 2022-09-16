## P01 - Vector Class
### Jarette Greene
### Description: 

      This program is used to create a Linked List based vector class and 
   		demonstrate my ability to create a beginner level class. This is done
			by creating a linked list class that allow for pushing data (ints) to 
			to both ends of the list, at any position and also sort the list and 
			place the approipriate position, and push another vector onto another. 
			It will also allows you to pop items off the front and rear and at a 
	  	position and find the position of an item. This List will also allow you 
 			create the list using a array, items from an input file, and another vector.

### Files

|   #   | File     | Description                      |
| :---: | -------- | -------------------------------- |
|   1   |[main.cpp]https://github.com/Jarette/2143-OOP-Greene/blob/main/Assignments/P01/main.cpp| Main driver of my list program . |
|   2   |[input.dat]https://github.com/Jarette/2143-OOP-Greene/blob/main/Assignments/P01/input.dat| Input file.|
|   3   |[output.dat]https://github.com/Jarette/2143-OOP-Greene/blob/main/Assignments/P01/output.dat| output file.|

### Instructions

- This program does not require any non standard libraries 

### Example Command

  Vector V1("input.dat");	
  V1.Pushfront(10);										//pushes 1o to the front
	V1.Pushfront(3);                    //pushed 3 to the front

  
	V1.Pushrear(12);										//pushes 12 to the rear
	V1.Pushrear(9);											// pushes 9 to the rear
  
  V1.Pushat(4, 15);										//pushing 15 to the position 4
  
  Vector V2(a,3);											// creating second vector with a array of size 3
  
  V1.Pushfront(V2);										// pushing new vector to the front of old vector 
  
  Vector V4(V3);											//create fourth vector using third vector
  
  V1.Pushrear(V4);										//pushing the fourth vector to the rear of the first 
  
  V1.Pushinorder(5);										// pushing 5 to approipriate spot in first vector
  
  num =V1.PopFront();										//popping the front off the Vector
  
  num = V1.Poprear();										//popping the rear off the vector 
  
  num=V1.Popat(5);										// popping the data at the 5th position
  
  num = V1.Find(7);										//finding the number 7 in the list


