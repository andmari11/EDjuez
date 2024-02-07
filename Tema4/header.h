
#ifndef header_h
#define header_h
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;


class torres {
private:

	unordered_map <string, pair <int, int>> info;
	unordered_map <int, map<int, string>> direccionX;
	unordered_map <int, map<int, string>> direccionY;


	pair<int, int> moverDir(string dir, const pair <int, int> coordernadas) {

		pair<int, int> ret = coordernadas;

		if (dir == "Norte") {

			ret.second++;
		}
		else if (dir == "Sur") {

			ret.second--;
		}
		else if (dir == "Este") {

			ret.first++;
		}
		else if (dir == "Oeste") {

			ret.first--;
		}
		return ret;
	}


public:
	enum class Direccion { Norte, Sur, Este, Oeste };

	void anyadir_torre(const string& nombre, int x, int y) {

		if (info.count(nombre)) {

			throw domain_error("Posicion ocupada");
		}
		info[nombre] = { x, y };
		direccionX[x][y] = nombre;
		direccionY[y][x] = nombre;
	}

	void eliminar_torre(const string& nombre) {

		if (!info.count(nombre)) {

			throw domain_error("Torre ya existente");
		}
		direccionX[info[nombre].first].erase(info[nombre].second);
		direccionY[info[nombre].second].erase(info[nombre].first);

		info.erase(nombre);
	}

	pair<int, int> posicion(const string& nombre) {
		if (!info.count(nombre)) {

			throw domain_error("Torre no existente");
		}

		return info.at(nombre);
	}

	pair<bool, string> torre_en_posicion(int x, int y) {

		if (!direccionX.count(x) or !direccionX[x].count(y)) {

			return { false, "" };
		}

		return { true, direccionX[x][y] };
	}


	string torre_mas_cercana(const string& nombre,const string& dir) {

		pair<int, int> coordenadas = posicion(nombre);

        auto it2 = direccionX[coordenadas.first].lower_bound(coordenadas.second);

		return direccionX[coordenadas.first][coordenadas.second];
	}



};


#endif // !header_h