#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n){
	int i,j,key;
	
	for(i=1;i<n;i++){
		key = arr[i];
		j=i-1;
		
		while(j>=0 && arr[j]>key){
		arr[j+1] = arr[j];
		j=j-1;
	}
	
	arr[j+1] = key;
		
	}
	
}

void printArr(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
}

int main(){

int arr[] = {50,14,62,90,8};
int n = sizeof(arr) / sizeof(arr[0]);

insertionSort(arr,n);
printArr(arr,n);

return 0;
	
}


