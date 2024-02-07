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
    void actualizar(){
        if(this->empty()){

            return;
        }

        Nodo* prev=this->prim;
        Nodo* aux= prev->sig;

        while(aux!=nullptr){

            if(prev->elem==aux->elem){

                prev->sig=aux->sig;
                Nodo* eliminar =aux;
                aux=aux->sig;
                delete eliminar;
            }
            else{

                prev=aux;
                aux=aux->sig;

            }
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