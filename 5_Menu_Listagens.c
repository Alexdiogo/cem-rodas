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
 