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
    map<int, int>mp, mp2;//how many time appear, how many remain  
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        v.push_back({x, y, i+1}); // arrival, burst, id
        mp[i+1]=y;
    }
    sort(v.begin(), v.end());
    int st = 0, end = 0;
    //total time
    for(int i=0;i<n;i++) end+= v[i][1];


    cout<< end <<endl;

//     page 1
// 42


    // vector<array<int,3>> a;

    // for(int i=0;i<end;){
    //     int ind = 0;
    //     vector<array<int,3>> na;

    //     while(1){
    //         if( ind<v.size() && v[ind][0]<=i) na.push_back({v[ind][2], v[ind][0], v[ind][1]}),ind++;
    //         else break;
    //     }
    //     //ID,Arrival Time,Burst Time

    //     // for(int j=0;j<=i;j++){
    //     //     if( ind<v.size() && v[ind][0]<=i && mp[v[ind][2]]>0 ) na.push_back({v[ind][2], v[ind][0], v[ind][1]}),ind++;
    //     // }
        
    //     sort(na.begin(), na.end());
    //     if( na.size() >= 1){
    //         //id 
    //         auto it = find_if(v.begin(), v.end(), [&](auto &x) { return x[0] == na[0][0]; });                
    //         v.erase(it);
    //         cout<< na[0][0] << " ";
    //         cout<< na[0][1] << " ";
    //         cout<< na[0][2] << "\n";
    //         a.push_back({na[0][0], i, na[0][2]});//id, time, total burst
    //         i+= na[0][2];
    //     }
    //     else {
    //         a.push_back({-1, i, 1});//id, end,time
    //         i+=1;
    //     }

    //     //if(na.size()>=1)cout<< na[0][0];
    //     // for(auto x: na) cout<< x[0] << " " << x[1] << " " << x[2] << " " << x[3] << endl;
    //     // cout<<endl;

    // }
    // cout << endl;

    vector<array<int,3>> a;
    int current_time = 0;

    for (auto p : v) {
        int arrival = p[0], burst = p[1], id = p[2];

        if (current_time < arrival) {
            // CPU idle period
            a.push_back({-1, current_time, arrival});
            current_time = arrival;
        }

        a.push_back({id, current_time, current_time + burst});
        current_time += burst;
    }

    for(auto x: a){
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
