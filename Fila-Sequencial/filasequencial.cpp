#include <iostream>

class FilaSeq {
    private:
        int* dados;
        int inicio;
        int fim;
        int qtdelem;
        int tamMax;

    public:
        FilaSeq(){
            inicio = 0;
            fim = -1;
            qtdelem = 0;
            tamMax = 100;
            dados = new int[tamMax];
        }

        bool vazia(){
            if (qtdelem == 0){
                return true;
            }else {
                return false;
            }
        }

        bool cheia(){
            if (qtdelem == tamMax){
                return true;
            }
            else{
                return false;
            }
        }

        int tamanho(){
            return qtdelem;
        }

        int primeiro(){
            if (vazia()){
                return false;
            }
            else{
                return dados[inicio];
            }
        }

        bool insere(int valor){
            if (cheia()){
                return false;
            }

            fim = (fim + 1) % tamMax;
            dados[fim] = valor;

            qtdelem++;
            return true;
        }

        int remove(){
            if (vazia()){
                return -1;
            }

            int res = primeiro();
            inicio = (inicio + 1) % tamMax;
            qtdelem--;
            return res;
        }

    void printlista(){
        for (int i = 0; i < qtdelem; i++){
            std::cout << dados[i] << " ";
        }
    }
};

int main(){
    FilaSeq* fila = new FilaSeq;

    fila->insere(10);
    fila->insere(20);
    fila->insere(30);
    fila->printlista();
    fila->remove();
    fila->remove();
    fila->printlista();
    fila->vazia();
    fila->cheia();
}