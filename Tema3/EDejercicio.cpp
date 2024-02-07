#include <iostream>
#include <string>
#include <queue>
#include "bintree_eda.h"

using namespace std;

template <class T>
int level (bintree<T> const  & t, auto n){

    queue <pair <int, bintree <T> > > cola;
    cola.push(1, t.root());
    int nivel=1;
    int ret=0;

    while(!cola.empty() and ret<2;){

        auto const& aux=cola.front();
        auto const& arbol=aux.second;

        if(aux.first!=nivel){

            ret=0;
        }

        if(arbol.root()==n){

            ret++;
        }

        if(!arbol.left().empty()){

            cola.push({aux.first+1, arbol.left()});
        }

        cola.pop();
    }

    return aux.;
}