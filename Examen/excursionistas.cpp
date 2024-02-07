#include <string>
#include <iostream>
#include "bintree_eda.h"
using namespace std;

using maximoExcursionistas=int;
using nRutas=int;

template<class T>
pair<nRutas, maximoExcursionistas> excursionistas(const bintree<T>& tree){

    if(tree.empty())return{0, 0};


    pair<nRutas, maximoExcursionistas> izq=excursionistas(tree.left());
    pair<nRutas, maximoExcursionistas> der=excursionistas(tree.right());

    maximoExcursionistas retMax=max(der.second, izq.second)+tree.root();
    int aux=(tree.root()!=0);
    nRutas retRutas=max(izq.first+der.first, aux);


    return {retRutas, retMax};
}

void resuelveCaso(){

    bintree<int> tree=leerArbol(-1);
    pair<int, int> ret=excursionistas(tree);

    std::cout<<ret.first<<" "<<ret.second<<endl;
}

int main(){

    int nCasos;
    cin>>nCasos;

    for(int i=0;i<nCasos; i++)resuelveCaso();


}
