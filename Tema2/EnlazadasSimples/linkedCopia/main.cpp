#include <iostream>

#include "linked_list_ed_plus.h"



bool resolver(){

    int aux;

    cin>>aux;

    if(!cin){

        return false;
    }
    linked_list_ed_plus <int> lista;   
    while(aux!=0){

        lista.push_back(aux);
        cin>>aux;
    }

    lista.invertir();
    lista.mostrar();
    
    return true;
}

int main(){

    while(resolver());
}