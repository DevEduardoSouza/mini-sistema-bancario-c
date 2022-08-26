#include <stdio.h>
#include <stdlib.h>

int tam = 5;
float criarConta(float mat[5][2], int contas);
void acessarConta(float mat[5][2]);
float depositar(float mat[5][2], float *codigoV);
float saque(float mat[5][2], float *codigoV);
void verificador(float mat[5][2], float *codigoV);
void consultarSaldo(float mat[5][2], float *codigoV);
void transferir(float mat[5][2], float *codigoV);

int main()
{
    int op, contas = -1;
    float mat[5][2] = {0}, id;
    

    printf("\t-------------Bem vindo ao nosso banco-------------\n");
    do
    {
        printf("\nMENU INICIAL\n\n");
        printf("1 - Criar conta\n2 - Acessar conta\n3 - sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            contas++;
            criarConta(mat, contas);
            break;
        case 2:
            acessarConta(mat);
            break;
        case 3:
            printf("\nSaindo.......");
            break;

        default:
            printf("\nOpcao invalida\n\n");
            break;
        }
    } while (op !=3);

    return 0;
}

float criarConta(float mat[5][2],int contas){

    float valor, id;

    printf("\nCrie um id para acessar sua conta: ");
    scanf("%f", &id);
    printf("\nInforme a quantidade que ira depositar: ");
    scanf("%f", &valor);

    for (contas; contas < tam; contas++)
    {
        if (mat[contas][0] == 0)
        {
            mat[contas][0] = id;
            mat[contas][1] = valor;
            printf("\nID: %.0f\nSaldo: %.2f\n", mat[contas][0] , mat[contas][1]);
        }
        break;
    }
}

void acessarConta(float mat[5][2]){

    int op;
    float *codigoV;
    do
    {
        printf("\nMenu Intermediario\n\n");
        printf("1 - Depositar\n2 - saque\n3 - Transferencia\n4 - Consultar saldo\n5 - retorna ao menu inicail\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            verificador(mat, &codigoV);
            depositar(mat, &codigoV);
            break;
        case 2:
            verificador(mat, &codigoV);
            saque(mat, &codigoV);
            break;
        case 3:
            verificador(mat, &codigoV);
            transferir(mat, &codigoV);
            break;
        case 4:
            verificador(mat, &codigoV);
             consultarSaldo( mat, &codigoV);
            break; 
        case 5:
            printf("\nRetornando ao menu principal.......\n");
            break;
        
        default:
            printf("\nOpcao invalida\n\n");
            break;
        }
    } while (op != 5);
}

float depositar(float mat[5][2], float *codigoV){

    float valorD = 0; 
    printf("\t\n-------Depositar-------\n");
    printf("Informe o valor a ser depositado: ");
    scanf("%f", &valorD);

    for (int i = 0; i < tam; i++)
    {   
        if (*codigoV == mat[i][0])
        {
            mat[i][1] = mat[i][1] + valorD;
        }
    }
}

float saque(float mat[5][2], float *codigoV){

    float valorD; 
    printf("\t\n-------Saque-------\n");
    printf("\nInforme valor de saque: ");
    scanf("%f", &valorD);

    for (int i = 0; i < tam; i++)
    {   
             if (*codigoV == mat[i][0])
            {
                if (valorD > mat[i][1])
                {
                    printf("\nSaldo insuficiente\n");
                }else{
                    mat[i][1] = mat[i][1] - valorD;
                }
            }
    }
}

void verificador(float mat[5][2], float *codigoV){ 

    int verificador;
    do
    {
        verificador = 0;
        printf("Informe seu codigo: ");
        scanf("%f", codigoV);
        for (int i = 0; i < tam; i++)
        {   if (*codigoV == mat[i][0])
            {
                printf("Login com sucesso\n");
            }else{
                verificador++;
            }
        }  
    } while (verificador == tam);
}

void consultarSaldo(float mat[5][2], float *codigoV){
    printf("\t\n-------Saldo-------\n");
    for (int i = 0; i < tam; i++)
    {   
        if (*codigoV == mat[i][0])
        {
             printf("\nSeu saldo eh: %.2f", mat[i][1]); 
        }
    }
}

void transferir(float mat[5][2], float *codigoV){
    
    float codigoE, valorE,  verificador, copia_valor = 0;
    int copia_i = 0;

    

    for (int i = 0; i < tam; i++)
    {
         if (*codigoV == mat[i][0])
        {
            printf("\nConta: %.0f\nSaldo: %.2f\n", mat[i][0], mat[i][1]);
            copia_i = i;
            copia_valor = mat[i][1];
        }
    }

    do
    {
        printf("\nInforme o valor a ser enviado: ");
        scanf("%f", &valorE);

        if (valorE > copia_valor)
        {
            printf("\nSaldo insuficiente");
        }
        
    } while (valorE > copia_valor);


    do
    {
        verificador = 0;
        printf("\nInfrome o codigo da conta para quem ire enviar: ");
        scanf("%f", &codigoE);

        for (int i = 0; i < tam; i++)
        {
            if (codigoE == mat[i][0])
            {
                printf("\nSaldo enviado com sucesso");
                mat[i][1] = mat[i][1] + valorE;
                mat[copia_i][1] = mat[copia_i][1] - valorE;
            }else{
                verificador++;
            }
        }

    } while (verificador == tam);
}