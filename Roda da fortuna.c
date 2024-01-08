
/*
* Trabalho 2 de SL (2023-2024) :-)
* Dupla:
* Nicolas Mady Corrêa Gomes
* Fernando Lucas Almeida Nascimento
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPCOES  (char) 0b00010000 // 16
#define MINIMO  (char) 0b11111000 // -8
#define MAXIMO  (char) 0b00000111 //  7
#define CHANCES (char) 0b00000100 //  4

char
resposta,
sua_sorte,
fortuna_infortunio_,
sortes[] = { 0b11111000, 0b11111001, 0b11111010, 0b11111011,   // { -8, -7, -6, -5,
             0b11111100, 0b11111101, 0b11111110, 0b11111111,   //   -4, -3, -2, -1,
             0b00000000, 0b00000001, 0b00000010, 0b00000011,   //    0,  1,  2,  3,
             0b00000100, 0b00000101, 0b00000110, 0b00000111 }; //    4,  5,  6,  7 }

void
inicio(),
roda_da_fortuna(char fortuna_infortunio, char chances);

int main() {
 inicio();
 return 0;
}

void inicio() {
 printf("Como o jogo funciona:\n"
        "1. Gire a roda e receba uma sorte inicial aleatoria (nao pode ficar com ela).\n"
        "2. Gire a roda novamente e some a sorte inicial com a sorte que cair.\n"
        "3. Sendo -8 a pior sorte e 7 a melhor, desejo-lhe a melhor sorte!\n"
        "4. Voce tem %hhd chances para tentar melhorar sua sorte.\n"
        "Pressione ENTER para girar a roda", CHANCES);
 scanf("%c", &resposta);

 srand(time(NULL));
 sua_sorte = sortes[rand() % OPCOES];
 printf("Sua sorte: %hhd\nPressione ENTER para girar novamente", sua_sorte);
 scanf("%c", &resposta);

 fortuna_infortunio_ = sortes[rand() % OPCOES];
 printf("Sua sorte: %hhd\n", fortuna_infortunio_);
 fortuna_infortunio_ += sua_sorte;

 if (fortuna_infortunio_ < MINIMO)
  fortuna_infortunio_ += OPCOES;
 else if (fortuna_infortunio_ > MAXIMO)
  fortuna_infortunio_ -= OPCOES;

 if (fortuna_infortunio_ >= 0)
  printf("Fortuna!: %hhd\n", fortuna_infortunio_);
 else
  printf("Infortunio!: %hhd\n", fortuna_infortunio_);

 printf("Voce tem %hhd chance(s)\n(1) jogar ou (0) parar?", CHANCES);
 scanf("%hhd", &resposta);
 if (resposta)
  roda_da_fortuna(fortuna_infortunio_, CHANCES);
 else
  printf("Sorte final: %hhd", fortuna_infortunio_);
}

void roda_da_fortuna(char fortuna_infortunio, char chances) {
 printf("Fortuna ou infortunio, o que vai ser?\nPressione ENTER para girar a roda");
 scanf("%c%*c", &resposta);

 for (char tentativa = 0; tentativa < chances; tentativa++) {
  sua_sorte = sortes[rand() % OPCOES];
  printf("Sua sorte: %hhd\n", sua_sorte);
  fortuna_infortunio += sua_sorte;

  if (fortuna_infortunio < MINIMO)
   fortuna_infortunio += OPCOES;
  else if (fortuna_infortunio > MAXIMO)
   fortuna_infortunio -= OPCOES;

  if (fortuna_infortunio >= 0)
   printf("Fortuna!: %hhd\n", fortuna_infortunio);
  else
   printf("Infortunio!: %hhd\n", fortuna_infortunio);

  if (tentativa == chances - 1)
   break;
  printf("Voce tem %hhd chance(s)\n(1) continuar ou (0) parar?", chances - tentativa - 1);
  scanf("%hhd", &resposta);
  if (!resposta)
   break;
 }
 printf("Sorte final: %hhd", fortuna_infortunio);
}
