#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
#define NR 300                          /* Numero maximo de Registos  */            	

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

	
/*	void funcao_ordena()
	{
 
	int i, j, aux;
 
          for( i=0; i<50; i++ ){
                  for( j=i+1; j<50; j++ )
				  {
                       if( x[i].numero > x[j].numero] )
					   {
                           aux = x[i]numero; 
                           numero[i] = numero[j];
                           numero[j] = aux;
                       }
                  }
           }
           printf("\n Ordenado com sucesso!"); 
	
		/* definicao das struturas e variaveis */

/*struct cliente {
		int numero;
		char nome[50];
		char morada[100];
		int telefone;
	};
	
	struct camioes {
		char matricula[9];
		int carga_maxima;
		char data_proxima_inspecao[8];
		int custo;
		int motorista_associado;
	};
	
	struct condutor {
		int numero;
		char nome[50];
		char morada[200];
		int telefone;
		char data_nascimento[11];
	};
	
	struct cargas {
		int numero_cliente;
		char local_origem[100];
		char local_destino[100];
		int distancia;
		int peso;
		char data[11];
	};

*/
//Menus completos e menu_orcamento a funcionar (Falta completar)


typedef struct  
    {
		long int numero;
		char nome[20];
		char apelido[30];
        char morada[100];
		long int telefone;
		int estado;
	}clientes;
	
	
	typedef struct
	  {
		int numero;
		char matricula[9];
		int cm;									/* carga maxima */
		char dpi[8];						/* data proxima inspeccao */
		int custo;
		int ma;								/*motorista associado */
		int estado;
	}camioes;
	

	


/*-----------------------------------------------------------------------------------OPCOES MENU CLIENTES INICIO--------------------------------*/
	void ler(clientes *x)
	{
		FILE *f;
		int n;
		if(!(f=fopen("\\clientes.txt","r")))
		{
			printf("Erro na Abertura de Leitura <Enter para Sair>");
			exit(0);
		}
		for(n=1;n<NR;n++)
		{
			fscanf(f,"%ld\n%s\n%s\n%s\n%ld\n%d\n", &x[n].numero,x[n].nome,
					      x[n].apelido, x[n].morada, &x[n].telefone, &x[n].estado);
						  
		}
		fclose(f);
		printf("\n\n\nFicheiro Lido <Enter para Continuar>");getch();
	}
	
	void mostrar(clientes *x)
	{
		int n;
		system ("cls");
		for(n=1;n<NR;n++)
		{
			if(x[n].estado==1)
			{
				printf("NUMERO=%ld\nNOME=%s\nAPELIDO=%s\nMORADA=%s\nTELEFONE=%ld\nESTADO=%d\n\n", x[n].numero,x[n].nome,x[n].apelido, x[n].morada, x[n].telefone, x[n].estado);
				
			}
		}
		printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
	}
	
	int inserir(clientes *x)
	{
		int n;
		long int inser;
		system ("cls");
		printf("\n\nQual o Numero de cliente que quer Inserir? ");
		scanf("%ld",&inser);
		for(n=1;n<NR;n++)
		{
			if(x[n].estado!=1)
			{
				x[n].numero=inser;
				printf("\n\nNOME= ");scanf("%s", x[n].nome);
                printf("\n\nAPELIDO= ");scanf("%s", x[n].apelido); 
                printf("\n\nMORADA= ");scanf("%s", x[n].morada);  
				printf("\n\nTELEFONE= ");scanf("%ld", &x[n].telefone);
				x[n].estado=1;
				printf("\n\n\nRegisto Inserido e gravado <Enter para Continuar>");
				getch();
				
				
		FILE *f;
		
		int n;
		if(!(f=fopen("\\clientes.txt","w")))
		{
			printf("\n\n\nErro na Abertura para Gravar <Enter para Sair>");
			getch();  exit(0);
		}
	
		for(n=1;n<NR;n++)
		{
			if(x[n].estado==1)
			{
				
				fprintf(f,"%ld\n%s\n%s\n%s\n%ld\n%d\n", x[n].numero,x[n].nome,
					      x[n].apelido, x[n].morada, x[n].telefone, x[n].estado);		     
			}
		}
		fclose(f);
		printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); 
				
				
				return(1);
			}
		}
		printf("ERRO! Nao foi possivel Inserir"); getch(); return(0);
	}
	
	int eliminar(clientes *x)
	{
		char confere;
		FILE *f;
        int n;
		long int eli;
		system("cls");
		printf("\n\nQual o Numero do cliente que quer Eliminar? "); scanf("%ld",&eli);
		for(n=1;n<NR;n++)
		{
			if(x[n].numero==eli)
			{
				printf("\n\nNUMERO=%ld\nNOME=%s\nAPELIDO=%s\nMORADA=%s\nTELEFONE=%ld\n\n",
				x[n].numero,x[n].nome, x[n].apelido, x[n].morada, x[n].telefone);
				printf("\n\nQuer mesmo eliminar? <S/N>");confere=getch();
	
				if (confere!='S' && confere!='s')    return(0);
	
				x[n].estado=0;
				printf("\n\n\nRegisto eliminado <enter para continuar>");
				getch();  return (1);
				
		fclose(f);
		printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); 
				
				
				return(1);
			
			}
		}
		printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
		getch(); return (0);
	}
	
	int alterar(clientes *x)
		{
			FILE *f;
            char confere;
			int n;
			long int alt;
			system("cls");
			printf("\n\nQual o Numero do cliente que quer Alterar? "); scanf("%ld",&alt);
			for(n=1;n<NR;n++)
		{
				if(x[n].numero==alt)
				
					printf("\n\nNUMERO=%ld\nNOME=%s\nAPELIDO=%s\nTELEFONE=%ld\n\n", x[n].numero,x[n].nome, x[n].apelido, x[n].telefone);
					
					printf("\n\nQuer mesmo alterar? <S/N>");confere=getch();
		
					if (confere!='S' && confere!='s')    return(0);
		
						
				if(x[n].estado!=1)
			
				x[n].numero=alt;
				printf("\n\nNOME= ");scanf("%s", x[n].nome);
				printf("\n\nAPELIDO= ");scanf("%s", x[n].apelido);
				printf("\n\nMORADA= ");scanf("%s", x[n].morada);
				printf("\n\nTELEFONE= ");scanf("%ld", &x[n].telefone);
				x[n].estado=1;
				printf("\n\n\nRegisto alterado <Enter para Continuar>");
								
				FILE *f;
		int n;
		if(!(f=fopen("\\clientes.txt","a+")))
		{
			printf("\n\n\nErro na Abertura para Gravar <Enter para Sair>");
			getch();  exit(0);
		}
	
		for(n=1;n<NR;n++)
		{
			if(x[n].estado==1)
			{
				fprintf(f,"%ld\n%s\n%s\n%s\n%ld\n%d\n",&x[n].numero,x[n].nome, x[n].apelido, x[n].morada, &x[n].telefone, &x[n].estado);
							      
			}
				printf("\n\n\nRegisto alterado <enter para continuar>");
				fclose(f);
		          printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); 
               getch();  return (1);
			}
		}
		printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
		getch(); return(0);
	}

/*-----------------------------------------------------------------------------------OPCOES MENU CLIENTES FIM--------------------------------*/


/*----------------------------------------------------------------------------------OPCOES MENU CAMIOES INICIO--------------------------------*/


	
	void le(camioes *x)
	{
		FILE *f;
		int c;
		if(!(f=fopen("\\camioes.txt","r")))
		{
			printf("Erro na Abertura de Leitura <Enter para Sair>");
			exit(0);
		}
		for(c=1;c<NR;c++)
		{
			fscanf(f,"%d\n%s\n%d\n%s\n%d\n%d\n%d\n", &x[c].numero, x[c].matricula, &x[c].cm,
					      x[c].dpi, &x[c].custo, &x[c].ma, &x[c].estado);
						  
		}
		fclose(f);
		printf("\n\n\nFicheiro Lido <Enter para Continuar>");getch();
	}
	
	void mostra(camioes *x)
	{
		int c;
		system ("cls");
		for(c=1;c<NR;c++)
		{
			if(x[c].estado==1)
			{
				printf("NUMERO=%d\nMATRICULA=%s\nCARGA MAXIMA=%d\nDATA PROX INSPECCAO=%s\nCUSTO=%d\nMOTORISTA ASSOCIADO=%d\nESTADO=%d\n\n", x[c].numero, x[c].matricula,x[c].cm,x[c].dpi, 
				x[c].custo, x[c].ma, x[c].estado);
				
			}
		}
		printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
	}
	
	int inseri(camioes *x)
	{
		int c;
		int inser;
		system ("cls");
		printf("\n\nQual o Numero de camiao que quer Inserir? ");
		scanf("%d",inser);
		for(c=1;c<NR;c++)
		{
			if(x[c].estado!=1)
			{
				x[c].numero=inser;
				printf("\n\nMATRICULA= ");scanf("%s", x[c].matricula);
                printf("\n\nCARGA MAXIMA KG= ");scanf("%d", &x[c].cm); 
                printf("\n\nDATA PROX INSPECCAO= ");scanf("%s", x[c].dpi);  
				printf("\n\nCUSTO EUROS= ");scanf("%d", &x[c].custo);
				printf("\n\nMOTORISTA ASSOCIADO= ");scanf("%d", &x[c].ma);
				x[c].estado=1;
				printf("\n\n\nRegisto Inserido e gravado <Enter para Continuar>");
				getch();
				
				
		FILE *f;
		int c;
		if(!(f=fopen("\\camioes.txt","w")))
		{
			printf("\n\n\nErro na Abertura para Gravar <Enter para Sair>");
			getch();  exit(0);
		}
	
		for(c=1;c<NR;c++)
		{
			if(x[c].estado==1)
			{
				
				fprintf(f,"%d\n%s\n%d\n%s\n%d\n%d\n%d\n", x[c].numero, x[c].matricula,x[c].cm,
					      x[c].dpi, x[c].custo, x[c].ma, x[c].estado);		     
			}
		}
		fclose(f);
		printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); 
				
				
				return(0);
			}
		}
		printf("ERRO! Nao foi possivel Inserir"); getch(); return(0);
	}
	
	int elimina(camioes *x)
	{
		char confere;
		FILE *f;
        int c;
		long int eli;
		system("cls");
		printf("\n\nQual o Numero do camiao que quer Eliminar? "); scanf("%d",&eli);
		for(c=1;c<NR;c++)
		{
			if(x[c].numero==eli)
			{
				printf("\n\nNUMERO=%d\nMATRICULA=%s\nCARGA MAXIMA=%d\nDATA PROX INSPECCAO=%s\nCUSTO=%d\nMOTORISTA ASSOCIADO=%d\n\n",
				x[c].numero, x[c].matricula, x[c].cm, x[c].dpi, x[c].custo, x[c].ma);
				printf("\n\nQuer mesmo eliminar? <S/N>");confere=getch();
	
				if (confere!='S' && confere!='s')    return(0);
	
				x[c].estado=0;
				printf("\n\n\nRegisto eliminado <enter para continuar>");
				getch();  return (1);
				
		fclose(f);
		printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); 
				
				
				return(1);
			
			}
		}
		printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
		getch(); return (0);
	}
	
	int altera(camioes *x)
		{
			FILE *f;
            char confere;
			int c;
			long int alt;
			system("cls");
			printf("\n\nQual o Numero do camiao que quer Alterar? "); scanf("%d",&alt);
			for(c=1;c<NR;c++)
		{
				if(x[c].numero==alt)
				
					printf("\n\nNUMERO=%d\nMATRICULA=%s\nCARGA MAXIMA=%d\nDATA PROX INSPECCAO=%s\nCUSTO=%d\nMOTORISTA ASSOCIADO=%d\n\n", x[c].numero, x[c].matricula,x[c].cm, x[c].dpi, x[c].custo, x[c].ma);
					
					printf("\n\nQuer mesmo alterar? <S/N>");confere=getch();
		
					if (confere!='S' && confere!='s')    return(0);
		
						
				if(x[c].estado!=1)
			
				x[c].numero=alt;
				printf("\n\nMATRICULA= ");scanf("%s", x[c].matricula);
				printf("\n\nCARGA MAXIMA= ");scanf("%d", &x[c].cm);
				printf("\n\nDATA PROX INSPECCAO= ");scanf("%s", x[c].dpi);
				printf("\n\nCUSTO= ");scanf("%d", &x[c].custo);
				printf("\n\nMOTORISTA ASSOCIADO= ");scanf("%d", &x[c].ma);
				x[c].estado=1;
				printf("\n\n\nRegisto alterado <Enter para Continuar>");
								
				FILE *f;
		int c;
		if(!(f=fopen("\\camioes.txt","a+")))
		{
			printf("\n\n\nErro na Abertura para Gravar <Enter para Sair>");
			getch();  exit(0);
		}
	
		for(c=1;c<NR;c++)
		{
			if(x[c].estado==1)
			{
				fprintf(f,"%d\n%s\n%d\n%s\n%d\n%d\n%d\n", x[c].numero, x[c].matricula, x[c].cm, x[c].dpi, x[c].custo, x[c].ma, x[c].estado);
							      
			}
				printf("\n\n\nRegisto alterado <enter para continuar>");
				fclose(f);
		          printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); 
               getch();  return (1);
			}
		}
		printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
		getch(); return(0);
	}

/*----------------------------------------------------------------------------------OPCOES MENU CAMIOES FIM--------------------------------*/

/*void main(void)
{
	char op;
	int n;
	clientes cli[NR];
	for(n=0;n<NR;n++)
		cli[n].estado=0;   
	do{
		system ("cls"); gotoxy(20,5);
		printf("TRABALHO CEM RODAS - MENU PRINCIPAL\n");
		printf("L - Ler Ficheiro\nM - Mostrar Clientes\n");
		printf("I - Inserir Cliente\nE - Eliminar Cliente\n");
		printf("A - Alterar Cliente\nS - Sair\n\n");
		printf("\nQual a sua opcao? "); op=getch();
		switch(op)
		{
			case 'L': case 'l': ler(cli); break;
			case 'M': case 'm': mostrar(cli); break;
			case 'I': case 'i': inserir(cli); break;
			case 'E': case 'e': eliminar(cli); break;
			case 'A': case 'a': alterar (cli); break;
			case 'S': case 's': exit(0);
		}
	}while (op!='S' && op!='s');
}*/


int menu_clientes() 
		
        
        {
        int op;
        int n;
	       clientes cli[NR];
	       for(n=0;n<NR;n++)
		   cli[n].estado=0;   /* limpa todo o Array de registos */
        system ("cls"); gotoxy(20,5);
        ler(cli);
        do {
        
		system ("cls");						        
		printf("\n\t|============================================|"); system("COLOR 0B"); /* fundo preto caracteres azul */
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
        printf("\n\t*               4 - Listar Clientes          *");
        printf("\n\t*                                            *");
        printf("\n\t*               0 - Menu Principal           *");
		printf("\n\t*                                            *");
        printf("\n\t**********************************************");
        printf("\n\n\t             Qual a sua opcao? ");
				
				scanf("%d",&op);
               int n;
					switch (op) {
                        case 1: inserir(cli); break;
                        case 2: alterar(cli); break;
                        case 3: eliminar(cli); break;
						case 4: mostrar(cli); break;
                        case 0: system ("cls"); break;
                        default: printf("Opcao invalida!\n");
                }
        } while (op!=0);return (0);
}



int menu_camioes ()
{
	int op;
	int c;
	       camioes cam[NR];
	       for(c=0;c<NR;c++)
		   cam[c].estado=0;   /* limpa todo o Array de registos */
        system ("cls"); gotoxy(20,10);
        ler(cam);
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
		printf("\n\t*               4 - Listar                   *");
		printf("\n\t*                                            *");
        printf("\n\t*               0 - Menu Principal           *");
		printf("\n\t*                                            *");
        printf("\n\t**********************************************");
        printf("\n\n\t             Qual a sua opcao? ");
				
				scanf("%d",&op);
               
				switch (op) {
                        case 1: inseri(cam); break;
                        case 2: altera(cam); break;
                        case 3: elimina(cam); break;
                        case 4: mostra(cam); break;
						case 0: system ("cls"); break;
                        default: printf("Opcao invalida!\n");
                }
    } while (op!=0);
	
}


int menu_condutores ()
{
	int op;
	do {
		system ("cls");						        
		printf("\n\t|============================================|"); system("COLOR 08");
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


int menu_cargas ()
{
	int op;
	do {
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
	int n;
	       clientes cli[NR];
	       for(n=0;n<NR;n++)
		   /*cli[n].estado=0;   /* limpa todo o Array de registos */
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
        printf("\n\t*  5 - Listagem Clientes                     *");
        printf("\n\t*                                            *");
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
						case 5: mostrar(cli); system ("cls");break;
                        case 0: system ("cls"); return(0);
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
	    	printf("\n\t Introduza o numero de kilometros da viagem: ");
	    	scanf("%f",&klm);
	    	printf("\n\t Introduza o numero de toneladas a transportar: ");
	    	scanf("%f",&toneladas);
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
	int n;
	clientes cli[NR];
	for(n=1;n<NR;n++)
		cli[n].estado=0;   /* limpa todo o Array de registos */
       
    
       
       
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
	

		
	
