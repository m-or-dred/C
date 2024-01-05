
#include "nicksLib.h"

void teste2() {
 int
 lista[] = { 12, 23, 45, 67, 89, 90, 112 },
 procurado =  112;
 unsigned long long tamanho = sizeof lista / sizeof lista[0];
 unsigned indice = buscaBin(lista, tamanho, procurado);

 if (!(indice))
  printf("o elemento nao esta no vetor\n");
 else
  printf("o elemento esta na posicao %hhd do vetor\n", indice);
}

//int main() {
// teste2();
//}

/* Procedimento para imprimir os bits de uma variavel inteira */
void printBin(unsigned char a) {
 /* Imprime cada bit da variavel ’a’ */
 for (unsigned i = 8; i > 0; --i) {
  printf("%u", a >> 7);
  a <<= 1;
 }
 printf("\n");
}

//int main() {
// unsigned char a = 10;
// for (unsigned i = 0; i <= 8; i++) {
//  printf("a << %d = %3hhu: ", i, a << i);
//  printBin(a << i); /* Deslocamento de ’i’ posicoes */
// }
//}
