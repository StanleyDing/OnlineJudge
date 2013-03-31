#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int main()
{
    long long int a, b, count;
    int N;
    string s;
    while(scanf("%d", &N) != EOF){
        while(N--){
            a = b = count = 0;
            cin >> s;
            for(int i = 0; i < s.size(); i++)
                a = a * 10 + s[i] - '0';
            for(int i = s.size() - 1; i >= 0; i--)
                b = b * 10 + s[i] - '0';
            do{
                a += b;
                b = 0;
                for(long long int i = a; i > 0; i /= 10)
                    b = b * 10 + (i % 10);
                count++;
            }while(a != b);
            printf("%lld %lld\n", count, a);
        }
    }
    return 0;
}
