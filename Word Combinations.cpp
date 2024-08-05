#include <bits/stdc++.h>

using namespace std;
#define int long long


struct Node{
    Node* children[26];
    int end = 0;
    
    Node(){
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
};

int dp[5005];
string s, w;
int n, k;
const int mod = 1e9+7;
Node root;

void insert(string k){
    Node* cur = &root;
    int i = 0, c;
    while(i < k.size()){
        c = k[i] - 'a';
        if(cur -> children[c] == nullptr)
            cur -> children[c] = new Node();
        cur = cur -> children[c];
        i++;
    }
    cur -> end++;
}

Node* search(char k, Node* cur){
    int c;
    c = k - 'a';
    return cur -> children[c];
}


int solve(int i){
    if(i == n) return 1;
    if(dp[i] != -1) return dp[i];
    int ans = 0;
    Node* curNode = &root;
    for(int j = i; j < n; j++){
        curNode = search(s[j], curNode);
        if(curNode == nullptr) break;
        ans = (ans + (curNode -> end) * solve(j+1))%mod;
    }

    return dp[i] = ans;
}

signed main(){
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    
    memset(dp, -1, sizeof(dp));
    cin >> s >> k;
    while(k--){
        cin >> w;
        insert(w);
    }
    n = s.size();

    cout << solve(0) << endl;

    return 0;
}