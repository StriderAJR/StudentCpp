// ��������������� ����:
// �������� ����/�����

#pragma once

#include <iostream>
#include <fstream>

using namespace std;

namespace FileInputOutput
{
    const char* FILE_NAME = "Example.txt";

    void prepareFile()
    {
        ofstream file;
        // �� ��������� ofstream ��� �������� ����������� ����,
        // �.�. ������� ������, ���� �� � ����, � ������� �����, ������.
        file.open(FILE_NAME);

        if(!file)
        {
            cout << "Could not open file. Sorry.";
            return;
        }

        file << "My test file. Hi." << endl;
        file << "I'm a multi line file, you know ;)" << endl;
        file << "Want some more?" << endl;
        file << "Hey! Give me a break!" << endl;
        file << "Ok. Now you've got it." << endl;
        file << "Fine! Eat it!" << endl;
        file << "Mille-feuille. Satisfied? Now shoo-shoo!" << endl;
        
        file.close();
    }

    void main()
    {
        prepareFile();

        ifstream file;
        file.open(FILE_NAME);

        if (!file)
        {
            cout << "No kino. Electricity is no more.";
            return;
        }

        const int bufSize = 255;
        char buf[bufSize];
        // �������� >> ������ �� ����-�������, ��������
        // �������� '\n' � ' '. ��� ��� ��� ���������������� ���� ��������
        file >> buf;
        cout << buf << endl;

        file >> buf;
        cout << buf << endl;

        while(file.getline(buf, bufSize))
        {
            cout << buf << endl;
        }

        file.close();
    }
}