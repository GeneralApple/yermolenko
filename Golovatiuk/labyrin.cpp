#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int lab[7][7];
	int dist[7][7];
	for (int i=0; i<7; ++i)
	{
		for (int j=0; j<7; ++j)
		{
			lab[i][j]=0; dist[i][j]=0;
		}
	}
	for (int i=1; i<5; ++i) { lab[i][1]=1; }
	lab[4][2]=1; lab[5][2]=1; lab[0][6]=1; lab[3][5]=1;
	lab[1][3]=1; lab[3][3]=1; //lab[4][3]=1;
	for (int i=1; i<7; ++i) { lab[i][4]=1; }
	lab[4][4]=0; lab[2][0]=3; lab[6][5]=5;
	for (int i=0; i<7; ++i)
	{
		for (int j=0; j<7; ++j)
		{
			cout << lab[i][j];
		}
		cout << endl;
	}


	queue<int*> togo;
	int di[4] = {-1,0,1,0};
	int dj[4] = {0,1,0,-1};
	bool finish = false;
	int* copa = new int[2];
	copa[0] = 2;
	copa[1] = 0;
	togo.push(copa);
	dist[copa[0]][copa[1]] = 1;
	while (!togo.empty())
	{
	 if (!finish)
	 {
		for (int i=0; i<4; ++i)
		{
			int* copa = new int[2];
			copa[0] = togo.front()[0] + di[i];
			copa[1] = togo.front()[1] + dj[i];
			if ( copa[0]>=0 && copa[0]<7 && copa[1]>=0 && copa[1]<7 )
			{
				if (lab[copa[0]][copa[1]]!=1 && dist[copa[0]][copa[1]]==0)
				{
					dist[copa[0]][copa[1]] = dist[copa[0]-di[i]][copa[1]-dj[i]] + 1;
					togo.push(copa);
					if (lab[copa[0]][copa[1]]==5) { finish = true;}
				}
			}
		}
	 }
	 togo.pop();
	}

	cout << endl;
	for (int i=0; i<7; ++i)
	{
		for (int j=0; j<7; ++j)
		{
			cout << dist[i][j] <<"\t";
		}
		cout << endl;
	}

	
return 0;
}
