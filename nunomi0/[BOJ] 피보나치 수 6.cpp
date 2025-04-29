#include <iostream>
#include <unordered_map>
#define mod 1000000007
using ll = unsigned long long;
using namespace std;

// if (n==0) F(n)=0
// if (n==1 || n==2) F(n)=1
// if (n%2==0) F(n)=F(n/2) * { F(n/2+1) + F(n/2-1) }
// if (n%2==1) F(n) = F((n-1)/2+1)^2 + F((n-1)/2)^2

ll n;
unordered_map<ll,ll> F;

ll fibo(ll n) {
    if (n==0)
        return F[0]; // 0은 값 자체가 0이라 예외
    if (F[n])
        return F[n]; // 채워져 있으면 그게 답
    if (n%2==0)
        F[n] = (fibo(n/2) % mod * (fibo(n/2+1) % mod + fibo(n/2-1) % mod)) % mod;
    if (n%2==1)
        F[n] = (((fibo((n-1)/2+1) % mod) * (fibo((n-1)/2+1) % mod)) % mod + ((fibo((n-1)/2) % mod) *  (fibo((n-1)/2) % mod)) % mod) % mod;
    return F[n];
}

int main() {
    cin >> n;
    F[0] = 0;
    F[1] = F[2] = 1;
    cout << fibo(n);
}
