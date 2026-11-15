#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

typedef struct {
    int number;
    int arr_hour;
    int arr_min;
    int dep_hour;
    int dep_min;
    char direction[50];
    double distance;
} Train;

void writefile(char* fname, Train* arr, int size)
{
    FILE* out;
    out = fopen(fname, "wt");
    for (int i = 0; i < size; i++)
    {
        fprintf(out, "No:%3d ; Прибытие:%02d:%02d ; Отбытие:%02d:%02d ; Направление:%15s ; Расстояние:%6.1f\n",
            arr[i].number,
            arr[i].arr_hour, arr[i].arr_min,
            arr[i].dep_hour, arr[i].dep_min,
            arr[i].direction,
            arr[i].distance);
    }
    fclose(out);
}

int main(void)
{
    setlocale(LC_ALL, "RUS");
    Train trains[3] = {
        { 101, 10, 15, 10, 30, "Москва_Курская", 450.5 },
        { 205, 12, 00, 12, 20, "Санкт_Петербург", 650.0 },
        { 312, 18, 45, 19, 00, "Казань_Центр", 820.3 }
    };

    writefile("trains.txt", trains, 3);
    printf("Записано в файл trains.txt.\n");
}
