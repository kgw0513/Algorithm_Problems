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
#define nINF -1000000000
#define INF 1000000000

using namespace std;

class Node{
	public:
	int s,e,t;
};
bool input(){
	int n,m,w,s,e,t;
	bool sstart[501]={};
	bool usednum[501]={};
	vector<Node*>arr;
	cin>>n>>m>>w;
	while(m--){
		Node* makeNode=new Node();
		Node* makeNode2=new Node();
		cin>>s>>e>>t;
		sstart[s]=true;
		sstart[e]=true;
		makeNode->s=s;
		makeNode->e=e;
		makeNode->t=t;
		arr.push_back(makeNode);
		makeNode2->s=e;
		makeNode2->e=s;
		makeNode2->t=t;
		arr.push_back(makeNode2);
	}
	while(w--){
		Node* makeNode=new Node();
		cin>>s>>e>>t;
		sstart[s]=true;
		makeNode->s=s;
		makeNode->e=e;
		makeNode->t=t*-1;
		arr.push_back(makeNode);
	}
	for(int k=1;k<=n;k++){
		if(sstart[k]==false)continue;
		if(usednum[k])continue;
		int wormhole[501]={};
		for(int i=1;i<=n-1;i++){
			for(int j=0;j<arr.size();j++){
				s=arr[j]->s;e=arr[j]->e;t=arr[j]->t;
				if(wormhole[s]==INF)continue;
				wormhole[e]=min(wormhole[e],wormhole[s]+t);
			}
		}
		for(int i=0;i<arr.size();i++){
			s=arr[i]->s;e=arr[i]->e;t=arr[i]->t;
			if(wormhole[s]==INF)continue;
			if(wormhole[e]>wormhole[s]+t){
				while(arr.size()){
					free(arr.back());
					arr.pop_back();
				}
				return true;
			}
		}
		for(int i=1;i<=n;i++){
			if(wormhole[i]!=INF)usednum[i]=true;
		}
	}
	while(arr.size()){
					free(arr.back());
					arr.pop_back();
				}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int nt;
	cin>>nt;
	while(nt--){
		if(input())cout<<"YES\n";
		else cout<<"NO\n";
	}
}