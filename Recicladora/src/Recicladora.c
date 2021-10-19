#include <stdio.h>
#include <stdlib.h>

#include "Input.h"
#include "Cliente.h"
#include "Pedido.h"
#include "Nexo_Cliente_Pedido.h"


int main(void) {

	setbuf(stdout, NULL);

	eCliente listaClientes[TAM_CLIENTES];


	ePedido listaPedidos[TAM_PEDIDOS];


	eCantidadPlasticos listaCantidadesPlastico[TAM_PEDIDOS];

	int opcion;
	int idCliente = 0;
	int idPedidos = 0;
	int contadorPp= 0;


	InicializarListaClientes(listaClientes, TAM_CLIENTES);
	InicializarListaPedidos(listaPedidos, TAM_PEDIDOS);

	do{
		printf(
				"\n1- Alta cliente\n"
				"2- Modificar datos de cliente\n"
				"3- Baja cliente\n"
				"4- Crear pedido de recoleccion\n"
				"5- Procesar residuos\n"
				"6- Imprimir clientes\n"
				"7- Imprimir pedidos pendientes\n"
				"8- Imprimir pedidos procesados\n"
				"9- Pedidos pendientes por localidad\n"
				"10- Promedio de kilos de polipropileno reciclado por cliente\n"
				"11- Salir\n");

		if(Utn_GetNumero(&opcion, "\nSeleccione una opcion: ", "\nError, a seleccionado una opcion no valida.\n", 1, 11, 3)==1)
		{
			switch(opcion){
					case 1:
						CargaDeClientes(listaClientes, TAM_CLIENTES, &idCliente);
						break;
					case 2:
						MostrarListaClientes(listaClientes, TAM_CLIENTES, listaPedidos, TAM_PEDIDOS);
						ModificarDatosClientes(listaClientes, TAM_CLIENTES);
						break;
					case 3:
						MostrarListaClientes(listaClientes, TAM_CLIENTES, listaPedidos, TAM_PEDIDOS);
						BajaDeClientes(listaClientes, TAM_CLIENTES);
						break;
					case 4:
						MostrarListaClientes(listaClientes, TAM_CLIENTES, listaPedidos, TAM_PEDIDOS);
						AltaPedido(listaClientes, TAM_CLIENTES, listaPedidos, TAM_PEDIDOS, &idPedidos);
						break;
					case 5:
						ProcesarPedido(listaPedidos, TAM_PEDIDOS, listaClientes, TAM_PEDIDOS, listaCantidadesPlastico);
						break;
					case 6:
						MostrarListaClientes(listaClientes, TAM_CLIENTES, listaPedidos, TAM_PEDIDOS);
						break;
					case 7:
						ImprimirPedidosPendientes(listaClientes, TAM_CLIENTES, listaPedidos, TAM_PEDIDOS);
						break;
					case 8:
						MostrarPedidosProcesados(listaClientes, TAM_CLIENTES, listaPedidos, TAM_PEDIDOS, listaCantidadesPlastico);
						break;
					case 9:
						CantidadPedidosPorLocalidad(listaClientes, TAM_CLIENTES,listaPedidos, TAM_PEDIDOS);
						break;
					case 10:
						PromedioPolipropilenoXCliente(listaClientes, TAM_CLIENTES, listaPedidos, TAM_PEDIDOS, listaCantidadesPlastico, &contadorPp);
						break;
					case 11:
						printf("Gracias vuelva pronto");
						break;
				}

		}
		else
		{
			 break;
		}

		}while(opcion !=11);

	return EXIT_SUCCESS;
}
