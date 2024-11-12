// //Min Cost Using UCS
// #include<bits/stdc++.h>
// using namespace std;

// int UCS(int n,int m,vector<vector<int>>& grid){
//     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
//     pq.push({grid[0][0],{0,0}});
//     while(!pq.empty()){
//         int row=pq.top().second.first;
//         int col=pq.top().second.second;
//         int cost=pq.top().first;
//         pq.pop();
//         if(row==n-1 && col==m-1){
//             return cost;
//         }
//         int move_x[]={-1,0,1,0};
//         int move_y[]={0,1,0,-1};
//         for(int i=0;i<4;i++){
//             int x=row+move_x[i],y=col+move_y[i];
//             if(x>=0 && x<n && y>=0 && y<m){
//                 int dist=cost+grid[x][y];
//                 pq.push({dist,{x,y}});
//             }
//         }
//     }
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> grid(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>grid[i][j];
//         }
//     }
//     cout<<UCS(n,m,grid)<<endl;
//     return 0;
// }

// //String in the matrix
// #include<bits/stdc++.h>
// using namespace std;

// void dfs(int n,int m,int row,int col,int& ind,string& s,vector<vector<char>>& grid,vector<vector<bool>>& visited){
//     visited[row][col]=true;
//     int move_x[]={-1,0,1,0};
//     int move_y[]={0,-1,0,1};
//     for(int i=0;i<4;i++){
//         int x=row+move_x[i],y=col+move_y[i];
//         if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==s[ind]){
//             ind++;
//             dfs(n,m,x,y,ind,s,grid,visited);
//         }
//     }
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<char>> grid(n,vector<char>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>grid[i][j];
//         }
//     }
//     string s;
//     cin>>s;
//     vector<vector<bool>> visited(n,vector<bool>(m,false));
//     bool flag=false;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(grid[i][j]==s[0]){
//                 int ind=1;
//                 dfs(n,m,i,j,ind,s,grid,visited);
//                 if(ind==s.size()){
//                     flag=true;
//                     break;
//                 }
//             }
//         }
//         if(flag) break;
//     }
//     if(flag) cout<<"True"<<endl;
//     else cout<<"False"<<endl;
//     return 0;
// }

// //UCS to find the least-cost path
#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> UCS(int n, vector<vector<int>> &grid, int src, int dest)
{
    vector<int> parent(n, -1);
    parent[src] = src;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (node == dest)
            break;
        for (int neighbour = 0; neighbour < n; neighbour++)
        {
            if (grid[node][neighbour] != 0)
            {
                int neighbour_cost = cost + grid[node][neighbour];
                if (neighbour_cost < dist[neighbour])
                {
                    dist[neighbour] = neighbour_cost;
                    parent[neighbour] = node;
                    pq.push({neighbour_cost, neighbour});
                }
            }
        }
    }
    int node = dest;
    vector<int> path;
    while (parent[node] != node)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(node);
    reverse(path.begin(), path.end());
    return {dist[dest], path};
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    pair<int, vector<int>> p = UCS(n, grid, 0, n - 1);
    cout << "Cost: " << p.first << endl;
    cout << "Path: ";
    for (auto it : p.second)
    {
        cout << char(it + 65) << " ";
    }
    cout << endl;
    return 0;
}

/*
5
0 1 4 0 0
1 0 2 0 6
4 2 0 4 3
0 0 4 0 3
0 6 3 3 0
*/

// //(DLS)Determine if it is possible to reach the goal within specified maximum depth.
// #include <bits/stdc++.h>
// using namespace std;

// bool dfs(int n, int m, int row, int col, int d, vector<vector<char>> &grid, vector<vector<bool>> &visited)
// {
//     if (d == 0 && grid[row][col] != 'G')
//         return false;
//     if (grid[row][col] == 'G')
//         return true;
//     visited[row][col] = true;
//     int move_x[] = {-1, 0, 1, 0};
//     int move_y[] = {0, -1, 0, 1};
//     for (int i = 0; i < 4; i++)
//     {
//         int x = row + move_x[i], y = col + move_y[i];
//         if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y] != '#')
//         {
//             if (dfs(n, m, x, y, d - 1, grid, visited))
//                 return true;
//         }
//     }
//     return false;
// }
// int main()
// {
//     int n, m, d;
//     cin >> n >> m >> d;
//     vector<vector<char>> grid(n, vector<char>(m));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> grid[i][j];
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (grid[i][j] == 'S')
//             {
//                 vector<vector<bool>> visited(n, vector<bool>(m, false));
//                 cout << dfs(n, m, i, j, d, grid, visited) << endl;
//             }
//         }
//     }
//     return 0;
// }

// //(IDDFS)Min moves needed to reach the target using IDDFS
// #include <bits/stdc++.h>
// using namespace std;

// bool dfs(int n, int m, int row, int col, int d, vector<vector<char>> &grid, vector<vector<bool>> &visited)
// {
//     if (d == 0 && grid[row][col] != 'T')
//         return false;
//     if (grid[row][col] == 'T')
//         return true;
//     visited[row][col] = true;
//     int move_x[] = {-1, 0, 1, 0};
//     int move_y[] = {0, -1, 0, 1};
//     x for (int i = 0; i < 4; i++)
//     {
//         int x = row + move_x[i], y = col + move_y[i];
//         if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y] != '#')
//         {
//             if (dfs(n, m, x, y, d - 1, grid, visited))
//                 return true;
//         }
//     }
//     return false;
// }
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<char>> grid(n, vector<char>(m));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> grid[i][j];
//         }
//     }
//     int row, col;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (grid[i][j] == 'S')
//             {
//                 row = i, col = j;
//             }
//         }
//     }
//     bool flag = false;
//     for (int d = 0; d < n * m; d++)
//     {
//         vector<vector<bool>> visited(n, vector<bool>(m, false));
//         if (dfs(n, m, row, col, d, grid, visited))
//         {
//             cout << d << endl;
//             flag = true;
//             break;
//         }
//     }
//     if (!flag)
//         cout << -1 << endl;
//     return 0;
// }
