//Shortest Job First

//input
// 5
// 6 2
// 2 5
// 8 1
// 3 0
// 4 4

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

//     page 3

// 23

// P4 0 1
// P4 1 2
// P4 2 3
// P1 3 1
// P5 4 1
// P2 5 1
// P2 6 2
// P5 7 2
// P5 8 3
// P5 9 4
// P1 10 2
// P1 11 3
// P1 12 4
// P1 13 5
// P1 14 6
// P3 15 1
// P3 16 2
// P3 17 3
// P3 18 4
// P3 19 5
// P3 20 6
// P3 21 7
// P3 22 8


    vector<array<int,3>> a;

    for(int i=0;i<end;i++){
        int ind = 0;
        vector<array<int,3>> na;
        while(1){
            if( ind<v.size() && v[ind][0]<=i && mp[v[ind][2]]>0 ) na.push_back({v[ind][1], v[ind][0], v[ind][2]}),ind++;
            else break;
        }

        //Burst Time, Arrival Time, ID
        sort(na.begin(), na.end());
        if( na.size() >= 1){
            mp[na[0][2]]--;
            mp2[na[0][2]]++;
            if( mp[na[0][2]] == 0 ){
                //erase
                //find an array having x[3]
                auto it = find_if(v.begin(), v.end(), [&](auto &x) { return x[2] == na[0][2]; });                
                v.erase(it);
            }
            a.push_back({na[0][2], i, mp2[na[0][2]]});//id, time, total burst
            
        }
        else {
            a.push_back({-1, i, 1});//id, end,time
        }

        //if(na.size()>=1)cout<< na[0][3];
        // for(auto x: na) cout<< x[0] << " " << x[1] << " " << x[2] << " " << x[3] << endl;
        // cout<<endl;
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
