#include "Agencia.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

//construtor padrão.
Agencia::Agencia()
{
    for(int i = 0;i<MAX; i++){
        vetContas[i] = 0;
    }
    contConta=0;
    proxConta=1;
}

void Agencia::criarConta(char* _nomeT)
{
    bool valida = false;
    for (int i =0; i<contConta; i++){
        if(!strcmp(vetContas[i]->getNomeT(), _nomeT))
            valida = true;
    }
    if (valida){
        cout<<"O cliente "<<_nomeT<<" ja possui conta neste banco"<<endl;
    }else{
        vetContas[contConta] = new (nothrow) Conta(_nomeT, proxConta);
        if(vetContas[contConta]){
            vetContas[contConta]->exibirConta();
            contConta++;
            proxConta++;
            cout<<"Conta Criada com sucesso"<<endl;
        }else{
            cout<<"Nao foi possivel alocar a nova conta"<<endl;
        }
    }
}

// verifica a existencia da conta, se seu saldo esta em zero, se positivo, deleta se a conta e rearranja o vetor em que antes a mesma estava incerida.
bool Agencia::encerraConta(int _numConta)
{
    // verifica os atributos da conta a ser deletada.
    int op;
    Conta *aux = locConta(_numConta);
    if(aux && aux->getSaldo()== 0){
        aux->exibirConta();
        // confirmação da ação da execução da função pelo cliente.
        cout<<"Realmente Deseja  Excluir esta conta ?" << endl ;
        cout << "(1)sim ou (0)Nao" <<endl;
        cin>>op;
        if (1){
            // reorganiza o vetor de contas, passando a lacuna vazia para o fim do vetor.
            for(int i=0;i<MAX-1;i++){
                if(aux == vetContas[i]){
                     vetContas[i] = 0;
                }
                if (!vetContas[i] && vetContas[i+1]){
                    vetContas[i]= vetContas[i+1];
                    vetContas[i+1] = 0;
                }
            }
            delete aux;
            aux = 0;
            // diminui o contador que é apontado de quantas contas são existentes no banco.
            contConta--;
            cout<< "Conta encerrada com sucesso ! " << endl;
            return true;
        }
        else{
            return false;
        }
    }else{
        // disclaimer para anunciar inconsistencia na operação, ou relativa ao saldo ainda ser posiitivo ou da inexistencia da  conta.
        if(aux->getSaldo() != 0)
            cout<<"A conta"<<_numConta<<"ainda possui saldo"<<endl;
        else
            cout<<"A conta"<<_numConta<<"nao existe"<<endl;

        return false;

    }

}

//operação para a busca das contas cadastradas na agencia.
Conta* Agencia::locConta(int _numero)
{
    for (int i=0;i<MAX;i++)
        if(vetContas[i]->getNumConta()==_numero)
            return vetContas[i];

    return 0;
}

// confere o valor pedido a ser sacado.
bool Agencia::sacar(int _numero, float valor)
{
    Conta *aux = locConta(_numero);
    if(aux){
        aux->exibirConta();
        if(aux->saque(valor)){
            return true;
        }else {
            cout<<"Saldo Insuficiente"<<endl;
            return false;
        }
    }else{
        cout<<"A conta de numero"<<_numero<<"nao existe"<<endl;
        return false;
    }
}

// verifica a existencia da conta requisitada.
bool Agencia::deposito(int _numero, float valor)
{
    Conta *aux = locConta(_numero);
    if(aux){
        aux->deposito(valor);
        aux->exibirConta();
        return true;
    }else
        return false;
}

//confere a existencia das contas exigidas e apos a confirmação positiva, tranfere o valor declarado.
bool Agencia::tranferir(int nOrigem, int nDestino, float valor){
    Conta *auxOrigem = locConta(nOrigem);
    Conta *auxDestino = locConta(nDestino);

    if (auxOrigem){
        auxOrigem->exibirConta();
        if(auxDestino){
            auxDestino->exibirConta();
            if(auxOrigem->saque(valor)){
                auxDestino->deposito(valor);
                return true;
            }else{
                cout<<"Saldo inssuficiente na conta origem"<<endl;
                return false;
            }
        }else{
            cout<<"Conta destino nao encontrada"<<endl;
            return false;
        }
    }else{
        cout<<"Conta de Origem nao encontrada"<<endl;
        return false;
    }
}

// exibe todas as contas cadastradas ate então na agencia.
void Agencia::listarCont()
{
    for(int i=0; i < MAX; i++){
        if (vetContas[i]){
            vetContas[i]->exibirConta();
            cout<<endl;
        }
    }
}

//destrutor
Agencia::~Agencia()
{
    for(int i=0; i<MAX; i++)
        delete vetContas[i];
}
