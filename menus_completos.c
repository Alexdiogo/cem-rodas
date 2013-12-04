#include <stdio.h>
#include <math.h>

//Menus completos e menu_orcamento a funcionar (Falta completar)

int menu_clientes() 
{
	int op;

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
	printf("\n\t*               0 - Menu Principal           *");
	printf("\n\t*                                            *");
	printf("\n\t**********************************************");
	do {
		printf("\n\n\t             Qual a sua opção? ");
		scanf("%d",&op);
	} while (op!=0);
		   
	switch (op) {
		case 1: printf("..."); break;
		case 2: printf("..."); break;
		case 3: printf("..."); break;
		case 0: system ("cls"); break;
	}       
}



int menu_camioes ()
{
	int op;
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
	do {
		printf("\n\n\t             Qual a sua opção? ");
		scanf("%d",&op);
	} while (op!=0);
		   
	switch (op) {
		case 1: printf("..."); break;
		case 2: printf("..."); break;
		case 3: printf("..."); break;
		case 0: system ("cls"); break;
	}
}


int menu_condutores ()
{
	int op;
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
	do {
		printf("\n\n\t             Qual a sua opção? ");
		scanf("%d",&op);
	} while (op!=0);
		   
	switch (op) {
		case 1: printf("..."); break;
		case 2: printf("..."); break;
		case 3: printf("..."); break;
		case 0: system ("cls"); break;
	}
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
		scanf("%d",&op);
	} while (op!=0);
		   
	switch (op) {
		case 1: printf("..."); break;
		case 2: printf("..."); break;
		case 3: printf("..."); break;
		case 0: system ("cls"); break;
	}
	
}
        
int menu_listagens ()
{
	int op;
	system ("cls");						        
	printf("\n\t|============================================|"); system("COLOR 0C");
	printf("\n\t|              C E M  R O D A S              |");
	printf("\n\t|                                            |");
	printf("\n\t|                                            |");
	printf("\n\t|              L I S T A G E N S             |");
	printf("\n\t|                                            |");
	printf("\n\t|============================================|");
	printf("\n\t*                                            *"); 
	printf("\n\t*  1 - Frota de Camiões                      *");
	printf("\n\t*                                            *"); 
	printf("\n\t*  2 - Cargas por Camião                     *");
	printf("\n\t*                                            *"); 
	printf("\n\t*  3 - Transportes/Custo por Cliente         *");
	printf("\n\t*                                            *");
	printf("\n\t*  4 - Camiões c/ Inspecção no Mes Corrente  *");
	printf("\n\t*                                            *");
	printf("\n\t*  0 - Menu Principal                        *");
	printf("\n\t*                                            *");
	printf("\n\t**********************************************");
	do {
		printf("\n\n\t             Qual a sua opção? ");
		scanf("%d",&op);
	} while (op!=0);
		   
	switch (op) {
		case 1: printf("..."); break;
		case 2: printf("..."); break;
		case 3: printf("..."); break;
		case 4: printf("..."); break;
		case 0: system ("cls"); break;
	}
	
}
 

int menu_pesquisa ()
{
	int op;
	system ("cls");						        
	printf("\n\t|============================================|"); system("COLOR 0A");
	printf("\n\t|              C E M  R O D A S              |");
	printf("\n\t|                                            |");
	printf("\n\t|                                            |");
	printf("\n\t|              P E S Q U I S A               |");
	printf("\n\t|                                            |");
	printf("\n\t|============================================|");
	printf("\n\t*                                            *"); 
	printf("\n\t*     1 - Camiões disponiveis por data       *");
	printf("\n\t*                                            *"); 
	printf("\n\t*     2 - Camiões por Destino                *");
	printf("\n\t*                                            *"); 
	printf("\n\t*     3 - Camiões por Carga Máxima           *");
	printf("\n\t*                                            *");
	printf("\n\t*     0 - Menu Principal                     *");
	printf("\n\t*                                            *");
	printf("\n\t**********************************************");
    do {
		printf("\n\n\t             Qual a sua opção? ");
		scanf("%d",&op);
	} while (op!=0);
		   
	switch (op) {
		case 1: printf("..."); break;
		case 2: printf("..."); break;
		case 3: printf("..."); break;
		case 0: system ("cls"); break;
	}
	
}


int menu_estatistica ()
{
	int op;
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
   do {
		printf("\n\n\t             Qual a sua opção? ");
		scanf("%d",&op);
	} while (op!=0);
		   
	switch (op) {
		case 1: printf("..."); break;
		case 2: printf("..."); break;
		case 3: printf("..."); break;
		case 0: system ("cls"); break;
	}
	
}
        
        
int orcamento()
{
    float klm,toneladas, res;
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
	} while (klm < 100);
	
	do {
		printf("\n\t Introduza o número de toneladas a transportar: ");
		scanf("%f",&toneladas);
	} while (toneladas<1);
	
	res1=1*klm+50*toneladas;
	printf("\n\t A sua viagem tem o valor de: %.2f euros",res);
	printf("\n\n\n\t Orçamento Concluído\n\t");
	system("pause");system ("cls");return(0);
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
	system("chcp 1252");
	printf("\n\t|============================================|"); system("COLOR 0A");
	printf("\n\t|       G E S T Ã O  D E  C A R G A S        |");
	printf("\n\t|             C E M   R O D A S              |");
	printf("\n\t|                                            |");
	printf("\n\t|         M E N U  P R I N C I P A L         |");
	printf("\n\t|============================================|");
	printf("\n\t*                                            *"); 
	printf("\n\t*              1 - Clientes                  *");
	printf("\n\t*                                            *"); 
	printf("\n\t*              2 - Camiões                   *");
	printf("\n\t*                                            *"); 
	printf("\n\t*              3 - Condutores                *");
	printf("\n\t*                                            *");
	printf("\n\t*              4 - Cargas                    *");
	printf("\n\t*                                            *");
	printf("\n\t*              5 - Listagens                 *");
	printf("\n\t*                                            *");
	printf("\n\t*              6 - Pesquisa                  *");
	printf("\n\t*                                            *");
	printf("\n\t*              7 - Estatísticas              *");
	printf("\n\t*                                            *");
	printf("\n\t*              8 - Orçamento                 *");
	printf("\n\t*                                            *");
	printf("\n\t*              9 - Iniciar Viagem            *");
	printf("\n\t*                                            *");
	printf("\n\t*                                            *");
	printf("\n\t*              0 - Sair                      *");
	printf("\n\t*                                            *");
	printf("\n\t**********************************************");
	do{
		printf("\n\n\t             Qual a sua opção? ");
		scanf("%d",&op);
	} while (op!=0);
        
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
		case 0: return 0;
	}
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
