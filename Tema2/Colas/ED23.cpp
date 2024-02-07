#include <deque>
#include <iostream>
#include <string>
#include <stack>


using namespace std;


void resolver( deque<int> &cola, const int k, const int n){





}
bool resuelveCaso(){

    int n, k;
    cin>>n>>k;

    if(n+k==0){

        return false;
    }

    deque <int> cola;
    deque <int> mayores;

    int aux;
    for(int i=0;i<k;i++){
        cin>>aux;
        cola.push_back(aux);

        while(!mayores.empty() and mayores.back()<aux){

            mayores.pop_back();
        }
        mayores.push_back(aux);
    }

    for(int i=k;i<n;i++){
        
        cout<<mayores.front()<<" ";

        cin>>aux;
        cola.push_back(aux);


            if(cola.front()==mayores.front()){

                mayores.pop_front();
            }
            cola.pop_front();
        
        while(!mayores.empty() and mayores.back()<aux){

            mayores.pop_back();
        }
        mayores.push_back(aux);
    }
    cout<< mayores.front()<<"\n";
    return true;
}



int main(){

    while(resuelveCaso());
}