#include <stack>
#include <iostream>
#include <string>


using namespace std;

bool comparar(const char a, const char b){

    bool ret=false;

    if(a=='(' and b==')'){

        ret=true;
    }
    else if(a=='{' and b=='}'){

        ret=true;
    }
    else if(a=='[' and b==']'){

        ret=true;
    }

    return ret;
}

bool resolver(const string& texto){

    int i=0;
    bool ret=true;


    stack <char> pila;

    while(ret and i<texto.length()){

        char aux=texto[i];

        if(texto[i]=='[' or texto[i]=='{' or texto[i]=='('){

            pila.push(texto[i]);
        }
        else if(texto[i]==']' or texto[i]=='}' or texto[i]==')'){

            ret=!pila.empty() and comparar(pila.top(),texto[i] );

            if(ret){

                pila.pop();
            }
        }

        i++;
    }

    return ret and pila.empty();
}




bool resuelveCaso(){

    string texto;

    getline(cin,texto);

    if(!cin){

        return false;
    }

    if(resolver(texto)){

        cout<<"SI \n";
    }
    else{

        cout<<"NO \n";
    }

    return true;
}


int main(){

    while(resuelveCaso());
}