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
