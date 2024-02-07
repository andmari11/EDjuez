#include <iostream>
#include <string>
using namespace std;
#include "bintree_eda.h"

struct tSol{

    int nodos=0, hojas=0, altura=0;
};

template <class T >
tSol analisisArbol ( bintree <T > const & arbol ) {

    if(arbol.empty()){
        return {0, 0, 0};
    }

    tSol izquierda=analisisArbol(arbol.left());
    tSol derecha= analisisArbol(arbol.right());

    int hojas=arbol.left().empty() and arbol.right().empty();


    return {izquierda.nodos+derecha.nodos+1 ,hojas+ izquierda.hojas+derecha.hojas, 1+max(izquierda.altura, derecha.altura)};
}

void resuelveCaso(){

    bintree <char> tree=leerArbol('.');

    tSol ret= analisisArbol(tree);

    cout <<ret.nodos << " " << ret.hojas<<" "<<ret.altura<<"\n";

}

int main() {

    int nCasos;

    cin>>nCasos;

    for(int i=0;i<nCasos;i++)resuelveCaso();
}