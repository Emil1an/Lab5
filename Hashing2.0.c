// Nombres de integrantes: Daniel Martinez Macedo, Emiliano Saucedo Tavitas, Roberto Carlos Benitez Rizzo, Adriana de Jesús Jerónimo Alarcón
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 9
#define SECOND_HASH_SIZE 6

// Estructura para cada elemento de la tabla hash
typedef struct {
    int key;
    int data;
} HashEntry;

// Estructura para la tabla hash
typedef struct {
    HashEntry *table[TABLE_SIZE];
} HashTable;

// Función de hash primaria
int hash1(int key) {
    return key % TABLE_SIZE;
}

// Función de hash secundaria
int hash2(int key) {
    return key % SECOND_HASH_SIZE;
}

// Función para inicializar la tabla hash
void initializeHashTable(HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
}

// Función para insertar datos en la tabla hash
void insertData(HashTable *ht, int key, int data) {
    int index = hash1(key);
    int stepSize = hash2(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        if (ht->table[index] == NULL) {
            // Espacio vacío encontrado, insertar el dato
            HashEntry *newEntry = (HashEntry *)malloc(sizeof(HashEntry));
            newEntry->key = key;
            newEntry->data = data;
            ht->table[index] = newEntry;
            printf("Dato %d insertado en la posicion %d\n", key, index);
            return;
        } else {
            // Colisión, aplicar función de hash secundaria
            index = (index + stepSize) % TABLE_SIZE;
            i++;
        }
    }

    // La tabla está llena
    printf("La tabla está llena, no se puede insertar el dato %d\n", key);
}

// Función para buscar un dato en la tabla hash
void searchData(HashTable *ht, int key) {
    int index = hash1(key);
    int stepSize = hash2(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        if (ht->table[index] != NULL && ht->table[index]->key == key) {
            // Dato encontrado
            printf("Dato %d encontrado en la posicion %d\n", key, index);
            return;
        } else {
            // Posiblemente haya una colisión, seguir buscando
            index = (index + stepSize) % TABLE_SIZE;
            i++;
        }
    }

    // El dato no se encontró
    printf("Dato %d no encontrado en la tabla\n", key);
}

// Función para eliminar un dato de la tabla hash
void deleteData(HashTable *ht, int key) {
    int index = hash1(key);
    int stepSize = hash2(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        if (ht->table[index] != NULL && ht->table[index]->key == key) {
            // Dato encontrado, eliminar
            free(ht->table[index]);
            ht->table[index] = NULL;
            printf("Dato %d eliminado de la posicion %d\n", key, index);
            return;
        } else {
            // Posiblemente haya una colisión, seguir buscando
            index = (index + stepSize) % TABLE_SIZE;
            i++;
        }
    }

    // El dato no se encontró
    printf("No se puede eliminar el dato %d porque no se encuentra en la tabla\n", key);
}

// Función para imprimir la tabla hash
void printHashTable(HashTable *ht) {
    printf("Tabla Hash:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] != NULL) {
            printf("[%d] -> Dato: %d, Valor: %d\n", i, ht->table[i]->key, ht->table[i]->data);
        } else {
            printf("[%d] -> NULL\n", i);
        }
    }
}

int main() {
    HashTable ht;
    initializeHashTable(&ht);

    // Insertar datos
    insertData(&ht, 4, 40);
    insertData(&ht, 17, 170);
    insertData(&ht, 30, 300);
    insertData(&ht, 55, 550);
    insertData(&ht, 90, 900);
    insertData(&ht, 11, 110);
    insertData(&ht, 56, 560);
    insertData(&ht, 77, 770);

    printHashTable(&ht);

    // Menú para búsqueda y eliminación de datos
    int choice, key, clv;
    do {
        printf("\nMenu:\n");
        printf("1. Insertar dato\n");
        printf("2. Buscar dato\n");
        printf("3. Eliminar dato\n");
        printf("4. Imprimir lista\n");
        printf("5. Salir\n");
        printf("Ingrese su eleccion: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Ingrese Dato: ");
                scanf("%d", &key);
                printf("Ingrese Clave: ");
                scanf("%d", &clv);
                insertData(&ht, key, clv);
                break;

            case 2:
                printf("Ingrese el dato a buscar: ");
                scanf("%d", &key);
                searchData(&ht, key);
                break;
            case 3:
                printf("Ingrese el dato a eliminar: ");
                scanf("%d", &key);
                deleteData(&ht, key);
                break;
            case 4:
                printHashTable(&ht);
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (choice != 5);

    return 0;
}