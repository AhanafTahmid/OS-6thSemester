//FCFS
//First Come First Served

//input
// 5
// 1 12
// 7 7
// 11 6
// 12 9
// 17 8

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
        v.push_back({x, y, i+1}); // arrival, burst, id
    }

    sort(v.begin(), v.end());
    vector<array<int,3>> a;
    int current_time = 0;
    for (auto p : v) {
        int arrival = p[0], burst = p[1], id = p[2];

        if (current_time < arrival) {
            // CPU idle period
            a.push_back({-1, current_time, arrival});//id,time, arrival
            current_time = arrival;
        }
        a.push_back({id, current_time, current_time + burst});
        current_time += burst;
    }

    for(array<int,3> x: a){
        cout << "P" << x[0] << " " << x[1] << " " << x[2] << endl;
    }
    //cout<< v.size() <<endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}
