/*
 * Nexo_Cliente_Pedido.h
 *
 *  Created on: 16 oct. 2021
 *      Author: juan
 */

#ifndef NEXO_CLIENTE_PEDIDO_H_
#define NEXO_CLIENTE_PEDIDO_H_

#include "Cliente.h"
#include "Pedido.h"


/// @brief Muestra la lista de clientes
/// @param  listaClientes array de clientes
/// @param  sizeClientes tamaño array clientes
/// @param  listaPedidos array de pedidos
/// @param  sizePedidos tamaño array pedidos
/// @return (1) if Ok, (0) Error,
int MostrarListaClientes(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos);

/// @brief Solicita los datos para dar de alta un pedido
/// @param listaClientes array de clientes
/// @param sizeClientes tam array clientes
/// @param listaPedidos array de pedidos
/// @param sizepedidos tam array pedidos
/// @param idPedido puntero a id pedido
/// @return (1) if Ok, (0) error
int AltaPedido(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos, int* idPedido);


/// @brief muestra la lista de pedidos en estado pendiende
/// @param listaPedidos array de pedidos
/// @param sizepedidos tam array pedidos
/// @return (1) if Ok, (0) Error
int MostrarListaPedidos(ePedido listaPedidos[], int sizePedidos);

/// @brief Procesa un pedido pendiente y lo transforma a completo
/// @param listaPedidos array de pedidos
/// @param sizepedidos tam array pedidos
/// @param listaClientes array de clientes
/// @param sizeclientes tam array clientes
/// @param listaCantidadPlasticos array con las cantidades de cada material que fue reciclado por pedido
/// @return (1) if Ok, (0) Error
int ProcesarPedido(ePedido listaPedidos[], int sizePedidos,
					eCliente listaClientes[], int sizeClientes, eCantidadPlasticos listaCantidadPlasticos[]);

/// @brief Muestra por consola los pedidos que estan pendientes
/// @param listaClientes array de clientes
/// @param sizeclientes tam array clientes
/// @param listaPedidos array de pedidos
/// @param sizepedidos tam array pedidos
/// @return (1) if Ok, (0) Error
int ImprimirPedidosPendientes(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos);

/// @brief Muestra por consola los pedidos que estan completados
/// @param listaClientes array de clientes
/// @param sizeclientes tamaño array clientes
/// @param listaPedidos array de pedidos
/// @param sizepedidos tam array pedidos
/// @param listaCantidades array de cantidades de cada plastico para cada pedido
/// @return (1) if Ok, (0) Error
int MostrarPedidosProcesados(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos, eCantidadPlasticos listaCantidades[]);

/// @brief Calcula el promedio de polipropileno que se reciclo entre los clientes
/// @param listaCLientes array de clientes
/// @param sizeCllientes tam array clientes
/// @param listapedidos array de pedidos
/// @param sizepedidos tam array de pedidos
/// @param listaACumuladores array paralelo al array de pedidos, tiene los datos de cada cantidad de plasticos que se reciclo por pedido
/// @return (1) if Ok, (0) Error,
int PromedioPolipropilenoXCliente(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos, eCantidadPlasticos listaAcumuladores[], int* contador);

/// @brief Calcula la cantidad de pedidos que hay en una localidad
/// @param listaClientes array de clientes
/// @param sizeclientes tam del array de clientes
/// @param listapedidos array de pedidos
/// @param sizepedidos tam array de pedidos
/// @return (1) if Ok, (0) Error
int CantidadPedidosPorLocalidad(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos);

#endif /* NEXO_CLIENTE_PEDIDO_H_ */
