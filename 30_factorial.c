#include <stdio.h>
typedef long long ll;
ll factorial(int n){
    ll sum = 1;
    for (int i = 1; i <= n; i++)
        sum *= i;
    return sum;
}

int main(){
    int n;
    scanf("%d", &n);
    ll ans = factorial(n);
    printf("%lld ", ans);
}