/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        int count = 0;
        int ans = 0;
        vector<int> starts;
        vector<int> ends;

        for(auto& it: intervals)
        {
            starts.push_back(it.start);
            ends.push_back(it.end);
        }

        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());
        
        int i = 0;
        int j = 0;
        while(i<n && j<n)
        {
            if(starts[i]<ends[j])
            {
                count++;
                i++;
            }
            else if(starts[i]>ends[j])
            {
                count--;
                j++;

            }
            else
            {
                j++;
                count--;
            }

            ans = max(ans,count);

        }

        return ans;
    }
};
