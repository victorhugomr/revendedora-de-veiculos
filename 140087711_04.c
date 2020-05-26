/*Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Computacao Basica  1/2015
Aluno(a): Victor Hugo Magalhaes Rodrigues
Matricula: 140087711
Turma: C
Versão do compilador: Code::Blocks 13.12
Descricao: Revendedora de Veiculos*/

#ifdef _WIN64
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoDadosVeiculo{
	int cod;
	char carro[15];
	char marca[15];
	int anofab;
	int anomod;
	char cor[15];
	int km;
	char ar;
	char dh;
	float preco;
	char data[9];
}TipoDadosVeiculo;

void Opcao1(char arquivobin[50]){
char resp;
FILE *fp;
TipoDadosVeiculo veiculo;

	fp = fopen(arquivobin, "wb");

	do{
		system(CLEAR);
		do{
			printf("Informe o codigo do veiculo: ");
			scanf("%d", &veiculo.cod);
		}while(veiculo.cod<=0);
		printf("Informe o nome do veiculo: ");
		scanf("%s", veiculo.carro);
		printf("Informe a marca do veiculo: ");
		scanf("%s", veiculo.marca);
		do{
			printf("Informe o ano de fabricacao do veiculo: ");
			scanf("%d", &veiculo.anofab);
		}while(veiculo.anofab<=0);
		do{
			printf("Informe o ano do modelo do veiculo: ");
			scanf("%d", &veiculo.anomod);
		}while(veiculo.anomod<=0);
		printf("Informe a cor do veiculo: ");
		scanf("%s", veiculo.cor);
		do{
			printf("Informe a quilometragem do veiculo: ");
			scanf("%d", &veiculo.km);
		}while(veiculo.km<0);
		do{
			printf("Informe se o veiculo possui ar condicionado: ");
			getchar();
			scanf("%c", &veiculo.ar);
		}while((veiculo.ar!='N') && (veiculo.ar!='n') && (veiculo.ar!='S') && (veiculo.ar!='s'));
		do{
			printf("Informe se o veiculo possui direcao hidraulica: ");
			getchar();
			scanf("%c", &veiculo.dh);
		}while((veiculo.dh!='N') && (veiculo.dh!='n') && (veiculo.dh!='S') && (veiculo.dh!='s'));
		do{
			printf("Informe o preco do veiculo: ");
			scanf("%f", &veiculo.preco);
		}while(veiculo.preco<=0);
		printf("Informe a data de entrada do veiculo: ");
		scanf("%s", veiculo.data);
		fwrite(&veiculo, sizeof(struct TipoDadosVeiculo),1,fp);
		do{
			printf("Deseja incluir um novo veiculo(S/N)?\n");
			getchar();
			scanf("%c", &resp);
		}while((resp!='N') && (resp!='n') && (resp!='S') && (resp!='s'));
	}while((resp=='S') || (resp=='s'));
	fclose(fp);
}

void Opcao2(char arquivobin[50]){
char resp;
FILE *fp;
TipoDadosVeiculo veiculo;

	fp = fopen(arquivobin, "ab");

	if(fp==NULL){
		printf("O cadastro atual nao possui dados");
		Opcao1(arquivobin);
	}
	else{
		do{
			system(CLEAR);
			do{
				printf("Informe o codigo do veiculo: ");
				scanf("%d", &veiculo.cod);
			}while(veiculo.cod<=0);
			printf("Informe o nome do veiculo: ");
			scanf("%s", veiculo.carro);
			printf("Informe a marca do veiculo: ");
			scanf("%s", veiculo.marca);
			do{
				printf("Informe o ano de fabricacao do veiculo: ");
				scanf("%d", &veiculo.anofab);
			}while(veiculo.anofab<=0);
			do{
				printf("Informe o ano do modelo do veiculo: ");
				scanf("%d", &veiculo.anomod);
			}while(veiculo.anomod<=0);
			printf("Informe a cor do veiculo: ");
			scanf("%s", veiculo.cor);
			do{
				printf("Informe a quilometragem do veiculo: ");
				scanf("%d", &veiculo.km);
			}while(veiculo.km<0);
			do{
				printf("Informe se o veiculo possui ar condicionado: ");
				getchar();
				scanf("%c", &veiculo.ar);
			}while((veiculo.ar!='N') && (veiculo.ar!='n') && (veiculo.ar!='S') && (veiculo.ar!='s'));
			do{
				printf("Informe se o veiculo possui direcao hidraulica: ");
				getchar();
				scanf("%c", &veiculo.dh);
			}while((veiculo.dh!='N') && (veiculo.dh!='n') && (veiculo.dh!='S') && (veiculo.dh!='s'));
			do{
				printf("Informe o preco do veiculo: ");
				scanf("%f", &veiculo.preco);
			}while(veiculo.preco<=0);
			printf("Informe a data de entrada do veiculo: ");
			scanf("%s", veiculo.data);
			fwrite(&veiculo, sizeof(struct TipoDadosVeiculo),1,fp);
			do{
				printf("Deseja incluir um novo veiculo(S/N)?\n");
				getchar();
				scanf("%c", &resp);
			}while((resp!='N') && (resp!='n') && (resp!='S') && (resp!='s'));
		}while((resp=='S') || (resp=='s'));
	}
	fclose(fp);
}

void Opcao3(char arquivobin[50]){
int busca;
char resp;
FILE *fp;
TipoDadosVeiculo veiculo;

	fp = fopen(arquivobin, "rb");

	if(fp==NULL){
		printf("O cadastro atual nao possui dados");
		getchar();
	}
	else{
		do{
			system(CLEAR);
			printf("Informe o codigo do veiculo: ");
			scanf("%d", &busca);
			do{
				fread(&veiculo,sizeof(TipoDadosVeiculo),1,fp);
			}while((veiculo.cod!=busca) && (fread(&veiculo,sizeof(TipoDadosVeiculo),1,fp)!=0));
			if(veiculo.cod==busca){
				printf("CODIGO: %d\n", veiculo.cod);
				printf("NOME: %s\n", veiculo.carro);
				printf("MARCA: %s\n", veiculo.marca);
				printf("ANO DE FABRICACAO: %d\n", veiculo.anofab);
				printf("ANO DO MODELO: %d\n", veiculo.anomod);
				printf("COR: %s\n", veiculo.cor);
				printf("QUILOMETRAGEM: %d\n", veiculo.km);
				printf("AR-CONDICIONADO:%c\n", veiculo.ar);
				printf("DIRECAO HIDRAULICA:%c\n", veiculo.dh);
				printf("PRECO: %.2f\n", veiculo.preco);
				printf("DATA DE ENTRADA: %s\n\n", veiculo.data);
			}
			else{
				printf("O veiculo nao existe no cadastro\n");
			}
			do{
				printf("Deseja buscar um novo veiculo(S/N)?\n");
				getchar();
				scanf("%c", &resp);
			}while((resp!='N') && (resp!='n') && (resp!='S') && (resp!='s'));
		}while((resp=='S') || (resp=='s'));
	}
}

void Opcao4(char arquivobin[50], char arquivotxt[50]){
int num=0;
int flag, i;
FILE *fp1;
FILE *fp2;
TipoDadosVeiculo veiculo;

    fp1 = fopen(arquivobin, "rb");
    if(fp1==NULL){
        printf("Arquivo binario nao encontrado!");
    }
    else{
        while(fread(&veiculo,sizeof(TipoDadosVeiculo),1,fp1)!=0){
            fread(&veiculo,sizeof(TipoDadosVeiculo),1,fp1);
            if(veiculo.km==0){
                num+=1;
            }
        }
        fclose(fp1);

TipoDadosVeiculo aux, vetor[num];

        fp1 = fopen(arquivobin, "rb");
        fp2 = fopen(arquivotxt, "w");

        num=0;
        fprintf(fp2,"*** LISTAGEM DE VEICULOS 0 KM ***\n");
        fprintf(fp2,"ANO\tCODIGO\tCARRO\tPRECO\n");
        while(fread(&veiculo,sizeof(TipoDadosVeiculo),1,fp1)!=0){
            fread(&veiculo,sizeof(TipoDadosVeiculo),1,fp1);
            if(veiculo.km==0){
                vetor[num]=veiculo;
                num+=1;
            }
        }
        fclose(fp1);
        do{
            flag=0;
            for(i=0;i<num-1;i++){
                if(vetor[i].anomod>vetor[i+1].anomod){
                    aux=vetor[i];
                    vetor[i]=vetor[i+1];
                    vetor[i+1]=aux;
                    flag=1;
                }
            }
        }while(flag);
        for(i=0;i<num;i++){
            fprintf(fp2,"%d\t%d\t%s\t%.2f\n",vetor[i].anomod,vetor[i].cod,vetor[i].carro,vetor[i].preco);
        }
        fclose(fp2);
        printf("Arquivo texto gerado com sucesso!\nTecle <enter> para continuar...");
        getchar();
        getchar();
    }
}


int main(){
int operacao;
char arquivobin[50] = "VEICULOS.bin";
char arquivotxt[50] = "VEICULOS_NOVOS.txt";

	do{
		do{
			system(CLEAR);
			printf("MENU PRINCIPAL\n\n1. CRIAR E INICIAR CADASTRO NOVO\n2. INCLUIR DADOS NO CADASTRO EXISTENTE\n3. CONSULTAR O CADASTRO POR CODIGO DE VEICULO\n4. GERAR ARQUIVO TXT DOS VEICULOS 0KM\n5. SAIR\n\n");
			scanf("%d", &operacao);
		}while((operacao<1) || (operacao>5));
		switch(operacao){
			case 1:
				Opcao1(arquivobin);
				break;
			case 2:
				Opcao2(arquivobin);
				break;
			case 3:
				Opcao3(arquivobin);
				break;
			case 4:
				Opcao4(arquivobin,arquivotxt);
				break;
			case 5:
				break;
		}
	}while(operacao!=5);
	getchar();

return 0;
}
