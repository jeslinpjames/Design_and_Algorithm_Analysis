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
        void inputMap();
        void randomMap();
        void inputSize();
        int collect();
        ~coinCollecting();
};
coinCollecting::~coinCollecting(){
    delete[] coin_map;
}
int coinCollecting::collect(){
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
void coinCollecting::inputSize(){
    cout<<"Enter the value of n : ";
    cin>>n;
    cout<<"Enter the value of m : ";
    cin>>m;
}
void coinCollecting::inputMap(){
    cout<<"Enter the map: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>coin_map[i][j];
        }
    }
}
void coinCollecting::randomMap(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            coin_map[i][j]=rand()%10;
        }
    }
}
