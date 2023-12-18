#include<iostream>
using namespace std;
class coinCollecting{   
    private:
        int m;
        int n;
        int **coin_map;
        int **F;
    public:
        coinCollecting():n(0),m(0),coin_map(nullptr){}
        coinCollecting(int n,int m):n(n),m(m){
            coin_map = new int*[n];
            for(int i=0;i<n;i++){
                coin_map[i]=new int[m];
            }
            F = new int*[n];
            for(int i=0;i<n;i++){
                F[i]=new int[m];
            }
        }
        int getN(){
            return n;
        }
        int getM(){
            return m;
        }
        void printMap();
        void printF();
        int collect();
        void initilizeMap(int **maps);
        ~coinCollecting();
};
coinCollecting::~coinCollecting() {
    for (int i = 0; i < n; i++) {
        delete[] coin_map[i];
    }
    delete[] coin_map;

    for (int i = 0; i < n; i++) {
        delete[] F[i];
    }
    delete[] F;
}
void coinCollecting::printMap(){
    cout<<"The map is : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<coin_map[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}
int coinCollecting::collect(){
    F[0][0]=coin_map[0][0];
    for(int j=1;j<m;j++){
        F[0][j]=F[0][j-1]+coin_map[0][j];
    }
    for(int i=1;i<n;i++){
        F[i][0]=F[i-1][0]+coin_map[i][0];
        for(int j =1;j<m;j++){
            F[i][j]=max(F[i-1][j],F[i][j-1])+coin_map[i][j];
        }
    }
    return F[n-1][m-1];
}
void coinCollecting::printF(){
    cout<<"The F matrix is : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<F[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}   
void coinCollecting::initilizeMap(int **maps){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            coin_map[i][j]=maps[i][j];
        }
    }
    return; 
}

int main(){
    int m ,n;
    cout<<"Enter the value of m : ";
    cin>>m;
    cout<<"Enter the value of n : ";
    cin>>n;
    coinCollecting ob(m,n);
     int **coins = new int*[m];
    for(int i = 0; i < m; i++) {
        coins[i] = new int[n];
    }
    cout << "Enter 1 if coin is present,else zero" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Location " << i + 1 << "," << j + 1 << ":";
            cin >> coins[i][j];
        }
    }
    cout << endl;
    ob.initilizeMap(coins);
    ob.printMap();
    cout<<"The maximum number of coins collected is : "<<ob.collect()<<endl;
    ob.printF();
    return 0;
}