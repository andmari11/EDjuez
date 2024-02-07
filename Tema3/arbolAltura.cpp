#include <iostream>
#include <string>
#include <vector>
#include "bintree_eda.h"

using namespace std;

template <class T>
bool level (bintree <T> const & arbol) {

    if(arbol.empty())   return false;

    //cola para los siguientes nodos
    queue <pair <int, bintree <T>>> cola;
    cola.push({1, arbol});

    pair <int, int> ret={0, 0};


    while(!cola.empty()){

        //siguiente <int, nodo>
        auto const& aux=cola.front();
        //el nodo en sí
        auto const& arbol= aux.second; 

        if(arbol.right().empty() and arbol.left().empty()){
        if(ret.first!=aux.first){

            ret.first=aux.first;
            ret.second=1;
        }
        else{

            ret.second++;
        }
        }
        //se añaden las hojas a la cola
        if (!arbol.left().empty())
            cola.push({aux.first + 1, arbol.left()});
        if (!arbol.right().empty())
            cola.push({aux.first + 1, arbol.right()});

        //pop de la cola (la hoja q acabamos de procesar)
        cola.pop();
    }    


    return ret.second>1;
}




void resuelveCaso(){

    bintree<int> tree = leerArbol(-1);

    if(level(tree))
        cout<<"SI";
    else    
        cout<<"NO";

    

    cout<<"\n";
}

int main() {

    int nCasos;

    cin>>nCasos;

    for(int i=0;i<nCasos;i++)resuelveCaso();
}