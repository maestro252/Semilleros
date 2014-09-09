#include <iostream>
#include <vector>

using namespace std;

long divisores(long long n){
	long res = 0;
	for (long long i = 1; i < n; ++i)
	{
		if(n % i == 0) res += i;

	}
	return res;
}

/*long long suma(vector<long long> a){
	long long res = 0;
	for (long long i = 0; i < a.size(); ++i)
	{
		res += a[i];
	}
	return res;
}
*/
void perfectos(long long n){
	for (long long i = 0; i <= n; ++i)
	{
		if(divisores(i) == i) cout << i << endl;
	}
}

int main(){
	long long x;
	cout << "Ingrese el limite" << endl;
	cin >> x;
	perfectos(x);
	return 0;
}