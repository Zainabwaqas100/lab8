#include <iostream>
using namespace std;

int main()
{
    int n; 
    cout << "Enter value for row and column: ";
    cin >> n;

    int arr[100][100];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    int left = 0;
    int right = n - 1;
    int peakRow = -1;
    int peakCol = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        int maxRow = 0;

        for (int i = 1; i < n; i++)
        {
            if (arr[i][mid] > arr[maxRow][mid])
                maxRow = i;
        }

        bool leftSmaller =
            (mid == 0 || arr[maxRow][mid] >= arr[maxRow][mid - 1]);

        bool rightSmaller =
            (mid == n - 1 || arr[maxRow][mid] >= arr[maxRow][mid + 1]);

        if (leftSmaller && rightSmaller)
        {
            peakRow = maxRow;
            peakCol = mid;
            break;
        }
        else if (mid > 0 && arr[maxRow][mid - 1] > arr[maxRow][mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    if (peakRow != -1)
        cout << "Peak element: " << arr[peakRow][peakCol]
             << "\nPosition: (" << peakRow << ", " << peakCol << ")\n";

    return 0;
}
