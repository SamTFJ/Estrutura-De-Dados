#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

class TabelaHash {
    private:
        vector<pair<int, vector<string>>> tabelahash;
    
    public:

        void inserir (int index, const vector<string>& valor) {
            for (auto& elemento : tabelahash) {
                if (elemento.first == index) {
                    // Adiciona todos os nomes no vetor existente
                    for (const auto& nome : valor) {
                        elemento.second.push_back(nome);
                    }
                    return;
                }
            }
            // Se não encontrou o índice, adiciona novo par
            tabelahash.push_back({index, valor});
        }

        void funcaohash (int chave, string nome){
            int indice = chave % 10;

            inserir(indice, {nome});
        };

        void printtable () {
            // imprime cada par, o compilador deduz cada elemento da table
            for (const auto& elemento : tabelahash) {
                cout << "Índice: " << elemento.first << endl;
                for(const auto& nome : elemento.second){
                    cout << nome << " ";
                }
                cout << endl;
            }
        }
        
        void encontrar (int chave, string nome1){
            int indice = chave % 10;

            for (const auto& elemento : tabelahash) {
                if (elemento.first == indice){
                    for(int i = 0; i < elemento.second.size(); ++i){
                        if (elemento.second[i] == nome1){
                            cout << "O elemento " << nome1 << " está no índice: " << elemento.first << " " << "e na posição: " << i << endl;   
                        }
                    }
                }
            }
        }
};

int main (){
    TabelaHash tbh;    

    // Inserindo dados na tabela
    tbh.funcaohash(5000, "gabriel");
    tbh.funcaohash(6000, "Ronaldo");
    tbh.funcaohash(7000, "Marcos");
    tbh.funcaohash(5001, "Julia");
    tbh.funcaohash(6001, "João");
    tbh.funcaohash(7001, "Carlos");
    tbh.funcaohash(5002, "Ronaebson");
    tbh.funcaohash(5003, "Taís");
    tbh.funcaohash(5004, "Samuel");

    // Impressão
    tbh.printtable();

    // Procurando elementos
    tbh.encontrar(7000, "Marcos");
    tbh.encontrar(7001, "Carlos");

    return 0;
}