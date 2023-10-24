#pragma once
#ifndef CAR_H
#define CAR_H

using namespace std;

#include <string>

struct Car {
    int numeroSerie;
    std::string marca;
    std::string modelo;
    int anioFabricacion;
    double tarifaDiaria;
    bool alquilado;

    Car* siguiente;

    Car(int numS, std::string marca, std::string modelo, int anio, double tarifaD, bool alq);
};
#endif // CAR_H

