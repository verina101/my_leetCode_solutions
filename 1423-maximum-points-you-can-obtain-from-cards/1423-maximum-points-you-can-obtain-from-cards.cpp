class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0,mx=0,cnt=k;
        for(int i=0;i<k;i++)
            sum+=cardPoints[i];
        
        mx=max(sum,mx);
        
        for(int i= cardPoints.size()-1 ; i>=0;i--){
            if(cnt==0)
                break;
            sum -= cardPoints[cnt-1];
            sum += cardPoints[i];
            cnt--;
            mx=max(sum,mx);
        }
        return mx;
    }
    
    
};