#include <stdio.h>
int dr[5][4]={
	{0,0,0,0},
	{2,1,1,3},
	{4,2,2,1},
	{1,3,3,4},
	{3,4,4,2}
};
int dxyr[2][2]={
	{1,2},
	{3,4}
};
int dx[5][4]={
	{0,0,0,0},
	{0,0,-1,-3},
	{-3,0,-1,0},
	{3,0,1,0},
	{0,0,1,3}
};
int dy[5][4]={
	{0,0,0,0},
	{-3,0,-1,0},
	{0,0,1,3},
	{0,0,-1,-3},
	{3,0,1,0}
};
int ddo[5][2]={
	{0,0},
	{1,1},
	{1,0},
	{0,1},
	{0,0}
};
int crossify[5][2]={
	{0,0},
	{1,1},
	{1,-1},
	{-1,1},
	{-1,-1}
};
void tri(int x,int y,int r,int sz) {
// 1 2
// 3 4
	if (sz==1) {
		printf("%d %d %d\n",x+1,y+1,r);
	} else {
		for (int i=0;i<4;++i)
		tri(2*x+ddo[r][0]+dx[r][i],
		    2*y+ddo[r][1]+dy[r][i],
		    dr[r][i],
		    sz-1);
	}
}
int main(int argc, char *argv[])
{
	int k,x,y,dx,dy;
	scanf("%d",&k);
	scanf("%d%d",&x,&y);
	--x;--y;
	for (int i=1;i<=k;++i) {
		dx=x%2;
		dy=y%2;
		int r=dxyr[dx][dy];
		tri(x+crossify[r][0],y+crossify[r][1],r,i);
		// putchar('\n');
		x/=2;
		y/=2;
	}
}