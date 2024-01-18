#include "professor.h"

// Class constructor
Professor::Professor()
{

}

// Class destructor
Professor::~Professor()
{

}

// Overloaded class constructor
Professor::Professor(std::string name, std::string surname, std::string ID)
{
    setName(name);
    setSurname(surname);
    setID(ID);
}

// Method to add a student
void Professor::addStudent(Student *student)
{
    students.push_back(student);
}

// Method to find the position of the student in the vector by their ID
int Professor::search(std::string ID)
{
    int position = -1;
    for (int i = 0; i < (int) students.size(); i++)
    {
        if (students[i]->getID() == ID)
        {
            position = i;
        }
    }

    if (position == -1)
    {
        std::cout << "Error: student with ID: " << ID << " not found in the list of professor " << getName() << std::endl;
    }

    return position;
}

// Overloaded methods to assign grades to students, specifying their ID

void Professor::assignGrade(std::string ID, double grade1)
{
    students[search(ID)]->addGrade(grade1);
}

void Professor::assignGrade(std::string ID, double grade1, double grade2)
{
    students[search(ID)]->addGrade(grade1);
    students[search(ID)]->addGrade(grade2);
}

void Professor::assignGrade(std::string ID, double grade1, double grade2, double grade3)
{
    students[search(ID)]->addGrade(grade1);
    students[search(ID)]->addGrade(grade2);
    students[search(ID)]->addGrade(grade3);
}

void Professor::assignGrade(std::string ID, double grade1, double grade2, double grade3, double grade4)
{
    students[search(ID)]->addGrade(grade1);
    students[search(ID)]->addGrade(grade2);
    students[search(ID)]->addGrade(grade3);
    students[search(ID)]->addGrade(grade4);
}

void Professor::assignGrade(std::string ID, double grade1, double grade2, double grade3, double grade4, double grade5)
{
    students[search(ID)]->addGrade(grade1);
    students[search(ID)]->addGrade(grade2);
    students[search(ID)]->addGrade(grade3);
    students[search(ID)]->addGrade(grade4);
    students[search(ID)]->addGrade(grade5);
}

// Method to print the list of students with their data and average grade
void Professor::printStudents()
{
    // Header
    std::cout << "----------------- Students of Professor ";
    std::cout << getName() << " " << getSurname() << " -------------------\n" << std::endl;

    for (int i = 0; i < (int) students.size(); i++){
        std::cout << "Student " << i + 1 << ": ";
        std::cout << students[i]->getName() << " ";
        std::cout << students[i]->getSurname() << ", ";
        std::cout << students[i]->getID() << ". Grades: ";
        students[i]->printGrades();
        std::cout << ". Average: " << students[i]->calculateAverage() << std::endl;
    }
    std::cout << "" << std::endl; // New line
}

// Method to print the student with the best average grade who has 3 grades
void Professor::printBest()
{
    double maximum = -1;
    int bestPosition = -1;
    for (int i = 0; i < (int) students.size(); i++)
    {
        if (students[i]->numberOfGrades() == 3)
        {
            if (students[i]->calculateAverage() > maximum)
            {
                maximum = students[i]->calculateAverage();
                bestPosition = i;
            }
        }
    }

    if (bestPosition != -1)
    {
        std::cout << "The student with three grades and the best average is: ";
        std::cout << students[bestPosition]->getName() << " ";
        std::cout << students[bestPosition]->getSurname();
        std::cout << ". Average: " << students[bestPosition]->calculateAverage() << std::endl;
        std::cout << "" << std::endl; // New line
    } else {
        std::cout << "Cannot determine the best, no students with three grades for professor " << getName() << std::endl;
    }
}

// Method that indicates how many students the professor has
int Professor::numberOfStudents()
{
    return students.size();
}

// Method to return a student according to their position in the array
Student* Professor::getStudentAt(int position)
{
    return students[position];
}
