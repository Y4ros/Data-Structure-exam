#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTOS 10

struct Producto {
    char nombre[50];
    float precio;
    int codigo;
	};
typedef struct Producto Tienda;//Renombre de la struct como Tienda

//Prototipado de funciones

int menu();
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
    menu();//Se llama a la funcion que muestra el menu, la cual contiene los contenidos

    return 0;
}

int menu()
{
    int opcion;//Variable con la que se maneja el switch del menú
    int regresar = 1; // Variable para regresar al menú luego de cada proceso
    Tienda productos[MAX_PRODUCTOS];//Vector combinado con struct
    int cantidadProductos = 0;//Variable con la que se maneja el registro de productos
    
    do{
        	system("CLS");
            printf("\nMEN%c:\n",233);
            printf("1. Ingresar productos\n");
            printf("2. B%csqueda de un producto\n",163);
            printf("3. Dar de baja un producto\n");
            printf("4. Mostrar los productos registrados\n");
            printf("5. Salir\n");
            printf("Ingrese su opci%cn: ",162);
            scanf("%d", &opcion);
            
            switch(opcion) {
                case 1:
                    // Llamar a la funcion para ingresar productos
                    ingresarProductos(productos, &cantidadProductos);
                    break;
                    
                case 2:
                	//Comprobación de registro
					if(cantidadProductos==0){
						printf("No hay productos registrados.\n");
						break;
					}
                    // Llamar a la funcion para buscar un producto
                    buscarProductoPorCodigo(productos, cantidadProductos);
                    break;
                    
                case 3:
                	//Comprobación de registro
					if(cantidadProductos==0){
						printf("No hay productos registrados.\n");
						break;
					}
                    // Llamar a la funcion para eliminar un producto
                    eliminarProducto(productos, &cantidadProductos);
                    break;
                    
                case 4:
                	//Comprobación de registro
					if(cantidadProductos==0){
						printf("No hay productos registrados.\n");
						break;
					}
						// Llamar a la funcion para mostrar productos
						mostrarProductos(productos, cantidadProductos);
                    break;
                    
                case 5:
                    printf("Saliendo del programa...\n");
                    break;
                    
                default:
                    printf("Opci%cn no v%clida. Intente de nuevo.\n",162,160);
            }
            
            if(opcion!=5){
            	printf("\n%cDesea regresar al men%c principal? (1 = Si, 0 = No): ",168,163);
            	scanf("%d", &regresar);
            	if(regresar == 0){
            		return 0;
				}
			}
           
        system("PAUSE");
    } while(opcion != 5||regresar!=0); // El bucle se repite hasta que se seleccione la opcion "Salir" (5)
    
    return 0;
}

// Funcion para ingresar productos
void ingresarProductos(Tienda productos[], int *cantidad) {
	int i;
	int cantidadProductos;
	printf("Ingrese la cantidad de productos a ingresar: ");
    scanf("%d", &cantidadProductos);
                    
    // Verificar que la cantidad de productos a ingresar no exceda el maximo permitido
    if ((*cantidad + cantidadProductos) > MAX_PRODUCTOS) {
        printf("%cError! La cantidad de productos excede el m%cximo permitido.\n",173,160);
    return;//regresa al menu
    }
    
    for (i = *cantidad ; i < (*cantidad + cantidadProductos) ; i++) {
        printf("\nIngrese el nombre del producto %d: ", i + 1);
        scanf("%s", productos[i].nombre);
        printf("Ingrese el precio del producto %d: ", i + 1);
        scanf("%f", &productos[i].precio);
        printf("Ingrese el c%cdigo del producto %d (debe ser un n%cmero de 3 digitos): ",162, i + 1,163);
        scanf("%d", &productos[i].codigo);
    }
    printf("Se han ingresado los productos correctamente.\n");
    *cantidad+=cantidadProductos;// Se actualiza la cantidad
}

//Funcion para buscar un producto
void buscarProductoPorCodigo(Tienda productos[], int cantidad) {
    printf("Ingrese el c%cdigo del producto que desea buscar: ",162);
    int i, codigo;
    scanf("%d", &codigo);

    int encontrado = 0;//Bandera de si se encuentra producto con dicho codigo
    for (i = 0; i < cantidad; i++) {
        if (productos[i].codigo == codigo) {
            printf("Producto encontrado:\n");
            printf("Nombre: %s\n", productos[i].nombre);
            printf("Precio: %.2f\n", productos[i].precio);
            printf("C%cdigo: %d\n",162, productos[i].codigo);
            encontrado = 1;//Bandera verde
            break;
        }
        
    }

   	if (!encontrado) {
        printf("No se encontr%c ning%cn producto con ese c%cdigo.\n",162,163,162);
    }
}

//Funcion para eliminar productos
void eliminarProducto(Tienda productos[], int *cantidad) {
    mostrarProductos(productos, *cantidad);/*Se llama a la funcion de mostrar para facilitar al 
											usuario de ver que productos hay y cual eliminar*/
	
    int i ,j , codigo;
    printf("Ingrese el c%cdigo del producto que desea eliminar: ",162);
    scanf("%d", &codigo);

    int encontrado = 0;
    for (i = 0; i < *cantidad; i++) {
        if (productos[i].codigo == codigo) {
            printf("Producto encontrado:\n");
            printf("Nombre: %s\n", productos[i].nombre);
            printf("Precio: %.2f\n", productos[i].precio);
            printf("C%cdigo: %d\n",162, productos[i].codigo);

            char confirmacion;//Declaracion de variable para confirmar la eliminacion del producto
            printf("%cEsta seguro de que desea eliminar este producto? (S/N): ",168);
            scanf(" %c", &confirmacion);
            if (confirmacion == 'S' || confirmacion == 's') {
                // Eliminar el producto moviendo los elementos restantes del arreglo hacia atras
                for (j = i; j < *cantidad - 1; j++) {
                    productos[j] = productos[j + 1];
                }
                (*cantidad)--;//Se actualiza la cantidad
                printf("Producto eliminado correctamente.\n");
            } 
			else{
                printf("Eliminaci%cn cancelada.\n",162);
            }
            encontrado = 1;//Bandera verde
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontr%c ning%cn producto con ese c%cdigo.\n",162,163,162);
    }
}

// Funcion para ingresar productos
void mostrarProductos(Tienda productos[], int cantidad) {
	int i;
    printf("Productos registrados:\n");
    for (i = 0; i < cantidad; i++) {
        printf("\nProducto %d\n", i + 1);
        printf("Nombre del producto: %s\n", productos[i].nombre);
        printf("Precio del producto: %.2f\n", productos[i].precio);
        printf("C%cdigo del producto: %d\n",162, productos[i].codigo);
    }
}
