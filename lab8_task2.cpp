#include <iostream>
using namespace std;

const int MAX = 20;

int board[MAX][MAX];

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool solve(int x, int y, int moveNo, int n)
{
    if (moveNo == n * n + 1)
        return true;

    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n
            && board[nx][ny] == 0)
        {
            board[nx][ny] = moveNo;

            if (solve(nx, ny, moveNo + 1, n))
                return true;

            board[nx][ny] = 0;
        }
    }

    return false;
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    if (n < 1 || n > MAX || x < 0 || x >= n
        || y < 0 || y >= n)
    {
        cout << "Invalid input\n";
        return 0;
    }

    board[x][y] = 1;

    if (solve(x, y, 2, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << "\t";

            cout << endl;
        }
    }
    else
    {
        cout << "No tour found\n";
    }

    return 0;
}
