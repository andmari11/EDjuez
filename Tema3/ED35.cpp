#include <iostream>
#include <string>
#include "bintree_eda.h"

using namespace std;

struct tSol{
    int maximo=0;
    int equipos=0;
};

template <class T >
tSol excursionistas ( bintree <T > const & arbol ) {

    if(arbol.empty())   return {0, 0};

    tSol dcha=excursionistas(arbol.right());
    tSol izq= excursionistas(arbol.left());

    int maximo=arbol.root()+max(dcha.maximo, izq.maximo);
    int equipos=dcha.equipos+izq.equipos;

    if(equipos==0 and arbol.root()!=0){

        equipos=1;
    }

    //0equipos antes=> si !=0 ++
    //1 equipo => si != igual
    //2 equipos => igual


    return {maximo, equipos};
}


void resuelveCaso(){

    bintree <int> tree=leerArbol(-1);

    cout<<excursionistas(tree).equipos<<" "<<excursionistas(tree).maximo<<"\n";

}

int main() {

    int nCasos;

    cin>>nCasos;

    for(int i=0;i<nCasos;i++)resuelveCaso();
}