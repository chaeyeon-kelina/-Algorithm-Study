#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    queue<int> q;
    cin >> n;

    while(n--){
        string str;
        int x;
        cin >> str;

        if(str == "push"){
            cin >> x;
            q.push(x);
        }
        else if(str == "size")  cout << q.size() << "\n";
        else if(q.empty()){
            if(str == "front")  cout << -1 << "\n";
            else if(str == "back")  cout << -1 << "\n";
            else if(str == "pop")  cout << -1 << "\n";
            else
                cout << (int)q.empty() << "\n";
        }
        else if(!q.empty()){
            int tmp = 0;
            if(str == "front")
                tmp = q.front();
            else if(str == "back")
                tmp = q.back();
            else if(str == "pop"){
                tmp = q.front();
                q.pop();
            }
                
            else
                tmp = (int)q.empty();
            cout << tmp << "\n";
        }
    }

}