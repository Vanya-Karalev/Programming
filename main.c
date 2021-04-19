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
    //ищем m-длину максимальной строки
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
    int space, len, beginning_line; //кол-во пробелов, длина и указатель на начало текущей строки
    char c;
    do
    {
        space = len = 0;
        beginning_line = ftell(fp);
        //считаем количество пробелов
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
                //k - количество пробелов, которое нужно вывести
                if ((m - len) % space) //если разница в длине максимальной строки и текущей не делитс€ нацело на количество пробелов в текущей строке
                {
                    k = (m - len) / space + 2; //+1 исходный пробел и +1 пробел от остатка делени€, поэтому +2
                    len++; //чтобы больше не входить в эту часть кода, при обработке данной строки
                }
                else k = (m - len) / space + 1; //+1 что бы сохранить исходный пробел, на который выводим
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

//5 - 6: ќткрываем файл input.txt дл€ чтени€ входных данных.

//9 - 15 : »щем самую длинную строку и заносим ее длину в переменную m.

//16 : ¬озвращаемс€ к началу файла.

//17 - 18 : ќткрываем или создаем файл output.txt дл€ вывода результата работы программы.

//21 - 49 : ÷икл от начала, до конца входного файла.«апоминаем текущую позицию начала 
//данной строки во входном файле, считаем количество пробелов в этой строке, 
//возвращаемс€ к началу этой строки, посимвольно выводим в output.txt текущую строку с 
//нужным количеством пробелов между словами, тем самым выравниваем текст по ширине, 
//обрабатываем так же следующую строчку, и так до конца файла.