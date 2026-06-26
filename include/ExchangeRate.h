#ifndef EXCHANGERATE_H
#define EXCHANGERATE_H
#include <string>
using namespace std;

struct ExchangeRate{
    string from;
    string to;
    double rate;
};
#endif