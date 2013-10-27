#include<cstdio>
#include<cstdlib>
#include<cstring>
#define SSS struct SS

SSS
{
	int a,b;
	int sum;
};
SSS an[50000000];
int S[1005];
int cmp(const void *a,const void *b)
{
	SSS x = *((SSS*)a);
	SSS y = *((SSS*)b);
	
	return x.sum-y.sum;
	
}
int qcmp(const void *a,const void *b)
{
	int x = *((int*)a);
	int y = *((int*)b);
	return x-y;
}
int main(void)
{
	int n;
	int i,j,k;
	int kn;
	while(~scanf("%d",&n)&&n)
	{
		kn = 0;
		for(i=0;i<n;i++)
			scanf("%d",&S[i]);
		qsort(S,n,sizeof(S[0]),qcmp);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				an[kn].sum = S[i]+S[j];
				an[kn].a = i;
				an[kn].b = j;
				kn++;
			}
	
	qsort(an,kn,sizeof(an[0]),cmp);
	int ans = -1;
	int l,r,m;
	for(i=n-1;i>=0&&ans==-1;i--)
		for(j=0;j<i&&ans==-1;j++)
		{
			int dif = S[i]-S[j];
			l = 0;
			r = kn-1;
			while(l<r)
			{
				
				m = (l+r)/2;
				if(dif>an[m].sum)
					l = m+1;
				else
					r = m;
			}
			if(an[r].sum==dif)
			{
				if(an[r].a!=i&&an[r].b!=i&&an[r].a!=j&&an[r].b!=j)
					ans = S[i];
			}
		}
		if(ans==-1)
			printf("no solution\n");
		else
			printf("%d\n",ans);
	}
	
	return 0;
}
