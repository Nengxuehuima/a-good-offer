#include <complex>
#include <ios>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        v.emplace_back(m);
    }
    int s = std::accumulate(v.begin(), v.end(), 0);
    int maxDiff = -2147483648;
    int lSum = v[0];
    int rSum = s - lSum;
    pair<int, int> p(maxDiff, 0);
    for (int i = 1; i < v.size() - 1; ++i)
    {
        long diff = rSum - lSum;
        if (diff > maxDiff)
        {
            p.first = diff;
            p.second = i;
        }
        rSum -= v[i];
        lSum += v[i];
    }
    int l = std::accumulate(v.begin(), v.begin() + p.second, 0);
    int r = std::accumulate(v.begin() + p.second, v.end(), 0);

    return l * r;
}
// 64 位输出请用 printf("%lld")