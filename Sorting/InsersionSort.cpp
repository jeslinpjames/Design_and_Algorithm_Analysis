#include<iostream>
using namespace std;

class Sort {
private:
	int* arr;
	int l;
public:
    void InsersionSort();
    void display();
	int* input();
};

void Sort::InsersionSort() {
    for(int i=1;i<l;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    ob.InsersionSort();
    ob.display();

    return 0;
}
