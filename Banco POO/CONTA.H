#ifndef CONTA_H_INCLUDED
#define CONTA_H_INCLUDED

// Conta gerencia todas as variaveis manipuladas de forma micro dentro das contas.
class  Conta{
private:
    // Aqui ficar salvo o nome do titular da conta.
    char *nomeT;
    // numero da conta, este que a caracteriza.
    int numConta;
    // valor atual da conta do titular, indicando o saldo em sua conta.
    float saldo;

public:
    // construtor sem parametros. Inicia os valores das variaveis zerados.
    Conta();
    // construtor parametrizado para iniciar o programa com o nome do titular, o numero atribuido a esta conta e zerando seu saldo.
    Conta(char _nomeT[], int _numConta);

    // Getters & Setters
    // Metodo que atribui o nome do titular.
    void setNomeT(char _nomeT[]);
    // Metodo que atribui o numero da conta.
    void setNumConta(int _numConta);
    // altera o valor do saldo presente.
    void setSaldo(float _saldo);

    char* getNomeT();
    int getNumConta();
    float getSaldo();

    // Metodo que imprime as informações da conta presente.
    void exibirConta();
    // Metodo que realiza a operação de deposito do valor inserido na Agencia.
    void deposito(float valor);
    // Metodo que verifica a viabilidade da operação proposta, o saque, e aprova que seja realizado o mesmo ( retornando true) ou negando este (caso o mesmo de false)
    bool saque(float valor);

    // Destructor
    ~Conta();
};


#endif // CONTA_H_INCLUDED
