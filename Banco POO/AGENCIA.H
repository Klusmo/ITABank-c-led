#ifndef AGENCIA_H_INCLUDED
#define AGENCIA_H_INCLUDED

#include "Conta.h"

// Numero maximo de contas permitidos na agencia.
const int MAX = 3;

// Agencia controla todo o macro das contas, gerindo todo o conjunto de operações.
class Agencia {

private:
    // vetor que guarda todas as contas do Banco, ate o limite extipulado por MAX.
    Conta *vetContas [MAX];
    int contConta ;
    int proxConta;

public:
    //Construtor
    Agencia ();
    // Cria uma nova conta.
    void criarConta (char *_nomeT);
    // verifica a existencia da conta e deleta a mesma ou sinaliza a inexistencia desta.
    bool encerraConta (int _numero);
    // procura uma conta apartir do numero informado.
    Conta* locConta (int _numero);


    // verifica a possibilidade da operação selecionada.
    bool sacar (int _numero, float valor);
    // verifica a a existencia da conta selecionada para a operação.
    bool deposito(int _numero, float valor);
    // verifica a existencia de ambas as contas e realiza a tranferencia entre as duas caso positivo.
    bool tranferir (int nOrigem, int nDestino, float valor);
    void listarCont ();

    // Destrutor padrão.
    ~Agencia ();

};





#endif // AGENCIA_H_INCLUDED
