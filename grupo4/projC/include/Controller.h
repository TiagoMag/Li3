/**
 * @file Controller.h
 * @author Grupo4
 * @date Abril 2020
 * @brief Ficheiro que contém declaração de funções e macros que primitem manipular o Controller.
 *  
 */

#ifndef Controller_H
#define Controller_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "interface.h"
#include "Input.h"
#include "View.h"
#include "Navegador.h"


/* @brief Interação entre sistema e utilizador.
 * 
 *  @return Int para continuar ou sair.
 */
int runController();

#endif