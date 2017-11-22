#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "ArvBin.h"

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

int ArvBin::getRaiz()
{
    if (raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "Árvore vazia!" << endl;
        exit(1);
    }
}

void ArvBin::cria(int x, ArvBin *sae, ArvBin *sad)
{
    No *p = new No();
    p->setInfo(x);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBin::anulaRaiz()
{
    raiz = NULL;
}

void ArvBin::montaArvore()
{
    if(!vazia())
        cout << "Arvore jah montada. So eh possivel a insercao de nos." << endl;
    else
    {
        cout << "Montagem da arvore em pre-ordem:" << endl;
        raiz = auxMontaArvore();
    }
}

No* ArvBin::auxMontaArvore()
{
    string linha;
    cout << "Valor: ";
    cin >> linha;
    if(linha != "NULL" && linha != "null")
    {
        istringstream ent(linha);
        int valor;
        ent >> valor;
        No *p = new No();
        p->setInfo(valor);
        cout << "Esquerda" << endl;
        p->setEsq(auxMontaArvore());
        cout << "Volta no noh" << p->getInfo() << endl;
        cout << "Direita" << endl;
        p->setDir(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        return p;
    }
    else
        return NULL;
}

void ArvBin::insere(int x)
{
    raiz = auxInsere(raiz, x);
}

No* ArvBin::auxInsere(No *p, int x)
{
    if(p == NULL)
    {
        p = new No();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else
    {
        char direcao;
        cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
        cin >> direcao;
        if(direcao == 'e' || direcao == 'E')
            p->setEsq(auxInsere(p->getEsq(), x));
        else
            p->setDir(auxInsere(p->getDir(), x));
    }
    return p;
}

bool ArvBin::vazia()
{
    return (raiz == NULL);
}

bool ArvBin::busca(int x)
{
    return auxBusca(raiz, x);
}

bool ArvBin::auxBusca(No *p, int x)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == x)
        return true;
    else if (auxBusca(p->getEsq(), x))
        return true;
    else
        return auxBusca(p->getDir(), x);
}

ArvBin::~ArvBin()
{
    raiz = libera(raiz);
}

No* ArvBin::libera(No *p)
{
    if (p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}

void ArvBin::preOrdem()
{
    cout << "Arvore Binaria em Pre-Ordem: ";
    auxPreOrdem(raiz);
}

void ArvBin::auxPreOrdem(No *p)
{
    if (p != NULL)
    {
        cout << p->getInfo() << " ";
        auxPreOrdem(p->getEsq());
        auxPreOrdem(p->getDir());
    }
}
int ArvBin::contaNos(){
    return auxContaNos(raiz);
}

int ArvBin::auxContaNos(No *p){

    if(p == NULL){
        return 0;
    }else{
        return 1 + auxContaNos(p->getEsq()) + auxContaNos(p->getDir());
    }
}

int ArvBin::contaNosFolhas(){
    return auxContaNosFolhas(raiz);
}
int ArvBin::auxContaNosFolhas(No *p){
    if(p == NULL){
        return 0;
    }else if(p->getEsq()==NULL && p->getDir()==NULL){
        return 1;
    }else {
        return auxContaNosFolhas(p->getEsq()) + auxContaNosFolhas(p->getDir());
    }
}

int ArvBin::contaAltura(){
    return auxContaAltura(raiz);
}

int ArvBin::auxContaAltura(No *p){
    if(p==NULL){
        return -1;
    }else{
        int ad = auxContaAltura(p->getDir());
        int ae = auxContaAltura(p->getEsq());
        if(ae>ad)
            return ae + 1;
        else
            return ad + 1;
    }
}

int ArvBin::contaImpar(){
    return auxContaImpar(raiz);
}

int ArvBin::auxContaImpar(No *p){
    if(p!=NULL){
        if(p->getInfo()%2!=0){
            return 1 + auxContaImpar(p->getEsq()) + auxContaImpar(p->getDir());
        }else{
            return 0 + auxContaImpar(p->getEsq()) + auxContaImpar(p->getDir());
        }
    }else{
        return 0;
    }
}

int ArvBin::contaFolhaImpar(){
    return auxContaFolhaImpar(raiz);
}
int ArvBin::auxContaFolhaImpar(No *p){
    if(p == NULL){
        return 0;
    }else if(p->getEsq()==NULL && p->getDir()==NULL){
        if(p->getInfo()%2!=0){
            return 1;
        }
    }else {
        return auxContaFolhaImpar(p->getEsq()) + auxContaFolhaImpar(p->getDir());
    }
}

void ArvBin::imprimeNivel(int k){
    if(k<0 || k>contaAltura()){
        cout << "ERRO: Nivel nao existe na arvore"<<endl;
    }else{
        cout << "Valores da arvore no nivel "<<k<<": ";
        auxImprimeNivel(raiz, k);
        cout << endl;
    }
}
void ArvBin::auxImprimeNivel(No *p, int k){
    if(p==NULL) {
        return;
    }else if(k==0){
        cout << p->getInfo() << " ";
    }else{
        auxImprimeNivel(p->getEsq(),k-1);
        auxImprimeNivel(p->getDir(),k-1);
    }
}

int ArvBin::noMaisEsq(){
    return auxNoMaisEsq(raiz);
}
int ArvBin::auxNoMaisEsq(No *p){
    if(p->getEsq()==NULL){
        return p->getInfo();
    }else{
        return auxNoMaisEsq(p->getEsq());
    }
}

void ArvBin::inverte(){
    auxInverte(raiz);
}
void ArvBin::auxInverte(No * p){
    if(p->getEsq()!=NULL && p->getDir()!=NULL){
        No *t = new No();
        t=p->getEsq();
        p->setEsq(p->getDir());
        p->setDir(t);
            auxInverte(p->getEsq());
            auxInverte(p->getDir());
}
}

int ArvBin::noMaisDir(){
    return auxNoMaisDir(raiz);
}
int ArvBin::auxNoMaisDir(No *p){
    if(p->getDir()==NULL){
        return p->getInfo();
    }else{
        return auxNoMaisDir(p->getDir());
    }
}

int ArvBin::minV(){
    return auxMinV(raiz, raiz->getInfo());
}
int ArvBin::auxMinV(No *p, int val){
    if(p==NULL){
        return val;
    }else if(p->getInfo()<val){
         int vale = auxMinV(p->getEsq(),p->getInfo());
         int vald = auxMinV(p->getDir(),p->getInfo());
         if(vale>vald){
            return vale;
         }else{
            return vald;
         }
    }else{
        return val;
    }
}
/*
int ArvBin::teste(){
    return auxTeste(raiz);
}
int ArvBin::auxTeste(No *p){
    return p->getInfo();
}
*/
