#include <iostream>
#include <string>
#include <set>
using namespace std;
 
class graphNode
{
public:
    char val;
    graphNode *up;
    graphNode *down;
    graphNode *left;
    graphNode *right;
};
 
string ansPath = "";
bool checkPath(graphNode *node, char dir, string path, set<graphNode*> visited)
{
    if(node->val != 'A')
        path.push_back(dir);
    if (node->val == 'B')
    {
        if (ansPath == "" || path.length() < ansPath.length())
            ansPath = path;
        return true;
    }
    if (visited.count(node) == 1)
        return false;
    visited.insert(node);
    bool result = false;
    if (node->up && node->up->val != '#')
        result |= checkPath(node->up, 'U', path, visited);
    if (node->down && node->down->val != '#')
        result |= checkPath(node->down, 'D', path, visited);
    if (node->left && node->left->val != '#')
        result |= checkPath(node->left, 'L', path, visited);
    if (node->right && node->right->val != '#')
        result |= checkPath(node->right, 'R', path, visited);
    return result;
}
 
int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    graphNode *startNode = nullptr;
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
            if (newNode->val == 'A')
                startNode = newNode;
        }
    }
    if (checkPath(startNode, 'A', "", set<graphNode*>()))
    {
        cout << "YES\n"
             << ansPath.length() << "\n" + ansPath;
    }
    else
    {
        cout << "NO";
    }
}