// Рассматриваемые темы:
// Рисование в консоли
// ВНИМАНИЕ! Работает только в Windows

#pragma once

#include <windows.h>
#include <iostream>

using namespace std;

namespace ConsoleDraw
{
    void DrawLine(int x1, int y1, int x2, int y2)
    {
        // Get window handle to console, and device context
        HWND console_window = GetConsoleWindow();
        HDC device_context = GetDC(console_window);

        //Here's a 5 pixels wide RED line [from initial 0,0] to 300,300
        HPEN pen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
        SelectObject(device_context, pen);
        MoveToEx(device_context, x1, y1, NULL);
        LineTo(device_context, x2, y2);

        ReleaseDC(console_window, device_context);
    }

    void DrawRectangle(int x, int y, unsigned int width, unsigned int height)
    {
        int x1 = x, y1 = y;
        int x2 = x + width, y2 = y;
        int x3 = x2, y3 = y2 + height;
        int x4 = x1, y4 = y1 + height;

        HWND console_window = GetConsoleWindow();
        HDC device_context = GetDC(console_window);

        HPEN pen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
        SelectObject(device_context, pen);

        MoveToEx(device_context, x1, y1, NULL);
        LineTo(device_context, x2, y2);
        LineTo(device_context, x3, y3);
        LineTo(device_context, x4, y4);
        LineTo(device_context, x1, y1);

        ReleaseDC(console_window, device_context);
    }

    void DrawEllipse()
    {
        HWND console_window = GetConsoleWindow();
        HDC device_context = GetDC(console_window);

        HPEN pen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
        HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0));   // to fill with green
        SelectObject(device_context, pen);
        SelectObject(device_context, brush);

        Ellipse(device_context, 90, 90, 120, 120);

        ReleaseDC(console_window, device_context);
    }

    void DrawText()
    {
        HWND console_window = GetConsoleWindow();
        HDC device_context = GetDC(console_window);

        SetTextColor(device_context, RGB(255, 0, 0));
        SetBkColor(device_context, RGB(0, 255, 0));

        TextOut(device_context, 150, 50, L"This is a text", 14);

        ReleaseDC(console_window, device_context);
    }

    void DrawSmile()
    {
        HWND console_window = GetConsoleWindow();
        HDC device_context = GetDC(console_window);

        HPEN pen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
        HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0));   // to fill with green
        SelectObject(device_context, pen);
        SelectObject(device_context, brush);

        Ellipse(device_context, 360, 240, 480, 310);
        SetPixel(device_context, 400, 260, RGB(0, 0, 255));   // draw one pixel
        SetPixel(device_context, 440, 260, RGB(0, 0, 255));
        SetPixel(device_context, 420, 270, RGB(0, 0, 255));
        Arc(device_context, 380, 260, 460, 290, 380, 275, 460, 275);
    }

    void main()
    {
        //    DrawLine(100, 100, 100, 200);
        //    DrawRectangle(50, 50, 200, 100);
        //    DrawEllipse();
        //    DrawText();
        DrawSmile();

        cin.ignore();
    }
}
