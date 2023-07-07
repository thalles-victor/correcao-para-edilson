#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

typedef struct
{
  char nome[100];
  char cpf[15];
  int anonasc;
} dadoscliente;

dadoscliente dados[999];
int opcao;
int contIngresso = 0;

void venderIngresso()
{
  while (true)
  {
    printf("Nome do cliente: ");
    fflush(stdin);
    fgets(dados[contIngresso].nome, 100, stdin);
    printf("CPF do cliente: ");
    fflush(stdin);
    fgets(dados[contIngresso].cpf, 10, stdin);
    printf("Ano de nascimento do cliente: ");
    fflush(stdin);
    scanf("%d", &dados[contIngresso].anonasc);

    contIngresso++;

    printf("count ingrsso é: ", contIngresso, "\n");

    printf("Deseja continuar cadastrando?\n");
    printf("[1]SIM [2] Menu principal\n");
    fflush(stdin);
    scanf("%d", &opcao);
    if (opcao == 2)
    {
      menu();
    }
    else
    {
      venderIngresso();
    }
  }
}

void listarIngresso()
{
  int i;
  printf("---------------------------------------\n");
  printf("-----LISTAGEM DE INGRESSOS VENDIDOS----\n");
  printf("---------------------------------------\n");
  printf("");
  printf("");
  printf("");
  printf("");
  i = 0;
  do
  {
    printf("---------------------------------------\n");
    printf("              INGRESSO %d              \n", i + 1);
    printf("---------------------------------------\n");
    printf("Nome: %s\n", dados[i].nome);                 //[erro] não pecorre o vetor
    printf("CPF: %s\n", dados[i].cpf);                   //[erro] não pecorre o vetor
    printf("Ano de nascimento: %d\n", dados[i].anonasc); //[erro] não pecorre o vetor
    printf("---------------------------------------\n");
    printf("                                       \n");
    printf("---------------------------------------\n");
    i++;

  } while (i < contIngresso);

  printf("Deseja ver a lista de ingressos vendidos novamente?\n");
  printf("[1]SIM [2] Menu principal\n");
  fflush(stdin);
  scanf("%d", &opcao);
  if (opcao == 2)
  {
    menu();
  }
  else
  {
    listarIngresso();
  }
}

void validarIngresso()
{
  int i;
  char validar[999];
  char vCpf;
  do
  {
    validar[i] = dados[i].cpf;
    i++;
  } while (i <= contIngresso);

  printf("-----------------------");
  printf("VALIDAÇÃO DE INGRESSO  ");
  printf("-----------------------");

  printf("Digite o CPF para validar o ingresso: \n");
  fgets(vCpf, 11, stdin);

  do
  {
    if (vCpf == validar[i])
    {
      printf("Ingresso validado!");
    }
    else
    {
      printf("[ERRO] Ingresso invalido!");
    }
  } while (i < 999);

  printf("Deseja fazer a validação de ingresso novamente?\n");
  printf("[1]SIM [2] Menu principal\n");
  fflush(stdin);
  scanf("%d", &opcao);
  if (opcao == 2)
  {
    menu();
  }
  else
  {
    validarIngresso();
  }
}

void menu()
{
  setlocale(LC_ALL, "");

  int selecao; // variavel de seleção de opção no menu

  // menu
  printf("Escolha uma opção\n");
  printf("1. Vender ingresso\n");
  printf("2. Listar ingressos vendidos\n");
  printf("3. Validar ingressos\n");
  printf("0. Sair\n");
  fflush(stdin);
  scanf("%d", &selecao);

  switch (selecao)
  {
  case 1:
    system("cls");
    venderIngresso();
    break;
  case 2:
    system("cls");
    listarIngresso();
    break;
  case 3:
    system("cls");
    validarIngresso();
    break;
  case 0:
    printf("Saindo...");
    exit(0);
    break;
  default:
    printf("[ERRO] Opção invalida!");
    break;
  }
}

int main()
{
  menu();
  return 0;
}