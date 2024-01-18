#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "person.h"
#include "student.h"

// Definition of the Professor class, which inherits from the Person class
class Professor : public Person
{
public:

    // List of students
    std::vector<Student*> students;

    // Class constructor
    Professor();

    // Overloaded class constructor
    Professor(std::string name, std::string surname, std::string ID);

    // Class destructor
    ~Professor();

    // Method to add a student
    void addStudent(Student *student);

    // Method to return the position of the student in the vector
    int search(std::string ID);

    // Overloaded methods to assign grades to students

    void assignGrade(std::string ID, double grade1);
    void assignGrade(std::string ID, double grade1, double grade2);
    void assignGrade(std::string ID, double grade1, double grade2, double grade3);
    void assignGrade(std::string ID, double grade1, double grade2, double grade3, double grade4);
    void assignGrade(std::string ID, double grade1, double grade2, double grade3, double grade4, double grade5);

    // Method to print the list of students with their data and average grade
    void printStudents();

    // Method to print the student with the best average grade who has 3 grades
    void printBest();

    // Method that indicates how many students the professor has
    int numberOfStudents();

    // Method to return a student according to their position in the array
    Student* getStudentAt(int position);

};

#endif // PROFESSOR_H
