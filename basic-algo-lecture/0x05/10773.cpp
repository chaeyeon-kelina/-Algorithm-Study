#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    int k;
    int ans = 0;
    cin >> k;
    while(k--){
        int x;
        cin >> x;
        if(x == 0){
            ans -= s.top();
            s.pop();
        }
        else{
            ans += x;
            s.push(x);
        }
    }
    cout << ans;
}