#include <stdio.h>

int menu_condutores ()
{
	int op;
	do {
		system ("cls");						        
		printf("\n\t|============================================|"); system("COLOR 0A");
    	printf("\n\t|              C E M  R O D A S              |");
    	printf("\n\t|                                            |");
	   	printf("\n\t|                                            |");
    	printf("\n\t|             C O N D U T O R E S            |");
    	printf("\n\t|                                            |");
    	printf("\n\t|============================================|");
        printf("\n\t*                                            *"); 
        printf("\n\t*               1 - Inserir\t             *");
        printf("\n\t*                                            *"); 
        printf("\n\t*               2 - Alterar\t             *");
		printf("\n\t*                                            *"); 
        printf("\n\t*               3 - Eliminar\t             *");
        printf("\n\t*                                            *");
        printf("\n\t*               0 - Menu Principal\t     *");
		printf("\n\t*                                            *");
        printf("\n\t**********************************************");
        printf("\n\n\t             Qual a sua opcao? ");
				
				scanf("%d",&op);
                scanf("%*c");
               
				switch (op) {
                        case 1: printf("1 - Inserir condutor\n");
                                break;
                        case 2: printf("2 - Alterar condutor\n");
                                break;
                        case 3: printf("3 - Eliminar condutor\n");
                                break;
						case 0: system ("cls");break;
                        default: printf("Opcao invalida!\n");
                }
    } while (op!=0);
	
}





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
        
        void menu_clientes(void) 
		{
        int op;
        do {
                
		system("cls");
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
        printf("\n\t*               0 - Menu Principal\t     *");
		printf("\n\t*                                            *");
        printf("\n\t**********************************************");
        printf("\n\n\t             Qual a sua opcao? ");
				
				scanf("%d",&op);
                scanf("%*c");
               
				switch (op) {
                        case 1: printf("1 - Inserir cliente\n");
                                break;
                        case 2: printf("2 - Alterar cliente\n");
                                break;
                        case 3: printf("3 - Eliminar cliente\n");
                                break;
						case 0: system ("cls");break;
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
         do { 
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
                        case 1: menu_clientes();system("cls");
		 						break; 									/*menu_clientes(alunos, na); break;*/
    	 				case 2: menu1();
		 						break;;system("cls");
		 				case 3: menu_condutores();system("cls");
		 						break;
    	 				case 4: printf("clicou no 4");break;
		 				case 5: printf("clicou no 5");break;
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
