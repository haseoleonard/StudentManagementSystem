#include"DTO/StudentList.h"
#include"DTO/Student.h"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
using namespace DTO;

void menu(){
    cout<<"=======Student Management System======="<<endl;
    cout<<"1 - Add a new Student"<<endl;
    cout<<"2 - Show Student List"<<endl;
    cout<<"3 - "<<endl;
    cout<<"4 - Exit."<<endl;
    cout<<"Your Choice: ";
}

int main()
{ 
    DTO::StudentList *_studentList = new DTO::StudentList();
    bool running = true;
    do
    {
        int choice = -1;
        _flushall();
        menu();
        try
        {
            cin>>choice;
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
                // _studentList->deleteStudent();
                break;
            default:
                cout<<"Goodbye !!!";
                getchar();
                running=false;
                break;
            }
        }
        catch (exception ex)
        {
            cerr << ex.what() << endl;
            getchar();
        }
        system("cls");
    }while(running);
    delete _studentList;
    return 0;
}