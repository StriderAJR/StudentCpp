#pragma once

#include <windows.h>
#include <iostream>

using namespace std;

namespace ConsoleDraw
{
    void ConsoleDraw_Main()
    {
        // Get window handle to console, and device context
        HWND console_handle = GetConsoleWindow();
        HDC device_context = GetDC(console_handle);

        //Here's a 5 pixels wide RED line [from initial 0,0] to 300,300
        HPEN pen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
        SelectObject(device_context, pen);
        LineTo(device_context, 300, 300);


        ReleaseDC(console_handle, device_context);
        cin.ignore();
    }
}