// Рассматриваемые темы:
// Перечисления

#pragma once

#include <iostream>
using namespace std;

namespace Enum
{
    // Перечисление - пользовательский тип данных,
    // который состоит из перечисленного набора констант
    // Переменная такого типа данных может принимать только
    // строго заданный набор значений
    enum Currency
    {
        Dollar, Euro, Ruble, Pound
    }; // <== Опять же не забываем про ';'!!!

    struct BankAccount
    {
        int sum;
        Currency currency;
    };

    void main()
    {
        BankAccount ivan;
        ivan.sum = 1200;
        ivan.currency = Currency::Ruble;

        BankAccount victor;
        victor.sum = 5000;
        victor.currency = Currency::Dollar;
    }
}