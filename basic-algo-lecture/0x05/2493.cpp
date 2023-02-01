#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<int> s;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        s.push(t);
    }
    stack<int> s2;
    while(n--){
        int num;
        num = s.top();
        s.pop();
        if(s.top() < num){
            s2.push(num);
            num = s.top();
            s.pop();
        }
        if(s2.top() < num){
            
        }
    }



}