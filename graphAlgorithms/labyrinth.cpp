#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

char calcDirection(int start, int end, int columnCount)
{
    if (start - end == columnCount)
        return 'U';
    if (end - start == columnCount)
        return 'D';
    if (start - end == 1)
        return 'L';
    if (end - start == 1)
        return 'R';
}

int findMin(int dist[], bool finalHash[], int count)
{
    int minDis = INT32_MAX, minIndex;
    for (int i = 0; i < count; i++)
    {
        if (!finalHash[i] && dist[i] <= minDis)
        {
            minIndex = i;
            minDis = dist[i];
        }
    }
    return minIndex;
}

string dijsktra(int graph[], int start, int end, int columnCount, int rowCount)
{
    int count = columnCount * rowCount;

    int dist[count];
    bool finalHash[count];
    string path[count];
    for (int i = 0; i < count; i++)
    {
        dist[i] = INT32_MAX;
        finalHash[i] = false;
        path[i] = "";
    }

    dist[start] = 0;
    for (int i = 0; i < count - 1; i++)
    {
        int next = findMin(dist, finalHash, count);
        finalHash[next] = true;
        for (int x = 0; x < count; x++)
        {
            if (!finalHash[x] && graph[next * count + x] && dist[next] != INT32_MAX && dist[next] + graph[next * count + x] < dist[x])
            {
                dist[x] = dist[next] + graph[next * count + x];
                path[x] = path[next];
                path[x].push_back(calcDirection(next, x, columnCount));
            }
        }
    }

    return path[end];
}

int main()
{
    long long n = 0, m = 0;
    cin >> n >> m;
    int *graph = (int *)malloc(sizeof(int) * n * m * n * m);
    char prevRow[m];
    int startIndex, endIndex;
    for (int i = 0; i < n; i++)
    {
        char prevChar;
        char rowVal[m];
        scanf("%s", rowVal);
        for (int j = 0; j < m; j++)
        {
            char newChar = rowVal[j];
            if (j != 0)
            {
                if (prevChar != '#')
                    graph[(i * m + j - 1) * n * m + i * m + j] = ((newChar == '#') ? 0 : 1);
                if (newChar != '#')
                    graph[(i * m + j) * n * m + i * m + j - 1] = ((prevChar == '#') ? 0 : 1);
            }
            if (i != 0)
            {
                if (prevRow[j] != '#')
                    graph[((i - 1) * m + j) * n * m + i * m + j] = ((newChar == '#') ? 0 : 1);
                if (newChar != '#')
                    graph[(i * m + j) * n * m + (i - 1) * m + j] = ((prevRow[j] == '#') ? 0 : 1);
            }
            prevChar = newChar;
            prevRow[j] = newChar;
            if (newChar == 'A')
                startIndex = i * m + j;
            if (newChar == 'B')
                endIndex = i * m + j;
        }
    }
    string ans = dijsktra(graph, startIndex, endIndex, m, n);
    if (ans.length() == 0)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES\n"
             << ans.length() << "\n" + ans;
    }
}