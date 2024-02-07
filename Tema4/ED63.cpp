#include <iostream>
#include <string>

#include "header.h"

using namespace std;




bool resuelveCaso() {

	string instruccion;
	cin >> instruccion;

	int x, y;
	string nombre;
	string dir;
	torres torre;


	if (!cin) {

		return false;
	}

	while (instruccion != "FIN") {
        try{

		if (instruccion == "anyadir_torre") {
			cin >> nombre >> x >> y;

			torre.anyadir_torre(nombre, x, y);

		}
		else if (instruccion == "torre_en_posicion") {
			cin >> x >> y;
            pair<bool, string> s = torre.torre_en_posicion(x, y);
            if (s.first)
                cout << "SI " << s.second << endl;
            else
                cout << "NO" << endl;
        }
		else if (instruccion == "torre_mas_cercana") {
			cin >> nombre >> dir;

			//torre.torre_mas_cercana(nombre, dir);
		}
		else if (instruccion == "posicion") {
            cin>>nombre;
            pair<int, int> s = torre.posicion(nombre);
            cout << s.first << " " << s.second << endl;
        }

        else if (instruccion == "eliminar_torre") {
			cin >> nombre;
			torre.eliminar_torre(nombre);
		}
    }
        catch(domain_error e){

            cout<<e.what()<<endl;
        }
		cin >> instruccion;


	}

	return true;
}




int main() {

	while (resuelveCaso());
}