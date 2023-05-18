#include <iostream>
#include <queue>
using namespace std;


template<class T>
class ArvoreNo {
	public:
		T el;
		ArvoreNo<T> *left, *right;

		ArvoreNo(){
			left = right = 0;			
		}

		ArvoreNo(T e, ArvoreNo<T> *l = 0, ArvoreNo<T> *r = 0){
			el = e;
			left = l;
			right = r;
		}
};

template<class T>
class Arvore {
	protected:
		ArvoreNo<T> *root;
	public:
		Arvore(){
			root = 0;			
		}
		
		
		ArvoreNo<T>* getRoot(){
			return root;
		}
		bool isEmpty() const {
		   return root=0;
		   }
		   
		void visit(ArvoreNo<T> *p){
			cout<<p->el<<" ";
		} 
		
		 //obs: pg 209 figura 6.23
		void insert(T el){
			ArvoreNo<T> *p=root,*prev=0;
			while (p!=0){
				prev=p;
				if (el<p->el)
					p=p->left;
				else p=p->right;
			}
			if (root==0) //a arvore esta vazia
			   root=new ArvoreNo<T>(el);
			else if (el < prev->el)
				prev->left=new ArvoreNo<T>(el);
			else prev->right=new ArvoreNo<T>(el);
		}
		
		void MorrisInOrder() {
		    ArvoreNo<T> *p = root, *tmp;
		    
		    while(p != 0) {
		        if(p->left == 0) {
		            visit(p);
		            p = p->right;
		        }
		        else {
		            tmp = p->left;
		        
		            while(tmp->right != 0 && tmp->right != p){
		                tmp = tmp->right;
		            }

		            if(tmp->right == 0) {
                        tmp->right = p;
                        p = p->left;
                    } else {
		                visit(p);
		                tmp->right = 0;
		                p = p->right;
		            }
		            
		        }
		    }
		}

        void MorrisPreOrder() {
            ArvoreNo<T> *p = root, *tmp;
            
            while (p != 0) {
                if (p->left == 0) {
                    visit(p);
                    p = p->right;
                } else {
                    tmp = p->left;
                    
                    while (tmp->right != 0 && tmp->right != p) {
                        tmp = tmp->right;
                    }
                    
                    if (tmp->right == 0) {
                        visit(p);
                        tmp->right = p;
                        p = p->left;
                    } else {
                        tmp->right = 0;
                        p = p->right;
                    }
                }
            }
        }

        void MorrisPreorder2(){
            ArvoreNo<T> *p=root, *tmp;
            while (p!=0){
                if (p->left==0){
                    visit(p);
                    p=p->right;
                }
                else{
                    tmp = p->left;
                    while (tmp->right!=0 && tmp->right!=p)
                        tmp=tmp->right;
                        if (tmp->right==0){
                            visit(p);                    
                            tmp->right=p;
                            p=p->left;
                        }
                        else{                    
                            tmp->right=0;
                            p=p->right;    
                        } 
                }
            }   
        }

};

main(){
	Arvore<int> *tree = new Arvore<int>();

    tree->insert(10);        
    tree->insert(5);
    tree->insert(20);
    tree->insert(4);
    tree->insert(7);
    tree->insert(15);
    tree->insert(25);
    tree->insert(6);
    tree->insert(8);
    tree->insert(14);
    
    
    cout << "preorder" << endl;
    tree->MorrisPreOrder();
    
    cout << endl;
    
    cout << "preorder2" << endl;
    tree->MorrisPreorder2();
}
