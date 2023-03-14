#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct tree {
	int value;
    struct tree *left;
	struct tree *right;
} *Tree;

Tree criarArvore(int v, Tree l, Tree r) {
    Tree newArv = (Tree)malloc(sizeof(Tree));
    newArv->value = v;
    newArv->left = l;
    newArv->right = r;
    
    return newArv;
}

Tree criarArvoreVazia() {
    return NULL;
}

bool arvVazia(Tree v) {
    if(v == NULL) {
        return true;
    }else {
        return false;
    }
}

void arvoreImprime(Tree root) {
    if(root != NULL) {
        cout << "<" << root->value;
        arvoreImprime(root->left);
        arvoreImprime(root->right);
        cout << ">";
    }
}

//Questao 13.2 (quantidade nós) 
int qtdNos(Tree arvore) {
    if(arvVazia(arvore)) {
        return 0;
    }

    return qtdNos(arvore->left) + qtdNos(arvore->right) + 1;
}

//Questao 13.3 (quantidade de folhas)
int qtdFolhas(Tree arvore) {
    if(arvVazia(arvore)) {
        return 0;
    } else if(arvore->left == NULL && arvore->right == NULL) {
        return 1;
    }

    return qtdFolhas(arvore->left) + qtdFolhas(arvore->right);
}

//Questao 13.4 (altura da arvore)
int altura(Tree arvore) {
    if(arvVazia(arvore) || (arvore->left == NULL && arvore->right ==NULL)) {
        return 0;
    } else {
        int alturaEsquerda = altura(arvore->left);
        int alturaDireita = altura(arvore->right);
        if(alturaEsquerda > alturaDireita){
            return alturaEsquerda + 1;
        }else {
            return alturaDireita + 1;
        }
    }


}

//Questao 13.5
bool estaNaArvore(Tree arvore, int item) {
    if(arvVazia(arvore)) {
        return false;
    }else if(arvore->value == item) {
        
    }

    return estaNaArvore(arvore->left, item) || estaNaArvore(arvore->right, item);
}

//Questao 13.6
bool ehEstritamenteBinaria(Tree arvore) {
    if(arvVazia(arvore)) {
        return true;
    } else {
        if(arvore->left != NULL && arvore->right != NULL) {
            return true;
        }else {
            return false;
        }

        return ehEstritamenteBinaria(arvore->left) && ehEstritamenteBinaria(arvore->right);
    }
}

//Questao 13.7
bool igual(Tree arvore1, Tree arvore2) {
     if (((arvore1) == NULL) != ((arvore2) == NULL)) 
       return false;
       
    if ((arvore1) == (arvore2)) 
       return true;
       
    if ((arvore1)->value != (arvore2)->value) 
       return false;
       
    if (!igual(((arvore1)->left), ((arvore2)->left))) 
        return false;
        
    if (!igual(((arvore1)->right), ((arvore2)->right)))
        return false;
        
    return true;
}

//Questao 13.8


//Questao 13.9
void exibe_dec(Tree arvore) {
    if(arvore == NULL) return;
    exibe_dec(arvore->right);
    cout << arvore->value << endl;
    exibe_dec(arvore->left);
}

int main() {
    Tree arvore1 = criarArvore(1, criarArvoreVazia(), criarArvore(2, criarArvoreVazia(), criarArvore(3, criarArvoreVazia(), criarArvoreVazia())));
    Tree arvore2 = criarArvore(1, criarArvoreVazia(), criarArvore(2, criarArvoreVazia(), criarArvore(3, criarArvoreVazia(), criarArvoreVazia())));
    Tree arvore3 = criarArvore(1, criarArvore(2, criarArvoreVazia(), criarArvoreVazia()), criarArvore(3, criarArvoreVazia(), criarArvoreVazia()));

    arvoreImprime(arvore1);
    cout << "\n" << qtdNos(arvore1) << endl;
    cout << qtdFolhas(arvore1) << endl;
    cout << altura(arvore1) << endl;
    cout << estaNaArvore(arvore1, 1) << endl;
    cout << estaNaArvore(arvore1, 5) << endl;

    cout << ehEstritamenteBinaria(arvore3) << endl;
    cout << igual(arvore1, arvore2);
}