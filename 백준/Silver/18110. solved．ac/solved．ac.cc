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
const int not_flow_INF=100000000;

typedef pair<int,int> intint;
typedef pair<intint,int> int2_int;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,w;
    vector<int>arr;
    cin>>n;
    if(n==0){
        cout<<0;
        return 0;
    }
    double h_p=double(15*n)/100;
    int cut_p=h_p-int(h_p)<0.5?int(h_p):int(h_p)+1;
    //cout<<h_p<<" "<<cut_p<<"\n";
    for(int i=0;i<n;i++){
        cin>>w;
        arr.push_back(w);
    }
    sort(arr.begin(),arr.end());
    h_p=0;
    for(int i=cut_p;i<arr.size()-cut_p;i++){
        h_p+=arr[i];
    }
    h_p/=n-2*cut_p;
    cut_p=h_p-int(h_p)<0.5?int(h_p):int(h_p)+1;
    cout<<cut_p;
}