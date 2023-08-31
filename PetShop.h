#include <iostream>

using namespace std;

class PetShop{
    private:
        string nomeEstabelecimento;
        float distancia;
        float precoCaesPequenosDiasUteis;
        float precoCaesGrandesDiasUteis;
        float precoCaesPequenosFinaisDeSemana;
        float precoCaesGrandesFinaisDeSemana;
    
    public:
        PetShop() {};
        ~PetShop() {};

        void setNomeEstabelecimento(string nomeEstabelecimento);
        void setPrecoCaes(float precoCaesPequenosDiasUteis, float precoCaesGrandesDiasUteis, float precoCaesPequenosFinaisDeSemana, float precoCaesGrandesFinaisDeSemana);
        void setDistancia(float distancia);
        
        string getNomeEstabelecimento();
        float getDistancia();
        
        float calculaPrecoTotal(string diaDaSemana, int numCaesPequenos, int numCaesGrandes);
};

void PetShop::setPrecoCaes(float precoCaesPequenosDiasUteis, float precoCaesGrandesDiasUteis, float precoCaesPequenosFinaisDeSemana, float precoCaesGrandesFinaisDeSemana){
    
    this->precoCaesPequenosDiasUteis = precoCaesPequenosDiasUteis;
    this->precoCaesGrandesDiasUteis = precoCaesGrandesDiasUteis;
    this->precoCaesPequenosFinaisDeSemana = precoCaesPequenosFinaisDeSemana;
    this->precoCaesGrandesFinaisDeSemana = precoCaesGrandesFinaisDeSemana;
}

void PetShop::setDistancia(float distancia){
    this->distancia = distancia;
}

void PetShop::setNomeEstabelecimento(string nomeEstabelecimento){
    this->nomeEstabelecimento = nomeEstabelecimento;
}

string PetShop::getNomeEstabelecimento(){
    return nomeEstabelecimento;
}
float PetShop::getDistancia(){
    return distancia;
}

float PetShop::calculaPrecoTotal(string diaDaSemana, int numCaesPequenos, int numCaesGrandes){
    float precoTotal = 0.0;
    if(diaDaSemana == "Sabado" || diaDaSemana == "Domingo"){
        precoTotal = precoCaesPequenosFinaisDeSemana * numCaesPequenos;
        precoTotal += precoCaesGrandesFinaisDeSemana * numCaesGrandes;
    }else{
        precoTotal = precoCaesPequenosDiasUteis * numCaesPequenos;
        precoTotal += precoCaesGrandesDiasUteis * numCaesGrandes;
    }
    return precoTotal;
}