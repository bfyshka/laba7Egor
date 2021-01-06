#include <iostream>
#include <string>

using namespace std;

char ost(int n)
{
    /*
    returns the remainder for 15-base system
    if the remained >= 10 returns the appropriate letter (from A to D)
    */

    if (n < 10)
        return n + '0';
    else
        return char(n - 10 + 'C');
}

void reverse(string &s, int n) // reverses the string
{
    string s1;
    for (int i = n - 1; i >= 0; i--)
    {
        s1 += s[i];
    }
    s = s1;
}

int pow(int n, int step) // analog for "cmath" pow
{
    int ans = 1;
    for (int i = 1; i <= step; i++)
    {
        ans *= n;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of 5-base number: ";
    cin >> n;
    int current_step = pow(5, n - 1);
    char curr;
    int ten = 0;
    string ans;
    cout << "Enter the 5-base number: ";
    for (int i = 0; i < n; i++)
    {
        cin >> curr;
        ten += (curr - '0') * current_step;
        current_step /= 5;
    }

    while (ten != 0)
    {
        ans += ost(ten % 15);
        ten /= 15;
    }

    reverse(ans, n);

    cout << "Your 15-base number: ";
    cout << ans;
}