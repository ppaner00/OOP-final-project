#include <iostream>
#include "person.h"
#include "student.h"
#include "professor.h"

void Grading();

int main()
{
    Grading();
    return 0;
}

void Grading()
{
    std::cout << "------------------------------------------------------------------------" << std::endl;
    std::cout << "                                GRADING                                 " << std::endl;
    std::cout << "------------------------------------------------------------------------" << std::endl;

    // Create a first professor with the constructor of the parent class person
    Person *professor1 = new Professor("David", "Martínez", "01-A");

    // Create students with the parent class person
    Person *st1 = new Student("Andrés", "García", "05-E");
    Person *st2 = new Student("Darío", "Díaz", "06-F");
    Person *st3 = new Student("Alicia", "Campos", "07-G");

    // Add those students to professor 1's list
    // Castings are necessary to access different methods
    ((Professor*)professor1)->addStudent((Student*)st1);
    ((Professor*)professor1)->addStudent((Student*)st2);
    ((Professor*)professor1)->addStudent((Student*)st3);

    // Add grades to the students with overloaded methods
    ((Professor*)professor1)->assignGrade("05-E", 3.25, 4.75, 4);
    ((Professor*)professor1)->assignGrade("06-F", 3.25, 4.95);
    ((Professor*)professor1)->assignGrade("07-G", 3, 4, 5, 5);

    // Print the list of students and the best student of professor 1
    ((Professor*)professor1)->printStudents();
    ((Professor*)professor1)->printBest();

    // Create a second professor with the constructor of the professor class
    Professor *professor2 = new Professor("María", "Fernández", "02-B");

    // Create students with the student class
    Student *st4 = new Student("Raúl", "Entreríos", "08-H");
    Student *st5 = new Student("Diego", "Lorenzana", "09-I");
    Student *st6 = new Student("Roberto", "Fernández", "10-J");

    // Add those students to professor 2's list
    // No need for castings anymore
    professor2->addStudent(st4);
    professor2->addStudent(st5);
    professor2->addStudent(st6);

    // Add grades to the students with overloaded methods
    professor2->assignGrade("08-H", 5, 5, 5);
    professor2->assignGrade("09-I", 3, 4, 5, 5, 3);
    professor2->assignGrade("10-J", 3, 3);

    // Print the list of students and the best student of professor 2
    professor2->printStudents();
    professor2->printBest();

    // Create a list of professors and add the available professors
    std::vector<Professor*> professors;
    professors.push_back((Professor*)professor1);
    professors.push_back(professor2);

    // Declare local variables
    std::string inputID;
    int found = -1;

    while(found < 0)
    {
        std::cout << "\n--> Enter an ID -----------------------------------------------------" << std::endl;
        std::cin >> inputID;

        for (int i = 0; i < (int)professors.size(); i++) // Iterate through the list of professors
        {
            if (professors[i]->getID() == inputID) // If the IDs match
            {
                std::cout << "\nThe ID corresponds to the professor ";
                std::cout << professors[i]->getName() << " ";
                std::cout << professors[i]->getSurname() << std::endl;
                std::cout << "" << std::endl;
                professors[i]->printStudents();
                professors[i]->printBest();
                found = 1;
            }
            else // If the IDs do not match
            {
                for (int j = 0; j < professors[i]->numberOfStudents(); j++)  // Iterate through the list of students
                {
                    if (professors[i]->getStudentAt(j)->getID() == inputID) // If the IDs match
                    {
                        std::cout << "\nThe ID corresponds to the student ";
                        std::cout << professors[i]->getStudentAt(j)->getName() << " ";
                        std::cout << professors[i]->getStudentAt(j)->getSurname() << std::endl;
                        std::cout << "Grades: ";
                        professors[i]->getStudentAt(j)->printGrades();
                        std::cout << "\nAverage: ";
                        std::cout << professors[i]->getStudentAt(j)->calculateAverage() << "\n" << std::endl;
                        found = 1;
                    }

                }
            }

        }

        if (found == -1) // Error message
        {
            std::cout << "Error: the indicated ID does not correspond to any person" << std::endl;
        }

    }

    // Delete the created objects
    delete professor1;
    delete professor2;
    delete st1;
    delete st2;
    delete st3;
    delete st4;
    delete st5;
    delete st6;
}
