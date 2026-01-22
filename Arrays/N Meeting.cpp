You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 
Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<tuple<int,int,int>> meetings;
        int n=start.size();
        for(int i=0;i<n;i++){
            meetings.push_back({end[i],start[i],i+1});
        }
        sort(meetings.begin(),meetings.end());
        int freetime=-1;
        int count=0;
        for(auto&m:meetings)
        {
            int e=get<0>(m);
            int s=get<1>(m);
            int idx=get<2>(m);
            if(s>freetime){
                count++;
                freetime=e;
            }
        }
        return count;
        
    }
};  
  
