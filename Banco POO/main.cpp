/*
Augusto Aranda Figueiredo 2017012181
Matheus Botelho Menezes dos Santos 2017012780
⁠⁠⁠⁠⁠Italo Rosa 2017012978
24/09/17

O Programa Segue a implementação de um banco utilizando os conceitos de
Programação Orientada a Objetos, no qual implementamos 2 classes,
Agencia e Conta, para gerenciar seu funcionamento.
Ao iniciar sera apresentado um menu, onde o usuario pode
escolher entre as opções e realizar as operações que desejar.
*/
#include <iostream>
#include "Agencia.h"
#include <cstdlib>
#include <cstdio>

using namespace std;
int main()
{
    Agencia *BancoPOO = new Agencia();
    int op, numConta, numConta2, valor;
    char nome[75];
    // Menu do BancoPoo.
    do{
        cout<<"Bem vindo ao Banco POO"<<endl;
        cout<<"Digite o numero referente a operação que deseja realizar"<<endl;
        cout<<" 1 - Criar Conta"<<endl;
        cout<<" 2 - Encerrar Conta"<<endl;
        cout<<" 3 - Saque"<<endl;
        cout<<" 4 - Deposito"<<endl;
        cout<<" 5 - Transferencia"<<endl;
        cout<<" 6 - Listar Contas"<<endl;
        cout<<" 0 - Sair"<<endl;
        cin>>op;
        switch (op){
            case 1:
                cout<<"Nova Conta"<<endl<<"Digite o nome do Titular"<<endl;
                fflush(stdin);
                gets(nome);
                BancoPOO->criarConta(nome);
                system("pause");
                system("cls");
                break;
            case 2:
                cout<<"Remover Conta"<<endl<<"Digite o numero da conta a ser excluida:";
                cin>>numConta;
                if (BancoPOO->encerraConta(numConta))
                    cout<<"Conta Removida"<<endl;
                else
                    cout<<"Conta nao removida"<<endl;
                system("pause");
                system("cls");
                break;
            case 3:
                cout<<"Saque"<<endl<<"Digite o numero da conta: ";
                cin>>numConta;
                cout<<"Digite o valor que deseja sacar: ";
                cin>>valor;
                if(!BancoPOO->sacar(numConta, valor))
                    cout<<"Nao foi possivel completar a operacao"<<endl;
                system("pause");
                system("cls");
                break;
            case 4:
                cout<<"Deposito"<<endl<<"Digite o numero da conta: ";
                cin>>numConta;
                cout<<"Digite o valor que deseja depositar: ";
                cin>>valor;
                if(BancoPOO->deposito(numConta, valor))
                system("pause");
                system("cls");
                break;
            case 5:
                cout<<"Transferencia"<<endl<<"Digite o numero da conta origem: ";
                cin>>numConta;
                cout<<"Digite o numero da conta destino: ";
                cin>>numConta2;
                cout<<"Digite o valor que deseja transferir: ";
                cin>>valor;
                if(BancoPOO->tranferir(numConta,numConta2, valor))
                system("pause");
                system("cls");
                break;
            case 6:
                cout<<"Listagem de contas"<<endl;
                BancoPOO->listarCont();
                system("pause");
                system("cls");

                break;
            case 0:
                delete BancoPOO; BancoPOO =0;
                break;
            default:
                cout<<"Operador Invalido"<<endl;

                system("pause");
                system("cls");
                break;
        }

    }while (op!= 0);

    cout << "Muito obrigado e tenha um bom dia !" << endl;

    // Fim do programa e sua interação com o cliente.
    return 0;
}
