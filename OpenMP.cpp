// usual.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>

using namespace std;

typedef long long ll;

const ll mod = 1'000'000'000'000'000'003;

ll multiply(ll a, ll b)
{
	ll res = 0;
	while (b > 0)
	{
		if (b & 1) res = (res + a) % mod;
		a = (a + a) % mod;
		b /= 2;
	}
	return res;
}

int main()
{
	int n;
	cout << "Input n: ";
	cin >> n;

	auto begin = clock();

	const int T = 100;
	ll resT[T+1];
	for (int i = 1; i <= T; i++)
		resT[i] = 1;

#pragma  omp parallel for
	for (int i = 1; i <= T; i++)
	{
		for (int j = i; j <= n; j += T)
			resT[i] = multiply(resT[i], j);
	}
	ll res = 1;
	for (int i=1; i<=T; i++)
		res = multiply(res, resT[i]);
	cout << "n! = " << res << " mod 10^18+3\n";

	auto end = clock();
	cout << "Time: " << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
