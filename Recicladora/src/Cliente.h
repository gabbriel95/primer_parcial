/*
 * Cliente.h
 *
 *  Created on: 16 oct. 2021
 *      Author: juan
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_


#include "Input.h"

typedef struct
{
	char nombreEmpresa[51];
	char cuitEmpresa[12];
	char direccionEmpresa[51];
	char localidadEmpresa[51];
	int idCliente;
	int isEmpty;
	int contadorPendientes;
	int flag;

}eCliente;

/// @brief
/// @param
/// @return (1) if Ok, (0) Error, no son numeros
int mostrarCliente(eCliente listaClientes);



/// @brief Inicializa la lista de clientes, cambia su estado a vacio y su contador pendiente a 0
/// @param listaClientes es la lista clientes
/// @param tamaño de la lista de clientes
void InicializarListaClientes(eCliente listaClientes[], int tamClientes);

/// @brief verifica que al menos exista un cliente
/// @param listaClientes array de los clientes
///@param tamClientes tamaño del array de clientes
/// @return(1) ok --- return(0) Error
int VerificarSiHayUnCliente(eCliente listaClientes[], int tamClientes);

/// @brief Solicita los datos de un cliente y los carga
/// @param listaClientes array de clientes
/// @param tamClientes  tamaño de array clientes
/// @param idcliente puntero a id de clientes
/// @return return(1) ok --- return(0) Error
int CargaDeClientes(eCliente listaClientes[], int tamClientes, int* idCliente);

/// @brief Modifica los datos de un cliente
/// @param listaClientes array de clientes
/// @param tamClientes es el tamaño del array
/// @return (1) if Ok, (0) Error, no son numeros
int ModificarDatosClientes(eCliente listaClientes[], int tamClientes);

/// @brief Da de baja un cliente, de la lista de clientes
/// @param listaClientes Array de cllientes
/// @param tamClientes tamaño array clientes
/// @return (1) if Ok, (0) Error, no son numeros
int BajaDeClientes(eCliente listaClientes[], int tamClientes);


#endif /* CLIENTE_H_ */
