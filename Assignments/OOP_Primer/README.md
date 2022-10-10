# OOP Terminology

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
![dynamic](https://imgur.com/YOPneLH)







