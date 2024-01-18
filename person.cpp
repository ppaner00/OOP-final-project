#include "person.h"

// Empty class constructor
Person::Person()
{

}

// Overloaded class constructor
Person::Person(std::string name, std::string surname, std::string ID)
{
    setName(name);
    setSurname(surname);
    setID(ID);
}

// Class destructor
Person::~Person(void)
{

}

// Getters and setters
std::string Person::getName()
{
    return name;
}

void Person::setName(std::string name)
{
    this->name = name;
}

std::string Person::getSurname()
{
    return surname;
}

void Person::setSurname(std::string surname)
{
    this->surname = surname;
}

std::string Person::getID()
{
    return ID;
}

void Person::setID(std::string ID)
{
    this->ID = ID;
}
