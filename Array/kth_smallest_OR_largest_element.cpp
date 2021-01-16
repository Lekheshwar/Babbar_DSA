// Following code can be modifind to get the kth smallest element as well.
// Quick Select solution also exist which has an Average TC of O(N) and WORST TC of O(N*N) 

// O(N Log N)
int findKthLargest(vector<int>& nums, int k){
  sort(nums.begin(), nums.end(), greater<int>);
  return nums[k - 1];
}

// O(N Log K)
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num : nums){
            pq.push(num);
            if(pq.size() > k)pq.pop();
        }
       return pq.top();
    }
