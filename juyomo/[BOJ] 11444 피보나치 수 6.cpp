// Author: Juyoung Moon
// https://www.acmicpc.net/problem/11444

#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1000000007;

void multiplyMatrices(vector<vector<long long>>& m1,
                      vector<vector<long long>>& m2) {
    long long a = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
    long long b = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];
    long long c = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
    long long d = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];

    m1[0][0] = a % mod;
    m1[0][1] = b % mod;
    m1[1][0] = c % mod;
    m1[1][1] = d % mod;
}

void getAn(vector<vector<long long>>& A, long long n) {
    if ( n == 1 ) {
        return;
    }

    vector<vector<long long>> original = A;
    if ( n % 2 == 0 ) {
        multiplyMatrices(A, original); // A ^ 2
        getAn(A, n / 2);
        return;
    } else {
        multiplyMatrices(A, original);
        getAn(A, n / 2);
        multiplyMatrices(A, original);
    }
}

void multiplyMatrixAndVector(const vector<vector<long long>>& A, vector<long long>& v) {
    long long v0 = v[0];
    long long v1 = v[1];
    v[0] = (v0 * A[0][0] + v1 * A[0][1]) % mod;
    v[1] = (v0 * A[1][0] + v1 * A[1][0]) % mod;
}

long long calcFib(long long n) {
    if (n < 2) {
        return n;
    }

    vector<vector<long long>> A = {{1, 1}, {1, 0}};
    getAn(A, n);

    vector<long long> fib = {1, 0};
    multiplyMatrixAndVector(A, fib);
    
    return fib[1] % mod;
}

int main() {
    long long n;
    cin >> n;
    cout << calcFib(n) << endl;
    return 0;
}
