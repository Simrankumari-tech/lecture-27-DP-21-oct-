#include<bits/stdc++.h>
using namespace std;
int solve(int amount , int*deno, int n){
            // base case
    if(amount == 0) return 0;
    int ans = INT_MAX ;
    for(int i= 0; i<n ;i++){
        if(amount>= deno[i]){
            int chotiamount = amount - deno[i];  
            int x = solve(chotiamount, deno , n);
            if(x != INT_MAX){
                ans = min(ans , x+1);
            }
        }
    }
    return ans;
}

int Topdown(int amount , int*deno, int n , int*dp){
            // base case
    if(amount == 0) return dp[amount]= 0;
    if(dp[amount] != -1 ) dp[amount];
    int ans = INT_MAX ;
    for(int i= 0; i<n ;i++){
        if(amount>= deno[i]){
            int chotiamount = amount - deno[i];  
            int x = Topdown(chotiamount, deno , n ,dp);
            if(x != INT_MAX){
                ans = min(ans , x+1);
            }
        }
    }
   return dp[amount] = ans;
}
int Bottomup(int amount , int *deno , int n){
    vector<int> dp(amount+1 , INT_MAX);
    dp[0] = 0;
    for(int amt =1; amt<= amount; amt++){
         int ans = INT_MAX ;
         for(int i= 0; i<n ;i++){
        if(amt>= deno[i]){
           
            int x = dp[amt - deno[i]];
            if(x != INT_MAX){
               dp[amt] = min(dp[amt] , x+1);
            }
        }
    }
    }
    return dp[amount];
}

int main(){
    int deno[]= {1, 7, 10};
    int n = sizeof(deno)/ sizeof(int);
    int amount ;
    cin>> amount ;
    int dp[10000];
    memset(dp , -1 , sizeof dp);
    cout << Topdown(amount , deno , n, dp)<< endl;
    cout << Bottomup(amount , deno, n ) ;
    return 0;   
}
