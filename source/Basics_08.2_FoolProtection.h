// Изучаемые темы:
// Защита от дурака

#pragma once

#include <iostream>
using namespace std;

namespace FoolProtection
{
    int readNumber()
    {

        do
        {
            int buffLen = 20;
            char* buff = new char[buffLen];

            cout << "Input number: ";
            cin.getline(buff, buffLen);

            bool isOk = true;
            for (int i = 0; i < strlen(buff); i++)
                if (buff[i] < '0' || buff[i] > '9') {
                    isOk = false;
                    break;
                }

            if (!isOk)
                cout << "Not number. Try again!" << endl;
            else 
                return atoi(buff);
        } while (true);
    }

    int main()
    {
        int a = readNumber(), b = readNumber(), c = readNumber();

        cout << endl << "a * b * c = " << a*b*c << endl;

        return 0;
    }
}