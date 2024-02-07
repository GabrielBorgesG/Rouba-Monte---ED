gcc -c lista_circ.c
gcc -c pilha_enc.c
gcc -c Rouba_monte.c
gcc -c lista_enc_dupla.c

gcc pilha_enc.o lista_enc_dupla.o lista_circ.o Rouba_monte.o programa.o -o jogo.exe

.\jogo.exe