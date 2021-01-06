#include <iostream>
//rabotaet 75/25
using namespace std;

int size(string s)
{
    for (int i = 0; i < 10000; i++)
    {
        if (s[i] == '\0') return i;
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

string natural_to_direct(int dec)
{
    int mod;
    string bin;
    while (dec)
    {
        mod = dec % 2;
        dec /= 2;
        bin += to_string(abs(mod)); 
    }
    for(int i = 0; i < 3; i++)
        bin += '0';
    if (mod > 0) bin += '0';
    else bin += '1';
    reverse(bin);
    return bin;
}

void direct_to_additional(string &s)
{
    if (s[0] == '0') return;
    int n = size(s);
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '1') s[i] = '0';
        else if (s[i] == '0') s[i] = '1';
    }
    if (s[n-1] == '0') s[n-1] = '1';
    else
    {
        for (int i = n; i > 0; i--)
        {
            s[i] = '0';
            if (s[i-1] == '0')
            {
                s[i-1] = '1';
                break;
            }
        }
    }
    
}

string sum_of_additional(string s1, string s2)
{
    string s3 = s1, s4 = s2;
    s3[0] = '0';
    s4[0] = '0';

    int sumint = stoi(s3) + stoi(s4);
    cout << "sum = " << sumint << endl;
    string sum = to_string(sumint);
    reverse(sum);

    if(s1 == s2)
    {
        sum += '0';
        for(int i = 0; i < size(sum); i++)
        {
            if(sum[i] == '2')
            {
                sum[i+1] = '1';
                sum[i] = '0';
            }
        }
    }
    else
    {
        
        for(int i = 0; i < size(sum); i++)
        {
            if(sum[i] == '2')
            {
                sum[i] = '0';
                sum[i+1] += 1;
            }
            if(sum[i] == '3')
            {
                sum[i] = '1';
                sum[i+1] += 1;           
            }
        }
    }
    
    
    sum += '0';
    if (size(s1) > size(s2))
    {
        sum += s1[0];
        for(int i = 0; i < size(sum) - 1; i++)
        if(sum[i] == '2')
        {
            sum[i] = '0';
        }
    }
    else if (size(s1) < size(s2))
    {
        sum += s2[0];
        for(int i = 0; i < size(sum) - 1; i++)
        if(sum[i] == '2')
        {
            sum[i] = '1';
        }
    }
    reverse(sum);
    cout << sum << endl;
    return sum;
}

void additional_to_direct(string &s)
{
    int n = size(s);
    if (s[0] == '1')
    {
        if (s[n - 1] == '1') s[n - 1] = '0';
        else
        {
            for (int i = n; i > 0; i--)
            {
                s[i] = '1';
                if (s[i - 1] == '1')
                {
                    s[i - 1] = '0';
                    break;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '0') s[i] = '1';
            else if (s[i] == '1') s[i] = '0';
        }
    }
}

int direct_to_natural(string s)
{
    reverse(s);
    int curr = 1;
    int ans = 0;
    for (int i = 0; i < size(s)-1; i++)
    {
        ans += curr * (s[i] - '0');
        curr *= 2;
    }
    if (s[size(s)-1] == '0') return ans;
    else return -ans;
}

int main()
{
    int number1, number2;
    cout << "Enter first number: ";
    cin >> number1;
    cout << "Enter second number: ";
    cin >> number2;

    string number1s = natural_to_direct(number1);
    string number2s = natural_to_direct(number2);
    cout << "Direct number 1 - " << number1s << endl;
    cout << "Direct number 2 - " << number2s << endl;

    direct_to_additional(number1s);
    direct_to_additional(number2s);
    cout << "Additional number 1 - " << number1s << endl;
    cout << "Additional number 2 - " << number2s << endl;

    string sum = sum_of_additional(number1s, number2s);
    additional_to_direct(sum);
    int ans = direct_to_natural(sum);
    cout << "Sum = " << ans << endl;
}