#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    bool same[1001];
    int k = 0;
    for (k = 0; k < n; k++)
    {
        int ans = 1;
        fill(same, same + 1001, false);
        string str1 = "";
        string str2 = "";
        cin >> str1 >> str2;
        for (int i = 0; i < str1.size(); i++)
        {
            for (int j = 0; j < str2.size(); j++)
            {
                if (str1[i] == str2[j] && same[i] == false)
                {
                    same[i] = true;
                    continue;
                }
            }
        }
        for (int i = 0; i < str2.size(); i++)
        {
            if (!same[i])
            {
                cout << "Impossible\n";
                ans = 0;
                continue;
            }
        }
        if (ans == 1)
        {
            cout << "Possible\n";
        }
    }
}
