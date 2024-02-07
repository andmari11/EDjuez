#include <iostream>
#include <string>
#include "bintree_eda.h"

using namespace std;

template <class T, class N>
pair<bool, int> level (bintree <T> const & arbol , N const& n) {

    if(arbol.empty())   return {false, {}};
    if(arbol.left().empty() and arbol.right().empty())  return {arbol.root()==n, 1 };

    //cola para los siguientes nodos
    queue <pair <int, bintree <T>>> cola;
    int nivel=0;
    cola.push({1, arbol});
    bool encontrado=false;

    while(!cola.empty() and !encontrado){

        auto const& aux=cola.front();
        auto const& arbol= aux.second;

        if(arbol.root()==n){

            //miro a ver si se ha encontrado un q cumpla ==n anteriormente
            if(nivel!=aux.first){
                nivel=aux.first;
            }
            else{

                encontrado=true;
                nivel=aux.first;
            }
        }

        if (!arbol.left().empty())
            cola.push({aux.first + 1, arbol.left()});
        if (!arbol.right().empty())
            cola.push({aux.first + 1, arbol.right()});

        cola.pop();
    }

    return {encontrado, nivel};
}




void resuelveCaso(){

    char tipo;
    cin>>tipo;

    pair <bool, int> ret;
    if(tipo=='N'){
        int n;
        cin>>n;
        bintree <int> tree=leerArbol(-1);
        ret=level(tree, n);
    }
    else{
        char n;
        cin>>n;
        bintree <char> tree=leerArbol('.');
        ret=level(tree, n);

    }
    if(ret.first){

        cout<<ret.second;
    }
    else {

        cout<<"NO EXISTE";
    }
    cout<<"\n";
}

int main() {

    int nCasos;

    cin>>nCasos;

    for(int i=0;i<nCasos;i++)resuelveCaso();
}