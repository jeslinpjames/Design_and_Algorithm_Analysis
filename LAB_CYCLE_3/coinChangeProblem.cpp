#include<iostream>
using namespace std;
class coinChange{
    private:
        int INT_MAX = 999999;
        int n;
        int *coins;
        int amount;
    public:
    void inputCoins(){
        cout<<"Enter the number of coins: ";
        cin>>n;
        coins = new int[n];
        cout<<"Enter the coins: ";
        for(int i=0;i<n;i++){
            cin>>coins[i];
        }
    }
    void inputValue(){
        cout<<"Enter the amount : ";
        cin>>amount;
        amount++;
    }
    int min(int a,int b){
        return a<b?a:b;
    }
    void printCoins(int *count, int n, int *coins, int d)
    {
        cout << "The coins we choose are : ";
        n--;
        for (int i = 0; i < d; i++)
        {
            int value = count[n - coins[i]] + 1;
            if (value == count[n])
            {
                n -= coins[i];
                cout << coins[i] << ", ";
                i--;
            }
        }
        return;
    }
    void minCoins()
    {
        int count[amount];
        count[0] = 0;
        for (int i = 1; i < amount; i++)
        {
            count[i] = INT_MAX;

            for (int j = 0; j < n; j++)
            {

                if (i < coins[j])
                    break;

                count[i] = min(count[i], count[i - coins[j]]);
            }
            ++count[i];
        }
        if (count[amount - 1] != INT_MAX)
        {
            cout << "Number of coins required: " << count[amount - 1] << endl;
            printCoins(count, amount, coins, n);
        }
        else
        {
            cout << "Cannot be solved";
        }
        return;
    }
};
int main()
{
    coinChange c;
    c.inputCoins();
    c.inputValue();
    c.minCoins();
    return 0;
}