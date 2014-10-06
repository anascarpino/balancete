#include <stdio.h>
#define TMAX 1000


typedef struct
{
	int cod;
	int quantComprada;
	float totalPago;
}tCliente;

typedef struct
{
	int cod;
	float faturamento, lucro;
}tProduto;

typedef struct
{
	tCliente cliente[TMAX];
	int tamanho;
}tListaClientes;

typedef struct{
	tProduto produto[TMAX];
	int tamanho;
}tListaProdutos;

//funções para inicializar um cliente, ler o cliente, e imprimir o total pago e a quantidade comprada
tCliente inicializaCliente(int codigo)
{
	tCliente c;
	c.cod = codigo;
	c.quantComprada = 0;
	c.totalPago = 0;	
	return c;
}

tCliente leCliente(tCliente c, int quantComprada, float totalPago)
{
	c.quantComprada = c.quantComprada + quantComprada;
	c.totalPago = c.totalPago + totalPago;
	return c;
}

void imprimeTotalPagoCliente(tCliente c)
{
	printf("(%d,%.2f) ",  c.cod, c.totalPago);
}

void imprimeQuantCompCliente(tCliente c)
{
	printf("(%d,%d) ", c.cod, c.quantComprada);
}


//funções para inicializar um produto, ler o produto e imprimir o faturamento e o lucro desse produto
tProduto inicializaProduto(int codigo)
{
	tProduto p;
	p.cod = codigo;
	p.faturamento = 0.0;
	p.lucro = 0.0;	
	return p;
}

tProduto leProduto(tProduto p, float fatProduto, float lucroProduto)
{
	p.faturamento = p.faturamento + fatProduto;
	p.lucro = p.lucro + lucroProduto;
	return p;
}

void imprimeFatProduto(tProduto produto)
{
	printf("(%d,%.2f) ", produto.cod, produto.faturamento);
}

void imprimeLucroProduto(tProduto produto)
{
	printf("(%d,%.2f) ", produto.cod, produto.lucro);
}

//funções para criar uma lista de clientes, de verificar se um cliente está na lista e inserir as informações necessárias desse cliente na lista, e depois ordenar a lista crescentemente pela quantidade comprada, e decrescentemente pelo total pago, imprimindo as listas ordenadas
tListaClientes criaListaClientes()
{
	tListaClientes c;
	c.tamanho = 0;
	return c;
}

int buscaCliente(tListaClientes c, tCliente cliente)
{
	int i;
	for(i=0; i<c.tamanho; i++){
		if(c.cliente[i].cod == cliente.cod)
		{
			return i;
		}
	}
	return -1;
}

tListaClientes insereCliente(tListaClientes c, tCliente cliente)
{
	int indice;
	indice = buscaCliente(c, cliente);
	if(indice == -1)
	{
		if(c.tamanho < TMAX)
		{
			c.cliente[c.tamanho] = cliente;
			c.tamanho = c.tamanho + 1;
		}
	}
	else
	{
		c.cliente[indice].quantComprada = c.cliente[indice].quantComprada + cliente.quantComprada;
		c.cliente[indice].totalPago = c.cliente[indice].totalPago + cliente.totalPago;
	}
	return c;
}

tListaClientes ordenaCresQuantClientes(tListaClientes c)
{
	int houveTroca = 1;
	int ultimaTroca = c.tamanho - 1;
	int posicaoTroca;

	while(houveTroca)
	{
		houveTroca = 0;
		for(int i=0; i<ultimaTroca; i++)
		{
			tCliente aux;
			if(c.cliente[i].quantComprada > c.cliente[i+1].quantComprada)
			{
				aux = c.cliente[i];
				c.cliente[i] = c.cliente[i+1];
				c.cliente[i+1] = aux;
				posicaoTroca = i;
				houveTroca = 1;
			}
		}
		ultimaTroca = posicaoTroca;
	}
	return c;
}

tListaClientes ordenaDecresValorClientes(tListaClientes c)
{
	int houveTroca = 1;
	int ultimaTroca = c.tamanho - 1;
	int posicaoTroca;

	while(houveTroca)
	{
		houveTroca = 0;
		for(int i=0; i<ultimaTroca; i++)
		{
			tCliente aux;
			if(c.cliente[i].totalPago < c.cliente[i+1].totalPago)
			{
				aux = c.cliente[i];
				c.cliente[i] = c.cliente[i+1];
				c.cliente[i+1] = aux;
				posicaoTroca = i;
				houveTroca = 1;
			}
		}
		ultimaTroca = posicaoTroca;
	}
	return c;
}

void imprimeQuantListaClientes(tListaClientes c)
{
	int i;
	for(i=0; i<c.tamanho; i++)
	{
		imprimeQuantCompCliente(c.cliente[i]);
	}
	printf("\n");
}

void imprimeTotalPagoListaClientes(tListaClientes c)
{
	int i;
	for(i=0; i<c.tamanho; i++)
	{
		imprimeTotalPagoCliente(c.cliente[i]);
	}
	printf("\n");
}


//funções para criar uma lista de produtos, de verificar se um produto está na lista e inserir as informações necessárias desse produto na lista, e depois ordenar a lista crescentemente pelo faturamento do produto, e decrescentemente pelo seu lucro, imprimindo as listas ordenadas
tListaProdutos criaListaProdutos()
{
	tListaProdutos p;
	p.tamanho = 0;
	return p;
}

int buscaProduto(tListaProdutos p, tProduto produto){
	int i;
	for(i=0; i<p.tamanho; i++){
		if(p.produto[i].cod == produto.cod){
			return i;
		}
	}
	return -1;
}

tListaProdutos insereProduto(tListaProdutos p, tProduto produto)
{
	int indice;
	indice = buscaProduto(p, produto);
	if (indice == -1)
	{
		if(p.tamanho < TMAX)
		{
			p.produto[p.tamanho] = produto;
			p.tamanho = p.tamanho + 1;
		}
	}
	else
	{
		p.produto[indice].faturamento = p.produto[indice].faturamento + produto.faturamento;
		p.produto[indice].lucro = p.produto[indice].lucro + produto.lucro;
	}
	return p;
}

tListaProdutos ordenaCresValorProdutos(tListaProdutos p)
{
	int houveTroca = 1;
	int ultimaTroca = p.tamanho - 1;
	int posicaoTroca;

	while(houveTroca)
	{
		houveTroca = 0;
		for(int i=0; i<ultimaTroca; i++)
		{
			tProduto aux;
			if(p.produto[i].faturamento > p.produto[i+1].faturamento)
			{
				aux = p.produto[i];
				p.produto[i] = p.produto[i+1];
				p.produto[i+1] = aux;
				posicaoTroca = i;
				houveTroca = 1;
			}
		}
		ultimaTroca = posicaoTroca;
	}
	return p;
}

tListaProdutos ordenaDecresLucroProdutos(tListaProdutos p)
{
	int houveTroca = 1;
	int ultimaTroca = p.tamanho - 1;
	int posicaoTroca;

	while(houveTroca)
	{
		houveTroca = 0;
		for(int i=0; i<ultimaTroca; i++)
		{
			tProduto aux;
			if(p.produto[i].lucro < p.produto[i+1].lucro)
			{
				aux = p.produto[i];
				p.produto[i] = p.produto[i+1];
				p.produto[i+1] = aux;
				posicaoTroca = i;
				houveTroca = 1;
			}
		}
		ultimaTroca = posicaoTroca;
	}
	return p;
}
		
void imprimeLucroListaProdutos(tListaProdutos p)
{
	int i;
	for(i=0; i<p.tamanho; i++)
	{
		imprimeLucroProduto(p.produto[i]);
	}
	printf("\n");
}

void imprimeFaturamentoListaProdutos(tListaProdutos p)
{

	int i;
	for(i=0; i<p.tamanho; i++)
	{
		imprimeFatProduto(p.produto[i]);
	}
	printf("\n");
}

//função principal
int main()
{
	tListaClientes lClientes1 = criaListaClientes(); //lista em ordem decrescente pelo valor total pago
	tListaClientes lClientes2 = criaListaClientes(); //lista em ordem crescente pelo total de compras
	tListaProdutos lProdutos1 = criaListaProdutos(); //lista em ordem crescente pelo valor total das vendas
	tListaProdutos lProdutos2 = criaListaProdutos(); //lista em ordem decrescente pelo lucro 
	tCliente cliente;
	tProduto produto;
	int codLoja, codDepto, codProduto, codCliente, quantProduto, somaQuantCliente, i, j, k, l, soma;
	float precoUnit, taxaLucro, valorPago, lucroProduto, fatProduto;
	scanf("%d\n", &codLoja);
	while(codLoja != -1)
	{
		scanf("%d", &codDepto);
		while(codDepto != -1)
		{
			scanf("%d", &codProduto);
			while (codProduto !=  -1)
			{
				scanf("%f %f", &precoUnit, &taxaLucro); 
				produto = inicializaProduto(codProduto);
				fatProduto = 0.0;
				lucroProduto = 0.0;
				scanf("%d", &codCliente);
				while (codCliente != -1)
				{
					cliente = inicializaCliente(codCliente);
					somaQuantCliente = 0;
					scanf("%d", &quantProduto);
					while (quantProduto != -1)
					{
						somaQuantCliente = somaQuantCliente + quantProduto;
						scanf("%d", &quantProduto);
					}
					valorPago = somaQuantCliente*precoUnit;
					cliente = leCliente(cliente, somaQuantCliente, valorPago);
					lClientes1 = insereCliente(lClientes1, cliente);
					lClientes2 = insereCliente(lClientes2, cliente);
					fatProduto = fatProduto + valorPago;
					lucroProduto = lucroProduto + valorPago*(taxaLucro/100);
					scanf("%d", &codCliente); 
				}
				produto = leProduto(produto, fatProduto, lucroProduto);
				lProdutos1 = insereProduto(lProdutos1, produto);
				lProdutos2 = insereProduto(lProdutos2, produto);
				scanf("%d", &codProduto);
			}
			scanf("%d", &codDepto);
		}
		scanf("%d", &codLoja);
	}
	scanf("%d %d %d %d", &i, &j, &k, &l);
	lClientes1 = ordenaDecresValorClientes(lClientes1);	
	lClientes2 = ordenaCresQuantClientes(lClientes2);
	lProdutos1 = ordenaCresValorProdutos(lProdutos1);
	lProdutos2 = ordenaDecresLucroProdutos(lProdutos2);
	i = lClientes1.cliente[i-1].cod;
	j = lClientes2.cliente[j-1].cod;
	k = lProdutos1.produto[k-1].cod;
	l = lProdutos2.produto[l-1].cod;
	soma = i + j + k + l;
	printf("%d \n", soma);
	imprimeTotalPagoListaClientes(lClientes1);
	imprimeQuantListaClientes(lClientes2);
	imprimeFaturamentoListaProdutos(lProdutos1);
	imprimeLucroListaProdutos(lProdutos2);
	return 0;
}

