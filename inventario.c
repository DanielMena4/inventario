#include "validacion.h"
int main () 
{
    
    int count = 0, menu, val, aux;
  // Se usa 3 matrices para almacenar los datos, la primera magnitud es usada como identificador y la segunda como limite del string//
    char in[10], productoN[10][10], productoV[10][10], productoC[10][10];

//el inicio: sirve para volver al menu principal siempre que sea necesario// 
inicio:
    printf ("\nMenu principal");
  
    printf("\n1.Ingresar productos\n2.Editar productos\n3.Listar productos\n4.Salir\n");
  // Se lee un string para poder usar la funcion validacion(), que usa isdigit()en el string para ver si es un digito//
    scanf ("%s", in);
    val = validacion(in);
    if(val == 0)
    {   
// si no es un digito vuelve a inicio:, en el menu principal//
        goto inicio;    
    }
    else
    {
        menu = atoi (in);
    }
// si es un digito se le asigna el valor del string in a la variable menu, para hacer la comprobacion del switch//
    switch (menu)
    {
    
    case 1:
    // la variable count sirve para llevar cuenta de todos los productos ingresados//
        count++;
        aux = count - 1;
    //la variable aux es usada aqui para llenar todos los digitos de la matriz, ya que las matrices empiezan desde 0//
        printf ("Ingrese el nombre del producto : ");
        scanf ("%s", productoN[aux]);
        val = 0;
	   while(val == 0)
	   {
   // Esta comprobacion sirve para que solo se ingresen numeros///
	       printf ("\nIngrese el valor unitario del producto: ");
	       scanf ("%s", productoV[aux]);
	       val = validacion(productoV[aux]);
	   }
        val = 0;
	    while(val == 0)
	   {
  // Esta comprobacion tambien sirve para que solo se ingresen numeros//
	    printf ("\nIngrese la cantidad del producto: ");
	    scanf ("%s", productoC[aux]);
	    val = validacion(productoC[aux]);
	   }
// Cuando se ingresan todos los datos del producto se vuelve al inicio del menu//
	   goto inicio;
    case 2:
    // Modificacion: es usado para volver al principio de este proceso si es necesario//
    modificacion:
    // Este for imprime todos los productos ingresados//
        printf("\n\t Nombre del producto//Valor del producto//Cantidad del producto \n");
        for (int i = 0; i < count; i++)
	    {   
	       printf ("  %d\t\t  %s\t\t  %s\t\t  %s\n", i + 1, productoN[i], productoV[i],productoC[i]);
	    }
	    // Se valida si lo ingresado es un numero//
	   printf ("\nIngrese el numero del producto que desea modificar: ");
	   scanf ("%s", in);
	   val = validacion(in);
	   if(val == 0)
	   {
	       goto modificacion;    
	   }
	   else if(atoi(in)>count)
	   {
		// Este else if comprueba si el numero ingresado es mayor al numero de productos que se ha ingresado//
	       printf("\nIngrese un valor valido");
	       goto modificacion;
	   }
	   else
	   {
	       aux = atoi (in);
	   }
// Seleccion: es usado para volver al principio de este submenu si se ingresa un valor incorrecto//
Seleccion: 
       printf("\n\t Nombre del producto//Valor del producto//Cantidad del producto \n");
	   printf ("  %d\t\t  %s\t\t  %s\t\t  %s\n", aux, productoN[aux - 1],productoV[aux - 1], productoC[aux - 1]);
	   printf("\n1. Modificar nombre\n2. Modificar valor unitario\n3. Modificar cantidad\n4. Volver al menu principal\n");
	   scanf ("%s", in);
	   val = validacion(in);
	   if(val == 0)
	   {   
	       goto Seleccion;    
	   }
	   else
	   {
	       menu = atoi (in);
	   }
	   switch (menu)
	   {
	       case 1:
	           printf ("\nIngrese el nuevo nombre del producto: ");
	           scanf ("%s", productoN[aux-1]);
	           break;
	       case 2:
	           val = 0;
	           while(val == 0)
	           {
	                printf ("\nIngrese el nuevo valor unitario del producto: ");
	                scanf ("%s", productoV[aux-1]);
	                val = validacion(productoV[aux-1]);
	           }
	           goto inicio;
	       case 3:
	           val = 0;
	           while(val == 0)
	           {
	                printf ("\nIngrese la nueva cantidad del producto: ");
	                scanf ("%s", productoC[aux-1]);
	                val = validacion(productoC[aux-1]);
	           }
	           goto inicio;
	// Este submenu permite volver al menu principal directamente sin modificar ningun dato///
	       case 4:
	           goto inicio;
           default:
                printf ("\nIngrese una opcion correcta");
                goto inicio;
    }
        goto inicio;
    case 3:
        printf("\n\t Nombre del producto//Valor del producto//Cantidad del producto \n");
        for (int i = 0; i < count; i++)
	    {
	        printf ("  %d\t\t  %s\t\t  %s\t\t  %s\n", i + 1, productoN[i], productoV[i],productoC[i]);
	    } 
        goto inicio;
    case 4:
// Esta opcion termina la ejecucion del programa//
        return 0;
    default:
        printf ("\nEscoga una opcion valida");
        goto inicio;
    }

}


