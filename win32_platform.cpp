#include <windows.h>

bool running = true;

LRESULT CALLBACK WindowCallback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;

    switch(uMsg)
    {
        case WM_CLOSE:
        case WM_DESTROY:
            running = false;
            break;
        default:
            result = DefWindowProc(hwnd, uMsg, wParam, lParam);

    }
    return result;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowcmd)
{
    // TO DO: 
    // Create Window Class
    WNDCLASSA windowClass = {0};
    windowClass.style = CS_HREDRAW | CS_VREDRAW;
    windowClass.lpszClassName = "Secret Sealing Club: Moon's Reflection";
    windowClass.lpfnWndProc = WindowCallback;

    // Register Class
    RegisterClass(&windowClass);

    // Create Window
    HWND window = CreateWindow(windowClass.lpszClassName, "Secret Sealing Club: Moon's Reflection", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);

    while(running)
    {
        //Input
        MSG message;
        while(PeekMessage(&message, window, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        //Simulate

        //Render
    }
}