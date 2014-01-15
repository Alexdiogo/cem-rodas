#include <stdio.h>
#include <windows.h> 
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#define NI 10              // numero maximo de clientes
#define NC 10             // numero maximo de camioes
#define NO 10             // numero maximo de condutores
#define NA 10             // numero maximo de cargas

/*!
*
*\file
*\brief Programa de gestao de uma empresa de transporte de cargas
*\author Filipa Amaro, Humberto Alexandre, Nelson Reis, Joao Fernandes
*\date 10 Janeiro 2014
*\bug Sem erros
*\copyright GNU publisher
*\version 1.0
*
*/

char historico [100];

/**
*
*Estrutura do tipo data 
*\param dia : int
*\param mes : int
*\param ano : int
*/		
typedef struct
{
    int dia;
    int mes;
    int ano;
}data; 

/**
*
*Estrutura dos clientes
*\param numero : long int
*\param nome : char
*\param morada : char
*\param telefone : long int
*\param estado : int
*/
typedef struct  
    {
		long int numero;
		char nome[50];
		char morada[60];
		long int telefone;
		int estado;
	}clientes;

/**
*
*Estrutura dos camioes
*\param ncam : int
*\param matricula : char
*\param cm : int
*\param dpi : data
*\param custo : int
*\param ma : int
*\param situacao : int
*\param estado : int
*/
typedef struct
  {
	int ncam;				// numero de camiao 
	char matricula[9];      // matricula camiao
	int cm;					// carga maxima
	data dpi;				// data proxima inspeccao 
	int custo;              // custo por km
	int ma;					//motorista associado
	int situacao;           // 1= ocupado 0 = livre
	int estado;				// 1 = activo 0 = apagado  
}camioes;
  
/**
*
*Estrutura dos clientes
*\param numero : int
*\param nome : char
*\param data_nas : data
*\param telefone : int
*\param morada : char
*\param situacao : int
*\param estado : int
*/
typedef struct{
	int numero;
	char nome[50];
    data data_nas;			
	int telefone;
	char morada[50];
	int situacao;		// 1= ocupado 0=livre
	int estado;			// 1=activo 0=apagado		
}condutores;

/**
*
*Estrutura das cargas
*\param numero : int
*\param nome_cliente : char
*\param local_origem : char
*\param local_destino : char
*\param distancia : int
*\param peso : int
*\param data_trans : data
*\param situacao : int
*\param estado : int
*/
typedef struct
{
	int numero;
	char nome_cliente[50];
	char local_origem[30];
	char local_destino[30];
	int distancia;
	int peso;
	data data_trans;
	int situacao;			// 1=atribuida 0= nao atribuida
	int estado;				// 1=activo 0=apagado
}cargas;


/**
*
*Funcao criar ficheiros (Clientes, Camioes, Condutores, Cargas e Historico)
*\param n : int
*\param m : int
*\param d : int
*\param c : int
*/
void iniciar_ficheiros (clientes *cli, camioes *cam, condutores *con, cargas *car)
{
    int n, m, d, c;
    FILE *fi, *fc, *fo, *fa,*fh;
     
    //Criar o ficheiro inicial de clientes se este nao existir
        if(!(fi=fopen("clientes.txt ","r")))
	{
		fi=fopen("clientes.txt","w");
		printf("\n\nFoi criado clientes.txt <Enter para Continuar>");getch();
	}
	 fclose(fi);
    
	//Criar o ficheiro inicial de camioes se este nao existir
    	if(!(fc=fopen("camioes.txt","r")))
    {
    	fc=fopen("camioes.txt","w");
    	printf("\nFoi criado camioes.txt <Enter para Continuar>");getch();
	}
	 fclose(fc);
    
	//Criar o ficheiro inicial de condutores se este nao existir
        if(!(fo=fopen("condutores.txt","r")))
	{
		fo=fopen("condutores.txt","w");
    	printf("\nFoi criado condutores.txt <Enter para Continuar>");getch();
	}
	 fclose(fo);
    
	 //Criar o ficheiro inicial de cargas se este nao existir
    if(!(fa=fopen("cargas.txt","r")))
	{
		fa=fopen("cargas.txt","w");
		printf("\nFoi criado cargas.txt <Enter para Continuar>");getch();
    }
     fclose(fa);
     
     //Criar o ficheiro historico se este nao existir
    if(!(fh=fopen("historico.txt","r")))
	{
		fh=fopen("historico.txt","w");
		printf("\nFoi criado historico.txt <Enter para Continuar>");getch();
    }
     fclose(fh);
     
     
}

/**
*
*Funcao ler_clientes le e carrega os clientes do ficheiro clientes.txt
*\param n : int
*/
void ler_clientes(clientes *cli)
{
			
	FILE *fi;
	int n;
	
	if(!(fi=fopen("clientes.txt","r")))
	{
		fi=fopen("clientes.txt","w");
		printf("Foi criado o ficheiro clientes\n");
	}
	
	for(n=1;n<NI;n++)	//carrega os dados do ficheiro clientes.txt 
	{
		
		{
			fscanf(fi,"%ld\n%s\n%s\n%ld\n%d\n", &cli[n].numero, cli[n].nome, cli[n].morada, &cli[n].telefone, &cli[n].estado);
		}
	}
	
	fclose(fi);
	printf("\n\nFicheiro Lido <Enter para continuar>\n"); getch();
}

/**
*
*Funcao para listagem dos clientes
*\param n : int
*/
void listar_clientes (clientes *cli)
{
    
    int n;
	system ("cls");printf("\n...A LISTAR CLIENTES...\n");	
	for(n=1;n<NI;n++)										//Lista todos os clientes
	{
	
	if(cli[n].estado == 1)
        	
		{
            printf("\nNumero: %ld\nNome: %s\nMorada: %s\nTelefone: %ld\nEstado: %d\n",cli[n].numero,cli[n].nome,cli[n].morada,cli[n].telefone, cli[n].estado);
		}
	}
	
	printf("\nListagem concluida <Enter para voltar>");getch();
}

/**
*
*Funcao para inserir clientes
*\param n : int
*\param inser: long int
*/
int inserir_clientes(clientes *cli)
{
		
	int n;
	long int inser;
	system ("cls");
	printf("Qual o numero do cliente que quer inserir? [1-%d]?", NI);
		do
		{
			scanf("%ld",&inser);
			if (inser<1 || inser >= NI)	//verifica se o numero inserido pelo utilizador está contido na quantidade defenida
			{
				printf("\nNumero fora dos Parametros ?");	 
			}
				else
					break;
																							
		}while(1);
			
	for(n=1;n<NI;n++)
	{
		if(cli[n].estado!=1)
		{
			cli[n].numero=inser;
			printf("\n\nNome: ");scanf("\n%[^\n]s",cli[n].nome);
			printf("\n\nMorada: ");scanf("\n%[^\n]s",cli[n].morada);
			printf("\n\nTelefone: ");scanf("%ld", &cli[n].telefone);
			cli[n].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para continuar>\n");
			getch();
			return(1);
		}
	}
	printf("ERRO! Não foi possivel inserir"); getch(); return(0);
	
}

/**
*
*Funcao para alterar clientes
*\param n : int
*\param confere : char
*\param alte : long int
*/
int alterar_clientes(clientes *cli)
{
	int n;
	char confere;
	long int alte;
	system("cls");
	printf("Qual o numero do Cliente que quer alterar? "); scanf("%ld",&alte);
	for(n=1;n<NI;n++)
	{
		if(cli[n].numero==alte)	//altera o numero de cliente digitado pelo utilizador
		{
			printf("\nNome: %s\nMorada: %s\nTelefone: %d\n\n",cli[n].nome, cli[n].morada, cli[n].telefone);
            printf("\n\nQuer mesmo alterar? <S/N>");confere=getch();
				if (confere!='S' && confere!='s')    return(0);	//Pede confirmacao da alteracao
					
				if(cli[n].estado==1)			
			cli[n].numero=alte;
			printf("\n\nNome: ");scanf("\n%[^\n]s", cli[n].nome);
			printf("\n\nMorada: ");scanf("\n%[^\n]s",cli[n].morada);
			printf("\n\nTelefone: ");scanf("%ld", &cli[n].telefone);
			cli[n].estado=1;
			printf("\n\n\nRegisto alterado com sucesso! <Enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);

}

/**
*
*Funcao para eliminar clientes
*\param confere : char
*\param n : int
*\param eli : long int
*/
int eliminar_clientes(clientes *cli)
{
	char confere;
	int n;
	long int eli;
	system("cls");
	printf("Qual o numero do cliente que quer eliminar? "); scanf("%ld",&eli);
	for(n=1;n<NI;n++)		//Verifica todos os clientes  
	{
		if(cli[n].numero==eli)	//altera o cliente conforme o numero inserido pelo utilizador
		{
			printf("\nNumero: %d\nNome: %s\nMorada: %s\nTelefone: %d\n\n",cli[n].numero, cli[n].nome, cli[n].morada, cli[n].telefone);
			printf("\n\nTem a certeza que quer eliminar? <S/N>");confere=toupper(getch());

			if (confere!='S' && confere!='s')    return(0);	//confirma a eliminacao com tecla S

			cli[n].estado=0;
			printf("\n\n\nRegisto eliminado <Enter para continuar>\n");getch();  return (1);
		}
	}
	printf("ERRO! Numero não Encontrado\n");system("pause");return(0);
}

/**
*
*Funcao para gravar clientes
*\param n : int
*/
void gravar_clientes(clientes *cli)
{
	FILE *fi;		//ponteiro para o ficheiro clientes.txt
	int n;
	if(!(fi=fopen("clientes.txt","w")))		//abre o ficheiro clientes.txt em modo "escrita"
	{
		printf("\n\n\nErro na Abertura para Gravar\n");system("pause");exit(0);
	}
	
	for(n=1;n<NI;n++)	//grava toda a estrutura dos clientes para clientes.txt
	{
		if(cli[n].estado==1)
		{
			fprintf(fi,"%ld\n%s\n%s\n%d\n%d\n",cli[n].numero,cli[n].nome,cli[n].morada,cli[n].telefone,cli[n].estado);
		}
	}
	fclose(fi);
	printf("\n\n\nFicheiro Gravado\n");getch();
}

/**
*
*Menu Clientes
*\param op : int
*\param n : int
*/
int menu_clientes() 
		{
        	int op;
			int n;
			clientes cli[NI];
			for(n=0;n<NI;n++) 
			cli[n].estado=0; //limpa array de registos dos clientes
			system("cls"); 
    		ler_clientes(cli);
		do {
        
		system ("cls");						        
		printf("\n\t|============================================|"); system("COLOR 0A");
    	printf("\n\t|              C E M  R O D A S              |");
    	printf("\n\t|                                            |");
	   	printf("\n\t|                                            |");
    	printf("\n\t|               C L I E N T E S              |");
    	printf("\n\t|                                            |");
    	printf("\n\t|============================================|");
        printf("\n\t*                                            *"); 
        printf("\n\t*               1 - Inserir                  *");
        printf("\n\t*                                            *"); 
        printf("\n\t*               2 - Alterar                  *");
		printf("\n\t*                                            *"); 
        printf("\n\t*               3 - Eliminar                 *");
        printf("\n\t*                                            *");
        printf("\n\t*               4 - Gravar                   *");
		printf("\n\t*                                            *");
		printf("\n\t*               5 - Listar                   *");
		printf("\n\t*                                            *");
		printf("\n\t*               0 - Menu Principal           *");
		printf("\n\t*                                            *");
        printf("\n\t**********************************************");
        printf("\n\n\t             Qual a sua opcao? ");
				
				scanf("%d",&op);
               
				switch (op) {
                        case 1: inserir_clientes(cli); break;
                        case 2: alterar_clientes(cli); break;
                        case 3: eliminar_clientes(cli); break;
						case 4: gravar_clientes(cli); break;
						case 5: listar_clientes(cli); break;
						case 0: system ("cls"); break;
                        default: printf("Opcao invalida!\n");
                }
        } while (op!=0);
}
//MENU CLIENTES FIM

// MENU CAMIOES INICIO

/**
*
*Funcao para ler e carregar os camioes do ficheiro camioes.txt
*\param c : int
*/
void ler_camioes(camioes *cam)
{
	FILE *fc;		//apontador para o ficheiro camioes.txt
	int c;
	
	if(!(fc=fopen("camioes.txt","r")))
	{
		fc=fopen("camioes.txt","w");
		printf("Foi criado o ficheiro camioes.txt\n");
	}
	for(c=1;c<NC;c++)
	{
		
		{
			fscanf(fc,"%d\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &cam[c].ncam, cam[c].matricula, &cam[c].cm,&cam[c].dpi.dia, &cam[c].dpi.mes, 
			&cam[c].dpi.ano, &cam[c].custo, &cam[c].ma, &cam[c].situacao, &cam[c].estado);
					
		}
	}
	fclose(fc);
	printf("\n\nFicheiro Lido <Enter para continuar>\n"); getch();
}

/**
*
*Funcao para listar camioes
*\param c : int
*/
void listar_camioes (camioes *cam)
{
    int c;
	system ("cls");
	printf("\n...A LISTAR CAMIOES...\n");
	for(c=1;c<NC;c++)
		
		if(cam[c].estado==1)
		{
        printf("\nNumero: %d\nMatricula: %s\nCarga Maxima KG: %d\nData inspeccao: %d/%d/%d\nCusto KM(EUROS): %d\nMotorista Camiao: %d\nSituacao 1-Ocupado 0-Livre: %d\nEstado: %d\n",
		cam[c].ncam,cam[c].matricula,cam[c].cm,cam[c].dpi.dia,cam[c].dpi.mes,cam[c].dpi.ano,cam[c].custo,cam[c].ma,cam[c].situacao,cam[c].estado);
		}
	
	printf("\nListagem concluida <Enter para voltar>");getch();
}

/**
*
*Funcao para inserir camioes
*\param c : int
*\param inser : long int
*/
int inserir_camioes(camioes *cam)
{
	int c;
	long int inser;
	system ("cls");
	printf("Qual o numero do camiao que quer inserir? [1-%d]?", NC);
		do
		{
			scanf("%ld",&inser);
			if (inser<1 || inser >= NC)
			{
				printf("\nNumero fora dos Parametros ?");
			}
				else
					break;
																							
		}while(1);
			
	for(c=1;c<NC;c++)
	{
		if(cam[c].estado!=1)
		{
			cam[c].ncam=inser;
			printf("\n\nMatricula: ");scanf("\n%s",cam[c].matricula);
			printf("\n\nCarga Maxima KG: ");scanf("\n%d",&cam[c].cm);
			printf("\n\nInspeccao dia: ");scanf("\n%d",&cam[c].dpi.dia);
			printf("\n\nInspeccao mes: ");scanf("\n%d",&cam[c].dpi.mes);
			printf("\n\nInspeccao ano: ");scanf("\n%d",&cam[c].dpi.ano);
			printf("\n\nCusto KM(Euros): ");scanf("\n%d",&cam[c].custo);
			printf("\n\nMotorista: ");scanf("\n%d",&cam[c].ma);
			printf("\n\nSituacao 1-ocupado 0-livre: ");scanf("%d", &cam[c].situacao);
			cam[c].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para continuar>\n");
			getch();
			return(1);
		}
	}
	printf("ERRO! Não foi possivel inserir"); getch(); return(0);
}

/**
*
*Funcao para alterar camioes
*\param confere : char
*\param c : int
*\param alte : long int
*/ 
int alterar_camioes(camioes *cam)
{
	char confere;
	int c;
	long int alte;
	system("cls");
	printf("Qual o numero do Camiao que quer alterar? "); scanf("%ld",&alte);
	for(c=1;c<NC;c++)
	{
		if(cam[c].ncam==alte)
		{
			printf("\nNumero: %d\nMatricula: %s\nCarga Maxima KG: %d\nData inspeccao: %d/%d/%d\nCusto KM(EUROS): %d\nMotorista Camiao: %d\nSituacao 1-Ocupado 0-Livre: %d\nEstado: %d\n",
			cam[c].ncam,cam[c].matricula,cam[c].cm,cam[c].dpi.dia,cam[c].dpi.mes,cam[c].dpi.ano,cam[c].custo,cam[c].ma,cam[c].situacao,cam[c].estado);
            
			printf("\n\nQuer mesmo alterar? <S/N>");confere=getch();
				if (confere!='S' && confere!='s')    return(0);
				if(cam[c].estado==1)
					
			printf("\n\nMatricula: ");scanf("\n%s",cam[c].matricula);
			printf("\n\nCarga Maxima KG: ");scanf("\n%d",&cam[c].cm);
			printf("\n\nInspeccao dia: ");scanf("\n%d",&cam[c].dpi.dia);
			printf("\n\nInspeccao mes: ");scanf("\n%d",&cam[c].dpi.mes);
			printf("\n\nInspeccao ano: ");scanf("\n%d",&cam[c].dpi.ano);
			printf("\n\nCusto KM(EUROS): ");scanf("\n%d",&cam[c].custo);
			printf("\n\nMotorista: ");scanf("\n%d",&cam[c].ma);
			printf("\n\nSituacao 1-ocupado 0-livre: ");scanf("%d", &cam[c].situacao);
			printf("\n\n\nRegisto alterado com sucesso! <Enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);
}

/**
*
*Funcao para eliminar camioes
*\param confere : char
*\param c : int
*\param eli : long int
*/
int eliminar_camioes(camioes *cam)
{
	char confere;
	int c;
	long int eli;
	system("cls");
	printf("Qual o numero do camiao que quer eliminar? "); scanf("%ld",&eli);
	for(c=1;c<NC;c++)
	{
		if(cam[c].ncam==eli)
		{
			printf("\nNumero: %d\nMatricula: %s\nCarga Maxima KG: %d\nData inspeccao: %d/%d/%d\nCusto KM(EUROS): %d\nMotorista Camiao: %d\nSituacao 1-Ocupado 0-Livre: %d\nEstado: %d\n",
			cam[c].ncam,cam[c].matricula,cam[c].cm,cam[c].dpi.dia,cam[c].dpi.mes,cam[c].dpi.ano,cam[c].custo,cam[c].ma,cam[c].situacao,cam[c].estado);
			
			printf("\n\nTem a certeza que quer eliminar? <S/N>");confere=toupper(getch());

			if (confere!='S')    return(0);

			cam[c].estado=0;
			printf("\n\n\nRegisto eliminado <Enter para continuar>\n");getch();  return (1);
		}
	}
	printf("ERRO! Numero não Encontrado\n");system("pause");return(0);
}

/**
*
*Funcao para gravar camioes
*\param c : int
*/
void gravar_camioes(camioes *cam)
{
	FILE *fc;
	int c;
	if(!(fc=fopen("camioes.txt","w")))
	{
		printf("\n\n\nErro na Abertura para Gravar\n");system("pause");exit(0);
	}
		
	for(c=1;c<NC;c++)
	{
		if(cam[c].estado==1)
		{
			fprintf(fc,"%d\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 
			cam[c].ncam, cam[c].matricula, cam[c].cm,cam[c].dpi.dia, cam[c].dpi.mes, 
			cam[c].dpi.ano, cam[c].custo, cam[c].ma, cam[c].situacao, cam[c].estado);
		}
	}
	fclose(fc);
	printf("\n\n\nFicheiro Gravado\n");getch();
}

/**
*
*Menu camioes
*\param op : int
*\param c : int
*/
void menu_camioes ()
{
		int op;
		int c;
		camioes cam[NC];
		for(c=0;c<NC;c++) //limpa array de registos da estrutura camioes
		cam[c].estado=0; 
		system("cls"); 
    	ler_camioes(cam);
	do {
		system ("cls");						        
		printf("\n\t|============================================|"); system("COLOR 0A");
    	printf("\n\t|              C E M  R O D A S              |");
    	printf("\n\t|                                            |");
	   	printf("\n\t|                                            |");
    	printf("\n\t|                C A M I O E S               |");
    	printf("\n\t|                                            |");
    	printf("\n\t|============================================|");
        printf("\n\t*                                            *"); 
        printf("\n\t*               1 - Inserir                  *");
        printf("\n\t*                                            *"); 
        printf("\n\t*               2 - Alterar                  *");
		printf("\n\t*                                            *"); 
        printf("\n\t*               3 - Eliminar                 *");
        printf("\n\t*                                            *");
        printf("\n\t*               4 - Gravar                   *");
		printf("\n\t*                                            *");
		printf("\n\t*               5 - Listar                   *");
		printf("\n\t*                                            *");
		printf("\n\t*               0 - Menu Principal           *");
		printf("\n\t*                                            *");
        printf("\n\t**********************************************");
        printf("\n\n\t             Qual a sua opcao? ");
				
				scanf("%d",&op);
               
				switch (op) {
                        case 1: inserir_camioes(cam); break;
                        case 2: alterar_camioes(cam); break;
                        case 3: eliminar_camioes(cam); break;
						case 4: gravar_camioes(cam); break;
						case 5: listar_camioes(cam); break;
						case 0: system ("cls"); break;
                        default: printf("Opcao invalida!\n");
                }
    } while (op!=0);
	
}
//MENU CAMIOES FIM

//MENU CONDUTORES INICIO

/**
*
*Funcao para ler condutores
*\param n : int
*/
void ler_condutores(condutores *con)
{
	FILE *fo;
	int n;
	if(!(fo=fopen("condutores.txt","r")))
	{
		fo=fopen("condutores.txt","w");
		printf("Foi criado o ficheiro condutores\n");
	}
	for(n=1;n<NO;n++)
	{
		
		{
			fscanf(fo,"%d\n%s\n%d\n%d\n%d\n%d\n%s\n%d\n%d\n",&con[n].numero,con[n].nome,&con[n].data_nas.dia,&con[n].data_nas.mes,&con[n].data_nas.ano,
			  &con[n].telefone,con[n].morada, &con[n].situacao, &con[n].estado);
		}
	}
		
	fclose(fo);
	printf("\n\nFicheiro Lido <Enter para continuar>\n"); getch();
}

/**
*
*Funcao para listar condutores
*\param n : int
*/
int listar_condutores (condutores *con)
{
    int n;
	system ("cls");
	printf("\n...A LISTAR CONDUTORES...\n\n");
	for(n=1;n<NO;n++)
		
	if(con[n].estado == 1)
        {
            printf("Condutor: %d\nNome: %s\nDia de Nascimento: %d\nMes de Nascimento: %d\nAno de Nascimento: %d\nTelefone: %d\nMorada: %s\nSituacao: %d\nEstado: %d\n\n", 
			con[n].numero, con[n].nome, con[n].data_nas.dia, con[n].data_nas.mes, con[n].data_nas.ano,	con[n].telefone, con[n].morada,	con[n].situacao,con[n].estado);
        }
			
		printf("\nListagem concluida <Enter> para voltar");getch();
}

/**
*
*Funcao para inserir condutores
*\param n : int
*\param inser : long int
*/
int inserir_condutores(condutores *con)
{
	int n;
	long int inser;
	system ("cls");
	printf("Qual o numero do condutor que quer inserir? [1-%d]?", NO);
		do
		{
			scanf("%ld",&inser);
			if (inser<1 || inser >= NO)
			{
				printf("\nNumero fora dos Parametros ?");
			}
				else
					break;
													
		}while(1);
	
	
	for(n=1;n<NO;n++)
	{
		if(con[n].estado!=1)
		{
			con[n].numero=inser;
			printf("\n\nNome: ");scanf("\n%s", con[n].nome);
			printf("\n\nDia de Nascimento: ");scanf("%d",&con[n].data_nas.dia);
			printf("\n\nMes de Nascimento: ");scanf("%d",&con[n].data_nas.mes);
			printf("\n\nAno de Nascimento: ");scanf("%d",&con[n].data_nas.ano);
			printf("\n\nTelefone: ");scanf("%ld", &con[n].telefone);
			printf("\n\nMorada: ");scanf("\n%s",con[n].morada);
			printf("\n\nSituacao 1-ocupado 0-livre: ");scanf("%d", &con[n].situacao);
			con[n].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para continuar>\n");
			getch();
			return(1);
		}
	}
	printf("ERRO! Não foi possivel inserir"); getch(); return(0);
}

/**
*
*Funcao para alterar condutores
*\param n : int
*\param confere : char
*\param alte : long int
*/
int alterar_condutores(condutores *con)
{
	int n;
	char confere;
	long int alte;
	system("cls");
	printf("Qual o numero do Condutor que quer alterar? "); scanf("%ld",&alte);
	for(n=1;n<NO;n++)
	{
		if(con[n].numero==alte)
		{
			printf("\nNome: %s\nData de Nascimento: %d/%d/%d\nTelefone: %d\nMorada: %s\nSituacao: %d\nEstado: %d\n\n"
			,con[n].nome, con[n].data_nas.dia, con[n].data_nas.mes, con[n].data_nas.ano, con[n].telefone, con[n].morada,con[n].situacao,con[n].estado);
            
			printf("\n\nQuer mesmo alterar? <S/N>");confere=getch();
				if (confere!='S' && confere!='s')    return(0);
				if(con[n].estado==1)
			printf("\n\nNome: ");scanf("\n%s", con[n].nome);
			printf("\n\nDia de Nascimento: ");scanf("%d",&(con[n].data_nas.dia));
			printf("\n\nMes de Nascimento: ");scanf("%d",&(con[n].data_nas.mes));
			printf("\n\nAno de Nascimento: ");scanf("%d",&(con[n].data_nas.ano));
			printf("\n\nTelefone: ");scanf("%d", &con[n].telefone);
			printf("\n\nMorada: ");scanf("\n%s",&con[n].morada);
			printf("\n\nSituacao 1-ocupado 0-livre: ");scanf("%d", &con[n].situacao);
			con[n].estado==1;
			printf("\n\n\nRegisto alterado com sucesso! <Enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);

}

/**
*
*Funcao para eliminar condutores
*\param confere : char
*\param n : int
*\param eli : long int
*/
int eliminar_condutores(condutores *con)
{
	char confere;
	int n;
	long int eli;
	system("cls");
	printf("Qual o numero do condutor que quer eliminar? "); scanf("%ld",&eli);
	for(n=1;n<NO;n++)
	{
		if(con[n].numero==eli)
		{
			printf("\nNome: %s\nData de Nascimento: %d/%d/%d\nTelefone: %d\nMorada: %s\nSituacao: %d\nEstado: %d\n\n"
			,con[n].nome, con[n].data_nas.dia, con[n].data_nas.mes, con[n].data_nas.ano, con[n].telefone, con[n].morada, con[n].situacao,con[n].estado);
			printf("\n\nTem a certeza que quer eliminar? <S/N>");

			if (confere!='S' && confere!='s')    return(0);

			con[n].estado=0;
			printf("\n\n\nRegisto eliminado <Enter para continuar>\n");getch();  return (1);
		}
	}
	printf("ERRO! Numero não Encontrado\n");system("pause");return(0);
}

/**
*
*Funcao para gravar condutores
*\param n : int
*/
void gravar_condutores (condutores *con)
{
	FILE *fo;
	int n;
	if(!(fo=fopen("condutores.txt","w")))
	{
		printf("\n\n\nErro na Abertura para Gravar\n");system("pause");exit(0);
	}

	for(n=1;n<NO;n++)
	{
		if(con[n].estado==1)
		{
			fprintf(fo,"%d\n%s\n%d\n%d\n%d\n%d\n%s\n%d\n%d\n",con[n].numero,con[n].nome,con[n].data_nas.dia,con[n].data_nas.mes,con[n].data_nas.ano,
			  con[n].telefone,con[n].morada, con[n].situacao, con[n].estado);
		}
	}
	fclose(fo);
	printf("\n\n\nFicheiro Gravado\n");getch();
}

/**
*
*Menu condutores
*\param op : int
*\param n : int
*/
int menu_condutores()
{
	int op;
	int n;
	condutores con[NO];
	for(n=1;n<NO;n++)
	con[n].estado=0; 
	system("cls"); 
    ler_condutores(con);  
	do{
		system ("cls");      
		printf("\n\t|============================================|"); system("COLOR 0A");
		printf("\n\t|              C E M  R O D A S              |");
		printf("\n\t|                                            |");
		printf("\n\t|                                            |");
		printf("\n\t|             C O N D U T O R E S            |");
		printf("\n\t|                                            |");
		printf("\n\t|============================================|");
		printf("\n\t*                                            *");
		printf("\n\t*               1 - Inserir                  *");
		printf("\n\t*                                            *");
		printf("\n\t*               2 - Alterar                  *");
		printf("\n\t*                                            *");
		printf("\n\t*               3 - Eliminar                 *");
		printf("\n\t*                                            *");
		printf("\n\t*               4 - Gravar                   *"); 
		printf("\n\t*                                            *");
		printf("\n\t*               5 - Listar                   *");
		printf("\n\t*                                            *");
		printf("\n\t*               0 - Menu Principal           *");
		printf("\n\t*                                            *");
		printf("\n\t**********************************************");
		printf("\n\t\t\tQual a sua opcao? "); scanf("%d",&op);
		switch(op)
		{
			case 1: inserir_condutores(con); break;
			case 2: alterar_condutores(con); break;
			case 3: eliminar_condutores(con); break;
			case 4: gravar_condutores(con);break;
			case 5: listar_condutores(con);break;
			case 0: system ("cls"); break;
            default: printf("Opcao invalida!\n");
		}
	}while (op!=0);
}

//FIM MENU CONDUTORES

//INICIO MENU CARGAS

/**
*
*Funcao para ler cargas
*\param ca : int
*/
void ler_cargas(cargas *car)
{
	FILE *fa;
	int ca;
	if(!(fa=fopen("cargas.txt","r")))
	{
		fa=fopen("cargas.txt","w");
		printf("Foi criado o ficheiro Cargas\n");
	}
	for(ca=1;ca<NA;ca++)
	{
		fscanf(fa,"%d\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",&car[ca].numero,car[ca].nome_cliente,
		car[ca].local_origem,car[ca].local_destino,&car[ca].distancia, &car[ca].peso,&car[ca].data_trans.dia, 
		&car[ca].data_trans.mes, &car[ca].data_trans.ano, &car[ca].situacao, &car[ca].estado);
	}
	fclose(fa);
	printf("\n\n\nFicheiro Lido <Enter para Continuar>");getch();
}

/**
*
*Funcao para listar cargas
*\param ca : int
*/
int listar_cargas(cargas *car)
{
	
    int ca;
	system ("cls");
	printf("\n...A LISTAR CARGAS...\n\n");
	 for(ca=1;ca<NA;ca++)
		
            if(car[ca].estado==1)
			{
				printf("Numero: %d\nNome do Cliente: %s\nLocal de Origem da Carga: %s\nLocal de Destino da Carga: %s\nDistancia da Origem ao Destino: %d\nPeso da Carga: %d\nDia do Transporte: %d\nMes do Transporte: %d\nAno do Transporte: %d\nSituacao: %d\nEstado: %d\n\n",
				car[ca].numero,car[ca].nome_cliente,car[ca].local_origem,car[ca].local_destino,car[ca].distancia,car[ca].peso,
        		car[ca].data_trans.dia,car[ca].data_trans.mes,car[ca].data_trans.ano,car[ca].situacao,car[ca].estado);		     
			}
	
		
	printf("\n\n\nListagem Concluida <Enter para Continuar>");
	getch();
}

/**
*
*Funcao para inserir cargas
*\param ca : int
*\param inser : long int
*/
int inserir_cargas(cargas *car)
{
	int ca;
	long int inser;
	system ("cls");
	printf("Insira um numero para a carga? [1-%d]?", NA);
		do
		{
			scanf("%ld",&inser);
			if (inser<1 || inser >= NA)
			{
				printf("\nNumero fora dos Parametros ?");
			}
				else
					break;
													
		}while(1);
		
	for(ca=1;ca<NA;ca++)
	{
		if(car[ca].estado!=1)
		{
			car[ca].numero=inser;
			printf("\n\nNome do cliente: ");scanf("\n%s", car[ca].nome_cliente);
			printf("\n\nLocal de Origem da Carga: ");scanf("%s",car[ca].local_origem);
			printf("\n\nLocal de Destino da Carga: ");scanf("%s",car[ca].local_destino);
			printf("\n\nDistancia da Origem ao Destino KM: ");scanf("%d",&car[ca].distancia);
			printf("\n\nPeso da Carga KG: ");scanf("%d", &car[ca].peso);
			printf("\n\nDia do Transporte: ");scanf("%d",&car[ca].data_trans.dia);
			printf("\n\nMes do Transporte: ");scanf("%d",&car[ca].data_trans.mes);
			printf("\n\nAno do Transporte: ");scanf("%d",&car[ca].data_trans.ano);
			car[ca].situacao=0;
			car[ca].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
			return(1);
		}
	}
	printf("ERRO! Nao foi possivel Inserir"); getch(); return(0);
}

/**
*
*Funcao para alterar cargas
*\param ca : int
*\param confere : char
*\param alte : long int
*/
int alterar_cargas(cargas *car)
	{
	int ca;
	char confere;
	long int alte;
	system("cls");
	printf("Qual o numero da carga que deseja alterar? "); scanf("%ld",&alte);
	for(ca=1;ca<NA;ca++)
	{
		if(car[ca].numero==alte)
		{
		printf("\nNome do Cliente: %s\nLocal de Origem da Carga: %s\nLocal de Destino da Carga: %s\nDistancia da Origem ao Destino: %d\nPeso da Carga: %d\nDia do Transporte: %d\nMes do Transporte: %d\nAno do Transporte: %d\nSituacao: %d\n\n",
		car[ca].nome_cliente,
        car[ca].local_origem,
        car[ca].local_destino,
        car[ca].distancia,
        car[ca].peso,
        car[ca].data_trans.dia,
        car[ca].data_trans.mes, 
        car[ca].data_trans.ano,
		car[ca].situacao);
		
		printf("\n\nQuer mesmo alterar? <S/N>");confere=getch();
				if (confere!='S' && confere!='s')    return(0);
				if(car[ca].estado==1)
       		printf("\n\nNome do cliente: ");scanf("\n%s", car[ca].nome_cliente);
			printf("\n\nLocal de Origem da Carga: ");scanf("%s",car[ca].local_origem);
			printf("\n\nLocal de Destino da Carga: ");scanf("%s",car[ca].local_destino);
			printf("\n\nDistancia da Origem ao Destino: ");scanf("%d",&car[ca].distancia);
			printf("\n\nPeso da Carga: ");scanf("%d", &car[ca].peso);
			printf("\n\nDia do Transporte: ");scanf("%d",&car[ca].data_trans.dia);
			printf("\n\nMes do Transporte: ");scanf("%d",&car[ca].data_trans.mes);
			printf("\n\nAno do Transporte: ");scanf("%d",&car[ca].data_trans.ano);
			car[ca].situacao=0;
			car[ca].estado=1;
			printf("\n\n\nRegisto alterado <enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);

}

/**
*
*Funcao para eliminar cargas
*\param confere : char
*\param ca : int
*\param eli : long int
*/
int eliminar_cargas(cargas *car)
{
	char confere;
	int ca; 
	long int eli;
	system("cls");
	printf("Qual o Numero da carga que quer Eliminar? "); scanf("%ld",&eli);
	for(ca=1;ca<NA;ca++)
	{
		if(car[ca].numero==eli)
		{
		printf("\nNome do Cliente: %s\nLocal de Origem da Carga: %s\nLocal de Destino da Carga: %s\nDistancia da Origem ao Destino: %d\nPeso da Carga: %d\nDia do Transporte: %d\nMes do Transporte: %d\nAno do Transporte: %d\nSituacao: %d\nEstado: %d\n\n",
		car[ca].nome_cliente,
        car[ca].local_origem,
        car[ca].local_destino,
        car[ca].distancia,
        car[ca].peso,
        car[ca].data_trans.dia,
        car[ca].data_trans.mes, 
        car[ca].data_trans.ano,
		car[ca].situacao,
		car[ca].estado);
		printf("\n\nQuer mesmo eliminar? <S/N>");confere=getch();

		if (confere!='S' && confere!='s')    return(0);

		car[ca].estado=0;
		
		printf("\n\n\nRegisto eliminado <enter para continuar>");
		getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);
}

/**
*
*Funcao para gravar cargas
*\param ca : int
*/
void gravar_cargas(cargas *car)
{
	FILE *fa;
	int ca;
	if(!(fa=fopen("cargas.txt","w")))
	{
		printf("\n\n\nErro na Abertura para Gravar <Enter para Sair>");
		getch();  exit(0);
	}
	    
    for(ca=1;ca<NA;ca++)
	{
		if(car[ca].estado==1)
		{
			fprintf(fa,"%d\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",car[ca].numero,car[ca].nome_cliente,
			car[ca].local_origem,car[ca].local_destino,car[ca].distancia,car[ca].peso,car[ca].data_trans.dia, car[ca].data_trans.mes, car[ca].data_trans.ano, car[ca].situacao, car[ca].estado);
		}
	}
	fclose(fa);
	printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); getch();
}

/**
*
*Menu cargas
*\param op : int
*\param ca : int
*/
int menu_cargas ()
{
	FILE *fa;
	int op;
	int ca;
	cargas car[NA];

    for(ca=1;ca<NA;ca++)
	car[ca].estado=0;
	system("cls");
	ler_cargas(car);
	
	do {
		system ("cls");						        
		printf("\n\t|============================================|"); system("COLOR 0A");
    	printf("\n\t|              C E M  R O D A S              |");
    	printf("\n\t|                                            |");
	   	printf("\n\t|                                            |");
    	printf("\n\t|                 C A R G A S                |");
    	printf("\n\t|                                            |");
    	printf("\n\t|============================================|");
        printf("\n\t*                                            *"); 
        printf("\n\t*               1 - Inserir                  *");
		printf("\n\t*                                            *"); 
        printf("\n\t*               2 - Alterar                  *");
        printf("\n\t*                                            *");
        printf("\n\t*               3 - Eliminar                 *");
	    printf("\n\t*                                            *");
        printf("\n\t*               4 - Gravar                   *");
		printf("\n\t*                                            *");
		printf("\n\t*               5 - Listar                   *");
		printf("\n\t*                                            *");
		printf("\n\t*               0 - Menu Principal           *");
		printf("\n\t*                                            *");
        printf("\n\t**********************************************");
        printf("\n\n\t             Qual a sua opcao? ");
				
				scanf("%d",&op);
               
				switch (op) 
                {
                        case 1: inserir_cargas(car); break;
                        case 2: alterar_cargas(car); break;
					    case 3: eliminar_cargas(car); break;
						case 4: gravar_cargas(car); break;
						case 5: listar_cargas(car); break;
						case 0: system ("cls"); break;
                        default: printf("Opcao invalida!\n");
                }
    
    }while (op !=0);
}
//FIM DO MENU CARGAS

//INICIO DO MENU LISTAGENS


/**
*
*Funcao para listar a frota de camioes
*\param c : int
*/
void listar_1 ()
{
    camioes cam[NC];
	int c;
	system ("cls");
	for(c=0;c<NC;c++) //limpa array de registos
	cam[c].estado=0;
	//ler_camioes(cam);
	printf("\n...A LISTAR CAMIOES...\n");
	for(c=1;c<NC;c++)
		if(cam[c].estado==1)
		{
        printf("\nNumero: %d\nMatricula: %s\nCarga Maxima KG: %d\nData inspeccao: %d\t%d\t%d\nCusto KM: %d\nMotorista Camiao: %d\nSituacao 1-Ocupado 0-Livre: %d\nEstado: %d\n",
		cam[c].ncam,cam[c].matricula,cam[c].cm,cam[c].dpi.dia,cam[c].dpi.mes,cam[c].dpi.ano,cam[c].custo,cam[c].ma,cam[c].situacao,cam[c].estado);
		}
	
	printf("\nListagem concluida <Enter para voltar>");getch();
}

/**
*
*Funcao para listar cargas por camiao
*\param ca : int
*/
void listar_2 ()
{
	cargas car[NA];
	FILE *fa;
	int ca;
	if(!(fa=fopen("cargas.txt","r")))
	{
		fa=fopen("cargas.txt","w");
		printf("Foi criado o ficheiro Cargas\n");
	
	}
	for(ca=1;ca<NA;ca++)
	{
		fscanf(fa,"%d\n%s\n%s\n%s\n%d\n%.2f\n%d\n%d\n%d\n%d\n%d\n",&car[ca].numero,car[ca].nome_cliente,
		car[ca].local_origem,car[ca].local_destino,&car[ca].distancia, &car[ca].peso,&car[ca].data_trans.dia, 
		&car[ca].data_trans.mes, &car[ca].data_trans.ano, &car[ca].situacao, &car[ca].estado);
	}
	for(ca=1;ca<NA;ca++)
	{
							
            if(car[ca].estado==1)
			{
				printf("Numero: %d\nNome do Cliente: %s\nLocal de Origem da Carga: %s\nLocal de Destino da Carga: %s\nDistancia da Origem ao Destino: %d\nPeso da Carga: %.2f\nDia do Transporte: %d\nMes do Transporte: %d\nAno do Transporte: %d\nEstado: %d\nSituacao: %d\n\n",
				car[ca].numero,car[ca].nome_cliente,car[ca].local_origem,car[ca].local_destino,car[ca].distancia,car[ca].peso,
        		car[ca].data_trans.dia,car[ca].data_trans.mes,car[ca].data_trans.ano,car[ca].situacao,car[ca].estado);		     
			}
	
		
	}printf("\n\n\nListagem Concluida <Enter para Continuar>");
	getch();
	
	fclose(fa);
	printf("\n\n\nFicheiro Lido <Enter para Continuar>");getch();

}

/**
*
*Funcao para listar camioes com inspeccao mes corrente
*\param c : int
*\param insp : char
*/
void listar_4 ()
{
    camioes cam[NC];
	int c;
	char insp;
	system("cls");
	printf("Qual o Mes que quer verificar? "); scanf("%s",&insp);
	printf("\n...CAMIOES COM INSPECCAO NO MES (%ld):\n\n",insp);
	for(c=1;c<NC;c++)
	{
		
		if(cam[c].estado==1 && cam[c].dpi.mes==insp)
    	
		{
        printf("\nNumero: %d\nMatricula: %s\nCarga Maxima KG: %d\nData inspeccao: %d\t%d\t%d\nCusto KM: %d\nMotorista Camiao: %d\nSituacao 1-Ocupado 0-Livre: %d\nEstado: %d\n",
		cam[c].ncam,cam[c].matricula,cam[c].cm,cam[c].dpi.dia,cam[c].dpi.mes,cam[c].dpi.ano,cam[c].custo,cam[c].ma,cam[c].situacao,cam[c].estado);
		}
	}
	printf("\nListagem concluida <Enter para voltar>");getch();
}


/**
*
*Funcao para listar clientes
*\param n : int
*/
void listar_6 ()
{
	int n;
	
	clientes cli[NI];
	for(n=0;n<NI;n++) //limpa array de registos
	cli[n].estado=0; 


	system ("cls");printf("\n...A LISTAR CLIENTES...\n");
	for(n=1;n<NI;n++)
	{
	
	if(cli[n].estado == 1)
        	
		{
            printf("\nNumero: %ld\nNome: %s\nMorada: %s\nTelefone: %ld\nEstado: %d\n",cli[n].numero,cli[n].nome,cli[n].morada,cli[n].telefone, cli[n].estado);
		}
	}
	
	printf("\nListagem concluida <Enter para voltar>");getch();
}


/**
*
*Menu listagens
*\param n : int
*\param c : int
*\param m : int
*\param a : int
*\param op : int
*/
void menu_listagens ()
{
	int n, c, m,a;
	int op;
	clientes cli[NI];
	for(n=0;n<NI;n++) //limpa array de registos
	cli[n].estado=0; 
	
	camioes cam[NC];
	for(c=0;c<NC;c++) //limpa array de registos
	cam[c].estado=0;
	
	condutores con[NO];
	for(m=0;m<NO;m++) //limpa array de registos
	con[m].estado=0;
	
	cargas car[NA];
	for(a=0;a<NA;a++) //limpa array de registos
	car[a].estado=0;
	ler_clientes(cli);
	ler_camioes(cam);
	ler_condutores(con);
	ler_cargas(car);
	do {
		system ("cls");						        
		printf("\n\t|============================================|"); system("COLOR 0A");
    	printf("\n\t|              C E M  R O D A S              |");
    	printf("\n\t|                                            |");
	   	printf("\n\t|                                            |");
    	printf("\n\t|              L I S T A G E N S             |");
    	printf("\n\t|                                            |");
    	printf("\n\t|============================================|");
        printf("\n\t*                                            *"); 
        printf("\n\t*  1 - Frota de Camioes                      *");
        printf("\n\t*                                            *"); 
        printf("\n\t*  2 - Listar Cargas                         *");
		printf("\n\t*                                            *"); 
        printf("\n\t*  3 - Transportes/Custo por Cliente         *");
        printf("\n\t*                                            *");
        printf("\n\t*  4 - Camioes c/ Inspeccao no Mes Corrente  *");
		printf("\n\t*                                            *");
		printf("\n\t*  5 - Listar condutores                     *");
		printf("\n\t*                                            *");
		printf("\n\t*  6 - Listar clientes                       *");
		printf("\n\t*                                            *");
        printf("\n\t*  0 - Menu Principal                        *");
		printf("\n\t*                                            *");
        printf("\n\t**********************************************");
        printf("\n\n\t             Qual a sua opcao? ");
				
				scanf("%d",&op);
               
				switch (op) {
                        case 1: listar_camioes(cam); break;
                        case 2: listar_cargas(car); break;
                        case 3: printf("listar_3"); break;
						case 4: listar_4(cam); break;
						case 5: listar_condutores(con); break;
						case 6: listar_clientes(cli); break;		
						case 0: system ("cls"); break;
                        default: printf("Opcao invalida!\n");
                }
    } while (op!=0);
	
}
//Fim do menu listagens

//Menu Pesquisa

/**
*
*Funcao para pesquisar camioes por destino
*\param ca : int
*\param destino : char
*/
void pesquisa_2 ()
{
    camioes cam[NC];
	ler_camioes(cam);
	cargas car[NA];
	ler_cargas(car);
	int ca;
	char destino;
	system ("cls");
	printf("Qual o Destino pretendido? "); scanf("%s",destino);
	printf("\n...A LISTAR CARGAS...\n");
	for(ca=1;ca<NA;ca++)
		if(car[ca].estado==1  && car[ca].local_destino==destino)
		{
        printf("Numero: %d\nNome do Cliente: %s\nLocal de Origem da Carga: %s\nLocal de Destino da Carga: %s\nDistancia da Origem ao Destino: %d\nPeso da Carga: %d\nDia do Transporte: %d\nMes do Transporte: %d\nAno do Transporte: %d\n\n",
				car[ca].numero,car[ca].nome_cliente,car[ca].local_origem,car[ca].local_destino,car[ca].distancia,car[ca].peso,
        		car[ca].data_trans.dia,car[ca].data_trans.mes,car[ca].data_trans.ano);
		}
	
	printf("\nListagem concluida <Enter para voltar>");getch();
}


/**
*
*Menu pesquisa
*\param op : int
*\param c : int
*/
int menu_pesquisa ()
{
	int op;
	int c,n;
	camioes cam[NC];
	for(c=0;c<NC;c++) //limpa array de registos
	cam[c].estado=0;
	cargas car[NA];
	for(n=0;n<NA;n++) //limpa array de registos
	car[n].estado=0;
	ler_camioes(cam);
	ler_cargas(car);
	
	do {
		system ("cls");						        
		printf("\n\t|============================================|"); system("COLOR 0A");
    	printf("\n\t|              C E M  R O D A S              |");
    	printf("\n\t|                                            |");
	   	printf("\n\t|                                            |");
    	printf("\n\t|              P E S Q U I S A               |");
    	printf("\n\t|                                            |");
    	printf("\n\t|============================================|");
        printf("\n\t*                                            *"); 
        printf("\n\t*     1 - Camioes disponiveis por data       *");
        printf("\n\t*                                            *"); 
        printf("\n\t*     2 - Camioes por Destino                *");
		printf("\n\t*                                            *"); 
        printf("\n\t*     3 - Camioes por Carga Maxima           *");
        printf("\n\t*                                            *");
        printf("\n\t*     0 - Menu Principal                     *");
		printf("\n\t*                                            *");
        printf("\n\t**********************************************");
        printf("\n\n\t             Qual a sua opcao? ");
				
				scanf("%d",&op);
               
				switch (op) {
                        case 1: printf("..."); break;
                        case 2: pesquisa_2(cam, car); break;
                        case 3: printf("..."); break;
						case 0: system ("cls"); break;
                        default: printf("Opcao invalida!\n");
                }
    } while (op!=0);
	
}

/**
*
*Menu estatistica
*\param op : int
*/
int menu_estatistica ()
{
	int op;
	do {
		system ("cls");						        
		printf("\n\t|============================================|"); system("COLOR 0A");
    	printf("\n\t|              C E M  R O D A S              |");
    	printf("\n\t|                                            |");
	   	printf("\n\t|                                            |");
    	printf("\n\t|           E S T A T I S T I C A            |");
    	printf("\n\t|                                            |");
    	printf("\n\t|============================================|");
        printf("\n\t*                                            *"); 
        printf("\n\t*      1 - Condutor c/ Mais Viagens          *");
        printf("\n\t*                                            *"); 
        printf("\n\t*      2 - Distancia Media de Viagens        *");
		printf("\n\t*                                            *"); 
        printf("\n\t*      3 - Condutor Mais Velho               *");
        printf("\n\t*                                            *");
        printf("\n\t*      4 - Destino Mais Frequente            *");
		printf("\n\t*                                            *");
        printf("\n\t*      0 - Menu Principal                    *");
		printf("\n\t*                                            *");
        printf("\n\t**********************************************");
        printf("\n\n\t             Qual a sua opcao? ");
				
				scanf("%d",&op);
               
				switch (op) {
                        case 1: printf("..."); break;
                        case 2: printf("..."); break;
                        case 3: printf("..."); break;
						case 4: printf("..."); break;
						case 0: system ("cls"); break;
                        default: printf("Opcao invalida!\n");
                }
    } while (op!=0);
	
}
        
/**
*
*Menu Orcamento
*\param klm : float
*\param toneladas : float
*\param res1 : float
*/        
int orcamento()
{
    	float klm,toneladas;
    	float res1;
    	system("cls");
        printf("\n\t|======================================================|"); system("COLOR 0A");
    	printf("\n\t|                  C E M  R O D A S                    |");
    	printf("\n\t|                                                      |");
	   	printf("\n\t|                                                      |");
    	printf("\n\t|                 O R C A M E N T O S                  |");
    	printf("\n\t|                                                      |");
    	printf("\n\t|======================================================|");
         
	
	    	do {
			printf("\n\n\t Introduza o numero de kilometros da viagem: ");
	    	scanf("%f",&klm);
	    	if (klm<100) {
				printf("\t Valor minimo: 100 kilometros!");
	    	}else break;
			} while (1);
			
			do {
			printf("\n\t Introduza o numero de toneladas a transportar: ");
	    	scanf("%f",&toneladas);
	    	if (toneladas<1) {
	    		printf("\t Valor minimo: 1 Tonelada!");
			}else break;
			} while (1);
			
			res1=1*klm+50*toneladas;
	    	printf("\n\t A sua viagem tem o valor de: %.2f euros",res1);
	        printf("\n\n\n\t Orcamento Concluido <Enter para Continuar>");
	        getch();system ("cls");return(0);
	
}  


/**
*
*Menu para iniciar um transporte
*\param carga : long int
*\param camiao : long int
*\param cliente : long int
*\param condutor : long int
*\param n : int
*\param ca : int
*\param o : int
*\param c : int
*/
int menu_inic_viag ()
{
	FILE *fh;
	FILE *fa;
	fa=fopen("cargas.txt","r");
		
	long int carga, camiao, cliente, condutor;
	int n,ca,o,c;
	cargas car[NA];
	for(n=0;n<NA;n++) //limpa array de registos
	car[n].estado=0;
	camioes cam[NC];
	for(o=0;o<NC;o++) //limpa array de registos
	cam[o].estado=0;
	
	ler_cargas(car);
	ler_camioes(cam);
	
	system("cls");
        printf("\n\t|======================================================|"); system("COLOR 0A");
    	printf("\n\t|                  C E M  R O D A S                    |");
    	printf("\n\t|                                                      |");
	   	printf("\n\t|                                                      |");
    	printf("\n\t|            I N I C I A R    V I A G E M              |");
    	printf("\n\t|                                                      |");
    	printf("\n\t|======================================================|");
    	
    	system ("cls");
		printf("Introduza a carga a ser entregue [1-%d]: ", NA);
			scanf("%ld",&carga);
			printf("\nCarga a ser transportada: ");
			
			for(ca=1;ca<NA;ca++)
	    {
	    	       		
			if (car[ca].numero==carga && car[ca].estado==1)
			{
				printf("\n\nNumero: %d\nNome do Cliente: %s\nLocal de Origem da Carga: %s\nLocal de Destino da Carga: %s\nDistancia da Origem ao Destino KM: %d\nPeso da Carga KG: %d\nData do Transporte: %d/%d/%d\n\n",
				car[ca].numero,car[ca].nome_cliente,car[ca].local_origem,car[ca].local_destino,car[ca].distancia,car[ca].peso,
        		car[ca].data_trans.dia,car[ca].data_trans.mes,car[ca].data_trans.ano);
				printf("\nCarga atribuida\n");	     
			}
		}				
						
			printf("\nIntroduza o camiao para efectuar o transporte [1-%d]: ", NC);
		
			scanf("%ld",&camiao);
					
			for(c=1;c<NC;c++)
	    {
	    	       		
			if (cam[c].ncam==camiao)
			{
				printf("\nNumero: %d\nMatricula: %s\nCarga Maxima KG: %d\nData inspeccao: %d/%d/%d\nCusto KM(EUROS): %d\nMotorista Camiao: %d\n",
				cam[c].ncam,cam[c].matricula,cam[c].cm,cam[c].dpi.dia,cam[c].dpi.mes,cam[c].dpi.ano,cam[c].custo,cam[c].ma);
			    printf("\n\nCamiao atribuido <enter para continuar>");getch();
			}
		}
			system("cls");
			
			printf ("O camiao %ld \niniciou viagem transportando a carga %d ",camiao,car[ca].numero);getch();
			fh=fopen("historico.txt","a+");
			fprintf (fh,"%ld\n%d\n%s",camiao,car[ca].numero, car[ca].local_destino);system("cls");
			
			car[ca].situacao=1;
			cam[c].ncam=1;	
						
				
			fclose(fh);
			fclose(fa);
		
}

/**
*
*Main (Menu Principal)
*\param op : int
*/
int main(void) 
{

    	
		clientes cli[NI];
	    camioes cam[NC];
	    condutores con[NO]; 
		cargas car[NA];
        iniciar_ficheiros (cli,cam,con,car);system ("cls");
	
		int op;
        do {
        printf("\n\t|============================================|"); system("COLOR 0A");
    	printf("\n\t|       G E S T A O  D E  C A R G A S        |");
    	printf("\n\t|             C E M   R O D A S              |");
    	printf("\n\t|                                            |");
        printf("\n\t|         M E N U  P R I N C I P A L         |");
    	printf("\n\t|============================================|");
		printf("\n\t*                                            *"); 
        printf("\n\t*              1 - Clientes                  *");
        printf("\n\t*                                            *"); 
        printf("\n\t*              2 - Camioes                   *");
		printf("\n\t*                                            *"); 
        printf("\n\t*              3 - Condutores                *");
        printf("\n\t*                                            *");
        printf("\n\t*              4 - Cargas                    *");
		printf("\n\t*                                            *");
        printf("\n\t*              5 - Listagens                 *");
        printf("\n\t*                                            *");
        printf("\n\t*              6 - Pesquisa                  *");
        printf("\n\t*                                            *");
        printf("\n\t*              7 - Estatisticas              *");
        printf("\n\t*                                            *");
        printf("\n\t*              8 - Orcamento                 *");
        printf("\n\t*                                            *");
		printf("\n\t*              9 - Iniciar Viagem            *");
		printf("\n\t*                                            *");
        printf("\n\t*                                            *");
        printf("\n\t*              0 - Sair                      *");
		printf("\n\t*                                            *");
        printf("\n\t**********************************************");
        printf("\n\n\t             Qual a sua opcao? ");
               
			     scanf("%d",&op);
        
				 switch (op) {
                        case 1: menu_clientes();break; 									/*menu_clientes(alunos, na); break;*/
    	 				case 2: menu_camioes();break;
		 				case 3: menu_condutores();break;
    	 				case 4: menu_cargas(car);break;
		 				case 5: menu_listagens();break;
         				case 6: menu_pesquisa();break;
		 				case 7: menu_estatistica();break;
		 				case 8: orcamento();break;   
     	 				case 9: menu_inic_viag();break;
		 				case 0: system ("cls");break;
		 				default: printf("Opcao invalida.\n");
         		}
         		
       } while (op!=0);
        printf("Fim!\n");
        return 0;
}
