#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int contador,nivel,ultimopaciente;

struct cadastro{
	int codigo;
	char nome[20];
	char CPF[20];
	char Fone[11];
	char nivel[20];
};
struct cadastro pacientes[32];

int cadastrar(int){
	contador=contador+1;
	pacientes[contador].codigo=contador;
	printf("Nome: ");
	fflush(stdin);
	gets(pacientes[contador].nome);
	printf("CPF: ");
	gets(pacientes[contador].CPF);
	//scanf("%d",&pacientes[contador].CPF);
	printf("Fone: ");
	gets(pacientes[contador].Fone);
	//scanf("%d",&pacientes[contador].Fone);
	return contador;
}

int perguntas(int nivel){
	int lacoperguntas,resposta;
	char perguntas[5][50]={"Possui febre?\n  1.Sim\n  2.Nao","Possui nausea?\n  1.Sim\n  2.Nao","Possui dor corporal?\n  1.Sim\n  2.Nao","Possui sangramento?\n  1.Sim\n  2.Nao","Possui dor intestinal?\n  1.Sim\n  2.Nao"};
	
	for(lacoperguntas=0;lacoperguntas<5;lacoperguntas++){

	printf("%s\n",perguntas[lacoperguntas]);scanf("%d",&resposta);if(resposta==1){nivel++;
	
	}
	}
	
	return nivel;
	
	system("pause");
}
void classificacao(){
	int nivel;
	if(perguntas(nivel)==5){
		printf("Paciente ala vermelha, alto risco!\n");
		//pacientes[contador].nivel="Ala vermelha";
		strcpy(pacientes[ultimopaciente].nivel,"Ala vermelha");
	}else if(nivel>=3){
		printf("Paciente ala amarela, risco moderado!\n");
		//pacientes[contador].nivel="Ala amarela";
		strcpy(pacientes[ultimopaciente].nivel,"Ala amarela");
	}else{
		printf("Paciente ala verde, risco baixo!\n");
		//pacientes[contador].nivel="Ala verde";
		strcpy(pacientes[ultimopaciente].nivel,"Ala verde");
	}
	system("pause");
}

void verificarcadastros(){
	int mostrados;
	for(mostrados=1;mostrados<=contador;mostrados++){
	printf("\nCodigo: %d\n",pacientes[mostrados].codigo);
	printf("\nNome: %s\n",pacientes[mostrados].nome);
	printf("CPF: %s\n",pacientes[mostrados].CPF);
	printf("Fone: %s\n",pacientes[mostrados].Fone);
	printf("Nivel de condicao: %.s\n",pacientes[mostrados].nivel);
    }
    system("pause");
}

void triar(){
	int resposta;
	//printf("Cliente possui cadastro?\n  1.Sim\n  2.Nao");scanf("%d",&resposta);if(resposta==2){
		cadastrar(ultimopaciente);
		classificacao();
	//}else{
	//	classificacao();
	//}
	
}

main(){
	int menu=0;
	printf("Ola Leozin, ");
	
	do{
	
	printf("\nOque deseja?\n\n 1.Triar paciente\n 2.Atualizar sintomas\n 3.Cadastrar\n 4.Verificar cadastro\n 0.Sair\n");
	
	scanf("%d",&menu);
	
	switch(menu){
		case 3:
			cadastrar(ultimopaciente);		
		break;
		case 2:
			classificacao();
		break;
		case 1:
			triar();
		break;
		case 4:
			verificarcadastros();
		break;
		default:
			printf("Invalido");
	}
	system("cls");
}while(menu!=0);
	return 0;
}
