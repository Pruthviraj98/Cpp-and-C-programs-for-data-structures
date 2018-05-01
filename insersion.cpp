#include<iostream>
#include<stdlib.h>

using namespace std;
/*void insertion(int *a, int n){

int t, j;	
	for(int i=1;i<=n-1;i++){
		t=a[i];
		j=i-1;
		cout<<"\n current t:"<<t<<"\n";
		while(t<=a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=t;
		cout<<"\n current aj+1:"<<a[j+1]<<"\n";

	}
}
*/
int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	//int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	//insertion(a, n);
	int t,j;
	for(int i=1;i<=n-1;i++){
		t=a[i];
		j=i-1;
		cout<<"\n current t:"<<t<<"\n";
		while(t<=a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=t;
		cout<<"\n current aj+1:"<<a[j+1]<<"\n";
	}
	for(int j=0;j<n;j++){
		cout<<a[j]<<"\n";
	}
	delete [] a;
}
