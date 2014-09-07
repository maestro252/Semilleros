using namespace std;

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <iterator>
#include <cstdlib>
#include <numeric>
#include <climits>
#include <cassert>

vector <int> bases (int n, int base){
    vector <int> numero;
    int naux;
    while(n>=base) {
        numero.push_back(n%base);
        naux=n;
        n = n/base;
    }
    numero.push_back(naux/base);
    reverse(numero.begin(), numero.end());
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
            /*
            for (int j=0; j<numero.size() && iguales ; ++j) {
                if(numero[j]!=palindromo[j]) iguales=false;
            }
            */
            if(numero!=palindromo)iguales=false;

            if(iguales) break;
        }
        cout << base << endl;
    }
    return 0;
}
