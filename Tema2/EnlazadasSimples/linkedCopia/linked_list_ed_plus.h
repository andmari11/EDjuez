#include <iostream>
#include <sstream>
#include <string>

using namespace std;


#ifndef linked_list_plus
#define linked_list_plus

#include "linked_list_ed.h"


template <typename T >
class linked_list_ed_plus : public linked_list_ed <T > {
    using Nodo = typename linked_list_ed <T >:: Nodo ;

public:

    void copia (){

        Nodo *aux=this->prim;
        Nodo *copia;
        while(aux!=nullptr){

            copia= new Nodo(aux->elem, aux->sig);
            aux->sig=copia;
            aux=copia->sig;
        }


    }

void invertir (){

        Nodo *aux=this->prim;
        Nodo *prev=nullptr;
        Nodo *siguiente;
        this->ult=aux;

        while(aux!=nullptr){

            siguiente=aux->sig;
            aux->sig=prev;
            prev=aux;
            aux=siguiente;
        }

        this->prim=prev;
}

    void mostrar()const {
        Nodo *aux=this->prim;

        while(aux!=nullptr){

            cout<<aux->elem<<" ";
            aux=aux->sig;
        }
        cout<<"\n";
    }
};

#endif