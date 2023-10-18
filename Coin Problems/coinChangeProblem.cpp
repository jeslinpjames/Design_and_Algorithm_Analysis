#include <iostream>
using namespace std;

class CoinChange {
private:
    int n;
    int *coins;
    int amount;

public:
    CoinChange() : n(0), coins(nullptr), amount(0) {}

    void inputDenominationsAndAmount();
    int countWays();
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

CoinChange::~CoinChange() {
    delete[] coins;
}

int main() {
    CoinChange ob;
    ob.inputDenominationsAndAmount();
    int numWays = ob.countWays();
    cout << "Number of ways to make change: " << numWays << endl;
    return 0;
}
