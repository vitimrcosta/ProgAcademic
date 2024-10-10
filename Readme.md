# Sistema de Gestão Acadêmica

Este é um programa simples de gestão acadêmica para um aluno universitário. Ele permite o cadastro e gerenciamento de disciplinas e atividades, além de exibir a matriz curricular baseada no semestre de entrada. O sistema também possui funcionalidade de paginação para facilitar a visualização de grandes listas de disciplinas.

## Funcionalidades

1. **Listar Disciplinas Disponíveis**  
   Exibe uma lista de todas as disciplinas disponíveis.

2. **Matricular em uma Disciplina**  
   Permite ao aluno se matricular em disciplinas disponíveis com base em seu código.

3. **Listar Disciplinas Matriculadas**  
   Exibe uma lista das disciplinas nas quais o aluno está atualmente matriculado.

4. **Cadastrar Atividade na Agenda**  
   Permite ao aluno registrar atividades e compromissos acadêmicos com uma descrição e uma data.

5. **Mostrar Agenda**  
   Exibe todas as atividades e compromissos cadastrados na agenda do aluno.

6. **Apresentar Matriz Curricular (Baseado no Semestre de Entrada)**  
   Mostra a matriz curricular a partir do semestre de entrada do aluno, utilizando paginação para organizar a visualização quando há muitas disciplinas.

## Estrutura do Programa

O programa é estruturado em torno de vários componentes principais:

- **Disciplinas**: Representa as informações sobre cada disciplina, incluindo código, nome, carga horária, semestre, pré-requisitos e tipo (obrigatória ou optativa).
  
- **Histórico**: Gerencia as disciplinas em que o aluno já se matriculou.
  
- **Agenda**: Gerencia as atividades acadêmicas do aluno.
  
- **Matriz Curricular**: Organiza as disciplinas por semestre e permite apresentar ao aluno a sequência correta de disciplinas conforme seu semestre de entrada.

## Requisitos

- Sistema operacional Windows (para o uso de `windows.h` no console).
- Compilador C (por exemplo, GCC ou MinGW para compilar o código no Windows).
- Arquivo binário `disciplinas.bin`, que contém as disciplinas oferecidas pelo curso.

## Como Executar

1. **Compilação**: Compile o programa utilizando um compilador C. Exemplo de comando no terminal:

   ```bash
   gcc sistema_academico.c -o sistema_academico


## Como Utilizar

Ao executar o programa, um menu será exibido com as seguintes opções

1. **Listar Disciplinas**: 
   Lista todas as disciplinas disponíveis no arquivo disciplinas.bin.

2. **Matricular em uma Disciplina:**: 
   Lista todas as disciplinas disponíveis no arquivo disciplinas.bin.

3. **Listar Disciplinas Matriculadas:** 
   Mostra todas as disciplinas em que o aluno já está matriculado.

4. **Cadastrar Atividade na Agenda:** 
   Adiciona uma nova atividade na agenda do aluno, informando uma descrição e a data.

5. **Mostrar Agenda:** 
   Exibe todas as atividades cadastradas na agenda do aluno.

6. **Apresentar Matriz Curricular (Baseado no Semestre de Entrada):** 
   Mostra a matriz curricular a partir do semestre de entrada do aluno, com suporte a paginação.

7. **Sair:** Encerra o programa.

## Funcionalidade de Paginação

A funcionalidade de paginação é usada na exibição da matriz curricular para dividir grandes listas de disciplinas em blocos menores, permitindo que o usuário navegue pelas páginas de maneira mais eficiente.

## Exemplo de Execução

--- Menu ---
1. Listar Disciplinas
2. Matricular em uma Disciplina
3. Listar Disciplinas Matriculadas
4. Cadastrar Atividade na Agenda
5. Mostrar Agenda
6. Apresentar Matriz Curricular (Baseado no Semestre de Entrada)
0. Sair
Escolha uma opção: 1

Disciplinas Disponíveis:
INF 111, Nome: Introdução à Engenharia de Software
MAES 111, Nome: Fundamentos de Álgebra e Cálculo
...

## Notas

- O arquivo disciplinas.bin deve conter as disciplinas em formato binário, e o programa fará a leitura dele ao iniciar.
- O arquivo disciplinas.bin deve estar na mesma pasta que o programa.
- O programa foi desenvolvido em C e utiliza a biblioteca windows.h para compatibilidade com o console do Windows.