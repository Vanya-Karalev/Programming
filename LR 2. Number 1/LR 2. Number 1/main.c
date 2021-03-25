/*Вариант 11*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
#include<complex.h>
#include<math.h>

int main() {
    setlocale(LC_ALL, "ru");
    int UserInput, res = 1, k = 0, n, s;
    double Rez, Imz, r, f, a, b, j, J;
    while (res == 1) {
        printf("\nМеню программы\n");
        printf("Выберите одну из следующих функций: \n");
        printf("1. Ввод комплексного числа\n");
        printf("2. Вывод комплексного числа в алгебраической форме.\n");
        printf("3. Вывод комплексного числа в показательной форме.\n");
        printf("4. Получение сопряженного комплексного числа\n");
        printf("5. Возведение комплексного числа в целую положительную степень.\n");
        printf("6. Информация о версии и авторе программы.\n");
        printf("7. Выход из программы.\n");
        s = scanf("%d", &UserInput);
        if (s != 1)
            do {
                s = scanf("%d", &UserInput);
                while (getchar() != '\n');
                if (s != 1) {
                    printf("%s", "Можно вводить только цифры !!!\n");
                    return;
                }
            } while (s != 1);
            if (UserInput < 1 || UserInput > 7) {
                printf("Выберите одну из предложенных функций!!!\n");
                return;
            }
            switch (UserInput)
            {
            case 1:
                system("cls");
                k = 1;
                printf("Введите действительную часть комплексного числа: ");
                s = scanf("%lf", &Rez);
                if (s != 1)
                    do {
                        s = scanf("%d", &Rez);
                        while (getchar() != '\n');
                        if (s != 1) {
                            printf("%s", "Можно вводить только цифры !!!\n");
                            return;
                        }
                    } while (s != 1);
                    printf("Введите мнимую часть комплексного числа: ");
                    s = scanf("%lf", &Imz);
                    if (s != 1)
                        do {
                            s = scanf("%d", &Imz);
                            while (getchar() != '\n');
                            if (s != 1) {
                                printf("%s", "Можно вводить только цифры !!!\n");
                                return;
                            }
                        } while (s != 1);
                        break;
            case 2:
                system("cls");
                if (k == 0)
                {
                    printf("Вы не ввели комплексное число.\n");
                    printf("Введите действительную часть комплексного числа: ");
                    s = scanf("%lf", &Rez);
                    if (s != 1)
                        do {
                            s = scanf("%d", &Rez);
                            while (getchar() != '\n');
                            if (s != 1) {
                                printf("%s", "Можно вводить только цифры !!!\n");
                                return;
                            }
                        } while (s != 1);
                        printf("Введите мнимую часть комплексного числа: ");
                        s = scanf("%lf", &Imz);
                        if (s != 1)
                            do {
                                s = scanf("%d", &Imz);
                                while (getchar() != '\n');
                                if (s != 1) {
                                    printf("%s", "Можно вводить только цифры !!!\n");
                                    return;
                                }
                            } while (s != 1);
                            printf("z = (%lf)", Rez);
                            printf(" + i*(%lf)\n", Imz);
                }
                else
                {
                    printf("z = (%lf)", Rez);
                    printf(" + i*(%lf)\n", Imz);
                }
                break;
            case 3:
                system("cls");
                if (k == 0)
                {
                    printf("Вы не ввели комплексное число.\n");
                    printf("Введите действительную часть комплексного числа: ");
                    s = scanf("%lf", &Rez);
                    if (s != 1)
                        do {
                            s = scanf("%d", &Rez);
                            while (getchar() != '\n');
                            if (s != 1) {
                                printf("%s", "Можно вводить только цифры !!!\n");
                                return;
                            }
                        } while (s != 1);
                        printf("Введите мнимую часть комплексного числа: ");
                        s = scanf("%lf", &Imz);
                        if (s != 1)
                            do {
                                s = scanf("%d", &Imz);
                                while (getchar() != '\n');
                                if (s != 1) {
                                    printf("%s", "Можно вводить только цифры !!!\n");
                                    return;
                                }
                            } while (s != 1);
                            r = sqrt(pow(Rez, 2) + pow(Imz, 2));
                            f = tan(Imz / Rez);
                            printf("z = (%lf)", r);
                            printf("*e^((%lf)*i)\n", f);
                }
                else
                {
                    r = sqrt(pow(Rez, 2) + pow(Imz, 2));
                    f = tan(Imz / Rez);
                    printf("z = (%lf)", r);
                    printf("*e^((%lf)*i)\n", f);
                }
                break;
            case 4:
                system("cls");
                if (k == 0)
                {
                    printf("Вы не ввели комплексное число.\n");
                    printf("Введите действительную часть комплексного числа: ");
                    s = scanf("%lf", &Rez);
                    if (s != 1)
                        do {
                            s = scanf("%d", &Rez);
                            while (getchar() != '\n');
                            if (s != 1) {
                                printf("%s", "Можно вводить только цифры !!!\n");
                                return;
                            }
                        } while (s != 1);
                        printf("Введите мнимую часть комплексного числа: ");
                        s = scanf("%lf", &Imz);
                        if (s != 1)
                            do {
                                s = scanf("%d", &Imz);
                                while (getchar() != '\n');
                                if (s != 1) {
                                    printf("%s", "Можно вводить только цифры !!!\n");
                                    return;
                                }
                            } while (s != 1);
                            printf("z = (%lf)", Rez);
                            printf(" - i*(%lf)\n", Imz);
                }
                else
                {
                    printf("z = (%lf)", Rez);
                    printf(" - i*(%lf)\n", Imz);
                }
                break;
            case 5:
                system("cls");
                if (k == 0)
                {
                    printf("Вы не ввели комплексное число.\n");
                    printf("Введите действительную часть комплексного числа: ");
                    s = scanf("%lf", &Rez);
                    if (s != 1)
                        do {
                            s = scanf("%d", &Rez);
                            while (getchar() != '\n');
                            if (s != 1) {
                                printf("%s", "Можно вводить только цифры !!!\n");
                                return;
                            }
                        } while (s != 1);
                        printf("Введите мнимую часть комплексного числа: ");
                        s = scanf("%lf", &Imz);
                        if (s != 1)
                            do {
                                s = scanf("%d", &Imz);
                                while (getchar() != '\n');
                                if (s != 1) {
                                    printf("%s", "Можно вводить только цифры !!!\n");
                                    return;
                                }
                            } while (s != 1);
                            printf("В какую степень вы хотите возвести Комплексное число ?\nn = ");
                            s = scanf("%d", &n);
                            if (s != 1)
                                do {
                                    s = scanf("%d", &n);
                                    while (getchar() != '\n');
                                    if (s != 1) {
                                        printf("%s", "Можно вводить только цифры !!!\n");
                                        return;
                                    }
                                } while (s != 1);
                                if (n < 0) {
                                    printf("Ошибка...\n");
                                    return;
                                }
                                r = sqrt(pow(Rez, 2) + pow(Imz, 2));
                                f = tan(Imz / Rez);
                                a = pow(r, n);
                                b = n * f;
                                j = cos(b);
                                J = sin(b);
                                printf("z = %lf", a);
                                printf("((%lf)", j);
                                printf("+(%lf)*i)\n", J);
                }
                else
                {
                    printf("В какую степень вы хотите возвести Комплексное число ?\nn = ");
                    s = scanf("%d", &n);
                    if (s != 1)
                        do {
                            s = scanf("%d", &n);
                            while (getchar() != '\n');
                            if (s != 1) {
                                printf("%s", "Можно вводить только цифры !!!\n");
                                return;
                            }
                        } while (s != 1);
                        if (n < 0) {
                            printf("Ошибка...\n");
                            return;
                        }
                        r = sqrt(pow(Rez, 2) + pow(Imz, 2));
                        f = tan(Imz / Rez);
                        a = pow(r, n);
                        b = n * f;
                        j = cos(b);
                        J = sin(b);
                        printf("z = %lf", a);
                        printf("((%lf)", j);
                        printf("+(%lf)*i)\n", J);
                }
                break;
            case 6:
                system("cls");
                printf("Вы вошли во вкладку: Информация о версии и авторе программы.\n");
                printf("На данный момент это версия 1.0.\nАвторам данной программы является студент 1 курса БГУИР группы 053502 Каралёв Иван.\n");
                break;
            case 7:
                system("cls");
                printf("Вы вышли из программы.\n");
                res = 0;
                return;
                break;
            }
    }
    return 0;
}