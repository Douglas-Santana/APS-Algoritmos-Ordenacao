# Implementação e Análise de Algoritmos de Ordenação 📈

![Status: Concluído](https://img.shields.io/badge/status-concluído-brightgreen)
![Linguagem](https://img.shields.io/badge/linguagem-C-blue)

Este é um projeto acadêmico desenvolvido para a Atividade Prática Supervisionada (APS) do curso de Ciência da Computação da Universidade Paulista (UNIP).

O objetivo principal é implementar, analisar e comparar o desempenho de três algoritmos de ordenação fundamentais: **Bubble Sort**, **Insertion Sort** e **Quick Sort**.

O programa, escrito em Linguagem C, funciona como um banco de testes (*benchmark*) que cronometra o tempo de execução de cada algoritmo ao ordenar um vetor de 30.000 números aleatórios. O projeto demonstra na prática a diferença de complexidade e eficiência entre os algoritmos $O(n^2)$ (Bubble e Insertion) e o $O(n \log n)$ (Quick Sort)

## 🚀 Funcionalidades

* **Menu interativo** via console.
* **Comparação de 3 algoritmos:** Bubble Sort, Insertion Sort e Quick Sort.
* **Geração de dados:** O programa cria vetores idênticos com 30.000 números aleatórios para garantir uma comparação justa entre os algoritmos.
* **Medição de performance:** Cronômetro de alta precisão (em milissegundos) para cada operação de ordenação.
* **Relatório de Desempenho:** Uma opção no menu exibe um resumo dos tempos gastos por cada algoritmo já executado.
* **Verificação de Ordenação:** Inclui uma função de Busca Binária para que o usuário possa pesquisar um número e confirmar que o vetor foi ordenado corretamente.

## ⚙️ Tecnologias Utilizadas

* **Linguagem C**

## 🏁 Como Executar

1.  **Pré-requisitos:** É necessário ter um compilador C (como o **GCC**/**MinGW**) instalado e configurado no PATH do sistema.

2.  **Clonar o repositório:**
    ```bash
    git clone [https://github.com/SEU-USUARIO/NOME-DO-REPOSITORIO.git](https://github.com/SEU-USUARIO/NOME-DO-REPOSITORIO.git)
    cd NOME-DO-REPOSITORIO
    ```

3.  **Compilar o programa (via terminal):**
    ```bash
    gcc aps.c -o aps
    ```

4.  **Executar o programa:**
    * No Linux / macOS:
        ```bash
        ./aps
        ```
    * No Windows (PowerShell):
        ```bash
        .\aps
        ```

5.  Siga as instruções do menu para testar os algoritmos e ver os resultados.

## 🎓 Autores

Este projeto foi desenvolvido por:

* Douglas Fonseca de Santana.
* Guilherme Augusto de Oliveira

### Professor Orientador
* Prof. Álvaro.

### Coordenador 
* Mario.
