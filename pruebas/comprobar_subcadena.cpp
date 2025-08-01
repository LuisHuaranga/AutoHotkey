#include <iostream>

using namespace std;

int main() {
    
    string text = "LuisoHuaranga";
    cout << "Longitud :" << text.length() << endl;
    
    for (int i = 0; i < text.length(); i++ ){
        cout << text[i] << endl;
    }
    return 0;
}
