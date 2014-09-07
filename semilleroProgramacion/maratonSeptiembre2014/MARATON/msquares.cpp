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

bool pruebe(vector <int> v,int arrS){
    int a;
    switch(arrS){
    case 2:
        a = (v[0]+v[1]);
        return (a==(v[2]+v[3]))&&(a==(v[1]+v[2]))&&(a==(v[0]+v[3]))&&(a==(v[0]+v[2]))&&(a==(v[3]+v[1]));
        break;
    case 3:
        a = (v[0]+v[1]+v[2]);
        return a==(v[3]+v[4]+v[5])&&a==(v[6]+v[7]+v[8])&&a==(v[0]+v[3]+v[6])&&a==(v[1]+v[4]+v[7])&&a==(v[5]+v[8]+v[2])&&a==(v[0]+v[4]+v[8])&&a==(v[4]+v[6]+v[2]);
        break;
    case 4:
        a = (v[0]+v[1]+v[2]+v[3]);
        return a==(v[4]+v[5]+v[6]+v[7])&&a==(v[8]+v[9]+v[10]+v[11])&&a==(v[12]+v[13]+v[14]+v[15])&&a==(v[0]+v[4]+v[8]+v[12])&&a==(v[1]+v[5]+v[9]+v[13])&&a==(v[6]+v[10]+v[2]+v[14])&&a==(v[7]+v[11]+v[15]+v[3])&&a==(v[0]+v[5]+v[10]+v[15])&&a==(v[6]+v[9]+v[12]+v[3]);
        break;
    default:
        return false;
        break;
    }
}

int main () {
    string x;
    vector <int> vec;
    while(getline(cin, x )){
        int matriz[4][4];
        bool aceptado=0;
        vec.clear();
        //cout << x << endl;
        for (int i=x.size()-1;i>=0;i--){
            int j = 0;
            int num = 0;
            while(x[i]!=' '&&i>=0){
                if(x[i]!='-'){
                    num += pow(10,j)*(x[i] -'0');
                    j++;
                    i--;
                }
                else{
                    num*=-1;
                    i--;
                }
            }
            //cout << num << endl;
            vec.push_back(num);
        }
        if(vec.size()== 1 ){

            cout << "Y"<<endl;
        }else if (vec.size()== 4 || vec.size()== 9 || vec.size()== 16){
            int arrSize = sqrt(vec.size());
            /*
            for(int i = 0; i < arrSize; i++){
               for(int j = 0; j < arrSize; j++){
                    matriz[i][j]=vec.back();
                    vec.pop_back();
               }
            }
            for(int i = 0; i < arrSize; i++){
               for(int j = 0; j < arrSize; j++){
                   cout << matriz[i][j]<< ", ";
               }
               cout << endl;
            }*/
            for(int i = 0; i < (arrSize*arrSize)*(arrSize*arrSize); i++){
                int cam = vec[0];
                for(int j = 0; j < (arrSize*arrSize)-1; j++){
                    vec[j]=vec[j+1];
                    vec[j+1]=cam;
                    if(pruebe(vec,arrSize)){
                        aceptado = true;
                    } else aceptado = false;
                    //if( aceptado){
                    //    break;
                    //}
                }
                //if( aceptado){
                //        break;
                //}
            }
            if( aceptado){
                cout << "Y"<<endl;
            }else{
            cout << "N"<<endl;
            }
        }else{
            cout << "N"<<endl;
        }
    }
    return 0;
}
