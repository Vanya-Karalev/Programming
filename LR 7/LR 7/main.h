#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

struct Student
{
    string FIO;
    string GroupNumber;
    double AverageScore;
    int MissHourse;
    string EducationForm;
};

void line();
void OutputInformarion(Student& object);
void OutputInformarionFromAllStudents();
void DeliteInformation();
void AddInformation();
void output();
void ChangeInformationAboutStudent();
void ScholarshipCalculation();
void input();
void PrintStatement();
void AwardPersonalScholarship();
void UniversityCouncilScholarship();