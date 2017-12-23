#pragma once

#include <iostream>
using namespace std;

namespace Strings
{
    char* readString()
    {
        char buf[255]; // Создаем буфер с "запасом", чтобы хватило
        cin.get(buf, 255); // Читаем данные в него
        char* str = new char[strlen(buf)]; // Выделяем ровно столько памяти, сколько "полезных" символов в буфере
                                            // strlen - ф-ция определения длины строки. Она считает символы только до нулевого байта
                                            // Если пользователь ввел всего 10 символов, то strlen и вернет 10
        strcpy(str, buf); // Копируем реальную строку из буфера в переменную str2
        return str;
    }

    int main()
    {
        char str0[7] = "qwerty";
        cout << str0 << endl;
        str0[6] = '!';
        cout << str0 << endl;

        char str1[5];
        cout << "Введите строку str1: ";
        cin.getline(str1, 5);
        cout << str1 << endl;


        char* buf = new char[255]; // Создаем буфер с "запасом", чтобы хватило
        cout << "Введите строку str2: ";
        cin.getline(buf, 255); // Читаем данные в него
        char* str2 = new char[strlen(buf)]; // Выделяем ровно столько памяти, сколько "полезных" символов в буфере
        // strlen - ф-ция определения длины строки. Она считает символы только до нулевого байта
        // Если пользователь ввел всего 10 символов, то strlen и вернет 10
        strcpy(str2, buf); // Копируем реальную строку из буфера в переменную str2
        delete[] buf; // Удаляем ненужный больше буфер
        cout << str2 << endl;

        cout << "Введите строку str3: ";
        char* str3 = readString();
        cout << str3 << endl;

        return 0;
    }
}