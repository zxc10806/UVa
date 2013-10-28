/*
11818 - Mouse & a Cheese
Solution: dp

*/


#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;
#define MAX 1<<13
#define St struct SS
#define EAT 1
#define WIN 2
#define LOSE 3

St
{
	int x,y;
	int x2,y2;
	int a,b;
	
};
St ss[105];
int dp[MAX];
int sn = 0;
int mapp[5000];

void init(void)
{
	memset(mapp,0,sizeof(mapp));
	int key;	
	ss[sn].a = 1;
	ss[sn].b = 2;
	ss[sn].x = 1;
	ss[sn].y = 0;
	ss[sn].x2 =1;
	ss[sn].y2 = 1;
	key = ss[sn].x*1000+ss[sn].y*100+ss[sn].x2*10+ss[sn].y2;
	mapp[key]=sn;
	sn++;
	ss[sn].a = 2;
	ss[sn].b = 3;
	ss[sn].x = 2;
	ss[sn].y = 0;
	ss[sn].x2 =2;
	ss[sn].y2 = 1;
	key = ss[sn].x*1000+ss[sn].y*100+ss[sn].x2*10+ss[sn].y2;
	mapp[key]=sn;
	sn++;
	ss[sn].a = 1;
	ss[sn].b = 4;
	ss[sn].x = 0;
	ss[sn].y = 1;
	ss[sn].x2 =1;
	ss[sn].y2 = 1;
	key = ss[sn].x*1000+ss[sn].y*100+ss[sn].x2*10+ss[sn].y2;
	mapp[key]=sn;
	sn++;
	ss[sn].a = 2;
	ss[sn].b = 5;
	ss[sn].x = 1;
	ss[sn].y = 1;
	ss[sn].x2 =2;
	ss[sn].y2 = 1;
	key = ss[sn].x*1000+ss[sn].y*100+ss[sn].x2*10+ss[sn].y2;
	mapp[key]=sn;
	sn++;
	ss[sn].a = 3;
	ss[sn].b = 6;
	ss[sn].x = 2;
	ss[sn].y = 1;
	ss[sn].x2 =3;
	ss[sn].y2 = 1;
	key = ss[sn].x*1000+ss[sn].y*100+ss[sn].x2*10+ss[sn].y2;
	mapp[key]=sn;
	sn++;
	ss[sn].a = 4;
	ss[sn].b = 5;
	ss[sn].x = 1;
	ss[sn].y = 1;
	ss[sn].x2 =1;
	ss[sn].y2 = 2;
	key = ss[sn].x*1000+ss[sn].y*100+ss[sn].x2*10+ss[sn].y2;
	mapp[key]=sn;
	sn++;
	ss[sn].a = 5;
	ss[sn].b = 6;
	ss[sn].x = 2;
	ss[sn].y = 1;
	ss[sn].x2 =2;
	ss[sn].y2 = 2;
	key = ss[sn].x*1000+ss[sn].y*100+ss[sn].x2*10+ss[sn].y2;
	mapp[key]=sn;
	sn++;
	ss[sn].a = 4;
	ss[sn].b = 7;
	ss[sn].x = 0;
	ss[sn].y = 2;
	ss[sn].x2 =1;
	ss[sn].y2 = 2;
	key = ss[sn].x*1000+ss[sn].y*100+ss[sn].x2*10+ss[sn].y2;
	mapp[key]=sn;
	sn++;
	ss[sn].a = 5;
	ss[sn].b = 8;
	ss[sn].x = 1;
	ss[sn].y = 2;
	ss[sn].x2 =2;
	ss[sn].y2 = 2;
	key = ss[sn].x*1000+ss[sn].y*100+ss[sn].x2*10+ss[sn].y2;
	mapp[key]=sn;
	sn++;
	ss[sn].a = 6;
	ss[sn].b = 9;
	ss[sn].x = 2;
	ss[sn].y = 2;
	ss[sn].x2 =3;
	ss[sn].y2 = 2;
	key = ss[sn].x*1000+ss[sn].y*100+ss[sn].x2*10+ss[sn].y2;
	mapp[key]=sn;
	sn++;
	ss[sn].a = 7;
	ss[sn].b = 8;
	ss[sn].x = 1;
	ss[sn].y = 2;
	ss[sn].x2 =1;
	ss[sn].y2 = 3;
	key = ss[sn].x*1000+ss[sn].y*100+ss[sn].x2*10+ss[sn].y2;
	mapp[key]=sn;
	sn++;
	ss[sn].a = 8;
	ss[sn].b = 9;
	ss[sn].x = 2;
	ss[sn].y = 2;
	ss[sn].x2 =2;
	ss[sn].y2 = 3;
	key = ss[sn].x*1000+ss[sn].y*100+ss[sn].x2*10+ss[sn].y2;
	mapp[key]=sn;
	sn++;
	
}

int adj[10][10];

int dps(int state,int s,int t)
{
	if(dp[state]!=0)
		return dp[state];
	int i,j,k;
	memset(adj,0,sizeof(adj));
	for(i=0;i<12;i++)
		{
			int y = (1<<i);
			if(state&y)
			{
				int a = ss[i].a;
				int b = ss[i].b;
				adj[a][b] = 1;
				adj[b][a] = 1;
			}
		}
		for(k=1;k<=9;k++)
			for(i=1;i<=9;i++)
				for(j=1;j<=9;j++)
				 adj[i][j] |= (adj[i][k]&&adj[k][j]);
		if(adj[s][t]==1)
		{
			dp[state] = EAT;
			return dp[state];
		}
	for(i=0;i<12;i++)
	{
		int y = (1<<i);
		if(!(state&y))
		{
			int r = state+y;
			int c = dps(r,s,t);
			if(c==EAT)
			{
				dp[state] = WIN;
				return dp[state];
			}
		}
	}
	for(i=0;i<12;i++)
	{
		int y = (1<<i);
		if(!(state&y))
		{
			int r = state+y;
			int c = dps(r,s,t);
		
			if(c==LOSE)
			{
				dp[state] = WIN;
				return dp[state];
			}
		}
	}
	dp[state] = LOSE;
	return dp[state];
}

int main(void)
{
	int S;
	int C;
	int R;
	init();
	int T;
	scanf("%d",&T);
	int t = 1;
	int i,j,k;
	int x,y,x2,y2;
	while(T--)
	{
		scanf("%d %d %d",&S,&C,&R);
		memset(dp,0,sizeof(dp));
		int s = 0;
		for(i=0;i<R;i++)
		{
			
			scanf("%d %d %d %d",&x,&y,&x2,&y2);
			
			if(x>x2)
			{
				t = x;
				x = x2;
				x2 = t;
				t = y;
				y = y2;
				y2 = t;
			}
			if(x==x2&&y>y2)
			{
				t = x;
				x = x2;
				x2 = t;
				t = y;
				y = y2;
				y2 = t;
			}
			int key = x*1000+y*100+x2*10+y2;
			int num = mapp[key];
			
			s=s+(1<<num);
			
			
		}
	
		memset(adj,0,sizeof(adj));
		
		for(i=0;i<12;i++)
		{
		
			int y = (1<<i);
			
			if(s&y)
			{
				
				int a = ss[i].a;
				int b = ss[i].b;
				adj[a][b] = 1;
				adj[b][a] = 1;
				
				
				
			}
			
			
		}
		for(k=1;k<=9;k++)
			for(i=1;i<=9;i++)
				for(j=1;j<=9;j++)
				 adj[i][j]|=adj[i][k]&&adj[k][j];
		
		
		if(adj[S][C]==1)
		{
			printf("Case %d: No Cheese!\n",t++);
		}
		else
		{
			dps(s,S,C);
			int c = dp[s];
			printf("Case %d: ",t++);
			if(c==WIN)
				printf("SOHA\n");
			else
				printf("TARA\n");
		}
		
	}
	
	
	
	return 0;
}
