#include<cstdio>
#include<cstdlib>
#include<cstring>
#define lint long long int


char str[1080];
int z[1050];
void zfunc()
{
	memset(z,0,sizeof(z));
	
	int L,R;
	L = R = 0;
	int sl = strlen(str);
	z[0] = sl;
	 for (int i=1; i<sl; ++i)
    {
        // i'，i用s[L, R]映至i'
        // 向左移動L單位
        // s[L]移到s[0]，減了L；s[i]移到s[i-L]，也是減了L。
        int ii = i - L;
		 // j+z(j)映射到字串開頭的位置
        // s[i]移到s[0]，減了i；s[R+1]移到s[R+1-i]，也是減了i。
        int n = R + 1 - i;
 
        // 已經算好的部份都派不上用場
        if (i > R)
        {
            // 從s[i]與s[0]開始比對，逐字比下去。
            int x = i;
            while (x < sl && str[x] == str[x-i]) x++;
            z[i] = x - i;
 
            // 更新s[0 ... z(j)-1] = s[j ... j+z(j)-1]。
            if (x > i) L = i, R = x - 1;
        }
        // s[i ... i+z(i')-1]貼齊或超出s[j ... j+z(j)-1]的右端
        else if (z[ii] >= n)
        {
            // 從s[R+1]與s[R+1-i]開始比對，逐字比下去。
            int x = R + 1;
            while (x < sl && str[x] == str[x-i]) x++;
            z[i] = x - i;
 
            // 更新s[0 ... z(j)-1] = s[j ... j+z(j)-1]。
            L = i;
            R = x - 1;
        }
        else
        {
            z[i] = z[ii];
        }
    }
	
}
int used[1050];
int main(void)
{
	
	int T;
	scanf("%d",&T);
	int i,j,k;
	
	while(T--)
	{
		scanf("%s",str);
		int l = strlen(str);
		zfunc();
		int ans = l;
		memset(used,0,sizeof(used));
		for(i=l-1;i>=0;i--)
		if(used[i]==0&&z[i]!=0)
		{
			int sk = z[i];
			k = z[i];
			int ch = 0;
			if(l%k==0)
			{
				j = i-k;
				while(j>=0)
				{
					if(z[j]!=sk+k)
						ch = 1;
					sk+=k;
					if(ch==0)
						used[j] = 1;
					j-=k;
					
				}
				if(ch==0&&ans>k)
					ans = k;
					
			}
		}
		printf("%d\n",ans);
		if(T)
		printf("\n");
		
		
	}
	
	
	return 0;
}
