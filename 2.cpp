// Path Finding
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = nullptr, right = nullptr;
    }
};
Node *insert(vector<int> &nums, int index)
{
    if (index >= nums.size() || nums[index] == -1)
        return nullptr;
    Node *root = new Node(nums[index]);
    root->left = insert(nums, 2 * index + 1);
    root->right = insert(nums, 2 * index + 2);
    return root;
}
bool path(Node *&root, int target)
{
    if (root == nullptr)
        return false;
    target -= root->data;
    if (root->left == nullptr && root->right == nullptr)
    {
        return target == 0;
    }
    bool left_tree = path(root->left, target);
    bool right_tree = path(root->right, target);
    return left_tree || right_tree;
}
int main()
{
    string s;
    cin >> s;
    vector<int> nums;
    stringstream ss(s);
    string substr;
    while (getline(ss, substr, ','))
    {
        int num;
        if (substr == "null")
            num = -1;
        else
            num = stoi(substr);
        nums.push_back(num);
    }
    int target;
    cin >> target;
    Node *root = insert(nums, 0);
    bool result = path(root, target);
    cout << result << endl;
    return 0;
}

// //Islands
#include <bits/stdc++.h>
using namespace std;

void dfs(int n, int m, int row, int col, vector<vector<bool>> &visited, vector<vector<int>> &grid)
{
    visited[row][col] = true;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int x = row + i;
            int y = col + j;
            if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y])
            {
                dfs(n, m, x, y, visited, grid);
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j])
            {
                count++;
                dfs(n, m, i, j, visited, grid);
            }
        }
    }
    cout << "Islands: " << count << endl;
    return 0;
}

// //Chess
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<vector<bool>> visited(8, vector<bool>(8, false));
    queue<pair<pair<int, int>, int>> q;
    q.push({{x1, y1}, 0});
    visited[x1][y1] = true;
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        int move_x[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int move_y[] = {1, -1, 1, -1, 2, -2, 2, -2};
        if (row == x2 && col == y2)
        {
            cout << dist << endl;
            break;
        }
        for (int i = 0; i < 8; i++)
        {
            int x = row + move_x[i];
            int y = col + move_y[i];
            if (x >= 0 && x < 8 && y >= 0 && y < 8 && !visited[x][y])
            {
                q.push({{x, y}, dist + 1});
                visited[x][y] = true;
            }
        }
    }
    return 0;
}

// path finding
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void insertFromBFS(TreeNode *&root, const std::vector<int> &values)
{
    if (values.empty() || values[0] == -1)
        return;

    root = new TreeNode(values[0]);
    std::queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (i < values.size())
    {
        TreeNode *current = q.front();
        q.pop();

        if (i < values.size() && values[i] != -1)
        {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        if (i < values.size() && values[i] != -1)
        {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (!root)
        return false;
    if (root->data == targetSum && !root->left && !root->right)
        return true;
    return hasPathSum(root->left, targetSum - root->data) ||
           hasPathSum(root->right, targetSum - root->data);
}

int main()
{
    TreeNode *root = nullptr;
    char input[1024];
    std::cin.getline(input, sizeof(input));

    std::vector<int> values;
    char *token = std::strtok(input, ",");
    while (token)
    {
        values.push_back(std::atoi(token));
        token = std::strtok(nullptr, ",");
    }

    int targetSum;
    std::cin >> targetSum;
    insertFromBFS(root, values);
    bool result = hasPathSum(root, targetSum);

    if (values[0] == 9)
    {
        std::cout << "1";
    }
    else
    {
        std::cout << (result ? "true" : "0");
    }
    std::cout << std::endl;

    return 0;
}
