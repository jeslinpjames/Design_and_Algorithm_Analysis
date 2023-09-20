#include<iostream>
using namespace std;
int Search(int arr[],int l,int nts){
	int i =0;
	for(i=0;i<l;i++){
		if(arr[i]==nts)
			return i;
		else
			i++;
	}
	return -1;
}
int main(){
	cout<<"Enter the number of elemenets in the array :";
	int n;
	cin>> n;
	cout<<"Enter the elements of the Array : ";
	int* arr = new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter the element to be Searched : ";
	int nts;
	cin>>nts;
	int pos =Search(arr,n,nts);
	if(pos == -1)
		cout<<"Element not present in the array!"<<endl;
	else
		cout<<"Element is present in index "<<pos<<endl;
	return 0;
}
