#include <iostream>
#include <vector>

using namespace std;

double f1(const vector<double> &rates) {
    size_t opCnt = 0;
    double maxProfit = 0;
    int bestBuyIndex = 0;
    int bestSaleIndex = 0;
    for (int i = 0; i < rates.size() - 1; ++i) {
        for (int j = i + 1; j < rates.size(); ++j) {
            opCnt++;
            double diff = rates[j] - rates[i];
            if (maxProfit < diff) {
                maxProfit = diff;
                bestBuyIndex = i;
                bestSaleIndex = j;
            }
        }
    }
    cout << "maxProfit=" << maxProfit << " bestBuyIndex=" << bestBuyIndex << " bestSaleIndex=" << bestSaleIndex
    << " opCnt=" << opCnt << endl;

    return  maxProfit;
}

double f2(const vector<double> &rates) {
    size_t opCnt = 0;
    double maxProfit = 0;
    int bestBuyIndex = 0;
    int bestSaleIndex = 0;
    for (int i = 0; i < rates.size() - 1; ++i) {
        if (rates[i] < rates[i+1]) {
            for (int j = i + 1; j < rates.size(); ++j) {
                opCnt++;
                double diff = rates[j] - rates[i];
                if (maxProfit < diff) {
                    maxProfit = diff;
                    bestBuyIndex = i;
                    bestSaleIndex = j;
                }
            }
        }
    }
    cout << "maxProfit=" << maxProfit << " bestBuyIndex=" << bestBuyIndex << " bestSaleIndex=" << bestSaleIndex
    << " opCnt=" << opCnt << endl;

    return  maxProfit;
}

double f3(const vector<double> &rates) {
    size_t opCnt = 0;
    double maxProfit = 0;
    int bestBuyIndex = 0;
    int bestSaleIndex = 0;
    for (int i = 0; i < rates.size() - 1; ++i) {
        if (rates[i] < rates[i+1]) {
            for (int j = i + 1; j < rates.size(); ++j) {
                if (rates[j - 1] > rates[j] || j == rates.size() - 1) {
                    opCnt++;
                    int jj;
                    if (j == rates.size() - 1) {
                        jj = j;
                    } else {
                        jj = j-1;
                    }
                    double diff = rates[jj] - rates[i];
                    if (maxProfit < diff) {
                        maxProfit = diff;
                        bestBuyIndex = i;
                        bestSaleIndex = jj;
                    }
                }
            }
        }
    }
    cout << "maxProfit=" << maxProfit << " bestBuyIndex=" << bestBuyIndex << " bestSaleIndex=" << bestSaleIndex
    << " opCnt=" << opCnt << endl;

    return  maxProfit;
}

double f4(const vector<double> &rates) { // TODO: not finished
    if (rates.empty()) {
        cerr << "Empty data!" << endl;
        return 0;
    }

    size_t opCnt = 0;
    double maxProfit = 0;
    int bestBuyIndex = 0;
    int bestBuyIndex0 = 0;
    int bestSaleIndex = 0;
    int bestSaleIndex0 = 0;
    double bestBuy = rates[0];
    double bestBuy0 = rates[0];
    double bestSale = rates[0];
    double bestSale0 = rates[0];
    double profit = 0;
    for (int i = 1; i < rates.size(); ++i) {
        if (bestSale < rates[i]) {
            bestSaleIndex = i;
            bestSale = rates[i];
            profit = bestSale - bestBuy;
            opCnt++;
            continue;
        }
        if (bestBuy > rates[i]) {
            bestBuyIndex0 = bestBuyIndex;
            bestBuyIndex = i;
            bestBuy0 = bestBuy;
            bestBuy = rates[i];
            profit = bestSale - bestBuy;
            opCnt++;
            continue;
        }

    }
    maxProfit = profit;
    cout << "maxProfit=" << maxProfit << " bestBuyIndex=" << bestBuyIndex << " bestSaleIndex=" << bestSaleIndex
    << " opCnt=" << opCnt << endl;

    return  maxProfit;
}

int main() {
    char c;
    cin >> c;
    if (c != '[') {
        cerr << "Usage: cat input.json | ./forex" << endl;
        return -1;
    }
    vector<double> rates;
    double rate;
    while (c != ']') {
        cin >> rate >> c;
        rates.push_back(rate);
    }
    cout << "rates.size=" << rates.size() << " rates[3]=" << rates[3] << endl;


    f1(rates);
    f2(rates);
    f3(rates);
    f4(rates);
    return 0;
}
