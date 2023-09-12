#include "OperarCalculos.h"

using namespace Core;
using namespace Core::Enums;
using namespace std;

OperarCalculos::OperarCalculos()
{
    _calculos = new Calculos();
}

OperarCalculos::~OperarCalculos()
{
    delete _calculos;
}

string OperarCalculos::Operador(int primeiroValor, int SegundoValor, OperadorEnums operacao)
{
    switch(operacao)
    {
        case OperadorEnums::SOMA:
            return Soma(primeiroValor, SegundoValor);
        case OperadorEnums::SUBTRACAO: 
            return Subtracao(primeiroValor, SegundoValor);
        case OperadorEnums::DIVISAO: 
            return Divisao(primeiroValor, SegundoValor);
        case OperadorEnums::MULTIPLICACAO: 
            return Multiplicacao(primeiroValor, SegundoValor);
        case OperadorEnums::ANDLOGICO: 
            return AndLogico(primeiroValor, SegundoValor);
        case OperadorEnums::ORLOGICO: 
            return OrLogico(primeiroValor, SegundoValor);
        case OperadorEnums::XORLOGICO: 
            return XorLogico(primeiroValor, SegundoValor);
        case OperadorEnums::ANDBITWISE: 
            return AndBitwise(primeiroValor, SegundoValor);
        case OperadorEnums::SEMOPERACAO:
            return "SEM OPERACAO!";
        default:
            return "";
    }
}

string OperarCalculos::Soma(int primeiroValor, int segundoValor)
{
    return to_string(_calculos->Soma(primeiroValor, segundoValor));
}

string OperarCalculos::Subtracao(int primeiroValor, int segundoValor)
{
    return to_string(_calculos->Subtracao(primeiroValor, segundoValor));
}

string OperarCalculos::Divisao(int primeiroValor, int segundoValor)
{
    if (segundoValor != 0)
    {
        return to_string(_calculos->Divisao(primeiroValor, segundoValor));
    }
    else
    {
        return "Nao existe divisao por zero!";
    }
}

string OperarCalculos::Multiplicacao(int primeiroValor, int segundoValor)
{
    return to_string(_calculos->Multiplicacao(primeiroValor, segundoValor));
}

string OperarCalculos::AndLogico(int primeiroValor, int segundoValor)
{
    return to_string(_calculos->AndLogico(primeiroValor, segundoValor));
}

string OperarCalculos::OrLogico(int primeiroValor, int segundoValor)
{
    return to_string(_calculos->OrLogico(primeiroValor, segundoValor));
}

string OperarCalculos::XorLogico(int primeiroValor, int segundoValor)
{
    return to_string(_calculos->XorLogico(primeiroValor, segundoValor));
}

string OperarCalculos::AndBitwise(int primeiroValor, int segundoValor)
{
    return to_string(_calculos->AndBitwise(primeiroValor, segundoValor));
}