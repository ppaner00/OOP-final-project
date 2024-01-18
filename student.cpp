#include "student.h"

// Class constructor
Student::Student()
{

}

// Overloaded class constructor
Student::Student(std::string name, std::string surname, std::string ID)
{
    setName(name);
    setSurname(surname);
    setID(ID);
}

// Class destructor
Student::~Student()
{

}

// Method to add a note to the student
void Student::addGrade(double grade)
{
    if (grades.size() < 5)
    {
        grades.push_back(grade);
    } else
    {
        std::cout << "Error: the student " << getName() << " " << getSurname() << " can only have up to 3 grades" << std::endl;
    }
}

// Method to return a grade according to its position in the array
double Student::getGradeAt(int position)
{
    return grades[position];
}

// Method that indicates how many grades the student has
int Student::numberOfGrades()
{
    return grades.size();
}

double Student::calculateAverage()
{
    double sum = 0;
    int count = 0;
    double result = 0;
    for (int i = 0; i < numberOfGrades(); i++)
    {
        sum += getGradeAt(i);
        count++;
    }
    result = sum / (double)count;
    return result;
}

// Method that prints the student's grades
void Student::printGrades()
{
    int last = 0;
    for (int i = 0; i < (int) grades.size() - 1; i++)
    {
        std::cout << getGradeAt(i);
        std::cout << ", ";
        last++;
    }
    std::cout << getGradeAt(last); // This way we get rid of the last comma
}
