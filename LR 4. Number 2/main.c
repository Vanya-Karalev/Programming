#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void search4u(FILE* fp, char* word, char* ans);

int main()
{
    FILE* fp;
    if ((fp = fopen("dict.txt", "r")) == NULL)
    {
        printf("Oh cringe, smth went wrong\n");
        return(-1);
    }
    /*if ((fp = fopen("D:\\words.txt", "r")) == NULL)
    {
        printf("Oh cringe, smth went wrong\n");
        return(-1);
    }*/

    char word[15];
    gets(word);
    char ans[120];
    search4u(fp, word, ans);
    printf("%s\n", ans);
    fclose(fp);
}

void search4u(FILE* fp, char* word, char* ans)
{
    static char str[10000];
    int result = 0;
    while (!feof(fp))
    {
        if (!fgets(str, 10000, fp))
        {
            printf("Oh cringe, smth went wrong\n");
            exit(-1);
        }
    }

    int lenght = 0, lenStr = 0;
    int i = 0, j = 0;
    while (1 > 0)
    {
        if (word[lenght] == '\0')/*   *   */
        {
            break;
        }
        lenght++;
    }

    for (i = 0; i < lenght; i++)
    {
        for (j = 0; j < lenght - 1; j++)
        {
            char let;
            if (word[j] > word[j + 1])
            {
                let = word[j + 1];/*   *   */
                word[j + 1] = word[j];
                word[j] = let;
            }
        }
    }

    for (i = 0; i < 120; i++)
    {
        ans[i] = '\0';
    }

    while (1 > 0)
    {
        if (str[lenStr] == '\0')
        {
            break;
        }
        lenStr++;
    }

    char tmpWord[15] = { 0 };
    char tmpWordCopy[15] = { 0 };
    int n = 0;
    int k = 0;
    for (i = 0; i <= lenStr; i++)
    {
        if (str[i] != ' ' && str[i] != '\0')
        {
            tmpWordCopy[n] = str[i];
            tmpWord[n] = str[i];
            n++;
        }
        else if (n == lenght)
        {
            int b;
            for (b = 0; b < n; b++)
            {
                for (j = 0; j < n - 1; j++)
                {
                    char let;
                    if (tmpWord[j] > tmpWord[j + 1])
                    {
                        let = tmpWord[j + 1];
                        tmpWord[j + 1] = tmpWord[j];
                        tmpWord[j] = let;
                    }
                }
            }
            int flag = 0;
            for (j = 0; j < lenght; j++)
            {
                if (word[j] != tmpWord[j])/*   *   */
                {
                    flag = -1;
                    break;
                }
            }
            if (flag != -1)
            {
                for (j = 0; j < n; j++)
                {
                    ans[k] = tmpWordCopy[j];
                    if (k + 1 < 120)
                    {
                        k++;
                    }
                    else
                    {
                        break;
                    }
                }
                ans[k++] = ' ';
                j = 0;
            }
            for (j = 0; j < n; j++)
            {
                tmpWord[j] = '\0';
                tmpWordCopy[j] = '\0';
            }
            n = 0;
        }
        else if (n != 0)
        {
            for (j = 0; j < n; j++)
            {
                tmpWord[j] = '\0';
                tmpWordCopy[j] = '\0';
            }
            n = 0;
        }
    }
}