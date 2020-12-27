/*--------------------------------------------------*/
/*####          PROGRAMACAO EM C                ####*/
/*--------------------------------------------------*/
/*$$$$ APLICACAO                                $$$$*/
/*$$$$ nome : aplicacao<XX>.c                   $$$$*/
/*$$$$ autor: <nome>                            $$$$*/
/*--------------------------------------------------*/
/*@@@@ DIRECTIVAS DE INCLUSAO                   @@@@*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#include "inputValues.h"

/*@@@@ DIRECTIVAS DE DEFINCAO                   @@@@*/


/*@@@@ VARIAVEIS GLOBAIS                        @@@@*/
int numeroPacientes;
/*@@@@ ESTRUTURAS                               @@@@*/
struct paciente{
	int id;
	char nome[20];
	int idade;
	char sexo;
	int primeiraConsulta;
	int ultimaConsulta;
	int proximaConsulta;
	char situacaoClinica[20];
	char nomeMedico[20];
	char especialidade[20];
}typedef paciente;

struct medico{
	int id;
	char nome[20];
	char especialidade[20];
	int experiencia;
	char localidade;
	int telefone;
	int salario;
	char horario[20];
};

/*@@@@ FUNCOES E PROCEDIMENTOS                  @@@@*/

void setProximaConsulta(paciente pacientes[20],int idPaciente){
	int data,i;
	printf("Insira data da nova consulta");
	scanf("%d",&data);
	for(i=0;i<=numeroPacientes;i++){
		if(pacientes[i].proximaConsulta==data){
			printf("Erro já existe uma consulta nesta data");
		}
		else{
				pacientes[idPaciente].proximaConsulta=data;

		}
	}
}

int registados(char *nomeFicheiro){
	int linhas,ch;
	FILE *fp=fopen(nomeFicheiro,"r");

		while(!feof(fp))
		{
  		ch = fgetc(fp);
  		if(ch == '\n'){
    linhas++;
  	}
	}
	return linhas;
}




void verificaFicheiros(FILE *pacientes,FILE *medicos,FILE *consultas){

	if((pacientes=fopen("pacientes.txt","r"))==NULL){
		fclose(pacientes);
		pacientes=fopen("pacientes.txt","w");
		fclose(pacientes);
	}
	if((medicos=fopen("medicos.txt","r"))==NULL){
		fclose(medicos);
		medicos=fopen("medicos.txt","w");
		fclose(medicos);
	}
	if((consultas=fopen("consultas.txt","r"))==NULL){
		fclose(consultas);
		consultas=fopen("consultas.txt","w");
		fclose(consultas);
	}


}

void print(paciente pacientes[20],int numeroPacientes){

	printf("%s\n", pacientes[numeroPacientes].nome);
	printf("%d\n",pacientes[numeroPacientes].idade);
	printf("%c\n", pacientes[numeroPacientes].sexo);
	printf("%d\n",pacientes[numeroPacientes].primeiraConsulta);
	printf("%d\n",pacientes[numeroPacientes].ultimaConsulta);
	printf("%d\n",pacientes[numeroPacientes].proximaConsulta);
	printf("%s\n",pacientes[numeroPacientes].nomeMedico);
	printf("%s\n",pacientes[numeroPacientes].situacaoClinica);
	printf("%s\n",pacientes[numeroPacientes].especialidade);


}


void perfilPaciente(paciente pacientes[numeroPacientes]){
	printf("Insira o nome\n");
	scanf("%s", pacientes[numeroPacientes].nome);
	printf("Insira a idade do paciente\n");
	scanf("%d",&pacientes[numeroPacientes].idade);
	printf("Insira o sexo do paciente\n");
	scanf(" %c", &pacientes[numeroPacientes].sexo);
	printf("Insira a data da primeira Consulta do paciente\n");
	scanf("%d",&pacientes[numeroPacientes].primeiraConsulta);
	printf("Insira a data da ultima Consulta do paciente\n");
	scanf("%d",&pacientes[numeroPacientes].ultimaConsulta);
	printf("Insira a data da proxima Consulta do paciente\n");
	scanf("%d",&pacientes[numeroPacientes].proximaConsulta);
	printf("Insira o nome do médico responsável pelo paciente\n");
	scanf("%s",pacientes[numeroPacientes].nomeMedico);
	printf("Insira o estado Clinico do paciente\n");
	scanf("%s",pacientes[numeroPacientes].situacaoClinica);
	printf("Insira a ala onde o paciente foi tratado\n");
	scanf("%s",pacientes[numeroPacientes].especialidade);

	return ;
}





/*@@@@ FUNCAO MAIN                              @@@@*/
int main(void) {

    setlocale(LC_ALL, "Portuguese");
    system("COLOR FC");

    // DECLARACAO DE VARIAVEIS E DE CONSTANTES
	int menu,numPaciente,menu1;
	paciente pacientes[20];

	FILE *doentes,*medicos,*consultas;





	// SEQUENCIA LOGICA DE INSTRUCOES

	verificaFicheiros(doentes,medicos,consultas);
	numeroPacientes=registados("pacientes.txt");



	do{
	printf("Login\n");
	printf("1-Admin\n");
	printf("2-Médico\n");
	printf("0-Sair\n");


	do{

	scanf("%d",&menu);
	if(menu!=1 && menu!=2 && menu!=0){
		printf("Opção inválida");
	}
}while(menu!=1 && menu!=2 && menu!=0);
	switch(menu){
		case 1:
			//criaFichaMedico();
		break;
		case 2:
			printf("1-Insere novo paciente\n");
			printf("2-Insere nova consulta para certo paciente\n");
			scanf("%d", &menu1);
			if(menu1==1){

					perfilPaciente(&pacientes[numeroPacientes]);
			}
		    else if(menu==2){

					printf("Insere id de Paciente");
					scanf("%d",&numPaciente);
					setProximaConsulta(pacientes,numPaciente);
			}

		break;

		case 0:
			break;

	}
}while(menu!=0);

	print(pacientes,0);





    printf("\n");



		printf("\n\n");
		printf("\n\n");


 return 0;
}
/*--------------------------------------------------*/
