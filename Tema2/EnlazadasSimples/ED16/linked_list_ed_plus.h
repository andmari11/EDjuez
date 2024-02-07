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
    
    void sumar(linked_list_ed_plus& lista2){

        Nodo* aux1=this->prim;
        Nodo* aux2=lista2.prim;
        Nodo* prev;

        
        while(aux1!=nullptr){

            this->ult=aux1;
            aux1->elem+=aux2->elem;

            if(aux1->elem==0){


                Nodo* borrar=aux1;
                

                if(aux1==this->prim){

                    this->prim=aux1->sig;
                }
                else{

                    prev->sig=aux1->sig;
                }
                
                aux1=aux1->sig;
                delete borrar;
            }
            else{

                prev=aux1;
                aux1=aux1->sig;
            }

            aux2=aux2->sig;

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