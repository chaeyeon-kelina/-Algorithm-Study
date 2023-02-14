#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> d;
    int n;
    int m;
    int ans = 0;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        d.push_back(i);
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        int idx = find(d.begin(), d.end(), x) - d.begin();
        while(d.front() != x){
            if(idx > d.size()-idx){       //3번 실행
                d.push_front(d.back());
                d.pop_back();
                ans++;
            }
            else if(idx <= d.size()-idx){       //2번 실행
                d.push_back(d.front());
                d.pop_front();
                ans++;
            }
        }
        d.pop_front();
    }
    cout << ans;

}