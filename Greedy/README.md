# Applications
- ![image](https://user-images.githubusercontent.com/69719072/165796066-618a15c6-c8b8-4e8e-9c44-decd70c28e32.png)
## Activity Selection Problem
- max no of activities that can happen on a single tasking machine
- ![image](https://user-images.githubusercontent.com/69719072/165805127-2fca34a1-9b84-42cd-ac05-2d666933bc64.png)
- sort according to finish time
```
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    struct meeting {
        int start;
        int end;
    };
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool static sortByEnd (struct meeting m1, struct meeting m2){
        return (m1.end < m2.end);
    }
    int maxMeetings(int start[], int end[], int n)
    {
        struct meeting meet[n];
        for (int i = 0; i < n; i++) {
            meet[i].start = start[i];meet[i].end = end[i];
        }
        
        sort(meet, meet+n, sortByEnd);
        int limit = meet[0].end;
        int mm = 1;
        for (int i = 1; i < n; i++) {
            if (meet[i].start > limit) {
                mm++;
                limit = meet[i].end;
            }
        }
        return mm;
    }
};
```
```
struct rail {
        int start;
        int end;
    };
    bool static mySort(rail a, rail b) {
        return a.end < b.end;
    }
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
        struct rail rails[n];
        for (int i = 0; i< n; i++){
            rails[i].start = arr[i];
            rails[i].end = dep[i];
        }
        sort (rails, rails + n, mySort);
        vector<int> p;
        p.push_back(rails[0].end);
        bool newP = true;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < p.size(); j++) {
                cout << "here " << i << "\n";
                if (p[j] < rails[i].start) {
                    cout << "If \n";
                    p[j] = rails[i].end;
                    newP = false;
                    break;
                }
            }
            cout << "newP:" << newP << endl;
            if (newP) {
                // cout << "newP";
                p.push_back(rails[i].end);
                newP = false;
            }
        }
        return p.size();
    }
```
## Fractinal Knapsack
- Knapsack with fraction of items allowed
```

```
