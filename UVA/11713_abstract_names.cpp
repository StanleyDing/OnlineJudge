#include <iostream>
#include <string>
using namespace std;

void compare(const string&, const string&);
int isVowel(const char);

int main()
{
    int n;//a
    string s1, s2;
    while(cin >> n){
        while(n--){
            cin >> s1 >> s2;
            if(s1.length() != s2.length()){
                cout << "No" << endl;
                continue;
            }
            compare(s1, s2);
        }
    }
}

void compare(const string &s1, const string &s2)
{
    for(int i = 0; i < s1.length(); i++){
        if(isVowel(s1[i]) && isVowel(s2[i]))
            continue;
        else if(s1[i] == s2[i])
            continue;
        else{
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int isVowel(const char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1;
    else
        return 0;
}
