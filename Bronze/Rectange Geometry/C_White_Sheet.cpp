#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
typedef vector<int> vi;

int inter_area(vi s1, vi s2)
{
    int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
    int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];
    int overlap_x = max(0LL, min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x));
    int overlap_y = max(0LL, min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y));
    return overlap_x * overlap_y;
}
int inter_area(vi s1, vi s2, vi s3)
{
    int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
    int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];
    int bl_c_x = s3[0], bl_c_y = s3[1], tr_c_x = s3[2], tr_c_y = s3[3];
    int overlap_x = max(0LL, min({tr_a_x, tr_b_x, tr_c_x}) - max({bl_a_x, bl_b_x, bl_c_x}));
    int overlap_y = max(0LL, min({tr_a_y, tr_b_y, tr_c_y}) - max({bl_a_y, bl_b_y, bl_c_y}));
    return overlap_x * overlap_y;
}
int area(vi s)
{
    return (s[2] - s[0]) * (s[3] - s[1]);
}

signed main()
{
    NeedForSpeed;
    vi white(4), black1(4), black2(4);
    for (int i = 0; i < 4; i++)
        cin >> white[i];
    for (int i = 0; i < 4; i++)
        cin >> black1[i];
    for (int i = 0; i < 4; i++)
        cin >> black2[i];

    int a = inter_area(white, black1);
    int b = inter_area(white, black2);
    int c = inter_area(white, black1, black2);
    int areawhite = area(white);
    int total_covered = a + b - c;
    if (total_covered >= areawhite)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}
