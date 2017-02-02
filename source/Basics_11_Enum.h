// ��������������� ����:
// ������������

#pragma once

#include <iostream>
using namespace std;

namespace Enum
{
    // ������������ - ���������������� ��� ������,
    // ������� ������� �� �������������� ������ ��������
    // ���������� ������ ���� ������ ����� ��������� ������
    // ������ �������� ����� ��������
    enum Currency
    {
        Dollar, Euro, Ruble, Pound
    }; // <== ����� �� �� �������� ��� ';'!!!

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
