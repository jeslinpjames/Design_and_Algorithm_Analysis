#include<iostream>
using namespace std;

class Sort {
private:
	int* arr;
	int l;
public:
    int* BubbleSort();
    void display();
	int* input();
};

int* Sort::BubbleSort() {
    for (int i = 0; i < l - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < l - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;  
    }
    return arr;
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
    int* sortedArray = ob.BubbleSort();
    ob.display();

    return 0;
}
