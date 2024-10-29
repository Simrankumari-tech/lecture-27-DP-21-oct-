#include<bits/stdc++.h>
using namespace std;
int fibo(int n){
    if(n==0 || n== 1){
        return n;
    }

    return fibo(n-1)+fibo(n-2);
}

int Topdown(int n, int*dp){
    if(n== 0|| n== 1){
        dp[n] = n;  // return s phle store
        return n;
    }

    if(dp[n]!= -1){ // calculate s phle check 
        return dp[n]; // ye ensure krega ki calculation ho gyi h wpis n kre
    }

    return dp[n] = Topdown(n-1 , dp)+ Topdown(n-2, dp);
}

int Bottomup(int n){
    int dp[1000];
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main(){
    int dp[1000];
    int n;
    cin >> n;
    memset(dp , -1, sizeof dp);
     cout << fibo(n) << endl;
    cout << Topdown(n , dp) << endl;
    cout << Bottomup(n) << endl;
    return 0;
}