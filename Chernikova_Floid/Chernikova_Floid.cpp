// Chernikova_Floid.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int** mas = NULL;
int kol = 0;

//вычисление минимального пути по Флойду
void minFLOID(int** m, int kl)
{
    for (int k = 0; k < kl; k++) {
        for (int i = 0; i < kl; i++) {
            for (int j = 0; j < kl; j++) {
                if (m[i][j] > m[i][k] + m[k][j])
                {
                    m[i][j] = m[i][k] + m[k][j];
                }
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите число вершин графа" << endl;
    cin >> kol;
    if (kol < 1) {

        return 0;
    }

    mas = new int* [kol];
    for (int i = 0; i < kol; i++) mas[i] = new int[kol];

    cout << "Введите матрицу смежности графа:" << endl;
    for (int i = 0; i < kol; i++)
        for (int j = 0; j < kol; j++) cin >> mas[i][j];
    for (int i = 0; i < kol; i++) mas[i][i] = 0;

    minFLOID(mas, kol);

    cout << "Минимальные пути между вершинами:" << endl;
    for (int i = 0; i < kol; i++) {
        for (int j = 0; j < kol; j++) {
            cout << mas[i][j] << "  ";
        }
        cout << endl;

    }

    return 0;
}