#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;
#define n 14

vector<int> grsort(vector<int> & a, int farray[n][n]) 
{
	auto sortingFunc = [&farray](int i, int j)
	{
		return  farray[int (i/n)][int (i-(i/n)*n)] < farray[int (j/n)][int (j-(j/n)*n)];
	};

	sort(a.begin(), a.end(), sortingFunc);
	return a;
}

int place(int p, int q)
	{
	return (p)*n+(q	);
	}




int main(int argc, char *argv[])
{
int h[n][n];
int f[n][n];
int g[n][n];
int road[n][n];
int len=0;
int t=0;
int istart=atoi(argv[1]);
int jstart=atoi(argv[2]);// (2-1)*n+(3-1)
int ifinal=atoi(argv[3]);
int jfinal=atoi(argv[4]); // 3*6+4=22;
bool mark[n][n];
int link[n*n];


for (int i=0; i<n; i++)
{
	for (int j=0; j<n; j++)
	{
	road[i][j]=0;
	g[i][j]=1;
	h[i][j]=(i-ifinal)*(i-ifinal)+(j-jfinal)*(j-jfinal);
	f[i][j]=h[i][j]+g[i][j];
	mark[i][j]=true;
 	
	}
}
for (int i=0; i<n; i++) {mark[0][i]=false;mark[i][0]=false;mark[n-1][i]=false;mark[i][n-1]=false;}
for (int i=2; i<8; i++)
{
mark[i][7]=false;
mark[7][i]=false;
mark[i+4][10]=false;
}
for (int i=0; i<4; i++)
{
mark[i][4]=false;
mark[i+4][9]=false;
mark[9][i+5]=false;
}
bool wall[n][n];

for (int i=0; i<n; i++)
	for (int j=0; j<n; j++)
	wall[i][j]=mark[i][j];


mark[istart][jstart]=false;
road[istart][jstart]=len;
len++;

vector<int> openlist(0);
vector<int> closedlist(0);


/*
openlist.push_back(place(istart,jstart)+1); mark[istart][jstart+1]=false; 
openlist.push_back(place(istart,jstart)-1); mark[istart][jstart-1]=false;
openlist.push_back(place(istart,jstart)+n); mark[istart+1][jstart]=false; 
openlist.push_back(place(istart,jstart)-n); mark[istart+1][jstart]=false; 
openlist=grsort(openlist,f);
*/
openlist.push_back(place(istart,jstart));
int y=0;
int ic=istart;
int jc	=jstart;
link[ic*n+jc]=ic*n+jc;
//road[len]=place(ic,jc);
//len++;

while (openlist[0]!=((ifinal)*n+jfinal))
{
//for (int i=0; i<n; i++ )
//{cout<<f[openlist[i]/n*n][openlist[i]-openlist[i]/n*n]<< "\t";}
//cout << endl;
ic=openlist[0]/n;
jc=openlist[0]-openlist[0]/n*n;
road[ic][jc]=len;
len++;
mark[ic][jc]=false;

openlist.erase(openlist.begin());
openlist=grsort(openlist,f);
y=place(ic,jc);
if ((y<(n*n-1))&&mark[ic][jc+1]) {openlist.push_back(y+1); mark[ic][jc+1]=false;  link[ic*n+jc+1]=ic*n+jc; f[ic][jc+1]=f[ic][jc]+1;} ;
if ((y>0)&&mark[ic][jc-1]) {openlist.push_back(y-1); mark[ic][jc-1]=false;link[ic*n+jc-1]=ic*n+jc;f[ic][jc-1]=f[ic][jc]+1;};
if ((y<(n*n-n))&&mark[ic+1][jc]) {openlist.push_back(y+n); mark[ic+1][jc]=false;link[ic*n+jc+n]=ic*n+jc; f[ic+1][jc]=f[ic][jc]+1;};
if ((y>n)&&mark[ic-1][jc]) {openlist.push_back(y-n); mark[ic-1][jc]=false;link[ic*n+jc-n]=ic*n+jc; f[ic-1][jc]=f[ic][jc]+1;};
openlist=grsort(openlist,f);
t=0;
//while (t<openlist.size())
//{
//if (openlist[t]==openlist[t+1]) {openlist.erase(openlist.begin()+t+1);};
//t++;
//}



//openlist[0]=22;
};
ic=openlist[0]/n;
jc=openlist[0]-openlist[0]/n*n;
road[ic][jc]=len;
len++;
mark[ic][jc]=false;

cout << endl;
/*
for (int i=1; i<n-1; i++ )
{
	for (int j=1; j<n-1; j++)
	{
		if (wall[i][j]!=false)
			cout << road[i][j]<< "\t";
		else  cout << "X"<< "\t";
	}
cout << endl;
}
cout << len << " ";

*/
int qaz[n*n];
qaz[0]=ifinal*n+jfinal;
qaz[1]=0;
char map[n][n];
for (int i=1; i<n-1; i++)
{
	for (int j=1; j<n-1; j++)
	{map[i][j]=' ' ;
	
	}
}



int qq=0; 
while (qaz[qq]!=qaz[qq-1])
{
qaz[qq+1]=link[qaz[qq]];
qq++;
}

//cout << endl;
for (int i=0; i<qq; i++)
{
map[qaz[i]/n][qaz[i]-qaz[i]/n*n]='@';
//cout << qaz[i]/n << "," << qaz[i]-qaz[i]/n*n<< "\t"; 
}
//cout << endl;

for (int i=1; i<n-1; i++)
{
	for (int j=1; j<n-1; j++)
	{
	if (wall[i][j]==false) {map[i][j]='X' ;};
	
	}
}
cout  << "            ";
for (int i=1; i<n-1; i++) {cout  << "__";}; cout <<endl;
for (int i=1; i<n-1; i++)
{
cout  << "           ";
cout << '|';
	for (int j=1; j<n-1; j++)
	{
	cout << map[i][j] << " ";
	
	}
cout << '|'<< endl;
}
cout  << "          ";
for (int i=1; i<n-1; i++) {cout  << "";};

    return 0;
}

