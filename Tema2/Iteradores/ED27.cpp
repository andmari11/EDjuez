#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

template <class T>
T Mysearch(T const &ini1, T const &fin1, T const &ini2, T const &fin2)
{
    auto it1 = ini1;
    auto it2 = ini2;
    while (it1 != fin1 && it2 != fin2)
    {
        if (*it1 == *ini2)
        { // recorre el subrango
            auto aux1 = it1;
            it2 = ini2;
            while (aux1 != fin1 && it2 != fin2 && *aux1 == *it2)
            {
                ++aux1;
                ++it2;
            }
            if (it2 != fin2)
                ++it1;
        }
        else
            ++it1;
    }
    return it1;
}

bool resuelveCaso()
{
    int nElem1, nElem2;
    std ::cin >> nElem1 >> nElem2;
    if (nElem1 == 0 && nElem2 == 0)
        return false;
    std ::list<int> lista1;
    for (int i = 0; i < nElem1; ++i)
    {
        int aux;
        std ::cin >> aux;
        lista1.push_back(aux);
    }
    std ::list<int> lista2;
    for (int i = 0; i < nElem2; ++i)
    {
        int aux;
        std ::cin >> aux;
        lista2.push_back(aux);
    }
    // Elimina todas las apariciones de la lista2 en la lista 1
    // Utilizando la funcion Mysearch
    auto it1 = lista1.begin();
    while (it1 != lista1.end())
    {
        it1 = Mysearch(it1, lista1.end(), lista2.begin(), lista2.end());
        if (it1 != lista1.end())
        {
            for (int i = 0; i < lista2.size(); ++i)
            {
                it1 = lista1.erase(it1);
            }
        }
    }
    // Escribe la lista
    auto it = lista1.begin();
    if (it != lista1.end())
    {
        std ::cout << *it;
        ++it;
    }
    for (; it != lista1.end(); ++it)
        std ::cout << ' ' << *it;
    std ::cout << '\n';
    return true;
}

int main()
{

    while (resuelveCaso())
        ;
}
