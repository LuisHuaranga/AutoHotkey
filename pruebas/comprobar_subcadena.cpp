#include <iostream>

using namespace std;

int main() {
    
    string text = "012345prog";
    cout << "Longitud :" << text.length() << endl;
    
    for (int i = 0; i < text.length(); i++ ){
        string sub = text.substr(i);
        cout << sub << endl;
    }
    return 0;
}
