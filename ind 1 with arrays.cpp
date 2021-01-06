#include <iostream>
#include <string>

using namespace std;

int size(string s) // returns the size of string
{
    for (int i = 0; i < 1000000; i++)
    {
        if (s[i] == '\0')
            return i;
    }
}

void reverse(string &s) // reverses the string
{
    string s1;
    for (int i = size(s) - 1; i >= 0; i--)
    {
        s1 += s[i];
    }
    s = s1;
}

int from5to10(string five) // converts from 5 base to 10 base
{
    reverse(five);
    int ans = 0;
    int curr = 1;
    for (int i = 0; i < size(five); i++)
    {
        ans += curr * (five[i] - '0');
        curr *= 5;
    }
    return ans;
}

char remainder(int n)
{
    /*
    returns the remainder for 15-base system
    if the remained >= 10 returns the appropriate letter (from A to D)
    */

    if (n < 10)
        return n + '0';
    else
        return char(n - 10 + 'A');
}

string from10to15(int ten) // converts from 10 base to 15 base
{
    string ans;
    while (ten != 0)
    {
        ans += remainder(ten % 15);
        ten /= 15;
    }

    reverse(ans);
    return ans;
}

int main()
{
    string five;
    cout << "Enter the 5-base number: ";
    cin >> five;
    cout << "Your 15-base number: ";
    cout << from10to15(from5to10(five));
}