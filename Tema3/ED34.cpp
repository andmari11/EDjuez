#include <iostream>
#include <string>
#include "bintree_eda.h"

using namespace std;

struct tSol{
    int max=0;
    int actual=0;
};

template <class T >
tSol maxDiametro ( bintree <T > const & arbol ) {

    if(arbol.empty())   return {0, 0};

    tSol dcha=maxDiametro(arbol.right());
    tSol izq= maxDiametro(arbol.left());



    return {1+max(dcha.max, izq.max),max(max(izq.actual, dcha.actual) , 1 + izq.max + dcha.max )};
}


void resuelveCaso(){

    bintree <char> tree=leerArbol('.');

    cout<<maxDiametro(tree).actual<<"\n";

}

int main() {

    int nCasos;

    cin>>nCasos;

    for(int i=0;i<nCasos;i++)resuelveCaso();
}