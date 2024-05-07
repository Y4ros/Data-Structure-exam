/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTOS 100

struct Producto {
    char nombre[50];
    float precio;
    int codigo;
};

int main()
{
    printf("Perez Peres Moises Yaroslav\n");
    printf("Santana Laura Alejandra\n");
    printf("Programacion Estructurada\n");
    printf("Tienda Doña Lucha\n");
    menu();

    return 0;
}

int menu()
{
    int opcion;
    int regresar = 1; // Variable para regresar al menu
    struct Producto productos[MAX_PRODUCTOS];
    int cantidadProductos;

    
    do {
        while (regresar) {
            printf("\nMENU:\n");
            printf("1. Opción 1\n");
            printf("2. Opción 2\n");
            printf("3. Opción 3\n");
            printf("4. Opción 4\n");
            printf("5. Salir\n");
            printf("Ingrese su opción: ");
            scanf("%d", &opcion);
            
            switch(opcion) {
                case 1:
                    printf("Ingrese la cantidad de productos a ingresar: ");
                    scanf("%d", &cantidadProductos);
                    
                    // Verificar que la cantidad de productos a ingresar no exceda el máximo permitido
                    if (cantidadProductos > MAX_PRODUCTOS) {
                        printf("¡Error! La cantidad de productos excede el máximo permitido.\n");
                        break;
                    }
                    
                    // Llamar a la función para ingresar productos
                    ingresarProductos(productos, cantidadProductos);
                    break;
                case 2:
                    opc2();
                    break;
                case 3:
                    opc3();
                    break;
                case 4:
                    opc4();
                    break;
                case 5:
                    printf("Saliendo del programa...\n");
                    return 0;
                default:
                    printf("Opción no válida. Intente de nuevo.\n");
            }
            
            printf("\n¿Desea regresar al menú principal? (1 = Sí, 0 = No): ");
            scanf("%d", &regresar);
        }
        
        regresar = 1; // Reiniciar regresar para mostrar el menú principal nuevamente
        
    } while(opcion != 5); // El bucle se repite hasta que se seleccione la opción "Salir" (5)
    
    return 0;
}

// Función para ingresar productos
void ingresarProductos(struct Producto productos[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("\nIngrese el nombre del producto %d: ", i + 1);
        scanf("%s", productos[i].nombre);
        printf("Ingrese el precio del producto %d: ", i + 1);
        scanf("%f", &productos[i].precio);
        printf("Ingrese el código del producto %d (debe ser un número de 3 dígitos): ", i + 1);
        scanf("%d", &productos[i].codigo);
    }
    printf("Se han ingresado los productos correctamente.\n");
}
int opc2()
{
    return 0;
}

int opc3()
{
    return 0;
}

int opc4()
{
    return 0;
}