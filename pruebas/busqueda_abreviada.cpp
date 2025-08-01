#include <iostream>
#include <string>
#include <map>


using std::string;
using std::cout;
using std::endl;
using std::size_t;
using std::map;


// Diccionario de abreviaturas
map<string, string> abbreviations = {
    {"sal", "saludos"},
    {"gra", "gracias"},
    {"porf", "por favor"},
    {"msj", "mensaje"},
    {"asap", "as soon as possible"},
    {"brb", "be right back"},
    {"np", "no problem"},
    {"ty", "thank you"},
    {"pls", "please"},
    {"btw", "by the way"}
};

int main() {
    
    string abbreviated = "21838374";

    for (size_t i = 0; i < abbreviated.length(); i++ ){
        string subtext = abbreviated.substr(i);

        if (abbreviations.find(subtext) != abbreviations.end()) {
            string fullText = abbreviations.at(subtext);         
            cout << abbreviated << ": "<< fullText << endl;
            break;
        }                  
    }

    return 0;
}
