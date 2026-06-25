#include<bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i,n) for(int i=0;i<n;i++)
#define ld long double
#define fr first
#define sc second
#define pii pair<int,int>
#define pb push_back

int checking=1,MOD=1e9+7;

//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

struct DSU {
    vector<int> parent, sz;int count;

    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        count=n;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;

        return parent[x] = find(parent[x]); 
        // path compression
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false; 
        // already in same component

        if (sz[a] < sz[b]) swap(a, b);
        // attach smaller component under bigger component

        parent[b] = a;
        sz[a] += sz[b];
        count--;
        return true;
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int size(int x) {
        return sz[find(x)];
    }
};

int mod(int a,int b){
    if(a>b) return a-b;
    return b-a;
}

void swap(int& a,int& b){
    int temp=a;a=b;b=temp;return;
}

int fact(int n){
    int ans=1;
    for(int i=2;i<=n;i++){
        ans*=i;
    }
    return ans;
}

int ceil(int a,int b){
    if(a%b==0)return a/b;
    else return 1+(a/b);
}

int power(int base,int exp) {
    int res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base);
        base = (base * base);
        exp /= 2;
    }
    return res;
}

int bits(int a){
    int ans=0;
    while(a>0){
        a=a/2;ans++;
    }
    return ans;
}

void bfs(int start, vector<vector<int>>& g, vector<int>& dist) {
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int child : g[v]) {
            if (dist[child] == -1) {// not visited
                dist[child] = dist[v] + 1;
                q.push(child);
            }
        }
    }
}

void dfs(int v,int p,vector<vector<int>>&g) {
    // 1. before visiting children
 
  for (int to : g[v]) {
    
        // 2. before going into child
        dfs(to,v,g);
        // 3. after child is fully processed
    }
  

    // 4. after all children are processed
}

signed main(){
    int nt;cin>>nt;
    while(nt--){

}
}

