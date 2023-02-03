#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int, int>> s;        //height, num

    int n;
    cin >> n;
    
    s.push({100000001, 0});
    for(int i=1; i<=n; i++){
        int h;
        cin >> h;
        while(s.top().first < h){
            s.pop();
        }
        cout << s.top().second << " ";
        s.push({h, i});
    }

}