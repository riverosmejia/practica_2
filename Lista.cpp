#include "Lista.h"

Lista::Lista() {
    // C�digo de inicializaci�n si es necesario
}


void Lista::agregarAuto(Car carro) {
    Car* nuevoAuto = new Car(carro.alquilado, carro.marca, carro.modelo, carro.anioFabricacion, carro.tarifaDiaria, carro.alquilado);
    nuevoAuto->siguiente = HEAD;
    HEAD = nuevoAuto;
}

void Lista::impAuto(){

    Car* actual=HEAD;

    system("cls");

    cout<<"AUTOS DISPONIBLES: \n\n";

    while (actual) {
    
        if (!actual->alquilado) {
            cout << "Numero de serie: " << actual->numeroSerie << "\n";
            cout << "Marca: " << actual->marca << "\n";
            cout << "Modelo: " << actual->modelo << "\n";
            cout << "Anio de fabricacion: " << actual->anioFabricacion << "\n";
            cout << "Tarifa diaria: " << actual->tarifaDiaria << "\n";
            cout << "---------------------\n";
        }
        
        actual = actual->siguiente;
    
    }

}
