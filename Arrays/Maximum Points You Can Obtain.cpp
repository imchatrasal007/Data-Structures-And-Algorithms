There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
  int leftsum=0;
        int rightsum=0;
        int n=cardPoints.size();
        int sum=0;
        for(int i=0;i<=k-1;i++){
          leftsum+=cardPoints[i];
        }
        int maxi=leftsum;
        int index=n-1;
        for(int i=k-1;i>=0;i--){
          leftsum=leftsum-cardPoints[i];
          rightsum=rightsum+cardPoints[index];
          index--;
          maxi=max(maxi,leftsum+rightsum);
        }
        return maxi; 
