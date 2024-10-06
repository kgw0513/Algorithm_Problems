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
const int nINF=10000000;

typedef long long ll;
typedef pair<int,int> intint;
typedef pair<int,ll> intlong;
typedef pair<intint,int> int2_int;

int arr[100000];
int have_num[1000001];
int sqrt_N;
int cout_ans[100000];
intint Q_insert[100000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int2_int>Q_sort;
	int n,a,b,w,Q;
	cin>>n;
	sqrt_N=sqrt(n);
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	cin>>Q;
	for(int i=0;i<Q;i++){
	    cin>>a>>b;
	    Q_insert[i]={a,b};
	    Q_sort.push_back({{(a-1)/sqrt_N,b-1},i});
	}
	sort(Q_sort.begin(),Q_sort.end());
	int last_s=-1,last_e=-1;
	int ans_counting=0;
	for(int i=0;i<Q_sort.size();i++){
	    int ans_num=Q_sort[i].s;
	    //cout<<"위치:"<<ans_num<<"\n";
	    a=Q_insert[ans_num].f-1;
	    b=Q_insert[ans_num].s-1;
	    //cout<<a<<","<<b<<"에서.\n";
	    if(last_s==-1){
	        for(int i=a;i<=b;i++){
	            w=arr[i];
    	        if(have_num[w]==0)ans_counting++;
    	        have_num[w]++;
    	        //cout<<i<<":"<<w<<"\n";
	        }
	        last_s=a;
    	    last_e=b;
    	    cout_ans[ans_num]=ans_counting;
	        continue;
	    }
	    if(a>=last_s){
	        for(int i=last_s;i<a;i++){
    	        w=arr[i];
    	        if(have_num[w]==1)ans_counting--;
    	        have_num[w]--;
    	    }
	    }
	    else{
	        for(int i=a;i<last_s;i++){
    	        w=arr[i];
    	        if(have_num[w]==0)ans_counting++;
    	        have_num[w]++;
    	    }
	    }
	    
	    if(b>=last_e){
	        for(int i=last_e+1;i<=b;i++){
    	        w=arr[i];
    	        if(have_num[w]==0)ans_counting++;
    	        have_num[w]++;
    	    }
	    }
	    else{
	        for(int i=b+1;i<=last_e;i++){
    	        w=arr[i];
    	        if(have_num[w]==1)ans_counting--;
    	        have_num[w]--;
    	    }
	    }
	    last_s=a;
	    last_e=b;
	    
	    cout_ans[ans_num]=ans_counting;
	}
	for(int i=0;i<Q;i++){
	    cout<<cout_ans[i]<<"\n";
	}
}