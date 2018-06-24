#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char mat[10];
	char nome[50];
	char cpf[15];
	char curso[30];	
} cadaluno;

typedef struct{
	char rua[20];
	char num[5];
} endereco;

typedef struct{
	int dia;
	int mes;
	int ano;
} data;

typedef struct{
	char nome[50];
	char cod[15];
	char cpf[10];
	int idade;
	endereco e;
	data d;
} cadpaciente;

typedef struct{
	char nome[50];
	char cod[15];
	char curso[30];
}cadsupervisor;

typedef struct{
	char nome[50];
	char cod[15];
	char codpa[15];
	char area[50];
	data d;	
}cadagendamento;
typedef struct{
	char cod[15];
	int dia;
	int mes;
	char nome;
	int diad;
	int codd;
	int mesd;
	char area;
	char nomesup;
	int coda;
	int codsup;
}cadatendimento;

int cod=0;

cadaluno ca[100];
cadpaciente cp[100];
cadsupervisor sp[100];
cadagendamento ag[100];
cadatendimento at[100];

void menu();

void aluno();
void CadastrarAluno();
void RemoverAluno();
void EditarAluno();
void ListarAluno();

void paciente();
void CadastrasPaciente();
void RemoverPaciente();
void EditarPaciente();
void ListarPaciente(); 

void supervisor();
void CadastrasSupervisor();
void RemoverSupervisor();
void EditarSupervisor();
void ListarSupervisor();

void agendamento();
void CriarAgendamento();
void CancelarAgendamento();
void ListarAgendamento();

void atendimento();
void CriarAtendimento();
void RemoverrAtendimento();
void ListarAtendimento();

int opc;

FILE *ArqAluno;
FILE *ArqPaciente;
FILE *ArqSupervisor;
FILE *ArqAgendamento;
FILE *ArqAtendimento;
FILE *arquivo;
FILE *arquivo1;

main(){
	int cont;
	do{
		system("cls");
		menu();
		system("cls");
		printf ("\n\t\t   ===============================\n");
    	printf ("\t\t   |\t                         |\n");
    	printf("\t\t   |  Acao conluida com sucesso! |\n");
    	printf ("\t\t   |\t                         |\n");
    	printf ("\t\t   ===============================\n");
    	printf ("\n\n");
		printf("\nDeseja voltar ao menu principal?");
		printf("\n\n 1- sim \n 2- nao\n");
		printf("\n Opcao: ");
		scanf("%d", &cont);
	} while(cont==1);
}

void menu(){
	printf("\n");
	printf ("\t\t  Clinica Escola da Universidade Estadual da Paraiba\n");
    printf ("\n\t\t\t ===============================\n");
    printf ("\t\t\t |\t                       |\n");
    printf("\t\t\t | 1 - Menu do aluno           |\n");
    printf("\t\t\t | 2 - Menu do paciente        |\n");
    printf("\t\t\t | 3 - Menu do supervisor      |\n");
    printf("\t\t\t | 4 - Menu de agendamento     |\n");
    printf("\t\t\t | 5 - Menu de atendimento     |\n");
    printf("\t\t\t | 0 - Sair                    |\n");
    printf ("\t\t\t |\t                       |\n");
    printf ("\t\t\t ===============================\n");
    printf ("\n\n");
    printf("\t\t\t      Selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &opc);
    system("cls");
	switch(opc){
		case 1:
			aluno();
			break;
		case 2:
			paciente();
			break;
		case 3:
			supervisor();
			break;
		case 4:
			agendamento();
			break;
		case 5:
			atendimento();
			break;
		case 0:
			break;
	}
	
}

void RemoverAluno(){
	int i=0;
	char mat2[100];
	char mat[100], curso[100], cpf[100], nome[100];
    ArqAluno = fopen("aluno.txt","r");
    
	printf("Informe a Matricula do Aluno que deseja remover:\n");
    fflush(stdin);
    gets(mat2);

    for(i=0;i<1;++i){
           if(strcmp(ca[i].mat,mat2) == 0){
            memset (ca[i].nome, 0, sizeof (nome) );
            memset (ca[i].cpf, 0, sizeof (cpf) );
            memset (ca[i].curso, 0, sizeof (curso) );
            memset (ca[i].mat, 0, sizeof (mat) );

            break;
        }
    }
    ArqAluno=fopen("aluno.txt", "w");
    system("cls");
		
}

void ListarAluno(){
	ArqAluno=fopen("aluno.txt", "r");
	char palavra[1000], str1[10000];
	int i=0;
	while(fgets(str1, 100, ArqAluno)!=NULL){
	printf("%s\n", str1);
	fflush(stdin);
}
	system("pause");
}

void CadastrarAluno(){
	
	int i=0;
	int opc;
		for(i;i<100;i++){
			printf("\nNome do aluno: ");
			fflush(stdin);
			gets(ca[i].nome);
			fflush(stdin);
			printf("\nMatricula do aluno: ");
			gets(ca[i].mat);
			fflush(stdin);
			printf("\nCPF do aluno: ");
			gets(ca[i].cpf);
			fflush(stdin);
			printf("\nCurso do aluno: ");
			gets(ca[i].curso);
			fflush(stdin);
			ArqAluno = fopen("aluno.txt", "a");
		
			fprintf(ArqAluno,"\nAluno: %s", &ca[i].nome);
			fprintf(ArqAluno,"\nMatricula: %s", &ca[i].mat);
			fprintf(ArqAluno,"\nCPF: %s", &ca[i].cpf);
			fprintf(ArqAluno,"\nCurso: %s", &ca[i].curso);
			fprintf(ArqAluno, "\n\n------------------------------------------\n\n");
			
			fclose(ArqAluno);
			system("cls");
			printf ("\n\n\t\t=====================================\n");
   			printf ("\t\t|                                   |\n");
  			printf("\t\t|                                   |\n");
    		printf("\t\t| Deseja fazer um novo cadastro?    |\n");
    		printf("\t\t|                                   |\n");
    		printf ("\t\t|                                   |\n");
    		printf ("\t\t=====================================\n");
    		printf ("\n\n");
    		printf("\n\t\t\t    1-sim\t2-nao");
    		printf("\n\n\t\t        Selecione uma opcao: ");
    		fflush(stdin);
    		scanf("%d", &opc);
    		system("cls");
    		if(opc!=1){
    			break;
			}
    
	}
}

void EditarAluno(){
	int i=0;
	char mat2[100];
	char mat[100], curso[100], cpf[100], nome[100];
    ArqAluno = fopen("aluno.txt","r");
    
	printf("Informe a matricula do aluno que deseja editar: ");
    fflush(stdin);
    gets(mat2);

    for(i=0;i<1;++i){
           if(strcmp(ca[i].mat,mat2) == 0){
            memset (ca[i].nome, 0, sizeof (nome) );
            memset (ca[i].cpf, 0, sizeof (cpf) );
            memset (ca[i].curso, 0, sizeof (curso) );
            memset (ca[i].mat, 0, sizeof (mat) );

            break;
        }
    }
    ArqPaciente=fopen("aluno.txt", "w");
    system("cls");
    
    printf ("\n\n\t\t=====================================\n");
  			printf("\t\t|                                   |\n");
    		printf("\t\t| Informe novos dados do aluno      |\n");
    		printf("\t\t|                                   |\n");
    		printf ("\t\t=====================================\n");
    		printf ("\n\n");
    
		for(i;i<100;i++){
			printf("\nNome do aluno: ");
			fflush(stdin);
			gets(ca[i].nome);
			fflush(stdin);
			printf("\nMatricula do aluno: ");
			gets(ca[i].mat);
			fflush(stdin);
			printf("\nCPF do aluno: ");
			gets(ca[i].cpf);
			fflush(stdin);
			printf("\nCurso do aluno: ");
			gets(ca[i].curso);
			fflush(stdin);
			ArqAluno = fopen("aluno.txt", "a");
		
			fprintf(ArqAluno,"\nAluno: %s", &ca[i].nome);
			fprintf(ArqAluno,"\nMatricula: %s", &ca[i].mat);
			fprintf(ArqAluno,"\nCPF: %s", &ca[i].cpf);
			fprintf(ArqAluno,"\nCurso: %s", &ca[i].curso);
			fprintf(ArqAluno, "\n\n------------------------------------------\n\n");
			
			fclose(ArqAluno);
			break;
			system("cls");
	}
		
}

void aluno(cadaluno ca){
	printf("\n");
    printf ("\t\t\tPagina do aluno\n");
    printf ("\n\n\t\t===============================\n");
    printf ("\t\t|                             |\n");
    printf("\t\t| 1 - Cadastrar aluno         |\n");
    printf("\t\t| 2 - Remover aluno           |\n");
    printf("\t\t| 3 - Editar aluno            |\n");
    printf("\t\t| 4 - Listar aluno cadastrado |\n");
    printf("\t\t| 0 - Sair                    |\n");
    printf ("\t\t|                             |\n");
    printf ("\t\t===============================\n");
    printf ("\n\n");
    printf("\t\t        Selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &opc);
    system("cls");
	switch(opc){
		case 1:
			CadastrarAluno();
			break;
		case 2:
			RemoverAluno();
			break;
		case 3:
			EditarAluno();
			break;
		case 4:
			ListarAluno();
			break;
		case 0:
			break;
	}
}

void ListarPaciente(){
	ArqPaciente=fopen("paciente.txt", "r");
	char palavra[1000], str1[1000];
	int i=0;
	while(fgets(str1, 100, ArqPaciente)!=NULL){
	printf("%s\n", str1);
	fflush(stdin);
}
	system("pause");
}

void CadastrarPaciente(){
		int i=0;
		int opc;
		for(i;i<1000;i++){
			printf("\nNome do paciente: ");
			fflush(stdin);
			gets(cp[i].nome);
			fflush(stdin);
			printf("\nCPF do paciente: ");
			gets(cp[i].cpf);
			fflush(stdin);
			printf("\nIdade do paciente: ");
			scanf("%d", &cp[i].idade);
			fflush(stdin);
			printf("\nData de nascimento do paciente");
			printf("\nDia: ");
			fflush(stdin);
			scanf("%d", &cp[i].d.dia);
			fflush(stdin);
			printf("\nMes: ");
			scanf("%d", &cp[i].d.mes);
			fflush(stdin);
			printf("\nAno: ");
			scanf("%d", &cp[i].d.ano);
			fflush(stdin);
			printf("\nEndereço do paciente\n");
			printf("\nRua: ");
			gets(cp[i].e.rua);
			fflush(stdin);
			printf("\nNumero da casa: ");
			gets(cp[i].e.num);
			fflush(stdin);
			ArqPaciente = fopen("paciente.txt", "a");
		
			fprintf(ArqPaciente,"\nPaciente: %s", cp[i].nome);
			fprintf(ArqPaciente,"\nCodigo: %d", cod);
			fprintf(ArqPaciente,"\nCPF: %s", cp[i].cpf);
			fprintf(ArqPaciente,"\nIdade: %d", cp[i].idade);
			fprintf(ArqPaciente,"\nData de nascimento: %d/%d/%d", cp[i].d.dia, cp[i].d.mes, cp[i].d.ano);
			fprintf(ArqPaciente,"\nEndereco: Rua %s, Numero %s", cp[i].e.rua, cp[i].e.num);
			fprintf(ArqPaciente, "\n\n------------------------------------------\n\n");

			
			fclose(ArqPaciente);
			break;
			system("cls");
	}
}

void RemoverPaciente(){
	int i=0;
	char mat2[100];
	char mat[100], curso[100], cpf[100], nome[100];
    ArqPaciente = fopen("paciente.txt","r");
    
	printf("Informe o Codigo do paciente que deseja remover:\n");
    fflush(stdin);
    gets(mat2);

    for(i=0;i<1;++i){
           if(strcmp(ca[i].mat,mat2) == 0){
            memset (ca[i].nome, 0, sizeof (nome) );
            memset (ca[i].cpf, 0, sizeof (cpf) );
            memset (ca[i].curso, 0, sizeof (curso) );
            memset (ca[i].mat, 0, sizeof (mat) );

            break;
        }
    }
    ArqPaciente=fopen("paciente.txt", "w");
    system("cls");
		
}

void EditarPaciente(){
	int i=0;
	char mat2[100];
	char mat[100], curso[100], cpf[100], nome[100];
    ArqPaciente = fopen("paciente.txt","r");
    
	printf("Informe o Codigo do paciente que deseja editar: ");
    fflush(stdin);
    gets(mat2);

    for(i=0;i<1;++i){
           if(strcmp(ca[i].mat,mat2) == 0){
            memset (ca[i].nome, 0, sizeof (nome) );
            memset (ca[i].cpf, 0, sizeof (cpf) );
            memset (ca[i].curso, 0, sizeof (curso) );
            memset (ca[i].mat, 0, sizeof (mat) );

            break;
        }
    }
    ArqPaciente=fopen("paciente.txt", "w");
    system("cls");
    
    printf ("\n\n\t\t=====================================\n");
  			printf("\t\t|                                   |\n");
    		printf("\t\t| Informe novos dados do paciente   |\n");
    		printf("\t\t|                                   |\n");
    		printf ("\t\t=====================================\n");
    		printf ("\n\n");
    
		for(i;i<100;i++){
			printf("\nNome do paciente: ");
			fflush(stdin);
			gets(cp[i].nome);
			fflush(stdin);
			printf("\nCPF do paciente: ");
			gets(cp[i].cpf);
			fflush(stdin);
			printf("\nIdade do paciente: ");
			scanf("%d", &cp[i].idade);
			fflush(stdin);
			printf("\nData de nascimento do paciente");
			printf("\nDia: ");
			fflush(stdin);
			scanf("%d", &cp[i].d.dia);
			fflush(stdin);
			printf("\nMes: ");
			scanf("%d", &cp[i].d.mes);
			fflush(stdin);
			printf("\nAno: ");
			scanf("%d", &cp[i].d.ano);
			fflush(stdin);
			printf("\nEndereço do paciente\n");
			printf("\nRua: ");
			gets(cp[i].e.rua);
			fflush(stdin);
			printf("\nNumero da casa: ");
			gets(cp[i].e.num);
			fflush(stdin);
			ArqPaciente = fopen("paciente.txt", "a");
		
			fprintf(ArqPaciente,"\nPaciente: %s", cp[i].nome);
			fprintf(ArqPaciente,"\nCodigo: %d", cod);
			fprintf(ArqPaciente,"\nCPF: %s", cp[i].cpf);
			fprintf(ArqPaciente,"\nIdade: %d", cp[i].idade);
			fprintf(ArqPaciente,"\nData de nascimento: %d/%d/%d", cp[i].d.dia, cp[i].d.mes, cp[i].d.ano);
			fprintf(ArqPaciente,"\nEndereco: Rua %s, Numero %s", cp[i].e.rua, cp[i].e.num);
			fprintf(ArqPaciente, "\n\n------------------------------------------\n\n");
			
			fclose(ArqPaciente);
			break;
			system("cls");
	}
		
}

void paciente(cadpaciente cp){
	printf("\n");
    printf ("\t\t\tPagina do paciente\n");
    printf ("\n\n\t\t==================================\n");
    printf ("\t\t|                                |\n");
    printf("\t\t| 1 - Cadastrar paciente         |\n");
    printf("\t\t| 2 - Remover paciente           |\n");
    printf("\t\t| 3 - Editar paciente            |\n");
    printf("\t\t| 4 - Listar paciente cadastrado |\n");
    printf("\t\t| 0 - Sair                       |\n");
    printf ("\t\t|                                |\n");
    printf ("\t\t==================================\n");
    printf ("\n\n");
    printf("\t\t        Selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &opc);
    system("cls");
	switch(opc){
		case 1:
			CadastrarPaciente();
			break;
		case 2:
			RemoverPaciente();
			break;
		case 3:
			EditarPaciente();
			break;
		case 4:
			ListarPaciente();
			break;
	}
}
void ListarSupervisor(){
	ArqSupervisor=fopen("supervisor.txt", "r");
	char palavra[1000], str1[1000];
	int i=0;
	while(fgets(str1, 100, ArqSupervisor)!=NULL){
	printf("%s\n", str1);
	fflush(stdin);
}
	system("pause");
}

void CadastrarSupervisor(){
	int i=0;
		for(i;i<100;i++){
			printf("\nNome do supervisor: ");
			fflush(stdin);
			gets(sp[i].nome);
			fflush(stdin);
			printf("\nCodigo do supervisor: ");
			gets(sp[i].cod);
			fflush(stdin);
			printf("\nCurso do supervisor: ");
			gets(sp[i].curso);
			fflush(stdin);
			ArqSupervisor = fopen("supervisor.txt", "a");
			
		
			fprintf(ArqSupervisor,"\nSupervisor: %s", &sp[i].nome);
			fprintf(ArqSupervisor,"\nCodigo: %s", &sp[i].cod);
			fprintf(ArqSupervisor,"\nCurso: %s", &sp[i].curso);
			fprintf(ArqSupervisor, "\n\n------------------------------------------\n\n");
			
			fclose(ArqSupervisor);
			break;
			system("cls");
	}
}

void RemoverSupervisor(){
	int i=0;
	char mat2[100];
	char mat[100], curso[100], cpf[100], nome[100];
    ArqSupervisor = fopen("supervisor.txt","r");
    
	printf("Informe o Codigo do supervisor que deseja remover:\n");
    fflush(stdin);
    gets(mat2);

    for(i=0;i<1;++i){
           if(strcmp(ca[i].mat,mat2) == 0){
            memset (ca[i].nome, 0, sizeof (nome) );
            memset (ca[i].cpf, 0, sizeof (cpf) );
            memset (ca[i].curso, 0, sizeof (curso) );
            memset (ca[i].mat, 0, sizeof (mat) );

            break;
        }
    }
    ArqSupervisor=fopen("supervisor.txt", "w");
    system("cls");
		
}

void EditarSupervisor(){
	int i=0;
	char mat2[100];
	char mat[100], curso[100], cpf[100], nome[100];
    ArqSupervisor = fopen("supervisor.txt","r");
    
	printf("Informe o Codigo do supervisor que deseja editar: ");
    fflush(stdin);
    gets(mat2);

    for(i=0;i<1;++i){
           if(strcmp(ca[i].mat,mat2) == 0){
            memset (ca[i].nome, 0, sizeof (nome) );
            memset (ca[i].cpf, 0, sizeof (cpf) );
            memset (ca[i].curso, 0, sizeof (curso) );
            memset (ca[i].mat, 0, sizeof (mat) );

            break;
        }
    }
    ArqSupervisor=fopen("supervisor.txt", "w");
    system("cls");
    
    printf ("\n\n\t\t=====================================\n");
  			printf("\t\t|                                   |\n");
    		printf("\t\t| Informe novos dados do supervisor |\n");
    		printf("\t\t|                                   |\n");
    		printf ("\t\t=====================================\n");
    		printf ("\n\n");
    
		for(i;i<100;i++){
			printf("\nNome do supervisor: ");
			fflush(stdin);
			gets(sp[i].nome);
			fflush(stdin);
			printf("\nCodigo do supervisor: ");
			gets(sp[i].cod);
			fflush(stdin);
			printf("\nCurso do supervisor: ");
			gets(sp[i].curso);
			fflush(stdin);
			ArqSupervisor = fopen("supervisor.txt", "a");
			
		
			fprintf(ArqSupervisor,"\nSupervisor: %s", &sp[i].nome);
			fprintf(ArqSupervisor,"\nCodigo: %s", &sp[i].cod);
			fprintf(ArqSupervisor,"\nCurso: %s", &sp[i].curso);
			fprintf(ArqSupervisor, "\n\n------------------------------------------\n\n");
			
			fclose(ArqSupervisor);
			break;
			system("cls");
	}
		
}

void supervisor(cadsupervisor sp){
	printf("\n");
    printf("\t\t\tPagina do supervisor\n");
    printf("\n\n\t\t====================================\n");
    printf("\t\t|                                  |\n");
    printf("\t\t| 1 - Cadastrar supervisor         |\n");
    printf("\t\t| 2 - Remover supervisor           |\n");
    printf("\t\t| 3 - Editar supervisor            |\n");
    printf("\t\t| 4 - Listar supervisor cadastrado |\n");
    printf("\t\t| 0 - Sair                         |\n");
    printf("\t\t|                                  |\n");
    printf("\t\t====================================\n");
    printf("\n\n");
    printf("\t\t        Selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &opc);
    system("cls");
	switch(opc){
		case 1:
			CadastrarSupervisor();
			break;
		case 2:
			RemoverSupervisor();
			break;
		case 3:
			EditarSupervisor();
			break;
		case 4:
			ListarSupervisor();
			break;
	}
}

void CriarAgendamento(){
		int i=0;
		for(i;i<100;i++){
			printf("\nNome do paciente: ");
			fflush(stdin);
			gets(ag[i].nome);
			fflush(stdin);
			printf("\nCodigo do paciente: ");
			gets(ag[i].codpa);
			fflush(stdin);
			printf("\nArea do agendamento: ");
			gets(ag[i].area);
			fflush(stdin);
			printf("\nData do agendamento\n");
			printf("\nDia:");
			scanf("%d", &ag[i].d.dia);
			fflush(stdin);
			printf("\nMes:");
			scanf("%d", &ag[i].d.mes);
			fflush(stdin);
			printf("\nAno:");
			scanf("%d", &ag[i].d.ano);
			fflush(stdin);
			ArqAgendamento = fopen("agendamento.txt", "a");
			fprintf(ArqAgendamento, "\n\n------------------------------------------\n\n");
			
			cod++;
		
			fprintf(ArqAgendamento,"\nPaciente: %s", &ag[i].nome);
			fprintf(ArqAgendamento,"\nCodigo do agendamento: %d", cod);
			fprintf(ArqAgendamento,"\nCodigo do paciente: %s", ag[i].codpa);
			fprintf(ArqAgendamento,"\nArea do agendamento: %s", ag[i].area);
			fprintf(ArqAgendamento,"\nData do agendamento: %d/%d/%d", ag[i].d.dia, ag[i].d.mes, ag[i].d.ano);
			
			fclose(ArqAgendamento);
			break;
			system("cls");
	}
}

void RemoverAgendamento(){
	int i=0;
	char mat2[100];
	char mat[100], curso[100], cpf[100], nome[100];
    ArqAgendamento = fopen("agendamento.txt","r");
    
	printf("Informe o Codigo do agendamento que deseja remover:\n");
    fflush(stdin);
    gets(mat2);

    for(i=0;i<1;++i){
           if(strcmp(ca[i].mat,mat2) == 0){
            memset (ca[i].nome, 0, sizeof (nome) );
            memset (ca[i].cpf, 0, sizeof (cpf) );
            memset (ca[i].curso, 0, sizeof (curso) );
            memset (ca[i].mat, 0, sizeof (mat) );

            break;
        }
    }
    ArqAgendamento=fopen("agendamento.txt", "w");
    system("cls");
}

void ListarAgendamento1(){
	ArqAgendamento=fopen("agendamento.txt", "r");
	char palavra[1000], str1[1000];
	int i=0;
	while(fgets(str1, 100, ArqAgendamento)!=NULL){
	printf("%s\n", str1);
	fflush(stdin);
}
	system("pause");
}

void ListarAgendamento2(){
	char c;
	printf("\nInforme a area: ");
	scanf("%s", &c);
	ArqAgendamento=fopen("agendamento.txt", "r");
	char palavra[1000], str1[1000];
	int i=0;
	while(fgets(str1, 100, ArqAgendamento)!=NULL){
	printf("%s\n", str1);
	fflush(stdin);
}
	system("pause");
}

void ListarAgendamento3(){
	char c;
	printf("\nInforme o nome do aluno: ");
	scanf("%s", &c);
	ArqAgendamento=fopen("agendamento.txt", "r");
	char palavra[1000], str1[1000];
	int i=0;
	while(fgets(str1, 100, ArqAgendamento)!=NULL){
	printf("%s\n", str1);
	fflush(stdin);
}
	system("pause");
}

void ListarAgendamento4(){
	char c;
	printf("\nInforme o nome do paciente: ");
	scanf("%s", &c);
	ArqAgendamento=fopen("agendamento.txt", "r");
	char palavra[1000], str1[1000];
	int i=0;
	while(fgets(str1, 100, ArqAgendamento)!=NULL){
	printf("%s\n", str1);
	fflush(stdin);
}
	system("pause");
}

void agendamento(cadagendamento ag){
	printf("\n");
    printf ("\t\t\tPagina de agendamento\n");
    printf ("\n\n\t\t===============================\n");
    printf ("\t\t|                             |\n");
    printf("\t\t| 1 - Criar novo agendamento  |\n");
    printf("\t\t| 2 - Remover agendamento     |\n");
    printf("\t\t| 3 - Listar agendamento      |\n");
    printf("\t\t| 0 - Sair                    |\n");
    printf ("\t\t|                             |\n");
    printf ("\t\t===============================\n");
    printf ("\n\n");
    printf("\t\t        Selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &opc);
    system("cls");
	switch(opc){
		case 1:
			CriarAgendamento();
			break;
		case 2:
			RemoverAgendamento();
			break;
		case 3:
			printf ("\n\n\t\t====================================\n");
    		printf ("\t\t|                                  |\n");
    		printf("\t\t| 1 - Listar todos os agendamentos |\n");
   			printf("\t\t| 2 - Listar por area              |\n");
    		printf("\t\t| 3 - Listar por aluno             |\n");
    		printf("\t\t| 4 - Listar por paciente          |\n");
    		printf("\t\t| 0 - sair                         |\n");
    		printf ("\t\t|                                  |\n");
    		printf ("\t\t====================================\n");
    		printf ("\n\n");
    		printf("\t\t        Selecione uma opcao: ");
    		scanf("%d", &opc);
    		system("cls");
    		switch(opc){
    			case 1:
    				ListarAgendamento1();
    				break;
    			case 2:
    				ListarAgendamento2();
    				break;
    			case 3:
    				ListarAgendamento3();
    				break;
    			case 4:
    				ListarAgendamento4();
    				break;
    			case 0:
    				break;
			}
	}
}

void CriarAtendimento(){
int i=0;
int cod=0;
		for(i;i<100;i++){
			printf("\nNome do atendido: ");
			fflush(stdin);
			scanf("%s", &at[i].area);
			printf("\nCodigo do atendido: ");
			scanf("%d", &at[i].coda);
			fflush(stdin);
			printf("\nNome do supervisor: ");
			fflush(stdin);
			scanf("%s", &at[i].nomesup);
			printf("\nCodigo do supervisor: ");
			scanf("%d", &at[i].codsup);
			fflush(stdin);
			printf("\nCodigo do agendamento: ");
			scanf("%d", &at[i].codd);
			fflush(stdin);
			printf("\nServico prestado (are do atendimento): ");
			scanf("%s", &at[i].area);
			fflush(stdin);
			printf("\nData do agendamento\n");
			printf("\nDia:");
			scanf("%d", &at[i].dia);
			fflush(stdin);
			printf("\nMes:");
			scanf("%d", &at[i].mes);
			fflush(stdin);
			printf("\nAno:");
			printf("\nData do atendimento\n");
			printf("\nDia:");
			scanf("%d", &at[i].diad);
			fflush(stdin);
			printf("\nMes:");
			scanf("%d", &at[i].mesd);
			fflush(stdin);
			ArqAtendimento = fopen("atendimento.txt", "r");
			fprintf(ArqAtendimento, "\n\n------------------------------------------\n\n");
			
			cod++;
		
			fprintf(ArqAtendimento,"\nAtendido: %s", &at[i].nome);
			fprintf(ArqAtendimento,"\nCodigo do agendamento: %d", &at[i].codd);
			fprintf(ArqAtendimento,"\nCodigo do atendimento: %d", cod);
			fprintf(ArqAtendimento,"\nSupervisor: %s", at[i].nomesup);
			fprintf(ArqAtendimento,"\nArea do atendimento: %s", at[i].area);
			fprintf(ArqAtendimento,"\nData do agendamento: %d/%d/2018", at[i].dia, at[i].mes);
			fprintf(ArqAtendimento,"\nData do atendimento: %d/%d/2018", at[i].diad, at[i].mesd);
			
			fclose(ArqAtendimento);
			break;
			system("cls");
	}
}

void RemoverAtendimento(){
	int i=0;
	char mat2[100];
	char mat[100], curso[100], cpf[100], nome[100];
    ArqAtendimento = fopen("atendimento.txt","r");
    
	printf("Informe o Codigo do atendimento que deseja remover:\n");
    fflush(stdin);
    gets(mat2);

    for(i=0;i<1;++i){
           if(strcmp(ca[i].mat,mat2) == 0){
            memset (ca[i].nome, 0, sizeof (nome) );
            memset (ca[i].cpf, 0, sizeof (cpf) );
            memset (ca[i].curso, 0, sizeof (curso) );
            memset (ca[i].mat, 0, sizeof (mat) );

            break;
        }
    }
    ArqPaciente=fopen("atendimento.txt", "w");
    system("cls");
}

void ListarAtendimento1(){
	ArqAtendimento=fopen("atendimento.txt", "r");
	char palavra[1000], str1[1000];
	int i=0;
	while(fgets(str1, 100, ArqAtendimento)!=NULL){
	printf("%s\n", str1);
	fflush(stdin);
}
	system("pause");
}

void ListarAtendimento2(){
	char c;
	printf("\nInforme a area do atendimento: ");
	scanf("%s", &c);
	ArqAtendimento=fopen("atendimento.txt", "r");
	char palavra[1000], str1[1000];
	int i=0;
	while(fgets(str1, 100, ArqAtendimento)!=NULL){
	printf("%s\n", str1);
	fflush(stdin);
}
	system("pause");
}

void ListarAtendimento3(){
	char c;
	printf("\nInforme o nome do atendido: ");
	scanf("%s", &c);
	ArqAtendimento=fopen("atendimento.txt", "r");
	char palavra[1000], str1[1000];
	int i=0;
	while(fgets(str1, 100, ArqAtendimento)!=NULL){
	printf("%s\n", str1);
	fflush(stdin);
}
	system("pause");
}

void atendimento(cadatendimento at){
	printf("\n");
    printf ("\t\t\tPagina de atendimento\n");
    printf ("\n\n\t\t===============================\n");
    printf ("\t\t|                             |\n");
    printf("\t\t| 1 - Criar novo atendimento  |\n");
    printf("\t\t| 2 - Remover atendimento     |\n");
    printf("\t\t| 3 - Listar atendimento      |\n");
    printf("\t\t| 0 - Sair                    |\n");
    printf ("\t\t|                             |\n");
    printf ("\t\t===============================\n");
    printf ("\n\n");
    printf("\t\t        Selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &opc);
    system("cls");
	switch(opc){
		case 1:
			CriarAtendimento();
			break;
		case 2:
			RemoverAtendimento();
			break;
		case 3:
			printf ("\n\n\t\t====================================\n");
    		printf ("\t\t|                                  |\n");
    		printf("\t\t| 1 - Listar todos os atendimentos |\n");
   			printf("\t\t| 2 - Listar por area              |\n");
    		printf("\t\t| 3 - Listar por nome              |\n");
    		printf("\t\t| 0 - sair                         |\n");
    		printf ("\t\t|                                  |\n");
    		printf ("\t\t====================================\n");
    		printf ("\n\n");
    		printf("\t\t        Selecione uma opcao: ");
    		scanf("%d", &opc);
    		system("cls");
    		switch(opc){
    			case 1:
    				ListarAtendimento1();
    				break;
    			case 2:
    				ListarAtendimento2();
    				break;
    			case 3:
    				ListarAtendimento3();
    				break;
    			case 0:
    				break;
			}
	}
}
