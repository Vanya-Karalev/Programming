/*������� 11*/
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
        printf("\n���� ���������\n");
        printf("�������� ���� �� ��������� �������: \n");
        printf("1. ���� ������������ �����\n");
        printf("2. ����� ������������ ����� � �������������� �����.\n");
        printf("3. ����� ������������ ����� � ������������� �����.\n");
        printf("4. ��������� ������������ ������������ �����\n");
        printf("5. ���������� ������������ ����� � ����� ������������� �������.\n");
        printf("6. ���������� � ������ � ������ ���������.\n");
        printf("7. ����� �� ���������.\n");
        s = scanf("%d", &UserInput);
        if (s != 1)
            do {
                s = scanf("%d", &UserInput);
                while (getchar() != '\n');
                if (s != 1) {
                    printf("%s", "����� ������� ������ ����� !!!\n");
                    return;
                }
            } while (s != 1);
            if (UserInput < 1 || UserInput > 7) {
                printf("�������� ���� �� ������������ �������!!!\n");
                return;
            }
            switch (UserInput)
            {
            case 1:
                system("cls");
                k = 1;
                printf("������� �������������� ����� ������������ �����: ");
                s = scanf("%lf", &Rez);
                if (s != 1)
                    do {
                        s = scanf("%d", &Rez);
                        while (getchar() != '\n');
                        if (s != 1) {
                            printf("%s", "����� ������� ������ ����� !!!\n");
                            return;
                        }
                    } while (s != 1);
                    printf("������� ������ ����� ������������ �����: ");
                    s = scanf("%lf", &Imz);
                    if (s != 1)
                        do {
                            s = scanf("%d", &Imz);
                            while (getchar() != '\n');
                            if (s != 1) {
                                printf("%s", "����� ������� ������ ����� !!!\n");
                                return;
                            }
                        } while (s != 1);
                        break;
            case 2:
                system("cls");
                if (k == 0)
                {
                    printf("�� �� ����� ����������� �����.\n");
                    printf("������� �������������� ����� ������������ �����: ");
                    s = scanf("%lf", &Rez);
                    if (s != 1)
                        do {
                            s = scanf("%d", &Rez);
                            while (getchar() != '\n');
                            if (s != 1) {
                                printf("%s", "����� ������� ������ ����� !!!\n");
                                return;
                            }
                        } while (s != 1);
                        printf("������� ������ ����� ������������ �����: ");
                        s = scanf("%lf", &Imz);
                        if (s != 1)
                            do {
                                s = scanf("%d", &Imz);
                                while (getchar() != '\n');
                                if (s != 1) {
                                    printf("%s", "����� ������� ������ ����� !!!\n");
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
                    printf("�� �� ����� ����������� �����.\n");
                    printf("������� �������������� ����� ������������ �����: ");
                    s = scanf("%lf", &Rez);
                    if (s != 1)
                        do {
                            s = scanf("%d", &Rez);
                            while (getchar() != '\n');
                            if (s != 1) {
                                printf("%s", "����� ������� ������ ����� !!!\n");
                                return;
                            }
                        } while (s != 1);
                        printf("������� ������ ����� ������������ �����: ");
                        s = scanf("%lf", &Imz);
                        if (s != 1)
                            do {
                                s = scanf("%d", &Imz);
                                while (getchar() != '\n');
                                if (s != 1) {
                                    printf("%s", "����� ������� ������ ����� !!!\n");
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
                    printf("�� �� ����� ����������� �����.\n");
                    printf("������� �������������� ����� ������������ �����: ");
                    s = scanf("%lf", &Rez);
                    if (s != 1)
                        do {
                            s = scanf("%d", &Rez);
                            while (getchar() != '\n');
                            if (s != 1) {
                                printf("%s", "����� ������� ������ ����� !!!\n");
                                return;
                            }
                        } while (s != 1);
                        printf("������� ������ ����� ������������ �����: ");
                        s = scanf("%lf", &Imz);
                        if (s != 1)
                            do {
                                s = scanf("%d", &Imz);
                                while (getchar() != '\n');
                                if (s != 1) {
                                    printf("%s", "����� ������� ������ ����� !!!\n");
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
                    printf("�� �� ����� ����������� �����.\n");
                    printf("������� �������������� ����� ������������ �����: ");
                    s = scanf("%lf", &Rez);
                    if (s != 1)
                        do {
                            s = scanf("%d", &Rez);
                            while (getchar() != '\n');
                            if (s != 1) {
                                printf("%s", "����� ������� ������ ����� !!!\n");
                                return;
                            }
                        } while (s != 1);
                        printf("������� ������ ����� ������������ �����: ");
                        s = scanf("%lf", &Imz);
                        if (s != 1)
                            do {
                                s = scanf("%d", &Imz);
                                while (getchar() != '\n');
                                if (s != 1) {
                                    printf("%s", "����� ������� ������ ����� !!!\n");
                                    return;
                                }
                            } while (s != 1);
                            printf("� ����� ������� �� ������ �������� ����������� ����� ?\nn = ");
                            s = scanf("%d", &n);
                            if (s != 1)
                                do {
                                    s = scanf("%d", &n);
                                    while (getchar() != '\n');
                                    if (s != 1) {
                                        printf("%s", "����� ������� ������ ����� !!!\n");
                                        return;
                                    }
                                } while (s != 1);
                                if (n < 0) {
                                    printf("������...\n");
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
                    printf("� ����� ������� �� ������ �������� ����������� ����� ?\nn = ");
                    s = scanf("%d", &n);
                    if (s != 1)
                        do {
                            s = scanf("%d", &n);
                            while (getchar() != '\n');
                            if (s != 1) {
                                printf("%s", "����� ������� ������ ����� !!!\n");
                                return;
                            }
                        } while (s != 1);
                        if (n < 0) {
                            printf("������...\n");
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
                printf("�� ����� �� �������: ���������� � ������ � ������ ���������.\n");
                printf("�� ������ ������ ��� ������ 1.0.\n������� ������ ��������� �������� ������� 1 ����� ����� ������ 053502 ������ ����.\n");
                break;
            case 7:
                system("cls");
                printf("�� ����� �� ���������.\n");
                res = 0;
                return;
                break;
            }
    }
    return 0;
}