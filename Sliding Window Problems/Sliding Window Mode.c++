#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>

using namespace std;

int32_t main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    auto comp = [](const pii a, const pii b){
        if(a.first == b.first)
            return a.second < b.second;

        return a.first > b.first;
    };

    set<pii, decltype(comp)> st(comp);
    map<int, int> f;

    vector<int> ans;

    for(int i = 0; i < k; i++){
        if(f[a[i]] > 0)
            st.erase(st.find(pii(f[a[i]], a[i])));
        
        f[a[i]]++;
        st.insert({f[a[i]], a[i]});
    }

    ans.push_back((*st.begin()).second);

    for(int i = k; i < n; i++){
        st.erase(st.find(pii(f[a[i-k]], a[i-k])));
        f[a[i-k]]--;

        st.insert({f[a[i-k]], a[i-k]});

        if(f[a[i]] > 0)
            st.erase(st.find(pii(f[a[i]], a[i])));
        
        f[a[i]]++;
        st.insert({f[a[i]], a[i]});

        ans.push_back((*st.begin()).second);
    }

    for(auto it: ans)
        cout << it << " ";
    cout << "\n";
}
