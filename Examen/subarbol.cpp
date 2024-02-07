#include <iostream>
#include <string>
#include "bintree_eda.h"

using namespace std;

template <class T>
//actual, max
pair<int, int> altura(const bintree<T>& tree){

    if(tree.empty())    return {0, 0};


    pair<int, int> ret={0, 0};
    pair<int, int> izq= altura(tree.left());
    pair<int, int> der= altura(tree.right());


    if(izq.first==der.first and !tree.left().empty() and !tree.right().empty()){

        ret.first=izq.first+1;
    }
    else{

        ret.first=max(izq.first, der.first);
    }



    ret.second=max(ret.first,max( izq.first, der.first));

    return ret;

}


void resuelveCaso(){

    bintree <char> tree= leerArbol('.');

    cout<<altura(tree).second<<endl;
}

int main(){

    int ncasos;
    cin>>ncasos;

    for(;ncasos>0;ncasos--){

        resuelveCaso();
    }
}