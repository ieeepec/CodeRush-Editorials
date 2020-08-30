#include<bits/stdc++.h>
using namespace std;

int maxHappiness(int a[],int b[],int n , int R);
int main (){
	int t;
	cin>>t;
	while(t--){
		int n,R;
		cin>>n>>R;
		int *a=new int[n];
		int *b=new int[n];
		
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i];
		}
		cout<<maxHappiness(a,b,n,R)<<endl;
	}
}
int maxHappiness(int a[], int b[], int n, int R)
{
	priority_queue<pair<int,int> > q;
    for(int i=0;i<n;i++){
        q.push(make_pair(a[i],b[i]));
    }
    int money=R;
    int ans=0;
    while(money--){
        int pas=q.top().first;
        int sub=q.top().second;
        q.pop();
        ans+=max(0,pas)%998244353;
        int ele=pas-sub;
        q.push(make_pair(ele,sub));
    }
    return ans;
}
