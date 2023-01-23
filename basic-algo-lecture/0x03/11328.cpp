#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int same[26] = {};
    int k = 0;
    for (k = 0; k < n; k++)
    {
        fill(same, same+26, 0);
        string str1, str2;
        cin >> str1 >> str2;
        for(auto i : str1)
            same[i - 'a']++;
        for(auto i : str2)
            same[i - 'a']--;
        bool possible = true;
        for(int i=0; i<26; i++){
            if(same[i] != 0){
                possible = false;
                continue;
            }
        }
        if(possible)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}
/*
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
*/