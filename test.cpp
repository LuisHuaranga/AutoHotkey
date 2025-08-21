#include <Windows.h>
#include <iostream>
#include <string>
#include <cstdlib> 

using namespace std;

HHOOK hKeyboardHook;
string textoEscrito;
const size_t LIMITWORD = 4;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0 && wParam == WM_KEYDOWN) {
        
        // system("cls");
        
        KBDLLHOOKSTRUCT* kbStruct = (KBDLLHOOKSTRUCT*)lParam;

        // Convertir vkCode a letra usando el teclado actual
        BYTE keyboardState[256];
        GetKeyboardState(keyboardState);

        WCHAR buffer[5];
        DWORD codigoTecla = kbStruct->vkCode;
        UINT scanCode = MapVirtualKey(codigoTecla, MAPVK_VK_TO_VSC);

        int result = ToUnicode(codigoTecla, scanCode, keyboardState, buffer, 4, 0);

        if (result > 0) {
            textoEscrito += (char)buffer[0];

            if (codigoTecla == VK_SPACE || codigoTecla == VK_RETURN || textoEscrito.length() >= LIMITWORD) {
                cout << "Reiniciando buffer"<< endl;
                textoEscrito.clear();
            }
            
            if (codigoTecla == VK_BACK && !textoEscrito.empty()){
                cout << "holi";
                cout << textoEscrito << "\t"<< endl;
                textoEscrito.pop_back();
                cout << textoEscrito << "\t"<< endl;
            }
            
            
            if (codigoTecla == VK_ESCAPE){
                PostQuitMessage(0);
            }
            
            cout << textoEscrito << "\t"<< "Tecla presionada!: " << codigoTecla << endl;

        }
    }
    return CallNextHookEx(hKeyboardHook, nCode, wParam, lParam);
}

int main() {
    cout << "Hook iniciado (Presiona ESC para salir)" << endl;

    hKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(hKeyboardHook);
    cout << "Hook desactivado" << endl;
    return 0;
}
