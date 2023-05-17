#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct arv {
	char info;
    struct arv *esq;
	struct arv *dir;
} *Arv;


Arv arvore(char x,Arv e,Arv d){
	Arv novo=(Arv )malloc(sizeof(a 	rv));
	novo->esq=e;
	novo->dir=d;
	novo->info=x;
	return novo;
	
}

void imprime(Arv n){		
					
			if (n!=NULL){
					
				cout<<"<"<<n->info;
				imprime(n->esq);
				imprime(n->dir);
				cout<<">";
			   }
			   else
			     cout<<"<>";
			}

int calculaQuantNos(Arv no){
	if(no == NULL) {
        return 0;
    }

    return calculaQuantNos(no->esq) + calculaQuantNos(no->dir) + 1;			
}

int calculaQuantNosFolha(Arv no){
	if(no == NULL) {
        return 0;
    } else if(no->esq == NULL && no->dir == NULL) {
        return 1;
    }

    return calculaQuantNosFolha(no->esq) + calculaQuantNosFolha(no->dir);			
}
		

		
int alturaArvore(Arv no){	        
	if(no == NULL || (no->esq == NULL && no->dir ==NULL)) {
        return 0;
    } else {
        int alturaEsquerda = alturaArvore(no->esq);
        int alturaDireita = alturaArvore(no->dir);
        if(alturaEsquerda > alturaDireita){
            return alturaEsquerda + 1;
        }else {
            return alturaDireita + 1;
        }
    }
        

}
   
int procura(Arv no, char valor){
	if(no == NULL) {
        return false;
    }else if(no->info == valor) {
        
    }

    return procura(no->esq, valor) || procura(no->dir, valor);		
}

// remove o n� procurado. Se o n� tiver filhos, remova tamb�m os filhos		
Arv removeNo(Arv no, char valor) {
    if (no == NULL) {
        return NULL;
    } else if (no->info == valor) {
        Arv novo;
        if (no->esq == NULL && no->dir == NULL) {
            free(no);
            novo = NULL;
        } else if (no->esq == NULL) {
            novo = no->dir;
            free(no);
        } else if (no->dir == NULL) {
            novo = no->esq;
            free(no);
        } else {
            Arv atual = no->dir;
            while (atual->esq != NULL) {
                atual = atual->esq;
            }
            no->info = atual->info;
            no->dir = removeNo(no->dir, atual->info);
            novo = no;
        }
        
		if (novo != NULL) {
            novo->esq = removeNo(novo->esq, valor);
            novo->dir = removeNo(novo->dir, valor);
        }
        return novo;
    } else {
        no->esq = removeNo(no->esq, valor);
        no->dir = removeNo(no->dir, valor);
        return no;
    }
}

bool arvoreBinariaCheia(Arv no) {
    if (no == NULL) {
        return true; // Árvore vazia
    }

    if (no->esq == NULL && no->dir == NULL) {
        return true;
    }

    if (no->esq != NULL && no->dir != NULL) {
        return arvoreBinariaCheia(no->esq) && arvoreBinariaCheia(no->dir);
    }

    return false;
}


	        
int main() {
    Arv d = arvore('d', NULL, NULL);
    Arv e = arvore('e', NULL, NULL);
    Arv b = arvore('b', d, e);
    Arv c = arvore('c', NULL, NULL);
    Arv a = arvore('a', b, c);
    
    imprime(a); // saída esperada: <a<b<d<><>><e<><>>><c<><>>>
    
    removeNo(a, 'b');
    imprime(a); // saída esperada: <a<c<><>>>
    cout << /n << arvoreBinariaCheia(a);
}
	

