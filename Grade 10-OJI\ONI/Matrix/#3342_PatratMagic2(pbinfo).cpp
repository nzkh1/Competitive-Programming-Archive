#include<bits/stdc++.h>
using namespace std;
int a[101][101],n;
void patrat(){
    int l=n/2+1,c=n;
    for(int i=1;i<=n*n;i++){
        if(l==0 && c==n+1){
            l=1;c=n-1;
        }else{
            if(c==n+1){
                c=1;
            }
            if(l<=0){
                l=n;
            }
        }
        if(a[l][c]){
            c-=2;
            l++;
        }
        a[l][c]=i;
        l--;c++;
    }
}
void afisare(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    patrat();
    afisare();
    
    return 0;
}
