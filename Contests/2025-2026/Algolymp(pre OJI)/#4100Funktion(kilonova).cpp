#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
const int MAX=2e6+10;
long long fact[MAX],fact_inv[MAX];

long long fastpow(long long base,long long exp,long long mod){
    long long res=1;
    while(exp>0){
        if(exp&1){
            res=(res*base)%mod;
            base=(base*base)%mod;
            exp>>=1;
        }
    }
    return res;
}
void precompute(){
    fact[0]=1;
    for(int i=1;i<MAX;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    fact_inv[MAX-1]=fastpow(fact[MAX-1],mod-2,mod);
    for(int i=MAX-2;i>=0;i--){
        fact_inv[i]=(fact_inv[i+1]*(i+1))%mod;
    }
}
long long nCR(int n,int x){
    return (((fact[n]*fact_inv[x])%mod)*fact_inv[n-x])%mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    if(!(cin>>n>>k))return 0;
    vector<long long> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    precompute();
    long long sum=0;
    for(int i=1;i<=n;i++){
        long long comb_weight=(nCR(i+k-1,k)*nCR(n-i+k,k))%mod;
        long long term=(a[i]%mod+mod)%mod;
        sum=(sum+(term*comb_weight)%mod)%mod;
        cout<<sum<<"\n";
    }
}
