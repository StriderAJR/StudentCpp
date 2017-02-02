// –ассматриваемые темы:
// ѕеречислени€

#pragma once

#include <iostream>
using namespace std;

namespace Enum
{
    // ѕеречисление - пользовательский тип данных,
    // который состоит из перечисленного набора констант
    // ѕеременна€ такого типа данных может принимать только
    // строго заданный набор значений
    enum Currency
    {
        Dollar, Euro, Ruble, Pound
    }; // <== ќп€ть же не забываем про ';'!!!

    struct BankAccount
    {
        int sum;
        Currency currency;
    };

    void main()
    {
        BankAccount ivan;
        ivan.sum = 1200;
        ivan.currency = Ruble;

        BankAccount victor;
        victor.sum = 5000;
        victor.currency = Dollar;
    }
}
