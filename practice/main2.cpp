#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
    int age;
    int height;
    int weight;
    string name;

public:
    void setAge(int age)
    {
        this->age = age;
    }
    int getAge()
    {
        return this->age;
    }

    void setHeight(int height)
    {
        this->height = height;
    }
    int getHeight()
    {
        return this->height;
    }

    //if we write here virtual, it may be overridden in the child classes
    virtual void print()
    {
        cout << "Age: " << age << ". Height: " << height << ". Weight: " << weight << ". Name: " << name << endl;
    }
    
    //default c-tor
    Animal()
    {
         age = 0;
         height = 0;
         weight = 0;
         name = "";
    }

    //constructor with parameters
    Animal(int age, int height, int weight, string name)
    {
        this->age = age;
        this->height = height;
        this->weight = weight;
        this->name = name;
    }
};

//dog class inherits from Animal class
class Dog : public Animal
{
    public:
    void print() 
    {
        cout << "Dog: " << this->name << endl;
    }
};

int main()
{
    Animal a1(10,120,80,"Elephant");
    a1.print();

    //pointer of Animal (Parent) class may point on Child classes
    Animal* a2 = new Dog();
    a2->print();

    delete a2;
    return 0;
}