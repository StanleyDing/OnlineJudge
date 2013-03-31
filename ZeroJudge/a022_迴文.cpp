#include <iostream>
#include <string>
using namespace std;

bool check(string);

int main()
{
    string s;
    while(cin >> s){
        if(check(s))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}

bool check(string s)
{
    int sl = s.length();
    for(int i = 0; i < sl/2; i++){
        if(s[i] == s[sl-i-1])
            continue;
        else
            return false;
    }
    return true;
}
