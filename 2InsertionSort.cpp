#include<iostream>
using namespace std;

void selectionSort(int arr[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		int targetIndex = i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[targetIndex]){
				targetIndex = j;
			}
		}
		swap(arr[j],arr[targetIndex]);
	}
}
