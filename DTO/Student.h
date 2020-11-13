#include <string>
using namespace std;
#pragma once
namespace DTO
{
    class Student
    {
    private:
        /* data */
        string _studentCode;
        string _studentName;
        string _dateOfBirth;
        float _learningPoint;

    public:
        Student(/* args */);
        Student(string studentCode, string studentName, string dateOfBirth, float learningPoint);
        Student(const Student &student);
        string getStudentCode() { return _studentCode; }
        void setStudentCode(string studentCode) { _studentCode = studentCode; }
        string getStudentName() { return _studentName; }
        void setStudentName(string studentName) { _studentName = studentName; }
        string getDateOfBirth() { return _dateOfBirth; }
        void setDateOfBirth(string dateOfBirth) { _dateOfBirth = dateOfBirth; }
        float getLearningPoint() { return _learningPoint; }
        void setLearningPoint(float learningPoint) { _learningPoint = learningPoint; }
        string toString()
        {
            return _studentCode + " - " + _studentName + " - " + _dateOfBirth + " - " + to_string(_learningPoint);
        }
        ~Student();
    };
    Student::Student(/* args */)
    {
        _studentCode = "";
        _studentName = "";
        _dateOfBirth = "";
        _learningPoint = 0;
    }
    Student::Student(string studentCode, string studentName, string dateOfBirth, float learningPoint)
    {
        _studentCode = studentCode;
        _studentName = studentName;
        _dateOfBirth = dateOfBirth;
        _learningPoint = learningPoint;
    }
    Student::Student(const Student &student)
    {
        _studentCode = student._studentCode;
        _studentName = student._studentName;
        _dateOfBirth = student._dateOfBirth;
        _learningPoint = student._learningPoint;
    }
    Student::~Student()
    {
    }
} // namespace DTO