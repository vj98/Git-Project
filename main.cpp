//
//  Created by Vijay Bhati on 13/10/18.
//  Copyright © 2018 Vijay Bhati. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <map>
#include <sstream>
#include <set>
#include <iomanip>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <numeric>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <memory>
#define ll long long
#define ull unsigned long long
#define pi acos(-1.0)
#define rf freopen("in.txt", "r", stdin);
#define ld long double
#define all(v) v.begin(),v.end()
#define pb push_back
#define P pair<ll, ll>
#define ff first
#define ss second
#define F first
#define S second
#define MOD 1000000007
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)

using namespace std;

ll max(ll a, ll b) {
    return a > b ? a : b;
}

ll min(ll a, ll b) {
    return a > b ? b : a;
}

ll __gcd(ll a, ll b) {
    if (a == 0) {
        return b;
    }
    return __gcd(b%a, a);
}

int isprime[100000];
vector <int> prime;

void sieve() {
    for (int i = 2; i < 100000; i++) {
        isprime[i] = 1;
    }
    
    for (int i = 2; i * i <= 100000; i++) {
        if (isprime[i]) {
            for (int j = 2*i; j < 100000; j+=i) {
                isprime[j] = 0;
            }
        }
    }
    
    for (int i = 2; i < 100000; i++) {
        if (isprime[i]) {
            prime.push_back(i);
        }
    }
}

int main() {
#ifdef __APPLE__
    const clock_t begin_time = clock();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    ll t;
    cin >> t;
    while (t--) {
        sieve();
        int n, f = 0, i = 0;
        cin >> n;
        
        
        for (int i = 0; i < prime.size(); i++) {
            while (n % prime[i] == 0) {
                n /= prime[i];
                cout << prime[i] << endl;
            }
            if (n == 0) {
                f = 1;
                break;
            }
        }
        cout << n << endl;
        if (f) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
#ifdef __APPLE__
    cout << endl;
    cout << "Time : ";
    cout << float( clock () - begin_time ) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}
