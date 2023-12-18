#include<iostream>
using namespace std;
class KnapsackProblem{
	private:
		int * weights;
		int * values;
		int capacity;
		int items;
	public:
		void input(){
			cout<<"Enter the number of items : ";
			cin>> items;
			weights = new int [items];
			values = new int [items];
			cout << "Enter the weights of the items: ";
			for (int i = 0; i < items; ++i)
			{
				cin >> weights[i];
			}
			cout << "Enter the values of the items : ";
			for (int i = 0; i < items; ++i)
			{
				cin >> values[i];
			}
			cout<<"Enter the capacity : ";
			cin>>capacity;
		}
		void findSolution(){
			int ** matrix = new int *[items+1];
			for(int i =0;i<= items;i++){
				matrix[i]= new int[capacity+1];
			}
			for (int i =0;i<=items;i++){
				for(int j =0;j<=capacity;j++){
					if((i==0)||(j==0)){
						matrix[i][j] = 0;
					}
					else if (j-weights[i-1]<0){
						matrix[i][j]=matrix[i-1][j];
					}
					else {
						matrix[i][j] = max (matrix[i-1][j],(values[i-1]+matrix[i-1][j-weights[i-1]]));
					}
				}
			}
			cout<<"Max profit for the capacity is : "<<matrix[items][capacity]<<endl;
			int selected [items];
			int Count=0;
			int i =items;
			int j = capacity;
			while(i>0 && j>0){
				if (matrix[i][j]!=matrix[i-1][j]){
					selected[Count++]=i;
					j -= weights[i - 1];
            		i--;
				}
				else{
					i--;
				}
			}
			cout<<"Weights of selected items : ";
			for(int i= Count-1;i>=0;i--){
				cout<<selected[i]+1<<" ";
			}
		}
};
int main(){
	KnapsackProblem ob;
	ob.input();
	ob.findSolution();
	cout<<endl;
	return 0;
}