/*
-> UNIVERSIDADE CATÓLICA DE PERNAMBUCO - UNICAP
-> DISCIPLINA: ESTRUTURA DE DADOS 1
-> ALUNO: DANILO ALVES DA SILVA
-> PROJETO: AGENDA TELEFONICA
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

typedef struct contato {
	char nome[100];
	char fone[15];
	struct contato *ant, *prox;
}Tcontato;

typedef struct indice {
	char letra;
	struct indice *ant, *prox;
	Tcontato *inicio;
}Tindice;

void listar(Tindice *l);
Tindice *buscaIndice(Tindice *l, char letra);
Tcontato *criarContato(char nome[]);
void criarIndice(Tindice**l, char nome[]);
void cadastrar(Tindice**l, char nome[]);
void removerContato(Tindice**l, char nome[]);
void removerIndice(Tindice**l, Tindice *pos);
void exibir(Tindice *l, char nome[]);
void alterarTelefone(Tindice *l, char nome[]);
void listar(Tindice *l);
void listarPorLetra(Tindice *l, char letra);
void apagarAgenda(Tindice**l);


int main() {
	int escolha, opc;
	char nome[100], letra;
	Tindice *agenda = NULL;

	setlocale(LC_ALL, ""); //altera o idioma, de inglês para o idioma do sistema
	do {
		printf("|------------AGENDA-----------|\n");
		printf("|                             |\n");
		printf("|1 - ADICIONAR UM CONTATO     |\n");
		printf("|-----------------------------|\n");
		printf("|2 - LISTAR TODOS OS CONTATOS |\n");
		printf("|-----------------------------|\n");
		printf("|3 - LISTAR TODOS POR INDICE  |\n");
		printf("|-----------------------------|\n");
		printf("|4 - PESQUISAR UM CONTATO     |\n");
		printf("|-----------------------------|\n");
		printf("|5 - ALTERAR TELEFONE         |\n");
		printf("|-----------------------------|\n");
		printf("|6 - REMOVER UM CONTATO       |\n");
		printf("|-----------------------------|\n");
		printf("|7 - APAGAR AGENDA            |\n");
		printf("|-----------------------------|\n");
		printf("|8 - SAIR                     |\n");
		printf("|.............................|\n");
		printf("-> ");
		scanf("%d", &opc);
		setbuf(stdin, NULL);
		switch (opc) {
		case 1:do {
			system("cls");
			printf("|------------ADICIONAR CONTATO-----------|\n\n");
			printf("NOME: ");
			setbuf(stdin, NULL);
			gets(nome);
			strupr(nome);
			setbuf(stdin, NULL);
			cadastrar(&agenda, nome);
			do {
				system("cls");
				printf("|------------ADICIONAR CONTATO-----------|\n\n");
				printf("Deseja adicionar outro contato ?\n");
				printf("|1 - SIM |\n");
				printf("|2 - NÃO |\n");
				printf("-> ");
				setbuf(stdin, NULL);
				scanf("%d", &escolha);
				setbuf(stdin, NULL);
			} while (escolha < 1 || escolha > 2);
			system("cls");
		} while (escolha == 1);
			break;
		case 2:system("cls");
			printf("|------------CONTATOS-----------|\n\n");
			listar(agenda);
			break;
		case 3:do {
			system("cls");
			printf("|------------LISTAR TODOS POR INDICE-----------|\n\n");
			printf("INFORME UM INDICE ENTRE A ATÉ Z: ");
			setbuf(stdin, NULL);
			letra = getchar();
			setbuf(stdin, NULL);
			toupper(letra);
			listarPorLetra(agenda, toupper(letra));
			do {
				system("cls");
				printf("|------------LISTAR TODOS POR INDICE-----------|\n\n");
				printf("Deseja listar ultizando outro indice ?\n");
				printf("|1 - SIM |\n");
				printf("|2 - NÃO |\n");
				printf("-> ");
				setbuf(stdin, NULL);
				scanf("%d", &escolha);
				setbuf(stdin, NULL);
			} while (escolha < 1 || escolha > 2);
			system("cls");
		} while (escolha == 1);
		break;
		case 4:do {
			system("cls");
			printf("|------------PESQUISAR UM CONTATO-----------|\n\n");
			printf("NOME: ");
			setbuf(stdin, NULL);
			gets(nome);
			strupr(nome);
			setbuf(stdin, NULL);
			exibir(agenda, nome);
			do {
				system("cls");
				printf("|------------PESQUISAR UM CONTATO-----------|\n\n");
				printf("Deseja pesquisar outro contato ?\n");
				printf("|1 - SIM |\n");
				printf("|2 - NÃO |\n");
				printf("-> ");
				setbuf(stdin, NULL);
				scanf("%d", &escolha);
				setbuf(stdin, NULL);
			} while (escolha < 1 || escolha > 2);
			system("cls");
		} while (escolha == 1);
		break;
		case 5:do {
			system("cls");
			printf("|------------ALTERAR TELEFONE-----------|\n\n");
			printf("NOME: ");
			setbuf(stdin, NULL);
			gets(nome);
			strupr(nome);
			setbuf(stdin, NULL);
			alterarTelefone(agenda, nome);
			do {
				system("cls");
				printf("|------------ALTERAR TELEFONE-----------|\n\n");
				printf("Deseja alterar o número de outro contato ?\n");
				printf("|1 - SIM |\n");
				printf("|2 - NÃO |\n");
				printf("-> ");
				setbuf(stdin, NULL);
				scanf("%d", &escolha);
				setbuf(stdin, NULL);
			} while (escolha < 1 || escolha > 2);
			system("cls");
		} while (escolha == 1);
		break;
		case 6:do {
			system("cls");
			printf("|------------REMOVER CONTATO-----------|\n\n");
			printf("NOME: ");
			setbuf(stdin, NULL);
			gets(nome);
			strupr(nome);
			setbuf(stdin, NULL);
			removerContato(&agenda, nome);
			do {
				system("cls");
				printf("|------------REMOVER CONTATO-----------|\n\n");
				printf("Deseja remover outro contato ?\n");
				printf("|1 - SIM |\n");
				printf("|2 - NÃO |\n");
				printf("-> ");
				setbuf(stdin, NULL);
				scanf("%d", &escolha);
				setbuf(stdin, NULL);
			} while (escolha < 1 || escolha > 2);
			system("pause");
			system("cls");
		} while (escolha == 1);
		  break;
		case 7: apagarAgenda(&agenda);
			system("pause");
			break;
		case 8:printf("SAINDO...");
			apagarAgenda(&agenda);//o método está sendo chamado aqui porque os dados estão apenas em memória, logo é necessário desalocar todas as variáveis heap
			break;
		default:system("cls");
			printf("*****OPÇÃO INVÁLIDA!*****\n\n\n");
			system("pause");
		}
		system("cls");
	} while (opc != 8);
	
	return 0;
}

Tindice *buscaIndice(Tindice *l, char letra) {
	Tindice *aux;

	if (l == NULL) {
		return NULL;
	}
	else {
		aux = l;
		do {
			if (aux->letra == letra) {
				return aux;
			}
			aux = aux->prox;
		} while (aux != l);
		
		return NULL;
	}

}

Tcontato *criarContato(char nome[]) {
	Tcontato *novo;

	novo = (Tcontato *)malloc(sizeof(Tcontato));
	strcpy(novo->nome, nome);
	printf("NÚMERO: ");
	setbuf(stdin, NULL);
	gets(novo->fone);
	return novo;
}

void criarIndice(Tindice**l, char nome[]) {
	char letra;
	Tindice *novoIndice, *aux = *l;


	novoIndice = (Tindice *)malloc(sizeof(Tindice));
	novoIndice->letra = nome[0];
	novoIndice->inicio = NULL;
	if (*l == NULL) { //se a agenda estiver vazia
		*l = novoIndice;
		novoIndice->ant = novoIndice;
		novoIndice->prox = novoIndice;
	}
	else if (aux->prox == aux) { // apenas 1 Nó
		if (novoIndice->letra < aux->letra) { //inserir indice no inicio se tiver apenas 1 nó
			novoIndice->prox = aux;
			novoIndice->ant = aux;
			aux->prox = novoIndice;
			aux->ant = novoIndice;
			*l = novoIndice;
		}
		else {//inserir indice no final se tiver apenas 1 nó
			aux->prox = novoIndice;
			novoIndice->ant = aux;
			novoIndice->prox = aux;
			aux->ant = novoIndice;
		}
	}
	else {
		while (aux->prox != *l && aux->letra < novoIndice->letra) {
			aux = aux->prox;
		}
		if (aux->prox == *l) { //inserir indice no final
			if (novoIndice->letra < aux->letra) {
				novoIndice->prox = aux;
				novoIndice->ant = aux->ant;
				aux->ant->prox = novoIndice;
				aux->ant = novoIndice;
			}
			else {
				aux->prox->ant = novoIndice;
				novoIndice->prox = aux->prox;
				aux->prox = novoIndice;
				novoIndice->ant = aux;
			}
		}
		else {
			novoIndice->prox = aux;
			novoIndice->ant = aux->ant;
			aux->ant->prox = novoIndice;
			aux->ant = novoIndice;
		}
	}
}

void cadastrar(Tindice**l, char nome[]) {
	char letra;
	Tindice *novoIndice, *auxIndice;
	Tcontato *novoContato, *auxContato;

	letra = nome[0];
	auxIndice = buscaIndice(*l, letra);
	if (auxIndice == NULL) {//Caso indice não exista***********************************************************
		criarIndice(&*l, nome);
		auxIndice = buscaIndice(*l, letra); 
	}
	if (auxIndice->inicio == NULL) { // se o indice estiver vazio.
		auxContato = NULL;
	}
	else {
		auxContato = auxIndice->inicio;
	}
	if (auxContato == NULL) { // se a lista secúndaria estiver vazia
		novoContato = criarContato(nome);
		auxIndice->inicio = novoContato;
		novoContato->ant = novoContato;
		novoContato->prox = novoContato;
	}
	else if (auxContato->prox == auxContato) {// lista secundária com apenas 1 nó
		if (strcmp(nome, auxContato->nome) == 0) {
			printf("Nome já cadastrado!\n");
			system("pause");
			return;
		}
		else if (strcmp(nome, auxContato->nome) < 0) { //inserir contato no inicio se a lista secundaria tiver apenas 1 nó
			novoContato = criarContato(nome);
			novoContato->prox = auxContato;
			novoContato->ant = auxContato;
			auxContato->prox = novoContato;
			auxContato->ant = novoContato;
			auxIndice->inicio = novoContato;
		}
		else {//inserir contato no final se a lista secundaria tiver apenas 1 nó
			novoContato = criarContato(nome);
			auxContato->prox = novoContato;
			novoContato->ant = auxContato;
			novoContato->prox = auxContato;
			auxContato->ant = novoContato;
		}
	}
	else {
		do {
			if (strcmp(nome, auxContato->nome) == 0) {
				printf("Nome já cadastrado!\n");
				system("pause");
				return;
			}
			auxContato = auxContato->prox;
		} while (auxContato != auxIndice->inicio && (strcmp(auxContato->nome, nome) < 0));
		if (strcmp(nome, auxContato->nome) == 0) {
			printf("Nome já cadastrado!\n");
			system("pause");
			return;
		}
		if (auxContato->prox == auxIndice->inicio) { // inserir no final da lista secundaria
			if (strcmp(nome, auxContato->nome) < 0) { // inserir antes do último
				novoContato = criarContato(nome);
				novoContato->prox = auxContato;
				novoContato->ant = auxContato->ant;
				auxContato->ant->prox = novoContato;
				auxContato->ant = novoContato;
			}
			else {//inserir depois do último
				novoContato = criarContato(nome);
				auxContato->prox->ant = novoContato;
				novoContato->prox = auxContato->prox;
				auxContato->prox = novoContato;
				novoContato->ant = auxContato;
			}
		}
		else {// inserir contato no meio da lista secundaria
			novoContato = criarContato(nome);
			novoContato->prox = auxContato;
			novoContato->ant = auxContato->ant;
			auxContato->ant->prox = novoContato;
			auxContato->ant = novoContato;
		}
	}
	printf("\n******CONTATO ADICIONADO COM SUCESSO!********\n\n");
	system("pause");
}

void listar(Tindice *l) {
	Tindice *auxIndice;
	Tcontato *auxContato;

	if (l == NULL) {
		printf("\nNão existe(m) contato(s) cadastrado(s)\n\n");
	}
	else {
		auxIndice = l;
		auxContato = auxIndice->inicio;
		do {
			    printf("|************** %c **************\n\n", toupper(auxIndice->letra));
			do {
				printf("|NOME: %s\n", (auxContato->nome));
				printf("|TELEFONE: %s\n", auxContato->fone);
				printf("|...............................\n");
				auxContato = auxContato->prox;
			} while (auxContato != auxIndice->inicio);
			auxIndice = auxIndice->prox;
			auxContato = auxIndice->inicio;
			printf("\n");
		} while (auxIndice != l);
		printf("|*******************************\n");
	}
	system("pause");
}

Tcontato *posicao(Tcontato *auxContato, char nome[]) {
	Tcontato *aux;

	if (auxContato == NULL) {
		return NULL;
	}
	else {
		aux = auxContato;
		do {
			if (strcmp(aux->nome, nome) == 0) {
				return aux;
			}
			aux = aux->prox;
		} while (aux != auxContato);
		return NULL;
	}
}

void removerContato(Tindice**l, char nome[]) {
	Tindice *auxIndice;
	Tcontato *auxContato, *pos;

	auxIndice = buscaIndice(*l, nome[0]);
	if (auxIndice == NULL) {
		printf("\n******CONTATO NÃO EXISTE!********\n\n");
		return;
	}
	else {
		auxContato = auxIndice->inicio;
		pos = posicao(auxContato, nome);//retorna a posição do contato
		if (pos == NULL) { //lista secundária vazia
			printf("\n******CONTATO NÃO EXISTE!********\n\n");
			return;
		}
		else if (pos->prox == pos) {//lista secundária com apenas 1 nó
			free(pos);
			removerIndice(&(*l), auxIndice);
		}
		else if (pos == auxIndice->inicio) { // remover o primeiro da lista secundária
			auxIndice->inicio = pos->prox;
			auxIndice->inicio->ant = pos->ant;
			pos->ant->prox = pos->prox;
			free(pos);
		}
		else if (pos->prox == auxIndice->inicio) {//remover no final da lista secundária
			pos->ant->prox = pos->prox;
			pos->prox->ant = pos->ant;
			free(pos);
		}
		else {//remover no meio
			pos->ant->prox = pos->prox;
			pos->prox->ant = pos->ant;
			free(pos);
		}

	}
	printf("\n******CONTATO REMOVIDO COM SUCESSO!********\n\n");
	system("pause");
}

void removerIndice(Tindice**l, Tindice *pos) {
	Tindice *auxIndice = *l;

     if (pos->prox == pos) {//Lista principal com apenas 1 no
		 free(pos);
		*l = NULL;
	}
	else if (pos == *l) { // remover o primeiro da lista principal
		auxIndice = pos->prox;
		auxIndice->ant = pos->ant;
		pos->ant->prox = pos->prox;
		*l = auxIndice;
		free(pos);
	}
	else if (pos->prox == auxIndice->inicio) {//remover no final da lista principal
		pos->ant->prox = pos->prox;
		pos->prox->ant = pos->ant;
		free(pos);
	}
	else {//remover no meio

		pos->ant->prox = pos->prox;
		pos->prox->ant = pos->ant;
		free(pos);
	}
}

void exibir(Tindice *l, char nome[]) {
	Tindice *auxIndice;
	Tcontato *auxContato;

	auxIndice = buscaIndice(l, nome[0]);
	if (auxIndice == NULL) {
		printf("******CONTATO NÃO EXISTE!********\n");
	}
	else {
		auxContato = auxIndice->inicio;
		auxContato = posicao(auxContato, nome);
		if (auxContato == NULL) {
			printf("******CONTATO NÃO EXISTE!********\n");
		}
		else {
			printf("TELEFONE: %s\n\n", auxContato->fone);
		}
	}
	system("pause");
}

void alterarTelefone(Tindice *l, char nome[]) {
	Tindice *auxIndice;
	Tcontato *auxContato;

	auxIndice = buscaIndice(l, nome[0]);
	if (auxIndice == NULL) {
		printf("\n\n******CONTATO NÃO EXISTE!********\n");
	}
	else {
		auxContato = auxIndice->inicio;
		auxContato = posicao(auxContato, nome);
		if (auxContato == NULL) {
			printf("\n\n******CONTATO NÃO EXISTE!********\n");
		}
		else {
			printf("TELEFONE: %s\n\n", auxContato->fone);
			printf("(NOVO) TELEFONE: ");
			setbuf(stdin, NULL);
			gets(auxContato->fone);
			setbuf(stdin, NULL);
		}
	}
	system("pause");
}

void listarPorLetra(Tindice *l, char letra) {
	Tindice *auxIndice;
	Tcontato *auxContato;

	auxIndice = buscaIndice(l, letra);
	if (auxIndice == NULL) {
		printf("\n\n******NÃO EXISTE(M) CONTATOS NO INIDICE: '%c' ********\n", toupper(letra));
	}
	else {
		auxContato = auxIndice->inicio;
		printf("|************** %c **************\n\n", toupper(auxIndice->letra));
		do {
			printf("|NOME: %s\n", (auxContato->nome));
			printf("|TELEFONE: %s\n", auxContato->fone);
			printf("|...............................\n");
			auxContato = auxContato->prox;
		} while (auxContato != auxIndice->inicio);
	}
	system("pause");
}

void apagarAgenda(Tindice**l) {
	Tindice *auxIndice;
	Tcontato *auxContato;

	if (*l == NULL) {
		printf("AGENDA VAZIA!\n");
	}
	else {
		do {
			auxIndice = *l;
			auxContato = auxIndice->inicio;
			if (auxContato->prox == auxContato) {//apenas 1 contato
				free(auxContato);
				removerIndice(&(*l), *l);
			}
			else {
				do {
					auxContato = (*l)->inicio;
					(*l)->inicio = auxContato->prox;
					auxContato->ant->prox = auxContato->prox;
					auxContato->prox->ant = auxContato->ant;
					free(auxContato);
				} while ((*l)->inicio->prox != (*l)->inicio);
				free((*l)->inicio);//remove o contato que sobrou
				removerIndice(&(*l), *l);
			}
		} while (*l != NULL);
	}
	system("pause");
}