
#include "linked_list_ed_plus.h"

using namespace std;


bool resuelveCaso(){

    int aux;

    cin>>aux;

    linked_list_ed_plus <int> lista1;

    while(aux!=0){

        lista1.push_back(aux);
        cin>>aux;
    }

    cin>>aux;

    linked_list_ed_plus <int> lista2;

    while(aux!=0){

        lista2.push_back(aux);
        cin>>aux;
    }

    lista1.merge(lista2);
    lista1.mostrar();



    return true;
}

int main(){

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        resuelveCaso();
    
}