#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>   
#include <stdbool.h>

// Definir tamanho dos vetores
#define tam 30000

// Apontadores para os laços de repetição
int i, j;
// Verificadores para saber se a opção já foi escolhida
bool a, c, d; 

typedef struct
{
    int vetor1[tam]; // Bubble
    int vetor3[tam]; // Insert
    int vetor4[tam]; // Quick

    // Usamos double para ter precisão decimal
    double bubble_time;
    double insert_time;
    double quick_time;
} Vetores;

// Função para limpar a tela de forma portatil
void limparTela() {
#ifdef _WIN32
    system("cls"); // Comando do Windows
#else
    system("clear"); // Comando do Linux/macOS
#endif
}

// Função para pausar o console de forma portatil
void pausarConsole() {
    printf("\nPressione Enter para continuar...\n");
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    getchar();
}

Vetores preencher(Vetores v)
{
    srand(time(NULL)); 
    for (i = 0; i < tam; i++)
    {
        v.vetor1[i] = rand() % tam;
        v.vetor3[i] = v.vetor1[i];
        v.vetor4[i] = v.vetor1[i];
    }
    return v;
}

void mostrarTela(int *vetor, int numeroVetor)
{
    printf("\n==== VETOR %d ORDENADO ====\n", numeroVetor);
}

void buscaBinaria(int *vetor)
{
    int achou = 0, inicio = 0, fim = tam - 1, meio, busca;
    printf("\nEntre com o inteiro a ser pesquisado: ");
    scanf("%d", &busca);
    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == busca)
        {
            achou = 1;
            break; 
        }
        if (busca < vetor[meio])
            fim = meio - 1;
        else
            inicio = meio + 1;
    }
    
    limparTela();
    
    if (achou == 1)
        printf("\nAchou o valor %d \n", busca);
    else
        printf("\nNao achou o valor %d \n", busca);
}

void bubbleSort(int *vetor)
{
    int aux;
    for (i = 0; i < tam - 1; i++)
    {
        for (j = i + 1; j < tam; j++)
        {
            if (vetor[i] > vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void insertSort(int *vetor)
{
    int chave;
    for (i = 1; i < tam; i++)
    {
        chave = vetor[i];
        j = i - 1;
        while ((j >= 0) && (vetor[j] > chave))
        {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

void quicksort(int *vetor, int began, int end)
{
    int i, j, pivo, aux;
    i = began;
    j = end - 1;
    pivo = vetor[(began + end) / 2];
    while (i <= j)
    {
        while (vetor[i] < pivo && i < end)
        {
            i++;
        }
        while (vetor[j] > pivo && j > began)
        {
            j--;
        }
        if (i <= j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    if (j > began)
        quicksort(vetor, began, j + 1);
    if (i < end)
        quicksort(vetor, i, end);
}

void interface(bool a, bool c, bool d)
{
    char string[20] = " (JA USADO)";
    printf("\n ---------------------------------------\n");
    printf("| Qual funcao voce deseja fazer?     |\n");
    
    if (!a) printf("| 1) Bubble Sort                        |\n");
    else    printf("| 1) Bubble Sort%s         |\n", string);

    if (!c) printf("| 2) Insertion Sort                     |\n");
    else    printf("| 2) Insertion Sort%s      |\n", string);

    if (!d) printf("| 3) Quick Sort                         |\n");
    else    printf("| 3) Quick Sort%s          |\n", string);

    // MUDANÇA AQUI: Alterado de 5 para 4
    printf("| 4) Obter dados das opcoes escolhidas  |\n");
    printf("| 0) Sair                               |\n");
    printf(" ---------------------------------------\n");
}

// Seleciona uma determinada opção para fazer a consulta de sort escolhida a partir do Switch
void opcaoSort(Vetores v)
{
    int opcao = -1;

    while (opcao != 0)
    {
        clock_t inicio, fim; 
        interface (a, c, d); 

        scanf("%d", &opcao);
        char str[20] = ""; 
        switch (opcao)
        {
        case 1:
            if (a)
            {
                limparTela();
                printf("Essa opcao ja foi executada! \n");
            }
            else
            {
                inicio = clock();
                bubbleSort(v.vetor1);
                fim = clock();
                mostrarTela(v.vetor1, 1);
                strcpy(str, "Bubble Sort");
                
                v.bubble_time = ((double)(fim - inicio) * 1000) / CLOCKS_PER_SEC; 
                
                buscaBinaria(v.vetor1);
                
                printf("\nTempo de ordenacao por %s: %.2f milisegundos\n", str, v.bubble_time); 
                
                a = true;
                pausarConsole();
                limparTela();
            }
            break;

        case 2:
            if (c)
            {
                limparTela();
                printf("Essa opcao ja foi executada! \n");
            }
            else
            {
                inicio = clock();
                insertSort(v.vetor3);
                fim = clock();
                mostrarTela(v.vetor3, 3);
                strcpy(str, "Insert Sort");
                
                v.insert_time = ((double)(fim - inicio) * 1000) / CLOCKS_PER_SEC; 
                
                buscaBinaria(v.vetor3);
                
                printf("\nTempo de ordenacao por %s: %.2f milisegundos\n", str, v.insert_time); 
                
                c = true;
                pausarConsole();
                limparTela();
            }
            break;

        case 3:
            if (d)
            {
                limparTela();
                printf("Essa opcao ja foi executada! \n");
            }
            else
            {
                inicio = clock();
                quicksort(v.vetor4, 0, tam);
                fim = clock();
                mostrarTela(v.vetor4, 4);
                strcpy(str, "Quick Sort");
                
                v.quick_time = ((double)(fim - inicio) * 1000) / CLOCKS_PER_SEC; 
                
                buscaBinaria(v.vetor4);
                
                printf("\nTempo de ordenacao por %s: %.2f milisegundos\n", str, v.quick_time); 
                
                d = true;
                pausarConsole();
                limparTela();
            }
            break;

        // MUDANÇA AQUI: Alterado de 5 para 4
        case 4:
            limparTela(); 
            if (!a && !c && !d)
            {
                printf("\nNenhuma opcao ainda foi executada!\n");
            }
            
            if (a)
                printf("Tempo de ordenacao por Bubble Sort: %.2f milisegundos\n\n", v.bubble_time);
            if (c)
                printf("Tempo de ordenacao por Insert Sort: %.2f milisegundos\n\n", v.insert_time);
            if (d)
                printf("Tempo de ordenacao por Quick Sort:  %.2f milisegundos\n\n", v.quick_time);
            
            pausarConsole();
            limparTela();
            break;

        case 0:
            limparTela();
            printf("Saindo do programa...\n");
            break;

        default:
            limparTela();
            printf("Opcao Invalida! \n");
            pausarConsole();
            limparTela();
            break;
        }
    }
}
int main()
{
    limparTela();
    printf("\n          Bem Vindo ao programa!\n");
    Vetores v;      
    v = preencher(v); 
    opcaoSort(v);     
    
    return 0;
}