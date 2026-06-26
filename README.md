# Arbitrage Detector

## Motivation
Currency arbitrage occurs when inconsistencies in exchange rates create an opportunity to make a profit through a sequence of currency exchanges. This project models exchange rates as a graph and uses the Bellman-Ford algorithm to detect such opportunities.

## The Project
A C++ application that detects currency arbitrage opportunities using the Bellman-Ford algorithm. The program models exchange rates as a weighted directed graph and identifies profitable currency exchange cycles.



## Features
- Detects arbitrage opportunities in currency exchange markets
- Models exchange rates as a weighted directed graph
- Uses the Bellman-Ford algorithm to detect negative-weight cycles
- Reads exchange rates from an external file
- Displays the arbitrage cycle
- Calculates the profit multiplier and profit percentage
- Modular object-oriented C++ design

## Project Structure

```text
arbitrage-detector/
│
├── data/
│   └── rates.txt
│
├── include/
│   ├── Edge.h
│   ├── ExchangeRate.h
│   └── Graph.h
│
├── src/
│   ├── Graph.cpp
│   └── main.cpp
│
└── README.md
```

## How It Works
Exchange rates are represented as a directed graph where:
- Each currency is a vertex.
- Each exchange rate is a directed edge.

Since exchange rates multiply along a trading cycle, the program converts each exchange rate using:
`weight = -log(exchange_rate)`

This transforms multiplication into addition.
A profitable arbitrage opportunity becomes a negative-weight cycle, which is detected using the Bellman-Ford algorithm.

## How to build and run?
```bash
g++ src/main.cpp src/Graph.cpp -o arbitrage.exe
```
```bash
.\arbitrage.exe
```
## Example Input

`data/rates.txt`

```text
USD EUR 0.91
EUR GBP 0.86
GBP USD 1.35
USD INR 83.50
INR JPY 1.72
JPY USD 0.0068
```

## Example Output

```text
=== Arbitrage Detector ===
EUR -> GBP (0.86)
GBP -> USD (1.35)
INR -> JPY (1.72)
JPY -> USD (0.0068)
USD -> EUR (0.91), INR (83.5)

Arbitrage Opportunity Found!
Cycle: GBP -> USD -> EUR -> GBP

Profit Multiplier: 1.06
Profit Percentage: 5.65%
```

## Technologies Used
- C++
- STL (vector, map)
- Object-Oriented Programming
- Graph Algorithms
- Bellman-Ford Algorithm
- Git & GitHub

## Future Improvements
- Integrate live exchange rates using an API
- Detect multiple arbitrage opportunities
- Rank arbitrage opportunities by profitability
- Add transaction costs and exchange fees
- Build a graphical user interface
