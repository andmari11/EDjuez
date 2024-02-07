using namespace std;
#include <iostream>

#include "double_linked_list_ed_h.h"

#ifndef linked_list_plus
#define linked_list_plus


template <typename T >
class double_linked_list_ed_plus : public double_linked_list_ed <T > {
    using Nodo = typename double_linked_list_ed <T >:: Nodo ;   
public: 

    void mostrar() const{

        Nodo* aux=this->fantasma->sig;

        while(aux!=this->fantasma){

            cout<<aux->elem<<" ";
            aux=aux->sig;
        }
        cout << "\n";
    }

    void interseccion(const double_linked_list_ed_plus &other){
        
        Nodo* borrar;
        Nodo* aux1=this->fantasma->sig;
        Nodo* aux2=other.fantasma->sig;
        Nodo* prev=this->fantasma;

        //una de las listas esta vacia
        if(other.empty() or this->empty()){
            
            //se eliminan todos los elementos de this
            while(aux1!=this->fantasma){

                borrar=aux1;
                aux1=aux1->sig;

                delete borrar;
            }
            this->fantasma->sig=this->fantasma;
            this->fantasma->ant=this->fantasma;
            return;
        }

        while(aux1!=this->fantasma and aux2!=other.fantasma){

            if(aux1->elem < aux2->elem){
                //eliminamos todos los elementos no repetidos de this
                while(aux1->elem < aux2->elem and aux1!=this->fantasma){
                    borrar=aux1;
                    aux1=aux1->sig;
                    delete borrar;
                }

                prev->sig=aux1;
                aux1->ant=prev;
            }
            else if(aux1->elem > aux2->elem){
                //other no lo tocamos
                while(aux1->elem > aux2->elem and aux2!=other.fantasma)
                    aux2=aux2->sig;
                
            }
            //elemento repetido
            //no se borra aux1 y aux2 pasa simplemente al siguiente elemento
            else{

                prev->sig=aux1;
                aux1->ant=prev;

                prev=aux1;
                aux1=aux1->sig;
                aux2=aux2->sig;
            }
        }
        
        //se eliminan todos los elementos restantes de this
        if(aux1!=this->fantasma){

            while(aux1!=this->fantasma){

                borrar=aux1;
                aux1=aux1->sig;

                delete borrar;
            }
            this->fantasma->ant=prev;
            prev->sig=this->fantasma;
        }

    }

    

};



#endif