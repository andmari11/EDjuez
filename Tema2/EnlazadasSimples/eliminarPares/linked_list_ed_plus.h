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

    void eliminaPares (){

        Nodo *aux=this->prim;
        Nodo *anterior;
        int contador=1;

        while(aux!=nullptr){

            if(contador%2==0){

                anterior->sig=aux->sig;
                delete aux;
            }

            contador++;
            anterior=aux;
            aux=aux->sig;
        }


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