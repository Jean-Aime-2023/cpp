#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
	int i,j,key;
	for(i=1;i<n;i++){
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j = j-1;
		}	
		arr[j+1] = key;
	}
}

void selectionSort(int arr[],int n){
	int i,j,targetIndex;
	for(i=0;i<n-1;i++){
		targetIndex = i;
		for(j=i+1;j<n;j++){
			if(arr[j]>arr[targetIndex]){
				targetIndex = j;
			}
		}
		swap(arr[j],arr[targetIndex]);
	}
}

void mergeSort(int a[] , int s , int e){
	if(s>=e){
		return;
	}
	
	int mid = (s+e)/2;
	int x[100],int y[100];
	
	for(int i=s; i<mid;i++){
		x[i] = a[i];
	}	
	for(int i=mid+1; i<e;i++){
		y[i] = a[i];
	}
	
	mergeSort(x,s,mid);
	mergeSort(y,mid+1,e);
	mergeArrays(x,y,a,s,e);
}

void mergeArrays(int x[] ,int y[] , int a[] ,int s, e){
	int mid = (s+e)/2;
	int i = s;
	int k = s;
	int j = mid + 1;
	
	while(i<=mid && j<=e){
		if(x[i]>y[i]){
			a[k] = x[i];
			i++;
			k++;
		}else{
			a[k] = y[i];
			i++;
			k++;
		}
	}
	
	while(i<=mid){
		a[k] = x[i];
			i++;
			k++;
	}
	
	while(j<=e){
		a[k] = y[i];
			i++;
			k++;
	}
}
