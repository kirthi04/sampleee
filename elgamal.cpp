#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ll long long


ll p = 19801,
e1 = 11, e2 = 1331;
ll xa = 3;

ll binpow(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

pair<ll, ll> elga_encrypt(ll plt, ll p, ll e1, ll e2)
{
    ll rand_k, C1, C2, temp;
    rand_k = rand() % (p - 1) + 1;
    cout << "Random k is " << rand_k << "\n";
    
	temp = binpow(e2, rand_k, p);
    C1 = binpow(e1, rand_k, p);
    C2 = (temp * plt) % p;
    
    return {C1, C2};
}

ll elga_decrypt(pair<ll, ll> cit, ll p, ll xa)
{
    ll K = binpow(cit.first, xa, p);
    ll M = (cit.second * binpow(K, p - 2, p)) % p;
    return M;
}


int main()
{
    srand(time(NULL));
    ll plt;
    cout << "Enter the plain text ";
    cin >> plt;
    pair<ll, ll> cit = elga_encrypt(plt, p, e1, e2);
    cout << "The Ciphertext ( C1, C2 )  for the given plain text is : ( " << cit.first << ", " << cit.second << " )\n";

    cout << "Plaintext got after after decryption is " << elga_decrypt(cit, p, xa) << endl;
}
