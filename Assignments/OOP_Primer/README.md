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

## Polymorphism

Polymorphsim is the ability of different functions can be called using 
the same name. There are two main forms of polymorphism:

### Static Polymorphism

Static Polymorphism is the case of where two functions having the same 
name but the different parameters. this also known as overloading 
functions

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

a method is a procedure(function) that is defined in a class and can be accessed by a class to change the attributes of the class.

```
class Myclass{
public:
    int getage();
    void setage(a);
};
```







