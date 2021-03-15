#include <iostream>
#include <string>
using namespace std;

class graphNode
{
public:
    char val;
    graphNode *up;
    graphNode *down;
    graphNode *left;
    graphNode *right;
    bool visited;
    // void printUp()
    // {
    //     graphNode *node = this;
    //     while (node)
    //     {
    //         cout << node->val;
    //         node = node->up;
    //     }
    //     cout << "\n";
    // };
    // void printDown()
    // {
    //     graphNode *node = this;
    //     while (node)
    //     {
    //         cout << node->val;
    //         node = node->down;
    //     }
    //     cout << "\n";
    // };
    // void printLeft()
    // {
    //     graphNode *node = this;
    //     while (node)
    //     {
    //         cout << node->val;
    //         node = node->left;
    //     }
    //     cout << "\n";
    // };
    // void printRight()
    // {
    //     graphNode *node = this;
    //     while (node)
    //     {
    //         cout << node->val;
    //         node = node->right;
    //     }
    //     cout << "\n";
    // };
    // void printGraph()
    // {
    //     graphNode *node = this;
    //     while (node)
    //     {
    //         node->printRight();
    //         node = node->down;
    //     }
    // }
};

void recurse(graphNode *node, int *count, int depth)
{
    if (node->visited)
        return;
    if (depth == 0)
        *count = *count + 1;
    node->visited = true;
    if (node->up && node->up->val == '.')
        recurse(node->up, count, depth + 1);
    if (node->down && node->down->val == '.')
        recurse(node->down, count, depth + 1);
    if (node->left && node->left->val == '.')
        recurse(node->left, count, depth + 1);
    if (node->right && node->right->val == '.')
        recurse(node->right, count, depth + 1);
}

int countRooms(graphNode *topLeftNode)
{
    int count = 0;
    while (topLeftNode)
    {
        graphNode *rowNode = topLeftNode;
        while (rowNode)
        {
            if (rowNode->val == '.')
            {
                recurse(rowNode, &count, 0);
            }
            rowNode = rowNode->right;
        }
        topLeftNode = topLeftNode->down;
    }
    return count;
}

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    graphNode *topLeftNode = nullptr;
    graphNode *prevRow[m];
    for (int i = 0; i < n; i++)
    {
        graphNode *prevNode;
        string rowVal;
        cin >> rowVal;
        for (int j = 0; j < m; j++)
        {
            graphNode *newNode = new graphNode;
            newNode->val = rowVal[j];
            newNode->visited = false;
            if (j != 0)
            {
                prevNode->right = newNode;
                newNode->left = prevNode;
            }
            if (i != 0)
            {
                prevRow[j]->down = newNode;
                newNode->up = prevRow[j];
            }
            prevNode = newNode;
            prevRow[j] = newNode;
            if (i + j == 0)
                topLeftNode = newNode;
        }
    }
    // topLeftNode->printGraph();
    cout << countRooms(topLeftNode);
}