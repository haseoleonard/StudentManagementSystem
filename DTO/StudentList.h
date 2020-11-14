#include <stdio.h>
#include <string>
#include <iostream>
#include "ArrayList.h"
#include "Student.h"
using namespace std;
#pragma once
namespace DTO
{
    class StudentList
    {
    private:
        ArrayList<Student> *_studentList;
        bool isStudentIDExisted(const string &id);
        bool isValidGrade(const float inputedMark);
        bool isValidDateOfBirth(const string &inputedDateOfBirth);
        int getIndexByID(const string &id);

    public:
        StudentList(/* args */);
        ~StudentList();
        void createNewStudent();
        void showStudentList();
        void deleteStudent();
    };

    StudentList::StudentList(/* args */)
    {
        _studentList = new ArrayList<Student>();
    }

    StudentList::~StudentList()
    {
        delete _studentList;
    }

    bool StudentList::isStudentIDExisted(const string &id)
    {
        if (!_studentList->isEmpty())
        {
            int size = _studentList->length();
            for (int i = 0; i < size; i++)
            {
                if (id.compare(_studentList->get(i)->getStudentCode()) == 0)
                    return true;
            }
        }
        return false;
    }

    bool StudentList::isValidGrade(const float inputedMark)
    {
        return inputedMark >= 0 && inputedMark <= 10;
    }

    bool StudentList::isValidDateOfBirth(const string &inputedDateOfBirth)
    {
        return !inputedDateOfBirth.empty();
    }
    void StudentList::createNewStudent()
    {
        try
        {
            string id, name, dob;
            float mark;
            do
            {
                _flushall();
                cout << "Enter Student Code: ";
                cin >> id;
            } while (id.empty());
            do
            {
                _flushall();
                cout << "Enter Student Name: ";
                getline(cin, name);
            } while (name.empty());
            do
            {
                _flushall();
                cout << "Enter Date Of Birth: ";
                getline(cin, dob);
            } while (!isValidDateOfBirth(dob));
            do
            {
                _flushall();
                try
                {
                    /* code */
                    cout << "Enter Student's Mark: ";
                    string inputedMark;
                    cin >> inputedMark;
                    mark = stof(inputedMark);
                }
                catch (const std::exception &e)
                {
                }
            } while (!isValidGrade(mark));
            cout<<endl;
            if (!isStudentIDExisted(id))
            {
                Student *newStudent = new Student(id, name, dob, mark);
                _studentList->add(*newStudent);
                delete newStudent;
                cout << "Student Added Successfully" << endl;
            }
            else
            {
                cout << "Student ID Existed" << endl;
            }
        }
        catch (std::exception ex)
        {
            cout << "Add Failed" << endl;
        }
        fflush(stdin);
        getchar();
    }

    void StudentList::showStudentList()
    {
        try
        {
            if (!_studentList->isEmpty())
            {
                int size = _studentList->length();
                cout << "Total Student: " + to_string(size) << endl;
                cout << "StudentID - Student Name - Date Of Birth - Mark" << endl;
                for (int i = 0; i < size; i++)
                {
                    cout << _studentList->get(i)->toString() << endl;
                }
            }
            else
            {
                cout << "Student List is Empty!!!" << endl;
            }
        }
        catch (std::exception ex)
        {
            cout << ex.what() << endl;
        }
        fflush(stdin);
        getchar();
    }
    int StudentList::getIndexByID(const string &id)
    {
        if (!_studentList->isEmpty())
            for (int i = 0; i < _studentList->length(); i++)
                if (id.compare(_studentList->get(i)->getStudentCode())==0)
                    return i;
        return -1;
    }
    void StudentList::deleteStudent()
    {
        try
        {
            string id;
            do
            {
                _flushall();
                cout << "Enter Student ID to Delete: ";
                getline(cin, id);
                if (id.empty())
                {
                    cout << "Please enter an StudentID" << endl;
                    getchar();
                }
            } while (id.empty());
            int index = getIndexByID(id);
            cout<<endl;
            if (index != -1)
            {
                Student *removedStudent = _studentList->removeAt(index);
                if (removedStudent != nullptr)
                {
                    cout << "Remove Student Succesfully" << endl;
                    cout << "Student ID: " + removedStudent->getStudentCode() << endl;
                    cout << "Student Name: " + removedStudent->getStudentName() << endl;
                    cout << "Student Date Of Birth: " + removedStudent->getDateOfBirth() << endl;
                    cout << "Student Mark: " + to_string(removedStudent->getLearningPoint()) << endl;
                }
            }
            else
            {
                cout << "Student Not Existed" << endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        fflush(stdin);
        getchar();
    }
} // namespace DTO