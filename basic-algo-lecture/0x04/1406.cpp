#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    list<int> edi;
    string s;   //초기에 편집기에 입력되어 있는 문자열
    cin >> s;
    for(auto i : s)
        edi.push_back(i);
    int m = 0;      //입력할 명령어의 개수
    cin >> m;
    auto cur = edi.end();

    for(int i=0; i<m; i++){
        char c;
        cin >> c;
        switch(c){
            case 'L':
                if(cur != edi.begin())
                    cur--;
                break;
            case 'D':
                if(cur != edi.end())
                    cur++;
                break;
            case 'B':
                if(cur != edi.begin()){
                    cur--;
                    cur = edi.erase(cur);       //왼쪽 문자를 지운다. 이때, cur은 자동으로 오른쪽 문자 위치를 반환한다.
                }
                break;
            case 'P':
                char alp;
                cin >> alp;
                edi.insert(cur, alp);
                break;
            default:
                break;
        }
    }
    
    for(char i:edi)
        cout << i;
    

}