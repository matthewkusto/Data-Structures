#include <iostream>
using namespace std;

class Person
{
public:
    // Consttuctor
    Person();
    Person(string first, string last);
    Person(string first, string last, string address);

    // Accessors
    string getFirstName() const, getLastName() const, getAddress() const;
    
    // Mutators
    void setFirstName(), setLastName(), setAddress();

private:
    string firstName, lastName, address;
};



int main()
{



    return 0;
}