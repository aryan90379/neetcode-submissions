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
        vector<int> starts;
        vector<int> ends;
        for(auto& interval : intervals)
        {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());

        int res =0;
        int count = 0;

        int s =0;
        int e =0;
        while(s<starts.size())
        {
            if(starts[s]<ends[e])
            {
                count++;
                res = max(res,count);
                s++;
            }
            else if (starts[s]==ends[e])
            {
                e++;
                count--;
            }
            else 
            {
                count --;
                e++;
            }
        }

        return res;
    }
};
