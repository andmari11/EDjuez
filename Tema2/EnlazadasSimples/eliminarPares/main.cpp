#include <iostream>
#include "horas.h"
#include "linked_list_ed_plus.h"
using namespace std;


bool resolver(){

    int num;
    cin>>num;

    if(num==0){

        return false;
    }

    Hora hora;
    linked_list_ed_plus <Hora> lista;   


    for(int i=0;i<num; i++){

        cin>>hora;
        lista.push_back(hora);
    }

    lista.eliminaPares();
    lista.mostrar();

    return true;
}




int main(){

    while(resolver());
}