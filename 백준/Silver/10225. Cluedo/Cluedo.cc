#include "grader.h"
#include "cluedo.h"

void Solve(){
    int ans_a=1,ans_b=1,ans_c=1;
    while(1){
        int r=Theory(ans_a,ans_b,ans_c);
        if(r==1){
            ans_a++;
        }
        else if(r==2){
            ans_b++;
        }
        else if(r==3){
            ans_c++;
        }
        else break;
    }
    return;
}

