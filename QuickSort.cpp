#include<iostream>
using namespace std;

class Sort {
private:
	int* arr;
	int l;
public:
    void QuickSort( int lowm , int high);
    int partition( int low, int high);
    void display();
	int* input();
    int getLength(){
        return l;
    }
};

void Sort::QuickSort(int low ,int high) {
    if(low<high){
        int pi = partition(low,high);
        QuickSort(low, pi-1);
        QuickSort(pi+1,high);
    }    
}
int Sort::partition(int low,int high){
    int pivot = arr[high];
    int i = low -1;
    for(int j=low;j<high;j++){
        if(arr[j]>pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
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
    int l = ob.getLength();
    ob.QuickSort(0,l);
    ob.display();

    return 0;
}

