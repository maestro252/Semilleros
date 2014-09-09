#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
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
vector <int> pasar(int n){ //el numero debe ser menor a 1024 aun no funciona
	vector<int> numero(11,0);
	bool sale = false;
	for (int i = 0; i < numero.size() and !sale; ++i)
	{
		if(n < pow(2, i)){
			numero[i - 1] = 1;
			n -= pow(2,i - 1);
			if(n <= 0) sale = true;
		}else if(n == pow(2, i)){
			sale = true;
			numero[i] = 1;
		}
	}
	reverse(numero.begin(), numero.end());
	
	for (int i = 0; i < numero.size(); ++i)
	{
		cout << numero[i];
	}
	cout << endl;
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
		cout << n << " en base 2 es: ";
		vector <int> numerito = pasar(n);
		cout << base << endl;
	}
	return 0;
}