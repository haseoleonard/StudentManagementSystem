#include "DTO/StudentList.h"
#include "DTO/Student.h"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
using namespace DTO;

void menu()
{
    cout << "=======Student Management System=======" << endl;
    cout << "1 - Add a new Student" << endl;
    cout << "2 - Show Student List" << endl;
    cout << "3 - Delete a Student" << endl;
    cout << "4 - Exit." << endl;
    cout << "Your Choice: ";
}

bool isNumber(const string &input)
{
    for (int i = 0; i < input.length(); i++)
        if (!isdigit(input[i]))
            return false;
    return true;
}

int main()
{
    DTO::StudentList *_studentList = new DTO::StudentList();
    bool running = true;
    // ArrayList<Student> *_studentList = new ArrayList<Student>();
    do
    {
        int choice = -1;
        _flushall();
        menu();
        try
        {
            // Student *newStudent = new Student("Ancd", "xyze", "refc", 9.8);
            // cout << 1 << endl;
            // cout << newStudent->toString() << endl;
            // getchar();
            // _studentList->add(*newStudent);
            // int size = _studentList->length();
            // cout << size << endl;
            // for (int i = 0; i < size; i++)
            // {
            //     cout << _studentList->get(i)->toString() << endl;
            // }
            do
            {
                fflush(stdin);
                string input;
                getline(cin, input);
                if (!input.empty()&&isNumber(input))
                    choice = stoi(input);
                else
                {
                    cout << "Invalid Input" << endl;
                    fflush(stdin);
                    getchar();
                    system("cls");
                    menu();
                }
            } while (choice == -1);
            cout<<endl;
            switch (choice)
            {
            case 1:
                /* code */                
                _studentList->createNewStudent();
                break;
            case 2:
                _studentList->showStudentList();
                break;
            case 3:
                _studentList->deleteStudent();
                break;
            case 4:
                cout << "Goodbye !!!";
                getchar();
                running = false;
                break;
            default:
                cout<<"Invalid Input"<<endl;
                getchar();
                break;
            }
        }
        catch (exception ex)
        {
            cerr << ex.what() << endl;
            getchar();
        }
        system("cls");
    } while (running);
    delete _studentList;
    return 0;
}