//Foi considerado que o grafo tem os vértices conectados com todos os outros vértices, entretanto cada aresta tem um peso diferente da outra
//Os valores do peso da aresta são criados de forma randômica

#include <bits/stdc++.h>
using namespace std;


int numeroAleatorio(int menor, int maior) {
    return rand()%(maior-menor+1) + menor;
}

int main(){
    srand(time(NULL));
    int max = 2000000000;
    cout << "Bem vindo ao código de resolução para o problema do caxeiro viajante" << endl;
    cout << "Você pode selecionar um grafo de até 15 vértices, indo de 1 até 9 e depois de 'a' até 'f'" << endl;
    cout << "Digite o número de vértices que terá o grafo (de 2 à 15): " << endl;
    int N; cin >> N;
    int matriz[N][N];

    cout << "Matriz de adjacência do grafo:" << endl;

// Esses 3 for's são referentes a criação da matriz de adjacência, sorteando um número para cada espaço x,y da matriz.

    for(int i=0; i<N; i++){
        for(int y=0; y<N; y++){
            matriz[i][y] = -1;
        }
    }

    for(int i=0; i<N; i++){
        for(int y=0; y<N; y++){
            if(matriz[i][y] == -1){
                matriz[i][y] = numeroAleatorio(1,20);
                if( i != y)
                    matriz[y][i] = matriz[i][y];
                if(i==y) matriz[y][i] = -1;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int y=0; y<N; y++){
            cout << matriz[i][y] << " ";
        }
        cout << endl;
    }
    cout << "Digite a cidade que se deseja começar: " << endl;
    int comeco;
    char letra = 'a';
    cin >> comeco;
    char comeco_letra='a';
    cout << "---------------------------------------------------------------------" << endl;
    auto start = chrono::steady_clock::now(); // Start do contador de tempo
    string s = "";
    for(int i=1; i<=N; i++){
        if(i<10){
        if(i != comeco){
            s += to_string(i);
        }}
        else{
            s+=letra;
            letra++;
        }
           
    }
    int aux_comeco = comeco;

    set<string> caminhos;
    string temp;
    string aux;
    do{     //Pegar todas as permutações possíveis e filtrar para que não haja repetidas (inversos, por exemplo 1231 = 1321 pois o grafo é não direcionado)
        aux = s;
        if(comeco<10){
        temp = to_string(comeco)+s+to_string(comeco);}
        if(comeco>=10){
            aux_comeco=-10;
            comeco_letra+=aux_comeco;
            temp = comeco_letra+s+comeco_letra;}
        aux_comeco = comeco;

        
        reverse(aux.begin(),aux.end());
        if(comeco<10){
        string temp = to_string(comeco)+s+to_string(comeco);}
        else{
            aux_comeco=-10;
            comeco_letra+=aux_comeco;
            string temp = comeco_letra+s+comeco_letra;}
        if(caminhos.count(aux) == 0)
            caminhos.insert(temp);
    }while (next_permutation(s.begin(),s.end()));

    
    auto it = caminhos.begin();
    int melhorCaminho = max;
    string melhorRota;
    int a,b;
    for(int i=0; i<caminhos.size(); i++){  //fazer a análise de caminhos conforme o peso salvo na matriz de adjacência
        string atual = *it;
        int somaCaminho=0;
        for(int y=0; y<atual.size()-1; y++){
            string c = ""; 
            string d = "";
            c = atual[y];
            d = atual[y+1];
            if( c!="a" && c!="b" && c!="c" && c!="d" && c!="e" && c!="f" ){
            a = stod(c);}
            else{
                if(c=="a") a = 10;
                else if(c=="b") a = 11;
                else if(c=="c") a = 12;
                else if(c=="d") a = 13;
                else if(c=="e") a = 14;
                else if(c=="f") a = 15;
            }
            if( d!="a" && d!="b" && d!="c" && d!="d" && d!="e" && d!="f" ){
            b = stod(d);}
            else{
                if(c=="a") b = 10;
                else if(c=="b") b = 11;
                else if(c=="c") b = 12;
                else if(c=="d") b = 13;
                else if(c=="e") b = 14;
                else if(c=="f") b = 15;
            }
            
            somaCaminho += matriz[a-1][b-1];
        }
        if(somaCaminho < melhorCaminho){
            melhorCaminho = somaCaminho;
            melhorRota = atual;
        }
        it++;
    }
    cout << "Melhor rota (cada número/letra representa um vértice): " << melhorRota << endl;
    cout <<"Caminho em KM gastos (conforme o peso das arestas): " <<melhorCaminho << endl;
    auto end = chrono::steady_clock::now(); // pausa o contador de tempo
    cout << "Tempo gasto em microsegundos: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " µs" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    return 0;
}