#include <string>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

bool cmp(string a, string b)
{
    string c, d;
    c = a + b;
    d = b + a;
    if(c > d)
        return true;
    return false;
}

int main()
{
    int n;
    string s[50];
    while(cin >> n, n){
        for(int i = 0; i < n; i++)
            cin >> s[i];
        sort(s, s + n, cmp);
        for(int i = 0; i < n; i++)
            cout << s[i];
        cout << endl;
    }
    return 0;
}
