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
    
    /*
    void actualizar(){
        if(this->empty()){

            return;
        }

        Nodo* prev=this->prim;
        Nodo* aux= prev->sig;

        while(aux!=nullptr){

            if(prev->elem==aux->elem){

                prev->sig=aux->sig;
                Nodo* repetido =aux;
                aux=aux->sig;
                delete repetido;
            }
            else{

                prev=aux;
                aux=aux->sig;

            }
        }
    }

    */
    

    void merge(linked_list_ed_plus& lista2){



        if(lista2.empty()){
            return;
        }
        if(this->empty()){

            this->prim=lista2.prim;
            this->ult=lista2.ult;

            lista2.prim=nullptr;
            lista2.ult=nullptr;
            return;
        }






        Nodo *aux1=this->prim;
        Nodo *prev;


        Nodo *aux2=lista2.prim;

        if(aux1->elem>aux2->elem){

            this->prim=lista2.prim;

            while(aux2->sig !=nullptr and aux1->elem>aux2->elem){

                prev=aux2;
                aux2=aux2->sig;
            }
        }
        else{

            prev=aux1;
            aux1=aux1->sig;
        }


        while(aux1!=nullptr and aux2!=nullptr){

            if(aux1->elem<=aux2->elem){

                prev->sig=aux1;

                prev=aux1;

                aux1=aux1->sig;

            }

            else{

                prev->sig=aux2;

                prev=aux2;
                aux2=aux2->sig;



            }
        }

        if(aux1==nullptr){

            prev->sig=aux2;
            this->ult=lista2.ult;
        }
        else{

            prev->sig=aux1;
        }

        lista2.prim=nullptr;
        lista2.ult=nullptr;
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