#include "Conta.h"
#include <iostream>
#include <cstring>
using  namespace std;

//Contrutor Padrão
Conta::Conta(){
    nomeT = 0;
    numConta=0;
    saldo=0;
}

//Contrutor Parametrizado
Conta::Conta(char _nomeT[], int _numConta){
    // aloca dinamicamente o nome do usuario.
    nomeT = new (nothrow) char[strlen(_nomeT)+ 1];
    if(nomeT){
        // recebe o nome inserido em Agencia.
        strcpy(nomeT, _nomeT);
        numConta=_numConta;
        saldo=0;
    }else
        cout<<"Não foi Possivel alocar "<<_nomeT<<endl;
}

//Setters & Getters
void Conta::setNomeT(char _nomeT[]){
    if(nomeT) delete [] nomeT;
    nomeT = new (nothrow) char[strlen(_nomeT)+ 1];
    if(nomeT){
        strcpy(nomeT, _nomeT);
    }else
        cout<<"Não foi Possivel alocar "<<_nomeT<<endl;
}

void Conta::setNumConta(int _numConta){
    numConta=_numConta;
}

void Conta::setSaldo(float _saldo){
    saldo = _saldo;
}

char* Conta::getNomeT(){
    return nomeT;
}

int Conta::getNumConta(){
    return numConta;
}

float Conta::getSaldo(){
    return saldo;
}

void Conta::exibirConta(){
    cout<<"Nome do Titular: "<< nomeT<<endl;
    cout<<"Numero da Conta: "<< numConta<<endl;
    cout<<"Saldo: "<<saldo<<endl<<endl;
}

void Conta::deposito(float valor){
    saldo += valor;
}

bool Conta::saque(float valor){
    // Esta verificando se e possivel proceguir com a operação.
    if(saldo>= valor){
        // realiza a operação.
        saldo -= valor;
        // retorna o sucesso desta.
        return true;
    }else
        // Sinaliza uma incompatibilidade para realizar a operação.
        return false;
}
// Destrutor
Conta::~Conta(){
    // desaloca a variavel da memoria .
    delete [] nomeT;
    nomeT = 0;
}
