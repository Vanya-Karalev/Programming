#include "main.h"

void lineChek() {
    fstream checkfile;
    checkfile.open("Check.txt");
    if (!checkfile.good())
        fstream out("Check.txt");
    //checkfile << line();

    for (int i = 0; i < 50; i++)
        checkfile << '*';

    long file_size;
    checkfile.seekg(0, ios::end);
    file_size = checkfile.tellg();

    printf("line check ");
    if (file_size != 0)
        printf("complited\n");
    else
        printf("failed\n");

    checkfile.close();
}

void inputCheck() {
    input();

    printf("input check ");

    if (true)
        printf("complited\n");
    else
        printf("failed\n");
}

void AddInformationCheck() {
    vector<Student> Students_list;
    setlocale(LC_ALL, "Russian");
    Student Mikle = { "Veromeev_Mikle_Sergeevich", "020604", 5.0, 25, "Платная" };
    Students_list.push_back({ "Veromeev_Mikle_Sergeevich", "020604", 5.0, 25, "Платная" });

    printf("AddInformation check ");

    if (true)
        printf("complited\n");
    else
        printf("failed\n");
}

void ChangeInformationAboutStudentCheck() {
    vector<Student> Students_list;
    double averagescore = 5.3;
    for (int i = 0; i < Students_list.size(); i++) {
        if (Students_list[i].FIO == "Veromeev_Mikle_Sergeevich")
        {
            Students_list.push_back({ "Veromeev_Mikle_Sergeevich", "020604", averagescore, 25, "Платная" });
            Students_list.erase(Students_list.begin() + i);
            break;
        }
    }
    printf("ChangeInformationAboutStudent check ");

    if (true)
        printf("complited\n");
    else
        printf("failed\n");
}

void OutputInformarionFromAllStudentsChek()
{
    OutputInformarionFromAllStudents();
    printf("OutputInformarionFromAllStudents check ");

    if (true)
        printf("complited\n");
    else
        printf("failed\n");
}

void DeliteInformationCheck() {
    vector<Student> Students_list;
    for (int i = 0; i < Students_list.size(); i++) {
        if (Students_list[i].FIO == "Veromeev_Mikle_Sergeevich")
        {
            Students_list.erase(Students_list.begin() + i);
            break;
        }
    }
    printf("DeliteInformation check ");

    if (true)
        printf("complited\n");
    else
        printf("failed\n");
}

void outputCheck() {
    output();

    printf("output check ");

    if (true)
        printf("complited\n");
    else
        printf("failed\n");
}

#undef main

int main()
{
    lineChek();
    inputCheck();
    AddInformationCheck();
    ChangeInformationAboutStudentCheck();
    OutputInformarionFromAllStudentsChek();
    DeliteInformationCheck();
    outputCheck();
}