#include <iostream>
#include <fstream>

using namespace std;

//Declaro las constantes universales

const int dimensionPersonas {8};
const int dimensionProductos {5};

//Funcion usada en el punto 2 (Calcula el maximo)

int maximo(int vec[], int dim)
{
	int max {};
	for (int i = 1; i < dim; i++)
		if (vec[i] > vec[max])
			max = i;
	return max;
}

int main()
{

  //Declarolas variables - vectores - matrices

    int codigoCliente;
    int codigoProducto;
    int productocliente[dimensionPersonas]{};
    int prodMayor {0};
    int cantidadEntregas[dimensionProductos]{};

    double DatosPeso[dimensionPersonas][dimensionProductos]{};
    double DatosKilometros[dimensionPersonas][dimensionProductos]{};
    double datosCant[dimensionProductos];

    float KmDeProducto;
    float KgDeProducto;

    string nom[dimensionPersonas]{};
    string prod[dimensionProductos]{};

    // Abro los archivos de datos

    ifstream archilecNombres;
    archilecNombres.open ("nombres.txt");

    for (int i = 0; i < dimensionPersonas && archilecNombres >> nom[i]; ++i);
	for (int i = 0; i < dimensionProductos && archilecNombres >> prod[i]; ++i);

    archilecNombres.close();

    ifstream archilecDatos;
    archilecDatos.open("Datos.txt");


    // Hago una lectura de datos

    while (archilecDatos >> codigoCliente >> codigoProducto >> KgDeProducto >> KmDeProducto)
    {
        DatosPeso[codigoCliente][codigoProducto] += KgDeProducto;
        DatosKilometros[codigoCliente][codigoProducto] += KmDeProducto;
        cantidadEntregas[codigoProducto]++;
    }

    archilecDatos.close();



    // 1)Emita un listado donde para cada cliente liste los tipos de producto tal que la cantidad total de
    //   kilos transportados es mayor a 13000.



    for (int i = 0; i < dimensionPersonas; i++)
    {
        for (int x = 0; x < dimensionProductos ; x++)
        {
            if (DatosPeso[i][x] > 13000)
            {
                cout << nom[i] << " Vende: " << prod[x] << endl;
                productocliente[i]++;
            }
        }
    }
    cout << endl << "..............................................." << endl << endl;

    // 2) Para el cliente con mayor cantidad tipos de productos que hayan superado 13000 kg en el punto
    //    anterior, emita un listado con nombre de tipo de producto y total de kilómetros recorridos,
    //    ordenado por total de kilómetros en forma ascendente.


    int mayorproducto = maximo(productocliente, dimensionPersonas);
    cout << "La Persona con mas ventas superiores a 13000kg es: " << nom[mayorproducto] << "." << endl;

    for (int i = 0; i < dimensionProductos; i++)
    {
        if(DatosPeso[mayorproducto][i] > 13000 )
        {
            cout << endl << prod[i] << ": " << "\t" << "\t" << DatosKilometros[mayorproducto][i] << " km." << endl ;
        }
    }

    cout << endl << "..............................................." << endl << endl;

    // 3) Del listado anterior, tome el tipo de producto con mayor cantidad de kilómetros recorridos e
    //    informe cuantas entregas se hicieron para ese tipo de producto (sin importar para que cliente)


    for (int i = 0; i < dimensionProductos; i++)
    {
        cout << endl<< prod[i] << " hizo: " << "\t" << cantidadEntregas[i] << " entregas" <<endl;
    }



 return 0;
}
