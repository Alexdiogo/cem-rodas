int main(void) 
{
        
	char op;
	
	system("COLOR 0A");
	system("CHCP 1252");
    
    printf("\n\t|============================================|"); 
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
	do {
        printf("\n\n\t             Qual a sua opção? ");
		getch(op);
    } while (op < '0' || op > '9');          
        
	switch (op) {
		case '1': menu_clientes();break; 
    	case '2': menu_camioes();break;
		case '3': menu_condutores();break;
    	case '4': menu_cargas();break;
		case '5': menu_listagens();break;
        case '6': menu_pesquisa();break;
		case '7': menu_estatistica();break;
		case '8': menu_orcamento();break;   
     	case '9': menu_inic_viag();break;
		case 0: exit(1);break;
    }
         		
	
	return 0;
}
	