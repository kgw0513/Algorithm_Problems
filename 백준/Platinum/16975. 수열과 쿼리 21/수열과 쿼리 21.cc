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

struct tree_Node{
    ll rem_need_plus_num=0;
    ll Node_sum=0;
    tree_Node* left_Node=nullptr;
    tree_Node* right_Node=nullptr;
    ll make_Node(int s,int e){
        if(s!=e){
            int mid=(s+e)/2;
            left_Node=new tree_Node();
            right_Node=new tree_Node();
            this->Node_sum=left_Node->make_Node(s,mid)+right_Node->make_Node(mid+1,e);
        }
        else cin>>Node_sum;
        
        return this->Node_sum;
    }
    void slow_plus(int s,int e){
        Node_sum+=rem_need_plus_num;
        if(left_Node!=nullptr)left_Node->rem_need_plus_num+=this->rem_need_plus_num;
        if(right_Node!=nullptr)right_Node->rem_need_plus_num+=this->rem_need_plus_num;
        rem_need_plus_num=0;
    }
    ll add_Node(int s,int e,int plus_s,int plus_e,ll &plus_num){
        slow_plus(s,e);
        if(e<plus_s||plus_e<s)return this->Node_sum; //더하고자 하는 범위 밖에 있을때.
        
        if(plus_s<=s&&e<=plus_e){ //더하고자 하는 범위 안에 들어가 있을때.
            //cout<<s<<"~"<<e<<"에:"<<Node_sum<<"+"<<(e-s+1)<<"x"<<plus_num<<"=";
            Node_sum+=(e-s+1)*plus_num;
            //cout<<Node_sum<<"로 변경.\n";
            if(left_Node!=nullptr)left_Node->rem_need_plus_num+=plus_num;
            if(right_Node!=nullptr)right_Node->rem_need_plus_num+=plus_num;
            return this->Node_sum;
        }
        
        //애매하게 걸쳐 있을때.
        int mid=(s+e)/2;
        return Node_sum=left_Node->add_Node(s,mid,plus_s,plus_e,plus_num)+right_Node->add_Node(mid+1,e,plus_s,plus_e,plus_num);
    }
    
    ll sum_Node(int s,int e,int sum_s,int sum_e){
        //cout<<s<<"~"<<e<<":"<<Node_sum<<"/"<<rem_need_plus_num<<"\n";
        slow_plus(s,e);
        if(e<sum_s||sum_e<s)return 0; //구하고자 하는 수가 범위 밖에 있을때.
        
        if(sum_s<=s&&e<=sum_e){ //구하고자 하는 범위 안에 들어가 있을때.
            //cout<<s<<"~"<<e<<"의 "<<Node_sum<<"반환.\n";
            return this->Node_sum;
        }
        
        //애매하게 걸쳐 있을때.
        int mid=(s+e)/2;
        return Node_sum=left_Node->sum_Node(s,mid,sum_s,sum_e)+right_Node->sum_Node(mid+1,e,sum_s,sum_e);
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,t,a,b,c;
	ll d;
	cin>>n;
	tree_Node* set_tree = new tree_Node();
	set_tree->make_Node(1,n);
	cin>>t;
	while(t--){
	    cin>>a;
	    if(a==1){
	        cin>>b>>c>>d;
	        set_tree->add_Node(1,n,b,c,d);
	        continue;
	    }
	    
	    //a==2
	    cin>>b;
	    cout<<set_tree->sum_Node(1,n,b,b)<<"\n";
	}
}