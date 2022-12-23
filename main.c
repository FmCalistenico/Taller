#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

//Numeros Romanos
int romanToInt(char *s) {
    int result = 0;
    int i;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == 'I') {
            if (s[i + 1] == 'V' || s[i + 1] == 'X') {
                result -= 1;
            } else {
                result += 1;
            }
        } else if (s[i] == 'V') {
            result += 5;
        } else if (s[i] == 'X') {
            if (s[i + 1] == 'L' || s[i + 1] == 'C') {
                result -= 10;
            } else {
                result += 10;
            }
        } else if (s[i] == 'L') {
            result += 50;
        } else if (s[i] == 'C') {
            if (s[i + 1] == 'D' || s[i + 1] == 'M') {
                result -= 100;
            } else {
                result += 100;
            }
        } else if (s[i] == 'D') {
            result += 500;
        } else if (s[i] == 'M') {
            result += 1000;
        } else {
            return -1;  // dato invalido
        }
    }
    return result;
}

void aux_romanToInt() {
    char roman[16];
    printf("Ingrese el numero romano que desee convertir... : ");
    scanf("%s", roman); //se captura el dato ingresado
    int result = romanToInt(roman); //se envia el resultado al metodo de conversion
    if (result == -1) {
        printf("Null\n");
    } else {
        printf("%d\n", result);
    }
}

//Factores Primos
void factoresPrimos(int numero) {
    int i;
    int potencia;
    int factores[100];  // Array para almacenar los factores primos
    int exponentes[100];  // Array para almacenar los exponentes de los factores primos
    int num_factors = 0;  // Número de factores primos encontrados hasta ahora

    // For para buscar el numero de factores primos del numero ingresado
    for (i = 2; i <= sqrt(numero); i++) {
        potencia = 0;
        while (numero % i == 0) {
            potencia++;
            numero /= i;
        }
        if (potencia > 0) {
            factores[num_factors] = i;
            exponentes[num_factors] = potencia;
            num_factors++;
        }
    }

   
    if (numero > 2) {
        factores[num_factors] = numero;
        exponentes[num_factors] = 1;
        num_factors++;
    }

    // Ordena los factores primos de mayor a menor
    for (i = 0; i < num_factors - 1; i++) {
        for (int j = i + 1; j < num_factors; j++) {
            if (factores[i] < factores[j]) {
                int temp = factores[i];
                factores[i] = factores[j];
                factores[j] = temp;
                temp = exponentes[i];
                exponentes[i] = exponentes[j];
                exponentes[j] = temp;
            }
        }
    }

    // Imprime la factorización de primos en formato potencia
    for (i = 0; i < num_factors; i++) {
        printf("%d^%d ", factores[i], exponentes[i]);
    }
    printf("\n");
}

int aux_factoresPrimos() {

    int n;
    //Le pedimos al usuario que ingrese un numero
    printf("Ingrese un numero... : ");
    //capturamos el numero ingresado
    scanf("%d", &n);
    printf("la descomposicion del numero en potencias de sus factores primos %d es: ", n);
    factoresPrimos(n);

    return 0;

}

//Borrar Espacios
void borrarEspacios(char *cadenaTexto) {
    int i = 0, j = 0;
    int len = strlen(cadenaTexto);

    // eliminar espacios del inicio
    while (isspace(cadenaTexto[i]) && i < len) i++;

    // eliminar espacios del final
    while (isspace(cadenaTexto[len - 1]) && len > 0) len--;

    // eliminar espacios entre palabras
    while (i < len) {
        if (!isspace(cadenaTexto[i]) || (isspace(cadenaTexto[i]) && !isspace(cadenaTexto[j - 1]))) {
            cadenaTexto[j++] = cadenaTexto[i];
        }
        i++;
    }

    cadenaTexto[j] = '\0';
}

char aux_borrarEspacios() {
#define MAX_LEN 100
    char cadenaTexto[MAX_LEN];

    printf("Ingresar un texto: ");
    fflush(stdin);
    fgets(cadenaTexto, MAX_LEN, stdin);

    borrarEspacios(cadenaTexto);
    printf("Texto ingresado con los espacios extra borrados: %s", cadenaTexto);
    printf("\n");

    return 0;
}

int Numeros_Egolatras(int n) {
    int numeroDigitos = floor(log10(n) + 1);
    char cadena[numeroDigitos + 1];;

    sprintf(cadena, "%d", n);

    int suma = 0;
    for (int i = 0; i < numeroDigitos; i++) {
        int cont = cadena[i] - '0';

        int elevado = pow(cont, numeroDigitos);
        suma = suma + elevado;
    }
    if (suma == n) {
        return 1;
    } else {
        return 0;
    }
}

int NumeroMagico(int number) {
    int ac, c, r, aux;
    while (c <= 9) {
        aux = number;
        while (aux > 0) {
            r = aux % 10;
            if (r == c) {
                ac = (ac * 10) + r;
            }
            aux = (aux - r) / 10;
        }
        c = c + 1;
    }
    int menor = ac;
    int invert = 0;
    while (ac > 0) {
        invert = (invert * 10) + (ac % 10);
        ac = ac / 10;

    }
    int mayor = invert;

    int resta = mayor - menor;
    if (resta == number) {
        return 1;
    } else {
        return 0;
    }

}

void Date(char date[10]) {


    if (date[2] == '/' && date[5] == '/' && date[9] !=
                                            '\0' && date[8] !=
                                                    '\0' && date[7] !=
                                                            '\0' && date[6] !=
                                                                    '\0') {
        char mes;
        char dia1 = date[0];
        char dia2 = date[1];
        char mes1 = date[3];
        char mes2 = date[4];
        char año1 = date[6];
        char año2 = date[7];
        char año3 = date[8];
        char año4 = date[9];


        if (dia1 == '0' || dia1 == '1' || dia1 == '2') {

            if (mes1 == '0' && mes2 == '1') {
                printf("%c%c de Enero de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '0' && mes2 == '2') {
                printf("%c%c de Febrero de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '0' && mes2 == '3') {
                printf("%c%c de Marzo de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '0' && mes2 == '4') {
                printf("%c%c de Abril de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '0' && mes2 == '5') {
                printf("%c%c de Mayo de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '0' && mes2 == '6') {
                printf("%c%c de Junio de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '0' && mes2 == '7') {
                printf("%c%c de Julio de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '0' && mes2 == '7') {
                printf("%c%c de Julio de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '0' && mes2 == '7') {
                printf("%c%c de Julio de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '0' && mes2 == '8') {
                printf("%c%c de Agosto de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '0' && mes2 == '9') {
                printf("%c%c de Septiembre de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '1' && mes2 == '0') {
                printf("%c%c de Octubre de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '1' && mes2 == '1') {
                printf("%c%c de Noviembre de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '1' && mes2 == '2') {
                printf("%c%c de Diciembre de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else {
                printf("El mes no es valido");
            }


        } else {
            printf("El dia no es valido");
        }
    } else {
        printf("La fecha  no es correcta por favor ingresera con el formato=01/12/2022");
    }
}

int productoPunto() {

    int vecOne[5], vecTwo[5];
    int aux[5];
    int result = 0;
    int lenOne, lenTwo;

    printf("\nIngrese la longitud del vector 1\n");
    scanf("%d", &lenOne);

    printf("Ingrese la longitud del vector 2\n");
    scanf("%d", &lenTwo);


    if (lenOne == lenTwo) {
        printf("Agregue valores al primer vector \n");
        for (int i = 0; i < lenOne; i++)
            scanf("%d", &vecOne[i]);
        printf("Agregue valores al segundo vector \n");
        for (int i = 0; i < lenTwo; i++)
            scanf("%d", &vecTwo[i]);


    } else {


        printf("Null\n");
        return 0;

    }

    for (int i = 0; i < lenTwo; i++) {
        aux[i] = vecOne[i] * vecTwo[i];
        result += aux[i];
    }


    printf("El producto punto de los vectores registrados es --> %d \n ", result);

    return result;

}

int multiplicacionMatriz() {
    int a[15][15], b[15][15], c[15][15];
    int f1, f2, c1, c2;

    int cont, aux;

    printf("\n Agregue el numero de filas de la matriz 1 \n");
    scanf("%d", &f1);

    printf("Agregue el numero de columnas de la matriz 1 \n");
    scanf("%d", &c1);

    printf("Agregue el numero de filas de la matriz 2 \n ");
    scanf("%d", &f2);

    printf("Agregue el numero de columnas de la matriz 2 \n");
    scanf("%d", &c2);


    if (f1 == c2) {


        for (int i = 0; i < f1; ++i) {
            for (int j = 0; j < c1; ++j) {
                a[i][j] = rand() % 9 + 1;
            }
        }

        for (int i = 0; i < f2; ++i) {
            for (int j = 0; j < c2; ++j) {
                b[i][j] = rand() % 9 + 1;
            }
        }

        for (int i = 0; i < f1; ++i) {
            for (int j = 0; j < c1; ++j) {
                for (cont = 0, aux = 0; cont < c1; ++cont) {
                    aux = aux + a[i][cont] * b[cont][j];
                }
                c[i][j] = aux;
            }
        }

        printf(" ---- Primer matriz -----");
        for (int i = 0; i < f1; ++i) {
            printf("\n");
            for (int j = 0; j < c1; ++j) {
                printf("\t%d", a[i][j]);
            }
        }

        printf("\n ---- Segunda matriz ----");
        for (int i = 0; i < f2; ++i) {
            printf("\n");
            for (int j = 0; j < c2; ++j) {
                printf("\t%d", b[i][j]);
            }
        }

        printf("\n Multiplicacion de matriz ");
        for (int i = 0; i < f1; ++i) {
            printf("\n");
            for (int j = 0; j < c2; ++j) {
                printf("\t%d", c[i][j]);
            }
        }
        printf("\n");
    } else {
        printf("Null\n");
        return 0;

    }

    return aux;
}

void matrizMagica(int num) {
    int a[num][num];
    int i = 1;
    int j = (1 + num) / 2;
    int aux = 2;


    if (num % 2 == 1) {
        for (int i = 1; i <= num; i++) {
            for (int j = 1; j <= num; j++) {
                a[i][j] = 0;
            }
        }
    } else {
        return;
    }

    a[i][j] = 1;
    while (aux <= (num * num)) {
        i = i - 1;
        j = j + 1;
        if (i < 1 && j > num) {
            i = i + 2;
            j = j - 1;
        } else {
            if (i < 1) {
                i = num;
            }
            if (j > num) {
                j = 1;
            }
        }
        if (a[i][j] == 0) {
            a[i][j] = aux;
        } else {
            i += 2;
            j -= 1;
            a[i][j] = aux;
        }
        aux++;
    }

    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= num; j++) {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

int menuOption;
char *menu = "\t---MENU DE OPCIONES--- \n\n"
             "1. Numeros Romanos\n"
             "2. Factores Primos\n"
             "3. Borrar Espacios\n"
             "4. Numeros Egolatras \n"
             "5. Numero Magico \n"
             "6. Fechas\n"
             "7. Producto Punto\n"
             "8. Multiplicacion de Matrices\n"
             "9. Matriz Magica\n"
             "0. Salir\n\n"
             "Dijite una opcion del menu\n";

int main() {

    do {

        printf(menu);
        scanf("%i", &menuOption);
        fflush(stdin);
        switch (menuOption) {
            int num;
            char date[0];

            case 0:
                printf("Saliendo...\n");

                break;
            case 1:
                printf("--Numeros Romanos--\n");
                aux_romanToInt();
                break;
            case 2:
                printf("--Factores Primos--\n");
                aux_factoresPrimos();
                break;
            case 3:
                printf("--Borrar Espacios Extra--\n");
                aux_borrarEspacios();
                break;
            case 4:
                num = 0;
                printf("-------Numeros Egolatras-----\n");
                printf("Ingrese el numero \n ");
                scanf("%d", &num);
                printf("El numero %d %s", num, Numeros_Egolatras(num) ? "es egolatra" : "No es egolatra\n");


                break;

            case 5:
                printf("-------Numeros Magico-----\n");
                printf("Ingrese el numero \n ");
                scanf("%d", &num);
                printf("El numero %d %s", num, NumeroMagico(num) ? "es magico" : "No es magico\n");

                break;

            case 6:

                printf("-------Fechas-----\n");
                printf("Ingrese la fecha de la siguiente forma 02/12/2022 \n ");
                scanf("%s", &date);
                Date(date);
                break;


            case 7:
                printf("--Producto Punto--");
                productoPunto();
                break;
            case 8:
                printf("--Multiplicacion de Matrices--");
                multiplicacionMatriz();
                printf("\n");


                break;
            case 9:
                num = 0;
                printf("---Matriz Magica--");
                printf("Agregue una longitud a la matriz magica (Impar)\n");
                scanf("%d", &num);
                matrizMagica(num);


                break;

            default:
                printf("\n\n Por favor seleccione una opcion valida\n\n\n");


        }
    } while (menuOption != 0);


    return 0;
}
