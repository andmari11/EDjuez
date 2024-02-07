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
    

    void positivosNegativos(linked_list_ed_plus& lista2){

        Nodo* prev1;
        Nodo* aux1=this->prim;
        Nodo* prev2;

        while(aux1!=nullptr){

            if(aux1->elem==0){

                Nodo* eliminar=aux1;

                //lo quitamos de la lista1
                if(aux1!=this->prim) prev1->sig=aux1->sig;
                else this->prim=aux1->sig;

                aux1=aux1->sig;


                delete eliminar;
            }

            else if(aux1->elem<0){
                
                //lo quitamos de la lista1
                if(aux1!=this->prim) prev1->sig=aux1->sig;
                else this->prim=aux1->sig;

                //lo enganchamos por detras en la lista2
                if(!lista2.empty()) prev2->sig=aux1;
                else lista2.prim=aux1;

                //ahora es el ultimo de la lista2
                prev2=aux1;
                aux1=aux1->sig;



            }
            else{

                prev1=aux1;
                aux1=aux1->sig;

            }


        }


        this->ult=prev1;

        if(!lista2.empty()){
            
            prev2->sig=nullptr;
            lista2.ult=prev2;
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