#include<stdio.h>
#include<stdbool.h>
#include<windows.h>
#include <vadefs.h>
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int answer;
void printboard()
{
	int i, j;
	printf("------------- \n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			printf("| %c ", board[i][j]);
		printf("| \n");
		printf("------------- \n");
	}
}
void ClearGrid()
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = '1' + (i + j);
			if (board[1][j])
			{
				board[1][j] = '2' + (i + j);
			}
			if (board[2][j])
			{
				board[2][j] = '5' + (i + j);
			}
		}
	}

}
bool WinCondition()
{
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
		return 1;
	else if (board[1][0] == board[1][1] && board[1][1] == board[1][2])

		return 1;
	else if (board[2][0] == board[2][1] && board[2][1] == board[2][2])

		return 1;
	else if (board[0][0] == board[1][0] && board[1][0] == board[2][0])

		return 1;
	else if (board[0][1] == board[1][1] && board[1][1] == board[2][1])

		return 1;
	else if (board[0][2] == board[1][2] && board[1][2] == board[2][2])

		return 1;
	else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return 1;
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return 1;
	else
		return 0;
}
void updateBoard(int choice, char x, bool player)
{
	if (choice == 1 && board[0][0] == '1')
		board[0][0] = x;
	else if (choice == 2 && board[0][1] == '2')
		board[0][1] = x;
	else if (choice == 3 && board[0][2] == '3')
		board[0][2] = x;
	else if (choice == 4 && board[1][0] == '4')
		board[1][0] = x;
	else if (choice == 5 && board[1][1] == '5')
		board[1][1] = x;
	else if (choice == 6 && board[1][2] == '6')
		board[1][2] = x;
	else if (choice == 7 && board[2][0] == '7')
		board[2][0] = x;
	else if (choice == 8 && board[2][1] == '8')
		board[2][1] = x;
	else if (choice == 9 && board[2][2] == '9')
		board[2][2] = x;
	else {
		if (player == true) {
			printf("Invalid move\n");
			scanf("%d", &choice);
			updateBoard(choice, x, true);
		}
		else
		{
			int y = 1 + rand() % 10;
			updateBoard(y, x, false);
		}

	}
}

void play()
{
	bool win1=false, win2 = false;
	int counter = 0;
	int choice, choice2;
	while (win1 == false && win2 == false && counter < 9)
	{
		printf("player 1 Move");
		scanf("%d", &choice);
		updateBoard(choice, 'X', true);
		printboard();
		win1 = WinCondition();
		if (win1 == true)
			break;
		printf("player 2 Move");
		scanf("%d", &choice2);
		updateBoard(choice2, 'O', true);
		counter += 2;
		printboard();
		win2 = WinCondition();
	}
	if (win1 == false && win2 == false)
		printf("draw");
	else if (win1 == true && win2 == false)
		printf("player1 wins !");
	else
		printf("player2 wins !");
}

void pvc()
{
	bool win1 = false;
	bool win2 = false;
	int counter = 0, choice;
	printboard();
	while (win1 == false && win2 == false && counter < 9)
	{
		printf("player 1 enter a number");
		scanf("%d", &choice);
		updateBoard(choice, 'X', true);
		win1 = WinCondition();
		if (win1 == true)
			break;
		int x = 1 + rand() % 10;
		updateBoard(x, 'O', false);
		counter += 2;
		printboard();
		win2 = WinCondition();
	}
	printboard();
	if (win1 == false && win2 == false)
		printf("draw");
	else if (win1 == true && win2 == false)
		printf("player1 wins !");
	else
		printf("player2 wins !");

}

int main()
{

	do {
		printboard();
		printf("(Player VS Player)  Press : 1\n");
		printf("(Player VS Computer)  Press : 2\n");
		int x;
		scanf("%d", &x);
		if (x == 1)
			play();
		else if (x == 2)
			pvc();
		printf("if you want to re play put 0\n");
		printf("if you want to exit play put 1\n");
		scanf("%u", &answer);
		ClearGrid();
	} while (answer == 0);
	printf("\n\n\n");

}