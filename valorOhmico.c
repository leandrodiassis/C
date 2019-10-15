/* 
*
* Calculadora de Valor Ohmico de Resistores
* Leandro de Assis
* Estudante de Eletroeletronica / SENAI
* leandroding@yahoo.com
* 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
int escolhaResistor();
int resistor4Cores();
int resistor5Cores();

int main(){
			
	printf("\n\t\t\t\t\t\t **** Calculadora para Resistores **** \n");
	escolhaResistor();	

}

int escolhaResistor(){ // decisao para qual dos dois tipos de resistores possui o usuario
	
	int tipoResistor;
	
	printf("\n>>> Qual e o tipo do seu resistor?\n");
	printf("     __________________ \t     _____________________  \n");
	printf("    / || || ||   ||    \\ \t    / || || || ||   ||    \\\n");
	printf("====  || || ||   ||     ==== \t====  || || || ||   ||     ====\n");
	printf("    \\_||_||_||___||____/ \t    \\_||_||_||_||___||____/ \n");
	printf("\n\t 1) 4 Faixas \t\t\t 2) 5 Faixas\n");
	
    tipoResistor = getch();
	
	if(tipoResistor == 49){
		resistor4Cores();
	} 
	else if(tipoResistor == 50){
		resistor5Cores();
	}
	else{
		system("cls");
		printf("\n>>>Entrada Invalida! Escolha entre os dois tipos de resistores\n");
		escolhaResistor();
		
	}
}

// operacao para o resistor de 4 cores

int resistor4Cores(){ 
	system("cls");
	// preto = 0, marrom = 1, vermelho = 2, laranja = 3, amarelo = 4, 
	//	verde = 5 , azul = 6 , violeta = 7, cinza = 8 , branco = 9, ouro, prata;
	
	char *coresResistor[12] = {"preto", "marrom", "vermelho", "laranja", "amarelo", "verde","azul", "violeta", "cinza", "branco", "ouro", "prata"};
	float valorDigito[4];
	int i;
	int entrada;
	float resultado;
	char decisaoUsuario;
	float tolerancia;
	
	inicioResistor: // informativo de cores
	printf("\n>>> Informe as cores de acordo com as faixas solicitadas. \n");
	printf("\n\t1 - preto \t6 - verde  \n\t2 - marrom \t7 - azul \n\t3 - vermelho \t8 - violeta  \n\t4 - laranja \t9 - cinza \n\t5 - amarelo \t10 - branco ");
	printf("\n\n\t11 - ouro \n\t12 - prata\n");
	printf("\n>>> Informe a cor da:\n");
	
	for(i=0; i<=3; i++){ // entre a cor escolhida
		
		printf("\n>>> %da Faixa: \n",i+1);
		scanf("%d",&entrada);
		
		// limitando as cores para cada digito
		
		if(entrada > 12){ //caso a cor escolhida for maior que o numero de cores disponiveis
			system("cls");
			printf("\n !!! Valor informado nao consta. Inicie novamente.\n");
			goto inicioResistor;
			
		}
		if(i < 2 ){ // limitando as cores prata e ouro apenas para multiplicadores e tolerancia
			if(entrada == 12 || entrada == 11){
				system("cls");
				printf("\n\t !!! A cor %s e apenas para a faixa de multiplicacao e tolerancia !!!\n", coresResistor[entrada-1]);
				goto inicioResistor;
			}
		}
		if(i == 2 ){ // branco e cinza nao podem ser multiplicadores
			if(entrada == 10 || entrada == 9){
				system("cls");
				printf("\n\t !!! A cor %s e apenas para a faixa de tolerancia !!!\n", coresResistor[entrada-1]);
				goto inicioResistor;
			}
		}
		if(i == 3 ){ // preto, branco, laranja e amarelo nao pode ser tolerancia
			if(entrada == 10 || entrada == 4 || entrada ==5 || entrada == 1){
				system("cls");
				printf("\n\t !!! A cor %s nao e uma faixa de tolerancia !!!\n", coresResistor[entrada-1]);
				goto inicioResistor;
			}	
							
		}
	
					
		// Atribuir valor ao digito		
		valorDigito[i] = entrada-1;	
		printf("\tVoce inseriu a cor %s \n", coresResistor[entrada-1]);
		
		//definindo valor do multiplicador
		
		if(i == 2){ // quando o digito for multiplicador
	
			if(valorDigito[2] == 0){ // se o multiplicador for preto
				valorDigito[2] = 1;
			}
			else if(valorDigito[2] == 1){ // se o multiplicador for marrom
				valorDigito[2] = 10;
			}
			else if(valorDigito[2] == 2){ // se o multiplicador for vermelho
				valorDigito[2] = 100;
			}
			else if(valorDigito[2] == 3){ // se o multiplicador for laranja
				valorDigito[2] = 1000;
			}
			else if(valorDigito[2] == 4){ // se o multiplicador for amarelo
				valorDigito[2] = 10000;
			}
			else if(valorDigito[2] == 5){ // se o multiplicador for verde
				valorDigito[2] = 100000;
			}
			else if(valorDigito[2] == 6){ // se o multiplicador for azul
				valorDigito[2] = 1000000;
			}
			else if(valorDigito[2] == 7){ // se o multiplicador for violeta
				valorDigito[2] = 10000000;
			}
			else if(valorDigito[2] == 8){ // se o multiplicador for cinza
				valorDigito[2] = 100000000;
			}		
		}
			
	}
				


	
	// formar uma dezena com as duas primeiras unidades do resistor
	resultado = valorDigito[0] * 10;
	resultado = resultado + valorDigito[1];
	resultado = resultado * valorDigito[2];
	
	//transformando os valores para exibir a faixa de tolerancia

   if(entrada == 2){ // marrom
	tolerancia = resultado*(0,01);
	}
	else if(entrada == 3){ //vermelho
		tolerancia = resultado*(0.02);
	}
	else if(entrada == 6){ //verde
		tolerancia = resultado*(0.05);
	}
	else if(entrada == 7){ // azul
		tolerancia = resultado*(0.0025);
	}
	else if(entrada == 8){ //violeta
		tolerancia = resultado*(0.01);
	}
	else if(entrada == 9){//cinza
		tolerancia = resultado*(0.0005);
	}
	else if(entrada == 11){ //ouro
		tolerancia = resultado*(0.05);
	}
	else if(entrada == 12){//prata
		tolerancia = resultado*(0.1);
	}
		 
	printf("\n\n>>> O valor Ohmico do resistor informado e de: %.0f Ohms.\n",resultado);
	printf("\n>>> A tolerancia e de %.0f Ohms para mais ou para menos.\n",tolerancia);

	loopDecisao:
	printf("\n\t\tDeseja realizar mais uma operacao? (s\\n)\n");
	decisaoUsuario = getch();
	
	switch(decisaoUsuario){
		case 's':
			system("cls");
			escolhaResistor();
		case 'S':
			system("cls");
			escolhaResistor();
		case 'N':
			exit(0);
		case 'n':
			exit(0);
		default:
			printf("\n >>> Opcao Invalida <<<\n");
			goto loopDecisao;
			
	}
	
}


// operacao para o resistor de 5 cores

int resistor5Cores(){	
	system("cls");
	// preto = 0, marrom = 1, vermelho = 2, laranja = 3, amarelo = 4, 
	//	verde = 5 , azul = 6 , violeta = 7, cinza = 8 , branco = 9, ouro, prata;
	
	char *coresResistor[12] = {"preto", "marrom", "vermelho", "laranja", "amarelo", "verde","azul", "violeta", "cinza", "branco", "ouro", "prata"};
	float valorDigito[4];
	int i;
	int entrada;
	float resultado;
	char decisaoUsuario;
	float tolerancia;
	
	inicioResistor: // informativo de cores
	printf("\n>>> Informe as cores de acordo com as faixas solicitadas. \n");
	printf("\n\t1 - preto \t6 - verde  \n\t2 - marrom \t7 - azul \n\t3 - vermelho \t8 - violeta  \n\t4 - laranja \t9 - cinza \n\t5 - amarelo \t10 - branco ");
	printf("\n\n\t11 - ouro \n\t12 - prata\n");
	printf("\n>>> Informe a cor do:\n");
	
	for(i=0; i<=4; i++){ // entre a cor escolhida
		
		printf("\n>>> %da Faixa: \n",i+1);
		scanf("%d",&entrada);
		
		// limitando as cores para cada digito
		
		if(entrada > 12){ //caso a cor escolhida for maior que o numero de cores disponiveis
			system("cls");
			printf("\n !!! Valor informado nao consta. Inicie novamente.\n");
			goto inicioResistor;
			
		}
		if(i < 3){ // limitando as cores prata e ouro apenas para multiplicadores e tolerancia
			if(entrada == 12 || entrada == 11){
				system("cls");
				printf("\n\t !!! A cor %s e apenas para a faixa de multiplicacao e tolerancia !!!\n", coresResistor[entrada-1]);
				goto inicioResistor;
			}
		}
		if(i == 3 ){ // branco e cinza nao podem ser multiplicadores
			if(entrada == 10 || entrada == 9){
				system("cls");
				printf("\n\t !!! A cor %s e apenas para a faixa de tolerancia !!!\n", coresResistor[entrada-1]);
				goto inicioResistor;
			}
		}
		if(i == 4 ){ // preto, branco, laranja e amarelo nao pode ser tolerancia
			if(entrada == 10 || entrada == 4 || entrada ==5 || entrada == 1){
				system("cls");
				printf("\n\t !!! A cor %s nao e uma faixa de tolerancia !!!\n", coresResistor[entrada-1]);
				goto inicioResistor;
			}	
							
		}
	
					
		// Atribuir valor ao digito		
		valorDigito[i] = entrada-1;	
		printf("\tVoce inseriu a cor %s \n", coresResistor[entrada-1]);
		
		//definindo valor do multiplicador
		
		if(i == 3){ // quando o digito for multiplicador
	
			if(valorDigito[3] == 0){ // se o multiplicador for preto
				valorDigito[3] = 1;
			}
			else if(valorDigito[3] == 1){ // se o multiplicador for marrom
				valorDigito[3] = 10;
			}
			else if(valorDigito[3] == 2){ // se o multiplicador for vermelho
				valorDigito[3] = 100;
			}
			else if(valorDigito[3] == 3){ // se o multiplicador for laranja
				valorDigito[3] = 1000;
			}
			else if(valorDigito[3] == 4){ // se o multiplicador for amarelo
				valorDigito[3] = 10000;
			}
			else if(valorDigito[3] == 5){ // se o multiplicador for verde
				valorDigito[3] = 100000;
			}
			else if(valorDigito[3] == 6){ // se o multiplicador for azul
				valorDigito[3] = 1000000;
			}
			else if(valorDigito[3] == 7){ // se o multiplicador for violeta
				valorDigito[3] = 10000000;
			}
			else if(valorDigito[3] == 8){ // se o multiplicador for cinza
				valorDigito[3] = 100000000;
			}		
		}
			
	}
				
	// formar uma dezena ou centena com as treis primeiras faixas do resistor
	resultado = valorDigito[0] * 100;	
	resultado = resultado + (valorDigito[1]*10);
	resultado = resultado + valorDigito[2];	
	resultado = resultado * valorDigito[3];
	
	//transformando os valores para exibir a faixa de tolerancia

   if(entrada == 2){ // marrom
	tolerancia = resultado*(0,01);
	}
	else if(entrada == 3){ //vermelho
		tolerancia = resultado*(0.02);
	}
	else if(entrada == 6){ //verde
		tolerancia = resultado*(0.05);
	}
	else if(entrada == 7){ // azul
		tolerancia = resultado*(0.0025);
	}
	else if(entrada == 8){ //violeta
		tolerancia = resultado*(0.01);
	}
	else if(entrada == 9){//cinza
		tolerancia = resultado*(0.0005);
	}
	else if(entrada == 11){ //ouro
		tolerancia = resultado*(0.05);
	}
	else if(entrada == 12){//prata
		tolerancia = resultado*(0.1);
	}
		 
	printf("\n\n>>> O valor Ohmico do resistor informado e de: %.0f Ohms.\n",resultado);
	printf("\n>>> A tolerancia e de %.0f Ohms para mais ou para menos.\n",tolerancia);

	loopDecisao:
	printf("\n\t\tDeseja realizar mais uma operacao? (s\\n)\n");
	decisaoUsuario = getch();
	
	switch(decisaoUsuario){
		case 's':
			system("cls");
			escolhaResistor();
		case 'S':
			system("cls");
			escolhaResistor();
		case 'N':
			exit(0);
		case 'n':
			exit(0);
		default:
			printf("\n >>> Opcao Invalida <<<\n");
			goto loopDecisao;

}
}
