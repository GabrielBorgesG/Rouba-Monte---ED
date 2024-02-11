#ifndef _MESA_H_
#define _MESA_H_

#include "listas.h"
#include "pilhas.h"

#define TAMANHO_MESA 8

typedef ListaEnc2 Mesa;

Mesa* criaMesa(Pilha *baralho);

void imprimeMesa(Mesa* mesa);

#endif