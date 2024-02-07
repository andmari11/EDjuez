
#include "linked_list_ed_plus.h"

using namespace std;


bool resuelveCaso(){

    int n;

    cin>>n;

    if(n==-1) return false;

    linked_list_ed_plus <int> lista1;
    
    int aux;

    for(int i=0;i<n;i++){
        
        cin>>aux;
        lista1.push_back(aux);
    }


    linked_list_ed_plus <int> lista2;

    lista1.positivosNegativos(lista2);
    lista1.mostrar();
    lista2.mostrar();



    return true;
}

int main(){

    while(resuelveCaso());
    
}