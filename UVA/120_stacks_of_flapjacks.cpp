#include <cstdio>
#include <deque>
#include <queue>
using namespace std;

deque<int> list, temp;
priority_queue<int> pque;

void sort();
void clear();

int main()
{
    int n;
    char c;
    while(scanf("%d%c", &n, &c) == 2){
        list.push_back(n);
        pque.push(n);
        if(c == '\n'){
            sort();
            list.clear();
        }
    }
    return 0;
}

void sort()
{
    int size = list.size();
    int index = list.size() - 1;
    for(int i = 0; i < size; i++)
        printf("%d ", list[i]);
    printf("\n");
    while(!pque.empty()){
        if(list[index] == pque.top()){  //if the element is already at the bottom
            pque.pop();
            index--;
            continue;
        }
        while(list.front() != pque.top()){
            temp.push_front(list.front());
            list.pop_front();
        }
        temp.push_front(list.front());
        list.pop_front();
        if(list.size() + 1 == size)
            printf("%d ", size - index);
        else
            printf("%d %d ", list.size() + 1, size - index);
        while(list.size() != (size - index - 1)){
            temp.push_back(list.front());
            list.pop_front();
        }
        while(!temp.empty()){
            list.push_front(temp.front());
            temp.pop_front();
        }
        pque.pop();
        index--;
    }
    printf("0 \n");
}
