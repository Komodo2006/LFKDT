#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("data.in","w",stdout);
	int n;scanf("%d",&n);
	printf("%d\n",n);
	mt19937 rnd(time(0));
	int mxsize=(1<<30);
	for(int i=1;i<=n;i++){
		int x=rnd()%mxsize,y=rnd()%mxsize;
		printf("%d %d\n",x,y);
	}
	for(int i=1;i<=100000;i++){
		int l,r;
		l=rnd()%mxsize,r=rnd()%mxsize;
		if(l>r)swap(l,r);
		printf("%d %d ",l,r);
		l=rnd()%mxsize,r=rnd()%mxsize;
		if(l>r)swap(l,r);
		printf("%d %d\n",l,r);
	}
	return 0;
}