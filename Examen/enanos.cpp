#include <iostream>
#include "bintree_eda.h"
using namespace std;

template <class T> 
pair<string, int> enanos(bintree<T> const & tree){

    if(tree.empty())    return{"", 0};

    pair<string, int>ret;
    pair<string, int>izq=enanos(tree.left());
    pair<string, int>der=enanos(tree.right());

    ret.second=izq.second+der.second;

    if(izq.second>der.second){

ret.first=izq.first;
    }
    else if(izq.second<der.second){
ret.first=der.first;
    }
    else{
        if(izq.first!="" and der.first!="")
            ret.first=min(izq.first, der.first);
        else
            ret.first=max(izq.first, der.first);
    }


    if(tree.root()=="Orcos"){

        ret.second/=2;

        if(ret.second==0){

            ret.first="";
        }
    }
    else if(tree.root()!="-"){

        ret={tree.root(), 1};
    }
    
    return ret; 
}

void resuelveCaso(){

    string a=".";
    bintree<string> tree =leerArbol(a);
    pair<string, int>ret=enanos(tree);

    if(ret.first!="")
    std::cout<<ret.first<<" "<<ret.second<<"\n";
    else
    std::cout<<"Ninguno\n";
}

int main(){


    int n;
    std::cin>>n;

        for(;n>0;n--)resuelveCaso();
}