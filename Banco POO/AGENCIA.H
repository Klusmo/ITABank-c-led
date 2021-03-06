#ifndef AGENCIA_H_INCLUDED
#define AGENCIA_H_INCLUDED

#include "Conta.h"

// Agencia controla todo o macro das contas, gerindo todo o conjunto de opera��es.
class Agencia
{

private:
    Conta *inicioContas;

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


    // verifica a possibilidade da opera��o selecionada.
    bool sacar (int _numero, float valor);
    // verifica a a existencia da conta selecionada para a opera��o.
    bool deposito(int _numero, float valor);
    // verifica a existencia de ambas as contas e realiza a tranferencia entre as duas caso positivo.
    bool tranferir (int nOrigem, int nDestino, float valor);
    void listarCont ();

    // Destrutor padr�o.
    ~Agencia ();

};





#endif // AGENCIA_H_INCLUDED
