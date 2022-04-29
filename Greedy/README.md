- generally in Greedy algoritms we sort items and then choose most optimal looking solution at present time
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
## Job Sequencing Problem
- you are given list of job with deadline and accompanied profit
- your job is maximise the profit
- Every job takes 1 unit of time
- only one job can be assigned at a time
- time starts at 0
- ![image](https://user-images.githubusercontent.com/69719072/165888635-f2bbca61-9a93-4942-8c0d-45f975e8ceaf.png)
### Solution
- Sort jobs in decreasing order of profits
- Initialize the results as first job in the sorted list. assign the latest possible slot
- Do following the remaining (n-1) jobs
- (a) If this job can not be added, ignore it.
- (b) else add it to the latest possible slot
```

```
