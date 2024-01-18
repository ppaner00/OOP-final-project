#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

// Definition of the Student class, which inherits from the Person class
class Student : public Person
{
public:

    // List of grades
    std::vector<double> grades;

    // Class constructor
    Student();

    // Overloaded class constructor
    Student(std::string name, std::string surname, std::string ID);

    // Class destructor
    ~Student();

    // Method to add a grade to the student
    void addGrade(double grade);

    // Method to return a grade according to its position in the array
    double getGradeAt(int position);

    // Method that indicates how many grades the student has
    int numberOfGrades();

    // Method to obtain the student's average grade
    double calculateAverage();

    // Method that prints the student's grades
    void printGrades();

};

#endif // STUDENT_H
