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
#include <bitset>
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
typedef pair<intint,intint> int2_int2;
typedef pair<int2_int2,string> int22_s;
typedef pair<int,char> int_char;

set<string>arr;
queue<string>brr;
queue<string>crr;

bool check[10];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string start_num="";
    string w;
    for(int i=0;i<9;i++){
        cin>>w;
        if(check[w[0]-'0'])return -1;
        check[w[0]-'0']=true;
        start_num+=w;
    }
    brr.push(start_num);
    int timer=-1;
    while(brr.size()){
        int size=brr.size();
        timer++;
        while(size--){
            int zero_p=8;
            string now_num=brr.front();
            brr.pop();
            if(arr.find(now_num)!=arr.end())continue;
            arr.insert(now_num);
            if(now_num=="123456780"){
                cout<<timer;
                return 0;
            }
            for(int i=0;i<8;i++){
                if(now_num[i]=='0'){
                    zero_p=i;
                    break;
                }
            }
            
            if(zero_p%3!=0){
                string copy_num=now_num;
                swap(copy_num[zero_p-1],copy_num[zero_p]);
                brr.push(copy_num);
            }
            if(zero_p>=3){
                string copy_num=now_num;
                swap(copy_num[zero_p-3],copy_num[zero_p]);
                brr.push(copy_num);
            }
            if(zero_p%3!=2){
                string copy_num=now_num;
                swap(copy_num[zero_p+1],copy_num[zero_p]);
                brr.push(copy_num);
            }
            if(zero_p<=5){
                string copy_num=now_num;
                swap(copy_num[zero_p+3],copy_num[zero_p]);
                brr.push(copy_num);
            }
        }
    }
    cout<<-1;
}