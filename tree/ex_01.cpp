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

int main() {
    Tree arvore = criarArvore(1, criarArvoreVazia(), criarArvore(2, criarArvoreVazia(), criarArvore(3, criarArvoreVazia(), criarArvoreVazia())));

    arvoreImprime(arvore);
}