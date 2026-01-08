struct Graph {
    int N;
    bool undirected;
    vector<vector<int>> g;
    Graph(int n, bool u): N(n), g(n), undirected(u) {}
    void add_edge(int u, int v){
        g[u].push_back(v);
        if(undirected) g[v].push_back(u);
    }

    vector<int> bfs_dist(int s){
        vector<int> dist(N, -1);
        queue<int> q;
        dist[s]=0; q.push(s);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int v:g[u]){
                if(dist[v]!=-1) continue;
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
        return dist;
    }

    vector<int> bfs_parent(int s){
        vector<int> par(N, -1);
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int v:g[u]){
                if(par[v]!=-1) continue;
                if(s==v) continue;
                par[v]=u;
                q.push(v);
            }
        }
        return par;
    }
};
vector<int> restore_path(int u, int v, const vector<int>& dist, const Graph& G){
    vector<int> path;
    int cur = v;
    path.push_back(cur);
    while(cur != u){
        for(int nx : G.g[cur]){
            if(dist[nx] == dist[cur] - 1){
                cur = nx;
                path.push_back(cur);
                break;
            }
        }
    }
    reverse(path.begin(), path.end());
    return path;
}
