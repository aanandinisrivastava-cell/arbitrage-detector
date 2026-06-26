#ifndef GRAPH_H
#define GRAPH_H
#include "Edge.h"
#include <vector>
#include <map>
#include <string>
#include "ExchangeRate.h"

using namespace std;

class Graph
{
private:
    map<string, vector<pair<string, double>>> graph;
    map<string, int> currencyId;
    vector<Edge> edges;
    map<int, string> idToCurrency;

public:
void addExchange(string from,string to,double rate);
void printExchanges();
bool detectArbitrage();
void loadFromFile(string filename);
};

#endif