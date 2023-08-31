#include <cmath>
#include <cstring>
#include <iostream>
#include "PetShop.h"
using namespace std;

// Função para encontrar o dia da semana de uma determinada data
string Zellercongruence(int day, int month, int year)
{
	if (month == 1) {
		month = 13;
		year--;
	}
	if (month == 2) {
		month = 14;
		year--;
	}
	int q = day;
	int m = month;
	int k = year % 100;
	int j = year / 100;
	int h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
	h = h % 7;
    string diaDaSemana;
	switch (h) {
	case 0:
		diaDaSemana = "Sabado";
		break;
	case 1:
		diaDaSemana = "Domingo";
		break;
	case 2:
		diaDaSemana = "Segunda";
		break;
	case 3:
		diaDaSemana = "Terca";
		break;
	case 4:
		diaDaSemana = "Quarta";
		break;
	case 5:
		diaDaSemana = "Quinta";
		break;
	case 6:
		diaDaSemana = "Sexta";
		break;
	}
	return diaDaSemana;
}

// Função para encontrar o petshop com o menor preço
void petShopMenorPreco(PetShop *pet1, PetShop *pet2, PetShop *pet3, float precoTotalPet1, float precoTotalPet2, float precoTotalPet3){
	PetShop *petShopMenorPreco;
	float *menorPreco;

	if(precoTotalPet1 < precoTotalPet2 && precoTotalPet1 < precoTotalPet3){
		petShopMenorPreco = pet1;
		menorPreco = &precoTotalPet1;
	}else if(precoTotalPet2 < precoTotalPet1 && precoTotalPet2 < precoTotalPet3){
		petShopMenorPreco = pet2;
		menorPreco = &precoTotalPet2;
	}else if(precoTotalPet3 < precoTotalPet1 && precoTotalPet3 < precoTotalPet2){
		petShopMenorPreco = pet3;
		menorPreco = &precoTotalPet3;
	}else if(precoTotalPet1 == precoTotalPet2 && precoTotalPet1 != precoTotalPet3){
		if(pet1->getDistancia() < pet2->getDistancia()){
			petShopMenorPreco = pet1;
			menorPreco = &precoTotalPet1;
		}else{
			petShopMenorPreco = pet2;
			menorPreco = &precoTotalPet2;
		}
	}else if(precoTotalPet1 != precoTotalPet2 && precoTotalPet1 == precoTotalPet3){
		if(pet1->getDistancia() < pet3->getDistancia()){
			petShopMenorPreco = pet1;
			menorPreco = &precoTotalPet1;
		}else{
			petShopMenorPreco = pet3;
			menorPreco = &precoTotalPet3;
		}
	}else if(precoTotalPet2 != precoTotalPet1 && precoTotalPet2 == precoTotalPet3){
		if(pet2->getDistancia() < pet3->getDistancia()){
			petShopMenorPreco = pet2;
			menorPreco = &precoTotalPet2;
		}else{
			petShopMenorPreco = pet3;
			menorPreco = &precoTotalPet3;
		}
	}else{
		if(pet1->getDistancia() < pet2->getDistancia() && pet1->getDistancia() < pet3->getDistancia()){
			petShopMenorPreco = pet1;
			menorPreco = &precoTotalPet1;
		}else if(pet2->getDistancia() < pet1->getDistancia() && pet2->getDistancia() < pet3->getDistancia()){
			petShopMenorPreco = pet2;
			menorPreco = &precoTotalPet2;
		}else{
			petShopMenorPreco = pet3;
			menorPreco = &precoTotalPet3;
		}
	}
	cout << "A melhor opcao para Eduardo eh: " << petShopMenorPreco->getNomeEstabelecimento() << " - Valor total: " <<  *menorPreco << endl;
}

// Função para remover os zeros a esquerda de uma string
string removeZero(string str)
{
    int i = 0;
    while (str[i] == '0')
       i++;

    str.erase(0, i);
  
    return str;
}

int main()
{
    PetShop *meuCaninoFeliz = new PetShop();
    PetShop *vaiRex = new PetShop();
    PetShop *chowChawgas = new PetShop();

	meuCaninoFeliz->setNomeEstabelecimento("Meu Canino Feliz");
    meuCaninoFeliz->setPrecoCaes(20.0, 40.0, 24.0, 48.0);
	meuCaninoFeliz->setDistancia(2.0);

	vaiRex->setNomeEstabelecimento("Vai Rex");
	vaiRex->setPrecoCaes(15.0, 50.0, 20.0, 55.0);
	vaiRex->setDistancia(1.7);

	chowChawgas->setNomeEstabelecimento("ChowChawgas");
	chowChawgas->setPrecoCaes(30.0, 45.0, 30.0, 45.0);
	chowChawgas->setDistancia(0.8);

    string data;
    int numCaesPequenos;
    int numCaesGrandes;


    cout << "Digite a data no formato DD/MM/AAAA, o numero de caes pequenos e o numeros de caes grandes." << endl;
    cin >> data >> numCaesPequenos >> numCaesGrandes;

	string dia = data.substr(0,2).c_str();
	dia = removeZero(dia);
	string mes = data.substr(3,5).c_str();
	mes = removeZero(mes);
	string ano = data.substr(6,10).c_str();
	
	string diaDaSemana = Zellercongruence(atoi(dia.c_str()), atoi(mes.c_str()), atoi(ano.c_str()));

	float precoTotalPet1 = meuCaninoFeliz->calculaPrecoTotal(diaDaSemana,numCaesPequenos,numCaesGrandes);
	float precoTotalPet2 = vaiRex->calculaPrecoTotal(diaDaSemana,numCaesPequenos,numCaesGrandes);
	float precoTotalPet3 = chowChawgas->calculaPrecoTotal(diaDaSemana,numCaesPequenos,numCaesGrandes);
	
	petShopMenorPreco(meuCaninoFeliz,vaiRex,chowChawgas, precoTotalPet1, precoTotalPet2, precoTotalPet3);
    
    return 0;
}