#include <iostream>
#include <string>
#include <vector>
#include "bintree_eda.h"

using namespace std;

template <class T>
vector<int> level (bintree <T> const & arbol) {

    vector <int> ret;
    if(arbol.empty())   return ret;

    //cola para los siguientes nodos
    queue <pair <int, bintree <T>>> cola;
    cola.push({1, arbol});
    pair <int, bintree <T>> derecha=cola.front();


    while(!cola.empty()){

        //siguiente <int, nodo>
        auto const& aux=cola.front();
        //el nodo en sí
        auto const& arbol= aux.second;

        //cosas del ejercicio (condiciones)
        if(derecha.first!=aux.first){

            ret.push_back(derecha.second.root());
        } 
        derecha=aux;  
    

        //se añaden las hojas a la cola
        if (!arbol.left().empty())
            cola.push({aux.first + 1, arbol.left()});
        if (!arbol.right().empty())
            cola.push({aux.first + 1, arbol.right()});

        //pop de la cola (la hoja q acabamos de procesar)
        cola.pop();
    }

    //cosas del ejercicio
    ret.push_back(derecha.second.root());
    
    return ret;
}




void resuelveCaso(){

    bintree<int> tree = leerArbol(-1);

    vector<int> ret=level(tree);

    for(int i=0;i<ret.size();i++){

        cout<<ret[i]<<" ";
    }

    cout<<"\n";
}

int main() {

    int nCasos;

    cin>>nCasos;

    for(int i=0;i<nCasos;i++)resuelveCaso();
}