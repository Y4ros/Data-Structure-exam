/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTOS 10

struct Producto {
    char nombre[50];
    float precio;
    int codigo;
};

//Prototipado de funciones
	/*ingresarProductos con variable puntero para que al momento de ingresar nuevamente productos
	o asi se modifique global y muestre todas en lugar de solo las ultimas agregadas*/
void ingresarProductos(struct Producto productos[], int *cantidad);
void mostrarProductos(struct Producto productos[], int cantidad);
void buscarProductoPorCodigo(struct Producto productos[], int cantidad);
void eliminarProducto(struct Producto productos[], int *cantidad);

int main()
{
    printf("Perez Peres Moises Yaroslav\n");
    printf("Santana Mart%cnez Laura Alejandra\n",161);
    printf("Programaci%cn Estructurada\n",162);
    printf("Tienda Do%ca Lucha\n",164);
    menu();

    return 0;
}

int menu()
{
    int opcion;
    int regresar = 1; // Variable para regresar al menu
    struct Producto productos[MAX_PRODUCTOS];
    int cantidadProductos = 0;
    int ProductoIngresado = 0;//Bandera de si se ha ingresado o no un producto
    
    while(opcion != 5 || regresar == 0) {
        	system("CLS");
            printf("\nMENU:\n");
            printf("1. Ingresar productos\n");
            printf("2. Busqueda de un producto\n");
            printf("3. Dar de baja un producto\n");
            printf("4. Mostrar los productos registrados\n");
            printf("5. Salir\n");
            printf("Ingrese su opcion: ");
            scanf("%d", &opcion);
            
            switch(opcion) {
                case 1:
                    // Llamar a la funcion para ingresar productos
                    ingresarProductos(productos, &cantidadProductos);
                    ProductoIngresado = 1;//Bandera Verde
                    break;
                case 2:
                    // Llamar a la funcion para buscar un producto
                    buscarProductoPorCodigo(productos, cantidadProductos);
                    break;
                case 3:
                    // Llamar a la funcion para eliminar un producto
                    eliminarProducto(productos, &cantidadProductos);
                    break;
                case 4:
                	//Verifica que se haya registrado al menos 1 producto
                	if(ProductoIngresado==0){
                		printf("Primero ingrese productos porfavor.\n");
					}
					else{
						// Llamar a la funcion para mostrar productos
						mostrarProductos(productos, cantidadProductos);
					}

                    break;
                case 5:
                    printf("Saliendo del programa...\n");
                    return 0;
                default:
                    printf("Opcion no valida. Intente de nuevo.\n");
            }
            
            printf("\n%cDesea regresar al menu principal? (1 = Si, 0 = No): ",168);
            scanf("%d", &regresar);
            if(regresar == 0){
            	return 0;
			}
           
        system("PAUSE");
    } while(opcion != 5); // El bucle se repite hasta que se seleccione la opcion "Salir" (5)
    
    return 0;
}

// Funcion para ingresar productos
void ingresarProductos(struct Producto productos[], int *cantidad) {
	int i;
	int cantidadProductos;
	printf("Ingrese la cantidad de productos a ingresar: ");
    scanf("%d", &cantidadProductos);
                    
    // Verificar que la cantidad de productos a ingresar no exceda el maximo permitido
    if ((*cantidad + cantidadProductos) > MAX_PRODUCTOS) {
        printf("%cError! La cantidad de productos excede el maximo permitido.\n",173);
    return;
    }
    for (i = *cantidad ; i < (*cantidad + cantidadProductos) ; i++) {
        printf("\nIngrese el nombre del producto %d: ", i + 1);
        scanf("%s", productos[i].nombre);
        printf("Ingrese el precio del producto %d: ", i + 1);
        scanf("%f", &productos[i].precio);
        printf("Ingrese el codigo del producto %d (debe ser un numero de 3 digitos): ", i + 1);
        scanf("%d", &productos[i].codigo);
    }
    printf("Se han ingresado los productos correctamente.\n");
    *cantidad+=cantidadProductos;// Se actualiza la cantidad
}
void buscarProductoPorCodigo(struct Producto productos[], int cantidad) {
    printf("Ingrese el codigo del producto que desea buscar: ");
    int codigo;
    scanf("%d", &codigo);

    int encontrado = 0;
    for (int i = 0; i < cantidad; i++) {
        if (productos[i].codigo == codigo) {
            printf("Producto encontrado:\n");
            printf("Nombre: %s\n", productos[i].nombre);
            printf("Precio: %.2f\n", productos[i].precio);
            printf("Codigo: %d\n", productos[i].codigo);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró ningún producto con ese código.\n");
    }
}

void eliminarProducto(struct Producto productos[], int *cantidad) {
    printf("Productos registrados:\n");
    mostrarProductos(productos, *cantidad);

    int codigo;
    printf("Ingrese el codigo del producto que desea eliminar: ");
    scanf("%d", &codigo);

    int encontrado = 0;
    for (int i = 0; i < *cantidad; i++) {
        if (productos[i].codigo == codigo) {
            printf("Producto encontrado:\n");
            printf("Nombre: %s\n", productos[i].nombre);
            printf("Precio: %.2f\n", productos[i].precio);
            printf("Codigo: %d\n", productos[i].codigo);

            char confirmacion;
            printf("¿Está seguro de que desea eliminar este producto? (S/N): ");
            scanf(" %c", &confirmacion);
            if (confirmacion == 'S' || confirmacion == 's') {
                // Eliminar el producto moviendo los elementos restantes del arreglo hacia atrás
                for (int j = i; j < *cantidad - 1; j++) {
                    productos[j] = productos[j + 1];
                }
                (*cantidad)--;
                printf("Producto eliminado correctamente.\n");
            } else {
                printf("Eliminación cancelada.\n");
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró ningún producto con ese código.\n");
    }
}

// Funcion para ingresar productos
void mostrarProductos(struct Producto productos[], int cantidad) {
    printf("Productos registrados:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("\nProducto %d\n", i + 1);
        printf("Nombre del producto: %s\n", productos[i].nombre);
        printf("Precio del producto: %.2f\n", productos[i].precio);
        printf("Codigo del producto: %d\n", productos[i].codigo);
    }
}