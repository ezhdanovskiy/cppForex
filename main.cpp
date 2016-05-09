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

int main() {
    int cnt;
    cin >> cnt;
    vector<double> rates(cnt);
    for (double &rate : rates) {
        cin >> rate;
    }
    cout << "rates[3]=" << rates[3] << endl;
    f1(rates);
    f2(rates);
    f3(rates);
    return 0;
}
