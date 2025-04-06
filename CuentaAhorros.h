#include "Cuenta.h"
using namespace std;
#include "json.hpp"
using json = nlohmann:: json;
#ifndef CUENTAAHORROS_H
#define CUENTAAHORROS_H



class CuentaAhorros : public Cuenta {
private:
    double tasaInteres;

public:
    CuentaAhorros(int n, int s, int ic, double tasaInteres);

    void mostrar() const override;

    json toJson() const override;

    string getTipo();

    double getTasaInteres() const;

    void aplicarInteres() ;

    void consignar(int cantidad) override;

    void retirar(int cantidad) override;
};



#endif //CUENTAAHORROS_H
