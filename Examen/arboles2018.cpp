#include <iostream>
#include <string>
#include "bintree_eda.h"


using namespace std;

template<class T>
pair<int, int> caminoPares(const bintree<T>& tree){

    if(tree.empty())return {0, 0};

    pair<int, int> der=caminoPares(tree.right());
    pair<int, int> izq=caminoPares(tree.left());

    int maxRet=max(der.second, izq.second);
    int camino=0;

    if(tree.root()%2==0 ){

        camino=max(izq.first, der.first)+1;
        maxRet=max(izq.first+ der.first+1, maxRet);
    }


    return {camino, maxRet} ;
}



void resuelveCaso(){

    bintree <int> tree=leerArbol(-1);

    std::cout<<caminoPares(tree).second<<"\n";
}



int main(){

    int n;
    cin>>n;

    for(int i=0;i<n;i++)resuelveCaso();
}
