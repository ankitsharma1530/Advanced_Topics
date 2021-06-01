class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int count =0;
        while(pq.size()>1){
            int t1 = pq.top()-1;
            pq.pop();
            int t2 = pq.top()-1;
            pq.pop();
            if(t1>0){
                pq.push(t1);
            }
            if(t2>0){
                pq.push(t2);
            }
            count++;
        }
        return count;
    }
};
/*
TC-:   For adding/removing in heap it takes O(log (3)) ,
       as there is only 3 elements so it will be constant
       
       Number of time while loop run depends in MIN (a, b, c)
       so it will be roughly ~ O(n)
       
       total TC - O(n*log(3)) ~ O(n) as log(3) will act as constant
*/
