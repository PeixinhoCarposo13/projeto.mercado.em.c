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

// Aqui estou definindo um limite de no máximo 10 produtos que podem ser cadastrados.
#define MAX_PRODUTOS 3

// Esta daqui é a estrutura para o armazenamento das informações dos itens cadastrados.
struct produto
{
  char nome[50];
  float preco;
};

int cadastro_produto(struct produto *produtos, int *qty_produtos, int posicao);
void mostrar_produtos_cadastrados(struct produto *produtos, int *qty_produtos);

int main()
{
  int qty_produtos = 0;
  struct produto produtos[MAX_PRODUTOS];

  for (int i = 0; i < MAX_PRODUTOS; i++)
  {
    cadastro_produto(produtos, &qty_produtos, i);
  }
  mostrar_produtos_cadastrados(produtos, &qty_produtos);

  return 0;
}

/*
Aqui foi feita a função para cadastrar os produtos, ela recebe o ararray de produtos
a quantidade de produtos cadastrados e a posição onde o produto será cadastrado,
para poder somar a quantidade de produtos
cadastrados a cada novo cadastro.
*/
int cadastro_produto(struct produto *produtos, int *qty_produtos, int posicao)
{
  printf("Digite o nome do produto: ");
  scanf("%s", produtos[posicao].nome); // Agora vai dar para colocar o nome do produto sem sobrescrever o nome do produto anterior.
  printf("Digite o preço do produto: ");
  scanf("%f", &produtos[posicao].preco); // Agora vai dar para colocar o preço do produto sem sobrescrever o preço do produto anterior.
  (*qty_produtos)++;
  return 0;
}
/*
Aqui foi feita a função para mostrar os produtos que foram cadastrados, ela vai
receber o array de produtos e a quantidade de produtos cadastrados,
para poder mostrar somente os produtos que foram cadastrados,
e não mostrar os espaços vazios do array.
*/
void mostrar_produtos_cadastrados(struct produto *produtos, int *qty_produtos)
{
  printf("Produtos cadastrados:\n");
  for (int i = 0; i < *qty_produtos; i++)
  {
    printf("%d. %s -> R$%.2f\n", i + 1, produtos[i].nome, produtos[i].preco);
  }
  return 0;
}