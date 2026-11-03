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
        vector<int> start_time;
        vector<int> end_time;

        for(auto& interval: intervals)
        {
            start_time.push_back(interval.start);
            end_time.push_back(interval.end);
        }

        sort(start_time.begin(),start_time.end());
        sort(end_time.begin(),end_time.end());

        int i =0;
        int count =0;
        int j =0;
        int ans = 0;
        while(i<n && j<n)
        {
            if(start_time[i]<end_time[j])
            {
                count++;
                i++;
            }
            else if(start_time[i]>end_time[j])
            {count--;
            j++;
            }
            else
            {
                i++;
                j++;
            }

            ans = max(ans,count);
        }

        return ans;

        
    }
};
