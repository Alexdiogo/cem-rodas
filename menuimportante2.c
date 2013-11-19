#include <stdio.h> 
#include <windows.h> 
#define NR 200                          /* Numero maximo de Registos  */            	
#define NA 200

typedef struct
{
	long int numero;
    char nome[60];
	char morada[60];
    int telefone;	
	int estado;		
}aluno;

typedef aluno ALUNOS[NA];

typedef struct 
{
		int numero;
		char nome[50];
		char morada[200];
		int telefone;
		char data_nascimento[11];
		int estado;
}condutor;




void menu1(void) {
        int op;
        do {
                
				printf("1 - Sub-opcao 1\n");
                printf("2 - Sub-opcao2\n");
                printf("0 - Retroceder\n");
                printf("\nIntroduza a opcao: ");
                scanf("%d",&op);
                scanf("%*c");
                system ("cls");
				switch (op) {
                        case 1: printf("Escolheu a sub-opcao 1.\n");
                                break;
                        case 2: printf("Escolheu a sub-opcao2.\n");
                                break;
                        case 0: system ("cls");break;
                        default: printf("Opcao invalida!\n");
                }
        } while (op!=0);
}
       
	   
	  
  
  void mostrar_cli(aluno *x)
{
	int n;
	system ("cls");
	for(n=1;n<NR;n++)
	{
		if(x[n].estado==1)
		{
			printf("NUMERO=%ld\nNOME=%s\nMORADA=%s\nTELEFONE%ld\nESTADO=%d\n\n",
			x[n].numero, x[n].nome, x[n].morada, x[n].telefone, x[n].estado);
		}
	}
	printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}


  void clientes (void)									/* MENU INSERIR CLIENTES NOVO A FUNCIONAR*/
{
   FILE *fp;
   char nome[100];
   char morada[100];
   char telefone[100];
   
   int n; 
   int m;
   int t;
   fp = fopen("clientes.txt","w");               /* Arquivo ASCII, para escrita */
   if(!fp)
    {
      printf( "Erro na abertura do arquivo");
      exit(0);
    }
   printf("\n\t|============================================|");
   printf("\n\t|                                            |");
   printf("\n\t| NOME: ");  														/* Grava a string, caractere a caractere */
   gets(nome);
   for(n=0; nome[n]; n++) putc(nome[n], fp);
   printf("\n\t|                                            |");
   printf("\n\t| MORADA: "); 
   gets(morada); 
   for(m=0; morada[m]; m++) putc(morada[m], fp);								/* Grava a string, caractere a caractere */
   printf("\n\t|                                            |");
   printf("\n\t| TELEFONE: "); 
   gets(telefone);
   for(t=0; telefone[t]; t++) putc(telefone[t], fp);							/* Grava a string, caractere a caractere */
   printf("\n\t|============================================|");
   fclose(fp);
   /*system ("pause");*/
   printf("\n\n\nFicheiro Lido <Enter para Continuar>");getch();system ("cls");
}
	   
	   
	    
        void menu_clientes (void) 
               
        
		{
        int op;
        do {
               
		printf("\n\t|============================================|"); system("COLOR 0C");
    	printf("\n\t|              C E M  R O D A S              |");
    	printf("\n\t|                                            |");
	   	printf("\n\t|                                            |");
    	printf("\n\t|               C L I E N T E S              |");
    	printf("\n\t|                                            |");
    	printf("\n\t|============================================|");
        printf("\n\t*                                            *"); 
        printf("\n\t*               1 - Inserir\t             *");
        printf("\n\t*                                            *"); 
        printf("\n\t*               2 - Alterar\t             *");
		printf("\n\t*                                            *"); 
        printf("\n\t*               3 - Eliminar\t             *");
        printf("\n\t*                                            *"); 
		printf("\n\t*               4 - Gravar\t             *");
		printf("\n\t*                                            *");
        printf("\n\t*               0 - Menu Principal\t     *");
		printf("\n\t*                                            *");
        printf("\n\t**********************************************");
        printf("\n\n\t             Qual a sua opcao? ");
				
				scanf("%d",&op);
                scanf("%*c");
               
				switch (op) {
                        case 1: clientes(); 
                                break;
                        case 2: inserir_cli();
                                break;
                        case 3: eliminar_cli();
                                break;
						case 4: gravar_cli();
						        break;
						case 0: system ("cls");break;
                        default: printf("Opcao invalida!\n\n");
                }
        } while (op!=0);
}
        
    ler_alunos(ALUNOS *x, int *na)
{
	FILE *f;
	int n, numero;
	if(!(f=fopen("c:\\alunos.txt","r")))
	{
		printf("Erro na Abertura de Leitura <Enter para Sair>");
		getch(); exit(0);
	}

	fscanf(f, "%d", &n);
	*na=n;
	
	for(n=0;n<*na;n++)
	{
		fscanf(f,"%ld\n%s\n%s\n%d\n%d\n", 
        &((*x)[n].numero),&((*x)[n].nome),&((*x)[n].morada),&((*x)[n].telefone), &((*x)[n].estado));
           
	}
	fclose(f);
	printf("\n\n\nFicheiro Lido <Enter para Continuar>");getch();
}    
       


		
	
	
	
	
	   int inserir_cli(aluno *x)
{
	int n;
	long int inser;
	system ("cls");
	printf("Qual o Numero do cliente que quer Inserir? ");
	scanf("%ld",&inser);
	for(n=1;n<NR;n++)
	{
		if(x[n].estado!=1)
		{
			x[n].numero=inser;
			printf("\n\nNome: ");scanf("%s", x[n].nome);
			printf("\n\nMorada: ");scanf("%s", &x[n].morada);
			printf("\n\nTelefone: ");scanf("%ld", &x[n].telefone);
			x[n].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
            break; /*return(1);*/	
		}
	}
	printf("ERRO! Nao foi possivel Inserir"); getch();return(0); 
}
	   
	   int eliminar_cli(ALUNOS *x, int *na)
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
			printf("\n\nNUMERO=%ld\nNOME=%s\nMORADA=%s\nTELEFONE=%ld\nESTADO=%d\n\n",
            &((*x)[n].numero), &((*x)[n].nome), &((*x)[n].morada), &((*x[n]).telefone), &((*x[n]).estado));
			printf("\n\nQuer mesmo eliminar? <S/N>");confere=getch();
			if (confere!='S' && confere!='s')    return(0);
			(*x[n]).estado=0;
			printf("\n\n\nRegisto eliminado <enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);
}
  
  void gravar_cli(aluno *x)
{
	FILE *f;
	int n;
	if(!(f=fopen("c:\\alunos.txt","w")))
	{
		printf("\n\n\nErro na Abertura para Gravar <Enter para Sair>");
		getch();  exit(0);
	}

	for(n=1;n<NR;n++)
	{
		if(x[n].estado==1)
		{
			fprintf(f,"%ld\n%s\n%s\n%ld\n%d\n",x[n].numero,x[n].nome,x[n].morada,x[n].telefone,x[n].estado);
		}
	}
	fclose(f);
	printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); 
    getch();
}
   
	  
	  
	  void menu_camioes(void) 										/* MENU CAMIOES*/
               
        
		{
        int op;
        do {
               
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
                scanf("%*c");
               
				switch (op) {
                        case 1: printf("Escolheu a sub-opcao 1.\n"); 
                                break;
                        case 2: printf("Escolheu a sub-opcao 2.\n");
                                break;
                        case 3: printf("Escolheu a sub-opcao 3.\n");
                                break;
						case 4: printf("Escolheu a sub-opcao 4.\n");
						        break;
						case 0: system ("cls");break;
                        default: printf("Opcao invalida!\n\n");
                }
        } while (op!=0);
}
	   
/*	   void mostrar_cli(aluno *x) 
{
	int n;
	system ("cls");
	for(n=1;n<NR;n++)
	{
		if(x[n].estado==1)
		{
			printf("NUMERO=%ld\nNOME=%s\nMORADA=%s\nTELEFONE%ld\nESTADO=%d\n\n",
			x[n].numero, x[n].nome, x[n].morada, x[n].telefone, x[n].estado);
		}
	}
	printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}
	   
*/	 
	 
	 
	   void menu_listagens(void) 
		{
        int op;
        do {
                
		printf("\n\t|============================================|"); system("COLOR 3E");
    	printf("\n\t|              C E M  R O D A S              |");
    	printf("\n\t|                                            |");
	   	printf("\n\t|                                            |");
    	printf("\n\t|              L I S T A G E N S             |");
    	printf("\n\t|                                            |");
    	printf("\n\t|============================================|");
        printf("\n\t*                                            *"); 
        printf("\n\t*           1 - Frota camioes\t             *");
        printf("\n\t*                                            *"); 
        printf("\n\t*           2 - Cargas por Camiao\t     *");
		printf("\n\t*                                            *"); 
        printf("\n\t*           3 - Cargas por Cliente/Custo     *");
        printf("\n\t*                                            *"); 
		printf("\n\t*           4 - Inspeccoes Mes corrente\t     *");
		printf("\n\t*                                            *");
        printf("\n\t*           0 - Menu Principal\t             *");
		printf("\n\t*                                            *");
        printf("\n\t**********************************************");
        printf("\n\n\t             Qual a sua opcao? ");
				
				scanf("%d",&op);
                scanf("%*c");
               
				switch (op) {
                        case 1: system ("cls"); printf("ler_alunos(ALUNOS *x, int *na);");
                                break;
                        case 2: printf("Opcao 2!\n");
                                break;
                        case 3: printf("Opcao 3!\n");
                                break;
						case 4: printf("Opcao 4!\n");
						        break;
						case 0: system ("cls");break;
                        default: printf("Opcao invalida!\n");
                }
        } while (op!=0);
}
	      
	    
        
int orcamento()
{
    int klm,toneladas;
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
         do { 
        printf("\n\t Introduza o numero de kilometros da viagem: ");
    	scanf("%d",&klm);
    	printf("\n\t Introduza o numero de toneladas a transportar: ");
    	scanf("%d",&toneladas);
    	res1=1*klm+50*toneladas;
    	printf("\n\t O Orcamento é de:%.2f euros",res1);
        printf("\n\n\n\t Orcamento Concluido <Enter para Continuar>");
        getch();system ("cls");return(0);
        }while(op!='0');
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
        printf("\n\t*              1 - Clientes\t             *");
        printf("\n\t*                                            *"); 
        printf("\n\t*              2 - Camioes\t             *");
		printf("\n\t*                                            *"); 
        printf("\n\t*              3 - Condutores\t             *");
        printf("\n\t*                                            *");
        printf("\n\t*              4 - Cargas\t             *");
		printf("\n\t*                                            *");
        printf("\n\t*              5 - Listagens\t             *");
        printf("\n\t*                                            *");
        printf("\n\t*              6 - Pesquisa\t             *");
        printf("\n\t*                                            *");
        printf("\n\t*              7 - Estatisticas\t             *");
        printf("\n\t*                                            *");
        printf("\n\t*              8 - Orcamento\t             *");
        printf("\n\t*                                            *");
		printf("\n\t*              9 - Iniciar Viagem\t     *");
		printf("\n\t*                                            *");
        printf("\n\t*                                            *");
        printf("\n\t*              0 - Sair                      *");
		printf("\n\t*                                            *");
        printf("\n\t**********************************************");
        printf("\n\n\t             Qual a sua opcao? ");
                scanf("%d",&op);
                scanf("%*c");
				 switch (op) {
                        case 1: system("cls"); menu_clientes();
		 						break; 									/*menu_clientes(alunos, na); break;*/
    	 				case 2: system("cls");menu_camioes();
		 						break;
		 				case 3: printf("clicou no 3");system("cls");
		 						break;
    	 				case 4: printf("clicou no 4");break;
		 				case 5: system("cls"); menu_listagens();
						 		break;
         				case 6: printf("clicou no 6");break;
		 				case 7: printf("clicou no 7");break;
		 				case 8: orcamento(); break;   
     	 				case 9: printf("clicou no 9");break;
		 				case 0: system ("cls");break;
		 				default: printf("Opcao invalida.\n");
         		}
         		
       } while (op!=0);
        printf("Fim!\n");
        return 0;
}
	

		
		/*int op;
        do {
                printf("-- MENU --\n");
                printf("1 - Opcao 1\n2 - Opcao 2\n3 - Opcao 3\n0 - Sair\n");
                printf("\nIntroduza a opcao: ");
                scanf("%d",&op);
                scanf("%*c");
                switch(op) {
                        case 1: menu1();
                                break;
                        case 2: printf("Escolheu a opcao2.\n");
                                break;
                        case 3: printf("Escolheu a opcao3.\n");
                                break;
                        case 0: break;
                        default: printf("Opcao invalida.\n");
                }
       } while (op!=0);
        printf("Fim!\n");
        return 0;*/
