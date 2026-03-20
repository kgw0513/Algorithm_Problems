#include <iostream> //힘들고 뒷부분은 이제 거의 구현문제 뿐이라서
#include <algorithm>//여기서 탈주하겠습니다.
#include <string>   //문제가 별로란 뜻은 아니고
#include <vector>   //모든 문제가 저가 생각한것 보다 맘에 들었습니다.
#include <queue>    //운영진분들 파이팅 입니다.
#include <deque>    //이 글을 읽을진 모르겠지만
#include <stack>    //봤으면 따봉~
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

struct Node{
    Node* next_Node=nullptr;
    int state=0;
    Node(int give_state):state(give_state){}
    //0->땅,1->황금열쇠,2->시작
    //3->무인도,4->사회복지,5->우주여행,6->땅 소유
    int land_cost=0;//0번 전용
    
    int get_money=0;//4번 전용.
};

queue<intint>gold_card;
Node* social_Node=nullptr;

struct Player{
    Node* now_position=nullptr;
    int have_dice=0;
    int start_pay;
    int player_money;
    
    Player(Node* a,int b,int c):now_position(a),player_money(b)
    ,start_pay(c){}
    
    void go_place(int have_num){
        while(have_num--){
            now_position=now_position->next_Node;
            if(now_position->state==2){
                player_money+=start_pay;
            }
        }
    }
    
    void buy_land(){
        if(now_position->land_cost<=player_money){
            player_money-=now_position->land_cost;
            now_position->state=6;
        }
    }
    
    void escape_island(){
        int escape_count=3;
        while(escape_count--&&have_dice--){
            int a,b;
            cin>>a>>b;
            if(a==b)break;
            if(have_dice==0){
                return;
            }
        }
        have_dice++;
    }
    
    void help_social(){
        player_money+=social_Node->get_money;
        social_Node->get_money=0;
    }
    
    void go_start_Node(){
        while(now_position->state!=2){
            now_position=now_position->next_Node;
        }
        player_money+=start_pay;
    }
    void get_card(){
        int gold_state=gold_card.front().f;
        int gold_pay=gold_card.front().s;
        gold_card.push(gold_card.front());
        gold_card.pop();
        if(gold_state==1){
            player_money+=gold_pay;
        }
        if(gold_state==2){
            player_money-=gold_pay;
            if(player_money<0){
                cout<<"LOSE";
                exit(0);
            }
        }
        if(gold_state==3){
            player_money-=gold_pay;
            social_Node->get_money+=gold_pay;
            if(player_money<0){
                cout<<"LOSE";
                exit(0);
            }
        }
        if(gold_state==4){
            go_place(gold_pay);
            //roll_dice 작성 다하면 여기에도 추가하기.
            if(now_position->state==0)buy_land();
            if(now_position->state==1)exit(-1);//이치에 안맞음.
            if(now_position->state==3)escape_island();
            if(now_position->state==4)help_social();
            if(now_position->state==5)go_start_Node();
        }
    }
    void roll_dice(){
        while(have_dice--){
            int a,b;
            cin>>a>>b;
            go_place(a+b);
            if(now_position->state==0)buy_land();
            if(now_position->state==1)get_card();
            if(now_position->state==3)escape_island();
            if(now_position->state==4)help_social();
            if(now_position->state==5)go_start_Node();
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* start_Node=new Node(2);
    Node* last_Node=start_Node;
    int n,player_money,start_pay,a,b,c;
    char d;
    cin>>n>>player_money>>start_pay>>a;
    while(a--){
        cin>>b>>c;
        gold_card.push({b,c});
    }
    for(int i=2;i<=4*n-4;i++){
        Node* now_Node=nullptr;
        if(i%(n-1)==1){
            if(i/(n-1)==1){
                now_Node=new Node(3);
            }
            else if(i/(n-1)==2){
                now_Node=new Node(4);
                social_Node=now_Node;
            }
            else{
                now_Node=new Node(5);
            }
            last_Node->next_Node=now_Node;
            last_Node=now_Node;
            continue;
        }
        cin>>d;
        if(d=='G'){
            now_Node=new Node(1);
            last_Node->next_Node=now_Node;
            last_Node=now_Node;
            continue;
        }
        now_Node=new Node(0);
        cin>>now_Node->land_cost;
        last_Node->next_Node=now_Node;
        last_Node=now_Node;
    }
    last_Node->next_Node=start_Node;
    
    Player* new_player=new Player(start_Node,player_money,start_pay);
    cin>>new_player->have_dice;
    //cout<<new_player->have_dice<<"개 주어진채로 시작.\n";
    new_player->roll_dice();
    
    if(new_player->player_money<0){
        cout<<"LOSE";
        return 0;
    }
    
    n=n*4-4;
    last_Node=start_Node;
    while(n--){
        if(last_Node->state==0){
            cout<<"LOSE";
            return 0;
        }
        last_Node=last_Node->next_Node;
    }
    cout<<"WIN";
    return 0;
}