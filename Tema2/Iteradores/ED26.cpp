#include <iostream>
#include <list>

using namespace std;

template <class T >
void mostrar(T& it, const T& end){

    if(it==end){
        return;
    }

    int aux=*it;
    ++it;
    mostrar(it, end);

    cout<<aux<<" ";
}

bool resuelveCaso(){
    
    int aux;
    list<int> lista;
    cin>>aux;
    while(aux!=0){
        lista.push_back(aux);
        cin>>aux;
    }



    auto it1=lista.begin();
    mostrar(it1, lista.end());
    cout<<"\n";


    return true;
}

int main(){
    int nCasos;
    cin>>nCasos;
    for(int i=0;i<nCasos;i++){
        
        resuelveCaso();
    }
}
