#include "Calculos.h"

using namespace Core;
using namespace std;

int Calculos::Soma(int primeiroValor, int SegundoValor)
{
    return primeiroValor + SegundoValor;
}

int Calculos::Subtracao(int primeiroValor, int SegundoValor)
{
    return primeiroValor - SegundoValor;
}

double Calculos::Divisao(int primeiroValor, int SegundoValor)
{
    return primeiroValor / SegundoValor;
}

double Calculos::Multiplicacao(int primeiroValor, int SegundoValor)
{
    return primeiroValor * SegundoValor;
}

bool Calculos::AndLogico(int primeiroValor, int SegundoValor)
{
    return primeiroValor && SegundoValor;
}

bool Calculos::OrLogico(int primeiroValor, int SegundoValor)
{
    return primeiroValor || SegundoValor;
}

bool Calculos::XorLogico(int primeiroValor, int SegundoValor)
{
    return primeiroValor != SegundoValor;
}

int Calculos::AndBitwise(int primeiroValor, int SegundoValor)
{
    return primeiroValor & SegundoValor;
}

