#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
#define NR 50                               	
int n_clientes = 0;
int n_camioes = 0;
int n_cargas = 0;
int n_condutores = 0;

typedef struct{
    int dia;
    int mes;
    int ano;
}data;        

typedef struct{
	long int numero;
	char nome[60];
    data data_nas;			
	long int telefone;
	char morada[30];
	int estado;	
}motorista;

typedef struct {
    int ncam;						
    char matricula[9];
    int cm;							
    char dpi[10];						
    int custo;
    int ma;							
    int estado;						
}camioes;

typedef struct {
    long int numero;
    char nome[30];
    char apelido[30];
    char morada[50];
    long int telefone;
    int estado;
}clientes;

typedef struct {
	int numero_carga;
	int numero_cliente;
	char local_origem[100];
	char local_destino[100]
	int distancia;
	int peso;
	char data[11];
} carga;

//***********************************************************INICIO DO MENU CONDUTORES**************************************************************

int inserir_condutor(motorista *x)
{
	int n;
	long int inser;
	system ("cls");
	printf("Qual o Número do condutor que quer Inserir? ");
	scanf("%ld",&inser);
	for(n=1;n<NR;n++)
	{
		if(x[n].estado!=1)
		{
			x[n].numero=inser;
			printf("\n\nNome=?");scanf("\n%[^\n]s", x[n].nome);
			printf("\n\nDia de Nascimento=?");scanf("%d",&(x[n].data_nas.dia));
			printf("\n\nMes de Nascimento=?");scanf("%d",&(x[n].data_nas.mes));
			printf("\n\nAno de Nascimento=?");scanf("%d",&(x[n].data_nas.ano));
			printf("\n\nTelefone=?");scanf("%ld", &x[n].telefone);
			printf("\n\nMorada=?");scanf("%s",&x[n].morada);
			x[n].estado=1;
			printf("\n\n\nRegisto Inserido \n");
			system("pause");
			return(1);
		}
	}
	printf("ERRO! Não foi possivel Inserir"); getch(); return(0);
}

void gravar_condutor(motorista *x)
{
	FILE *f;
	int n;
	if(!(f=fopen("i:\\motoristas1.txt","w")))
	{
		printf("\n\n\nErro na Abertura para Gravar\n");system("pause");exit(0);
	}

	for(n=1;n<NR;n++)
	{
		if(x[n].estado==1)
		{
			fprintf(f,"%ld\n%s\n%d\n%d\n%d\n%ld\n%s\n%d\n",x[n].numero,x[n].nome,x[n].data_nas.dia,x[n].data_nas.mes,x[n].data_nas.ano,
						      x[n].telefone,x[n].morada, x[n].estado);
		}
	}
	fclose(f);
	printf("\n\n\nFicheiro Gravado\n");system("pause");
}

void ler(motorista *x)
{
	FILE *f;
	int n;
	if(!(f=fopen("i:\\motoristas1.txt","r")))
	{
		printf("Erro na Abertura de Leitura\n");system("pause"); exit(0);
	}
	for(n=1;n<NR;n++)
	{
		fscanf(f,"%ld\n%s\n%d\n%d\n%d\n%ld\n%s\n%d\n",&x[n].numero,x[n].nome,&x[n].data_nas.dia,&x[n].data_nas.mes,&x[n].data_nas.ano,
			  &x[n].telefone,&x[n].morada, &x[n].estado);
	}
	fclose(f);
	printf("\n\n\nFicheiro Lido\n");system("pause");
}

int eliminar(motorista *x)
{
	char confere;
	int n;
	long int eli;
	system("cls");
	printf("Qual o número do condutor que quer Eliminar? "); scanf("%ld",&eli);
	for(n=1;n<NR;n++)
	{
		if(x[n].numero==eli)
		{
			printf("\nNome=%s\nData de Nascimento=%d/%d/%d\nTelefone=%ld\nMorada=%s\n\n"
			,x[n].nome,
			x[n].data_nas.dia,
			x[n].data_nas.mes,
			x[n].data_nas.ano,
			x[n].telefone,
			x[n].morada);
			printf("\n\nQuer mesmo eliminar? <S/N>");confere=toupper(getch());

			if (confere!='S')    return(0);
			
			//não há aqui nada a dizer que o registo foi eliminado... ou será a instrução a seguir?

			x[n].estado=0;
			printf("\n\n\nRegisto eliminado\n");system("pause");  return (1);
		}
	}
	printf("ERRO! Número não Encontrado\n");system("pause");return(0);
}

int alterar(motorista *x)
{
	int n;
	long int alte;
	system("cls");
	printf("Qual o número do Condutor que quer alterar? "); scanf("%ld",&alte);
	for(n=1;n<NR;n++)
	{
		if(x[n].numero==alte)
		{
			printf("\nNome=%s\nData de Nascimento=%d/%d/%d\nTelefone=%ld\nMorada=%s\n\n"
			,x[n].nome,
			x[n].data_nas.dia,
			x[n].data_nas.mes,
			x[n].data_nas.ano,
			x[n].telefone,
			x[n].morada);
            printf("\n\nNome=?");scanf("%s", x[n].nome);
			printf("\n\nDia de Nascimento=?");scanf("%d",&(x[n].data_nas.dia));
			printf("\n\nMes de Nascimento=?");scanf("%d",&(x[n].data_nas.mes));
			printf("\n\nAno de Nascimento=?");scanf("%d",&(x[n].data_nas.ano));
			printf("\n\nTelefone=?");scanf("%ld", &x[n].telefone);
			printf("\n\nMorada=?");scanf("%s",&x[n].morada);
			printf("\n\n\nRegisto alterado <enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);

}

int menu_condutores()
{
	char op;
	int n;
	motorista mot[NR];
	for(n=0;n<NR;n++)
	mot[n].estado=0; 
	system ("cls"); 
    ler(mot);  
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
		printf("\n\t*               0 - Menu Principal           *");
		printf("\n\t*                                            *");
		printf("\n\t**********************************************");
		printf("\n\tQual a sua opção? "); op=getch();
		switch(op)
		{
			case '1': inserir_condutor(mot); break;
			case '2': alterar_condutor(mot); break;
			case '3': eliminar_condutor(mot); break;
			case '4': gravar_condutor(mot);break;
			case '0': menu();
		}
	}while (op!='S' && op!='s');
}
//   **************************************************************FIM DO MENU CONDUTORES***********************************************************


//   **************************************************************INICIO DO MENU CAMIOES***********************************************************
	void ler_camioes(camioes *x)
	{
		FILE *f;
		int c;
		if(!(f=fopen("i:\\camioes.txt","a+")))
		{
			printf("Erro na Abertura de Leitura\n");system("pause");
			exit(0);
		}
		system("cls");
		fscanf(f,"%d",&n_camioes);
			
		for(c=0; c<n_camioes; c++)
		{
			fscanf(f,"%d\n%s\n%d\n%s\n%d\n%d\n%d\n", &x[c].ncam, x[c].matricula, &x[c].cm,
					      x[c].dpi, &x[c].custo, &x[c].ma, &x[c].estado);
			/*printf("%d\n%s\n%d\n%s\n%d\n%d\n%d\n", x[c].ncam, x[c].matricula,
					      x[c].cm, x[c].dpi, x[c].custo, x[c].ma, x[c].estado);*/		  
		}
		fclose(f);
		printf("\n\nFicheiro Lido\n");system("pause");
	}
	
int mostrar_camioes(camioes *x)
{
	FILE *f;
	int c;
	if(!(f=fopen("i:\\camioes.txt","r")))
	{
		printf("Erro na Abertura de Leitura <Enter para Sair>");
		exit(0);
	}
	system("cls");
	fscanf(f,"%d",&n_camioes);
	/*printf("Numero de camioes = %d\n", n_camioes);
	getch();*/		
	for(c = 0; c < NR; c++)
		
		if(x[c].estado==1)
		{
			printf("\nA listar camiao->%d",c);
			printf("\nCamiao %d\nMatricula %s\nCarga Maxima (KG) %d\nData Prox Inspeccao %s\nCusto (KM) %d\nMotorista %d\n", 
			x[c].ncam,x[c].matricula, x[c].cm, x[c].dpi, x[c].custo, x[c].ma);		     
		}
	fclose(f);
	printf("\n\n\nListagem Concluida <Enter para Continuar>");
	getch();
}
		
int inserir_camioes(camioes *x)
{
	int verifica;
	FILE *f;
	int c;
	system ("cls");
	printf("\n\nQual o Numero de camiao que quer Inserir [0-%d]? ", NR);
	
	do{
		scanf("%d",&c);
		if (c<0 || c >= NR){
			printf("\nNumero fora dos Parametros ?");
		
		}
			else
				break;
												
	}while(1);

			x[c].ncam= c;
							
			if (x[c].estado == 0)
			n_camioes++;
				
			x[c].estado = 1;
			printf("\n\nMATRICULA= ");scanf("\n%[^\n]s", x[c].matricula);
			printf("\n\nCARGA MAXIMA KG= ");scanf("%d", &x[c].cm); 
			printf("\n\nDATA PROX INSPECCAO= ");scanf("%s", x[c].dpi);  
			printf("\n\nCUSTO P/KM EM EUROS= ");scanf("%d", &x[c].custo);
			printf("\n\nMOTORISTA ASSOCIADO= ");scanf("%d", &x[c].ma);
			x[c].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
							
	
}
	
int eliminar_camioes(camioes *x)
{
	char confere;
	int c;
	
		system("cls");
		
	
	do{
		printf("\n\nQual o Numero de camiao que quer Eliminar [0-%d]? ", NR);
		scanf("%d",&c);										
	}while(c<0 || c >= NR);
	if(x[c].ncam==c)
	
	for(c=0; c<n_camioes; c++) {

		printf("%d\n%s\n%d\n%s\n%d\n%d\n%d\n", x[c].ncam, x[c].matricula,
				  x[c].cm, x[c].dpi, x[c].custo, x[c].ma, x[c].estado);			  

		
		printf("\n\nQuer mesmo eliminar? <S/N>");confere=getch();

		if (confere!='S' && confere!='s')    return(0);
	}
	x[c].estado=0;
	printf("\n\n\nRegisto alterado <Enter para Continuar>");
		
	getch();  return (1);			
}
	
	
int alterar_camioes(camioes *x)
{
	
		int c;
		char confere;
		int alt;
		system("cls");
		printf("\n\nQual o Numero de camiao que quer Alterar [0-%d]? ", NR);
	
	do{
		scanf("%d",&c);
		if (c<0 || c >= NR){
			printf("\nNumero fora dos Parametros ?");
		
		}
			else
				break;
												
	}while(1);
	{
			
			x[c].ncam==NR;
									
		printf("%d\n%s\n%d\n%s\n%d\n%d\n%d\n", x[c].ncam, x[c].matricula,
					  x[c].cm, x[c].dpi, x[c].custo, x[c].ma, x[c].estado);			  
	
				
				printf("\n\nQuer mesmo alterar? <S/N>");confere=getch();
	
				if (confere!='S' && confere!='s')    return(0);
	
					
			if(x[c].estado==1)
		
			x[c].ncam=c;
			printf("\n\nMATRICULA= ");scanf("%s", x[c].matricula);
			printf("\n\nCARGA MAXIMA KG= ");scanf("%d", &x[c].cm);
			printf("\n\nDATA PROX INSPECCAO= ");scanf("%s", x[c].dpi);
			printf("\n\nCUSTO P/KM EUROS= ");scanf("%d", &x[c].custo);
			printf("\n\nMOTORISTA ASSOCIADO= ");scanf("%d", &x[c].ma);
			x[c].estado=1;
			printf("\n\n\nRegisto alterado <Enter para Continuar>");
						
			getch();  return (1);
		}
	}
	
	

void gravar_camioes(camioes *x)
{
	FILE *f;
	int c;
	if(!(f=fopen("i:\\camioes.txt","w")))
	{
		printf("\n\n\nErro na Abertura para Gravar <Enter para Sair>");
		getch();  exit(0);
	}

	fprintf(f, "%d\n", n_camioes);
	for(c = 0; c < NR; c++){
		if(x[c].estado==1)
		{
			
			fprintf(f,"%d\n%s\n%d\n%s\n%d\n%d\n%d\n", x[c].ncam,x[c].matricula,
					  x[c].cm, x[c].dpi, x[c].custo, x[c].ma, x[c].estado);		     
		}
	}
	fclose(f);
	printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); 
	getch();
}


/**
OPCOES MENU CAMIOES FIM
*/

int menu_camioes()
{
	char op;
	int c;
	camioes cam[NR];
	for(c=0;c<NR;c++)
	cam[c].estado=0;   /* limpa todo o Array de registos */
	system ("cls"); /*gotoxy(20,10);*/
	ler_camioes(cam);
	do {
		system ("cls");						        
		printf("\n\t|============================================|"); system("COLOR 0B");
    	printf("\n\t|              C E M  R O D A S              |");
    	printf("\n\t|                                            |");
	   	printf("\n\t|                                            |");
    	printf("\n\t|                C A M I Õ E S               |");
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
        printf("\n\n\t             Qual a sua opcao? ");scanf("%d",&op);
		switch (op) {
			case 1: inserir_camioes(cam); break;
			case 2: alterar_camioes(cam); break;
			case 3: eliminar_camioes(cam); break;
			case 4: gravar_camioes(cam); break;
			case 0: menu();
					system ("cls"); break;
			default: printf("Opcao invalida!\n");
		}
    } while (op!='S' && op!='s');
	
}

//*******************************************************************FIM DO MENU CAMIOES*************************************************************

//----- Menu Cargas Início (o resto do grupo deve rever URGENTEMENTE esta parte
void inserir_carga(carga *x)
{
	int n;
	long int inser;
	FILE *f;
	if(!(f=fopen("f:\\alunos.txt","w")))
	{
		printf("Erro na Abertura de Leitura\n");
		system("pause"); exit(0);
	}
	system ("cls");
	printf("Qual o número da carga que pretende inserir? ");
	scanf("%ld",&inser);
	for(n=1;n<NR;n++)
	{
		if(x[n].estado!=1)
		{
			x[n].numero_carga=inser;
			printf("\n\nCliente correspondente: ");scanf("%d", &x[n].numero_cliente);fprintf(f,"%d", &x[n].peso);
			printf("\n\nOrigem: ");gets(x[n].local_origem);fputs(x[n].local_origem,f);
			printf("\n\nDestino: ");gets(x[n].local_destino);fputs(x[n].local_destino,f);
			printf("\n\nDistância: ");scanf("%d", &x[n].distancia);fprintf(f,"%d\n", &x[n].distancia);
			printf("\n\nPeso: ");scanf("%d", &x[n].peso);fprintf(f,"%d", &x[n].peso);
			printf("\n\nData: ");gets(&x[n].data);fgets(&x[n].data,f);
			x[n].estado=1;
			printf("\n\n\nRegisto Inserido\n");
			system("PAUSE");
           		return(1);	
		}
	}
	printf("ERRO! Nao foi possivel Inserir"); system("PAUSE");return(0); 
}

void alterar_carga(carga *x) //não tenho a certeza se este menu está correto, os restantes membros do grupo devem rever esta função
{
	int n;
	long int alt;
	FILE *f;
	if(!(f=fopen("f:\\alunos.txt","w")))
	{
		printf("Erro na Abertura de Leitura\n");
		system("pause"); exit(0);
	}
	system ("cls");
	printf("Qual o número da carga que pretende alterar? ");
	scanf("%ld",&alt);
	for(n=1;n<NR;n++)
	{
		if((*x)[n].numero==alt)
		{
			x[n].numero_carga=inser;
			printf("\n\nCliente correspondente: %d, Novo: ",x[n].numero_cliente);scanf("%d", &x[n].numero_cliente); if (x[n].numero_cliente != "") fprintf(f,"%d", &x[n].numero_cliente);
			printf("\n\nOrigem: %d, Novo: ",x[n].local_origem);gets(x[n].local_origem);if (x[n].local_origem != "")fputs(x[n].local_origem,f);
			printf("\n\nDestino: %d, Novo: ",x[n].local_destino);gets(x[n].local_destino);if (x[n].local_destino != "") fputs(x[n].local_destino,f);
			printf("\n\nDistância: %d, Novo: ",x[n].distancia);scanf("%d", &x[n].distancia);if (x[n].distancia != 0) fprintf(f,"%d\n", &x[n].distancia);
			printf("\n\nPeso: %d, Novo: ",x[n].peso);scanf("%d", &x[n].peso);if (x[n].peso != 0) fprintf(f,"%d", &x[n].peso);
			printf("\n\nData: %d, Novo: ",x[n].data);gets(&x[n].data);if (x[n].data != "")fgets(&x[n].data,f);
			printf("\n\n\nRegisto Inserido\n");
			system("PAUSE");
           		return(1);	
		}
	}
	printf("ERRO! Número nao Encontrado \n");
	system("PAUSE"); return(0);
}

int eliminar_carga(carga *x, int *na)
{
	char confere;
	int n;
	long int eli;
	system("cls");
	printf("Qual o Numero do Cliente que quer Eliminar? "); scanf("%ld",&eli);
	for(n=0;n<*na;n++)
	{
		if((*x)[n].numero==eli)
		{
			printf("\n\nCLIENTE=%d\nORIGEM=%s\nDESTINO=%s\nDISTÂNCIA=%d\nPESO=%d\n\nDATA=%s\n\n",
            &((*x)[n].numero_cliente), &((*x)[n].local_origem), &((*x)[n].local_destino), &((*x[n]).distancia), &((*x[n]).peso)), &((*x[n]).data));
			printf("\n\nQuer mesmo eliminar? <S/N>");confere=toupper(getch());
			if (confere!='S')    return(0);
			printf("\n\n\nRegisto eliminado <enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado \n");
	system("PAUSE"); return(0);
}

int menu_cargas ()
{
	int op;
	system ("cls");						        
	printf("\n\t|============================================|"); system("COLOR 08");
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
	printf("\n\t*               0 - Menu Principal           *");
	printf("\n\t*                                            *");
	printf("\n\t**********************************************");
	do {
		printf("\n\n\t             Qual a sua opção? ");
		getch(op);
	} while (op!=0);
               
	switch (op) {
		case 1: inserir_carga(&carga) break;
		case 2: alterar_carga(&carga) break;
		case 3: eliminar_carga(&carga,na); break;
		case 0: system ("cls"); break;
	}
	
}
//----- Menu Cargas Fim

//******************************************************************INICIO MENU ORCAMENTO***********************************************************

void orcamento()
{
    float klm,toneladas,res1;
    system("cls");
	printf("\n\t|======================================================|"); system("COLOR 0B");
	printf("\n\t|                  C E M  R O D A S                    |");
	printf("\n\t|                                                      |");
	printf("\n\t|                                                      |");
	printf("\n\t|                 O R Ç A M E N T O S                  |");
	printf("\n\t|                                                      |");
	printf("\n\t|======================================================|");
	 
	do {
		printf("\n\t Introduza o número de kilometros da viagem: ");
		scanf("%f",&klm);
	} while (klm < 100); //manter esta parte assim, o código é melhor
	
	do {
	printf("\n\t Introduza o número de toneladas a transportar: ");
	scanf("%f",&toneladas);
	} while (toneladas < 1); //manter esta parte também assim
	
	res=1*klm+50*toneladas;
	printf("\n\t A sua viagem tem o valor de: %.2f euros",res1);
	printf("\n\n\n\t Orcamento Concluido \n");
	system("pause");system ("cls");
} 

//*************************************************************FIM DO MENU ORCAMENTO**************************************************************
 
void main(void)
{
    menu();
}    


int menu() 
{
    system ("cls");    
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
        printf("\n\t*              0 - Sair                      *");
		printf("\n\t*                                            *");
        printf("\n\t**********************************************");
        printf("\n\n\t             Qual a sua opcao? ");
               
			     scanf("%d",&op);
        
				 switch (op) {
                        //case 1: menu_clientes();break; 									/*menu_clientes(alunos, na); break;*/
    	 				case 2: menu_camioes();break;
		 				case 3: menu_condutores();break;
    	 				//case 4: menu_cargas();break;
		 			//	case 5: menu_listagens();break;
//         				case 6: menu_pesquisa();break;
//		 				//case 7: menu_estatistica();break;
		 				case 8: orcamento();break;   
     	 				//case 9: menu_inic_viag();break;
		 				case 0: system ("cls");break;
		 				default: printf("Opcao invalida.\n");
         		}
         		
       } while (op!=0);
        printf("Fim!\n");
        return 0;
}
