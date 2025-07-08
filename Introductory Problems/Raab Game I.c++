#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, a, b;
        cin >> n >> a >> b;

        vector<int> dpa(n), dpb(n);
        iota(dpa.begin(), dpa.end(), 1LL);
        iota(dpb.begin(), dpb.end(), 1LL);

        if(n < a + b || a == n || b == n){
            cout << "NO\n";
            continue;
        }

        int i = n - a - b;

        if(a <= b){
            for(int j = 0; j < a; i++, j++)
                swap(dpa[i], dpa[n-j-1]);

            for(int j = 0; i + 1 < n; i++)
                swap(dpb[i], dpb[i+1]);
        }
        else{
            for(int j = 0; j < b; i++, j++)
                swap(dpb[i], dpb[n-j-1]);

            for(int j = 0; i + 1 < n; i++)
                swap(dpa[i], dpa[i+1]);
        }


        for(int i = 0; i < n; i++)
            a -= (dpa[i] > dpb[i]), 
            b -= (dpb[i] > dpa[i]);

        if(a || b)
            cout << "NO\n";
        else{
            cout << "YES\n";
            for(int i = 0; i < n; i++)
                cout << dpa[i] << " ";
            cout << "\n";
            for(int i = 0; i < n; i++)
                cout << dpb[i] << " ";
            cout << "\n";
        } 
    }
}
