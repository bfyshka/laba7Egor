#include <iostream>

using namespace std;

char m = 0;

int size(string s)
{
    for (int i = 0; i < 1000; i++)
    {
        if (s[i] == '\0') return i;
    }
    return -1;
}

int fix(char c)
{
    if (c <= '9') return (c - '0');
    return (c - 'A' + 10);
}

char fix(int n)
{
    if (n <= 9) return (n + '0');
    return (n - 10 + 'A');
}

void deleteminus(string &s)
{
    string res;
    for (int i = 1; i < size(s); i++)
    {
        res += s[i];
    }
    s = res;
}

void fixsize(string &s1, string &s2)
{
    while (size(s1) > size(s2))
    {
        s2 = '0' + s2;
    }

    while (size(s1) < size(s2))
    {
        s1 = '0' + s1;
    }

    for (int i = 0; i < size(s1); i++)
    {
        if (fix(s1[i]) < fix(s2[i]))
        {
            swap(s1, s2);
            m = '-';
            return;
        }

        if (fix(s1[i]) > fix(s2[i]))
        {
            return;
        }
    }
}

string addition(string s1, string s2)
{
    string result;
    int n = size(s1);
    int to_add = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = fix(s1[i]) + fix(s2[i]) + to_add;
        to_add = 0;
        if (curr >= 15)
        {
            to_add = curr / 15;
            curr %= 15;
        }

        result = fix(curr) + result;
    }
    if (to_add != 0)
    {
        result = fix(to_add) + result;
    }
    return result;
}

string substraction(string s1, string s2)
{
    string result;
    int n = size(s1);
    int to_sub = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = fix(s1[i]) - fix(s2[i]) - to_sub;
        to_sub = 0;
        if (curr < 0)
        {
            to_sub = 1;
            curr += 15;
        }

        result = fix(curr) + result;
    }
    return result;
}

int main()
{
    string number1, number2;
    cout << "Enter two numbers: " << endl;
    cin >> number1 >> number2;
    cout << "The result of addition two 15-base numbers: ";
    if (number1[0] == '-' && number2[0] == '-')
    {
        deleteminus(number1);
        deleteminus(number2);
        fixsize(number1, number2);
        cout << "-" << addition(number1, number2);
        return 0;
    }

    if (number1[0] == '-')
    {
        deleteminus(number1);
        fixsize(number1, number2);
        cout << m + substraction(number1, number2);
        return 0;
    }

    if (number2[0] == '-')
    {
        deleteminus(number2);
        fixsize(number2, number2);
        cout << m + substraction(number1, number2);
        return 0;
    }
    fixsize(number1, number2);
    cout << addition(number1, number2);
    return 0;
}