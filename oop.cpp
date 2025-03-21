#include <iostream>
#include <string>
// cpp -> c with classes
// convention case: camelCase

// oop pillars!
// abstraction -- makes something easier to understand by hiding complexity - object
// encapsulation -- garanting access to private data only by controlling public interfaces - private, methods(getters and setters)
// inheritance -- derived classes can inherit properties from parent classes
// polymorphism -- 

// class: group of functions and variables that describes the structure
// object: instance of that structure (class)
// instance of a class: a class in use, an initialized class, an object
// methods: functions used by a class

// convention: class names are UpperCamelCase
class   Person {
    // private: functions and variables only accesible "inside", by other funcs/vars of the same class/objects
    private:
        std::string firstName;
        std::string lastName;

    // public: controls what/how this data is going to be initiaized and returned outside class/obj
    public:
        // constructor: called when a -new- class is initialized. same name as class
        Person(std::string first, std::string last) {
            this->firstName = first;
            this->lastName = last;
        }
        // default constructor: initializes Person if declared but not initialized
        Person() { this->firstName = "", this->lastName = ""; } ;
        // alternative declaration:
        // Person(std::string first, std::string last): firstName(first), lastName(last) {}
        //
        // destructor: called when a class is -deleted- (or automatically when the scope ends - for stack allocated classes). ~ + same name as class. it has no params
        ~Person();

        // getters and setters
        void setFirstName(std::string first) { this->firstName = first; }
        void setLastName(std::string last) { this->lastName = last; }
        std::string getFullName () { return this->firstName + " " + this->lastName; }

        void printFullName() { std::cout << this->firstName << " " << this->lastName << std::endl; }
};

// parent class (base class):
// child class (derived class):

// Badass is a child class, derived from Person
// by writting this way, all public data of Person becomes private:
// class Badass : Person {}
// this way we can access public Person data by a Badass instance:
class Badass : public Person {
    std::string specialty;

    public:
        Badass() = default;
        Badass(std::string firstName, std::string lastName, std::string specialty): Person(firstName, lastName), specialty(specialty) {}
        std::string getSpecialty() { return this->specialty; }

};

int main() {
    // NOTE: p is stack allocated; limited by scope, in the end the descructor is called by default
    Person p("Antonio", "Rodrigues");
    // object p is an instance of class Person wich has a method printFullName
    p.printFullName(); 


    Badass n1;
    n1.setFirstName("Tony");
    n1.setLastName("Jones");
    n1.printFullName(); 
}
