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
    for(int i=0;i<l-1;i++){
        int min =i;
        for(int j=i+1;j<l;j++){
            if(arr[j]<arr[min]){
              min =j;
            }
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
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
