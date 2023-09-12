#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <cstring>
#include "OperarCalculos.h"

using namespace std;
using namespace Core;
using namespace Core::Enums;

OperadorEnums StringToOperadorEnums(string operadorEnums)
{
    string OPERADORSOMA = "+";
    string OPERADORSUBTRACAO = "-";
    string OPERADORMULTIPLICACAO = "*";
    string OPERADORDIVISAO = "/";
    string OPERADORANDLOGICO = "&&";
    string OPERADORORLOGICO = "||";
    string OPERADORXORLOGICO = "!=";
    string OPERADORANDBITWISE = "&";
    
    if(strcasecmp(operadorEnums.c_str(), OPERADORSOMA.c_str()) == 0) return OperadorEnums::SOMA;
    else if(strcasecmp(operadorEnums.c_str(), OPERADORSUBTRACAO.c_str()) == 0) return OperadorEnums::SUBTRACAO;
    else if(strcasecmp(operadorEnums.c_str(), OPERADORMULTIPLICACAO.c_str()) == 0) return OperadorEnums::MULTIPLICACAO;
    else if(strcasecmp(operadorEnums.c_str(), OPERADORDIVISAO.c_str()) == 0) return OperadorEnums::DIVISAO;
    else if(strcasecmp(operadorEnums.c_str(), OPERADORANDLOGICO.c_str()) == 0) return OperadorEnums::ANDLOGICO;
    else if(strcasecmp(operadorEnums.c_str(), OPERADORORLOGICO.c_str()) == 0) return OperadorEnums::ORLOGICO;
    else if(strcasecmp(operadorEnums.c_str(), OPERADORXORLOGICO.c_str()) == 0) return OperadorEnums::XORLOGICO;
    else if(strcasecmp(operadorEnums.c_str(), OPERADORANDBITWISE.c_str()) == 0) return OperadorEnums::ANDBITWISE;
    else return OperadorEnums::SEMOPERACAO;
}

string CalcularOperacao(int primeirovalor, int segundovalor, string operacao)
{
    auto operatorEnums = StringToOperadorEnums(operacao);
    OperarCalculos operarCalculos;

    string result = "";
    if (operatorEnums != OperadorEnums::SEMOPERACAO)
    {
        result = operarCalculos.Operador(primeirovalor, segundovalor, operatorEnums);
    }
    else
    {
        result = "Escolha uma operacao (+, -, *, /, &&, ||, != or &) correta ou digite exit para sair do programa!";
    }

    return result;
}

bool SairPrograma(string operacao)
{
    bool exitPrograma = false;
    string sair = "exit";

    transform(operacao.begin(), operacao.end(), operacao.begin(), ::toupper);
    transform(sair.begin(), sair.end(), sair.begin(), ::toupper);
    
    if (strcasecmp(operacao.c_str(), sair.c_str()) == 0)
    {
        exitPrograma = true;
    } 

    return exitPrograma;
}


int main()
{
    string result;
    int primeiroValor;
    int segundoValor;
    string operacao;

    bool sairPrograma = false;

    do 
    { 
        try
        {
            cout<<"Insira o primeiro valor inteiro a ser calculado: "<< endl;
            if (!(cin >> primeiroValor))
                throw std::invalid_argument("Inseriu o primeiro valor invalido!");

            cout<<"Insira o segundo valor inteiro a ser calculado: "<< endl;
            if (!(cin >> segundoValor))
                throw std::invalid_argument("Inseriu o segundo valor invalido!");

            cout<<"Insira a operacao que voce deseja (+, -, *, /, &&, ||, != or &) ou exit para sair do programa): "<< endl;
            cin >> operacao;

            sairPrograma = SairPrograma(operacao);
            if (!sairPrograma)
            {
                result = CalcularOperacao(primeiroValor, segundoValor, operacao);
                cout << primeiroValor << " " << operacao << " " << segundoValor << " = " << result << endl;
            }
        }
        catch(const exception& e)
        {
            cout << e.what() << endl;
            break;
        }
        
    } while (!sairPrograma);

    return 0;
}