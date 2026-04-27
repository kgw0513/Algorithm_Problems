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
#define f first
#define s second
using namespace std;

const int INF=2147483647;

typedef pair<int,int> intint;
typedef pair<intint,int> int2_int;
typedef long long ll;

ll fenwick_tree[30001];

void add_fenwick(int now_t,ll sum_n){
	//cout<<now_t<<"/"<<sum_n<<"작동.\n";
	while(now_t<=30000){
		fenwick_tree[now_t]+=sum_n;
		now_t+=now_t&-now_t;
	}
}
ll sum_fenwick(int now_t){
	ll ans=0;
	while(now_t>0){
		ans+=fenwick_tree[now_t];
		now_t-=now_t&-now_t;
	}
	return ans;
}
void make_hackenbush(int n,int m,int &now_t){
	if(n>40||m>40){
		cout<<"map size error\n";
		exit(-1);
	}
    char set_map[40][40]={};
	int count_A=0;
	int count_B=0;
	int in_count=0;
	int out_count=0;
	intint last_P_A,last_P_B;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>set_map[i][j];
			if(set_map[i][j]=='A'){
				last_P_A={i,j};
				count_A++;
			}
			else if(set_map[i][j]=='B'){
				last_P_B={i,j};
				count_B++;
			}
		}
	}
	bool free_boom=false;
	
	if(count_A!=1&&count_B!=1){
		//나올 수가 없음.
		cout<<"count Error\n";
		exit(-1);
	}
	
	//cout<<now_t<<" : "<<count_A<<" vs "<<count_B<<"/";
	
	int sum_count_map[40][40]={};
	if(count_B==1){
		//cout<<"B\n";
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<m;j++){
			    if(i+1!=n)sum_count_map[i][j]+=sum_count_map[i+1][j];
			    if(j!=0)sum_count_map[i][j]+=sum_count_map[i][j-1];
			    if(i+1!=n&&j!=0)sum_count_map[i][j]-=sum_count_map[i+1][j-1];
				if(set_map[i][j]=='A')sum_count_map[i][j]++;
				else continue;
				
				//cout<<i<<","<<j<<"입성.\n";
				if(i>=last_P_B.f&&j<=last_P_B.s){
					in_count++;
					continue;
				}
				out_count++;
			}
		}
		
		for(int i=last_P_B.f;i>=0;i--){
		    for(int j=last_P_B.s;j<m;j++){
		        if(set_map[i][j]!='A')continue;
		        if(sum_count_map[i][j]==1+in_count){
		            free_boom=true;
		            break;
		        }
		    }
		}
		ll check_n=(1LL<<40)*out_count-(1LL<<(40-in_count-free_boom));
		//cout<<in_count<<" / "<<out_count<<"=>\n";
		//cout<<check_n<<"\n";
		add_fenwick(now_t,check_n);
		return;
	}
	
	
	if(count_A==1){
		//cout<<"A\n";
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<m;j++){
			    if(i+1!=n)sum_count_map[i][j]+=sum_count_map[i+1][j];
			    if(j!=0)sum_count_map[i][j]+=sum_count_map[i][j-1];
			    if(i+1!=n&&j!=0)sum_count_map[i][j]-=sum_count_map[i+1][j-1];
				if(set_map[i][j]=='B')sum_count_map[i][j]++;
				else continue;
				
				//cout<<i<<","<<j<<"입성.\n";
				if(i>=last_P_A.f&&j<=last_P_A.s){
					in_count++;
					continue;
				}
				out_count++;
			}
		}
		
		for(int i=last_P_A.f;i>=0;i--){
		    for(int j=last_P_A.s;j<m;j++){
		        if(set_map[i][j]!='B')continue;
		        if(sum_count_map[i][j]==1+in_count){
		            free_boom=true;
		            break;
		        }
		    }
		}
		ll check_n=(1LL<<40)*out_count-(1LL<<(40-in_count-free_boom));
        check_n*=-1;
		//cout<<in_count<<" / "<<out_count<<"=>\n";
		//cout<<check_n<<"\n";
		add_fenwick(now_t,check_n);
		return;
	}
	
	cout<<"Unknown Runtime error\n";
	exit(-1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,t2,a,b,c;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,m;
		cin>>n>>m;
		make_hackenbush(n,m,i);
		//cout<<sum_fenwick(i)-sum_fenwick(i-1)<<"...\n";
	}
	//return 0;
	cin>>t2;
	while(t2--){
		cin>>a>>b>>c;
		/*
		for(int i=1;i<=t;i++){
			cout<<sum_fenwick(i)-sum_fenwick(i-1)<<" ";
		}
		*/
		//cout<<"컷\n";
		ll change_n=sum_fenwick(a)-sum_fenwick(a-1);
		//cout<<"ch:"<<change_n<<"\n\n";
        change_n*=-2;
		add_fenwick(a,change_n);
		ll ans_n=sum_fenwick(c)-sum_fenwick(b-1);
		if(ans_n<=0)cout<<"Bagus\n";
		else cout<<"Ahgus\n";
	}
}