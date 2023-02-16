#include <iostream> //bliblioteca de trabajo
#include <string> //uso del string

using namespace std; //espacio de trabajo

int main() //función
{
	string num_art,art_nom, descrip, gender_art, clasi_art, consol_art; //declaración de variables
	int opc,decision;
	float precio, Total, impuesto;

	cout << "\t ***MENU DE OPCIONES*** \n";
	cout << "1.-Alta de articulos \n";
	cout << "2.-Modificacion de articulos \n";
	cout << "3.-Baja de articulos \n";
	cout << "4.-Lista de articulos \n";
	cout << "5.-Limpiar pantalla \n";
	cout << "6.-Salir \n";
	cin >> opc; //variable a comparar con los casos
	
	switch (opc) 
	{
	case 1:
		cin.ignore(); //Se utiliza para poder las variables tipo string
		cout<<"Ingresa el #item del articulo \n";
		getline(cin, num_art);
		cout<<"Ingresa el nombre del articulo \n";
		getline(cin, art_nom);
		cout<< "Inrese la descripcion del articulo \n";
		getline(cin, descrip);
		cout<< "Ingresa el genero del articulo \n";
		getline(cin, gender_art);
		cout<<"Ingresa la clasificacion del articulo \n";
		getline(cin, clasi_art);
		cout<<"Ingresa la consola del articulo \n";
		getline(cin, consol_art);
		cout << "Ingrese el precio del articulo \n";
		cin >> precio;
		impuesto = (16 * precio)/100;
		Total = precio + impuesto;
		cout << "El precio es: " << precio << "\n";
		cout << "El impuesto es de: " << impuesto << "\n";
		cout << "El precio total es de: " << Total << "\n";
		cout << "Desea agregar otro articulo, 1-SI 2-NO \n";
		cin >> decision;
		if (decision == 1)
		{
			return main();
		}
		else
		{
			cout << "Gracias, vuelva pronto \n";
			break;
		}
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		system("cls");
		return main();
		break;
	case 6:
		exit(1);
		break;
	default:
		cout << "Opcion invalida \n";
		return main();
		break;
	}
	
}