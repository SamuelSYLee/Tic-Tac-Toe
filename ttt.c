/**
*** How to Program C
*** Test Week 10 - Tic Tac Toe
**/

#include <stdio.h>
#include "ttt.h"

void init(TicTacToe *ttt)
{
	int i, j, k = 0;
	
	for(i = 0; i < 3; i ++)
	{
		for(j = 0; j < 3; j ++)
		{
			k += 1;
			ttt->board[i][j] = k;
		}
	}
}

int play(TicTacToe *ttt, int move[9])
{
	const int plr_A = 0, plr_B = 11;
	int flag = 1;	// A => flag = 1; B => flag = 0
	int i, j, k = 0, cnt = 0;
	int diag_temp = 0;
	
	while(k < 9)
	{	
		for(i = 0; i < 3; i ++)
		{
			for(j = 0; j < 3; j ++)
			{	
				cnt ++;
				if(flag)
				{
					if(move[k] == ttt->board[i][j])
					{
						ttt->board[i][j] = plr_A;
						cnt = 0;
						break;
					}
				}
				else
				{
					if(move[k] == ttt->board[i][j])
					{
						ttt->board[i][j] = plr_B;
						cnt = 0;
						break;
					}
				}
			}
		}
		
		if(cnt > 8)
		{
			if(flag)
			{
				printf("A has a illegal move %d!!\n", move[k]);
				return -1;
			}
			else
			{
				printf("B has a illegal move %d!!\n", move[k]);
				return -1;
			}	
		}
		
		printf("move[%d] = %d, flag = %d\n", k, move[k], flag);
		for(i = 0; i < 3; i ++)
		{
			for(j = 0; j < 3; j ++)
			{
				printf("%3d ", ttt->board[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		
		for(i = 0; i < 3; i ++)
		{
			if(ttt->board[i][0] == ttt->board[i][1] && ttt->board[i][1] == ttt->board[i][2])
			{
				if(ttt->board[i][0] == plr_A)
				{
					printf("A wins at move %d!!!\n", move[k]);
					return 0;
				}
				else
				{
					printf("B wins at move %d!!!\n", move[k]);
					return 0;
				}
			}
			
			if(ttt->board[0][i] == ttt->board[1][i] && ttt->board[1][i] == ttt->board[2][i])
			{
				if(ttt->board[0][i] == plr_A)
				{
					printf("A wins at move %d!!!\n", move[k]);
					return 0;
				}
				else
				{
					printf("B wins at move %d!!!\n", move[k]);
					return 0;
				}
			}
		}
		
		if(ttt->board[0][0] == ttt->board[1][1] && ttt->board[2][2] == ttt->board[1][1])
		{
			if(ttt->board[0][0] == plr_A)
			{
				printf("A wins at move %d!!!\n", move[k]);
				return 0;
			}
			else
			{
				printf("B wins at move %d!!!\n", move[k]);
				return 0;
			}
		}

		if(ttt->board[0][2] == ttt->board[1][1] && ttt->board[2][0] == ttt->board[1][1])
		{
			if(ttt->board[1][1] == plr_A)
			{
				printf("A wins at move %d!!!\n", move[k]);
				return 0;
			}
			else
			{
				printf("B wins at move %d!!!\n", move[k]);
				return 0;
			}
		}
		
		flag = !flag;
		k ++;
	}
	
	printf("It's a draw!!\n");
	return 1;
}

int main(void)
{
	TicTacToe ttt;
	int move[9];
	int i, j;

	init(&ttt);
	
	for(i = 0; i < 9; i ++)
	{
		scanf("%d", &move[i]);
	}
	
	play(&ttt, move);
	
	printf("\n");
	for(i = 0; i < 3; i ++)
	{
		for(j = 0; j < 3; j ++)
		{
			printf("%3d ", ttt.board[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}