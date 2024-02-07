#include <iostream>
#include <string>
#include "bintree_eda.h"


using namespace std;


//1st ret (num de tramos), 2nd caudal 
template <class T>
pair<int, int> navegable(bintree<T> const &t, bool primer=false){

    if(t.empty())   return {0, 0};

    if(t.left().empty() and t.right().empty())    return{0, 1};

    auto izq=navegable(t.left(), false);
    auto der=navegable(t.right(), false);

    int caudal= max(0,der.second+izq.second-t.root());
    int ret=der.first+izq.first+(caudal>=3 and !primer); 

    return{ret, caudal};
}

void resuelveCaso(){

    bintree<int> tree= leerArbol(-1);

    cout<<navegable(tree, true).first;

    cout<<"\n";
}






int main() {

    int nCasos;

    cin>>nCasos;

    for(int i=0;i<nCasos;i++)resuelveCaso();
}