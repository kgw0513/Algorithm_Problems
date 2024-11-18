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

short nimone[501];//chess one
short nimtwo[501][501];//chess two
bool checkroute[501][501];
vector<short>arr[501];//route
bool horse[501][501];//horse[position][color]=1;

short dfs(short onep,short twop){
	if(onep==twop)twop=-1;
	if(onep==-1){
		for(int error=1;error<=1000000;error++){
			cout<<"error\n";
		}
		exit(0);
	}
	if(twop==-1){
		if(nimone[onep]!=-1)return nimone[onep];
		bool nim[651]={};
		for(int i=0;i<arr[onep].size();i++){
			//cout<<arr[onep][i]<<"들감.\n";
			nim[dfs(arr[onep][i],-1)]=true;
		}
		for(int i=0;i<=650;i++){
			if(!nim[i]){
				nimone[onep]=i;
				break;
			}
		}
		if(nimone[onep]<=-1)exit(-1);
		return nimone[onep];
	}
	else{
		if(nimtwo[onep][twop]!=-1)return nimtwo[onep][twop];
		bool nim[651]={};
		for(int i=0;i<arr[onep].size();i++){
			nim[dfs(arr[onep][i],twop)]=true;
		}
		for(int i=0;i<arr[twop].size();i++){
			nim[dfs(onep,arr[twop][i])]=true;
		}
		for(int i=0;i<=650;i++){
			if(!nim[i]){
				nimtwo[onep][twop]=i;
				break;
			}
		}
		if(nimtwo[onep][twop]==-1)exit(-1);
		return nimtwo[onep][twop];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i=1;i<=500;i++){
		nimone[i]=-1;
		for(int j=1;j<=500;j++){
			nimtwo[i][j]=-1;
		}
	}
	int n,m,p,q;
	cin>>n>>m;
	while(m--){
		cin>>p>>q;
		if(!checkroute[p][q]){
			checkroute[p][q]=1;
			arr[p].push_back(q);//p->q
		}
	}
	cin>>m;//horse count
	while(m--){
		cin>>p>>q;
		horse[p][q]=1;
	}
	int sum=0;
	for(int i=1;i<=n;i++){//1부터 n까지 색 확인 후 계산
		int onep=-1,twop=-1;
		for(int j=1;j<=n;j++){
			if(horse[j][i]){
				if(onep==-1)onep=j;
				else if(twop==-1)twop=j;
				else {
					for(int error=1;error<=1000000;error++){
						cout<<"error\n";
					}
					return 0;
				}
			}
		}
		if(onep!=-1){
			int rem=dfs(onep,twop);
			sum^=rem;
			//cout<<onep<<","<<twop<<"=>"<<rem<<"/"<<sum<<"\n";
		}
	}
	if(sum==0)cout<<"Cheol";
	else cout<<"Young";
}