#include <iostream>

#include "linked_list_ed_plus.h"



bool resolver(){

    int aux;

    cin>>aux;

    if(aux==-1){

        return false;
    }

    linked_list_ed_plus <char> lista; 
    char letra;

    for(int i=0;i<aux;i++){

        cin>>letra;
        lista.push_back(letra);
    }
    
    lista.actualizar();
    lista.mostrar();
    
    return true;
}

int main(){

    while(resolver());
}