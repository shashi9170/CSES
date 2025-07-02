#include <bits/stdc++.h>
using namespace std;

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();

    string response;
    cin >> response;
    return response == "YES";
}

vector<int> merge_sort(const vector<int>& indices) {
    if (indices.size() <= 1) return indices;

    int mid = indices.size() / 2;
    vector<int> left(indices.begin(), indices.begin() + mid);
    vector<int> right(indices.begin() + mid, indices.end());

    left = merge_sort(left);
    right = merge_sort(right);

    vector<int> result;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (ask(left[i], right[j])) {
            result.push_back(left[i++]);
        } else {
            result.push_back(right[j++]);
        }
    }

    while (i < left.size()) result.push_back(left[i++]);
    while (j < right.size()) result.push_back(right[j++]);

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 1);

    vector<int> sorted = merge_sort(indices);

    vector<int> a(n + 1);
    for (int i = 0; i < n; ++i) {
        a[sorted[i]] = i + 1;
    }

    cout << "! ";
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout.flush();
}
