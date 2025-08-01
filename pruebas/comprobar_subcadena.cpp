#include <iostream>
#include <string>

// Solo importar lo que necesitas específicamente
using std::string;
using std::cout;
using std::endl;
using std::size_t;


int main() {
    
    string text = "012345prog";
    cout << "Longitud :" << text.length() << endl;
    
    for (size_t i = 0; i < text.length(); i++ ){
        string sub = text.substr(i);
        cout << sub << endl;
    }
    
    return 0;
}
