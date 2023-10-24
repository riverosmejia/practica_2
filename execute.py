class Car:
    def __init__(self, serie, marca, modelo, anio, tarifa_diaria, alquilado):
        self.serie = serie
        self.marca = marca
        self.modelo = modelo
        self.anio = anio
        self.tarifa_diaria = tarifa_diaria
        self.alquilado = alquilado

class Lista:
    gan=0.0 
    def __init__(self):
              
        self.autos = []

    def agregar_auto(self, carro):
        self.autos.append(carro)

    def imprimir_autos(self):
        for carro in self.autos:
            if not carro.alquilado:
                print(f"\nSerie: {carro.serie}, \nMarca: {carro.marca}, \nModelo: {carro.modelo}, \nAño: {carro.anio}, \nTarifa Diaria: {carro.tarifa_diaria}")

    def alquilar_auto(self, num):
        for carro in self.autos:
            if carro.serie == num and not carro.alquilado:
                carro.alquilado = True
                return True
        return False

    def devolver_auto(self, num):
        for carro in self.autos:
            if carro.serie == num and carro.alquilado:
                carro.alquilado = False
                return True
        return False

    def ganancias(self):

        self.gan=self.gan + sum(carro.tarifa_diaria for carro in self.autos if carro.alquilado)

        return self.gan;

class execute:
    def arranque(self):
        ListaAutos = Lista()

        serie = 1

        carro1 = Car(serie, "Renault", "12", 1996, 20.0, False)
        ListaAutos.agregar_auto(carro1)

        serie += 1

        carro2 = Car(serie, "Fiat", "Palio", 2005, 45.0, False)
        ListaAutos.agregar_auto(carro2)

        serie += 1

        carro3 = Car(serie, "Chevrolet", "Spark", 2015, 65.0, False)
        ListaAutos.agregar_auto(carro3)

        serie += 1

        carro4 = Car(serie, "Toyota", "Corolla", 2023, 150.0, False)
        ListaAutos.agregar_auto(carro4)

        self.programa(ListaAutos)

    def programa(self, ListaAutos):
        num = 0

        while num != 5:

            num=0;

            while num < 1 or num > 5:
                num = int(input("MENU:\n\n1. Autos Disponibles.\n2. Alquilar Auto\n3. Devolver Auto\n4. Ingresos Totales Actuales\n5. Salir\n\nR/= "))

                if num < 1 or num > 5:
                    print("Número no válido. Debe estar en el rango de 1 a 5.")

            if num == 1:
                ListaAutos.imprimir_autos()

            if num == 2:
                num1 = int(input("Dame el número del automóvil: "))
                if ListaAutos.alquilar_auto(num1):
                    print("\n\n<----Auto Alquilado con éxito---->\n\n")
                else:
                    print("\n\n<---El número del auto que ingresaste es inválido o ya está alquilado--->\n\n")

            if num == 3:
                num1 = int(input("Dame el número del automóvil a devolver: "))
                if ListaAutos.devolver_auto(num1):
                    print("\n\n<----Auto Devuelto con éxito---->\n\n")
                else:
                    print("\n\n<---El número del auto que ingresaste es inválido o ya se ha devuelto--->\n\n")

            if num == 4:
                g = ListaAutos.ganancias()
                print(f"\n\nINGRESOS ACTUALES: {g}\n\n")

            if num == 5:
                print("\n\nAdiós\n\n")

            input("Presiona Enter para continuar...")
            