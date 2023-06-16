#include <iostream>
#include <algorithm>
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
		   return root==0;
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
    
    int treeHeight(ArvoreNo<T> *root){
            if(root == NULL) {
                return 0;
            }

            int left_height = treeHeight(root->left);
            int right_height = treeHeight(root->right);

            if(left_height > right_height) return left_height + 1;
            return right_height + 1;
    }
    
   void printTreeFormated(ArvoreNo<T> *root){
            if(root != NULL){
                cout << "<" << root->el;

                printTreeFormated(root->left);
                printTreeFormated(root->right);
                cout << ">";
            }
    }


    
    
    void balancear (T vetor[], int first, int last) {
        if(first <= last){
            int middle = (first + last)/2;
            insert(vetor[middle]);
            balancear(vetor, first, middle-1);
            balancear(vetor, middle+1, last);
        }
    }
    
   
    void fillTreeInOrder(ArvoreNo<T> *root, T array[], int& index) {
        if (root != NULL) {
            fillTreeInOrder(root->left, array, index);
            array[index++] = root->el;
            fillTreeInOrder(root->right, array, index);
        }
    }

     int countNodes(ArvoreNo<T>* root){
        if(root == NULL) {
            return 0;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    
};

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
	
	/*1) Criação da árvore binária com os elementos inseridos na ordem: 7, 6, 22, 14, 40, 63.*/
        Arvore<int> *tree = new Arvore<int>();
        
        tree->insert(7);        
        tree->insert(6);
        tree->insert(22);        
        tree->insert(14);
        tree->insert(40);        
        tree->insert(63);
    
    //=====================================================================================================
        cout << "1.1) Altura resultante da árvore: "<< tree->treeHeight(tree->getRoot()) << endl;
    
    //=====================================================================================================
        cout << "\n1.2) Mostre a árvore resultante:" << endl;
        cout<< "Árvore resultante: ";
        tree->printTreeFormated(tree->getRoot());
    
    //=====================================================================================================
        cout << "\n\n1.3) A árvore resultante está balanceada ou não?\n" << endl;
        
        cout << "Resposta: Não está balanceada porque a diferença entre a altura ";
        cout << "das subárvores direita e esquerda da raiz é 2 e para uma árvore ser "; 
        cout << "balanceada ela deve ter uma diferença de no máximo 1.";
        
    //=====================================================================================================
        cout << "\n\n1.4) Método sort para ordenar o vetor resultante" << endl;

        //Criação do array e ordenação
        int array[] = {7, 6, 22, 14, 40, 63};
        int size = sizeof(array) / sizeof(array[0]);
        sort(array, array+size);

        //Baleanceamento da árvore utilizando o array de elementos in-order de uma árvore desbalanceada
        Arvore<int> *tree2 = new Arvore<int>();
        tree2->balancear(array, 0, 5);
        tree2->printTreeFormated(tree2->getRoot());
    
    //=====================================================================================================
        cout << "\n\n1.5) método percurso in order para ordenar vetor resultante" << endl;
        
        //Criação do array
        int size2 = tree->countNodes(tree->getRoot());
        int* array2 = new int[size2];
        int index = 0;

        //Preenchendo array com os elementos do percurso em ordem da primeira árvore
        tree->fillTreeInOrder(tree->getRoot(), array2, index);
        
        //Baleanceamento da árvore utilizando o array de elementos in-order de uma árvore desbalanceada
        Arvore<int> *tree3 = new Arvore<int>();
        tree3->balancear(array2, 0, 5);
        tree3->printTreeFormated(tree3->getRoot());
    
    
    //=====================================================================================================
        cout << "\n\n1.6) Compare os resultados em 1.4 e 1.5. As árvores resultantes estão balanceadas? Elas são iguais?\n"<< endl;

        cout << "Elas estão balanceadas e são iguais porque os vetores gerados pelos dois métodos são iguais. ";
        cout << "Realizar um percurso em ordem em uma árvore de busca binária válida, retorna os elementos ";
        cout << "em ordem crescente, o que gera um array de elementos ordenados, assim como se pegassemos ";
        cout << "um array desordenado e ordenássemos utilizando algum método de ordenação." << endl;

        cout << "Portanto, como estamos utilizando a estratégia de balanceamento por reordenação para os dois casos ";
        cout << "as árvores geradas são idênticas. Além disso, são balanceadas pois a diferença entre as duas subárvores";
        cout << "em qualquer nó da árvore não ultrapassa o valor de 1";

}












