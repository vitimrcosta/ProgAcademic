#include <stdio.h>        // Inclui a biblioteca padrão de entrada e saída.
#include <string.h>      // Inclui a biblioteca para manipulação de strings.
#include <locale.h>      // Inclui a biblioteca para definir a localidade.
#include <windows.h>     // Inclui a biblioteca para funções específicas do Windows.
#include <ctype.h>       // Inclui a biblioteca para manipulação de caracteres.

#define MAX_DISCIPLINAS 50        // Define o número máximo de disciplinas.
#define MAX_PREREQUISITOS 10      // Define o número máximo de pré-requisitos por disciplina.
#define MAX_SEMESTRES 10          // Define o número máximo de semestres no curso.
#define MAX_ATIVIDADES 100        // Define o número máximo de atividades na agenda.

// Enumeração para o tipo da disciplina (Obrigatória ou Optativa).
typedef enum {
    Obrigatoria,
    Optativa
} TipoDisciplina;

// Estrutura para representar uma disciplina.
typedef struct {
    char codigo[10];                // Código da disciplina.
    char titulo[100];               // Título da disciplina.
    int cargaHoraria;               // Carga horária da disciplina.
    int semestre;                   // Semestre em que a disciplina é oferecida.
    char prerequisitos[MAX_PREREQUISITOS][10]; // Lista de pré-requisitos.
    int numPrerequisitos;           // Número de pré-requisitos.
    TipoDisciplina tipo;            // Tipo da disciplina (Obrigatória ou Optativa).
} Disciplina;

// Estrutura para representar a matriz curricular do curso.
typedef struct {
    Disciplina disciplinas[MAX_DISCIPLINAS]; // Array de disciplinas.
    int numSemestres;                         // Número total de semestres no curso.
} MatrizCurricular;

// Estrutura para representar uma disciplina matriculada por um aluno.
typedef struct {
    char codigo[10];   // Código da disciplina matriculada.
    int semestre;      // Semestre em que a disciplina foi matriculada.
} DisciplinaMatriculada;

// Estrutura para representar o histórico de disciplinas matriculadas de um aluno.
typedef struct {
    DisciplinaMatriculada disciplinasMatriculadas[MAX_DISCIPLINAS]; // Array de disciplinas matriculadas.
    int numMatriculas; // Número total de matrículas do aluno.
} Historico;

// Estrutura para representar uma atividade (como uma tarefa ou projeto).
typedef struct {
    char descricao[100]; // Descrição da atividade.
    char data[11];       // Data da atividade no formato dd/mm/aaaa.
} Atividade;

// Estrutura para representar uma agenda de atividades.
typedef struct {
    Atividade atividades[MAX_ATIVIDADES]; // Array de atividades.
    int numAtividades;                     // Número total de atividades na agenda.
} Agenda;


// Função para remover espaços em branco do início e do fim de uma string
void trim(char *str) {
    // Remover espaços à esquerda
    while (isspace((unsigned char)*str)) str++; // Move o ponteiro 'str' para a direita enquanto houver espaços

    // Remover espaços à direita
    char *end = str + strlen(str) - 1; // Ponteiro 'end' aponta para o último caractere da string
    while (end > str && isspace((unsigned char)*end)) end--; // Move o ponteiro 'end' para a esquerda enquanto houver espaços

    // Null-terminar a string (adiciona o caractere nulo no final)
    *(end + 1) = '\0'; // Define o caractere nulo após o último caractere não-espaço
}

// Função para listar atividades da agenda
void listarAtividades(Agenda agenda) {
    printf("\nAtividades:\n"); // Cabeçalho para a listagem de atividades
    for (int i = 0; i < agenda.numAtividades; i++) { // Loop através das atividades armazenadas na agenda
        // Exibe a descrição e a data de cada atividade
        printf("Descrição: %s, Data: %s\n", agenda.atividades[i].descricao, agenda.atividades[i].data);
    }
}

// Função para cadastrar disciplina matriculada
void cadastrarDisciplinaMatriculada(Historico *historico, Disciplina disciplina) {
    // Verifica se ainda há espaço para novas disciplinas no histórico
    if (historico->numMatriculas < MAX_DISCIPLINAS) {
        // Copia o código da disciplina para o histórico
        strcpy(historico->disciplinasMatriculadas[historico->numMatriculas].codigo, disciplina.codigo);
        // Armazena o semestre da disciplina matriculada
        historico->disciplinasMatriculadas[historico->numMatriculas].semestre = disciplina.semestre;
        // Incrementa o número de matrículas
        historico->numMatriculas++;
        printf("Disciplina %s matriculada com sucesso!\n", disciplina.titulo); // Mensagem de sucesso
    } else {
        // Mensagem de erro se o limite de disciplinas for atingido
        printf("Limite de disciplinas matriculadas atingido!\n");
    }
}

// Função para listar disciplinas matriculadas
void listarDisciplinasMatriculadas(Historico historico) {
    printf("\nDisciplinas Matriculadas:\n"); // Cabeçalho para a listagem de disciplinas matriculadas
    for (int i = 0; i < historico.numMatriculas; i++) { // Loop através do histórico de matrículas
        // Exibe o código e o semestre de cada disciplina matriculada
        printf("Código: %s, Semestre: %d\n", historico.disciplinasMatriculadas[i].codigo, historico.disciplinasMatriculadas[i].semestre);
    }
}

// Função para cadastrar uma atividade na agenda
void cadastrarAtividade(Agenda *agenda, const char *descricao, const char *data) {
    // Verifica se ainda há espaço para novas atividades
    if (agenda->numAtividades < MAX_ATIVIDADES) {
        // Copia a descrição da atividade para a agenda
        strcpy(agenda->atividades[agenda->numAtividades].descricao, descricao);
        // Copia a data da atividade para a agenda
        strcpy(agenda->atividades[agenda->numAtividades].data, data);
        // Incrementa o número de atividades
        agenda->numAtividades++;
        // Mensagem de sucesso ao cadastrar a atividade
        printf("Atividade '%s' cadastrada com sucesso!\n", descricao);
    } else {
        // Mensagem de erro se o limite de atividades for atingido
        printf("Limite de atividades atingido!\n");
    }
}

// Função para apresentar a matriz curricular com paginação baseada no semestre de entrada
void apresentarMatrizCurricularPorSemestrePaginado(Disciplina disciplinas[], int quantidade, int semestreEntrada, int itensPorPagina) {
    printf("\nMatriz Curricular a partir do Semestre %d:\n", semestreEntrada); // Cabeçalho da matriz curricular
    printf("--------------------------------------------------------------------------------\n");

    // Contar o número de disciplinas a partir do semestre de entrada
    int disciplinasFiltradas = 0; // Inicializa o contador de disciplinas filtradas
    for (int i = 0; i < quantidade; i++) { // Loop para contar disciplinas a partir do semestre de entrada
        if (disciplinas[i].semestre >= semestreEntrada) { // Se a disciplina é oferecida no semestre desejado ou posterior
            disciplinasFiltradas++; // Incrementa o contador
        }
    }

    int pagina = 0; // Inicializa a página atual
    // Calcula o total de páginas necessárias com base na quantidade de disciplinas filtradas
    int totalPaginas = (disciplinasFiltradas + itensPorPagina - 1) / itensPorPagina;

    while (1) { // Loop infinito para navegação de páginas
        // Exibe a página atual e o total de páginas
        printf("\nPágina %d de %d\n", pagina + 1, totalPaginas);
        printf("--------------------------------------------------------------------------------\n");

        // Exibir as disciplinas da página atual
        int mostradas = 0; // Contador de disciplinas mostradas
        for (int i = 0, exibidas = 0; i < quantidade && exibidas < itensPorPagina; i++) {
            // Verifica se a disciplina está no semestre desejado
            if (disciplinas[i].semestre >= semestreEntrada) {
                // Se as disciplinas mostradas estão dentro da faixa da página atual
                if (mostradas >= pagina * itensPorPagina && exibidas < itensPorPagina) {
                    // Exibe os detalhes da disciplina
                    printf("Código: %s\nTítulo: %s\nCarga Horária: %d\nSemestre: %d\n",
                           disciplinas[i].codigo,
                           disciplinas[i].titulo,
                           disciplinas[i].cargaHoraria,
                           disciplinas[i].semestre);
                    printf("--------------------------------------------------------------------------------\n");
                    exibidas++; // Incrementa o contador de disciplinas exibidas
                }
                mostradas++; // Incrementa o contador de disciplinas mostradas
            }
        }

        // Navegação da página
        printf("\nDigite 'n' para a próxima página, 'p' para a anterior, ou 's' para sair: ");
        char opcao; // Variável para armazenar a opção do usuário
        scanf(" %c", &opcao); // Lê a opção do usuário

        // Lógica para navegar entre as páginas
        if (opcao == 'n' && pagina < totalPaginas - 1) {
            pagina++; // Avança para a próxima página
        } else if (opcao == 'p' && pagina > 0) {
            pagina--; // Retorna para a página anterior
        } else if (opcao == 's') {
            break; // Sai do loop se o usuário escolher sair
        } else {
            // Mensagem de erro para opções inválidas
            printf("Opção inválida!\n");
        }
    }
}

// Função para listar disciplinas com paginação
void listarDisciplinasPaginado(Disciplina disciplinas[], int quantidade, int itensPorPagina) {
    int pagina = 0; // Inicializa a página atual
    // Calcula o total de páginas necessárias com base na quantidade de disciplinas
    int totalPaginas = (quantidade + itensPorPagina - 1) / itensPorPagina;

    while (1) { // Loop infinito para navegação de páginas
        // Exibe a página atual e o total de páginas
        printf("\nPágina %d de %d\n", pagina + 1, totalPaginas);
        int inicio = pagina * itensPorPagina; // Índice de início para a página
        int fim = inicio + itensPorPagina;     // Índice de fim para a página
        if (fim > quantidade) fim = quantidade; // Ajusta o fim se exceder a quantidade

        // Exibe as disciplinas da página atual
        for (int i = inicio; i < fim; i++) { // Loop para exibir as disciplinas
            printf("Código: %s, Nome: %s\n", disciplinas[i].codigo, disciplinas[i].titulo);
        }

        // Navegação da página
        printf("\nDigite 'n' para a próxima página, 'p' para a anterior, ou 's' para sair: ");
        char opcao; // Variável para armazenar a opção do usuário
        scanf(" %c", &opcao); // Lê a opção do usuário

        // Lógica para navegar entre as páginas
        if (opcao == 'n' && pagina < totalPaginas - 1) {
            pagina++; // Avança para a próxima página
        } else if (opcao == 'p' && pagina > 0) {
            pagina--; // Retorna para a página anterior
        } else if (opcao == 's') {
            break; // Sai do loop se o usuário escolher sair
        } else {
            // Mensagem de erro para opções inválidas
            printf("Opção inválida!\n");
        }
    }
}

// Função para exibir o menu
void exibirMenu() {
    // Exibe o cabeçalho do menu
    printf("\n--- Menu ---\n");
    printf("1. Listar Disciplinas\n"); // Opção para listar disciplinas
    printf("2. Matricular em uma Disciplina\n"); // Opção para matricular em uma disciplina
    printf("3. Listar Disciplinas Matriculadas\n"); // Opção para listar disciplinas matriculadas
    printf("4. Cadastrar Atividade na Agenda\n"); // Opção para cadastrar atividade na agenda
    printf("5. Mostrar Agenda\n"); // Opção para mostrar a agenda
    printf("6. Apresentar Matriz Curricular (Baseado no Semestre de Entrada)\n"); // Opção para apresentar matriz curricular
    printf("0. Sair\n"); // Opção para sair do programa
}


// Função principal
int main() {
    // Configura a localidade para exibir caracteres especiais corretamente
    setlocale(LC_ALL, "Portuguese_Brazil.UTF-8");
    // Configura o console para usar codificação UTF-8
    SetConsoleOutputCP(CP_UTF8);

    FILE *arq; // Ponteiro para o arquivo
    // Abre o arquivo binário de disciplinas para leitura
    arq = fopen("disciplinas.bin", "rb");
    // Verifica se houve erro ao abrir o arquivo
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo disciplinas.bin\n");
        return 1; // Sai do programa em caso de erro
    }

    // Move o ponteiro do arquivo para o final e obtém o tamanho do arquivo
    fseek(arq, 0, SEEK_END);
    long tamanhoArquivo = ftell(arq); // Armazena o tamanho do arquivo
    rewind(arq); // Retorna o ponteiro para o início do arquivo
    // Calcula a quantidade de registros (disciplinas) no arquivo
    int quantidadeRegistros = tamanhoArquivo / sizeof(Disciplina);
    Disciplina disciplinas[quantidadeRegistros]; // Array para armazenar as disciplinas lidas do arquivo
    // Lê as disciplinas do arquivo
    fread(disciplinas, sizeof(Disciplina), quantidadeRegistros, arq);
    fclose(arq); // Fecha o arquivo após a leitura

    // Inicializa o histórico e a agenda
    Historico historico = { .numMatriculas = 0 };
    Agenda agenda = { .numAtividades = 0 };

    int opcao; // Variável para armazenar a opção do menu
    char descricao[100], data[11]; // Variáveis para descrição e data da atividade
    int semestreEntrada; // Variável para o semestre de entrada

    do {
        exibirMenu(); // Exibe o menu de opções
        printf("Escolha uma opção: ");
        scanf("%d", &opcao); // Lê a opção escolhida pelo usuário
        getchar(); // Limpa o buffer de entrada

        switch (opcao) {
            case 1:
                // Chama a função para listar disciplinas com paginação (5 disciplinas por página)
                listarDisciplinasPaginado(disciplinas, quantidadeRegistros, 5);
                break;

            case 2:
                // Solicita o código da disciplina para matrícula
                printf("Digite o código da disciplina para matricular: ");
                char codigo[10];
                fgets(codigo, sizeof(codigo), stdin); // Lê o código da disciplina
                codigo[strcspn(codigo, "\n")] = 0; // Remove a nova linha

                // Procura a disciplina correspondente ao código informado
                for (int i = 0; i < quantidadeRegistros; i++) {
                    if (strcmp(disciplinas[i].codigo, codigo) == 0) { // Compara o código
                        // Se encontrado, cadastra a disciplina matriculada
                        cadastrarDisciplinaMatriculada(&historico, disciplinas[i]);
                        break; // Sai do loop após a matrícula
                    }
                }
                break;

            case 3:
                // Chama a função para listar disciplinas matriculadas
                listarDisciplinasMatriculadas(historico);
                break;

            case 4:
                // Solicita a descrição da atividade
                printf("Digite a descrição da atividade: ");
                fgets(descricao, sizeof(descricao), stdin); // Lê a descrição da atividade
                descricao[strcspn(descricao, "\n")] = 0; // Remove a nova linha

                // Solicita a data da atividade
                printf("Digite a data da atividade (dd/mm/aaaa): ");
                fgets(data, sizeof(data), stdin); // Lê a data da atividade
                data[strcspn(data, "\n")] = 0; // Remove a nova linha

                // Cadastra a atividade na agenda
                cadastrarAtividade(&agenda, descricao, data);
                break;

            case 5:
                // Chama a função para listar as atividades cadastradas na agenda
                listarAtividades(agenda);
                break;

            case 6:
                // Solicita o semestre de entrada do aluno
                printf("Digite o seu semestre de entrada: ");
                scanf("%d", &semestreEntrada);
                // Chama a função para apresentar a matriz curricular com base no semestre de entrada (5 itens por página)
                apresentarMatrizCurricularPorSemestrePaginado(disciplinas, quantidadeRegistros, semestreEntrada, 5);
                break;

            case 0:
                // Mensagem de saída do programa
                printf("Saindo...\n");
                break;

            default:
                // Mensagem de erro para opção inválida
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0); // Continua o loop até que a opção escolhida seja 0 (sair)

    return 0; // Retorna 0 ao sistema, indicando que o programa terminou com sucesso
}