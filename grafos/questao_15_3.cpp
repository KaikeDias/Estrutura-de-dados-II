//Grupo: Kaike Dias, Kelson Eduardo, Igor Julliano

#include "Fila.cpp"

void bfs(int v, int w, Lista Adj[]){
    Fila F = fila(100);
    enfileira(no(v, NULL),F);
    while(!vaziaf(F)) {
        Lista c = desenfileira(F);
        if(c->item == w){
            exibe_invertido(c);
            puts("");
        } else
        for (Lista s = Adj[c->item]; s; s = s->prox)
            if(!pertence(s->item,c)) enfileira(no(s->item, clone(c)), F);
        destruir(&c);
    }
    destroi(F);
}

Lista Adj [] = { no(1, no(2, no(3, NULL))),
    no(0, no(3, NULL)),
    no(0, no(3, no(4, NULL))),
    no(2, no(5, no(1, NULL))),
    NULL,
    no(3, no(4, NULL)),
};

int main(){
    bfs(0, 5, Adj);
}
