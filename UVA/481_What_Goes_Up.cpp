//Longest Increment Sequence, LIS

//vector v is used to determine the LIS length
//vector pos is used to track the LIS elements
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

vector<int> seq;
vector<int> v;
vector<int> pos;

int LIS();
int lower_bound(int, int, int);
void printAns(int);

int main()
{
    int n, max;
    while(scanf("%d", &n) != EOF)
        seq.push_back(n);
    max = LIS();
    printf("%d\n-\n", max);
    printAns(max);
    return 0;
}

int LIS()
{
    v.push_back(seq[0]);
    pos.push_back(0);
    for(int i = 1; i < seq.size(); i++){
        if(seq[i] > v.back()){
            pos.push_back(v.size());
            v.push_back(seq[i]);
        }
        else{
            int lb = lower_bound(0, v.size() - 1, seq[i]);
            v[lb] = seq[i];
            pos.push_back(lb);
        }
    }
    return v.size();
}

int lower_bound(int low, int up, int val)
{
    if(v[low] >= val)
        return low;

    int mid = (low + up) / 2;
    if(v[mid] >= val)
        return lower_bound(low,  mid, val);
    else
        return lower_bound(mid + 1, up, val);
}

void printAns(int ith)
{
    stack<int> stk;
    ith--;
    for(int i = pos.size() - 1; i >= 0; i--){
        if(pos[i] != ith)
            continue;
        stk.push(seq[i]);
        ith--;
    }

    while(!stk.empty()){
        printf("%d\n", stk.top());
        stk.pop();
    }
}
