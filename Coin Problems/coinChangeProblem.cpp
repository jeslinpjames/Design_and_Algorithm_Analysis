#include <iostream>
using namespace std;

class CoinChange {
private:
    int n;
    int *coins;
    int amount;
    int* minCoins;
    int INT_MAX_CUSTOM = 2147483647;  // Custom definition of INT_MAX

public:
    CoinChange() : n(0), coins(nullptr), amount(0) {}

    void inputDenominationsAndAmount();
    int countWays();
    int minCoinCount();
    ~CoinChange();
};

void CoinChange::inputDenominationsAndAmount() {
    cout << "Enter the number of denominations: ";
    cin >> n;
    coins = new int[n];
    cout << "Enter the denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << "Enter the target amount: ";
    cin >> amount;
    minCoins = new int[amount + 1];
    for (int i = 0; i <= amount; i++) {
        minCoins[i] = INT_MAX_CUSTOM;
    }
    minCoins[0] = 0;
}

int CoinChange::countWays() {
    if (n <= 0)
        return 0;

    int dp[amount + 1] = {0};
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[amount];
}

int CoinChange::minCoinCount() {
    if (n <= 0)
        return -1;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0 && minCoins[i - coins[j]] != INT_MAX_CUSTOM) {
                minCoins[i] = min(minCoins[i], minCoins[i - coins[j]] + 1);
            }
        }
    }

    return minCoins[amount];
}

CoinChange::~CoinChange() {
    delete[] coins;
    delete[] minCoins;
}

int main() {
    CoinChange ob;
    ob.inputDenominationsAndAmount();
    int numWays = ob.countWays();
    int minCoinCount = ob.minCoinCount();
    cout << "Number of ways to make change: " << numWays << endl;
    cout << "Minimum number of coins: " << minCoinCount << endl;
    return 0;
}
