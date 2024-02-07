#include <iostream>
#include <string>
#include "bintree_eda.h"

using namespace std;

struct tSol{

    bool listaRetret=true;
    int nodos=0;
};

template <class T >
tSol zurdo ( bintree <T > const & arbol ) {

    //arbol vacio es zurdo y tiene 0 nodos
    if(arbol.empty()){
        return{true, 0};
    }
    else{

        tSol izquierda= zurdo(arbol.left());
        tSol derecha= zurdo(arbol.right());

        //si uno de los hijos no es zurdo el arbol no es zurdo
        if(!izquierda.ret or !derecha.ret){

            return {false, 0};
        }

        //si la izquierda tiene mas nodos o ambos tienen cero es zurdo
        //y devuelve el numero total de nodos del arbol contando con el nodo "raiz"
        return {izquierda.nodos>derecha.nodos or izquierda.nodos+derecha.nodos==0, 1+derecha.nodos+izquierda.nodos};
    }
}


void resuelveCaso(){

    bintree <char> tree=leerArbol('.');

    if(zurdo(tree).ret){
        cout<<"SI";
    }
    else{
        cout<<"NO";
    }
    cout<<"\n";

}

int main() {

    int nCasos;

    cin>>nCasos;

    for(int i=0;i<nCasos;i++)resuelveCaso();
}