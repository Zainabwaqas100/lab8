#include <iostream>
using namespace std;

const int MAX = 100;

int rods[3][MAX];
int top[3] = {-1, -1, -1};

void moveDisk(int from, int to, char names[])
{
    if (top[from] == -1)
    {
        rods[from][++top[from]] = rods[to][top[to]--];
        cout << "Move disk " << rods[from][top[from]]
             << " from " << names[to]
             << " to " << names[from] << endl;
    }
    else if (top[to] == -1)
    {
        rods[to][++top[to]] = rods[from][top[from]--];
        cout << "Move disk " << rods[to][top[to]]
             << " from " << names[from]
             << " to " << names[to] << endl;
    }
    else if (rods[from][top[from]] < rods[to][top[to]])
    {
        rods[to][++top[to]] = rods[from][top[from]--];
        cout << "Move disk " << rods[to][top[to]]
             << " from " << names[from]
             << " to " << names[to] << endl;
    }
    else
    {
        rods[from][++top[from]] = rods[to][top[to]--];
        cout << "Move disk " << rods[from][top[from]]
             << " from " << names[to]
             << " to " << names[from] << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    if (n < 1 || n > MAX)
    {
        cout << "Invalid number of disks\n";
        return 0;
    }

    char names[3] = {'A', 'B', 'C'};

    for (int i = n; i >= 1; i--)
        rods[0][++top[0]] = i;

    int totalMoves = (1 << n) - 1;

    int source = 0;
    int auxiliary = 1;
    int destination = 2;

    if (n % 2 == 0)
    {
        int temp = destination;
        destination = auxiliary;
        auxiliary = temp;
    }

    for (int i = 1; i <= totalMoves; i++)
    {
        if (i % 3 == 1)
            moveDisk(source, destination, names);
        else if (i % 3 == 2)
            moveDisk(source, auxiliary, names);
        else
            moveDisk(auxiliary, destination, names);
    }

    return 0;
}
