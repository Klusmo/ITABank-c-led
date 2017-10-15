#include "Agencia.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//construtor padrão.
Agencia::Agencia(){
    inicioContas = 0;

    contConta=0;
    proxConta=1;
}

void Agencia::criarConta(char* _nomeT){
    bool valida = false;
    Conta *aux = inicioContas;
    while(aux && !valida){
        if(!strcmpi(aux->getNomeT(), _nomeT))
            valida = true;
        aux = aux->getProx();
    }
    if (valida){
        cout<<"O cliente "<<_nomeT<<" ja possui conta neste banco"<<endl;
    }else{
        Conta *contaAInserir = new (nothrow) Conta(_nomeT, proxConta);
        if(contaAInserir){
            contaAInserir->exibirConta();
            if(inicioContas){
                contaAInserir->setProx(inicioContas);
                inicioContas->setAnt(contaAInserir);
            }
            inicioContas = contaAInserir;
            contConta++;
            proxConta++;
            cout<<"Conta Criada com sucesso"<<endl;
        }else{
            cout<<"Nao foi possivel alocar a nova conta"<<endl;
        }
    }
}

// verifica a existencia da conta, se seu saldo esta em zero, se positivo, deleta se a conta e rearranja o vetor em que antes a mesma estava incerida.
bool Agencia::encerraConta(int _numConta){
    // verifica os atributos da conta a ser deletada.
    int op;
    Conta *aux = locConta(_numConta);
    if(aux && aux->getSaldo()== 0){
        aux->exibirConta();
        // confirmação da ação da execução da função pelo cliente.
        cout<<"Realmente Deseja  Excluir esta conta ?" << endl ;
        cout << "(1)sim ou (0)Nao" <<endl;
        cin>>op;
        if (op){
            if(aux->getAnt()){
                (aux->getAnt())->setProx(aux->getProx());
                if(aux->getProx())
                    (aux->getProx())->setAnt(aux->getAnt());
            }else{
                inicioContas=aux->getProx();
            }

            aux->setAnt(0);
            aux->setProx(0);

            // diminui o contador que é apontado de quantas contas são existentes no banco.
            contConta--;
            delete aux;
            aux = 0;
            cout<< "Conta encerrada com sucesso ! " << endl;
            return true;
        }else{
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
Conta* Agencia::locConta(int _numero){
    Conta *aux = inicioContas;
        while(aux){
            if(aux->getNumConta()==_numero)
                return aux;
            aux = aux->getProx();
        }
    return 0;
}

// confere o valor pedido a ser sacado.
bool Agencia::sacar(int _numero, float valor){
    Conta *aux = locConta(_numero);
    if(aux){
        aux->exibirConta();
        if(aux->saque(valor)){
            return true;
        }else{
            cout<<"Saldo Insuficiente"<<endl;
            return false;
        }
    }else{
        cout<<"A conta de numero"<<_numero<<"nao existe"<<endl;
        return false;
    }
}

// verifica a existencia da conta requisitada.
bool Agencia::deposito(int _numero, float valor){
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
void Agencia::listarCont(){
    Conta *aux = inicioContas;
    while (aux){
        aux->exibirConta();
        cout<<endl;
        aux = aux->getProx();
    }
}

//destrutor
Agencia::~Agencia(){
    delete inicioContas;
    inicioContas = 0;
}
