#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de textos por região
#include <string.h> //biblioteca para cuidar das strings

//definindo funções para cada tela
int registrar() //Função responsável pelo registro de nomes
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por criar os valores da string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file,cpf); // salva o valor da variável
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

int consultar() //Função responsável pela consulta de nomes
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
		printf("Não foi possivel abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() //Função responsável por deletar nomes
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Esse CPF não está cadastrado \n");
		system("pause");
	}
	
}

int main()
{
	
	int opcao = 0; //definindo variáveis
	int laco = 1;
	
	for(laco=1;laco=1;) //definindo laço de repetição
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
		printf("\t Cartório da EBAC\n\n"); //início do menu
		printf("Escolha abaixo a opção que deseja:\n\n");
		printf("\t1 - Registrar Nome\n");
		printf("\t2 - Consultar Nome\n");
		printf("\t3 - Deletar Nome\n");
		printf("\t4 - Sair dos Sistema\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //definindo escolha do usuário
	
		system("cls"); //Responsável por limpar a tela
		
		switch(opcao) //início de seleção do menu
		{
			case 1: //chamada das funções
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
			printf("Essa opção não está disponível\n\n");
			system("pause");
			break; 
		} //fim de seleção
	
	}
}
