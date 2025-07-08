// Bankers Algorithm
// https://youtu.be/7gMLNiEz3nw
// input:
// 5 3
// 10 5 7

// 0 1 0
// 2 0 0
// 3 0 2
// 2 1 1
// 0 0 2

// 7 5 3
// 3 2 2
// 9 0 2
// 4 2 2
// 5 3 3

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int p, r;cin>>p>>r;//process, resource
    vector<vector<int>>allocation(p, vector<int>(r)), max_need(p, vector<int>(r)), available(p+1, vector<int>(r))
    , rem_need(p, vector<int>(r));
    vector<int>given_resources(r);

    for(int i=0;i<r;i++){
        cin>>given_resources[i];
    }

    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            cin>>allocation[i][j];
        }
    }
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            cin>>max_need[i][j];
        }
    }

    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            rem_need[i][j] = max_need[i][j] - allocation[i][j];
        }
    }

    //first available need
    vector<int>sum(r);
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            sum[j]+=allocation[i][j];
        }
    }

    for(int i=0;i<r;i++) available[0][i] = given_resources[i] - sum[i];

    int ind = 0;
    // ok = 1 = no deadlock
    // ok = 0 = deadlock
    bool ok = 0;

    int cnt = 0,inf = 100;
    while(1){
        ok = 0;
        for(int i=0;i<p;i++){
            for(int j=0;j<r;j++){
                inf--;
                if(rem_need[i][j]!=-1){

                    if( rem_need[i][j] > available[ind][j] ){
                        break;
                    }
                    if(j == r-1){
                         cnt++;
                        for(int k=0;k<r;k++) available[ind+1][k] = available[ind][k] + allocation[i][k], rem_need[i][k] = -1;
                        ind++;
                    }
                }
            }
        }

        if(cnt==p){
            ok = 1;
            break;
        }
        if(inf==0)break;
    }

    cout<<endl;
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            cout<< rem_need[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<< (ok?"Safe state":"Unsafe state")<<endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve();
    return 0;
}