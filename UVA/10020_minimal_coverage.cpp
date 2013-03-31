//greedy
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct SEGMENT{
    int L, R;
    bool operator<(const SEGMENT &t) const{
        return L < t.L;
    }
}temp;

int main()
{
    int cases, M, l_bound, r_bound, count, l, r;
    vector<SEGMENT> v, output;
    vector<SEGMENT>::iterator itr;

    scanf("%d", &cases);
    while(cases--){
        queue<SEGMENT> que;
        l_bound = r_bound = count = 0;
        scanf("%d", &M);
        while(scanf("%d%d", &l, &r) && (l || r)){
            temp.L = l, temp.R = r;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        itr = v.begin();
        while(itr != v.end()){
            temp.L = temp.R = 0;
            for(; itr != v.end() && itr->L <= l_bound; itr++){
                if(itr->R > r_bound){
                    r_bound = itr->R;
                    temp = *itr;
                }
            }
            if(!temp.L && !temp.R){     //fail to find a pair
                count = 0;
                break;
            }
            l_bound = r_bound;
            que.push(temp);     //queue the result
            count++;
            if(r_bound >= M)    //all covered
                break;
        }
        if(!count)
            printf("0\n\n");
        else{
            printf("%d\n", count);
            while(!que.empty()){
                temp = que.front(), que.pop();
                printf("%d %d\n", temp.L, temp.R);
            }
            printf("\n");
        }
        v.clear();
    }
}
