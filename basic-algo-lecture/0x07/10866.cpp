#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> dq;
    string str;
    int x;

    while(n--){
        str = "";
        x = 0;
        cin >> str;

        if(str == "push_front"){
            cin >> x;
            dq.push_front(x);
            continue;
        }
        else if(str == "push_back"){
            cin >> x;
            dq.push_back(x);
            continue;
        }
        else if(str == "size"){
            cout << dq.size() << "\n";
            continue;
        }
        if(dq.empty()){     //deque가 비어있으면
            if(str == "pop_front" || str=="pop_back" || str=="front" || str=="back")
                cout << -1 << "\n";
            else if(str == "empty") cout << 1 << "\n";
        }
        else{
            if(str == "pop_front"){
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            else if(str == "pop_back"){
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            else if(str == "front"){
                cout << dq.front() << "\n";
            }
            else if(str == "back")
                cout << dq.back() << "\n";
            else if(str == "empty") 
                cout << 0 << "\n";
        }
    }
}