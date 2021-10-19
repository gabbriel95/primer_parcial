#include "Nexo_Cliente_Pedido.h"

int MostrarListaClientes(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos)
{
	int retorno =0;

	if(listaClientes !=NULL && sizeClientes > 0 && listaPedidos != NULL && sizePedidos > 0)
	{
		retorno =1;
		if(VerificarSiHayUnCliente(listaClientes, sizeClientes) == 1)
		{
			printf("ID 		EMPRESA 		   CUIT 		  DIRECCION 		 LOCALIDAD 		 PEDIDOS PENDIENTES\n");
			for(int i = 0; i<sizeClientes;i++)
			{
				mostrarCliente(listaClientes[i]);
			}

		}
		else
		{
			printf("Todavia no se ingresaron clientes\n");
		}

	}

	return retorno;
}


int MostrarListaPedidos(ePedido listaPedidos[], int sizePedidos)
{
	int retorno = 0;
	if(listaPedidos != NULL && sizePedidos > 0)
	{
		retorno = 1;
		printf("ID Pedido    Cantidad Kg	ID Cliente\n");


			for(int i=0; i<sizePedidos; i++)
			{

					mostrarPedido(listaPedidos[i]);

			}


	}
	return retorno;
}








int AltaPedido(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos, int* idPedido)
{
	int idClienteAux;
	int retorno = 0;
	int flag= 0;
		if(listaClientes != NULL && sizeClientes > 0 && listaPedidos != NULL && sizePedidos > 0)
		{
			retorno = 1;
			// VALIDAR ID INGRESADO
			Utn_GetNumero(&idClienteAux, "Ingrese el ID del cliente: ", "Error, a ingresado letras, o un id fuera de rango\n", 1, INT_MAX, 3);

			for(int j=0; j<sizeClientes;j++)
			{
				if(idClienteAux == listaClientes[j].idCliente)
				{
					flag = 1;
					listaClientes[j].contadorPendientes++;
				}

			}

			if(flag == 1)
			{
				printf("Se a encontrado el ID\n");
				for(int i=0; i<sizePedidos; i++)
				{
					if(listaPedidos[i].isEmpty == 1)
					{
						Utn_GetNumeroFlotante(&listaPedidos[i].cantidadKg, "Ingrese la cantidad de KG totales a recolectar : ", "Error, a ingresado letras o fuera del rango\n", 1, INT_MAX, 3);
						listaPedidos[i].isEmpty = 0;
						listaPedidos[i].idPedido = GeneradorId(idPedido);
						listaPedidos[i].idEstado = 1;
						listaPedidos[i].idCliente = idClienteAux;
						break;

					}
				}
			}
			else
			{
				printf("El id ingresado no existe en la base de datos\n");
			}


		}

		return retorno ;
}


int ProcesarPedido(ePedido listaPedidos[], int sizePedidos,
					eCliente listaClientes[], int sizeClientes, eCantidadPlasticos listaPlasticos[])
{
	int idPedido;
	int retorno = 0;

	if(listaPedidos != NULL && sizePedidos > 0 && listaClientes != NULL && sizeClientes > 0 && listaPlasticos != NULL)
	{
		retorno = 1;
		MostrarListaPedidos(listaPedidos, sizePedidos);


		printf("Ingrese el ID del pedido a procesar: ");
		GetInt(&idPedido);

				for(int j=0;j<sizeClientes;j++)//MODIFIQUE
				{
					for(int i=0; i<sizePedidos;i++)
					{
						if(listaClientes[j].idCliente == listaPedidos[i].idCliente && listaPedidos[i].idPedido == idPedido)
						{
							listaClientes[j].contadorPendientes--;
						}
					}
				}


				for(int i=0; i<sizePedidos; i++)
				{
					if(listaPedidos[i].idPedido == idPedido)
					{
						printf("Ingrese la cantidad de Polietileno de alta densidad que pudo reciclarse: ");
						GetFloat(&listaPlasticos[i].hdpe);
						printf("Ingrese la cantidad de Polietileno de baja densidad que pudo reciclarse: ");
						GetFloat(&listaPlasticos[i].ldpe);
						printf("Ingrese la cantidad de Polietileno que pudo reciclarse: ");
						GetFloat(&listaPlasticos[i].pp);
						listaPlasticos[i].idCliente = listaPedidos[i].idCliente;
						listaPlasticos[i].idPedido = listaPedidos[i].idPedido;
						listaPedidos[i].idEstado = 0;
					}

			}

	}


return retorno;
}


int ImprimirPedidosPendientes(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos)
{
	int retorno = 0;
	if(listaClientes != NULL && sizeClientes >0 && listaPedidos != NULL && sizePedidos > 0)
	{
		retorno = 1;
		if(VerificarSiHayUnPedidoPendiente(listaPedidos, sizePedidos)  == 1)
		{
			for(int i=0; i<sizePedidos ;i++)
			{
				if(listaPedidos[i].idEstado == 1)
				{
					if(i==0)
					{
						printf("Lista de pedidos pendientes\n\n");
						printf("ID PEDIDO      CUIT CLIENTE     DIRECCION CLIENTE     CANTIDAD KG a recolectar\n");

					}

					for(int j=0; j<sizeClientes ; j++)
					{
						if(listaPedidos[i].idCliente == listaClientes[j].idCliente && listaPedidos[i].isEmpty != 1)
						{
							printf("%5d %20s %20s %20.2f\n", listaPedidos[i].idPedido, listaClientes[j].cuitEmpresa, listaClientes[j].direccionEmpresa, listaPedidos[i].cantidadKg);
							break;
						}
					}
				}
			}

		}
		else
		{
			printf("\nNo hay pedidos pendientes que mostrar\n");
		}

	}
	return retorno;
}

int MostrarPedidosProcesados(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos, eCantidadPlasticos listaCantidades[])
{
	int retorno = 0;
	if(listaClientes != NULL && sizeClientes > 0 && listaPedidos != NULL && sizePedidos > 0 && listaCantidades != NULL)
	{
		retorno =1;
		if(VerificarSiHayUnPedidoProcesado(listaPedidos, sizePedidos) == 1)
		{
			for(int i=0; i<sizePedidos;i++)
			{
				if(listaPedidos[i].idEstado == 0)
				{
					if(i==0)
					{
						printf("Lista de pedidos pendientes\n\n");
						printf("ID PEDIDO     CUIT CLIENTE       DIRECCION CLIENTE     KG HDPE        KG LDPE         KGPP\n");

					}
					for(int j=0; j<sizeClientes;j++)
					{
						if(listaPedidos[i].idCliente == listaClientes[j].idCliente && listaPedidos[i].isEmpty != 1)
						{
							printf("%5d %20s %20s %14.2f %12.2f %14.2f\n", listaPedidos[i].idPedido, listaClientes[j].cuitEmpresa, listaClientes[j].direccionEmpresa, listaCantidades[i].hdpe, listaCantidades[i].ldpe, listaCantidades[i].pp);
							break;
						}
					}

				}
			}

		}
		else
		{
			printf("\nNo hay pedidos completos para mostrar\n");
		}

	}
	return retorno;
}

int PromedioPolipropilenoXCliente(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos, eCantidadPlasticos listaAcumuladores[], int* contador)
{
	float acumuladorPp = 0;
	int contadorClientes = *contador;
	float promedio;
	int retorno = 0;

	if(listaClientes != NULL && sizeClientes > 0 && listaPedidos != NULL && sizePedidos > 0 && listaAcumuladores != NULL)
	{
		retorno = 1;
		for(int j=0; j<sizePedidos; j++)
			{
				for(int i=0;i<sizeClientes;i++)
				{
					if(listaClientes[i].idCliente == listaPedidos[j].idCliente && listaClientes[i].idCliente == listaAcumuladores[j].idCliente && listaPedidos[j].idEstado == 0)
					{
						if(listaClientes[i].isEmpty == 0 && listaClientes[i].flag == 0)
						{
							contadorClientes ++;
							listaClientes[i].flag = 1;
						}
						acumuladorPp = acumuladorPp + listaAcumuladores[j].pp;
						break;
					}
				}


			}

			*contador = contadorClientes;

			if(contadorClientes != 0)
			{
				promedio = acumuladorPp / contadorClientes;
			}

			printf("El promedio de polipropileno por cliente es %.2f",promedio);

	}

	return retorno;
}

int CantidadPedidosPorLocalidad(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos)
{
	int retorno = 0;
	if(listaClientes != NULL && sizeClientes > 0 && listaPedidos != NULL && sizePedidos > 0)
	{
		retorno = 1;
		if(VerificarSiHayUnPedidoPendiente(listaPedidos, sizePedidos) == 1)
		{
			char localidad[TCADENA];
			int acumuladorPendientes = 0;
			PedirCadenaChars(localidad, TCADENA, "Ingrese una localidad", "Error", 3);

			for(int i=0; i<sizeClientes;i++)
			{
				if(strcmp(localidad, listaClientes[i].localidadEmpresa) == 0)
				{
					acumuladorPendientes = acumuladorPendientes + listaClientes[i].contadorPendientes;
				}
			}

			printf("En %s hay %d pedidos pendientes", localidad, acumuladorPendientes);

		}
		else
		{
			printf("No hay pedidos pendientes");
		}

		}

	return retorno;
}
