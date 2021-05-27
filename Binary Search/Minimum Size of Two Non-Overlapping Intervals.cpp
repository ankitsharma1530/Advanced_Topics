int solve(vector<vector<int>> &a) {
    int i, j, n = a.size(), mn = 1e9, ret = 2e9;
    sort(a.begin(), a.end(), [&](const vector<int> &x, const vector<int> &y) {
        if (x[1] != y[1]) return x[1] < y[1];
        return x[0] < y[0];
    });
    for (i = 0, j = 0; i < n; i++) {
        while (j < i && a[j][1] < a[i][0]) {
            mn = min(mn, a[j][1] - a[j][0] + 1);
            j++;
        }
        ret = min(ret, a[i][1] - a[i][0] + 1 + mn);
    }
    return ret >= 1e9 ? 0 : ret;
}
