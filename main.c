
// Dupla: Nicolas Mady e Fernando Lucas

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPCOES 16
#define MIN -8
#define MAX 7
#define TENTATIVAS 4

char
resposta,
sua_sorte,
fortuna_infortunio,
sortes[] = { -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7 };

void
roda_da_fortuna_(),
roda_da_fortuna(char fortuna_infortunio, char tentativas);

void roda_da_fortuna_() {

 printf("Como o jogo funciona:\n"
        "1. Gire a roda e receba uma sorte inicial aleatoria (nao pode ficar com ela).\n"
        "2. Gire a roda novamente e some a sorte que caiu com a inicial.\n"
        "3. Voce tem %hhd tentativas para tentar melhorar sua sorte.\n"
        "Pressione ENTER para girar a roda", TENTATIVAS);
 scanf("%c", &resposta);

 srand(time(NULL));
 sua_sorte = sortes[rand() % OPCOES];
 printf("Sua sorte: %hhd\nPressione ENTER para girar novamente", sua_sorte);
 scanf("%c", &resposta);

 fortuna_infortunio = sortes[rand() % OPCOES];
 printf("Sua sorte: %hhd\n", fortuna_infortunio);
 fortuna_infortunio += sua_sorte;

 if      (fortuna_infortunio < MIN) fortuna_infortunio += OPCOES;
 else if (fortuna_infortunio > MAX) fortuna_infortunio -= OPCOES;

 if (fortuna_infortunio >= 0) printf("Fortuna!: %hhd\n", fortuna_infortunio);
 else                         printf("Infortunio!: %hhd\n", fortuna_infortunio);

 printf("Voce tem %hhd tentativas\n(1) jogar ou (2) parar?", TENTATIVAS);
 scanf("%hhd", &resposta);
 if (resposta == 1) roda_da_fortuna(fortuna_infortunio, TENTATIVAS - 1);
 else printf("Sorte final: %hhd", fortuna_infortunio);
}

void roda_da_fortuna(char fortuna_infortunio, char tentativas) {
 printf("Fortuna ou infortunio, o que vai ser?\nPressione ENTER para girar a roda");
 scanf("%c%*c", &resposta);

 for (char tentativa = 0; tentativa <= tentativas; ++tentativa) {
  sua_sorte = sortes[rand() % OPCOES];
  printf("Sua sorte: %hhd\n", sua_sorte);
  fortuna_infortunio += sua_sorte;

  if      (fortuna_infortunio < MIN) fortuna_infortunio += OPCOES;
  else if (fortuna_infortunio > MAX) fortuna_infortunio -= OPCOES;

  if (fortuna_infortunio >= 0) printf("Fortuna!: %hhd\n", fortuna_infortunio);
  else                         printf("Infortunio!: %hhd\n", fortuna_infortunio);

  if (tentativa == tentativas) break;
  printf("Voce tem %hhd tentativa(s)\n(1) continuar ou (2) parar?", tentativas - tentativa);
  scanf("%hhd", &resposta);
  if (resposta == 2) break;
 }
 printf("Sorte final: %hhd", fortuna_infortunio);
}

int main() {
 roda_da_fortuna_();
}
