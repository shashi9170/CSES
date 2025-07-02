#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e9;

int32_t main(){

    int left = 1, right = MAXN;

    while(left < right){
        int mid = (left + right) / 2;
        cout << "? " << mid << endl;
        cout.flush();

        string s;
        cin >> s;

        if(s == "YES")
            left = mid + 1;
        else
            right = mid;
    }

    cout << "! " << left << endl;
    cout.flush();
}
