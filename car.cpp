

#include "Car.h"

Car::Car(int numS, std::string marca, std::string modelo, int anio, double tarifaD, bool alq) {
    numeroSerie = numS;
    this->marca = marca;
    this->modelo = modelo;
    anioFabricacion = anio;
    tarifaDiaria = tarifaD;
    alquilado = alq;
}
