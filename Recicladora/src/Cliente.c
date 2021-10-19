#include "Cliente.h"
#include "Input.h"

void InicializarListaClientes(eCliente listaClientes[], int tamClientes)
{

		for(int i=0; i<tamClientes; i++)
		{
			listaClientes[i].isEmpty = 1;
			listaClientes[i].contadorPendientes = 0;
		}

}


int VerificarSiHayUnCliente(eCliente listaClientes[], int tamClientes)
{
	int retorno = 0;

	for(int i=0; i<tamClientes;i++)
	{
		if(listaClientes[i].isEmpty == 0)
		{
			retorno = 1;
			break;
		}
	}

	return retorno;
}


int CargaDeClientes(eCliente listaClientes[], int tamClientes, int* idCliente)
{
	int retorno = 0;
	if(listaClientes != NULL && tamClientes >0)
	{
		retorno = 1;
		for(int i=0; i<tamClientes; i++)
		{
			if(listaClientes[i].isEmpty == 1)
			{
				if(
					PedirCadenaChars(listaClientes[i].nombreEmpresa, TCADENA, "Ingrese el nombre de la empresa\n", "Error, supero la cantidad de caracteres\n", 3) == 1 &&
				   cargarCuit(listaClientes[i].cuitEmpresa, 3) == 1 &&
				   PedirAlphaNumerico(listaClientes[i].direccionEmpresa, TCADENA, "Ingrese la direccion de la empresa\n", "Error, supero la cantidad de caracteres\n", 3) == 1 &&
				   PedirCadenaChars(listaClientes[i].localidadEmpresa, TCADENA, "Ingrese la localidad de la empresa\n", "Error, supero la cantidad de caracteres\n", 3) == 1
				  )
				{
					listaClientes[i].isEmpty = 0;
					listaClientes[i].idCliente = GeneradorId(idCliente);
					listaClientes[i].contadorPendientes = 0;
					listaClientes[i].flag = 0;
				}
				else
				{
					printf("Error en la carga de un dato, no se pudo cargar el cliente, intente nuevamente");
				}

				break;
			}
		}
	}
	return retorno;
}

int ModificarDatosClientes(eCliente listaClientes[], int tamClientes)
{
	int idAux;
	int respuesta;
	int flag = 0;
	int retorno =0;

	if(listaClientes !=NULL && tamClientes > 0)
	{
		retorno = 1;
		if(VerificarSiHayUnCliente(listaClientes, tamClientes) == 1)
		{
			Utn_GetNumero(&idAux, "Ingrese el ID del empleado que desea modificar: ", "Error, a ingresado letras, o un id fuera de rango\n", 1, INT_MAX, 3);

			for(int i=0; i<tamClientes; i++)
			{
				if(listaClientes[i].idCliente == idAux && listaClientes[i].isEmpty == 0)
				{
					printf("Se a encontrado al cliente con el id %d", idAux);
					Utn_GetNumero(&respuesta, " ¿Qué desea modificar? \n 1-Dirección \n 2-Localidad\n 3-Direccion y Localidad\n Respuesta: ", "Opcion incorrecta\n", 1, 3, 3);
					flag = 1;

					switch(respuesta)
					{
					case 1:
						PedirAlphaNumerico(listaClientes[i].direccionEmpresa, TCADENA, "Ingrese la direccion de la empresa\n", "Error, supero la cantidad de caracteres\n", 3);
						break;
					case 2:
						PedirCadenaChars(listaClientes[i].localidadEmpresa, TCADENA, "Ingrese la localidad de la empresa\n", "Error, supero la cantidad de caracteres\n", 3);
						break;
					case 3:
						PedirAlphaNumerico(listaClientes[i].direccionEmpresa, TCADENA, "Ingrese la direccion de la empresa\n", "Error, supero la cantidad de caracteres\n", 3);
						PedirCadenaChars(listaClientes[i].localidadEmpresa, TCADENA, "Ingrese la localidad de la empresa\n", "Error, supero la cantidad de caracteres\n", 3);
						break;
					}
				}
			}

			if(flag == 0)
			{
				printf("El ID N° %d no se encuentra en la base de datos\n", idAux);
			}
		}

		}

	return retorno;
}

int BajaDeClientes(eCliente listaClientes[], int tamClientes)
{
	int idAux;
	int respuesta;
	int flag = 0;
	int retorno  = 0;

	if(listaClientes !=NULL && tamClientes > 0)
	{
		retorno = 1;
		if(VerificarSiHayUnCliente(listaClientes, tamClientes) == 1)
		{
			Utn_GetNumero(&idAux, "Ingrese el ID del empleado que desea eliminar: ", "Error, a ingresado letras, o un id fuera de rango\n", 1, INT_MAX, 3);

			for(int i=0; i<tamClientes; i++)
			{
				if(listaClientes[i].idCliente == idAux && listaClientes[i].isEmpty == 0)
				{
					printf("Se a encontrado al cliente con el id %d", idAux);
					Utn_GetNumero(&respuesta, " ¿Esta seguro que desea eliminarlo? \n 1-Si \n 2-No\n Respuesta: ", "Opcion incorrecta\n", 1, 2, 3);
					flag = 1;

					switch(respuesta)
					{
					case 1:
						listaClientes[i].isEmpty = 1;
						break;
					case 2:
						break;
					}
				}
			}

			if(flag == 0)
			{
				printf("El ID N° %d no se encuentra en la base de datos\n", idAux);
			}
		}

	}

	return retorno;
}



int mostrarCliente(eCliente listaClientes)
{
	int retorno = 0;

				if(listaClientes.isEmpty == 0)
				{

					printf("%1d %20s %30s %20s %20s %25d\n", listaClientes.idCliente, listaClientes.nombreEmpresa, listaClientes.cuitEmpresa,
												  listaClientes.direccionEmpresa, listaClientes.localidadEmpresa, listaClientes.contadorPendientes);
				}



	return retorno;
}


