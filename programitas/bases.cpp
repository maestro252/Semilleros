#include<iostream>
#include<vector>
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

int main(){
int n;
cin >> n;
int b;
cin >> b;
vector <int> num;
num = bases(n,b);
for(int i = num.size() - 1; i >= 0; --i){
  cout <<  num[i] << " ";
}
return 0;
}
