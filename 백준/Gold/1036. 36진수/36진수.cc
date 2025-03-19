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

int sum1[54]={},sum2[54]={};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	vector<string>arr;
	queue<string>brr;
	queue<string>crr;
	queue<string>drr;
	string w;
	//cin>>w;
	cin>>n;
	while(n--){
	    cin>>w;
	    arr.push_back(w);
	}
	cin>>n;
	string make;
	while(n--){
	    //cout<<"=================\n";
	    for(int j=0;j<=53;j++){
	            sum1[j]=0;
	        }
	    for(int i=0;i<=9;i++){
	        while(crr.size()){
	               crr.pop();
	       }
	        for(int j=0;j<=53;j++){
	            sum2[j]=0;
	        }
	        for(int j=0;j<arr.size();j++){
	            make="";
	            for(int k=0;k<arr[j].size();k++){
	                if(arr[j][k]==char('0'+i))make+='Z';
	                else make+=arr[j][k];
	            }
	            brr.push(make);
	            crr.push(make);
	            //cout<<make<<"\n";
	        }
	        while(brr.size()){
	            for(int j=0;j<brr.front().size();j++){
	                if('0'<=brr.front()[j]&&brr.front()[j]<='9')sum2[brr.front().size()-j-1]+=brr.front()[j]-'0';
	                else sum2[brr.front().size()-j-1]+=brr.front()[j]-'A'+10;
	            }
	            brr.pop();
	        }
	        for(int j=0;j<53;j++){
	            sum2[j+1]+=sum2[j]/36;
	            sum2[j]%=36;
	        }
	        for(int j=53;j>=0;j--){
	            if(sum1[j]<sum2[j]){
	                //cout<<i<<","<<j<<"에서\n";
	                //cout<<sum1[j]<<","<<sum2[j]<<"\n";
	                for(int k=53;k>=0;k--){
	                    sum1[k]=sum2[k];
	                }
	                while(drr.size()){
	                    drr.pop();
	                }
	                while(crr.size()){
	                    //cout<<crr.front()<<"됨.\n";
	                    drr.push(crr.front());
	                    crr.pop();
	                }
	                break;
	            }
	            if(sum1[j]>sum2[j])break;
	        }
	    }
	    for(int i=0;i<=25;i++){
	        while(crr.size()){
	               crr.pop();
	       }
	        for(int j=0;j<=53;j++){
	            sum2[j]=0;
	        }
	        for(int j=0;j<arr.size();j++){
	            make="";
	            for(int k=0;k<arr[j].size();k++){
	                if(arr[j][k]==char('A'+i))make+='Z';
	                else make+=arr[j][k];
	            }
	            brr.push(make);
	            crr.push(make);
	        }
	        while(brr.size()){
	            for(int j=0;j<brr.front().size();j++){
	                if('0'<=brr.front()[j]&&brr.front()[j]<='9')sum2[brr.front().size()-j-1]+=brr.front()[j]-'0';
	                else sum2[brr.front().size()-j-1]+=brr.front()[j]-'A'+10;
	            }
	            brr.pop();
	        }
	        for(int j=0;j<53;j++){
	            sum2[j+1]+=sum2[j]/36;
	            sum2[j]%=36;
	        }
	        for(int j=53;j>=0;j--){
	            if(sum1[j]<sum2[j]){
	                //cout<<i+10<<"입장.\n";
	                for(int k=53;k>=0;k--){
	                    sum1[k]=sum2[k];
	                }
	                while(drr.size()){
	                    drr.pop();
	                }
	                while(crr.size()){
	                    drr.push(crr.front());
	                    crr.pop();
	                }
	                break;
	            }
	            if(sum1[j]>sum2[j])break;
	        }
	    }
	    if(drr.size()==0)break;
	    while(arr.size()){
	        arr.pop_back();
	    }
	    while(drr.size()){
	        //cout<<drr.front()<<"로 전환.\n";
	        arr.push_back(drr.front());
	        drr.pop();
	    }
	}
	for(int j=0;j<=53;j++){
	   sum1[j]=0;
	}
	while(arr.size()){
	    brr.push(arr.back());
	    arr.pop_back();
	}
	while(brr.size()){
	            for(int j=0;j<brr.front().size();j++){
	                if('0'<=brr.front()[j]&&brr.front()[j]<='9')sum1[brr.front().size()-j-1]+=brr.front()[j]-'0';
	                else sum1[brr.front().size()-j-1]+=brr.front()[j]-'A'+10;
	            }
	            brr.pop();
	        }
	   for(int j=0;j<53;j++){
	            sum1[j+1]+=sum1[j]/36;
	            sum1[j]%=36;
	        }
	/*
	for(int i=53;i>=0;i--){
	    cout<<sum1[i]<<",";
	}
	cout<<"\n";
	*/
	
	n=0;
	for(int i=53;i>=0;i--){
	    if(sum1[i]==0){
	        if(n==0){
	            if(i==0)cout<<0;
	        }
	        else cout<<0;
	    }
	    else{
	        n=1;
	        if(0<=sum1[i]&&sum1[i]<=9){
	            cout<<sum1[i];
	        }
	        else cout<<char(sum1[i]-10+'A');
	    }
	}
}