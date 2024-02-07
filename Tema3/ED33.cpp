#include <iostream>
#include <string>
using namespace std;
#include "bintree_eda.h"



template <class T >
T menor ( bintree <T > const & arbol ) {

    auto it=arbol.begin();
    auto ret=*it;
    ++it;

    while(it!=arbol.end()){

        if(ret>*it){

            ret=*it;
        }
        ++it;
    }
    return ret;
}

bool resuelveCaso(){
    
    char tipo;
    cin>>tipo;

    if(!cin){

        return false;
    }

    if(tipo=='N'){

        bintree <int> tree=leerArbol(-1);
        cout<<menor(tree)<<"\n";

    }
    else{
        string aux="#";
        bintree <string> tree=leerArbol(aux);

        cout<<menor(tree)<<"\n";
    }

    return true;
}

int main() {

    while(resuelveCaso());
}