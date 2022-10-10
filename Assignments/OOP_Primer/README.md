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



