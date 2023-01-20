#include <bits/stdc++.h>
using namespace std;

const int MX = 5005;
bool isEmpty[MX]; // 죽은 사람 true
int nxt[MX];      // 연결 리스트
int cur = 1;      // 커서
vector<int> ans;

void erase(int t)
{
  ans.push_back(t);
  isEmpty[t] = true;
  nxt[t-1] = nxt[t];
}

int check(int t, int n){
  while(isEmpty[t] == true){   //그 사람이 죽었으면
    if(t > n)
      t = 1;
    else
      t++;
  }
  return t;
}

int main(void)
{
  fill(isEmpty, isEmpty + MX, true);
  fill(nxt, nxt + MX, -1);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    isEmpty[i] = false;
    nxt[i] = i + 1;
  }
  nxt[n] = 1; // 원형 리스트로 연결

  int kill = 1;
  int count = n;
  while (count != 0)
  {
    
    cur = check(cur, n);
    if (kill == k)
    {
      erase(cur);
      kill = 0;
      count--;
    }
      cur++;
    kill++;
    
  }

  cout << "<";
  for(int i=0; i<n; i++){
    cout << ans[i];
    if(i < n-1)
      cout << ", ";
  }
  cout << ">";
}