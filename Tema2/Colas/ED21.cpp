
// Programa para probar la implementación de una cola

#include <iostream> 
#include <fstream> 
#include "queue_eda.h"

bool resuelveCaso() {
    std::string str;
    getline(std::cin, str);
    if (str == ".") return false;
    // lee los datos de entrada en la cola
    queue<char> cola;
    for (int i = 0; i < str.length(); ++i) {
        cola.push(str[i]);
    }

    // Duplica los elementos de la cola
    int numElem = (int)cola.size();

    // Muestra los elementos de la cola y la deshace
    numElem = (int)cola.size();
    for (int i = 0; i < numElem; i ++) {
        std::cout << cola.front();
        cola.pop();
    }
    if (!cola.empty()) std::cout << "ERROR\n";
    std::cout << '\n';
    return true;
}


int main() {

    while (resuelveCaso()) ;

}
