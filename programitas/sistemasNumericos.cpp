#include <iostream>
#include <string>
#include <sstream>
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
int main () {
	int n;
	while(cin >> n) {
		int base = 0;
		for (int i=2; i < n; ++i) {
			base = i;
			vector <int> numero = bases(n,i);
			vector <int> palindromo = numero;
			reverse(palindromo.begin(), palindromo.end());
			bool iguales=true;
			if(numero!=palindromo)iguales=false;
			if(iguales) break;
		}
		cout << base << endl;
	}
	return 0;
}