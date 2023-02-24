#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respos�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string

	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //criar o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //criar o arquivo e o "a" significa escrever
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); ;//criar o arquivo e o "a" significa escrever
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //criar o arquivo e o "a" significa escrever
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s" ,sobrenome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // criar o arquivo e o "a" significa escrever
	fprintf(file,sobrenome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa escrever
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a se cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa escrever
	fprintf(file,cargo); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	system("pause");
	
	
	
}  

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definido a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("n�o foi possivel abrir o arquivo, n�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}  

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definido vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //responsavel por limpa a tela
		
		setlocale(LC_ALL, "portuguese"); //Definido a linguagem
			
	    printf("### cart�rio da EBAC ###\n\n"); //Inicio do menu 	
	    printf("Escolha a op��o desejada do menu:\n\n");	   
	    printf("\t1 - Registrar nomes\n");	 
	    printf("\t2 - Consultar nomes\n");	    
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
		printf("Opcao: ");//Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls"); //responsavel por limpa a tela
		
		
		switch(opcao) //inicio da sele��o do menu
		{
		
		 case 1:
		 registro(); //chamada de fun��es
		 break;
		 
		 case 2:
		 consulta(); //chamada de fun��es
		 break;
		 
		 case 3:
		 deletar(); //chamada de fun��es
		 break;
		 
		 case 4:
		 printf("Obrigado por utilizar o sistema!\n");
		 return 0;
		 break;
		 
		 default:
		 printf("Essa op��o n�o est� disponivel\n!");
		 system("pause");
		 break;  
		}
			
     }
}
