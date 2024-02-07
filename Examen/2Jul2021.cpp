#include "bintree_eda.h"

using namespace std;


template <class T>
pair<bool, int> bienCodificado(bintree <T > const & tree){

    if(tree.empty())    return {true, 0};

    pair <bool, int> izq=bienCodificado(tree.left());
    pair <bool, int> der=bienCodificado(tree.right());


    bool ret1=der.first and izq.first and abs(izq.second-der.second)<=1;
    int ret2=der.second+izq.second;
    if(tree.root()==0){
        ret2++;
    }

    return{ret1, ret2};
}

void resuelveCaso(){

    bintree <int> tree= leerArbol(-1);
    pair<bool, int> sol=bienCodificado(tree);
    if(sol.first)
        cout<<"SI\n";
    else
        cout<<"NO\n";
}




int main(){

    int nCasos;

    cin>>nCasos;

    for(int i=0;i<nCasos;i++)
        resuelveCaso();
}