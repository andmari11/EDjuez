#include "pelicula.h"
#include <algorithm>


using namespace std;


bool resuelveCaso(){

    int numPelis;
    cin>>numPelis;

    if(numPelis==0){
        return false;
    }

    vector <pelicula> listaPelis;

    for(int i=0; i<numPelis;i++){

        tHora ini, duracion;
        string name;

        ini.read(cin);
        duracion.read(cin);
        getline(cin, name);


        listaPelis.push_back(pelicula(ini, duracion, name));
    }

    sort(listaPelis.begin(), listaPelis.end());

    for(int i=0; i<numPelis;i++){
    
        cout<<listaPelis[i].getFin()<< listaPelis[i].getName()<< "\n";
    
    }
    cout<<"---"<<"\n";

    return true;
}



int main(){


   while (resuelveCaso());


}