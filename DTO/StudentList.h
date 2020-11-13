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
            Student *newStudent = new Student(id,name,dob,mark);
            _studentList->add(*newStudent);
            cout<<"Student Added Successfully"<<endl;
        }
        catch (std::exception ex)
        {
            cout<<"Add Failed"<<endl;
        }
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
        getchar();
    }

} // namespace DTO