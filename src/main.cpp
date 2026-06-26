#include <iostream>
#include "../include/ExchangeRate.h"
#include "../include/Graph.h"
using namespace std;


int main(){
    cout<<"===Arbitrage Detector==="<<endl;
    ExchangeRate e1;

Graph market;

market.loadFromFile("data/rates.txt");
market.printExchanges();
market.detectArbitrage();
}
