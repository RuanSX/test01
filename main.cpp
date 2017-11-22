#include <iostream>
#include "ArvBin.h"
using namespace std;

int main()
{
    ArvBin arv;
    arv.montaArvore();
    arv.preOrdem();
    cout<<endl;
    cout<<"Numero de nos: "<<arv.contaNos()<<endl;
    cout<<"Numero de nos folhas: "<<arv.contaNosFolhas()<<endl;
    cout<<"Altura da arvore: "<<arv.contaAltura()<<endl;
    cout<<"Quantidade de nos com valores impares: "<<arv.contaImpar()<<endl;
    cout<<"Quantidade de nos folhas com valores impares: "<<arv.contaFolhaImpar()<<endl;
    arv.imprimeNivel(2);
    cout<<"Valor do noh mais aa esquerda: "<<arv.noMaisEsq()<<endl;
    cout<<"Valor do noh mais aa direita: "<<arv.noMaisDir()<<endl;
    arv.inverte();
    arv.preOrdem();
    cout<<endl;
    cout<<"Menor valor da arvore: "<<arv.minV()<<endl;
    return 0;
}
