#include <iostream>
using namespace std;

// TODO: Implementar función para calcular la suma de los dígitos de un número
int sumaDigitos(int n) {
    int primerDigito = n/10;
    int segundoDigito = n- (primerDigito*10);
    int suma = primerDigito+segundoDigito;
    return suma;
}

// TODO: Implementar la lógica para calcular la tarifa
double calcularTarifa(int horas, int dia) {
    const double TARIFA_PRIMERA_HORA = 6.00;
    const double TARIFA_1_A_3 = 4.00;
    const double TARIFA_3_A_5 = 3.00;
    const double TARIFA_FIJA = 22.00;
    const int LIMITE_HORAS = 24;
    const double INCREMENTO_FIN_SEMANA = 1.15;
    const double DESCUENTO_DIGITOS = 0.95;

    // Validar límite de horas
    if (horas > LIMITE_HORAS) {
        return -1;
    }

    double totalPagar = 0.0;


    // TODO: Implementar la lógica para calcular la tarifa base
    if (horas >= 1 && horas <= 3) {
        int orbitasAdicionales = (horas-1)* TARIFA_1_A_3;
        totalPagar += TARIFA_PRIMERA_HORA+orbitasAdicionales;
    }

   else if (horas > 3 && horas <= 5) {
       int orbitasAdicionales = 2 * TARIFA_1_A_3;
       totalPagar += TARIFA_PRIMERA_HORA+ orbitasAdicionales+TARIFA_3_A_5*(horas-3);
    }
    else {
        totalPagar += TARIFA_FIJA;
    }

    // TODO: Aplicar incremento si es fin de semana
    if (dia>=6 && dia<=7) {
        totalPagar *= INCREMENTO_FIN_SEMANA;
    }

    // TODO: Aplicar descuento si la suma de los dígitos es múltiplo de 3
    if (sumaDigitos(horas)%3 == 0) {
        totalPagar *= DESCUENTO_DIGITOS;
    }

    return totalPagar;
}

int main() {
    int horas, dia;

    // Leer los valores de entrada
    cin >> horas >> dia;

    double resultado = calcularTarifa(horas, dia);
    if (resultado == -1) {
        cout << "ERROR" << endl;
    } else {
        printf("%.2f\n", resultado);
    }

    return 0;
}