#include<cstdio>
#include<cassert>
#include<algorithm>
using namespace std;
struct Node{
	Node *ch[4];
	int z;
	int x[2];
	int mx[2],mn[2];
	int sum;
	Node(){
		ch[0]=ch[1]=ch[2]=ch[3]=nullptr;
	}
};
bool is_in_range(Node* rt,int x,int y){
	x^=rt->x[0];y^=rt->x[1];
	return (x|y)<(1<<rt->z);
}
void pushup(Node* rt){
	rt->sum=0;
	rt->mx[0]=rt->mx[1]=0;
	rt->mn[0]=rt->mn[1]=0x7fffffff;
	for(int i=0;i<4;++i){
		if(rt->ch[i]==nullptr)continue;
		rt->sum+=rt->ch[i]->sum;
		rt->mx[0]=max(rt->mx[0],rt->ch[i]->mx[0]);
		rt->mx[1]=max(rt->mx[1],rt->ch[i]->mx[1]);
		rt->mn[0]=min(rt->mn[0],rt->ch[i]->mn[0]);
		rt->mn[1]=min(rt->mn[1],rt->ch[i]->mn[1]);
	}
}
int get_st(Node* rt,int x,int y){
	return ((((rt->x[0]^x)>>(rt->z-1))&1)<<1)|(((rt->x[1]^y)>>(rt->z-1))&1);
}
void set_node(Node* rt,int x,int y,int val){
	rt->z=0;
	rt->x[0]=rt->mn[0]=rt->mx[0]=x;
	rt->x[1]=rt->mn[1]=rt->mx[1]=y;
	rt->sum=val;
}
/**
 * User must ensure that (x,y) lies with in range of rt.
 */
Node* insert(Node* rt,int x,int y,int val){
	//assert(is_in_range(rt,x,y));
	int st=get_st(rt,x,y);//get the children id
	if((rt->ch[st])==nullptr){
		Node *ch=new Node;
		set_node(ch,x,y,val);
		rt->ch[st]=ch;
		pushup(rt);
		return rt;
	}else if(is_in_range(rt->ch[st],x,y)){
		if(rt->ch[st]->z==0){
			rt->ch[st]->sum+=val;
		}else{
			insert(rt->ch[st],x,y,val);
		}
		pushup(rt);
		return rt;
	}else{
		Node *s=rt->ch[st],*t=new Node,*u=new Node;
		set_node(u,x,y,val);
		rt->ch[st]=t;
		t->z=rt->z-1;
		int s1,s2;
		while(1){
			t->x[0]=x^(x&((1<<t->z)-1));
			t->x[1]=y^(y&((1<<t->z)-1));
			s1=get_st(t,x,y),s2=get_st(t,s->x[0],s->x[1]);
			if(s1==s2)--t->z;
			else break;
		}
		t->ch[s1]=u;
		t->ch[s2]=s;
		pushup(t);
		pushup(rt);
		return rt;
	}
}
int qrycnt=0;
int query(Node* rt,int mx[2],int mn[2]){
	qrycnt++;
	if(mn[0]<=rt->mn[0]&&rt->mx[0]<=mx[0]&&mn[1]<=rt->mn[1]&&rt->mx[1]<=mx[1])return rt->sum;
	else if(mx[0]<rt->mn[0]||rt->mx[0]<mn[0]||mx[1]<rt->mn[1]||rt->mx[1]<mn[1])return 0;
	int ans=0;
	if(rt->ch[0]!=nullptr)ans+=query(rt->ch[0],mx,mn);
	if(rt->ch[1]!=nullptr)ans+=query(rt->ch[1],mx,mn);
	if(rt->ch[2]!=nullptr)ans+=query(rt->ch[2],mx,mn);
	if(rt->ch[3]!=nullptr)ans+=query(rt->ch[3],mx,mn);
	return ans;
}
int main(){
	Node* root=new Node;
	root->z=30;
	//freopen("data.in","r",stdin);
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;scanf("%d%d",&x,&y);
		root=insert(root,x,y,i);
	}
	int Mx=0,Mn=0x3f3f3f3f;
	long long sum=0;
	for(int i=1;i<=100000;i++){
		int lx,rx,ly,ry;scanf("%d%d%d%d",&lx,&rx,&ly,&ry);
		int mx[2]={rx,ry},mn[2]={lx,ly};
		qrycnt=0;
		printf("%d\n",query(root,mx,mn));
		Mx=max(Mx,qrycnt);
		Mn=min(Mn,qrycnt);
		sum+=qrycnt;
	}
	printf("mx=%d,mn=%d,avg=%lf\n",Mx,Mn,(double)sum/100000);
	return 0;
}