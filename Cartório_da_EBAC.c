#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de textos por regi�o
#include <string.h> //biblioteca para cuidar das strings

//definindo fun��es para cada tela
int registrar() //Fun��o respons�vel pelo registro de nomes
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por criar os valores da string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file,cpf); // salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	system("pause");
}

int consultar() //Fun��o respons�vel pela consulta de nomes
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() //Fun��o respons�vel por deletar nomes
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Esse CPF n�o est� cadastrado \n");
		system("pause");
	}
	
}

int main()
{
	
	int opcao = 0; //definindo vari�veis
	int laco = 1;
	
	for(laco=1;laco=1;) //definindo la�o de repeti��o
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
		printf("\t Cart�rio da EBAC\n\n"); //in�cio do menu
		printf("Escolha abaixo a op��o que deseja:\n\n");
		printf("\t1 - Registrar Nome\n");
		printf("\t2 - Consultar Nome\n");
		printf("\t3 - Deletar Nome\n");
		printf("\t4 - Sair dos Sistema\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //definindo escolha do usu�rio
	
		system("cls"); //Respons�vel por limpar a tela
		
		switch(opcao) //in�cio de sele��o do menu
		{
			case 1: //chamada das fun��es
			registrar();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel\n\n");
			system("pause");
			break; 
		} //fim de sele��o
	
	}
}
