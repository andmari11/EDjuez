#include <iostream>
#include <string>
#include "bintree_eda.h"


using namespace std;

template <class T>
pair<int, int> binario(bintree<T> const &arbol)
{

    if (arbol.empty())
        return {-1, -1};

    pair<int, int> izq = binario(arbol.left());

    pair<int, int> der = binario(arbol.right());

    if (izq.first == -2 or der.first == -2)
    {

        return {-2, -2};
    }

    int min = arbol.root(), max = arbol.root();

    if (izq.first != -1)
    {
        min = izq.first;
    }
    if (der.second != -1)
    {
        max = der.second;
    }

    if ((izq.first == -1 or izq.second < arbol.root()) and (der.first == -1 or der.first > arbol.root()))
        return {min, max};

    return {-2, -2};
}

void resuelveCaso(){

    bintree<int> tree= leerArbol(-1);
    if(binario(tree).first!=-2){
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