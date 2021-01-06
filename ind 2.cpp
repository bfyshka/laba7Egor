#include <iostream>

using namespace std;

int size(string s)
{
    for (int i = 0; i < 10000; i++)
    {
        if (s[i] == '\0')
            return i;
    }
}

void reverse(string &s)
{
    string s1;
    for (int i = size(s) - 1; i >= 0; i--)
    {
        s1 += s[i];
    }
    s = s1;
}

int todec(string s)
{
    reverse(s);
    int curr = 1;
    int ans = 0;
    for (int i = 0; i < size(s); i++)
    {
        ans += curr * (s[i] - '0');
        curr *= 2;
    }
    return ans;
}

int main()
{
    string dop;
    cout << "Number in an additional code form: ";
    cin >> dop;
    int n = size(dop);

    if (dop[0] == '1')
    {
        if (dop[n - 1] == '1') dop[n - 1] = '0';
        else
        {
            for (int i = n; i > 0; i--)
            {
                dop[i] = '1';
                if (dop[i - 1] == '1')
                {
                    dop[i - 1] = '0';
                    break;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (dop[i] == '0') dop[i] = '1';
            else if (dop[i] == '1') dop[i] = '0';
        }
    }

    string curr;
    for (int i = 1; i < n; i++)
        curr += dop[i];

    int ans = todec(curr);
    if (dop[0] == '1') ans *= -1;
    cout << "The number in natural form: " << ans << endl;
}