#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

const int MAX_N = 16; // Maximum number of vertices

int n; // Number of vertices
double graph[MAX_N][MAX_N]; // Graph representing distances between vertices
double memo[MAX_N][1 << MAX_N]; // Memoization table
int parent[MAX_N][1 << MAX_N]; // Table to store parent nodes
double dp(int pos, int bitmask);
void tsp() {
    // Initialize memoization table
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < (1 << n); ++j) {
            memo[i][j] = -1;
            parent[i][j] = -1;
        }

    double distance = dp(0, 1);
    cout << "Distance: " << distance << endl;

    // Construct the solution path
    vector<int> path;
    int cur_node = 0;
    int cur_mask = 1;
    while (cur_node != -1) {
        path.push_back(cur_node);
        int nxt_node = parent[cur_node][cur_mask];
        cur_mask |= (1 << cur_node); // Update current mask
        cur_node = nxt_node;
    }

    // Output the solution path
    cout << "Path: ";
    for (int node : path)
        cout << node << " ";
    cout << endl;
}

double dp(int pos, int bitmask) {
    if (bitmask == (1 << n) - 1 && pos == 0)
        return 0; // Return to starting vertex
    if (memo[pos][bitmask] != -1)
        return memo[pos][bitmask];
    double ans = numeric_limits<double>::max();
    for (int nxt = 0; nxt < n; ++nxt) {
        if (nxt != pos && !(bitmask & (1 << nxt))) {
            double cur_value = graph[pos][nxt] + dp(nxt, bitmask | (1 << nxt));
            if (ans > cur_value) {
                ans = cur_value;
                parent[pos][bitmask] = nxt; // Store parent node
            }
        }
    }
    memo[pos][bitmask] = ans;
    return ans;
}

int main() {
    // Sample graph initialization
    n = 4;
    double sample_graph[MAX_N][MAX_N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            graph[i][j] = sample_graph[i][j];

    tsp();

    return 0;
}
