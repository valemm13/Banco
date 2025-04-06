using namespace std;
#include "json.hpp"
using json = nlohmann:: json;
#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H
#include "Cuenta.h"


class CuentaCorriente : public Cuenta {
private:
    int limiteSobregiro;
public:
    CuentaCorriente(int n, int s, int ic, int ls);

    void mostrar() const override;

    json toJson() const override;

    string getTipo();

    int getLimite() const;

    void consignar(int cantidad) override;

    void retirar(int cantidad) override;
};



#endif //CUENTACLIENTE_H
