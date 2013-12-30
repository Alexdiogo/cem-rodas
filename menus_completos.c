#include <stdio.h>
#include <windows.h> 
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#define NR 200
#define NM 50


typedef struct
{
    int dia;
    int mes;
    int ano;
}data;       

//Estrutura das cargas
typedef struct
{
	int numero;
	char nome_cliente[50];
	char local_origem[30];
	char local_destino[30];
	int distancia;
	float peso;
	data data_trans;
	int estado;
}cargas;

//Estrutura dos motoristas
typedef struct{
	long int numero;
	char nome[60];
    data data_nas;			
	long int telefone;
	char morada[30];
	int estado;	
}motorista;

//**************************************** MENU CONDUTORES*****************************

int inserir_condutor(motorista *x)
{
	int n;
	long int inser;
	system ("cls");
	printf("Qual o numero do condutor que quer inserir? ");
	scanf("%ld",&inser);
	for(n=1;n<NM;n++)
	{
		if(x[n].estado!=1)
		{
			x[n].numero=inser;
			printf("\n\nNome: ");scanf("\n%[^\n]s", x[n].nome);
			printf("\n\nDia de Nascimento: ");scanf("%d",&(x[n].data_nas.dia));
			printf("\n\nMes de Nascimento: ");scanf("%d",&(x[n].data_nas.mes));
			printf("\n\nAno de Nascimento: ");scanf("%d",&(x[n].data_nas.ano));
			printf("\n\nTelefone: ");scanf("%ld", &x[n].telefone);
			printf("\n\nMorada: ");scanf("%s",&x[n].morada);
			x[n].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para continuar>\n");
			getch();
			return(1);
		}
	}
	printf("ERRO! Não foi possivel inserir"); getch(); return(0);
}

void gravar_condutor(motorista *x)
{
	FILE *f;
	int n;
	if(!(f=fopen("motoristas1.txt","w")))
	{
		printf("\n\n\nErro na Abertura para Gravar\n");system("pause");exit(0);
	}

	for(n=1;n<NM;n++)
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

void ler_condutor(motorista *x)
{
	FILE *f;
	int n;
	if(!(f=fopen("motoristas1.txt","r")))
	{
		f=fopen("motoristas1.txt","w");
		printf("Foi criado o ficheiro Motoristas\n");
	}
	for(n=1;n<NM;n++)
	{
		fscanf(f,"%ld\n%s\n%d\n%d\n%d\n%ld\n%s\n%d\n",&x[n].numero,x[n].nome,&x[n].data_nas.dia,&x[n].data_nas.mes,&x[n].data_nas.ano,
			  &x[n].telefone,&x[n].morada, &x[n].estado);
	}
	fclose(f);
	printf("\n\nFicheiro Lido\n<Enter para continuar>\n"); getch();
}

int eliminar_condutor(motorista *x)
{
	char confere;
	int n;
	long int eli;
	system("cls");
	printf("Qual o numero do condutor que quer eliminar? "); scanf("%ld",&eli);
	for(n=1;n<NM;n++)
	{
		if(x[n].numero==eli)
		{
			printf("\nNome: %s\nData de Nascimento: %d/%d/%d\nTelefone: %ld\nMorada: %s\n\n"
			,x[n].nome,
			x[n].data_nas.dia,
			x[n].data_nas.mes,
			x[n].data_nas.ano,
			x[n].telefone,
			x[n].morada);
			printf("\n\nTem a certeza que quer eliminar? <S/N>");confere=toupper(getch());

			if (confere!='S')    return(0);

			x[n].estado=0;
			printf("\n\n\nRegisto eliminado <Enter para continuar>\n");getch();  return (1);
		}
	}
	printf("ERRO! Numero não Encontrado\n");system("pause");return(0);
}

int alterar_condutor(motorista *x)
{
	int n;
	long int alte;
	system("cls");
	printf("Qual o numero do Condutor que quer alterar? "); scanf("%ld",&alte);
	for(n=1;n<NM;n++)
	{
		if(x[n].numero==alte)
		{
			printf("\nNome: %s\nData de Nascimento: %d/%d/%d\nTelefone: %ld\nMorada: %s\n\n"
			,x[n].nome,
			x[n].data_nas.dia,
			x[n].data_nas.mes,
			x[n].data_nas.ano,
			x[n].telefone,
			x[n].morada);
            printf("\n\nNome: ");scanf("%s", x[n].nome);
			printf("\n\nDia de Nascimento: ");scanf("%d",&(x[n].data_nas.dia));
			printf("\n\nMes de Nascimento: ");scanf("%d",&(x[n].data_nas.mes));
			printf("\n\nAno de Nascimento: ");scanf("%d",&(x[n].data_nas.ano));
			printf("\n\nTelefone: ");scanf("%ld", &x[n].telefone);
			printf("\n\nMorada: ");scanf("%s",&x[n].morada);
			printf("\n\n\nRegisto alterado com sucesso! <Enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);

}

int menu_condutores()
{
	int op;
	int n;
	motorista mot[NM];
	for(n=0;n<NM;n++)
	mot[n].estado=0; 
	system("cls"); 
    ler_condutor(mot);  
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
		printf("\n\t\t\tQual a sua opcao? "); scanf("%d",&op);
		switch(op)
		{
			case 1: inserir_condutor(mot); break;
			case 2: alterar_condutor(mot); break;
			case 3: eliminar_condutor(mot); break;
			case 4: gravar_condutor(mot);break;
			case 0: system ("cls"); break;
            default: printf("Opcao invalida!\n");
		}
	}while (op!=0);
}

//********************************************Fim do menu condutores******************************

//***************************MENU CARGAS*******************************************

int inserir_cargas(cargas *x)
{
	int ca;
	int inser;
	system ("cls");
	printf("Insira um numero para a carga? ");
	scanf("%d",&inser);
	for(ca=1;ca<NR;ca++)
	{
		if(x[ca].estado!=1)
		{
			x[ca].numero=inser;
			printf("\n\nNome do cliente: ");scanf("\n%[^\n]s", x[ca].nome_cliente);
			printf("\n\nLocal de Origem da Carga: ");scanf("%s",(x[ca].local_origem));
			printf("\n\nLocal de Destino da Carga: ");scanf("%s",(x[ca].local_destino));
			printf("\n\nDistancia da Origem ao Destino: ");scanf("%d",&(x[ca].distancia));
			printf("\n\nPeso da Carga: ");scanf("%f", &x[ca].peso);
			printf("\n\nDia do Transporte: ");scanf("%d",&(x[ca].data_trans.dia));
			printf("\n\nMes do Transporte: ");scanf("%d",&(x[ca].data_trans.mes));
			printf("\n\nAno do Transporte: ");scanf("%d",&(x[ca].data_trans.ano));
		
			x[ca].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
			return(1);
		}
	}
	printf("ERRO! Nao foi possivel Inserir"); getch(); return(0);
}

void gravar_cargas(cargas *x)
{
	FILE *fc;
	int ca;
	if(!(fc=fopen("cargas.txt","a+")))
	{
		printf("\n\n\nErro na Abertura para Gravar <Enter para Sair>");
		getch();  exit(0);
	}

	for(ca=1;ca<NR;ca++)
	{
		if(x[ca].estado==1)
		{
			fprintf(fc,"%d\n%s\n%s\n%s\n%d\n%.2f\n%d\n%d",x[ca].numero,x[ca].nome_cliente,
			x[ca].local_origem,x[ca].local_destino,x[ca].distancia,
			x[ca].peso,x[ca].data_trans.dia, x[ca].data_trans.mes, x[ca].data_trans.ano);
		}
	}
	fclose(fc);
	printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); getch();
}

void ler_cargas(cargas *x)
{
	FILE *fc;
	int ca;
	if(!(fc=fopen("cargas.txt","r")))
	{
		fc=fopen("cargas.txt","w");
		printf("Foi criado o ficheiro Cargas\n");
	
	}
	for(ca=1;ca<NR;ca++)
	{
		fscanf(fc,"%d\n%s\n%s\n%s\n%d\n%.2f\n%d\n%d",&x[ca].numero,x[ca].nome_cliente,
		x[ca].local_origem,x[ca].local_destino,&x[ca].distancia,
		&x[ca].peso,&x[ca].data_trans.dia, &x[ca].data_trans.mes, &x[ca].data_trans.ano);
	}
	fclose(fc);
	printf("\n\n\nFicheiro Lido <Enter para Continuar>");getch();
}


int eliminar_cargas(cargas *x)
{
	char confere;
	int ca; 
	long int eli;
	system("cls");
	printf("Qual o Numero da carga que quer Eliminar? "); scanf("%ld",&eli);
	for(ca=1;ca<NR;ca++)
	{
		if(x[ca].numero==eli)
		{
		printf("\nNome do Cliente: %s\nLocal de Origem da Carga: %s\nLocal de Destino da Carga: %s\nDistancia da Origem ao Destino: %d\nPeso da Carga: %.2f\nDia do Transporte: %d\nMes do Transporte: %d\nAno do Transporte: %d\n\n",
		x[ca].nome_cliente,
        x[ca].local_origem,
        x[ca].local_destino,
        x[ca].distancia,
        x[ca].peso,
        x[ca].data_trans.dia,
        x[ca].data_trans.mes, 
        x[ca].data_trans.ano);
		
		printf("\n\nQuer mesmo eliminar? <S/N>");confere=getch();

		if (confere!='S' && confere!='s')    return(0);

		x[ca].estado=0;
		printf("\n\n\nRegisto eliminado <enter para continuar>");
		getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);
}


int alterar_cargas(cargas *x)
	{
	int ca;
	long int alte;
	system("cls");
	printf("Qual o numero da carga que deseja alterar? "); scanf("%ld",&alte);
	for(ca=1;ca<NR;ca++)
	{
		if(x[ca].numero==alte)
		{
		printf("\nNome do Cliente: %s\nLocal de Origem da Carga: %s\nLocal de Destino da Carga: %s\nDistancia da Origem ao Destino: %d\nPeso da Carga: %.2f\nDia do Transporte: %d\nMes do Transporte: %d\nAno do Transporte: %d\n\n",
		x[ca].nome_cliente,
        x[ca].local_origem,
        x[ca].local_destino,
        x[ca].distancia,
        x[ca].peso,
        x[ca].data_trans.dia,
        x[ca].data_trans.mes, 
        x[ca].data_trans.ano);
		
       		printf("\n\nNome do cliente: ");scanf("\n%[^\n]s", x[ca].nome_cliente);
			printf("\n\nLocal de Origem da Carga: ");scanf("%s",(x[ca].local_origem));
			printf("\n\nLocal de Destino da Carga: ");scanf("%s",(x[ca].local_destino));
			printf("\n\nDistancia da Origem ao Destino: ");scanf("%d",&(x[ca].distancia));
			printf("\n\nPeso da Carga: ");scanf("%f", &x[ca].peso);
			printf("\n\nDia do Transporte: ");scanf("%d",&(x[ca].data_trans.dia));
			printf("\n\nMes do Transporte: ");scanf("%d",&(x[ca].data_trans.mes));
			printf("\n\nAno do Transporte: ");scanf("%d",&(x[ca].data_trans.ano));
		
			printf("\n\n\nRegisto alterado <enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);

}

int menu_cargas ()
{
	
	int op;
	int ca;
	cargas car[NR];
	for(ca=0;ca<NR;ca++)
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
		printf("\n\t*               0 - Menu Principal           *");
		printf("\n\t*                                            *");
        printf("\n\t**********************************************");
        printf("\n\n\t             Qual a sua opcao? ");
				
				scanf("%d",&op);
               
				switch (op) {
                        case 1: inserir_cargas(car); break;
                        case 2: alterar_cargas(car); break;
					    case 3: eliminar_cargas(car); break;
						case 4: gravar_cargas(car); break;
						case 0: system ("cls"); break;
                        default: printf("Opcao invalida!\n");
                }
    } while (op!=0);
    
}
	
//***************************************Fim do menu cargas******************************


int menu_clientes() 
		{
        int op;
        do {
        
		system ("cls");						        
		printf("\n\t|============================================|"); system("COLOR 05");
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
		printf("\n\t*               0 - Menu Principal           *");
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



int menu_camioes ()
{
	int op;
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
        printf("\n\t*               0 - Menu Principal           *");
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

        
int menu_listagens ()
{
	int op;
	do {
		system ("cls");						        
		printf("\n\t|============================================|"); system("COLOR 0C");
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
        printf("\n\t*  0 - Menu Principal                        *");
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
}



int main(void) 
{
    	
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
    	 				case 4: menu_cargas();break;
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

