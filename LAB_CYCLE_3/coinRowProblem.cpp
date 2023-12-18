#include <iostream>
using namespace std;
class CoinRow{
private:
    int size;
    int *coins;
    int *sum;
public:
    CoinRow(int n){
        size = n+1;
        coins = new int[size];
        sum = new int[size];
    }
    ~CoinRow(){
        delete[] coins;
    }
    void inputCoins(){
        cout<<"Enter the coins: ";
        for(int i=1;i<size;i++){
            cin>>coins[i];
        }
    }
    int solve(){
        sum[0] = 0;
        sum[1] = coins[1];
        for(int i=2;i<size;i++){
            sum[i] = max(sum[i-1],sum[i-2]+coins[i]);
        }   
        return sum[size - 1]; 
    }
    void printCoins(){
        cout<<"The coins used are: ";
        for(int i=size-1;i>=1;i=i-2){
            if(sum[i]==sum[i-1]){
                i--;
            }
            cout<<coins[i]<<" ";
        }
        cout<<endl;
    }
};
int main() {
    int n;
    cout << "Enter the number of coins: ";
    cin >> n;

    CoinRow coinRow(n);
    coinRow.inputCoins();
    int maxValue = coinRow.solve();

    cout << "Largest value: " << maxValue << endl;
    coinRow.printCoins();

    return 0;
}