/*
Devemos desenvolver uma aplicação onde ao ser inicializada
apresente ao usuário um menu onde seja possível cadastrar,
listar e comprar produtos, além de visualizar carrinho de compra ou sair da aplicação.

Ao adicionar um produto no carrinho de compras, deve-se
verificar se já existe um mesmo produto no carrinho, bastando alterar a quantidade.

Ao finalizar a compra deve ser apresentado ao usuário
o total de acordo com os produtos e quantidades inseridas no carrinho de compra.

1 - Função para cadastrar produtos.
2- Função para mostrar os produtos cadastrados.
3- Função para adicionar produtos no carrinho de compras.
3.1- Verificar se o produto já existe no carrinho, caso exista, alterar a quantidade.
4- Função para mostrar os produtos no carrinho de compras.
5- Função para modificar a quantidade de um produto no carrinho de compras. (Essa eu vou adicionar)
6- Função para finalizar a compra, apresentando o total de acordo com os produtos e quantidades inseridas no carrinho de compra.
7-função perguntando metodo de pagamento. (Essa eu vou adicionar)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUTOS 10

struct produto
{
  char nome[50];
  float preco;
};

int cadastro_produto(struct produto *produtos, int *qty_produtos)
{
  printf("Digite o nome do produto: ");
  scanf("%s", produtos->nome);
  printf("Digite o preço do produto: ");
  scanf("%f", &produtos->preco);
  (*qty_produtos)++;
  return 0;
}

int mostrar_produtos_cadastrados(struct produto *produtos, int *qty_produtos)
{
  printf("Produtos cadastrados:\n");
  for (int i = 0; i < *qty_produtos; i++)
  {
    printf("%d. %s -> R$%.2f\n", i + 1, produtos[i].nome, produtos[i].preco);
  }
  return 0;
}

int main()
{
  int qty_produtos = 0;
  struct produto produtos[MAX_PRODUTOS];

  cadastro_produto(produtos, &qty_produtos);
  mostrar_produtos_cadastrados(produtos, &qty_produtos);

  return 0;
}