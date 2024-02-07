#include <iostream>
#include <string>
#include "bintree_eda.h"


using namespace std;

//first:ret(num de acumuladores)
//second: suma
template <class T>
pair<int, int> acumuladores (bintree <T> const & arbol) {


    if(arbol.empty())   return {0, 0};
    if(arbol.left().empty() and arbol.right().empty() and arbol.root()==0) return {1, arbol.root()};
    if(arbol.left().empty() and arbol.right().empty())  return {0, arbol.root()};

    pair<int, int> izq, der;

    izq=acumuladores(arbol.left());
    der=acumuladores(arbol.right());



    return {izq.first+der.first+(izq.second+der.second==arbol.root()), izq.second+der.second+arbol.root()};
}




void resuelveCaso(){

    bintree<int> tree= leerArbol(-1);


    cout<< acumuladores(tree).first <<"\n";
}






int main() {

    int nCasos;

    cin>>nCasos;

    for(int i=0;i<nCasos;i++)resuelveCaso();
}