#include "Pedido.h"
#include "Input.h"


int InicializarListaPedidos(ePedido listaPedidos[], int tamPedidos)
{
	int retorno  = 0;
	if(listaPedidos != NULL && tamPedidos > 0)
	{
		retorno = 1;
		for(int i=0; i<tamPedidos; i++)
		{
			listaPedidos[i].isEmpty = 1;
		}
	}

	return retorno;
}




void mostrarPedido(ePedido listaPedido)
{

		if(listaPedido.isEmpty == 0 && listaPedido.idEstado == 1)
		{
				printf("%5d %16.2f %16d\n", listaPedido.idPedido, listaPedido.cantidadKg, listaPedido.idCliente);
		}

}

int VerificarSiHayUnPedido(ePedido listaPedidos[], int sizePedidos)
{
	int retorno = 0;

	if(listaPedidos != NULL && sizePedidos > 0)
	{
		retorno = 1;
		for(int i=0; i<sizePedidos;i++)
		{
			if(listaPedidos[i].isEmpty == 0)
			{
				retorno = 1;
				break;
			}
		}

	}

	return retorno;
}

int VerificarSiHayUnPedidoPendiente(ePedido listaPedidos[], int sizePedidos)
{
	int retorno = 0;

	if(listaPedidos != NULL && sizePedidos > 0)
		{
			retorno = 1;
			for(int i=0; i<sizePedidos;i++)
			{
				if(listaPedidos[i].idEstado == 1)
				{
					retorno = 1;
					break;
				}
			}
		}

	return retorno;
}

int VerificarSiHayUnPedidoProcesado(ePedido listaPedidos[], int sizePedidos)
{
	int retorno = 0;

	if(listaPedidos != NULL && sizePedidos > 0)
		{
			for(int i=0; i<sizePedidos;i++)
			{
				if(listaPedidos[i].idEstado == 0)
				{
					retorno = 1;
					break;

				}
			}
		}
	return retorno;
}
