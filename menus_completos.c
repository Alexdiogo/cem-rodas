#include <stdio.h>
#include <windows.h> 
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#define NI 10              // numero maximo de clientes
#define NC 100              // numero maximo de camioes
#define NO 100              // numero maximo de condutores
#define NA 10              // numero maximo de cargas


//estrutura tipo data	
typedef struct
{
    int dia;
    int mes;
    int ano;
}data; 

//estrutura dos clientes
typedef struct  
    {
		long int numero;
		char nome[50];
		char morada[60];
		long int telefone;
		int estado;
	}clientes;

//estrutura dos camioes
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
  
//estrutura dos condutores
typedef struct{
	int numero;
	char nome[50];
    data data_nas;			
	int telefone;
	char morada[50];
	int situacao;		// 1= ocupado 0=livre
	int estado;			// 1=activo 0=apagado		
}condutores;

//estrutura das cargas
typedef struct
{
	int numero;
	char nome_cliente[50];
	char local_origem[30];
	char local_destino[30];
	int distancia;
	float peso;
	data data_trans;
	int situacao;			// 1=atribuida 0= nao atribuida
	int estado;				// 1=activo 0=apagado
}cargas;


// iniciar ficheiros txt
void iniciar_ficheiros (clientes *cli, camioes *cam, condutores *con, cargas *car)
{
    int n, m, d, c;
    FILE *fi, *fc, *fo, *fa;
     
    //Criar o ficheiro inicial de clientes
        if(!(fi=fopen("clientes.txt ","r")))
	{
		fi=fopen("clientes.txt","w");
		for(n=1;n<NI;n++)
    	{    	
		fprintf(fi,"%d\n%s\n%s\n%d\n%d\n",n,"Nome","Morada",289123123,1);
    	}
		printf("\n\nFoi criado clientes.txt <Enter para Continuar>");getch();
	}
	 fclose(fi);
    
	//Criar o ficheiro inicial de camioes
    	if(!(fc=fopen("camioes.txt","r")))
    {
    	fc=fopen("camioes.txt","w");
    	//fprintf(fc,"%d\n%s\n%d\n%s\n%d\n%d\n%d\n%d",0,"Matricula",10000,12,12,2014,20,1,1,0);
    	printf("\nFoi criado camioes.txt <Enter para Continuar>");getch();
	}
	 fclose(fc);
    
	//Criar o ficheiro inicial de condutores
        if(!(fo=fopen("condutores.txt","r")))
	{
		fo=fopen("condutores.txt","w");
    	//fprintf(fo,"%d\n%s\n%d\n%d\n%d\n%d\n%s\n%d\n%d\n\n", 1,"Nome_condutor",12,12,2000,289123123,"Morada",1,0);
   		printf("\nFoi criado condutores.txt <Enter para Continuar>");getch();
	}
	 fclose(fo);
    
	 //Criar o ficheiro inicial de cargas
    if(!(fa=fopen("cargas.txt","r")))
	{
		fa=fopen("cargas.txt","w");
		for(c=1;c<NA;c++) 
    	{
    	fprintf(fa,"%d\n%s\n%s\n%s\n%d\n%.2f\n%d\n%d\n%d\n%d\n%d",c,"Nome_cliente","Local_origem","Local_destino",300,100,12,12,2014,0,1);
		}
		printf("\nFoi criado cargas.txt <Enter para Continuar>");getch();
    }
     fclose(fa);
}

//Ler clientes
void ler_clientes(clientes *cli)
{
			
	FILE *fi;
	int n,c;
	
	if(!(fi=fopen("clientes.txt","r")))
	{
		fi=fopen("clientes.txt","w");
		printf("Foi criado o ficheiro clientes\n");
	}
	rewind (fi);
	for(n=1;n<NI;n++)
	{
		//if(cli[n].estado==1)
		{
			fscanf(fi,"%ld\n%s\n%s\n%ld\n%d\n", &cli[n].numero, cli[n].nome, cli[n].morada, &cli[n].telefone, &cli[n].estado);
			printf("\nNumero: %ld\nNome: %s\nMorada: %s\nTelefone: %ld\nEstado: %d\n",cli[n].numero,cli[n].nome,cli[n].morada,cli[n].telefone, cli[n].estado);
		}
	}
	
	fclose(fi);
	printf("\n\nFicheiro Lido\n<Enter para continuar>\n"); getch();
}

//Listar clientes
void listar_clientes (clientes *cli)
{
    
    FILE *fi;
	int n,c;
	//for(n=0;n<NI;n++)
	//	cli[n].estado=0;
	//fi=fopen("clientes.txt","r");
	
	/*for(n=1;n<NI;n++)
	{
		fscanf(fi,"%ld\n%[^\n]s\n%[^\n]s\n%ld\n%d\n",cli[n].numero, cli[n].nome, cli[n].morada, cli[n].telefone, cli[n].estado);
	}*/
	system ("cls");printf("\n...A LISTAR CLIENTES...\n");
	for(n=1;n<NI;n++)
	{
	
	if(cli[n].estado == 1)
        	
		{
            printf("\nNumero: %ld\nNome: %s\nMorada: %s\nTelefone: %ld\nEstado: %d\n",cli[n].numero,cli[n].nome,cli[n].morada,cli[n].telefone, cli[n].estado);
		}
	}
	//fclose(fi);
	printf("\nListagem concluida <Enter para voltar>");getch();
}

//Inserir clientes 
int inserir_clientes(clientes *cli)
{
		
	int n;
	long int inser;
	system ("cls");
	printf("Qual o numero do cliente que quer inserir? [1-%d]?", NI);
		do
		{
			scanf("%ld",&inser);
			if (inser<1 || inser >= NI)
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

//Alterar clientes
int alterar_clientes(clientes *cli)
{
	int n;
	char confere;
	long int alte;
	system("cls");
	printf("Qual o numero do Cliente que quer alterar? "); scanf("%ld",&alte);
	for(n=1;n<NI;n++)
	{
		if(cli[n].numero==alte)
		{
			printf("\nNome: %s\nMorada: %s\nTelefone: %d\n\n",cli[n].nome, cli[n].morada, cli[n].telefone);
            printf("\n\nQuer mesmo alterar? <S/N>");confere=getch();
				if (confere!='S' && confere!='s')    return(0);
					
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

//Eliminar clientes
int eliminar_clientes(clientes *cli)
{
	char confere;
	int n;
	long int eli;
	system("cls");
	printf("Qual o numero do cliente que quer eliminar? "); scanf("%ld",&eli);
	for(n=1;n<NI;n++)
	{
		if(cli[n].numero==eli)
		{
			printf("\nNumero: %d\nNome: %s\nMorada: %s\nTelefone: %d\n\n",cli[n].numero, cli[n].nome, cli[n].morada, cli[n].telefone);
			printf("\n\nTem a certeza que quer eliminar? <S/N>");confere=toupper(getch());

			if (confere!='S' && confere!='s')    return(0);

			cli[n].estado=0;
			printf("\n\n\nRegisto eliminado <Enter para continuar>\n");getch();  return (1);
		}
	}
	printf("ERRO! Numero não Encontrado\n");system("pause");return(0);
}

//Gravar clientes
void gravar_clientes(clientes *cli)
{
	FILE *fi;
	int n;
	if(!(fi=fopen("clientes.txt","w")))
	{
		printf("\n\n\nErro na Abertura para Gravar\n");system("pause");exit(0);
	}

		
	for(n=1;n<NI;n++)
	{
		if(cli[n].estado==1)
		{
			fprintf(fi,"%ld\n%s\n%s\n%d\n%d\n",cli[n].numero,cli[n].nome,cli[n].morada,cli[n].telefone,cli[n].estado);
		}
	}
	fclose(fi);
	printf("\n\n\nFicheiro Gravado\n");getch();
}

// MENU CLIENTES
int menu_clientes() 
		{
        	int op;
			int n;
			clientes cli[NI];
			for(n=0;n<NI;n++) //limpa array de registos
			cli[n].estado=0; 
			system("cls"); 
    		ler_clientes(cli);
		do {
        
		system ("cls");						        
		printf("\n\t|============================================|"); system("COLOR 0F");
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

//Ler camioes
void ler_camioes(camioes *cam)
{
	FILE *fc;
	int n,c;
	
	if(!(fc=fopen("camioes.txt","r")))
	{
		fc=fopen("camioes.txt","w");
		printf("Foi criado o ficheiro camioes.txt\n");
	}
	for(c=1;c<NC;c++)
	{
		//if(cli[n].estado==1)
		{
			fscanf(fc,"%d\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 
			&cam[c].ncam, &cam[c].matricula, &cam[c].cm,&cam[c].dpi.dia, &cam[c].dpi.mes, 
			&cam[c].dpi.ano, &cam[c].custo, &cam[c].ma, &cam[c].situacao, &cam[c].estado);
		}
	}
	fclose(fc);
	printf("\n\nFicheiro Lido\n<Enter para continuar>\n"); getch();
}

//Listar camioes
int listar_camioes (camioes *cam)
{
    FILE *fc;
	int n,c;
	fc=fopen("camioes.txt","r");
	for(c=1;c<NC;c++)
	{
		fscanf(fc,"%d\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 
			&cam[c].ncam, &cam[c].matricula, &cam[c].cm,&cam[c].dpi.dia, &cam[c].dpi.mes, 
			&cam[c].dpi.ano, &cam[c].custo, &cam[c].ma, &cam[c].situacao, &cam[c].estado);
	}
	system ("cls");printf("\n...A LISTAR CAMIOES...\n");
	for(c=1;c<NC;c++)
	{
	if(cam[n].estado == 1)
        	
		{
        printf("\nNumero: %d\nMatricula: %s\nCarga Maxima KG: %d\nData inspeccao: %d\t%d\t%d\nCusto KM: %d\nMotorista Camiao: %d\nSituacao 1-Ocupado 0-Livre: %d\nEstado: %d\n",
		cam[c].ncam,cam[c].matricula,cam[c].cm,cam[c].dpi.dia,cam[c].dpi.mes,cam[c].dpi.ano,cam[c].custo,cam[c].ma,cam[c].situacao,cam[c].estado);
		}
	}
	fclose(fc);
	printf("\nListagem concluida <Enter para voltar>");getch();
}

//Inserir camioes 
int inserir_camioes(camioes *cam)
{
	
	int n,c;
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
			printf("\n\nMatricula: ");scanf("\n%[^\n]s",cam[c].matricula);
			printf("\n\nCarga Maxima KG: ");scanf("\n%d",&cam[c].cm);
			printf("\n\nInspeccao dia: ");scanf("\n%d",&cam[c].dpi.dia);
			printf("\n\nInspeccao mes: ");scanf("\n%d",&cam[c].dpi.mes);
			printf("\n\nInspeccao ano: ");scanf("\n%d",&cam[c].dpi.ano);
			printf("\n\nCusto KM(€): ");scanf("\n%d",&cam[c].custo);
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

//Alterar camioes 
int alterar_camioes(camioes *cam)
{
	char confere;
	int n,c;
	long int alte;
	system("cls");
	printf("Qual o numero do Camiao que quer alterar? "); scanf("%ld",&alte);
	for(c=1;c<NO;c++)
	{
		if(cam[c].ncam==alte)
		{
			printf("\nNumero: %d\nMatricula: %s\nCarga Maxima KG: %d\nData inspeccao: %d\t%d\t%d\nCusto KM: %d\nMotorista Camiao: %d\nSituacao 1-Ocupado 0-Livre: %d\nEstado: %d\n",
			cam[c].ncam,cam[c].matricula,cam[c].cm,cam[c].dpi.dia,cam[c].dpi.mes,cam[c].dpi.ano,cam[c].custo,cam[c].ma,cam[c].situacao,cam[c].estado);
            
			printf("\n\nQuer mesmo alterar? <S/N>");confere=getch();
				if (confere!='S' && confere!='s')    return(0);
				if(cam[c].estado==1)
					
			printf("\n\nMatricula: ");scanf("\n%[^\n]s",cam[c].matricula);
			printf("\n\nCarga Maxima KG: ");scanf("\n%d",&cam[c].cm);
			printf("\n\nInspeccao dia: ");scanf("\n%d",&cam[c].dpi.dia);
			printf("\n\nInspeccao mes: ");scanf("\n%d",&cam[c].dpi.mes);
			printf("\n\nInspeccao ano: ");scanf("\n%d",&cam[c].dpi.ano);
			printf("\n\nCusto KM(€): ");scanf("\n%d",&cam[c].custo);
			printf("\n\nMotorista: ");scanf("\n%d",&cam[c].ma);
			printf("\n\nSituacao 1-ocupado 0-livre: ");scanf("%d", &cam[c].situacao);
			printf("\n\n\nRegisto alterado com sucesso! <Enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);
}

//Eliminar camioes
int eliminar_camioes(camioes *cam)
{
	char confere;
	int n,c;
	long int eli;
	system("cls");
	printf("Qual o numero do camiao que quer eliminar? "); scanf("%ld",&eli);
	for(c=1;c<NC;c++)
	{
		if(cam[c].ncam==eli)
		{
			printf("\nNumero: %d\nMatricula: %s\nCarga Maxima KG: %d\nData inspeccao: %d\t%d\t%d\nCusto KM: %d\nMotorista Camiao: %d\nSituacao 1-Ocupado 0-Livre: %d\nEstado: %d\n",
			cam[c].ncam,cam[c].matricula,cam[c].cm,cam[c].dpi.dia,cam[c].dpi.mes,cam[c].dpi.ano,cam[c].custo,cam[c].ma,cam[c].situacao,cam[c].estado);
			
			printf("\n\nTem a certeza que quer eliminar? <S/N>");confere=toupper(getch());

			if (confere!='S')    return(0);

			cam[c].estado=0;
			printf("\n\n\nRegisto eliminado <Enter para continuar>\n");getch();  return (1);
		}
	}
	printf("ERRO! Numero não Encontrado\n");system("pause");return(0);
}

//Gravar camioes
void gravar_camioes(camioes *cam)
{
	FILE *fc;
	int n,c;
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

// MENU CAMIOES
int menu_camioes ()
{
		int op;
		int n;
		camioes cam[NC];
		for(n=0;n<NC;n++) //limpa array de registos
		cam[n].estado=0; 
		system("cls"); 
    	ler_camioes(cam);
	do {
		system ("cls");						        
		printf("\n\t|============================================|"); system("COLOR 0B");
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
		printf("\n\t*               0 - Menu Principal           *");
		printf("\n\t*                                            *");
        printf("\n\t**********************************************");
        printf("\n\n\t             Qual a sua opcao? ");
				
				scanf("%d",&op);
               
				switch (op) {
                        case 1: inserir_camioes(cam); break;
                        case 2: alterar_camioes(cam); break;
                        case 3: printf("..."); break;
						case 4: printf("..."); break;
						case 0: system ("cls"); break;
                        default: printf("Opcao invalida!\n");
                }
    } while (op!=0);
	
}
//MENU CAMIOES FIM

//MENU CONDUTORES INICIO

//Ler condutores
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
		if(con[n].estado==1)
		{
			fscanf(fo,"%d\n%s\n%d\n%d\n%d\n%d\n%s\n%d\n%d\n",&con[n].numero,&con[n].nome,&con[n].data_nas.dia,&con[n].data_nas.mes,&con[n].data_nas.ano,
			  &con[n].telefone,&con[n].morada, &con[n].situacao, &con[n].estado);
		}
	}
	
	
	fclose(fo);
	printf("\n\nFicheiro Lido\n<Enter para continuar>\n"); getch();
}

// listar condutores
int listar_condutores (condutores *con)
{
    int m;
  	FILE *fo;
	int n;
	fo=fopen("condutores.txt","r");
	
	for(n=1;n<NO;n++)
	{
		fscanf(fo,"%d\n%s\n%d\n%d\n%d\n%d\n%s\n%d\n%d\n",&con[n].numero,&con[n].nome,&con[n].data_nas.dia,&con[n].data_nas.mes,&con[n].data_nas.ano,
			  &con[n].telefone,&con[n].morada, &con[n].situacao, &con[n].estado);
	}
	system ("cls");
	
	for(m=1;m<NO;m++)
		
	if(con[m].estado == 1)
        {
            printf("Condutor: %d\nNome: %s\nDia de Nascimento: %d\nMes de Nascimento: %d\nAno de Nascimento: %d\nTelefone: %d\nMorada: %s\nSituacao: %d\n\n", 
			con[m].numero, con[m].nome, con[m].data_nas.dia, con[m].data_nas.mes, con[m].data_nas.ano,	con[m].telefone, con[m].morada,	con[m].situacao);
        }
			
	fclose(fo);
	printf("\nListagem concluida <Enter> para voltar");getch();
}

//Inserir condutores
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
			printf("\n\nNome: ");scanf("\n%[^\n]s", con[n].nome);
			printf("\n\nDia de Nascimento: ");scanf("%d",&con[n].data_nas.dia);
			printf("\n\nMes de Nascimento: ");scanf("%d",&con[n].data_nas.mes);
			printf("\n\nAno de Nascimento: ");scanf("%d",&con[n].data_nas.ano);
			printf("\n\nTelefone: ");scanf("%ld", &con[n].telefone);
			printf("\n\nMorada: ");scanf("\n%[^\n]s",con[n].morada);
			con[n].situacao=0;
			con[n].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para continuar>\n");
			getch();
			return(1);
		}
	}
	printf("ERRO! Não foi possivel inserir"); getch(); return(0);
}

//Alterar condutores
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
			printf("\nNome: %s\nData de Nascimento: %d/%d/%d\nTelefone: %d\nMorada: %s\n\n"
			,con[n].nome, con[n].data_nas.dia, con[n].data_nas.mes, con[n].data_nas.ano, con[n].telefone, con[n].morada);
            
			printf("\n\nQuer mesmo alterar? <S/N>");confere=getch();
				if (confere!='S' && confere!='s')    return(0);
				if(con[n].estado==1)
			printf("\n\nNome: ");scanf("\n%[^\n]s", con[n].nome);
			printf("\n\nDia de Nascimento: ");scanf("%d",&(con[n].data_nas.dia));
			printf("\n\nMes de Nascimento: ");scanf("%d",&(con[n].data_nas.mes));
			printf("\n\nAno de Nascimento: ");scanf("%d",&(con[n].data_nas.ano));
			printf("\n\nTelefone: ");scanf("%d", &con[n].telefone);
			printf("\n\nMorada: ");scanf("\n%[^\n]s",&con[n].morada);
			printf("\n\n\nRegisto alterado com sucesso! <Enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);

}

//Eliminar condutores
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
			printf("\nNome: %s\nData de Nascimento: %d/%d/%d\nTelefone: %d\nMorada: %s\n\n"
			,con[n].nome, con[n].data_nas.dia, con[n].data_nas.mes, con[n].data_nas.ano, con[n].telefone, con[n].morada);
			printf("\n\nTem a certeza que quer eliminar? <S/N>");confere=toupper(getch());

			if (confere!='S')    return(0);

			con[n].estado=0;
			printf("\n\n\nRegisto eliminado <Enter para continuar>\n");getch();  return (1);
		}
	}
	printf("ERRO! Numero não Encontrado\n");system("pause");return(0);
}

//Gravar condutores
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

//MENU CONDUTORES
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
		printf("\n\t|============================================|"); system("COLOR 00");
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

//Ler cargas
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
		fscanf(fa,"%d\n%s\n%s\n%s\n%d\n%.2f\n%d\n%d\n%d\n%d\n%d\n",&car[ca].numero,&car[ca].nome_cliente,
		&car[ca].local_origem,&car[ca].local_destino,&car[ca].distancia, &car[ca].peso,&car[ca].data_trans.dia, 
		&car[ca].data_trans.mes, &car[ca].data_trans.ano, &car[ca].situacao, &car[ca].estado);
	}
	fclose(fa);
	printf("\n\n\nFicheiro Lido <Enter para Continuar>");getch();
}

//Listar cargas
int listar_cargas(cargas *car)
{
	FILE *fa;
	fa=fopen("cargas.txt","r");
    int ca;
	system ("cls");
	 for(ca=1;ca<NA;ca++)
	{
							
            for(ca=1;ca<NA;ca++)
            if(car[ca].estado==1)
			{
				printf("Numero: %d\nNome do Cliente: %s\nLocal de Origem da Carga: %s\nLocal de Destino da Carga: %s\nDistancia da Origem ao Destino: %d\nPeso da Carga: %.2f\nDia do Transporte: %d\nMes do Transporte: %d\nAno do Transporte: %d\nEstado: %d\nSituacao: %d\n\n",
				car[ca].numero,
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
			}
	
		
	}printf("\n\n\nListagem Concluida <Enter para Continuar>");
	getch();fclose(fa);
}

//Inserir cargas
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
			printf("\n\nNome do cliente: ");scanf("\n%[^\n]s", car[ca].nome_cliente);
			printf("\n\nLocal de Origem da Carga: ");scanf("%s",car[ca].local_origem);
			printf("\n\nLocal de Destino da Carga: ");scanf("%s",car[ca].local_destino);
			printf("\n\nDistancia da Origem ao Destino KM: ");scanf("%d",&car[ca].distancia);
			printf("\n\nPeso da Carga KG: ");scanf("%f", &car[ca].peso);
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

//Alterar cargas
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
		printf("\nNome do Cliente: %s\nLocal de Origem da Carga: %s\nLocal de Destino da Carga: %s\nDistancia da Origem ao Destino: %d\nPeso da Carga: %.2f\nDia do Transporte: %d\nMes do Transporte: %d\nAno do Transporte: %d\n\n",
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
       		printf("\n\nNome do cliente: ");scanf("\n%[^\n]s", car[ca].nome_cliente);
			printf("\n\nLocal de Origem da Carga: ");scanf("%s",car[ca].local_origem);
			printf("\n\nLocal de Destino da Carga: ");scanf("%s",car[ca].local_destino);
			printf("\n\nDistancia da Origem ao Destino: ");scanf("%d",&car[ca].distancia);
			printf("\n\nPeso da Carga: ");scanf("%f", &car[ca].peso);
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

//Eliminar cargas
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
		printf("\nNome do Cliente: %s\nLocal de Origem da Carga: %s\nLocal de Destino da Carga: %s\nDistancia da Origem ao Destino: %d\nPeso da Carga: %.2f\nDia do Transporte: %d\nMes do Transporte: %d\nAno do Transporte: %d\nSituacao: %d\n\n",
		car[ca].nome_cliente,
        car[ca].local_origem,
        car[ca].local_destino,
        car[ca].distancia,
        car[ca].peso,
        car[ca].data_trans.dia,
        car[ca].data_trans.mes, 
        car[ca].data_trans.ano,
		car[ca].situacao);
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

//Gravar cargas
void gravar_cargas(cargas *car)
{
	FILE *fa;
	int ca;
	if(!(fa=fopen("cargas.txt","a+")))
	{
		printf("\n\n\nErro na Abertura para Gravar <Enter para Sair>");
		getch();  exit(0);
	}
	    
    for(ca=1;ca<NA;ca++)
	{
		if(car[ca].estado==1)
		{
			fprintf(fa,"%d\n%s\n%s\n%s\n%d\n%.2f\n%d\n%d\n%d\n%d\n%d\n",car[ca].numero,car[ca].nome_cliente,
			car[ca].local_origem,car[ca].local_destino,car[ca].distancia,
			car[ca].peso,car[ca].data_trans.dia, car[ca].data_trans.mes, car[ca].data_trans.ano, car[ca].situacao, car[ca].estado);
		}
	}
	fclose(fa);
	printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); getch();
}

//MENU CARGAS
int menu_cargas ()
{
	
	int op;
	int ca;
	cargas car[NA];
	FILE *fa;
    //for(ca=1;ca<NA;ca++)
	//car[ca].estado=0;
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
        printf("\n\t*               4 - Listar cargas            *");
		printf("\n\t*                                            *");
		printf("\n\t*               5 - Gravar                   *");
		printf("\n\t*                                            *");
		printf("\n\t*               0 - Menu Principal           *");
		printf("\n\t*                                            *");
        printf("\n\t**********************************************");
        printf("\n\n\t             Qual a sua opcao? ");
			do{	
				scanf("%d",&op);
               
				switch (op) 
                {
                        case 1: inserir_cargas(car); break;
                        case 2: alterar_cargas(car); break;
					    case 3: eliminar_cargas(car); break;
						case 4: listar_cargas(car); break;
						case 5: gravar_cargas(car); break;
						case 0: system ("cls"); break;
                        default: printf("Opcao invalida!\n");
                }
    } while (op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=0);
    
    /*fa=fopen("cargas.txt","w");
    for(ca=0;ca<NA;ca++)
    fprintf(fa,"%d\n%s\n%s\n%s\n%d\n%.2f\n%d\n%d\n%d\n%d\n%d\n",car[ca].numero,car[ca].nome_cliente,
		              car[ca].local_origem,car[ca].local_destino,car[ca].distancia, car[ca].peso,car[ca].data_trans.dia, 
		              car[ca].data_trans.mes, car[ca].data_trans.ano, car[ca].situacao, car[ca].estado);
    fclose(fa);*/

    }while (op !=0);
}
//FIM DO MENU CARGAS

// INICIO MENU LISTAGENS
void menu_listagens (void)
{
	int n, c;
	clientes cli[NI];
	camioes cam[NC];
	condutores con[NO];
	//cargas car[NA];
	int op;
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
        printf("\n\t*  2 - Cargas por Camiao                     *");
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
                        case 2: printf("..."); break;
                        case 3: printf("..."); break;
						case 4: printf("..."); break;
						case 5: ler_condutores(con);
								listar_condutores(con); break;
						case 6: ler_clientes(cli);listar_clientes(cli); break;		
						case 0: system ("cls"); break;
                        default: printf("Opcao invalida!\n");
                }
    } while (op!=0);
	
}

//Listar camioes com inspeccao mes corrente
int listar_4 (camioes *cam)
{
    FILE *fc;
	fc=fopen("camioes.txt","r");
	int c,m;
	long int insp;
	system("cls");
	printf("Qual o Mes que quer verificar? "); scanf("%ld",&insp);
	
	for(c=1;c<NC;c++)
	{
		fscanf(fc,"%d\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 
			&cam[c].ncam, &cam[c].matricula, &cam[c].cm,&cam[c].dpi.dia, &cam[c].dpi.mes, 
			&cam[c].dpi.ano, &cam[c].custo, &cam[c].ma, &cam[c].situacao, &cam[c].estado);
	}
	system ("cls");printf("\n...CAMIOES COM INSPECCAO NO MES...: %d\n",insp);
	for(m=1;m<NC;m++)
	{
	if(cam[m].estado == 1)
    if(cam[m].dpi.mes == insp)	
		{
        printf("\nNumero: %d\nMatricula: %s\nCarga Maxima KG: %d\nData inspeccao: %d\t%d\t%d\nCusto KM: %d\nMotorista Camiao: %d\nSituacao 1-Ocupado 0-Livre: %d\nEstado: %d\n",
		cam[c].ncam,cam[c].matricula,cam[c].cm,cam[c].dpi.dia,cam[c].dpi.mes,cam[c].dpi.ano,cam[c].custo,cam[c].ma,cam[c].situacao,cam[c].estado);
		}
	}
	fclose(fc);
	printf("\nListagem concluida <Enter para voltar>");getch();
}


 

int menu_pesquisa ()
{
	int op;
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
                        case 2: printf("..."); break;
                        case 3: printf("..."); break;
						case 0: system ("cls"); break;
                        default: printf("Opcao invalida!\n");
                }
    } while (op!=0);
	
}


int menu_estatistica ()
{
	int op;
	do {
		system ("cls");						        
		printf("\n\t|============================================|"); system("COLOR 0C");
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
        
        
int orcamento()
{
    float klm,toneladas;
    float res1;
    char op;
    system("cls");
        printf("\n\t|======================================================|"); system("COLOR 0B");
    	printf("\n\t|                  C E M  R O D A S                    |");
    	printf("\n\t|                                                      |");
	   	printf("\n\t|                                                      |");
    	printf("\n\t|                 O R C A M E N T O S                  |");
    	printf("\n\t|                                                      |");
    	printf("\n\t|======================================================|");
         
		 do 
		 { 
	    	do {
			printf("\n\t Introduza o numero de kilometros da viagem: ");
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
	     }while(op!='0');
}  

int menu_inic_viag ()			// Falta acabar o menu
{
	system("cls");
        printf("\n\t|======================================================|"); system("COLOR 0B");
    	printf("\n\t|                  C E M  R O D A S                    |");
    	printf("\n\t|                                                      |");
	   	printf("\n\t|                                                      |");
    	printf("\n\t|            I N I C I A R    V I A G E M              |");
    	printf("\n\t|                                                      |");
    	printf("\n\t|======================================================|");



	int carga, cliente, camiao, condutor;
	
	printf("Insira o numero da carga [1-%d]:", NA);
		do
		{
			scanf("%d",&carga);
			if (inser<1 || inser >= NA)
			{
				printf("\nNumero fora dos Parametros ?");
			}
				else
					break;
													
		}while(1);
		
	for(ca=1;ca<NA;ca++)
	{
		if(car[ca].estado==1 && car[ca].numero==carga)
		{
			
			
			car[ca].situacao=1;
			getch();
			return(1);
		}
	}
	printf("ERRO! Nao foi possivel Inserir"); getch(); return(0);
}



}





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
