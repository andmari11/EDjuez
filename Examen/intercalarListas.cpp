#include <iostream>
#include <string>
#include "deque_extended.h"

using namespace std;


bool resuelveCaso(){

    int nElementos1;
    cin>>nElementos1;

    if(!cin)return false;

    int aux;
    deque_ed_extended <int> lista1;
    deque_ed_extended <int> lista2;


    for(int i=0;i<nElementos1;i++){
        cin>>aux;
        lista1.push_back(aux);
    }

    int nElementos2;
    cin>>nElementos2;

    for(int i=0;i<nElementos2;i++){
        cin>>aux;
        lista2.push_back(aux);
    }

    
    lista1.entremezclar(lista2);
    lista1.mostrar();
    
    return true;
}

int main(){

    int ncasos;
    std::cin>>ncasos;
    for(int i=0;i<ncasos;i++){

        resuelveCaso();
    }
}
