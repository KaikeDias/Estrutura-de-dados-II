#include <queue>
#include <iostream>
#include <cmath>

using namespace std;


template<class T>
class ArvoreNo {
	public:
		T el;
		ArvoreNo<T> *left,*right;
		ArvoreNo(){
			left=right=0;			
		}
		ArvoreNo(T e,ArvoreNo<T> *l=0,ArvoreNo<T> *r=0){
			el=e;
			left=l;
			right=r;
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
		~Arvore(){
			clear();
		}
		void clear(){
			clear(root);
			root=0;
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
		
		T search(T el) {
			ArvoreNo<T> *p=root;
			while (p!=0){
				
				if (el==p->el)		
					return p->el;								    
				else{					
					if (el < p->el)
				       p=p->left;
				   else p=p->right;
			 	}
		    }
			return 0;			
			
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
		
		void percusoExtensao(){
			queue<ArvoreNo<T>*> f;
			ArvoreNo<T> *p=root;
			if (p!=NULL){
				f.push(p);
				while (!f.empty()){
					p=f.front();					
					visit(p);
					f.pop();
					if (p->left!=0)
						f.push(p->left);
					if (p->right!=0)
						f.push(p->right);
				}	}
		}
		
		
		void preorder(ArvoreNo<T> *p){
			if (p!=0) {
				visit(p);
				preorder(p->left);
				preorder(p->right);
			}
			
		}
		
			
		void backbone(ArvoreNo<T> *root){
			ArvoreNo<T> *currentNode = root;
			ArvoreNo<T> *previousNode = nullptr;
			ArvoreNo<T> *leftChild = nullptr;
			
			while(currentNode != nullptr) {
				if(currentNode->left != nullptr){
					leftChild = currentNode->left;
					
					if(previousNode != nullptr) {
						previousNode->right = leftChild;
					} else {
						root = leftChild;
					}
					
					currentNode->left = nullptr;
					leftChild->right = currentNode;
					
					currentNode = leftChild;  
					leftChild = nullptr;
				} else {
					previousNode = currentNode;
					currentNode = currentNode->right;
				}
			}
		}

		int treeHeight(ArvoreNo<T> *root){
            if(root == NULL) {
                return 0;
            }

            int left_height = treeHeight(root->left);
            int right_height = treeHeight(root->right);

            if(left_height > right_height) return left_height + 1;
            return right_height + 1;
    	}


		bool ehBalanceada(ArvoreNo<T> *root){

			if(root == nullptr){
				return true;
			}

			int rightHeight = treeHeight(root->right);
			int leftHeight = treeHeight(root->left);

			if(abs(rightHeight - leftHeight) > 1){
				return false;
			}

			bool leftTreeEhBalanceada = ehBalanceada(root->left);
			bool rightTreeEhBalanceada = ehBalanceada(root->right);

			return leftTreeEhBalanceada && rightTreeEhBalanceada;
		}
};

	
main(){
	
	Arvore<int> *a=new Arvore<int>();

	a->insert(7);
	a->insert(22);
	a->insert(14);
	a->insert(40);
	a->insert(30);
	a->insert(63);
	a->insert(80);

	int treeHeight = a->treeHeight(a->getRoot());

	cout << "A altura da árvore resultante é " << treeHeight << endl;
	
	
	a->preorder(a->getRoot());

	string verificaBalanceamento = (a->ehBalanceada(a->getRoot()) ? "" : "não");

	cout << "A árvore resultante " << verificaBalanceamento << " está balanceada" << endl;
	
	cout << endl;

	a->backbone(a->getRoot());
	
	cout<<"---Apos as rotacoes -----"<<endl;
	a->preorder(a->getRoot());
	

   	
};
