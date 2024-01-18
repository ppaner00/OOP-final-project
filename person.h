#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>

// Definition of the Person class
class Person
{
public:

    // Class constructor
    Person();

    // Overloaded class constructor
    Person(std::string name, std::string surname, std::string ID);

    // Class destructor
    ~Person(void);

    // Getters and setters
    std::string getName();
    void setName(std::string name);

    std::string getSurname();
    void setSurname(std::string surname);

    std::string getID();
    void setID(std::string ID);

private:

    std::string name;
    std::string surname;
    std::string ID;

};

#endif // PERSON_H
