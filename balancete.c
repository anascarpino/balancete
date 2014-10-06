#include <stdio.h>

int main()
{
	int codLoja, codDepartamento, codProduto, codCliente, quantCliente, somaQuantCliente, maiorComprador, maiorCompra, lojaMaiorCompra, produtoMaiorCompra, depMaiorCompra, quantTotalProduto, primeiroMaisLucrativo, terceiroMaisLucrativo, segundoMaisLucrativo, nProdutoDep, depMaiorFatMedio, nDepartamento, lojaMaiorFatMedio, lojaMenorFatMedio;

	double precoUnit, tLucro, fatProduto, fatDepartamento, fatLoja, lucroProduto, lucroPrimeiroMaisLucrativo, lucroTerceiroMaisLucrativo, lucroSegundoMaisLucrativo, fatMedioDep, maiorFatMedioDep, fatMedioLoja, fatEmpresa, menorFatMedioLoja, maiorFatMedioLoja ;

	/* inicializa as variáveis da empresa */
	fatEmpresa = 0.0;
	maiorCompra = -1;
	lojaMenorFatMedio = -1;
	lojaMaiorFatMedio = -1;

	/* esse primeiro bloco faz o processamento das lojas */
	scanf("%d", &codLoja);
	while(codLoja != -1)
	{
		printf("Loja: %d \n", codLoja);
		
		/* inicializa as variáveis da loja */
		fatLoja = 0.0;
		fatMedioLoja = 0.0;
		maiorFatMedioDep = -1.0;
		depMaiorFatMedio = 0;
		nDepartamento = 0;

		/* esse segundo bloco faz o processamento dos departamentos */
		scanf("%d", &codDepartamento);
		while (codDepartamento != -1)
		{
			printf("\tDepartamento: %d \n", codDepartamento);

			/* inicializa as variáves do departamento */
			fatDepartamento = 0.0;
			primeiroMaisLucrativo = 0;
			segundoMaisLucrativo = 0;
			terceiroMaisLucrativo = 0;
			lucroPrimeiroMaisLucrativo = 0.0;
			lucroSegundoMaisLucrativo = 0.0;
			lucroTerceiroMaisLucrativo = 0.0;
			nProdutoDep = 0;

			/* esse terceiro bloco faz o processamento dos produtos */
			scanf("%d", &codProduto);
			while (codProduto != -1)
			{
				quantTotalProduto = 0;
				printf("\t\tProduto: %d \n", codProduto);
				scanf("%lf %lf", &precoUnit, &tLucro);

				/* esse quarto bloco faz o processamento dos clientes */
				scanf("%d", &codCliente);
				while (codCliente != -1)
				{
					somaQuantCliente = 0;

					/* esse quinto bloco incrementa a quantidade por cliente */
					scanf("%d",&quantCliente);
					while (quantCliente != -1)
					{
						somaQuantCliente = quantCliente + somaQuantCliente;
						scanf("%d", &quantCliente);
					}

					/* verifica qual cliente comprou a maior quantidade de um produto qualquer */
					if(somaQuantCliente > maiorCompra)
					{
						maiorComprador = codCliente;
						maiorCompra = somaQuantCliente;
						produtoMaiorCompra = codProduto;
						depMaiorCompra = codDepartamento;
						lojaMaiorCompra = codLoja;
					}
					scanf("%d", &codCliente);
					quantTotalProduto = quantTotalProduto + somaQuantCliente;
				}
				nProdutoDep = nProdutoDep + 1;		
				fatProduto = quantTotalProduto*precoUnit;
				printf("\t\t\tFaturamento do Produto: %.6f \n", fatProduto);
				lucroProduto = (fatProduto*tLucro)/100;

				/* verifica quais os três produtos mais lucrativos de cada departamento */
				if (lucroProduto > lucroPrimeiroMaisLucrativo)
				{
					terceiroMaisLucrativo = segundoMaisLucrativo;
					segundoMaisLucrativo = primeiroMaisLucrativo;
					primeiroMaisLucrativo = codProduto;
					lucroTerceiroMaisLucrativo = lucroSegundoMaisLucrativo;
					lucroSegundoMaisLucrativo = lucroPrimeiroMaisLucrativo;
					lucroPrimeiroMaisLucrativo = lucroProduto;
				}
				else    if (lucroProduto > lucroSegundoMaisLucrativo)
					{
						terceiroMaisLucrativo = segundoMaisLucrativo;
						segundoMaisLucrativo = codProduto;
						lucroTerceiroMaisLucrativo = lucroSegundoMaisLucrativo;
						lucroSegundoMaisLucrativo = lucroProduto;
					}
					else    if (lucroProduto > lucroTerceiroMaisLucrativo)
						{
							terceiroMaisLucrativo = codProduto;
							lucroTerceiroMaisLucrativo = lucroProduto;
						}
				fatDepartamento = fatProduto + fatDepartamento;
				scanf("%d", &codProduto);
			}
			printf("\t\tFaturamento do Departamento: %.6lf \n", fatDepartamento);
			fatMedioDep = fatDepartamento/nProdutoDep;
			nDepartamento = nDepartamento + 1;

			/* verifica qual departamento obteve maior faturamento médio */
			if (fatMedioDep > maiorFatMedioDep)
			{
				maiorFatMedioDep = fatMedioDep;
				depMaiorFatMedio = codDepartamento;
			}

			/* imprime os três produtos mais lucrativos, caso existam */
			printf("\t\tProduto Mais Lucrativo: %d Lucro: %.6lf \n", primeiroMaisLucrativo, lucroPrimeiroMaisLucrativo);
			if (segundoMaisLucrativo != 0)
			{-
				printf("\t\tSegundo Produto Mais Lucrativo: %d Lucro: %.6lf \n", segundoMaisLucrativo, lucroSegundoMaisLucrativo);
				if (terceiroMaisLucrativo != 0)
				{
				       printf("\t\tTerceiro Produto Mais Lucrativo: %d Lucro: %.6lf\n",terceiroMaisLucrativo,lucroTerceiroMaisLucrativo);
				}
			}
			fatLoja = fatDepartamento + fatLoja;
			scanf("%d", &codDepartamento);
		}
		fatMedioLoja = fatLoja/nDepartamento;

		/* verifica as lojas de menor e maior faturamento medio */
		if(lojaMaiorFatMedio == -1)
		{
			maiorFatMedioLoja = fatMedioLoja;
			menorFatMedioLoja = fatMedioLoja;
			lojaMaiorFatMedio = codLoja;
			lojaMenorFatMedio = codLoja;
		}
		else    if (fatMedioLoja < menorFatMedioLoja)
			{
				menorFatMedioLoja = fatMedioLoja;
				lojaMenorFatMedio = codLoja;
			}
			else 	if (fatMedioLoja > maiorFatMedioLoja)
				{
					maiorFatMedioLoja = fatMedioLoja;
					lojaMaiorFatMedio = codLoja;
				}
		printf("\tFaturamento da Loja: %.6lf \n", fatLoja);
		printf("\tDep. de Maior Fat. Medio: %d Fat. Medio: %.6lf\n", depMaiorFatMedio, maiorFatMedioDep);
		fatEmpresa = fatLoja + fatEmpresa;
		scanf("%d", &codLoja);
	}
	printf("Faturamento da Empresa: %.6lf\n", fatEmpresa);
	printf("Maior Comprador: %d %d %d %d %d \n", maiorComprador, produtoMaiorCompra, depMaiorCompra, lojaMaiorCompra, maiorCompra);
	printf("Loja de Menor Fat. Medio: %d Fat. Medio: %.6lf \n", lojaMenorFatMedio, menorFatMedioLoja);
	printf("Loja de Maior Fat. Medio: %d Fat. Medio: %.6lf \n", lojaMaiorFatMedio, maiorFatMedioLoja);
	return 0;
}
