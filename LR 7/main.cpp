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

vector<Student> Students_list;

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

int ch = 0, cah = 0;

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    input();
    int request;
    do {
        system("cls");
        cout << "���� ��������� ����������� ���������\n";
        cout << "0: ������� ���������� � ���� ����������\n";
        cout << "1: �������� ���������� � ���������\n";
        cout << "2: �������� ������� ���� ��������\n";
        cout << "3: ������� ���������� � ���������\n";
        cout << "4: ��������� ������� ���������\n";
        cout << "5: ��������� ��������� ������ ����\n";
        cout << "6: ��������� ���������\n";
        cout << "7: ������ ���������\n";
        cout << "8: ����� �� ���������\n";
        cin >> request;
        while (true) {
            if (request < 0 || request > 8) {
                cout << "��������� ������� �����:\n(����� ������� ������ ����� �� 0 �� 8)\n";
                cin >> request;
            }
            else
                break;
        }
        if (cin.fail()) {
            cout << "��������� ���������\n(����� ������������ ������ �����)\n";
            return 0;
        }
        switch (request)
        {
        case 0:
            cout << "����� ���������� � ���� ���������� ��������\n";
            OutputInformarionFromAllStudents();
            break;
        case 1:
            cout << "���������� ���������� � ���������\n";
            AddInformation();
            break;
        case 2:
            cout << "��������� �������� ����� ��������\n";
            ChangeInformationAboutStudent();
            break;
        case 3:
            cout << "�������� ���������� � ���������\n";
            DeliteInformation();
            break;
        case 4:
            cout << "���������� ������� ���������\n";
            AwardPersonalScholarship();
            break;
        case 5:
            cout << "���������� ��������� ������ ����\n";
            UniversityCouncilScholarship();
            break;
        case 6:
            cout << "������ ��������� ��������\n";
            ScholarshipCalculation();
            break;
        case 7:
            cout << "������ ��������� ���������\n";
            PrintStatement();
            break;
        case 8:
            cout << "�� ����� �� ���������\n";
            break;
        }
        output();
    } while (request != 8);
    return 0;
}

void input()
{
    fstream fin;
    fin.open("Students.txt");
    if (!fin.good())
        fstream out("Students.txt");
    string fio, groupnumber, educationform;
    double averagescore;
    int misshourse;
    while (!fin.eof())
    {
        fin >> fio >> groupnumber >> averagescore >> misshourse >> educationform;
        if (fio == "-1")
            break;
        Students_list.push_back ({ fio, groupnumber, averagescore, misshourse, educationform });
    }
    fin.close();
}

void OutputInformarionFromAllStudents()
{   
    int k = 0;
    for (auto object : Students_list) {
        OutputInformarion(object);
        k++;
    }
    if (k == 0)
        cout << "������ ��������� ���� ��� ���� :(\n";
    system("pause");
}

void OutputInformarion(Student& object)
{
    cout << "\n";
    line();
    cout << "���: " << object.FIO << "\n";
    cout << "����� ������: " << object.GroupNumber << "\n";
    cout << "������� ����: " << object.AverageScore << "\n";
    cout << "���������� ����������� �����: " << object.MissHourse << "\n";
    cout << "�������/��������� ����� ��������: " << object.EducationForm << " ����� ��������" <<"\n";
    line();
}

void DeliteInformation()
{
    string fio;
    regex regularFIO("([�-��-���]+)(\_)([�-��-���]+)(\_)([�-��-���]+)");
    cout << "������� ��� ��������, ���������� �������� ������ �������: "; 
    cin >> fio;
    while (true) {
        if (!regex_match(fio, regularFIO)) {
            cout << "��������� ������� �����:\n(������ ������� ����������� ������ �������������, ����� ����� ������������ ������ ������� �����)\n";
            cin >> fio;
        }
        else
            break;
    }
    for (int i = 0; i < Students_list.size(); i++) {
        if (Students_list[i].FIO == fio)
        {
            Students_list.erase(Students_list.begin() + i);
            line();
            cout << "*���������� � ������ �������� �������*\n";
            line();
            break;
        }
        else
            cout << "������� � ����� ��� �� ������";
    }
}

void AddInformation()
{
    string fio, groupnumber, educationform;
    double averagescore;
    int misshourse;
    regex regularFIO("([�-��-���]+)(\_)([�-��-���]+)(\_)([�-��-���]+)");
    regex regularGroupNumber("([0-9]+)");    
    cout << "\n������� ���: ";
    cin >> fio;
    while (true) {
        for (int i = 0; i < Students_list.size(); i++) {
            if (Students_list[i].FIO == fio) {
                cout << "��������� ������� �����:\n(������� � ����� ��� ��� ������ � ���� ������)\n";
                cin >> fio;
            }
        }
        if (!regex_match(fio, regularFIO)) {
            cout << "��������� ������� �����:\n(������ ������� ����������� ������ �������������, ����� ����� ������������ ������ ������� �����)\n";
            cin >> fio;
            for (int i = 0; i < Students_list.size(); i++) {
                if (Students_list[i].FIO == fio) {
                    cout << "��������� ������� �����:\n(������� � ����� ��� ��� ������ � ���� ������)\n";
                    cin >> fio;
                }
            }
        }
        else if (true) {
            for (int i = 0; i < Students_list.size(); i++) {
                if (Students_list[i].FIO == fio) {
                    cout << "��������� ������� �����:\n(������� � ����� ��� ��� ������ � ���� ������)\n";
                    cin >> fio;
                    i = 0;
                }
                if (i + 1 == Students_list.size())
                    break;
            }
            break;
        }
        else
            break;
    }
    cout << "\n������� ����� ������: ";
    cin >> groupnumber;
    while (true) {
        if (!regex_match(groupnumber, regularGroupNumber)) {
            cout << "��������� ������� �����:\n(����� ������������ ������ �����)\n";
            cin >> groupnumber;
        }
        else if (groupnumber.length() < 6 || groupnumber.length() > 6) {
            cout << "��������� ������� �����:\n(����� ������������ ������ 6 ����)\n";
            cin >> groupnumber;
        }
        else
            break;
    }
    cout << "\n������� ������� ����: ";
    cin >> averagescore;
    while (true) {
        if (averagescore < 0 || averagescore > 10) {
            cout << "��������� ������� �����:\n(�� ����� �������� �����)\n";
            cin >> averagescore;
        }
        else
            break;
    }
    if (cin.fail()) {
        cout << "��������� ���������\n(����� ������������ ������ �����)\n";
        return ;
    }
    cout << "\n������� ���������� ����������� �����: ";
    cin >> misshourse;
    while (true)
    {
        if (misshourse < 0 || misshourse > 1000) {
            cout << "��������� ������� �����:\n(�� ����� �������� ���������� ���������)\n";
            cin >> misshourse;
        }
        else
            break;
    }
    if (cin.fail()) {
        cout << "��������� ���������\n(����� ������������ ������ �����)\n";
        return;
    }
    cout << "\n�������� ����� �������� (�������/���������): ";
    cin >> educationform;
    while (true) {
        if (educationform == "�������" || educationform == "���������") {
            cout << "\n";
            break;
        }
        else {
            cout << "��������� ������� �����:\n(����� ������� ���� ������� �����(�������) ��������, ���� ���������(���������))\n";
            cin >> educationform;
        }
    }
    Students_list.push_back({ fio, groupnumber, averagescore, misshourse, educationform });
    line();
    cout << "*���������� � �������� ���������*\n";
    line();
    system("pause");
}

void ChangeInformationAboutStudent() {
    string fio;
    int x = 0;
    regex regularFIO("([�-��-���]+)(\_)([�-��-���]+)(\_)([�-��-���]+)");
    cout << "������� ��� ��������, ������� ���� �������� ������ ��������: ";
    cin >> fio;
    while (true) {
        if (!regex_match(fio, regularFIO)) {
            cout << "��������� ������� �����:\n(������ ������� ����������� ������ �������������, ����� ����� ������������ ������ ������� �����)\n";
            cin >> fio;
        }
        else
            break;
    }
    double averagescore;
    cout << "������� ������� ���� �� ������� ������ ��������: ";
    cin >> averagescore;
    while (true) {
        if (averagescore < 0 || averagescore > 10) {
            cout << "��������� ������� �����:\n(�� ����� �������� �����)\n";
            cin >> averagescore;
        }
        else
            break;
    }
    if (cin.fail()) {
        cout << "��������� ���������\n(����� ������������ ������ �����)\n";
        return;
    }
    for (int i = 0; i < Students_list.size(); i++){
        if (Students_list[i].FIO == fio)
        {
            Students_list.push_back({ Students_list[i].FIO, Students_list[i].GroupNumber, averagescore, Students_list[i].MissHourse, Students_list[i].EducationForm });
            Students_list.erase(Students_list.begin() + i);
            break;
        }
        else {
            cout << "�� ������ ������� �� ������� �� ������ ��������";
            x = 1;
        }
    }
    if (x != 1) {
        line();
        cout << "*������� ���� �������� �������*";
        line();
    }
}

void PrintStatement() {
    int kol = 0, chek = 0;
    double sum = 0, a = 181, b = 135;
    line();
    for (int i = 0; i < Students_list.size(); i++) {
        if (Students_list[i].EducationForm == "�������" || Students_list[i].MissHourse > 10 || Students_list[i].AverageScore < 5) {
            chek = 1;
        }
        else
        {
            if (Students_list[i].AverageScore >= 5 && Students_list[i].AverageScore <= 10)
                kol++;
        }
    }
    cout << "���������� ���������, ���������� ���������: " << kol << "\n\n";
    cout << "������ ���������, ���������� ���������:\n";
    for (int i = 0; i < Students_list.size(); i++) {
        if (Students_list[i].EducationForm == "�������" || Students_list[i].MissHourse > 10 || Students_list[i].AverageScore < 5) {
            chek = 1;
        }
        else
        {
            if (Students_list[i].AverageScore >= 5 && Students_list[i].AverageScore < 6) {
                cout << Students_list[i].FIO << "\n";
                sum = sum + 78.862;
            }
            if (Students_list[i].AverageScore >= 6 && Students_list[i].AverageScore < 8) {
                cout << Students_list[i].FIO << "\n";
                sum = sum + 94.634;
            }
            if (Students_list[i].AverageScore >= 8 && Students_list[i].AverageScore < 9) {
                cout << Students_list[i].FIO << "\n";
                sum = sum + 110.405;
            }
            if (Students_list[i].AverageScore >= 9 && Students_list[i].AverageScore <= 10) {
                cout << Students_list[i].FIO << "\n";
                sum = sum + 126.179;
            }
        }
    }
    cout << "\n������ ���������, ���������� ���������� ���������: \n";
    for (int i = 0; i < Students_list.size(); i++) {
        if (Students_list[i].EducationForm == "�������" || Students_list[i].MissHourse > 10 || Students_list[i].AverageScore < 5) {
            chek = 1;
        }
        else
        {
            if (Students_list[i].AverageScore >= 6 && Students_list[i].AverageScore <= 10)
                cout << Students_list[i].FIO << "\n";
        }
    }
    sum = ch * a + cah * b + sum;
    cout << "\n����� ���������� ����������� ����� ����������: " << sum << " ���." << "\n";
    line();
    system("pause");
}

void ScholarshipCalculation() {
    int chek = 0;
    line();
    for (int i = 0; i < Students_list.size(); i++) {
        if (Students_list[i].EducationForm == "�������") {
            cout << Students_list[i].FIO << " �� �������� ���������, ��� ��� � ���� ������� ����� ��������\n\n";
        }
        else if (Students_list[i].MissHourse > 10) {
            cout << Students_list[i].FIO << " �� �������� ���������, ��� ��� � ���� ����� 10 ����� ���������\n\n";
        }
        else if (Students_list[i].AverageScore < 5) {
            cout << Students_list[i].FIO << " �� �������� ���������, ��� ��� � ���� ������ ������� ����\n\n";
        }
        else
        {
            if (Students_list[i].AverageScore >= 5 && Students_list[i].AverageScore < 6)
                cout << Students_list[i].FIO << " �������� � 78,862 ���.\n\n";
            if (Students_list[i].AverageScore >= 6 && Students_list[i].AverageScore < 8)
                cout << Students_list[i].FIO << " �������� � 94,634 ���.\n\n";
            if (Students_list[i].AverageScore >= 8 && Students_list[i].AverageScore < 9)
                cout << Students_list[i].FIO << " �������� � 110,405 ���.\n\n";
            if (Students_list[i].AverageScore >= 9 && Students_list[i].AverageScore <= 10)
                cout << Students_list[i].FIO << " �������� � 126,179 ���.\n\n";
        }
    }
    line();
    system("pause");
}

void AwardPersonalScholarship() {
    string fio;
    int chek = 0, pack = 0;
    regex regularFIO("([�-��-���]+)(\_)([�-��-���]+)(\_)([�-��-���]+)");
    cout << "������� ��� ��������, ������� ��������� �������� �� ������ ���������: \n";
    cin >> fio;
    while (true) {
        if (!regex_match(fio, regularFIO)) {
            cout << "��������� ������� �����:\n(������ ������� ����������� ������ �������������, ����� ����� ������������ ������ ������� �����)\n";
            cin >> fio;
        }
        else
            break;
    }
    for (int i = 0; i < Students_list.size(); i++) {
        if (Students_list[i].FIO == fio) {
            if (Students_list[i].EducationForm == "�������") {
                cout << Students_list[i].FIO << " �� �������� ���������, ��� ��� � ���� ������� ����� ��������\n";
                pack = 1;
                chek = 1;
            }
            else if (chek == 1 || Students_list[i].MissHourse > 10) {
                cout << Students_list[i].FIO << " �� �������� ���������, ��� ��� � ���� ����� 10 ����� ���������\n";
                pack = 1;
                chek = 2;
            }
            else if (chek == 1 || chek == 2 || Students_list[i].AverageScore < 5) {
                cout << Students_list[i].FIO << " �� �������� ���������, ��� ��� � ���� ������ ������� ����\n";
                pack = 1;
                chek == 3;
            }
            else
            {
                if (Students_list[i].AverageScore >= 8.5 && Students_list[i].AverageScore <= 10) {
                    cout << Students_list[i].FIO << " �������� ������� ���������\n";
                    pack = 1;
                    ch++;
                }
                else {
                    cout << Students_list[i].FIO << " �� �������� ������� ���������, ��� ��� � ���� ������� ���� ���� ��� ����������\n";
                    pack = 1;
                }
            }
        }
    }
    if (pack != 0) {
        cout << "������� � ����� ��� �� ������";
    }
    system("pause");
}

void UniversityCouncilScholarship() {
    string fio;
    int chek = 0, pack = 0;
    regex regularFIO("([�-��-���]+)(\_)([�-��-���]+)(\_)([�-��-���]+)");
    cout << "������� ��� ��������, ������� ��������� �������� �� ������ ���������: \n";
    cin >> fio;
    while (true) {
        if (!regex_match(fio, regularFIO)) {
            cout << "��������� ������� �����:\n(������ ������� ����������� ������ �������������, ����� ����� ������������ ������ ������� �����)\n";
            cin >> fio;
        }
        else
            break;
    }
    for (int i = 0; i < Students_list.size(); i++) {
        if (Students_list[i].FIO == fio) {
            if (Students_list[i].EducationForm == "�������") {
                cout << Students_list[i].FIO << " �� �������� ���������, ��� ��� � ���� ������� ����� ��������\n";
                pack = 1;
                chek = 1;
            }
            else if (chek == 1 || Students_list[i].MissHourse > 10) {
                cout << Students_list[i].FIO << " �� �������� ���������, ��� ��� � ���� ����� 10 ����� ���������\n";
                pack = 1;
                chek = 2;
            }
            else if (chek == 1 || chek == 2 || Students_list[i].AverageScore < 5) {
                cout << Students_list[i].FIO << " �� �������� ���������, ��� ��� � ���� ������ ������� ����\n";
                pack = 1;
                chek == 3;
            }
            else
            {
                if (Students_list[i].AverageScore >= 8 && Students_list[i].AverageScore <= 10) {
                    cout << Students_list[i].FIO << " �������� ��������� ������ ����\n";
                    pack = 1;
                    cah++;
                }
                else {
                    cout << Students_list[i].FIO << " �� �������� ��������� ������ ����, ��� ��� � ���� ������� ���� ���� ��� ����������\n";
                    pack = 1;
                }
            }
        }
    }
    if(pack != 0)
        cout << "������� � ����� ��� �� ������";
    system("pause");
}

void line()
{
    for (int i = 0; i < 50; i++)
        cout << '*';
    cout << endl;
}

void output()
{
    ofstream fout("Students.txt");
    for (auto object : Students_list)
        fout << object.FIO << " " << object.GroupNumber << " " << object.AverageScore << " " << object.MissHourse << " " << object.EducationForm << endl;
    fout << -1;
    fout.close();
}