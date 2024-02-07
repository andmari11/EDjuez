#include <deque>
#include <iostream>
#include <string>
#include <stack>


using namespace std;

bool vocal(const char a){

    return(a=='a' or a=='e' or a=='i' or a=='o' or a=='u');
}

void pila(string& ret, stack<char> &consonantes){

    while(!consonantes.empty()){

        ret.push_back(consonantes.top());
        consonantes.pop();
    }
}
void resolver(string frase){

    deque <char> cola1;
    deque <char> cola2;
    bool inicio=true;

    for(int i=0;i<frase.size();i++){

        if(inicio){

            cola1.push_back(frase[i]);
        }
        else{

            cola2.push_front(frase[i]);
        } 
        inicio^=true;
    }

    while(!cola2.empty()){
        cola1.push_back(cola2.front());
        cola2.pop_front();
    }

    string ret;
    stack <char> consonantes; 

       while (!cola1.empty()) {
        if (vocal(tolower(cola1.front()))) {
            pila(ret, consonantes);
            ret.push_back(cola1.front());
        }
        else consonantes.push(cola1.front());
        cola1.pop_front();
    }

    pila(ret, consonantes);

    cout<<ret<<"\n";

}









bool resuelveCaso(){

    string frase;

    getline(cin, frase);

    if(!cin){

        return false;
    }

    resolver(frase);

    return true;
}

int main(){

    while(resuelveCaso());
}