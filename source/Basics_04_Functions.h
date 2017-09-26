// ��������������� ����:
// �������

#pragma once

#include <iostream>
using namespace std;

namespace Functions
{
    // ������� - ��� ����������� ����� ����, 
    // ������� ����� �������� ��� ���������� �������������� ���-�� ���
    // �������� ������ �-��� - ������� ��� ����� ���������� � ��������

    // ������ ���������� �-���
    int add(int a, int b) // <-- ��������� �-���
    { // <-- ������ ���� �-���

        // ��� ����� ���� ����� ���, ������� ����� ���������

        return a + b; // ���������� ��������� ������ �������
    } // <-- ����� ���� �-���

    // ��������� �-��� ����������� ������ �������� �� ��������� ���������:
    
    // ��� ���_�������(������_����������)

    // ��� ������������� �������� (���)
    // ��� ��� ������ ���������� ������ �-���. ������ ��������� ��������� � ���� � ����� ������ ����� �-���
    // ���� �-��� �� ����� ����� ��������� (������ ���-�� ������ � ���), ����� ��� ������������� �������� ����� void - ���������� ����
    
    // ��� �������
    // ������ ������ ��������� ������� � �� ����� �-��� ������ ���� ����� �������, ��� ��� ������. 
    // ������� ������� ���� �-���: readFromFile, writeToFile, getVectorLength, multiplyMatrix, add
    // ������� ������ ���� �������: func1, foo, boo, getResult, do, blablabla
    
    // ������ ����������
    // ��������� ������������� � �-��� ����� �������. �������� - ��� ��������� ���������� ��� �������, � ������ �� ���������� ����������.
    // ��������� ����� ���������������. int param1, double param2 � �.�.

    // ��� ������� �������� �-���:

    void writeToFile(char* str)
    {
        // ...
    }

    double devide(int a, double b, float c)
    {
        return a / b / c;
    }

    void consoleRead(char* buff, int num)
    {
        cin.getline(buff, num);
    }
    

    int main() 
    {
        double a = devide(10, 3.7, 1.2);
        // ^^^
        // ��� ����� �����������: 
        // 1. ��������� �-���, ��������� (��������� ���������� �-���) ������������������� ���������������� ���������� (a = 10, b = 3.7, c = 1.2)
        // �������� ��������, ��� ���������� a � �-��� main � ���������� a - � �-��� devide - ������ ��������� ����������!
        // ��������!!! ������ ���������� ������ ������ ������ ����� ����. � ��� ����� �� ������������, ��� ������ ������ � ������.
        // 2. �-��� devide ������ ���� ���� (������, ��� ��� ������ ��� � �-��� main ����� �� ������� - ��� ������ ���� ����� �-���)
        // 3. ��� �-��� ����������, ������ ���� ����������� "devide(10, 3.7, 1.2)" ����������� �������� ��������� ������ �-���.
        // ����� ���-�� �����
        // double a = ���������;

        // � �������� ������� �� ����� �� ���������:
        
        while (a > 0)
        {
            cout << a << endl;
            int p1; double p2; float p3;
            cin >> p1 >> p2 >> p3;
            a = devide(p1, p2, p3);
        }

        return 0;
    }
}