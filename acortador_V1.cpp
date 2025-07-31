#include <Windows.h>
#include <iostream>


HHOOK hKeyboardHook;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0 && wParam == WM_KEYDOWN) {
        KBDLLHOOKSTRUCT* kbStruct = (KBDLLHOOKSTRUCT*)lParam;
        std::cout << "Tecla presionada: " << kbStruct->vkCode << std::endl;
        
        if (kbStruct->vkCode == VK_ESCAPE) {
            PostQuitMessage(0);
        }
    }
    return CallNextHookEx(hKeyboardHook, nCode, wParam, lParam);
}

int main() {

    std::cout << "Hook iniciado (Presiona ESC para salir)\n";

    hKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(hKeyboardHook);
    std::cout << "Hook desactivado\n";
    return 0;
}