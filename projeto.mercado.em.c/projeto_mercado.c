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
  int codigo_produto;
};

// Esta daqui é a estrutura para o armazenamento dos itens que estão no carrinho de compras.
struct carrinho
{
  char nome[50];
  float preco;
  int codigo_produto;
  int quantidade;
};

// Arrumei as funções em ordem alfabetica para eu não me perder;
void adicionar_produto_carrinho(struct produto *produtos, int *qty_produtos);
int cadastro_produto(struct produto *produtos, int *qty_produtos, int posicao);
void carrinho_compras(struct carrinho *carrinho, int *qty_carrinho);
void interacao_funcionario(struct produto *produtos, int *qty_produtos);
int interacao_sistema();
void mostrar_produtos_cadastrados(struct produto *produtos, int *qty_produtos);
int pergunta_inicial_funcionario();
void remover_produto(struct produto *produtos, int *qty_produtos);

int main()
{
  int qty_produtos = 0;
  int opcao, opcao_funcionarios = 0, opcao_clientes = 0;
  struct produto produtos[MAX_PRODUTOS];

  printf("Bem-vindo ao mercado Bom Preço!\n");
  while (1)
  {
    opcao = interacao_sistema(); // Aqui rola a interação inicial do sistema com o usuário;

    if (opcao == 1)
    {
      interacao_funcionario(produtos, &qty_produtos);
    }
    else if (opcao == 2)
    {
      printf("Opção de clientes selecionada.\n");
    }
    else if (opcao == 3)
    {
      printf("Obrigado por usar o mercado Bom Preço! Até a próxima!\n");
    }
    else
    {
      printf("Opção inválida! Por favor, escolha uma opção válida.\n");
    }
  }

  return 0;
}

/*
Aqui eu vou fazer a funçao para adicionar os produtos no carrinho de compras.
*/
void adicionar_produto_carrinho(struct produto *produtos, int *qty_produtos)
{

  return 0;
}

/*
Aqui eu vou fazer a função para mostrar os produtos que estão no carrinho de compras.
*/
void carrinho_compras(struct carrinho *carrinho, int *qty_carrinho)
{

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
  printf("Qual é o código do produto? ");
  scanf("%d", &produtos[posicao].codigo_produto); // Coloquei o código do produto agora.
  printf("Digite o nome do produto: ");
  scanf("%s", produtos[posicao].nome); // Agora vai dar para colocar o nome do produto sem sobrescrever o nome do produto anterior.
  printf("Digite o preço do produto: ");
  scanf("%f", &produtos[posicao].preco); // Agora vai dar para colocar o preço do produto sem sobrescrever o preço do produto anterior.
  (*qty_produtos)++;
  return 0;
}
/*
Aqui eu vou fazer a função da interação completa do funcionário com o sistema,
onde ele vai escolher as opções de cadastrar produto, listar produtos cadastrados,
apagar produto ou voltar ao menu principal.
*/
void interacao_funcionario(struct produto *produtos, int *qty_produtos)
{
  int opcao_funcionarios = 0;

  printf("Opção de funcionários selecionada.\n");
  while (1)
  {
    opcao_funcionarios = pergunta_inicial_funcionario(); // Aqui rola a interação do funcionário com o sistema;

    if (opcao_funcionarios == 1)
    {
      if (qty_produtos < MAX_PRODUTOS)
      {
        cadastro_produto(produtos, &qty_produtos, qty_produtos); // Aqui está acontecendo o cadastro dos produtos;
      }
      else
      {
        printf("Limite de produtos cadastrados atingido! Não é possível cadastrar mais produtos.\n");
      }
    }
    else if (opcao_funcionarios == 2)
    {
      mostrar_produtos_cadastrados(produtos, &qty_produtos); // Aqui caso o funcionário queira vai listar os produtos cadastrados;
    }
    else if (opcao_funcionarios == 3)
    {
      remover_produto(produtos, &qty_produtos); // Aqui caso o funcionário queira apagar um produto cadastrado, ele pode fazer isso;
    }
    else if (opcao_funcionarios == 4)
    {
      break;
    }
    else
    {
      printf("Opção inválida! Por favor, escolha uma opção válida.\n");
    }
  }
}

/*
Função com as perguntas padrão para o sistema.
*/
int interacao_sistema()
{
  int opcao;
  printf("1 - Funcionários\n");
  printf("2 - Clientes\n");
  printf("3 - Sair\n");
  printf("Escolha uma opção: ");
  scanf("%d", &opcao);
  return opcao;
}

/*
Aqui foi feita a função para mostrar os produtos que foram cadastrados, ela vai
receber o array de produtos e a quantidade de produtos cadastrados,
para poder mostrar somente os produtos que foram cadastrados,
e não mostrar os espaços vazios do array.
*/
void mostrar_produtos_cadastrados(struct produto *produtos, int *qty_produtos)
{
  printf("Estes são os produtos cadastrados no nosso sistema:\n");
  for (int i = 0; i < *qty_produtos; i++)
  {
    printf("%d. Código:%d Produto: %s Preço: R$%.2f\n", i + 1, produtos[i].codigo_produto, produtos[i].nome, produtos[i].preco);
  }
}

/*
Função com as perguntas padrão para os funcionários e recebimento de opção.
*/
int pergunta_inicial_funcionario()
{
  int opcao_funcionarios;
  printf("1 - Cadastrar produto\n");
  printf("2 - Listar produtos cadastrados\n");
  printf("3 - Apagar produto\n");
  printf("4 - Voltar ao menu principal\n");
  printf("Escolha uma opção: ");
  scanf("%d", &opcao_funcionarios);
  return opcao_funcionarios;
}

/*
Aqui eu vou fazer uma função para apagar os intens, ela funciona dessa maneira:
** Esqueci de mostrar os produtos que estão cadastrados para o funcionário escolher qual ele quer apagar;
1- O usuário digita o código do produto que deseja remover.
2- O sistema percorre o array de produtos para encontrar o produto com o código correspondente.
3- Se o produto for encontrado, ele é removido do array (deslocando os outros produtos para sobreescrever ele).
4- A quantidade de produtos cadastrados é diminuída em 1.
*/
void remover_produto(struct produto *produtos, int *qty_produtos)
{
  int codigo;

  // Mostrando os produtos cadastrados para o funcionário escolher qual ele quer apagar;
  mostrar_produtos_cadastrados(produtos, qty_produtos);

  printf("Digite o código do produto que deseja remover: ");
  scanf("%d", &codigo);

  int mostrar = codigo; // preciso disso para mostrar o código que foi apagado;

  for (int i = 0; i < *qty_produtos; i++)
  {
    if (produtos[i].codigo_produto == codigo)
    {
      // desloca os produtos para sobrescrever o produto a ser removido
      for (int j = i; j < *qty_produtos - 1; j++)
      {
        produtos[j] = produtos[j + 1];
      }

      (*qty_produtos)--; // diminui a quantidade

      printf("Produto com o código %d foi removido com sucesso!\n", mostrar);
      return;
    }
  }

  printf("Produto não encontrado!\n");
}
