#include <iostream>
#include <vector>
using namespace std;

void coin_collecting(vector<vector<int>> C, int n, int m) {
    vector<vector<int>> F(n, vector<int>(m, 0));
    F[0][0] = C[0][0];
    for (int i = 1; i < n; i++) {
        F[i][0] = F[i-1][0] + C[i][0]; // First column
    }
    for (int j = 1; j < m; j++) {
        F[0][j] = F[0][j-1] + C[0][j]; // First row
    }
    // Fill the rest of the matrix
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            F[i][j] = max(F[i-1][j], F[i][j-1]) + C[i][j];
        }
    }

    // The bottom-right corner contains the maximum number of coins
    cout << "Maximum coins collected: " << F[n-1][m-1] << endl;
}

int main() {
    vector<vector<int>> C = {
        {0, 3, 1, 1},
        {2, 0, 0, 4},
        {1, 5, 3, 1}
    };
    
    int n = C.size();    // Number of rows
    int m = C[0].size(); // Number of columns

    coin_collecting(C, n, m);

    return 0;
}
