#ifndef CLIENTE_H
#define CLIENTE_H
#include "json.hpp"
using namespace std;
#include <iostream>
using json = nlohmann:: json;

class Cliente {
private:
    string nombre;
    string direccion;
    int id;

public:
    Cliente(string n, string d, int i);

    string getNombre() const;

    string getDireccion() const;

    int getId() const;

    void mostrar() const;

    json toJson() const;
};



#endif //CLIENTE_H
