#include<iostream>
using namespace std;

class Sort {
private:
	int* arr;
	int l;
public:
    void SelectionSort();
    void display();
	int* input();
};

void Sort::SelectionSort() {
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            if(arr[j]>arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j]=temp;
            }
        }
    }
}
int* Sort::input(){
	cout << "Enter the size of the array: ";
    cin >> l;
    cout << "Enter " << l << " array elements: ";
	 arr = new int[l];
	for(int i=0;i<l;i++){
		cin>>arr[i];
	}
	return arr;
}
void Sort::display() {
    cout << "The Sorted array is: ";
    for (int i = 0; i < l; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Sort ob;
	ob.input();
    ob.SelectionSort();
    ob.display();

    return 0;
}
