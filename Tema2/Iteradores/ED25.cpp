#include <iostream>
#include <list>

using namespace std;


bool resuelveCaso(){

    int n;
    cin>>n;

    if(n==0){

        return false;
    }

    list<string> lista;
    for(int i=0;i<n;i++){

        string aux;
        cin>>aux;
        lista.push_back(aux);
    }

    auto it=lista.begin();
    bool eliminar=false;
    while(it!=lista.end()){

        if(eliminar){

            it=lista.erase(it);
            eliminar=false;
        }
        else{

            it++;
            eliminar=true;
        }
    }


    auto it1=lista.begin();
    for(int i=0;i<lista.size();i++){

        cout<<*it1<<" ";
        it1++;
    }
    cout<<"\n";


    return true;
}

int main(){

    while(resuelveCaso());
}
