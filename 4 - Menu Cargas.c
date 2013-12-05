struct carga {
	int numero_carga;
	int numero_cliente;
	char local_origem[100];
	char local_destino[100]
	int distancia;
	int peso;
	char data[11];
};

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
        