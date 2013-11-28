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
                        case 1: menu_clientes();break; 
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
	