#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

long long MAX;
int need_treeLen;
long long result;

long long binary_search(vector<long long>& tree,long long start, long long high) {
    long long mid = (start + high) / 2;
    long long cut_tree = 0;
    
    if (start > high) return result;

    for (size_t idx = 0; idx < tree.size(); idx++) 
        if (tree[idx] - mid < 0) break;
        else cut_tree += tree[idx] - mid;
     
    if (cut_tree >= need_treeLen)  
        result = result < mid ? mid : result;   

    if (cut_tree > need_treeLen) 
        return binary_search(tree, mid + 1, high);
    else
        return binary_search(tree, start, mid - 1);

}

int main() {
    int N = 0;
    long long temp = 0;
    cin >> N; cin >> need_treeLen;
    vector<long long>tree;
    tree.reserve(N + 1);
    
    for (int i = 0; i < N; i++) {
        cin >> temp;
        tree.emplace_back(temp);
    }
    
    sort(tree.rbegin(), tree.rend());  
    MAX = tree[0];

    printf("%lld\n", binary_search(tree, 0, MAX));
    return 0;
}

