#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string x, y;
        int n;
        cin >> n;
        cin >> x >> y;
        int correct = 0, xc = 0, yc = 0;
        for (int i = 0; i < n; i++)
        {
            if (x[i] != y[i])
            {
                if (x[i] == '1')
                    xc++;
                if (y[i] == '1')
                    yc++;
            }
        }
        cout << max(xc, yc) << endl;
    }

    return 0;
}
