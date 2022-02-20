#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> grid(9);   //grille vide à modifier lors de l'execution du programme

void inputsudoku()
{
    int nb;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
		    cin>>nb;
            grid[i].push_back(nb);
		}

	}
}
void printsudoku()
{
    cout<<endl;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout<<"\t"<<grid[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}

bool isvalid(int row, int col, int num)
{	int r,c;
	for(c=0;c<9;c++)
	{
		if(grid[row][c]==num)
		{
			return false;
		}
	}
	for(r=0;r<9;r++)
	{
		if(grid[r][col]==num)
		{
			return false;
		}
	}
	row=row-(row%3);
	col=col-(col%3);
	for(int i=row;i<row+3;i++)
	{
		for(int j=col;j<col+3;j++)
		{
			if(grid[i][j]==num)
			{
				return false;
			}
		}
	}
	return true;

}
void solver()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(grid[i][j]==0)
			{
				for(int n=1;n<10;n++)
				{
					if(isvalid(i,j,n))
					{
						grid[i][j]=n;            // Backtracking Algorithm
						solver();
						grid[i][j]=0;

					}

				}
				return;

			}

		}
	}

	printsudoku();

}


int main()
{
    inputsudoku();        //donner 0 pour toute case vide

	cout<<endl<<"le sudoku a resoudre:"<<endl;

	printsudoku();
    cout<<"la/les solution(s): "<<endl;
	solver();


	return 0;

}
