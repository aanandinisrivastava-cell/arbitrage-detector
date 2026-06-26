#include <iostream>
using namespace std;
#include "../include/Graph.h"
#include <cmath>
#include <fstream>
#include <algorithm>
#include <iomanip>

void Graph::addExchange(string from, string to, double rate){
    graph[from].push_back({to, rate});
    if (currencyId.find(from) == currencyId.end()){
        int id = currencyId.size();
        currencyId[from] = id;
        idToCurrency[id] = from;
    }

    if (currencyId.find(to)==currencyId.end()){
        int id=currencyId.size();
        currencyId[to]=id;
        idToCurrency[id]=to;
    }

    Edge e;
    e.from=currencyId[from];
    e.to=currencyId[to];
    e.weight=-log(rate);

    edges.push_back(e);
}
void Graph::printExchanges(){
    for (auto &entry:graph){
        cout<<entry.first<<" -> ";
        for (int i=0;i<(entry.second.size()-1);i++){
            cout<<entry.second[i].first<<" (" <<entry.second[i].second<< "), ";
        }
        cout<<entry.second[(entry.second.size()-1)].first<<" (" <<entry.second[(entry.second.size()-1)].second<< ")"<<endl;
    }
}
bool Graph::detectArbitrage(){
    int n=currencyId.size();

    vector<double> dist(n,0.0);
    vector<int> parent(n,-1);

    for (int i = 0; i < n - 1; i++){
        for (Edge e:edges){
            if (dist[e.from]+e.weight<dist[e.to]){
                dist[e.to]=dist[e.from]+e.weight;
                parent[e.to]=e.from;
            }
        }
    }

    int cycleStart=-1;

    for (Edge e:edges){
        if (dist[e.from]+e.weight<dist[e.to]){
            cycleStart=e.to;
            break;
        }
    }

    if (cycleStart==-1){
        cout <<"No Arbitrage Opportunity Found!"<< endl;
        return false;
    }

    for (int i=0;i<n;i++)
        cycleStart=parent[cycleStart];

    vector<int> cycle;
    int cur=cycleStart;

    do{
        cycle.push_back(cur);
        cur=parent[cur];
    }
    while (cur!=cycleStart);
    cycle.push_back(cycleStart);
    reverse(cycle.begin(),cycle.end());

    cout << "\nArbitrage Opportunity Found!\n";
    cout << "Cycle: ";

    for (int i=0; i<cycle.size();i++)
{
    cout <<idToCurrency[cycle[i]];
    if (i!=cycle.size()-1)
        cout <<" -> ";
}
    cout<<endl;
    double multiplier=1.0;

for (int i=0;i<cycle.size()-1;i++)
{
    int u =cycle[i];
    int v =cycle[i+1];

    for (Edge e:edges)
    {
        if (e.from==u && e.to==v)
        {
            multiplier*=exp(-e.weight);
            break;
        }
    }
}
cout<<fixed<<setprecision(2);

cout<<"\nProfit Multiplier: "<<multiplier<<endl;
cout<<"Profit Percentage: "<<(multiplier-1)*100 <<"%"<<endl;

    return true;
}
void Graph::loadFromFile(string filename)
{
    ifstream file(filename);
    if (!file){
    cout<<"Error: Could not open "<<filename<<endl;
    return;
    }
    string from,to;
    double rate;
    while (file>>from>>to>>rate){
        addExchange(from,to,rate);
    }
    file.close();
}