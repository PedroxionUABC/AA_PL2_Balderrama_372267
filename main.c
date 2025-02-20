#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipos

void generator(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void countingSort(int arr[], int n, int exp);
void radixSort(int arr[], int n);
void printArray(int arr[], int n);
void menu();
void printMenu();
void clear();
void pause();

// main

int main()
{
    menu();
    return 0;
}

// Desarrollo de funciones

void generator(int arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }
    clear();
    printArray(arr, n);
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printArray(arr, n);
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
    printArray(arr, n);
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printArray(arr, n);
}

void countingSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    printArray(arr, n);
}

void radixSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);

    printArray(arr, n);
}

void printArray(int arr[], int n)
{
    printf("Cantidad de columnas para imprimir la tabla del arreglo: ");
    int x;
    fflush(stdin);
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);

        if (i % x == 0 && i != 0)
        {
            printf("\n");
        }
    }
    printf("\n");
    pause();
}

void menu()
{
    clear();
    printf("Analisis de algoritmos - Actividad de laboratorio 2\n");
    printf("Escribe el tamano del arreglo: ");
    int n;
    fflush(stdin);
    scanf("%d", &n);
    int arr[n];
    generator(arr, n);
    while (1)
    {
        clear();
        printMenu();
        int op;
        //char opChar;
        printf("Opcion: ");
        scanf("%d", &op);
        clear();
        switch (op)
        {
        // case 0:
        //     generator(arr, n);
        //     break;
        case 1:
            insertionSort(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            break;
        case 3:
            bubbleSort(arr, n);
            break;
        case 4:
            radixSort(arr, n);
            break;
        case 5:
            printArray(arr, n);
            break;
        case 10:
            generator(arr, n);
            break;
        default:
            printf("No escogiste una opcion valida");
            pause();
            break;
        }
        clear();
    }
}
void printMenu()
{
    // printf("Opcion 0.- Generar arreglo\n");
    printf("Opcion 1.- Ordenamiento por insercion\n");
    printf("Opcion 2.- Ordenamiento por seleccion\n");
    printf("Opcion 3.- Ordenamiento por burbuja\n");
    printf("Opcion 4.- Ordenamiento radix\n");
    printf("Opcion 5.- Imprimir arreglo\n");
    printf("Opcion 10.- Reiniciar arreglo\n");
}
void clear()
{
    system("clear");
}
void pause()
{
    printf("ENTER para continuar");
    while (getchar() != '\n')
        ; // limpiar el buffer
    getchar();
}