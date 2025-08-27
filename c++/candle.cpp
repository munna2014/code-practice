#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<long long> a(N);
    for (auto &x : a)
        cin >> x;

    long long ans = LLONG_MAX;
    for (int i = 0; i <= N - K; i++)
    {
        long long L = a[i], R = a[i + K - 1];
        ans = min(ans, min(2 * abs(L) + abs(R), 2 * abs(R) + abs(L)));
    }
    cout << ans << "\n";
}
