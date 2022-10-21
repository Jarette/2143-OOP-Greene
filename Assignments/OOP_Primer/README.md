# OOP Terminology

## Object Oriented Programming

Object Oriented Programming (OOP) is a computer programming model that organizes its process in objects through classes that are created by grouping attributes and methods together

## Abstraction

Abstraction is a fundamental concept of computer science but also a key 
concept of Object Oriented Programming. Abstraction simply is the 
practice showing only the relevant information and hiding all
the irrelevant information.

![abstraction example](https://journaldev.nyc3.digitaloceanspaces.com/2019/09/data-abstraction.png)


## Encapsulation

Encapsulation is the grouping of data and functions together and hiding 
thier implementation by restricting the access using access modifiers
to keep selected pieces private.

### Example of Encapsulation: 
```
class Myclass{
    private:

        // attributes and methods

    protected:
    
        // attributes and methods

    public:

        // attributes and methods
}
```

## Inherticance

Inheritance is an object oriented programming technique that allows you 
to create a class using the attribute and methods of another class.

### Example of Inheritance:

```
    // C++ program to demonstrate function overriding

    #include <iostream>
    using namespace std;

    class Base {
    public:
        void print() {
            cout << "Base Function" << endl;
        }
    };

    class Derived : public Base {
    public:
        void print() {
            cout << "Derived Function" << endl;
        }
    };

    int main() {
        Derived derived1;
        derived1.print();
        return 0;
    }
```
** Output **
```
    Derived Function
```
## Multiple Inheritance

There are many types of inheritance one of which is Multiple inheritance 
This is when a class derives from one of more parent class.

### Example of Multiple Inheritance

'''
class A{
 // class methods and attributes
};
class B{
 // class methods and attributes
};
Class C: public A, public B{
 // class derived from both A and B
};

## Composition

Composition is similar to inheritance where it allows another class to 
use the attributes and methods of another class but achieves this 
differently. Composition is achieved by creating an instance of a class 
as an attribute of another class. 

### Example  of Composition
'''
class A{
public:
    void print(){
        cout << "printed";
    }
    };
class B{
 private:
    A A1;
public:
    B(){
        A1.print();
    }
    };
    int main() {
    B B1;
}
'''
Output
'''
printed
'''

## Polymorphism

Polymorphsim is the ability of different functions can be called using 
the same name. There are two main forms of polymorphism:

### Static Polymorphism

Static Polymorphism is the case of where two functions having the same 
name but the different parameters. this also known as overloading 
functions. This is also reffered to as the Overloading and this can be 
done to operators 

### example of static polymorphism:

```
void display(int);
void display(float);
void display(int, float);
```

### Dynamic Polymorphism

Dynamic Polymorphism is this when functions are defined using the keyword 
virtual.

### example of dynaimic polymorphism

![virtual](https://miro.medium.com/max/1300/1*4ioFiXqE2ddWgKWVpc_F5Q.png)

## Class

A class is considered a blue print for a data type. this blue print is 
what is used to create an object can do. This is becasue in the 
definition of this class is where there are all the attributes and 
methods that the class will have access too.

### example of a class

```
class Myclass{
private:

    int name
    int age

public:
    int getage();
    void setage(a);
};
```
## Subclass

A subclass is a class that is derived from another class sometimes 
refered to as child class and the original class as the parent class

## Object

An object is created from a class and this object has access to methods 
and attributes in the public section of a class

### example of an object
```
Myclass class1
Myclass class2

class1.getage();
```

## Attributes / Properties 

Attributes are the changeable characteristics of a component of a 
program. Classes have their own attributes that can only be changed 
within the class.

### examples of attributes:

```
class Myclass{
private: 
    int name;
    int age;
 };
```

## Methods

a method is a procedure(function) that is defined in a class and can be 
accessed by a class to change the attributes of the class.

```
class Myclass{
public:
    int getage();
    void setage(a);
};
```

## Class variable

A class variable is a variable that is defined in a class and only a 
single instance of this variable is created no matter how many instances 
of the class is created. This is done by using the static keyword

### example of class variables:

```
class Myclass{
private:
    static int a = 0;
    int b; 

};
```

## Instance Variables

Instance variables are variables that are defined with every instance of 
an object being created that are distinct for each object.

### example of instance variables

```
class Myclass{
private:
    int a;
    int b;
    int c;
};
```

## Member Varibles 

Member variables are similar to instance variables and in some languages 
are all the same. Member variables are variables that are associated with 
a specfic object and can be accessed by methods in the class. These 
variables can share names with methods.

```
class Myclass{
private:
    int a;
    int b;
public:
    int Add(){
        return a+b;
    }
};
```
## Constructor
  
A constructor is a member function that shares the name of the class and
is used to initialize the variables in a class.

### exampe of a constructor 

```
class Myclass{
private:
    int a;
    int b;
public:
    Myclass(){
        a = 1;
        b = 2;
    }
};
```

## Access Modifiers

Access modifiers are key words used when creatng a class that restrict the
access of certian pieces of data for different objects or other classes 
that might be derived from this class. These access modifiers are:

### Private

Private restricts access of data to only methods or functions that are 
found within the class itself. So objects and outside functions would not 
be able change an of the data located under this heading.

### Protected

Protected is similar to private but allows access to classes that are derived from the original class but not objects that are created from 
the class

### Public 

The public key word allows for classes, subclasses and objects that 
created using the class to get access to any attributes and methods that 
were under this heading.

### example of use of access modifiers

```
myclass{
private:
    string address
    int SSN
Protected:
    string name
Public:
    string getname();
}
```

# Other Keywords important in OOP

## Friend

The Friend keyword allows for classes to have access to functions that are not defined outside of the class.

### example of using the Friend keyword

```
class Myclass{
private:
    int a;
public: 
    friend void print();
};

void print(){
    cout << "friend keyword";
}
```

## Methods

These are functions that are apart of a class. These functions can be 
called by the object if in public using the dot (.) or -> operator.

### example of  a method

'''
class A{
public:
    void print(){
        cout << "print";
    }
};

int main(){

    A A1

    A1.print();
}
'''
Output
'''
print
'''

## Static Keyword

The static keyword caused what is created using it to be stored on the 
heap which means that it hold its values in memory until the program ends 
and even outside of itsscope similarly to declaring a global variable.The 
static keyword can be added to variable in functions, class objects,
member variables in class, and methds in class. 

### example of static keyword
'''
void counter(){
    static int count=0;
    cout << count++;
     }
int main(){
    for(int i=0;i<5;i++){
        counter();
    }  
}
'''
Output
'''
0 1 2 3 4
'''

## Virtual Keyword

This virtual keyword is used to tell the compiler that a function in a 
base class can be overwritten by a function in a derived class. The 
virtual is only neccesary if the class calling the function is created
as a pointer  

### example of virtual keyword 

'''
class Base {
public:
   virtual void print() {
    // code
    }
};
class Derived : public Base {
public:
    void print() {
    // code
    }
};
int main() {

    Derived derived1;
    Base* base1 = &derived1;

    // calls function of Base class

    base1->print();
    return 0; 
}
'''
