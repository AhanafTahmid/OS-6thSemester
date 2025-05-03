//Priority scheduling algorithm 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    vector<array<int,4>> v;
    map<int, int>mp,mp2;

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x, y, z; cin >> x >> y >> z; // priority, arrival, burst 
        v.push_back({x, y, z, i+1}); // priority, arrival, burst, id, 
        mp[i+1] = z;
    }
    sort(v.begin(), v.end());
    //for(auto x: v) cout<< x[0] << " " << x[1] << " " << x[2] << " " << x[3] << endl;

    int st = 0, end = 0;
    //total time
    for(int i=0;i<n;i++) end+= v[i][2];

    //page 7
    // P1 0 1 2
    // P1 1 2 2
    // P1 2 3 2
    // P1 3 0 2
    // P2 4 1 3
    // P2 5 2 3
    // P2 6 0 3
    // P3 7 0 4
    // P4 8 1 5
    // P4 9 2 5
    // P4 10 3 5
    // P4 11 4 5
    // P4 12 0 5
    // P5 13 1 5
    // P5 14 2 5
    
    
    vector<array<int,4>> a;
    for(int i=0;i<=end;i++){
        int ind = 0;
        vector<array<int,4>> na;
        while (1)
        {
            if( ind<v.size() && v[ind][1]<=i && mp[v[ind][0]]>0) na.push_back({v[ind][0], v[ind][1], v[ind][2], v[ind][3]}),ind++;
            else break;
        }
        sort(na.begin(), na.end());
        if( na.size() >= 1){
            mp[na[0][3]]--;
            mp2[na[0][3]]++;
            if( mp[na[0][3]] == 0 ){
                //erase
                //find an array having x[3]
                auto it = find_if(v.begin(), v.end(), [&](auto &x) { return x[3] == na[0][3]; });                
                v.erase(it);
            }
            a.push_back({na[0][3], i, mp2[v[0][3]], na[0][0]});//id, time, end, priority
        }
        else a.push_back({-1, i, 1 -1});


        //if(na.size()>=1)cout<< na[0][3];
        // for(auto x: na) cout<< x[0] << " " << x[1] << " " << x[2] << " " << x[3] << endl;
        // cout<<endl;
    }
    
    for(auto x: a){
       cout << "P" << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << endl;
    }
    
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}