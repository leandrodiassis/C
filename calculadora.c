/* 
*
* Calculadora Simples para Estudo da Linguagem de Programacao C
* Leandro de Assis
* Estudante de Eletroeletronica / SENAI
* leandroding@yahoo.com
* 
*/

#include <stdio.h>
#include <stdlib.h>

int operacoes();
int decisao(int);
int adicao();
int subtracao();
int multiplicacao();
int divisao();
int chamarFinal();
int escolhaInvalida();

int main(void){ // instrucoes para o usuario
	

		
	printf("\n\n\t\t\t\t\t\t**** Calculadora do Leandro ****\n");
	printf("\n\t>>>INSTRUCOES: \n");
	printf("\t\t- Escolha a operacao desejada usando os sinais (+,-,x,/).\n");
	printf("\t\t- Aperte enter sempre depois de inserir um valor,\n\t\t  o simbolo da operacao sera adicionado automaticamente apos apertar enter.\n");
		
	operacoes();
	
}

int operacoes(){ // escolha da operacao matematica
	
	int escolhaUsuario;
	
	printf("\n >>>Escolha a operacao:\n\n");
	printf("\t+ - Adicao\n");
	printf("\t- - Subtracao\n");
	printf("\tx - Multiplicacao\n");
	printf("\t/ - Divisao\n");
	
	escolhaUsuario = getch();
	
	decisao(escolhaUsuario);
}
int decisao(int escolha){ //decisao para qual operacao lancar
	
	switch (escolha){
		case '+':
			adicao();
		case '-':
			subtracao();
		case 'x':
			multiplicacao();
		case 'X':
			multiplicacao();
		case '/':
			divisao();
		default:
			escolhaInvalida();
	}
}
int adicao(){ // funcao para operacao de adicao
	
	float entradaValor1, entradaValor2, resultado;
	
	printf(">>> Insira os valores: \n");
	scanf("%f",&entradaValor1);
	printf("\n%.2f + ",entradaValor1);
	scanf("%f",&entradaValor2);
	
	resultado = entradaValor1 + entradaValor2;
	
	printf(">>> Resultado: %.2f + %.2f = %.2f\n", entradaValor1,entradaValor2,resultado);
	
	chamarFinal();
}

int subtracao(){ // funcao para operacao de subtracao
	
	float entradaValor1, entradaValor2, resultado;
	
	printf(">>> Insira os valores: \n");
	scanf("%f",&entradaValor1);
	printf("\n%.2f - ",entradaValor1);
	scanf("%f",&entradaValor2);
	
	resultado = entradaValor1 - entradaValor2;
	
	printf(">>> Resultado: %.2f - %.2f = %.2f\n", entradaValor1,entradaValor2,resultado);
	
	chamarFinal();
}

int multiplicacao(){ // funcao para operacao de multiplicacao
	
	float entradaValor1, entradaValor2, resultado;
	
	printf(">>> Insira os valores: \n");
	scanf("%f",&entradaValor1);
	printf("\n%.2f x ",entradaValor1);
	scanf("%f",&entradaValor2);
	
	resultado = entradaValor1 * entradaValor2;
	
	printf(">>> Resultado: %.2f x %.2f = %.2f\n", entradaValor1,entradaValor2,resultado);
	
	chamarFinal();
}

int divisao(){ // funcao para operacao de divisao
	
	float entradaValor1, entradaValor2, resultado;
	
	printf(">>> Insira os valores: \n");
	scanf("%f",&entradaValor1);
	
	printf("\n%.2f / ",entradaValor1);
	scanf("%f",&entradaValor2);
	
	resultado = entradaValor1 / entradaValor2;
	
	printf(">>> Resultado: %.2f / %.2f = %.2f\n", entradaValor1,entradaValor2,resultado);
	
	chamarFinal();
}
int escolhaInvalida(){ // alerta o usuario que a entrada foi invalida
	
	printf("\n>>> Opcao Invalida, escolha entre os operadores listados.\n");
	operacoes();
}
int chamarFinal(){ // decidir entre reiniciar ou terminar o programa
	char decisao;
	
	printf("\n>>> Deseja realizar outra operacao?\n");
	printf("(s / n)\n");
	
	decisao = getch();
	
	if(decisao == 's' || decisao == 'S') {
		system("cls");
		operacoes();
	}
	if(decisao == 'n' || decisao == 'N'){
		printf("\n>>> Finalizando o programa ...");
		
	exit(0);
	}
	
}
