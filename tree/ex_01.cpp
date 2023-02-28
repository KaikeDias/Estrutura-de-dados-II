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
        return true;
    }

    return estaNaArvore(arvore->left, item) || estaNaArvore(arvore->right, item);
}

int main() {
    Tree arvore = criarArvore(1, criarArvoreVazia(), criarArvore(2, criarArvoreVazia(), criarArvore(3, criarArvoreVazia(), criarArvoreVazia())));

    arvoreImprime(arvore);
    cout << "\n" << qtdNos(arvore) << endl;
    cout << qtdFolhas(arvore) << endl;
    cout << altura(arvore) << endl;
    cout << estaNaArvore(arvore, 1) << endl;
    cout << estaNaArvore(arvore, 5) << endl;
}