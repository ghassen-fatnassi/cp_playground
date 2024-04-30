void dfs(int pos)
{
    vis[pos] = true;
    for (int i = 0; i < graph[pos].size(); i++)
    {
        int x = graph[pos][i];
        if (!vis[x])
        {
            dfs(x);
        }
    }
    return;
}

// BFS :
const int N = 1e5;
bool vis[N];
vector<int> graph[N];

void bfs(int pos)
{
    vis[pos] = true;
    queue<int> q;
    q.push(pos);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < graph[x].size(); i++)
        {
            int next = graph[x][i];
            if (!vis[next])
            {
                vis[next] = true;
                q.push(next);
            }
        }
    }
}