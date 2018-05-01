#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	int t, j;
	for(int i=1;i<n;i++){
		t=a[i];
		j=i-1;
		while(t<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=t;
	}

	for(int i=0;i<n;i++){
		cout<<a[i];
	}
}
