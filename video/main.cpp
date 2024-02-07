#include "double_linked_list_ed_plus.h"
#include <list>

void interseccionList(list <int>& lista1, const list <int>& lista2) {

    auto it1 = lista1.begin();
    auto it2 = lista2.begin();

    if (it1 == lista1.end()) {
        lista1.clear();
    }

    while (it1 != lista1.end() && it2 != lista2.end()) {

        if (*it1 < *it2) {

            //borra el elemento no repetido y el iterador pasa al siguiente
            it1 = lista1.erase(it1);

        }
        else if (*it2 < *it1) {

            //pasamos al siguiente elemento sin borrar
            ++it2;
        }
        else {

            //esta en ambas listas asi q no se borra
            ++it1;
            ++it2;
        }
    }
    while (it1 != lista1.end()) {
        it1 = lista1.erase(it1);
    }


    for (auto it = lista1.begin(); it != lista1.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

}

void resuelveCaso2() {
    int aux;

    cin >> aux;

    list <int> lista1;

    while (aux != 0) {

        lista1.push_back(aux);
        cin >> aux;
    }

    cin >> aux;

    list <int> lista2;

    while (aux != 0) {

        lista2.push_back(aux);
        cin >> aux;
    }

    interseccionList(lista1, lista2);
}
int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        resuelveCaso2();

}