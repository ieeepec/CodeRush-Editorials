#include<bits/stdc++.h>
using namespace std;

int ans(int arr[]);

int main(){
	int t;
	cin>>t;
	while(t--){
		int n=11;
		int arr[11];
		for(int i=0;i<n;i++)
		cin>>arr[i];
		cout<<ans(arr)<<endl;
	}
}
int ans(int arr[]){
	int n=11;
	sort(arr,arr+n);
	int s;
	s=arr[9];
	return s;
}

