#include <iostream>
#include <string>
#include "bintree_eda.h"

using namespace std;

template <class T>
void mostrar(bintree <T> const& arbol) {
    if (arbol.empty()) {
        return;
    }
    cout << arbol.root() << " ";
    mostrar(arbol.left());
    mostrar(arbol.right());
}

template <class T>
bintree <T> acumular (bintree <T> const& arbol) {

    if(arbol.empty())   return {};
    if(arbol.left().empty() and arbol.right().empty()) return arbol.root();

    int suma=0;

    auto izq=acumular(arbol.left());
    auto der=acumular(arbol.right());

    if(!izq.empty()){

        suma+=izq.root();
    }
    if(!der.empty()){

        suma+=der.root();
    }


    return {izq, suma, der};
}


void resuelveCaso(){

    bintree<int> tree = leerArbol(-1);
    bintree<int> ret=acumular(tree);

    mostrar(ret);
    
    cout<<"\n";
}

int main() {

    int nCasos;

    cin>>nCasos;

    for(int i=0;i<nCasos;i++)resuelveCaso();
}