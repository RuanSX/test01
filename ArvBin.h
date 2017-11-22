#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "No.h"

class ArvBin
{
  public:
    ArvBin();
    ~ArvBin();
    int getRaiz();
    void cria(int x, ArvBin *sae, ArvBin *sad);
    void anulaRaiz();
    bool vazia(); // verifica se a árvore está vazia
    bool busca(int x);
    void preOrdem();
    void montaArvore();
    void insere(int x);
    //int teste();//teste
    int contaNos(); //ex01
    int contaNosFolhas(); //ex02
    int contaAltura(); //ex03
    int contaImpar(); //ex04
    int contaFolhaImpar(); //ex05
    void imprimeNivel(int k); //ex06
    int minV();//ex08
    int maxV();//ex08
    void inverte(); //ex09
    int noMaisEsq(); //ex10
    int noMaisDir(); //ex10

  private:
    No *raiz; // ponteiro para o No raiz da árvore

    No* libera(No *p);
    bool auxBusca(No *p, int x);
    void auxPreOrdem(No *p);
    No* auxMontaArvore();
    void auxImpNivel(No *p, int atual, int k);
   // void auxInverte(No * p);
    No* auxInsere(No *p, int x);
    //int auxTeste(No *p); //teste
    int auxContaNos(No *p); //ex01
    int auxContaNosFolhas(No *p); //ex02
    int auxContaAltura(No *p); //ex03
    int auxContaImpar(No *p); //ex04
    int auxContaFolhaImpar(No *p); //ex05
    void auxImprimeNivel(No *p, int k); //ex 06
    int auxMaxV(No *p, int val); //ex08
    int auxMinV(No *p, int val); //ex08
    void auxInverte(No *p); //ex09
    int auxNoMaisEsq(No *p); //ex10
    int auxNoMaisDir(No *p); //ex10


};

#endif // ARVBIN_H_INCLUDED
