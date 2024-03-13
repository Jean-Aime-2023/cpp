 #include<iostream>
using namespace std;


void selectionSort(int arr[],int n){
	int i,j,targetIndex;
	
	for(i=0;i<n-1;i++){
		targetIndex,i;
		for(j=i+1;j<n;j++){
			while(arr[j]<arr[targetIndex]){
				targetIndex = j;
			}
		}
		
		swap(arr[j],arr[targetIndex]);
	}
}


