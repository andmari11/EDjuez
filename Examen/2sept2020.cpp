#include <iostream>
#include <string>
#include "bintree_eda.h"

using namespace std;


template <class T>
//camino, max
pair <int, int> camino(bintree <T> const &tree){

    if(tree.empty()) return {0, 0};

    pair <int, int> izq=camino(tree.left());
    pair <int, int> der=camino(tree.right());

    int maxRet=max(izq.first+der.first+tree.root(), max(izq.second, der.second));
    int camino=max(izq.first, der.first)+tree.root();

    return {camino, maxRet};
}

void resuelveCaso(){

    bintree<int> tree=leerArbol(-1);
    cout<<camino(tree).second<<endl;
}

int main(){
    int ncasos;
    cin>>ncasos;

    for(;ncasos>0;ncasos--)resuelveCaso();
}