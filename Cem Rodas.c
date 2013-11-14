#include <stdio.h> 
#include <windows.h> 
#define NR 200                          /* Numero maximo de Registos  */            	
#define NA 200
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

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
/*
void ler_alunos(ALUNOS *x, int *na)
{
	FILE *f;
	int n, numero;
	if(!(f=fopen("f:\\alunos.txt","r")))
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
*/
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
            return(1);	
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
	if(!(f=fopen("f:\\alunos.txt","w")))
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

int menu_clientes(ALUNOS *alunos, int *na)
{
	char op;
	int n;
	/* aluno alu[NR];
	* for(n=0;n<*na;n++)
	*	alu[n].estado=0;
	* acho que este pedaço de código não é necessário, está ainda aqui se for necessário
	*/
	system ("cls");
	printf("\n1- Ler Ficheiro\n2- Inserir\n3- Alterar\n4- Eliminar\n5- Gravar\n0- Menu Principal\n\n");
	do{
		printf("Qual a sua opção? "); 
		op=getch();
	} while (op < '0' || op > '5');
	switch(op)
	{          
		case '2': inserir_cli(alu); break;
		case '4': eliminar_cli(alunos, na); break;
		case '5': gravar_cli(alu); break;
		case '0': menu();
	}
}
    
int menu_condutores()
{
	char op;
	int n;
	condutor con[NR];
	for(n=0;n<NR;n++)
		con[n].estado=0;
	system ("cls");
	printf("\n1- Inserir\n2- Alterar\n3- Eliminar\n4- Gravar\n0- Menu Principal\n\n");
	do{
		printf("Qual a sua opção? "); 
		op=getch();
	} while (op < '0' || op > '4');
	switch(op)
	{
		case '1': inserir_con(con); break;
		//case '3': eliminar_con(con); break;
		//case '4': gravar_con(con); break;
		case '0': menu();
	}
}

//void gravar_con(condutor *x)
//{
//	FILE *f;
//	int n;
//	if(!(f=fopen("f:\\condutores.txt","w")))
//	{
//		printf("\n\n\nErro na Abertura para Gravar <Enter para Sair>");
//		getch();  exit(0);
//	}
//
//	for(n=1;n<NR;n++)
//	{
//		if(x[n].estado==1)
//		{
//			fprintf(f,"%ld\n%s\n%d\n%d\n",x[n].numero,x[n].nome,
//						      x[n].morada, x[n].telefone, x[n].estado);
//		}
//	}
//	fclose(f);
//	printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); 
//    getch();
//}
// há problema com este código?


//int eliminar_con(condutor *x)
//{
//	char confere;
//	int n;
//	long int eli;
//	system("cls");
//	printf("Qual o Numero do aluno que quer Eliminar? "); scanf("%ld",&eli);
//	for(n=1;n<NR;n++)
//	{
//		if(x[n].numero==eli)
//		{
//			printf("\n\nNUMERO=%ld\nNOME=%s\nNOTA=%d\nESTADO=%d\n\n",
//			x[n].numero,x[n].nome,x[n].morada,x[n].telefone,x[n].estado);
//			printf("\n\nQuer mesmo eliminar? <S/N>");confere=getch();
//
//			if (confere!='S' && confere!='s')    return(0);
//
//			x[n].estado=0;
//			printf("\n\n\nRegisto eliminado <enter para continuar>");
//			getch();  return (1);
//		}
//	}
//	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
//	getch(); return(0);
//}

int inserir_con(condutor *x)
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
			printf("\n\nData de Nascimento: ");scanf("%ld", &x[n].data_nascimento);
			x[n].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
            return(1);	
		}
	}
	printf("ERRO! Nao foi possivel Inserir"); getch();return(0); 
}
	
int listagens()
{
	char op;
	int n;
	aluno alu[NR];
	for(n=0;n<NR;n++)
		alu[n].estado=0; //acho que esta parte ainda não está completa
	int tipo2;
	system ("cls");
	printf("\n1- Clientes\n2- Camiões\n3- Condutores\n4- Cargas\n0- Menu Principal\n\n");
	do{
		printf("Qual a sua opção? "); op=getch();
	} while (op < '0' || op > '4');
	switch(op)
	{
		case '1': mostrar_cli(alu); break;
		case '0': exit(0);
	}
}  
  
int orcamento()
{
	int klm,toneladas;
	float res1;
	char op;
	system("cls");
	printf("\n\t|============================================|");
	printf("\n\t|                                            |");
	printf("\n\t|            O R C A M E N T O S             |");
	printf("\n\t|             C E M   R O D A S              |");
	printf("\n\t|                                            |");
	printf("\n\t|============================================|");
	do { 
		printf("\n\t Introduza o numero de kilómetros da viagem: ");
		scanf("%d",&klm);
		printf("\n\t Introduza o numero de toneladas a transportar: ");
		scanf("%d",&toneladas);
		res1=1*klm+50*toneladas;
		printf("\n\t O Orçamento é de:%f euros",res1);
		printf("\n\n\n\t Orcamento Concluido");
		system("pause");
		return(0); //acho que esta instrução faz com que não verifique o ciclo
	}while(op!='0');
}   	

int menu(ALUNOS *alunos, int *na)
{
	char op;
	system("chcp 1252");      
	system ("cls"); 
	printf("\n\t|============================================|");
	printf("\n\t|                                            |");
	printf("\n\t|             C E M   R O D A S              |");
	printf("\n\t|                                            |");
	printf("\n\t|============================================|");
	printf("\n\t1 - Clientes\n\t2 - Camiões\n");
	printf("\t3 - Condutores\n\t4 - Cargas\n");
	printf("\t5 - Listagens\n\t6 - Pesquisa\n");
	printf("\t7 - Estatísticas\n\t8 - Orçamento\n");
	printf("\t9 - Iniciar Viagem\n\t0 - Sair\n\n");
	do {
		printf("\n\tQual a sua opção? ");
		op=getch();
	} while (op < '0' || op > '9');
	switch(op)
	{         
	 case '1': menu_clientes(alunos, na); break;
	 case '3': menu_condutores(); break;
	 case '5': listagens(); break; 
	 case '8': orcamento(); break;   
	 case '0': exit(0);
   }
}

int main(void)          
{
	ALUNOS alunos;
	int na;
	ler_alunos(&alunos, &na);                   
	menu();
} 
