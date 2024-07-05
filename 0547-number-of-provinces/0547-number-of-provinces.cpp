

class Disjoinset
{
    vector<int> rank, parent, size;

public:
    Disjoinset(int n)
    {
        rank.resize(n + 1);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }
    int findparent(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findparent(parent[node]);
    }
    void unionbyrank(int u, int v)
    {
        int ulpu = findparent(u);
        int ulpv = findparent(v);
        if (ulpu == ulpv)
            return;
        if (ulpu < ulpv)
            parent[ulpu] = ulpv;
        else if (ulpu > ulpv)
            parent[ulpv] = ulpu;
        else
        {
            parent[ulpv] = ulpu;
            rank[ulpu]++;
        }
    }
    void unionByresize(int u, int v)
    {
        int ulpu = findparent(u);
        int ulpv = findparent(v);
        if (ulpu == ulpv)
            return;
        if (size[ulpu] < size[ulpv])
        {
            parent[ulpu] = ulpv;
            size[ulpv] += size[ulpu];
        }
        else
        {
            parent[ulpv] = ulpu;
            size[ulpu] += size[ulpv];
        }
    }
};
int numProvinces(vector<vector<int>> adj, int v) {
        // code here
        Disjoinset obj(v);
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(adj[i][j]==1) obj.unionbyrank(i,j);
            }
        }
        int count=0;
        for(int i=0;i<v;i++)
        {
            if(obj.findparent(i)==i) count++;
        }
        return count;
        
    }
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        return numProvinces( isConnected, isConnected.size());
    }
};