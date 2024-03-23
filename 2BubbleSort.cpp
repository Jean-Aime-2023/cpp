#include<iostream>
using namespace std;

void swap(int &a , int &b){
	int temp = a;
	a = b ;
	b=temp;
}

void bubbleSort(int arr[],int n){
	int i,j;
	for(i = 0 ; i<n-1 ; ++i){
		for(j = 0 ; j<n-i-1 ; ++j){
			if(arr[j] > arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
	}
}}


int main(){
	
	int arr[] = {62,69,70,68,65,54};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	bubbleSort(arr,n);
	
	cout<<"The Sorted array is : " << endl;
	
	int i;
	
	for(i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}

	return 0;
}
