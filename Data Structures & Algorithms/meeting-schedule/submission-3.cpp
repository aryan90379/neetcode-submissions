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
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        vector<int> start_time;
        vector<int> end_time;
        for(auto& interval: intervals)
        {
            start_time.push_back(interval.start);
            end_time.push_back(interval.end);
        }

        sort(start_time.begin(),start_time.end());
        sort(end_time.begin(),end_time.end());

        int i =0; //start times
        int j =0;

int count = 0;
        while(i<start_time.size())
        {
            if(start_time[i]<end_time[j])
            {
                count++;
                if(count>1) return false;
                i++;
                
            }
            else {
                count--;
                j++;
        
            }
        }

        return true;
        
        
    }
};
