#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>

int main()
{
    char b[8000];
    FILE* fp;
    /*fp = fopen("input.txt", "w+");
    printf("Enter your text: \n");
    gets(b, 4500, stdin);
    fprintf(fp, "%s", b);
    fclose(fp);*/

    fopen_s(&fp, "input.txt", "r");
    int m = 0, k = 0, i;
    //���� m-����� ������������ ������
    do
    {
        while ((getc(fp) != '\n') && (!feof(fp)))
            k++;
        if (k > m) m = k;
        k = 0;
    } while (!feof(fp));
    rewind(fp);
    FILE* fp_out;
    fopen_s(&fp_out, "output.txt", "w+");
    int space, len, beginning_line; //���-�� ��������, ����� � ��������� �� ������ ������� ������
    char c;
    do
    {
        space = len = 0;
        beginning_line = ftell(fp);
        //������� ���������� ��������
        while (((c = getc(fp)) != '\n') && (!feof(fp)))
        {
            if (c == ' ') space++;
            len++;
        }
        fseek(fp, beginning_line, SEEK_SET);
        while (((c = getc(fp)) != '\n') && (!feof(fp)))
        {
            if (c != ' ') fprintf(fp_out, "%c", c);
            else
            {
                //k - ���������� ��������, ������� ����� �������
                if ((m - len) % space) //���� ������� � ����� ������������ ������ � ������� �� ������� ������ �� ���������� �������� � ������� ������
                {
                    k = (m - len) / space + 2; //+1 �������� ������ � +1 ������ �� ������� �������, ������� +2
                    len++; //����� ������ �� ������� � ��� ����� ����, ��� ��������� ������ ������
                }
                else k = (m - len) / space + 1; //+1 ��� �� ��������� �������� ������, �� ������� �������
                for (i = 0; i < k; i++)
                    fprintf(fp_out, " ");
            }
        }
        fprintf(fp_out, "\n");
    } while (!feof(fp));
    fclose(fp);
    fclose(fp_out);


    fopen_s(&fp_out, "output.txt", "r");
    while (!feof(fp_out)) {
        fscanf(fp_out, " %s ", b);
        printf("%s ", b);
        //puts(fp_out);
    }
    fclose(fp_out);
    return 0;
}

//5 - 6: ��������� ���� input.txt ��� ������ ������� ������.

//9 - 15 : ���� ����� ������� ������ � ������� �� ����� � ���������� m.

//16 : ������������ � ������ �����.

//17 - 18 : ��������� ��� ������� ���� output.txt ��� ������ ���������� ������ ���������.

//21 - 49 : ���� �� ������, �� ����� �������� �����.���������� ������� ������� ������ 
//������ ������ �� ������� �����, ������� ���������� �������� � ���� ������, 
//������������ � ������ ���� ������, ����������� ������� � output.txt ������� ������ � 
//������ ����������� �������� ����� �������, ��� ����� ����������� ����� �� ������, 
//������������ ��� �� ��������� �������, � ��� �� ����� �����.