#include<iostream>
using namespace std;
class minCostPath{
    private:
    int m,n;
    int ** cost;
    int ** sum;
    public:
    int min(int a, int b , int c){
        return a<b?(a<c?a:c):(b<c?b:c);
    }
    void acceptCost(){
        cout<<"Enter the value of m : ";
        cin>>m;
        cout<<"Enter the value of n : ";
        cin>>n;
        cost = new int*[m];
        for(int i=0;i<m;i++){
            cost[i]=new int[n];
        }
        cout<<"Enter the cost matrix : "<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>cost[i][j];
            }
        }
    }
    void displayMat(){
        cout<<"The matrix is : "<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<cost[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void findMinCost(){
        sum = new int*[m];
        for(int i = 0;i<m;i++){
            sum[i] =  new int[n];
        }
        sum[0][0] = cost [0][0];
        for (int i = 1; i < m; i++)
        {
            sum[i][0] = sum[i - 1][0] + cost[i][0];
        }
        for (int j = 1; j < n; j++)
        {
            sum[0][j] = sum[0][j - 1] + cost[0][j];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                sum[i][j] = min(sum[i - 1][j], sum[i][j - 1], sum[i - 1][j - 1]) + cost[i][j];
            }
        }
        cout<<"min cost ="<<sum[m-1][n-1];
    }
    void Path()
    {
        cout << "\tPath\n";
        int i = 0;
        int j = 0;
        m--;
        n--;
        cout << "(" << i + 1 << "," << j + 1 << ")-->";
        while (i != m && j != n)
        {
            if (i == m)
            {
                j++;
            }
            else if (j == n)
            {
                i++;
            }
            else if (sum[i + 1][j] <= sum[i][j + 1] && sum[i + 1][j] <= sum[i + 1][j + 1])
            {
                i++;
            }
            else if (sum[i][j + 1] <= sum[i + 1][j] && sum[i][j + 1] <= sum[i + 1][j + 1])
            {
                j++;
            }
            else
            {
                i++;
                j++;
            }
            cout << "(" << i + 1 << "," << j + 1 << ")-->";
        }
        cout << "(" << m+1 << "," << n+1 << ")";
        return;
    }
};
int main()
{   
    minCostPath ob;
    ob.acceptCost();
    ob.displayMat();
    ob.findMinCost();
    ob.Path();
    return 0;
}
