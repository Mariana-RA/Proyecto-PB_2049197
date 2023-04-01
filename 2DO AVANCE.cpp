#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>

using namespace std; 


struct tienda
{
	string num_art, art_nom, descrip, gender_art, clasi_art, consol_art; //declaración de variables
	float precio, Total, impuesto;
};


int main()
{
	tienda videojuegos[3];

	int opc;

	do
	{
		printf("\t ***MENU DE OPCIONES*** \n");
		printf("1.-Alta de articulos \n");
		printf("2.-Modificacion de articulos \n");
		printf("3.-Baja de articulos \n");
		printf("4.-Lista de articulos \n");
		printf("5.-Limpiar pantalla \n");
		printf("6.-Salir \n");
		scanf_s("%d", &opc); //variable a comparar con los casos

		switch (opc)
		{
		case 1: //Alta de articulos
			for (int i = 0; i < 3; i++)
			{
				cin.ignore(); //Se utiliza para poder usar las variables tipo string
				printf("Ingresa el #item del articulo \n");
				getline(cin, videojuegos[i].num_art);
				printf("Ingresa el nombre del articulo \n");
				getline(cin, videojuegos[i].art_nom);
				printf("Ingresa la descripcion del articulo \n");
				getline(cin, videojuegos[i].descrip);
				printf("Ingresa el genero del articulo \n");
				getline(cin, videojuegos[i].gender_art);
				printf("Ingresa la clasificacion del articulo \n");
				getline(cin, videojuegos[i].clasi_art);
				printf("Ingresa la consola del articulo \n");
				getline(cin, videojuegos[i].consol_art);
				printf("Ingresa el precio del articulo \n");
				scanf_s("%f", &videojuegos[i].precio);
				videojuegos[i].impuesto = (16 * videojuegos[i].precio) / 100;
				videojuegos[i].Total = videojuegos[i].precio + videojuegos[i].impuesto;
				printf("********************************************************************* \n");
			}
			break;
		case 2:
			break;
		case 3:
			break;
		case 4: //Lista de articulos
			//Imprimir las variables
			for (int i = 0; i < 3; i++)
			{
				printf("El numero de item del articulo es: %s \n", videojuegos[i].num_art.c_str());
				printf("El nombre del articulo es: %s \n", videojuegos[i].art_nom.c_str());
				printf("La descripcion del articulo es: %s \n", videojuegos[i].descrip.c_str());
				printf("El genero del articulo es: %s \n", videojuegos[i].gender_art.c_str());
				printf("La clasificacion del articulo es: %s \n", videojuegos[i].clasi_art.c_str());
				printf("La consola del articulo es: %s \n", videojuegos[i].consol_art.c_str());
				printf("El precio es: %f \n", videojuegos[i].precio);
				printf("El impuesto es de: %f \n", videojuegos[i].impuesto);
				printf("El precio total es de: %f \n", videojuegos[i].Total);
				printf("********************************************************************* \n");
			}
			break;
		case 5:
			system("cls");
			break;
		case 6:
			exit(1);
			break;
		default:
			printf("Opcion invalida \n");
			break;
		}
	} while (opc != 6);
}