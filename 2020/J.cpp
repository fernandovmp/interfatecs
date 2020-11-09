#include <bits/stdc++.h>
using namespace std;

int main(){
    double H, C, L;
    while(1){
	cin >> H >> C >> L;
	if(H==0.0 && C==0.0 && L==0.0)
		break;
	if(H*100/C<=8.334 && L>=0.80)
		cout << "PROJETO SIMPLES\n";
	else
		cout << "PROJETO ESPECIAL\n";}
	return 0;
}
