//bibliotecas
#include <iostream>  
#include <conio.h>
#include <stdio.h>
#include <string.h> // permite el uso del string
#include <string>
#include <wchar.h>
#include <fstream> //permite el uso de archivos
#include <stdlib.h> //se utiliza para la gestión de la memoria

using namespace std; //espacio de trabajo


struct tienda //Permite el uso de diferentes tipo de variables
{
	string num_art, art_nom, descrip, gender_art, clasi_art, consol_art,status,carac_art; //declaración de variables
	int año_art;
	float precio, Total, impuesto;
};
int cont, alta;

tienda* videojuegos; //uso de punteros de la estructura
//declaración de funciones tipo void
void Alta();
void Modificar();
void Baja();
void Lista();
void Archivo();


int main()
{
	int opc;
	printf("\t %c %c %c MEN%c DE OPCIONES %c %c %c \n",1,2,1,233,2,1,2);
	printf("%c 1.-Alta de art%cculos \n",16,161);
	printf("%c 2.-Modificaci%cn de art%cculos \n",16,162,161);
	printf("%c 3.-Baja de art%cculos \n",16,161);
	printf("%c 4.-Lista de art%cculos \n",16,161);
	printf("%c 5.-Limpiar pantalla \n",16);
	printf("%c 6.-Salir \n",16);
	scanf_s("%d", &opc); //variable a comparar con los casos

	switch (opc)
	{
	case 1://Alta de articulos
		Alta();
		return main();
		break;
	case 2://Modificar art
		Modificar();
		return main();
		break;
	case 3://Baja de art
		Baja();
		return main();
		break;
	case 4://Lista de art
		Lista();
		return main();
		break;
	case 5://Limpiar pantalla
		system("cls");
		return main();
		break;
	case 6://Salir
		Archivo();
		break;
	default:
		printf("%c%cOPCION INVALIDA%c%c, favor de la elegir la opcion correcta \n",173,173,33,33);
		return main();
		break;
	}
	
}
void Alta()
{
	printf("Ingrese la cantidad de art%cculos a dar de alta \n",161);
	scanf_s("%d", &alta);
	videojuegos = new tienda[alta]; //uso del new para hacerlo dinamico en toda la estructura
	for (int i = 0; i < alta; i++)
	{
		cin.ignore(); //Se utiliza para borrar el espacio que haya quedado al utilizar cin
		printf("Ingresa el #item del art%cculo \n",161);
		getline(cin, videojuegos[i].num_art);
		printf("Ingresa el nombre del art%cculo \n",161);
		getline(cin, videojuegos[i].art_nom);
		printf("Ingresa la descripci%cn del art%cculo \n",162,161);
		getline(cin, videojuegos[i].descrip);
		printf("Ingresa el g%cnero del art%cculo \n",130,161);
		getline(cin, videojuegos[i].gender_art);
		printf("Ingresa la clasificaci%cn del art%cculo \n",162,161);
		getline(cin, videojuegos[i].clasi_art);
		printf("Ingrese las caracter%csticas del art%cculo \n",161, 161);
		getline(cin, videojuegos[i].carac_art);
		printf("Ingresa la consola del art%cculo \n",161);
		getline(cin, videojuegos[i].consol_art);
		printf("Ingrese el a%co de lanzamiento \n",164);
		scanf_s("%d", &videojuegos[i].año_art);
		printf("Ingresa el precio del art%cculo \n",161);
		scanf_s("%f", &videojuegos[i].precio);
		videojuegos[i].impuesto = (16 * videojuegos[i].precio) / 100;
		videojuegos[i].Total = videojuegos[i].precio + videojuegos[i].impuesto;
		printf("********************************************************************* \n");
	}
}

void Baja()
{
	string nume_baja;
	printf("Ingrese el #item del art%cculo que desea dar de baja \n",161);
	cin.ignore(); //Se utiliza para borrar el espacio que haya quedado al utilizar cin
	getline(cin, nume_baja);
	for (int i = 0; i < alta; i++)
	{
		if (nume_baja == videojuegos[i].num_art)
		{
			printf("Eliminando art%cculo %s \n",161, videojuegos[i].num_art.c_str());
			videojuegos[i].status = "ELIMINADO";
			break;
		}
	}
}

void Modificar()
{
	string nume_mod;
	int opcion,decision;
	printf("Ingrese el #item que desea modificar \n");
	cin.ignore(); //Se utiliza para borrar el espacio que haya quedado al utilizar cin
	getline(cin, nume_mod);
	for (int i = 0; i < alta; i++)
	{
		if (nume_mod == videojuegos[i].num_art) //Compara el item ingresado con los existentes
		{
			if (videojuegos[i].status == "ELIMINADO")
			{
				printf("ARTICULO ELIMINADO, opci%cn invalida \n",162);
				printf("Desea modificar otro articulo: \n1.-SI \n2.-NO \n");
				scanf_s("%d", &decision);
				if (decision == 1)
				{
					return Modificar();
				}
				else
				{
					break;
				}
				return;
			}
			printf("Ingrese que desea modificar: \n%c 1.-Nombre del art%cculo \n%c 2.-Descripci%cn del art%cculo \n%c 3.-G%cnero del art%cculo \n%c 4.-Clasificaci%cn \n%c 5.-Caracter%csticas \n%c 6.-Consola \n%c 7.-A%co \n%c 8.-Precio \n", 16,161, 16,162,161, 16,130,161, 16,162, 16,161,16,16,164,16);
			scanf_s("%d", &opcion);
			cin.ignore(); //Se utiliza para borrar el espacio que haya quedado al utilizar cin

			switch (opcion) //variable a comparar
			{
			case 1: //Nombre del art
				printf("Ingrese el nombre del art%cculo \n",161);
				getline(cin, videojuegos[i].art_nom);
				break;
			case 2: //Descrip del art
				printf("Ingrese la descripci%cn del art%cculo \n",162,161);
				getline(cin, videojuegos[i].descrip);
				break;
			case 3: //Genero del art
				printf("Ingrese el g%cnero del art%cculo \n",130,161);
				getline(cin, videojuegos[i].gender_art);
				break;
			case 4: // Clasi del art
				printf("Ingrese la clasificaci%cn del art%cculo \n",162,161);
				getline(cin, videojuegos[i].clasi_art);
				break;
			case 5: //Caracteristicas del art
				printf("Ingrese las caracter%csticas del art%cculo \n",161, 161);
				getline(cin, videojuegos[i].carac_art);
				break;
			case 6: //Consola
				printf("Ingrese la consola del art%cculo \n",161);
				getline(cin, videojuegos[i].consol_art);
				break;
			case 7: //Año
				printf("Ingrese el a%co de lanzamiento del art%cculo \n",164, 161);
				scanf_s("%d", &videojuegos[i].año_art);
				break;
			case 8: //Precio
				printf("Ingrese el precio del art%cculo \n",161);
				scanf_s("%f", &videojuegos[i].precio);
				videojuegos[i].impuesto = (16 * videojuegos[i].precio) / 100;
				videojuegos[i].Total = videojuegos[i].precio + videojuegos[i].impuesto;
				break;
			default:
				printf("Opcion invalida, porfavor eliga la correcta \n");
				return Modificar();
				break;
			}
		}
	}
}

void Lista()
{
	for (int i = 0; i < alta; i++)
	{
		if (videojuegos[i].status == "ELIMINADO")
		{
			printf("ARTICULO ELIMINADO %s \n", videojuegos[i].num_art.c_str());
		}
		else
		{
			printf("\t ARTICULO #%s \n",videojuegos[i].num_art.c_str());
			printf("NOMBRE: %s \n", videojuegos[i].art_nom.c_str());
			printf("DESCRIPCION: %s \n",videojuegos[i].descrip.c_str());
			printf("G%cNERO: %s \n", 144,videojuegos[i].gender_art.c_str());
			printf("CLASIFICACION: %s \n", videojuegos[i].clasi_art.c_str());
			printf("CARACTERISTICAS: %s \n", videojuegos[i].carac_art.c_str());
			printf("CONSOLA: %s \n", videojuegos[i].consol_art.c_str());
			printf("A%cO: %d \n", 165, videojuegos[i].año_art);
			printf("SUBTOTAL: %f \n", videojuegos[i].precio);
			printf("IMPUESTO: %f \n", videojuegos[i].impuesto);
			printf("TOTAL: %f \n", videojuegos[i].Total);
		}
	}
}

void Archivo()
{
	ofstream archivo; //ofstream para crear archivos de texto
	string nombrearchivo;
	string texto;

	nombrearchivo = "registrotienda.txt";

	archivo.open(nombrearchivo.c_str(), ios::out); //Se utiliza para abrir el archivo

	if (archivo.fail())
	{
		printf("ERROR NO SE PUDO CREAR EL ARCHIVO \n");
		exit(1);
	}

	archivo << "#ITEM" << "\t"<<" ";
	archivo << "NOMBRE" << "\t"<<"\t";
	archivo << "DESCRIPCION" << "\t"<<"\t"<<"\t"<<"\t"<<"\t"<<" ";
	archivo << "GENERO" << "\t"<<"\t"<<"\t"<<" ";
	archivo << "CLASIFICACION" << "    ";
	archivo << "CARCATERISTICAS" << "\t" << "  ";
	archivo << "CONSOLA" << "\t"<<"  ";
	archivo << "LANZAMIENTO"<< "\t" << "  ";
	archivo << "PRECIO TOTAL" << "\n";

	for (int i = 0; i < alta; i++)
	{
		if (videojuegos[i].status == "ELIMINADO")
		{
			texto = "REGISTRO ELIMINADO ";
			archivo << texto <<videojuegos[i].num_art<<"\n";
		}
		else
		{
			archivo << videojuegos[i].num_art << "\t";
			archivo << videojuegos[i].art_nom<< "\t";
			archivo << videojuegos[i].descrip << "\t";
			archivo << videojuegos[i].gender_art<< "\t";
			archivo << videojuegos[i].clasi_art << "\t";
			archivo << videojuegos[i].carac_art << "\t";
			archivo << videojuegos[i].consol_art << "\t";
			archivo << videojuegos[i].año_art << "\t";
			archivo <<"$"<< videojuegos[i].Total << "\n";
		}
	}
	archivo.close(); //Función para cerrar el archivo
}