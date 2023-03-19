#include <bits/stdc++.h>
using namespace std;

#define N 4

bool isSafe(int *board, int row, int col)
{
    for (int j = 0; j < col; j++)
    {
        if (*(board + (row * N) + j))
            return false;
    }
    for (int i = 0; i < row; i++)
    {
        if (*(board + (i * N) + col))
            return false;
    }
    // for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    //     if (*(board + (N * row) + col))
    //         return false;
    int k = row - 1;
    for (int i = row; i >= 0; i--)
    {
        for (int j = col; j >= 0; j--)
        {
            if (j == k)
            {
                if (*(board + (N * i) + j) == 1)
                    return false;
            }
        }
        k--;
    }
    return true;
}
bool nQueen(int *board, int row)
{
    if (row == N)
        return true;
    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col))
        {
            *(board + (N * row) + col) = 1;
            if (nQueen(board, row + 1))
                return true;
            *(board + (N * row) + col) = 0;
        }
    }
    return false;
}
void print_board(int *board, int side)
{
    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            cout << *(board + (i * N) + j) << "\t";
        }
        cout << "\n";
    }
}
int main()
{
    int side = 4;
    // cout << "Enter number of box in a row in the board: ";
    // cin >> side;
    int board[side][side];
    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            board[i][j] = 0;
        }
    }
    nQueen((int *)board, 0);
    print_board((int *)board, side);
    return 0;
}