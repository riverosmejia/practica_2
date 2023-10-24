#include "Lista.h"

Lista::Lista() {
    // Código de inicialización si es necesario
}


void Lista::agregarAuto(Car carro) {
    Car* nuevoAuto = new Car(carro.alquilado, carro.marca, carro.modelo, carro.anioFabricacion, carro.tarifaDiaria, carro.alquilado);
    nuevoAuto->siguiente = HEAD;
    HEAD = nuevoAuto;
}
