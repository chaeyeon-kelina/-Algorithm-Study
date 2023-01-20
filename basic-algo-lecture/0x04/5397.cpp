#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        list<char> L;
        auto t = L.begin();
        
        string a;
        cin >> a;

        for(char i:a){
            if(i == '-'){
                if(t != L.begin()){
                    t--;
                    t = L.erase(t);
                }
            }
            else if(i == '<'){
                if(t!= L.begin())
                    t--;
            }
            else if(i == '>'){
                if(t != L.end())
                    t++;
            }
            else{
                L.insert(t, i);
            }
        }
        for(auto i : L)
            cout << i;
        cout << '\n';
    }
    
    
    
}