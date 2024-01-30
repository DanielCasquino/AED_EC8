#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find(int u,vector<int>& parent){
        if(u==parent[u]) return u;
        return parent[u]=find(parent[u],parent);
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> parent(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
        for(auto x:dislikes){
            bool u=x[0],v=x[1];
            int pu=find(u,parent),pv=find(v,parent);
            if(pu==pv) 
                return false;
            parent[pu]=pv;
        }
        return true;
    }
};
int main(){
    Solution s;
    vector<vector<int>> dislikes={{1,2},{1,3},{2,4}};
    cout<<s.possibleBipartition(4,dislikes);
    return 0;
    /*vector<vector<int>> dislikes={{1,2},{1,3},{2,3}};
    cout<<s.possibleBipartition(3,dislikes);
    return 0;*/
}

