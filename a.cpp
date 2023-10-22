#include <iostream>
#include <string>

struct Auto {
    int numeroSerie;
    
    std::string marca;
    std::string modelo;
    
    int anioFabricacion;
    double tarifaDiaria;
    bool alquilado;
    
    Auto* siguiente;

    Auto(int numSerie, std::string marca, std::string modelo, int anio, double tarifa){

            this->numeroSerie=numSerie; 
            
            this->marca=marca;
            
            this->modelo=modelo; 
            
            this->anioFabricacion=anio;
            
            this->tarifaDiaria=tarifa; 
            
            this->alquilado=false; 
            
            this->siguiente=nullptr;

          }

};

class ListaAutos {

public:
    Auto* cabeza;
    ListaAutos() : cabeza(nullptr) {}

    void agregarAuto(int numSerie, std::string marca, std::string modelo, int anio, double tarifa) {
        
        Auto* nuevoAuto = new Auto(numSerie, marca, modelo, anio, tarifa);
        
        nuevoAuto->siguiente = cabeza;
        
        cabeza = nuevoAuto;
    }

    void listarAutosDisponibles() {
        Auto* actual = cabeza;
        std::cout << "Autos disponibles:\n";
        while (actual) {
            if (!actual->alquilado) {
                std::cout << "Número de serie: " << actual->numeroSerie << "\n";
                std::cout << "Marca: " << actual->marca << "\n";
                std::cout << "Modelo: " << actual->modelo << "\n";
                std::cout << "Año de fabricación: " << actual->anioFabricacion << "\n";
                std::cout << "Tarifa diaria: " << actual->tarifaDiaria << "\n";
                std::cout << "---------------------\n";
            }
            actual = actual->siguiente;
        }
    }

    void alquilarAuto(int numSerie) {
        Auto* actual = cabeza;
        while (actual) {
            if (actual->numeroSerie == numSerie && !actual->alquilado) {
                actual->alquilado = true;
                return;
            }
            actual = actual->siguiente;
        }
        std::cout << "Auto no encontrado o ya alquilado.\n";
    }

    void devolverAuto(int numSerie) {
        Auto* actual = cabeza;
        while (actual) {
            if (actual->numeroSerie == numSerie && actual->alquilado) {
                actual->alquilado = false;
                return;
            }
            actual = actual->siguiente;
        }
        std::cout << "Auto no encontrado o no alquilado.\n";
    }

    double calcularIngresoTotal() {
        double total = 0.0;
        Auto* actual = cabeza;
        while (actual) {
            if (actual->alquilado) {
                // Calcula los ingresos sumando la tarifa diaria de autos alquilados
                total += actual->tarifaDiaria;
            }
            actual = actual->siguiente;
        }
        return total;
    }

    void intercambiarAutos(int numSerie1, int numSerie2) {
        // Encuentra los nodos que deben intercambiarse
        Auto* anterior1 = nullptr;
        Auto* actual1 = cabeza;
        while (actual1 && actual1->numeroSerie != numSerie1) {
            anterior1 = actual1;
            actual1 = actual1->siguiente;
        }
        
        Auto* anterior2 = nullptr;
        Auto* actual2 = cabeza;
        while (actual2 && actual2->numeroSerie != numSerie2) {
            anterior2 = actual2;
            actual2 = actual2->siguiente;
        }
        
        // Verifica si ambos autos se encontraron
        if (actual1 && actual2) {
            // Si uno de ellos es el primer elemento, actualiza la cabeza
            if (anterior1 == nullptr) {
                cabeza = actual2;
            } else {
                anterior1->siguiente = actual2;
            }
            
            if (anterior2 == nullptr) {
                cabeza = actual1;
            } else {
                anterior2->siguiente = actual1;
            }
            
            // Intercambia los punteros de "siguiente"
            Auto* temp = actual1->siguiente;
            actual1->siguiente = actual2->siguiente;
            actual2->siguiente = temp;
        }
    }
};

int main() {
    ListaAutos listaAutos;
    
    listaAutos.agregarAuto(1, "Toyota", "Camry", 2022, 50.0);
    listaAutos.agregarAuto(2, "Honda", "Civic", 2021, 45.0);
    listaAutos.agregarAuto(3, "Ford", "Focus", 2022, 48.0);
    listaAutos.agregarAuto(4,"Fiat","Palio",2005,32.0);
    
    listaAutos.listarAutosDisponibles();
    
    listaAutos.alquilarAuto(1);
    listaAutos.alquilarAuto(2);
    
    listaAutos.listarAutosDisponibles();
    
    listaAutos.devolverAuto(2);
    
    listaAutos.listarAutosDisponibles();
    
    double ingresoTotal = listaAutos.calcularIngresoTotal();
    std::cout << "Ingreso total: " << ingresoTotal << " USD\n";
    
    listaAutos.intercambiarAutos(1, 3);
    
    listaAutos.listarAutosDisponibles();
    
    return 0;
}
