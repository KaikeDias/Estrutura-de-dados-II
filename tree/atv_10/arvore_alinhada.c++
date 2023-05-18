#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#ifndef THREADED_TREE
#define THREADED_TREE

template<class T>
class ThreadedNode {
    public:
        ThreadedNode() {
            left = right = 0;
        }

        ThreadedNode (const T& e, ThreadedNode *l = 0, ThreadedNode *r = 0) {
            el = e, left = l, right = r, successor = 0;
        };
        T el;
        ThreadedNode *left, *right;
        unsigned int successor: 1;
};

template<class T>
class ThreadedTree {
    public: 
    ThreadedTree() {
        root = 0;
    }

    void insert(const T& el) {
        ThreadedNode<T>* p;
        ThreadedNode <T>* prev;
        ThreadedNode<T>* newNode = new ThreadedNode<T>(el);

        if(root == 0) {
            root = newNode;
            return;
        }
        p = root;
        
        while(p != 0) {
            prev = p;
            if(p->el > el) {
                p = p->left;
            } else if (p->successor == 0) {
                p = p->right;
            } else break;
        }

        if(prev->el > el) {
            prev->left = newNode;
            newNode->successor = 1;
            newNode->right = prev;
            
        } else if (prev->successor == 1) {
            newNode->successor = 1;
            prev->successor = 0;
            newNode->right = prev->right;
            prev->right = newNode;
            
        } else {
            prev->right = newNode;
        }
    }

    void inorder() {
        ThreadedNode<T>* p = root;
        ThreadedNode <T>* prev;
    
        if(p != 0) {
            while(p->left != 0) {
                p = p->left;
            };

            while (p != 0) {
                cout << p->el << endl;

                prev = p;
                p = p->right;

                if( p != 0 && prev->successor == 0) {
                    while(p->left != 0) {
                        p = p->left;
                    };
                }
            };
        }
    }

    void preorder() {
        ThreadedNode<T>* p = root;
    
        while (p != 0) {
            cout << p->el << endl;
    
            if (p->left != 0) {
                p = p->left;
            } else if (p->successor == 0) {
                p = p->right;
            } else {
                while (p != 0 && p->successor == 1) {
                    p = p->right;
                }
    
                if (p != 0) {
                    p = p->right;
                }
            }
        }
    }

    protected:
        ThreadedNode<T>* root;
};

#endif


int main () {

    ThreadedTree<int> *tree = new ThreadedTree<int>();

    tree->insert(8);        
    tree->insert(3);
    tree->insert(10);
    tree->insert(1);
    tree->insert(7);
    tree->insert(6);
    tree->insert(14);
    tree->insert(4);
    tree->insert(13);

    tree->inorder();
    cout << "====================" << endl;
    tree->preorder();

};