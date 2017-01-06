// Рассматриваемые темы:
// Ссылки и указатели

#pragma once

#include <iostream>
#include <string.h>
using namespace std;
 
namespace ReferencesPractic
{
    int sum_by_value(int);// суммирование по значению
    int sum_by_reference(int &);// суммирование по ссылке
    int sum_by_pointer(int *); // суммирование по указателю

    int main()
    {
        int value = 15;
        int& reference = value; // объявление и инициализация ссылки значением переменной value

        cout << "value     = " << value << endl;
        cout << "reference = " << reference << endl;

        char* string = NULL;

        reference += 15; // изменяем значение переменной value посредством изменения значения в ссылке

        cout << "value     = " << value << endl; // смотрим, что получилось, как будет видно дальше значение поменялось как в ссылке,
        cout << "reference = " << reference << endl; //  так и в ссылочной переменной

        system("pause");

        value = 10;

        cout << "sum_by_value     = " << sum_by_value(value) << endl;
        cout << "value = " << value << endl; // значение переменной осталось неизменным
        cout << "sum_by_reference = " << sum_by_reference(value) << endl;
        cout << "value = " << value << endl; // значение переменной изменилось
        cout << "sum_by_pointer     = " << sum_by_pointer(&value) << endl;
        cout << "value = " << value << endl; // значение переменной изменилось ещё раз

        system("pause");

        return 0;
    }

    int sum_by_value(int value)// функция принимающая аргумент по значению
    {
        value += value;
        return value;
    }

    int sum_by_reference(int& reference) // функция принимающая аргумент по ссылке
    {
        reference += reference;
        return reference;
    }

    int sum_by_pointer(int* ptrvalue)// функция принимающая аргумент через указатель
    {
        *ptrvalue += *ptrvalue; // арифметика с указателем
        return *ptrvalue;
    }
}
