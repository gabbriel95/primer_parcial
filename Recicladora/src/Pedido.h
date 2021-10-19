/*
 * Pedido.h
 *
 *  Created on: 16 oct. 2021
 *      Author: juan
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_

typedef struct
{
	int idPedido;
	int idCliente;
	int idEstado;
	int isEmpty;
	float cantidadKg;
}ePedido;


typedef struct
{
 int idCliente;
 int idPedido;
 float hdpe;
 float ldpe;
 float pp;

}eCantidadPlasticos;


/// @brief muestra un pedido que este pendiente
/// @param recibe un pedido
void mostrarPedido(ePedido listaPedido);

/// @brief inicializa los empty de la lista de pedidos en vacio(1)
/// @param listaPedidos lista de pedidos
/// @param tamPedidos tamaño array de pedidos
int InicializarListaPedidos(ePedido listaPedidos[], int tamPedidos);

/// @brief Analiza el array de pedidos en busca de que al menos uno este en estado lleno (0)
/// @param listaPedidos array de pedidos
/// @param sizepedidos tam array pedidos
/// @return (1) if Ok, (0) Error
int VerificarSiHayUnPedido(ePedido listaPedidos[], int sizePedidos);

/// @brief Verifica si al menos existe un pedido en estado pendiente (1)
/// @param listaPedidos array de pedidos
/// @param sizepedidos tam array pedidos
/// @return (1) if Ok, (0) Error
int VerificarSiHayUnPedidoPendiente(ePedido listaPedidos[], int sizePedidos);

/// @brief verifica si al menos existe un pedido ene stado completado (0)
/// @param listaPedidos array de pedidos
/// @param sizepedidos tam array pedidos
/// @return (1) if Ok, (0) Error
int VerificarSiHayUnPedidoProcesado(ePedido listaPedidos[], int sizePedidos);

#endif /* PEDIDO_H_ */
