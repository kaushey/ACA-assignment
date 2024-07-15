#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

// Function to multiply two matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& a, const vector<vector<int>>& b, int size) {
    vector<vector<int>> result(size, vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result[i][j] = (result[i][j] + 1LL * a[i][k] * b[k][j] % MOD) % MOD;
            }
        }
    }
    return result;
}

// Function to perform matrix exponentiation
vector<vector<int>> powerMatrix(vector<vector<int>> matrix, int power, int size) {
    vector<vector<int>> result(size, vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        result[i][i] = 1; // Initialize result as the identity matrix
    }

    while (power > 0) {
        if (power % 2 == 1) {
            result = multiplyMatrices(result, matrix, size);
        }
        matrix = multiplyMatrices(matrix, matrix, size);
        power /= 2;
    }

    return result;
}

int main() {
    int size, power;
    cin >> size >> power;

    // Read the adjacency matrix
    vector<vector<int>> adjMatrix(size, vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> adjMatrix[i][j];
        }
    }

    // Calculate the matrix raised to the given power
    vector<vector<int>> resultMatrix = powerMatrix(adjMatrix, power, size);

    // Calculate the sum of all elements in the resulting matrix
    int totalSum = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            totalSum = (totalSum + resultMatrix[i][j]) % MOD;
        }
    }

    // Output the result
    cout << totalSum << endl;
    return 0;
}
