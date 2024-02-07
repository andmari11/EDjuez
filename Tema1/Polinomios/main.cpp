
#include <iostream>
#include <iomanip>
#include <fstream>

#include "polinomio.h"

using namespace std;


bool resuelveCaso() {
    
    int exp=-1, coef=-1, grado=0;
    polinomio pol = polinomio();

    cin >> coef >> exp;

    if (!std::cin)
        return false;

    while (!(exp == 0 and coef == 0)) {

        pol.addMonomio(coef, exp);

        cin >> coef >> exp;

    } 

    int numCasos, valorX;
    cin >> numCasos;

    for (int i = 0; i < numCasos; i++) {

        cin>>valorX;

        cout << pol.calcularPol(valorX)<<" ";
    }
    cout << endl;

    return true;

}



int main() {


    while (resuelveCaso())
        ;



}