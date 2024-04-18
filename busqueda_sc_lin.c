// Nombres de integrantes: Daniel Martinez Macedo, Emiliano Saucedo Tavitas, Roberto Carlos Benitez Rizzo, Adriana de Jesús Jerónimo Alarcón
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 10000

// Funciones de ordenamiento
void bubbleSort(int arr[], int n);
void Blineal(int arr[], int value, int size);
int binarySearch(int arr[], int value, int left, int right);

// Funciones auxiliares
void printArray(int arr[], int n);

int main() {
    int option, value, size;
    time_t t1 = 0;
    srand((unsigned)time(&t1));

    printf("Ingrese la cantidad de datos para generar: ");
    scanf("%d", &size);
    printf("Generando Array\n");
    int arr[MAX_ARRAY_SIZE];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 101;
    }

    printf("Arreglo sin ordenar:\n");
    printArray(arr, size);

    printf("\nIngresar dato a buscar: ");
    scanf("%d", &value);

    printf("\nSeleccione el metodo de busqueda:\n");
    printf("1. Busqueda lineal\n2. Busqueda Binaria\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("\nResultado de la búsqueda lineal:\n");
            Blineal(arr, value, size);
            break;
        case 2:
            bubbleSort(arr, size);
            //printf("\nArreglo ordenado:\n");
            //printArray(arr, size);
            printf("\nResultado de la búsqueda binaria:\n");
            printf("El dato se encuentra en la posición %d del arreglo.\n", binarySearch(arr, value, 0, size - 1));
            break;
        default:
            printf("Opción invalida.\n");
            return 1;
    }

    return 0;
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Blineal(int arr[], int value, int size) {
    int pos = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            pos = i;
            printf("\nEl dato se encuentra en la posición %d del arreglo\n", pos);
        }
    }
    if (pos == -1) {
        printf("\nEl dato no se encontró\n");
    }
    return;
}

int binarySearch(int arr[], int value, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == value)
            return mid;

        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}