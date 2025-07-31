#include <iostream>
#include <string>
#include <map>


using namespace std;

// Diccionario de abreviaturas
map<string, string> abreviaturas = {
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
    
    string textoAbreviado = "salo";
    string textoCompleto;

    try {
        textoCompleto = abreviaturas.at(textoAbreviado); 
        cout << "El texto completo es: " << textoCompleto << endl;
    } catch(const out_of_range& e) {
        cout << "Elemento no encontrado\n";
    }
    
    if (abreviaturas.find(textoAbreviado) == abreviaturas.end()) {
        cout << textoAbreviado << " NO EXISTE!!" << endl;
    }   
    
    return 0;
}
