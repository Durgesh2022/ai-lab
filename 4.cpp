// //A* Algorithm
#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> A_Star(int n, int src, int dest, vector<vector<int>> &grid, vector<int> &heuristic)
{
    vector<int> parent(n, -1);
    vector<int> dist(n, INT_MAX);
    parent[src] = src, dist[src] = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({heuristic[src], {src, 0}});
    while (!pq.empty())
    {
        int node = pq.top().second.first;
        int cost = pq.top().second.second;
        pq.pop();
        for (int neighbour = 0; neighbour < n; neighbour++)
        {
            if (grid[node][neighbour] != 0)
            {
                int neighbour_cost = cost + grid[node][neighbour];
                if (neighbour_cost < dist[neighbour])
                {
                    dist[neighbour] = neighbour_cost;
                    parent[neighbour] = node;
                    int f_n = neighbour_cost + heuristic[neighbour];
                    pq.push({f_n, {neighbour, neighbour_cost}});
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
    vector<int> heuristic(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> heuristic[i];
    }
    pair<int, vector<int>> p = A_Star(n, 0, n - 1, grid, heuristic);
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
7
0 3 1 0 0 0 0
3 0 0 7 5 0 0
1 0 0 9 0 2 0
0 7 9 0 2 0 3
0 5 0 2 0 6 6
0 0 2 0 6 0 5
0 0 0 3 6 5 0
10 8 6 5 3 1 0
*/

/*
8
0 2 4 0 0 0 0 0
2 0 0 7 3 0 0 0
4 0 0 0 8 5 0 0
0 7 0 0 0 0 6 0
0 3 8 0 0 0 4 0
0 0 5 0 0 0 0 7
0 0 0 6 4 0 0 3
0 0 0 0 0 7 3 0
10 8 7 5 6 4 3 0
*/

// //GBFS
// #include<bits/stdc++.h>
// using namespace std;

// pair<int,vector<int>> GBFS(int n,int src,int dest,vector<vector<int>>& grid,vector<int>& heuristic){
//     vector<int> parent(n,-1);
//     vector<int> dist(n,INT_MAX);
//     parent[src]=src,dist[src]=0;
//     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
//     pq.push({heuristic[src],{src,0}});
//     while(!pq.empty()){
//         int node=pq.top().second.first;
//         int cost=pq.top().second.second;
//         pq.pop();
//         for(int neighbour=0;neighbour<n;neighbour++){
//             if(grid[node][neighbour]!=0){
//                 int neighbour_cost=cost+grid[node][neighbour];
//                 if(neighbour_cost<dist[neighbour]){
//                     dist[neighbour]=neighbour_cost;
//                     parent[neighbour]=node;
//                     int f_n=heuristic[neighbour];
//                     pq.push({f_n,{neighbour,neighbour_cost}});
//                 }
//             }
//         }
//     }
//     int node=dest;
//     vector<int> path;
//     while(parent[node]!=node){
//         path.push_back(node);
//         node=parent[node];
//     }
//     path.push_back(node);
//     reverse(path.begin(),path.end());
//     return {dist[dest],path};
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<vector<int>> grid(n,vector<int>(n));
//     vector<int> heuristic(n);
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>grid[i][j];
//         }
//     }
//     for(int i=0;i<n;i++){
//         cin>>heuristic[i];
//     }
//     pair<int,vector<int>> p=GBFS(n,0,n-1,grid,heuristic);
//     cout<<"Cost: "<<p.first<<endl;
//     cout<<"Path: ";
//     for(auto it:p.second){
//         cout<<char(it+65)<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

/*
8
0 5 0 0 9 0 0 0
5 0 2 4 0 0 0 0
0 2 0 6 0 0 3 0
0 4 6 0 4 8 0 0
9 0 0 4 0 5 0 0
0 0 0 8 5 0 0 6
0 0 3 0 0 0 0 1
0 0 0 0 0 6 1 0
8 3 5 9 7 4 2 0
*/

// //Matrix Problem
// #include<bits/stdc++.h>
// using namespace std;

// int bfs(int n,int m,vector<vector<int>>& grid,int k){
//     queue<pair<pair<int,int>,int>> q;
//     q.push({{0,0},grid[0][0]});
//     int count=0;
//     while(!q.empty()){
//         int row=q.front().first.first;
//         int col=q.front().first.second;
//         int data=q.front().second;
//         q.pop();
//         if(row==n-1 && col==m-1 && data%k==0){
//             count++;
//         }
//         int move_x[]={0,1};
//         int move_y[]={1,0};
//         for(int i=0;i<2;i++){
//             int x=row+move_x[i],y=col+move_y[i];
//             if(x>=0 && x<n && y>=0 && y<m){
//                 q.push({{x,y},data+grid[x][y]});
//             }
//         }
//     }
//     return count;
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
//     int k;
//     cin>>k;
//     cout<<bfs(n,m,grid,k)<<endl;
//     return 0;
//  }
