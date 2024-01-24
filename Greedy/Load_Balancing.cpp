// LOAD BALANCING(SPOJ)
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    while (true)
    {
        int n;
        cin >> n;

        if (n == -1)
        {
            break;
        }

        vector<int> v(n);
        int sum = 0, ans = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
        }

        if ((sum % n) != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            int average = sum / n;
            sum = 0;

            for (int i = 0; i < n; i++)
            {
                sum += (average - v[i]);
                ans = max(ans, abs(sum));
            }

            cout << ans << endl;
        }
    }

    return 0;
}
