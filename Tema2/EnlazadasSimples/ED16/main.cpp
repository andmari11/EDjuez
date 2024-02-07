
#include "linked_list_ed_plus.h"

using namespace std;


bool resuelveCaso(){

    int aux;

    cin>>aux;

    if(aux==-1){

        return false;
    }

    int n;
    linked_list_ed_plus <int> lista1;

    for(int i=0;i<aux;i++){

        cin>>n;
        lista1.push_back(n);
    }


    linked_list_ed_plus <int> lista2;


    for(int i=0;i<aux;i++){

        cin>>n;
        lista2.push_back(n);
    }

    lista1.sumar(lista2);
    lista1.mostrar();



    return true;
}

int main(){

    while(resuelveCaso());
    
}