#include <iostream>
#include <string>
#include <cmath>
#include "bintree_eda.h"

using namespace std;

bool esPrimo(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

template <class T>
pair<int, int> camino (bintree <T> const & arbol) {

    if(arbol.empty())   return {0, -1};
    if(arbol.root()%7==0 and arbol.root()!=7)  return {arbol.root(), 1 };
    if(esPrimo(arbol.root()))   return {0, -1};

    //cola para los siguientes nodos
    queue <pair <int, bintree <T>>> cola;
    cola.push({1, arbol});

    while(!cola.empty()){

        auto const& aux=cola.front();
        auto const& arbol= aux.second;

        if(arbol.root()%7==0 and arbol.root()!=7){

            return {arbol.root(), aux.first};
        }
        if (!esPrimo(arbol.root())){

            if (!arbol.left().empty())
                cola.push({aux.first + 1, arbol.left()});
            if (!arbol.right().empty())
                cola.push({aux.first + 1, arbol.right()});
        }
        cola.pop();
    }

    return {0, -1};
}




void resuelveCaso(){

    pair<int, int> ret;

    bintree<int> tree = leerArbol(-1);
    ret = camino(tree);

    if(ret.second>=0){

        cout<<ret.first << " "<<ret.second;
    }
    else {

        cout<<"NO HAY";
    }
    cout<<"\n";
}

int main() {

    int nCasos;

    cin>>nCasos;

    for(int i=0;i<nCasos;i++)resuelveCaso();
}