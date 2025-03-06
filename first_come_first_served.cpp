//FCFS
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// arrival sort
// p ranges
void solve(){
    vector<array<int,3>> v;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        v.push_back({x, i+1, y}); // arrival, process, burst
    }

    sort(v.begin(), v.end());
    int st = 0, end = 0;
    // process, start, end
    vector<array<int,3>> a;
    for(int i = 0; i < n; i++){
        a.push_back({v[i][1], st, st + v[i][2]});
        st = st + v[i][2];
        
        if(i+1 < n && v[i+1][0] > a.back()[2]){
            a.push_back({-1, a.back()[2], v[i+1][0]});
            st = a.back()[2];
        }
    }

    cout << endl;
    for(auto x: a){
        cout << "P" << x[0] << " " << x[1] << " " << x[2] << endl;
    }
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}
