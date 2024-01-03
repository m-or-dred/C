#include <stdio.h>

void ordena_3(int a, int b, int c) {
    if      (a < b && b < c) printf("(%d %d %d)\n", a, b, c);
    else if (a < c && c < b) printf("(%d %d %d)\n", a, c, b);
    else if (b < a && a < c) printf("(%d %d %d)\n", b, a, c);
    else if (b < c && c < a) printf("(%d %d %d)\n", b, c, a);
    else if (c < a && a < b) printf("(%d %d %d)\n", c, a, b);
    else                     printf("(%d %d %d)\n", c, b, a);
}
void loop(int num) {
    int acc = 0, n = 0;
    while (num) acc += num, n++, scanf("%d", &num);
    printf("lidos: %d\ntotal: %d\nmedia: %d", n, acc, acc/n);
}
void list_num() {
    int size; scanf("%d", &size);
    float list[size], num;
    for (int i = 0; i  < size; i++) scanf("%f", &list[i]);
    for (int i = 0; i  < size; i++) printf("%f ", list[i]);
}
void evens_0_to_100() {
    for (unsigned char n = 0; n < 100; n++) if (!(n % 2)) printf("%d ", n);
}
void drawSquareX(unsigned char ordem) {
    for (unsigned char x = 0; x < ordem; x++) {
        for (unsigned char y = 0; y < ordem; y++) {
            if (x == 0 || x == ordem - 1 || y == 0 || y == ordem - 1 || y == x || y + x == ordem - 1) printf("*   ");
            else printf("    ");
        }
        printf("\n");
    }
}
void drawFullDiamond()
{
    int ordem;
    printf("ordem\n");
    scanf("%d", &ordem);
    if (ordem % 2)
    {
        for (int x = 0; x < ordem - ordem / 2; x++)
        {
            printf("%d\t", x);
            for (int y = 0; y < ordem; y++)
            {
                if (y >= ordem / 2 - x && y <= ordem / 2 + x)
                {
                    printf("%d ", y);
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
        for (int x = ordem - ordem / 2; x < ordem; x++)
        {
            printf("%d\t", x);
            for (int y = 0; y < ordem; y++)
            {
                if (y >= x - ordem / 2 && y <= (ordem - 1) - (x - ordem / 2))
                {
                    printf("%d ", y);
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
    else
    {
        for (int x = 0; x < ordem - ordem / 2; x++)
        {
            printf("%d\t", x);
            for (int y = 0; y < ordem; y++)
            {
                if (y >= ordem / 2 - x - 1 && y <= ordem / 2 + x)
                {
                    printf("%d ", y);
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
        for (int x = ordem - ordem / 2; x < ordem; x++)
        {
            printf("%d\t", x);
            for (int y = 0; y < ordem; y ++)
            {
                if (y >= x - ordem / 2 && y <= ordem - 1 - (x - ordem / 2))
                {
                    printf("%d ", y);
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
}
void drawHorizontalStrips()
{
    int length, rows, start;
    printf("number of rows, high and start: (0: skip first; 1: fill first):\n");
    scanf("%d %d %d", &rows, &length, &start);
    if (start)
    {
        for (int row = 0; row < rows; row++)
        {
            printf("%d\t", row);
            if (!(row % 2))
            {
                for (int collumn = 0; collumn < length; collumn++)
                {
                    printf("%d ", collumn);
                }
            }
            printf("\n");
        }
    }
    else
    {
        for (int row = 0; row < rows; row++)
        {
            printf("%d\t", row);
            if (row % 2)
            {
                for (int collumn = 0; collumn < length; collumn++)
                {
                    printf("%d ", collumn);
                }
            }
            printf("\n");
        }
    }
}
void drawEmptyDiamond()
{
    int ordem;
    printf("ordem\n");
    scanf("%d", &ordem);
    if (ordem % 2) {
        for (int x = 0; x < ordem; x++) {
            printf("%d\t", x);
            for (int y = 0; y < ordem; y++) {
                if (y == ordem / 2 +- x ||
                    //                    y == ordem / 2 + x ||
                    y == ordem / 2 - ordem + x + 1 ||
                    y == ordem / 2 + ordem - x - 1)
                    printf("%d ", y);
                else
                    printf("  ");
            }
            printf("\n");
        }
    }
    else {
        for (int x = 0; x < ordem; x++) {
            printf("%d\t", x);
            for (int y = 0; y < ordem; y++) {
                if (y == ordem / 2 - x - 1 ||
                    y == ordem / 2 + x ||
                    y == ordem / 2 - ordem + x ||
                    y == ordem / 2 + ordem - x - 1)
                    printf("%d ", y);
                else
                    printf("  ");
            }
            printf("\n");
        }
    }
}
void drawVerticalStrips()
{
    int rows, collumns, start;
    printf("number of rows and collumns and start value: (0: skip first; 1: fill first)\n");
    scanf("%d%d%d", &rows, &collumns, &start);
    if (start)
    {
        for (int row = 0; row < rows; row++)
        {
            printf("%d\t", row);
            for (int collumn = 0; collumn < collumns; collumn++)
            {
                if (collumn % 2)
                {
                    printf("\\");
                }
                else
                {
                    printf("/");
                }
            }
            printf("\n");
        }
    }
    else
    {
        for (int row = 0; row < rows; row++)
        {
            printf("%d\t", row);
            for (int collumn = 0; collumn < collumns; collumn++)
            {
                if (collumn % 2)
                {
                    printf("/");
                }
                else
                {
                    printf("\\");
                }
            }
            printf("\n");
        }
    }
}
void drawEmptyTriangle()
{
    int base;
    printf("base\n");
    scanf("%d", &base);
    if (base % 2)
    {
        for (int x = -1; x < base / 2; x++)
        {
            if (x == base / 2 - 1)
            {
                for (int y = 0; y < base; y++)
                {
                    printf("* ");
                }
                break;
            }
            for (int y = 0; y < base; y++)
            {
                if (y == base / 2 - x - 1 || y == base / 2 + x + 1)
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
    else
    {
        for (int x = -1; x < base / 2; x++)
        {
            if (x == base / 2 - 1)
            {
                for (int y = -1; y < base; y++)
                {
                    printf("* ");
                }
                break;
            }
            for (int y = 0; y < base; y++)
            {
                if (y == base / 2 - x - 1 || y == base / 2 + x + 1)
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
}
void drawFullTriangle()
{
    int base;
    printf("base\n");
    scanf("%d", &base);
    if (base % 2)
    {
        for (int x = -1; x < base / 2; x++)
        {
            if (x == base / 2 - 1)
            {
                for (int y = 0; y < base; y++)
                {
                    printf("* ");
                }
                break;
            }
            for (int y = 0; y < base; y++)
            {
                if (y >= base / 2 - x - 1 && y <= base / 2 + x + 1)
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
    else
    {
        for (int x = -1; x < base / 2; x++)
        {
            if (x == base / 2 - 1)
            {
                for (int y = -1; y < base; y++)
                {
                    printf("* ");
                }
                break;
            }
            for (int y = 0; y < base; y++)
            {
                if (y >= base / 2 - x - 1 && y <= base / 2 + x + 1)
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
}
void drawGrading(unsigned side, unsigned start) {
    if (start) {
        for (int x = 0; x < side; x++) {
            if (x % 2) {
                for (int y = 0; y < side; y++) {
                    if (y % 2) printf("x   ");
                    else       printf("o   ");
                }
            }
            else {
                for (int y = 0; y < side; y++) {
                    if (y % 2) printf("o   ");
                    else printf("x   ");
                }
            }
            printf("\n");
        }
    }
    else {
        for (int x = 0; x < side; x++) {
            if (x % 2) {
                for (int y = 0; y < side; y++) {
                    if (y % 2) printf("o   ");
                    else       printf("x   ");
                }
            }
            else {
                for (int y = 0; y < side; y++) {
                    if (y % 2) printf("x   ");
                    else       printf("o   ");
                }
            }
            printf("\n");
        }
    }
}
void menorMaior(unsigned quantidade) {
//    printf("quantidade de numeros: %u\n", quantidade);
    float numero; scanf("%f", &numero);
    float menor = numero, maior = numero;
    for (unsigned lidos = 1; lidos < quantidade; lidos++) {
        scanf("%f", &numero);
        if      (numero < menor) menor = numero;
        else if (numero > maior) maior = numero;
    }
    printf("menor: %.2f\nmaior: %.2f", menor, maior);
}
void menorMaiorPar(unsigned quantidade) {
//    printf("quantidade de numeros: %u\n", quantidade);
    int numero; scanf("%d", &numero); unsigned char lidos = 1;
    for (; numero % 2 && lidos < quantidade; lidos++) scanf("%d", &numero);
    int menor = numero, maior = numero;
    for (; lidos < quantidade; lidos++) {
        scanf("%d", &numero);
        if (!(numero % 2)) {
            if      (numero < menor) menor = numero;
            else if (numero > maior) maior = numero;
        }
    }
    if (menor % 2) printf("nao houve par");
    else           printf("menor par: %d\nmaior par: %d", menor, maior);
}
void testFormula(unsigned n) {
    unsigned formula = (2*n*n*n + 3*n*n + n)/6, iteration = 1;
    for (unsigned i = 2; i <= n; i++) iteration += i * i;
    if (formula == iteration) printf("formula:   %d\niteration: %d\nformula works", formula, iteration);
}
unsigned long long powerN(unsigned char number, unsigned char expoent) {
    unsigned long long k = 1;
    for (unsigned long long i = 0; i < expoent; i++) k *= number;
    return k;
}
void doisElevadoA(unsigned n) {
    for (; n >= 1; n--) printf("%llu | ", powerN(2, n));
    printf("%llu", powerN(2, n));
}
void contruirVetor(unsigned tamanho) {
    char lista[tamanho];
    for (unsigned i = 0; i < tamanho; ++i) scanf("%hhd", &lista[i]);
}
void selectionSort(int vet[], int lenVet) {
    for (int x = lenVet - 1; x > 0; --x) {
        int n = 0;
        int y = 1;
        for (; y < x + 1; ++y) {
            if (vet[n] < vet[y]) n = y;
        }
        int z = x;
        vet[x] = vet[n];
        vet[y] = vet[z];
    }
}
float maiorDoVetor(float vetor[], int tamanho) {
    float maior = vetor[0];
    for (int i = 1; i < tamanho; i++) if (vetor[i] > maior) maior = vetor[i];
    return maior;
}
