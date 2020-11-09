#include <bits/stdc++.h>
using namespace std;
struct pontos{
	int X;
	int Y;
};
int main(){
	int N, R;
	cin >> N >> R;
	int i, cont=0, j, a, b, mediaX, mediaY, cont1, posicao;
	double menor;
	pontos p[N];
	pontos c[N];
	for(i=0;i<N;i++){
		c[i].X=-1;
		c[i].Y=-1;
		cin >> p[i].X >> p[i].Y;
	}
	for(i=0;i<N;i++){
		if(cont==0){
			c[cont].X=p[i].X;
			c[cont].Y=p[i].Y;
			cont++;
			continue;
		}
		menor=99999999;
		mediaX=0;
		mediaY=0;
		cont1=0;
		for(j=0;j<cont;j++){
			if((sqrt(pow((p[i].X-c[j].X),2)+pow((p[i].Y-c[j].Y),2))<menor) ||((sqrt(pow((p[i].X-c[j].X),2)+pow((p[i].Y-c[j].Y),2))==menor) && posicao>j)){
				menor=sqrt(pow((p[i].X-c[j].X),2)+pow((p[i].Y-c[j].Y),2));
				a=c[j].X;
				b=c[j].Y;
				posicao=j;}
		}
		if(menor>R){
			c[cont].X=p[i].X;
			c[cont].Y=p[i].Y;
			cont++;
			continue;
		}
		else{
			for(j=0;j<=i;j++){
				if(sqrt(pow((p[j].X-c[posicao].X),2)+pow((p[j].Y-c[posicao].Y),2))<=R){
					mediaX+=p[j].X;
					mediaY+=p[j].Y;
					cont1++;
				//	cout << p[i].X << " " << p[i].Y << "\n\n";
				}
					
			}
			mediaX/=cont1;
			mediaY/=cont1;
			
			c[posicao].X=mediaX;
			c[posicao].Y=mediaY;
		}
			
}
	cout << cont << "\n";
	for(i=0;i<cont;i++)
		cout << c[i].X << " " << c[i].Y << "\n";
	return 0;
}
