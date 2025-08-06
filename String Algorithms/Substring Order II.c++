#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
 
const int maxSize = 1e5 + 5;
 
int suffixArray[maxSize], position[maxSize], temporary[maxSize], LCP[maxSize];
 
int gap, n, k;
string s;
 
 
bool compareSuffixes(int x, int y)
{
    if (position[x] != position[y])
        return position[x] < position[y];
 
    x += gap;
    y += gap;
 
    return (x < n && y < n) ? position[x] < position[y] : x > y;
}
 
void buildSuffixArray()
{
    for (int i = 0; i < n; i++)
        suffixArray[i] = i, position[i] = s[i];
 
 
    for (gap = 1;; gap <<= 1) {
 
        sort(suffixArray, suffixArray + n, compareSuffixes);
 
        for (int i = 0; i < n - 1; i++)
            temporary[i + 1] = temporary[i] + compareSuffixes(suffixArray[i], suffixArray[i + 1]);
 
        for (int i = 0; i < n; i++)
            position[suffixArray[i]] = temporary[i];
 
        if (temporary[n - 1] == n - 1)
            break;
    }
}

 
int32_t main()
{
    cin >> s >> k;
    n = s.size();
 
    buildSuffixArray();

    map<char, vector<int>> index;
    vector<int> dp(n);

    for(int i = 0; i < n; i++){
        if(index[s[suffixArray[i]]].empty())
            dp[i] = n - suffixArray[i], index[s[suffixArray[i]]].push_back(i);
        else{
            if(index[s[suffixArray[i]]].size() == 1)
                dp[i] = dp[i-1] + n - suffixArray[i], 
                index[s[suffixArray[i]]].push_back(i);
            else
                dp[i] = dp[i-1] + n - suffixArray[i], 
                index[s[suffixArray[i]]].pop_back(),
                index[s[suffixArray[i]]].push_back(i);
        }
    }

    string ans = "";

    int i = 0;
    for(; i < n; ){
        if(k > dp[index[s[suffixArray[i]]].back()])
            k -= dp[index[s[suffixArray[i]]].back()], 
            i = index[s[suffixArray[i]]].back() + 1;
        else
            break;
    }

    int start = index[s[suffixArray[i]]][0], end = index[s[suffixArray[i]]].back();

    for(int j = 0; ; ){
        if(suffixArray[start] + j >= n)
            start++;
        if(suffixArray[end] + j >= n)
            end--;

        if(s[suffixArray[start] + j] == s[suffixArray[end] + j]){

            if(k > (end - start + 1))
                k -= (end - start + 1);
            else{
                ans = s.substr(suffixArray[start + k - 1], j + 1);
                break; 
            }
            j++;
        }
        else{
            int x = end;
            for(; s[suffixArray[start] + j] != s[suffixArray[x] + j]; x--);
            
            if(k > (dp[x] - dp[start] + (n - suffixArray[start]) - (x - start + 1) * j))
                k -= (dp[x] - dp[start] + (n - suffixArray[start]) - (x - start + 1) * j),
                start = x + 1;
            else
                end = x;
        }
    }

    cout << ans << '\n';
}
