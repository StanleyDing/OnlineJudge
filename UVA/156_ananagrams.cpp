#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <cctype>
#include <algorithm>
#define MAX_C 30
using namespace std;


int main()
{
    map<string, string> m;
    map<string, string>::iterator map_itr;
    set<string> output;
    set<string>::iterator set_itr;
    string str, lower_str;
    char s[MAX_C];
    while(scanf("%s", s) && s[0] != '#'){
        str = s;
        for(int i = 0; s[i] != '\0'; i++)
            s[i] = tolower(s[i]);
        sort(s, s + strlen(s));
        for(int i = 0; s[i] != '\0'; i++)
            lower_str += s[i];
        if(m[lower_str] == "\0")
            m[lower_str] = str;
        else
            m[lower_str] = "!";
        lower_str.clear();
    }
    for(map_itr = m.begin(); map_itr != m.end(); map_itr++){
        if(map_itr->second == "!")
            continue;
        output.insert(map_itr->second);
    }
    for(set_itr = output.begin(); set_itr != output.end(); set_itr++)
        cout << *set_itr << endl;
}
