#include <iostream>
#include <vector>
using namespace std;

vector <int> bases (int n, int base){
	vector <int> numero;
	int naux;
	while(n>=base) {
		numero.push_back(n%base);
		naux=n;
		n = n/base;
	}
	numero.push_back(naux/base);
	return numero;
}

bool comparar(vector<int> a){
	for (int i = 0; i < (a.size()/2); ++i)
	{
		if(a[i] != a[(a.size() - i - 1)]) return false;
	}
	return true;
}
int main () {
	int n;
	while(cin >> n) {
		for (int i=2; i < n; ++i) {
			vector <int> numero = bases(n,i);
			if(comparar(numero)){ cout << i << endl; break; }
		}
	}
	return 0;
}