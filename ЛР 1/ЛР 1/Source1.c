//Вариант 11
#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "ru");
    int k = 0, res;
    printf("Введите число k: ");
    res = scanf_s("%d", &k);
    if (res != 1) 
        do {
            res = scanf_s("%d", &k);
            while (getchar() != '\n');
            if (res != 1) printf("%s", "Можно вводить только цифры !!!\nВведите число k: \n");
        } while (res != 1);
    int s = 0, i = 0, b, c, n, a;
    while (s < k)
    {
        i = i++;
        b = i * i;
        c = 1;
        n = 10;
        while (b / n != 0)
        {
            n = n * 10;
            c = c++;
        }
        s = s + c;
        printf("%d ", b);
    }
    s = s - c;
    n = n / 10;
    while (s != k)
    {
        a = b / n % 10;
        n = n / 10;
        s = s++;
    }
    printf("\nОтвет: %d", a);
    return 0;
}