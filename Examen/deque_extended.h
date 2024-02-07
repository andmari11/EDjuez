
using namespace std;

#ifndef deque_extended
#define deque_extended

#include "deque.h"

template <class T>
class deque_ed_extended : public double_linked_list_ed<T>{
    using Nodo=typename double_linked_list_ed<int>::Nodo;

public:

    void entremezclar( deque_ed_extended& other){

        if(this->empty() or other.empty())return;

        Nodo* aux1=this->fantasma->sig;
        
        Nodo* aux2=other.fantasma->sig;
        Nodo* sig2=aux2->sig;


        while(aux1!=this->fantasma and aux2!=other.fantasma){

            aux2->sig->ant=aux2->ant;
            aux2->ant->sig=aux2->sig;

            aux2->sig=aux1->sig;
            aux1->sig->ant=aux2;
            aux1->sig=aux2;
            aux2->ant=aux1;


            aux2=sig2;
            sig2=aux2->sig;
            aux1=aux1->sig->sig;            
        }

        if(aux2!=other.fantasma){


            aux1->ant->sig=aux2;
            aux2->ant=aux1->ant;

            other.fantasma->ant->sig=this->fantasma;
            this->fantasma->ant=other.fantasma->ant;


            other.fantasma->sig=other.fantasma;
            other.fantasma->ant=other.fantasma;


        }
    }
    void mostrar()const {
        Nodo *aux=this->fantasma->sig;

        while(aux!=this->fantasma){
            cout<<aux->elem<<" ";
            aux=aux->sig;
        }
        cout<<"\n";
    }

};

#endif