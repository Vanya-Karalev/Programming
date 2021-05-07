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
        cout << "Меню программы начисляющей стипендию\n";
        cout << "0: Вывести информацию о всех студенетах\n";
        cout << "1: Добавить информацию о студенете\n";
        cout << "2: Изменить средний балл студента\n";
        cout << "3: Удалить информацию о студенете\n";
        cout << "4: Начислить именную стипендию\n";
        cout << "5: Начислить Стипендию Совета вуза\n";
        cout << "6: Расчитать стипендию\n";
        cout << "7: Печать ведомости\n";
        cout << "8: Выход из программы\n";
        cin >> request;
        while (true) {
            if (request < 0 || request > 8) {
                cout << "Повторите попытку ввода:\n(Можно вводить только цифры от 0 до 8)\n";
                cin >> request;
            }
            else
                break;
        }
        if (cin.fail()) {
            cout << "Программа завершена\n(Можно использовать только цифры)\n";
            return 0;
        }
        switch (request)
        {
        case 0:
            cout << "Вывод информации о всех студенетах выполнен\n";
            OutputInformarionFromAllStudents();
            break;
        case 1:
            cout << "Добавление информации о студенете\n";
            AddInformation();
            break;
        case 2:
            cout << "Изменение среднего балла студента\n";
            ChangeInformationAboutStudent();
            break;
        case 3:
            cout << "Удаление информации о студенете\n";
            DeliteInformation();
            break;
        case 4:
            cout << "Начисление именной стипендии\n";
            AwardPersonalScholarship();
            break;
        case 5:
            cout << "Начисление Стипендии Совета вуза\n";
            UniversityCouncilScholarship();
            break;
        case 6:
            cout << "Расчёт стипендии выполнен\n";
            ScholarshipCalculation();
            break;
        case 7:
            cout << "Печать ведомости выполнена\n";
            PrintStatement();
            break;
        case 8:
            cout << "Вы вышли из программы\n";
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
        cout << "Список студентов пока что пуст :(\n";
    system("pause");
}

void OutputInformarion(Student& object)
{
    cout << "\n";
    line();
    cout << "ФИО: " << object.FIO << "\n";
    cout << "Номер группы: " << object.GroupNumber << "\n";
    cout << "Средний балл: " << object.AverageScore << "\n";
    cout << "Количество пропущенных часов: " << object.MissHourse << "\n";
    cout << "Платная/Бюджетная форма обучения: " << object.EducationForm << " форма обучения" <<"\n";
    line();
}

void DeliteInformation()
{
    string fio;
    regex regularFIO("([А-Яа-яЁё]+)(\_)([А-Яа-яЁё]+)(\_)([А-Яа-яЁё]+)");
    cout << "Введите ФИО студента, информацию которого хотите удалить: "; 
    cin >> fio;
    while (true) {
        if (!regex_match(fio, regularFIO)) {
            cout << "Повторите попытку ввода:\n(Вместо пробела используйте нижнее подчеркивание, также можно использовать только русские буквы)\n";
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
            cout << "*Информация о данном студенте удалена*\n";
            line();
            break;
        }
        else
            cout << "Студент с таким ФИО не найден";
    }
}

void AddInformation()
{
    string fio, groupnumber, educationform;
    double averagescore;
    int misshourse;
    regex regularFIO("([А-Яа-яЁё]+)(\_)([А-Яа-яЁё]+)(\_)([А-Яа-яЁё]+)");
    regex regularGroupNumber("([0-9]+)");    
    cout << "\nВведите ФИО: ";
    cin >> fio;
    while (true) {
        for (int i = 0; i < Students_list.size(); i++) {
            if (Students_list[i].FIO == fio) {
                cout << "Повторите попытку ввода:\n(Студент с таким ФИО уже занесён в базу данных)\n";
                cin >> fio;
            }
        }
        if (!regex_match(fio, regularFIO)) {
            cout << "Повторите попытку ввода:\n(Вместо пробела используйте нижнее подчеркивание, также можно использовать только русские буквы)\n";
            cin >> fio;
            for (int i = 0; i < Students_list.size(); i++) {
                if (Students_list[i].FIO == fio) {
                    cout << "Повторите попытку ввода:\n(Студент с таким ФИО уже занесён в базу данных)\n";
                    cin >> fio;
                }
            }
        }
        else if (true) {
            for (int i = 0; i < Students_list.size(); i++) {
                if (Students_list[i].FIO == fio) {
                    cout << "Повторите попытку ввода:\n(Студент с таким ФИО уже занесён в базу данных)\n";
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
    cout << "\nВведите номер группы: ";
    cin >> groupnumber;
    while (true) {
        if (!regex_match(groupnumber, regularGroupNumber)) {
            cout << "Повторите попытку ввода:\n(Можно использовать только цифры)\n";
            cin >> groupnumber;
        }
        else if (groupnumber.length() < 6 || groupnumber.length() > 6) {
            cout << "Повторите попытку ввода:\n(Можно использовать только 6 цифр)\n";
            cin >> groupnumber;
        }
        else
            break;
    }
    cout << "\nВведите средний балл: ";
    cin >> averagescore;
    while (true) {
        if (averagescore < 0 || averagescore > 10) {
            cout << "Повторите попытку ввода:\n(Вы ввели неверное число)\n";
            cin >> averagescore;
        }
        else
            break;
    }
    if (cin.fail()) {
        cout << "Программа завершена\n(Можно использовать только цифры)\n";
        return ;
    }
    cout << "\nВведите количество пропущенных часов: ";
    cin >> misshourse;
    while (true)
    {
        if (misshourse < 0 || misshourse > 1000) {
            cout << "Повторите попытку ввода:\n(Вы ввели неверное количество пропусков)\n";
            cin >> misshourse;
        }
        else
            break;
    }
    if (cin.fail()) {
        cout << "Программа завершена\n(Можно использовать только цифры)\n";
        return;
    }
    cout << "\nВыберите форму обучения (Платная/Бюджетная): ";
    cin >> educationform;
    while (true) {
        if (educationform == "Платная" || educationform == "Бюджетная") {
            cout << "\n";
            break;
        }
        else {
            cout << "Повторите попытку ввода:\n(Можно вводить либо Платную форму(Платная) обучения, либо Бюджетную(Бюджетная))\n";
            cin >> educationform;
        }
    }
    Students_list.push_back({ fio, groupnumber, averagescore, misshourse, educationform });
    line();
    cout << "*Информация о студенте добавлена*\n";
    line();
    system("pause");
}

void ChangeInformationAboutStudent() {
    string fio;
    int x = 0;
    regex regularFIO("([А-Яа-яЁё]+)(\_)([А-Яа-яЁё]+)(\_)([А-Яа-яЁё]+)");
    cout << "Введите ФИО студента, средний балл которого хотите изменить: ";
    cin >> fio;
    while (true) {
        if (!regex_match(fio, regularFIO)) {
            cout << "Повторите попытку ввода:\n(Вместо пробела используйте нижнее подчеркивание, также можно использовать только русские буквы)\n";
            cin >> fio;
        }
        else
            break;
    }
    double averagescore;
    cout << "Введите средний балл на который хотите изменить: ";
    cin >> averagescore;
    while (true) {
        if (averagescore < 0 || averagescore > 10) {
            cout << "Повторите попытку ввода:\n(Вы ввели неверное число)\n";
            cin >> averagescore;
        }
        else
            break;
    }
    if (cin.fail()) {
        cout << "Программа завершена\n(Можно использовать только цифры)\n";
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
            cout << "По вашиму запросу не найдено ни одного студента";
            x = 1;
        }
    }
    if (x != 1) {
        line();
        cout << "*Средний балл студента изменен*";
        line();
    }
}

void PrintStatement() {
    int kol = 0, chek = 0;
    double sum = 0, a = 181, b = 135;
    line();
    for (int i = 0; i < Students_list.size(); i++) {
        if (Students_list[i].EducationForm == "Платная" || Students_list[i].MissHourse > 10 || Students_list[i].AverageScore < 5) {
            chek = 1;
        }
        else
        {
            if (Students_list[i].AverageScore >= 5 && Students_list[i].AverageScore <= 10)
                kol++;
        }
    }
    cout << "Количество студентов, получивших стипендию: " << kol << "\n\n";
    cout << "Список студентов, получивших стипендию:\n";
    for (int i = 0; i < Students_list.size(); i++) {
        if (Students_list[i].EducationForm == "Платная" || Students_list[i].MissHourse > 10 || Students_list[i].AverageScore < 5) {
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
    cout << "\nСписок студентов, получивших повышенную стипендию: \n";
    for (int i = 0; i < Students_list.size(); i++) {
        if (Students_list[i].EducationForm == "Платная" || Students_list[i].MissHourse > 10 || Students_list[i].AverageScore < 5) {
            chek = 1;
        }
        else
        {
            if (Students_list[i].AverageScore >= 6 && Students_list[i].AverageScore <= 10)
                cout << Students_list[i].FIO << "\n";
        }
    }
    sum = ch * a + cah * b + sum;
    cout << "\nОбщее количество выплаченных денег составляет: " << sum << " руб." << "\n";
    line();
    system("pause");
}

void ScholarshipCalculation() {
    int chek = 0;
    line();
    for (int i = 0; i < Students_list.size(); i++) {
        if (Students_list[i].EducationForm == "Платная") {
            cout << Students_list[i].FIO << " не получает стипендию, так как у него Платная форма обучения\n\n";
        }
        else if (Students_list[i].MissHourse > 10) {
            cout << Students_list[i].FIO << " не получает стипендию, так как у него более 10 часов пропусков\n\n";
        }
        else if (Students_list[i].AverageScore < 5) {
            cout << Students_list[i].FIO << " не получает стипендию, так как у него низкий средний балл\n\n";
        }
        else
        {
            if (Students_list[i].AverageScore >= 5 && Students_list[i].AverageScore < 6)
                cout << Students_list[i].FIO << " получает – 78,862 руб.\n\n";
            if (Students_list[i].AverageScore >= 6 && Students_list[i].AverageScore < 8)
                cout << Students_list[i].FIO << " получает – 94,634 руб.\n\n";
            if (Students_list[i].AverageScore >= 8 && Students_list[i].AverageScore < 9)
                cout << Students_list[i].FIO << " получает – 110,405 руб.\n\n";
            if (Students_list[i].AverageScore >= 9 && Students_list[i].AverageScore <= 10)
                cout << Students_list[i].FIO << " получает – 126,179 руб.\n\n";
        }
    }
    line();
    system("pause");
}

void AwardPersonalScholarship() {
    string fio;
    int chek = 0, pack = 0;
    regex regularFIO("([А-Яа-яЁё]+)(\_)([А-Яа-яЁё]+)(\_)([А-Яа-яЁё]+)");
    cout << "Введите ФИО студента, именную стипендию которому вы хотите начислить: \n";
    cin >> fio;
    while (true) {
        if (!regex_match(fio, regularFIO)) {
            cout << "Повторите попытку ввода:\n(Вместо пробела используйте нижнее подчеркивание, также можно использовать только русские буквы)\n";
            cin >> fio;
        }
        else
            break;
    }
    for (int i = 0; i < Students_list.size(); i++) {
        if (Students_list[i].FIO == fio) {
            if (Students_list[i].EducationForm == "Платная") {
                cout << Students_list[i].FIO << " не получает стипендию, так как у него платная форма обучения\n";
                pack = 1;
                chek = 1;
            }
            else if (chek == 1 || Students_list[i].MissHourse > 10) {
                cout << Students_list[i].FIO << " не получает стипендию, так как у него более 10 часов пропусков\n";
                pack = 1;
                chek = 2;
            }
            else if (chek == 1 || chek == 2 || Students_list[i].AverageScore < 5) {
                cout << Students_list[i].FIO << " не получает стипендию, так как у него низкий средний балл\n";
                pack = 1;
                chek == 3;
            }
            else
            {
                if (Students_list[i].AverageScore >= 8.5 && Students_list[i].AverageScore <= 10) {
                    cout << Students_list[i].FIO << " получает именную стипендию\n";
                    pack = 1;
                    ch++;
                }
                else {
                    cout << Students_list[i].FIO << " не получает именную стипендию, так как у него средний балл ниже чем полагается\n";
                    pack = 1;
                }
            }
        }
    }
    if (pack != 0) {
        cout << "Студент с таким ФИО не найден";
    }
    system("pause");
}

void UniversityCouncilScholarship() {
    string fio;
    int chek = 0, pack = 0;
    regex regularFIO("([А-Яа-яЁё]+)(\_)([А-Яа-яЁё]+)(\_)([А-Яа-яЁё]+)");
    cout << "Введите ФИО студента, именную стипендию которому вы хотите начислить: \n";
    cin >> fio;
    while (true) {
        if (!regex_match(fio, regularFIO)) {
            cout << "Повторите попытку ввода:\n(Вместо пробела используйте нижнее подчеркивание, также можно использовать только русские буквы)\n";
            cin >> fio;
        }
        else
            break;
    }
    for (int i = 0; i < Students_list.size(); i++) {
        if (Students_list[i].FIO == fio) {
            if (Students_list[i].EducationForm == "Платная") {
                cout << Students_list[i].FIO << " не получает стипендию, так как у него платная форма обучения\n";
                pack = 1;
                chek = 1;
            }
            else if (chek == 1 || Students_list[i].MissHourse > 10) {
                cout << Students_list[i].FIO << " не получает стипендию, так как у него более 10 часов пропусков\n";
                pack = 1;
                chek = 2;
            }
            else if (chek == 1 || chek == 2 || Students_list[i].AverageScore < 5) {
                cout << Students_list[i].FIO << " не получает стипендию, так как у него низкий средний балл\n";
                pack = 1;
                chek == 3;
            }
            else
            {
                if (Students_list[i].AverageScore >= 8 && Students_list[i].AverageScore <= 10) {
                    cout << Students_list[i].FIO << " получает Стипендия Совета вуза\n";
                    pack = 1;
                    cah++;
                }
                else {
                    cout << Students_list[i].FIO << " не получает Стипендию Совета вуза, так как у него средний балл ниже чем полагается\n";
                    pack = 1;
                }
            }
        }
    }
    if(pack != 0)
        cout << "Студент с таким ФИО не найден";
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