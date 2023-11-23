#include "validacion.h"
int main () 
{
    
    int count = 0, menu, val, aux;
  
    char in[10], productoN[10][10], productoV[10][10], productoC[10][10];

 
inicio:
    printf ("\nMenu principal");
  
    printf("\n1.Ingresar productos\n2.Editar productos\n3.Listar productos\n4.Salir\n");
  
    scanf ("%s", in);
    val = validacion(in);
    if(val == 0)
    {   
        goto inicio;    
    }
    else
    {
        menu = atoi (in);
    }

    switch (menu)
    {
    
    case 1:
    
        count++;
        aux = count - 1;
    
        printf ("Ingrese el nombre del producto : ");
        scanf ("%s", productoN[aux]);
        val = 0;
	   while(val == 0)
	   {
	       printf ("\nIngrese el valor unitario del producto: ");
	       scanf ("%s", productoV[aux]);
	       val = validacion(productoV[aux]);
	   }
        val = 0;
	    while(val == 0)
	   {
	    printf ("\nIngrese la cantidad del producto: ");
	    scanf ("%s", productoC[aux]);
	    val = validacion(productoC[aux]);
	   }
	   goto inicio;
    case 2:
    
    modificacion:
    
        printf("\n\t Nombre del producto//Valor del producto//Cantidad del producto \n");
        for (int i = 0; i < count; i++)
	    {   
	       printf ("  %d\t\t  %s\t\t  %s\t\t  %s\n", i + 1, productoN[i], productoV[i],productoC[i]);
	    }
	   printf ("\nIngrese el numero del producto que desea modificar: ");
	   scanf ("%s", in);
	   val = validacion(in);
	   if(val == 0)
	   {
	       goto modificacion;    
	   }
	   else if(atoi(in)>count)
	   {
	       printf("\nIngrese un valor valido");
	       goto modificacion;
	   }
	   else
	   {
	       aux = atoi (in);
	   }
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
	       case 4:
	           goto modificacion;
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
        return 0;
    default:
        printf ("\nEscoga una opcion valida");
        goto inicio;
    }

}


