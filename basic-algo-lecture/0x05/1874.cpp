#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    stack<int> s;
    queue<char> q;
    cin >> n;
    int t = 1;
    while(n--){
        int x;
        cin >> x;
        while(t <= x){
            s.push(t);
            t = t+1;
            q.push('+');
            
        }
        if(s.top() != x){
            cout << "NO";
            return 0;
        }
        s.pop();
        q.push('-');
    }
    while(!q.empty()){
        cout << q.front() << "\n";
        q.pop();
    }
}