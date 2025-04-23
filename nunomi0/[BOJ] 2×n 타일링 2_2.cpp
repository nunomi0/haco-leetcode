#include <iostream>
using namespace std;

int a=1,b=1,n;
int main() {
     cin >> n;
     for (int i = 0; i < n; i++) {
          int temp = a;
          a = (b * 2 + a) % 10007;
          b = temp;
     }
     cout << b;
}
