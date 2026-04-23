#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#pragma warning(disable:4996)
#define INF 2147483647

using namespace std;

int ans=0,ans0=0,ans1=0;

typedef pair<int,int> intint;

typedef pair<long long,int> longint;

vector<longint>arr;
vector<longint>brr;

vector<longint>arr0;//+
vector<longint>arr1;//-

vector<longint>brr0;//+
vector<longint>brr1;//-

void settinga(int p,longint ns){
	//ns.f>=0->0,<0->1
	//ns에 아무것도 안들어가는건 나중에 고려해봐야
	//겠당
	if(p>=arr.size()){
		if(ns.first>0)arr0.push_back(ns);
		else if(ns.first<0)arr1.push_back(ns);
		if(ns.first==0){
			ans0=max(ans0,ns.second);
		}
		return;
	}
	settinga(p+1,ns);
	ns.first+=arr[p].first;
	ns.second+=arr[p].second;
	settinga(p+1,ns);
}

void settingb(int p,longint ns){
	//ns.f>=0->0,<0->1
	//ns에 아무것도 안들어가는건 나중에 고려해봐야
	//겠당
	if(p>=brr.size()){
		if(ns.first>0)brr0.push_back(ns);
		else if(ns.first<0)brr1.push_back(ns);
		if(ns.first==0){
			ans1=max(ans1,ns.second);
		}
		return;
	}
	settingb(p+1,ns);
	ns.first+=brr[p].first;
	ns.second+=brr[p].second;
	settingb(p+1,ns);
}

bool cmp0(longint a,longint b){//내림차순
	if(a.first!=b.first)return a.first>b.first;
	else return a.second<b.second;
}

bool cmp1(longint a,longint b){//오름차순
	if(a.first!=b.first)return a.first<b.first;
	else return a.second<b.second;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	string w;
	for(int i=0;i<n;i++){
		cin>>w;
		long long tp=pow(2,40);
		long long sum=0;
		bool dividing=false;
		for(int j=0;j<w.size();j++){
			if(w[j]=='B')sum+=1*tp;
			else sum-=1*tp;
			if(j<w.size()-1&&w[j]!=w[j+1])dividing=true;
			if(dividing)tp/=2;
		}
		if(i<n/2)arr.push_back({sum,w.size()});
		else brr.push_back({sum,w.size()});
		//cout<<sum<<"\n";
	}
	if(arr.size()>20||brr.size()>20)return -1;
	settinga(0,{0,0});
	settingb(0,{0,0});
	ans=ans0+ans1;
	//내림차순 정렬
	sort(arr0.begin(),arr0.end(),cmp0);
	sort(brr0.begin(),brr0.end(),cmp0);
	
	//오름차순 정렬
	sort(arr1.begin(),arr1.end(),cmp1);
	sort(brr1.begin(),brr1.end(),cmp1);
	
	//같은 수 걸러내기
	for(int i=0;i<int(arr0.size())-1;i++){
		if(arr0[i].first==arr0[i+1].first)arr0[i].second=-1;
	}
	for(int i=0;i<int(arr1.size())-1;i++){
		if(arr1[i].first==arr1[i+1].first)arr1[i].second=-1;
	}
	for(int i=0;i<int(brr0.size())-1;i++){
		if(brr0[i].first==brr0[i+1].first)brr0[i].second=-1;
	}
	for(int i=0;i<int(brr1.size())-1;i++){
		if(brr1[i].first==brr1[i+1].first)brr1[i].second=-1;
	}
	
	//cout<<arr0.size()<<","<<arr1.size()<<"\n";
	//cout<<brr0.size()<<","<<brr1.size()<<"\n";
	
	//Meet-in-the-middle 알고리즘 이용
	//arr0&brr1
	int p1=0,p2=0;
	while((p1<arr0.size())&&(p2<brr1.size())){
		if(arr0[p1].second==-1){
			p1++;
			continue;
		}
		if(brr1[p2].second==-1){
			p2++;
			continue;
		}
		long long sum=arr0[p1].first+brr1[p2].first;
		int sumc=arr0[p1].second+brr1[p2].second;
		if(sum==0){
			ans=max(ans,sumc);
		}
		if(sum>=0)p1++;
		else p2++;
	}
	
	//arr1&brr0
	p1=0;p2=0;
	while((p1<arr1.size())&&(p2<brr0.size())){
		if(arr1[p1].second==-1){
			p1++;
			continue;
		}
		if(brr0[p2].second==-1){
			p2++;
			continue;
		}
		long long sum=arr1[p1].first+brr0[p2].first;
		int sumc=arr1[p1].second+brr0[p2].second;
		if(sum==0){
			ans=max(ans,sumc);
		}
		if(sum>=0)p2++;
		else p1++;
	}
	
	cout<<ans;
}