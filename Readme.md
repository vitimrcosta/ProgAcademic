# Sistema de Gest�o Acad�mica

Este � um programa simples de gest�o acad�mica para um aluno universit�rio. Ele permite o cadastro e gerenciamento de disciplinas e atividades, al�m de exibir a matriz curricular baseada no semestre de entrada. O sistema tamb�m possui funcionalidade de pagina��o para facilitar a visualiza��o de grandes listas de disciplinas.

## Funcionalidades

1. **Listar Disciplinas Dispon�veis**  
   Exibe uma lista de todas as disciplinas dispon�veis.

2. **Matricular em uma Disciplina**  
   Permite ao aluno se matricular em disciplinas dispon�veis com base em seu c�digo.

3. **Listar Disciplinas Matriculadas**  
   Exibe uma lista das disciplinas nas quais o aluno est� atualmente matriculado.

4. **Cadastrar Atividade na Agenda**  
   Permite ao aluno registrar atividades e compromissos acad�micos com uma descri��o e uma data.

5. **Mostrar Agenda**  
   Exibe todas as atividades e compromissos cadastrados na agenda do aluno.

6. **Apresentar Matriz Curricular (Baseado no Semestre de Entrada)**  
   Mostra a matriz curricular a partir do semestre de entrada do aluno, utilizando pagina��o para organizar a visualiza��o quando h� muitas disciplinas.

## Estrutura do Programa

O programa � estruturado em torno de v�rios componentes principais:

- **Disciplinas**: Representa as informa��es sobre cada disciplina, incluindo c�digo, nome, carga hor�ria, semestre, pr�-requisitos e tipo (obrigat�ria ou optativa).
  
- **Hist�rico**: Gerencia as disciplinas em que o aluno j� se matriculou.
  
- **Agenda**: Gerencia as atividades acad�micas do aluno.
  
- **Matriz Curricular**: Organiza as disciplinas por semestre e permite apresentar ao aluno a sequ�ncia correta de disciplinas conforme seu semestre de entrada.

## Requisitos

- Sistema operacional Windows (para o uso de `windows.h` no console).
- Compilador C (por exemplo, GCC ou MinGW para compilar o c�digo no Windows).
- Arquivo bin�rio `disciplinas.bin`, que cont�m as disciplinas oferecidas pelo curso.

## Como Executar

1. **Compila��o**: Compile o programa utilizando um compilador C. Exemplo de comando no terminal:

   ```bash
   gcc sistema_academico.c -o sistema_academico


## Como Utilizar

Ao executar o programa, um menu ser� exibido com as seguintes op��es

1. **Listar Disciplinas**: 
   Lista todas as disciplinas dispon�veis no arquivo disciplinas.bin.

2. **Matricular em uma Disciplina:**: 
   Lista todas as disciplinas dispon�veis no arquivo disciplinas.bin.

3. **Listar Disciplinas Matriculadas:** 
   Mostra todas as disciplinas em que o aluno j� est� matriculado.

4. **Cadastrar Atividade na Agenda:** 
   Adiciona uma nova atividade na agenda do aluno, informando uma descri��o e a data.

5. **Mostrar Agenda:** 
   Exibe todas as atividades cadastradas na agenda do aluno.

6. **Apresentar Matriz Curricular (Baseado no Semestre de Entrada):** 
   Mostra a matriz curricular a partir do semestre de entrada do aluno, com suporte a pagina��o.

7. **Sair:** Encerra o programa.

## Funcionalidade de Pagina��o

A funcionalidade de pagina��o � usada na exibi��o da matriz curricular para dividir grandes listas de disciplinas em blocos menores, permitindo que o usu�rio navegue pelas p�ginas de maneira mais eficiente.

## Exemplo de Execu��o

--- Menu ---
1. Listar Disciplinas
2. Matricular em uma Disciplina
3. Listar Disciplinas Matriculadas
4. Cadastrar Atividade na Agenda
5. Mostrar Agenda
6. Apresentar Matriz Curricular (Baseado no Semestre de Entrada)
0. Sair
Escolha uma op��o: 1

Disciplinas Dispon�veis:
INF 111, Nome: Introdu��o � Engenharia de Software
MAES 111, Nome: Fundamentos de �lgebra e C�lculo
...

## Notas

- O arquivo disciplinas.bin deve conter as disciplinas em formato bin�rio, e o programa far� a leitura dele ao iniciar.
- O arquivo disciplinas.bin deve estar na mesma pasta que o programa.
- O programa foi desenvolvido em C e utiliza a biblioteca windows.h para compatibilidade com o console do Windows.