void MorrisInPreorderSearchTwo(){
            TreeNo<T> *p=root, *tmp;
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

// A) resultado: 10 -> 5 -> 3 -> 7 -> 20 -> 15 -> 24

//B) O algoritmo apresentado é uma variação do algoritmo Morris para percurso em pré-ordem de uma árvore binária. Aqui estão os passos explicados:

// 1. Inicialize um ponteiro `p` com a raiz da árvore.
// 2. Enquanto o ponteiro `p` não for nulo, faça o seguinte:
//    a. Verifique se o nó apontado por `p` não tem filho esquerdo.
//       - Se não tiver filho esquerdo:
//         - Visite o nó atual (`visit(p)`).
//         - Atualize o ponteiro `p` para apontar para o nó à direita.
//    b. Se o nó apontado por `p` tiver um filho esquerdo, siga estes passos:
//       i. Inicialize um ponteiro temporário `tmp` com o filho esquerdo de `p`.
//       ii. Enquanto o filho direito de `tmp` não for nulo e não apontar para o nó atual (`tmp->right != 0 && tmp->right != p`):
//         - Avance `tmp` para a direita.
//       iii. Verifique se o filho direito de `tmp` é nulo.
//         - Se for nulo:
//           - Visite o nó atual (`visit(p)`).
//           - Atualize o filho direito de `tmp` para apontar para o nó atual (`tmp->right = p`).
//           - Atualize o ponteiro `p` para apontar para o filho esquerdo do nó atual (`p = p->left`).
//         - Caso contrário, se o filho direito de `tmp` apontar para o nó atual:
//           - Atualize o filho direito de `tmp` para nulo (`tmp->right = 0`).
//           - Atualize o ponteiro `p` para apontar para o filho direito do nó atual (`p = p->right`).
// 4. O algoritmo continua executando até que todos os nós da árvore tenham sido visitados.

// Este algoritmo de percurso em pré-ordem usando o algoritmo Morris permite percorrer a árvore sem o uso de uma pilha de recursão ou uma pilha de auxílio, tornando-o eficiente em termos de espaço.

// Espero que esta explicação seja útil para entender os passos do algoritmo.