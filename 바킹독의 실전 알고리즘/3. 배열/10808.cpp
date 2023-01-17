//백준 10808 : 알파벳 개수
#include <bits/stdc++.h>
using namespace std;
int freq[26];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string S;
	cin >> S;
	for (auto c : S) {
		freq[c - 'a'] += 1;
	}
	for (int i = 0; i < 26; i++)
		cout << freq[i] << ' ';
}