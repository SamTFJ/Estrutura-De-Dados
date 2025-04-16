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
            tabelahash.push_back({index, valor});
        }

        int funcaohash (int chave, string nome){
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

};

int main (){
    TabelaHash tbh;

    // Inserindo dados na tabela
    tbh.inserir(0, {"João", "Pedro"});
    tbh.inserir(1, {"Marco", "Matheus"});
    tbh.inserir(2, {"Marina", "Juliana"});

    // Impressão
    tbh.printtable();

    return 0;
}