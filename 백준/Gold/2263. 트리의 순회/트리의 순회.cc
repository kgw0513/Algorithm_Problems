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

int INF=2147483647;

typedef pair<int,int> intint;
typedef long long ll;

struct Node{
    int num=-1;
    int nump=-1;
    Node* leftNode=nullptr;
    Node* rightNode=nullptr;
};
Node* inorder[100002]={};
int position[100002]={};
bool insert[100002]={};
int Find(int p){
    if(inorder[p]->num!=inorder[p]->nump){
        return inorder[p]->num=Find(position[inorder[p]->num]);
    }
    else return inorder[p]->num;
}
void freeorder(Node* nowNode){
    cout<<nowNode->nump<<" ";
    /*
    //2차 검수용
    cout<<nowNode->nump<<"=>";
    cout<<"왼쪽 :";
    if(nowNode->leftNode!=nullptr)cout<<nowNode->leftNode->nump;
    else cout<<"X";
    
    cout<<" 오른쪽 :";
    if(nowNode->rightNode!=nullptr)cout<<nowNode->rightNode->nump;
    else cout<<"X";
    
    cout<<endl;
    */
    if(nowNode->leftNode!=nullptr)freeorder(nowNode->leftNode);
    if(nowNode->rightNode!=nullptr)freeorder(nowNode->rightNode);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,w;
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>w;
	    Node* makeNode=new Node();
	    makeNode->num=w;
	    makeNode->nump=w;
	    inorder[i]=makeNode;
	    position[w]=i;
	}
	for(int i=1;i<=n;i++){
	    cin>>w;
	    w=position[w];
	    insert[w]=true;
	    //cout<<w<<":\n";
	    if(insert[w-1]){
	        Find(w-1);
	        inorder[w]->leftNode=inorder[position[inorder[w-1]->num]];
	        //cout<<inorder[w]->nump<<"->"<<inorder[w]->leftNode->nump<<" 좌.\n";
	        inorder[position[inorder[w-1]->num]]->num=inorder[w]->num;
	    }
	    if(insert[w+1]){
	        Find(w+1);
	        inorder[w]->rightNode=inorder[position[inorder[w+1]->num]];
	        //cout<<inorder[w]->nump<<"->"<<inorder[w]->rightNode->nump<<" 우.\n";
	        inorder[position[inorder[w+1]->num]]->num=inorder[w]->num;
	    }
	    /*
	    //검수용
	    for(int j=1;j<=n;j++){
	        cout<<insert[j]<<" ";
	    }
	    cout<<"\n";
	    for(int j=1;j<=n;j++){
	        cout<<inorder[j]->num<<" ";
	    }
	    cout<<"\n";
	    for(int j=1;j<=n;j++){
	        cout<<inorder[j]->nump<<" ";
	    }
	    cout<<"\n\n";
	    */
	}
	freeorder(inorder[w]);
}