// Leet Code Que -> 703 Kth Largest Element in a Stream
/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.
Implement KthLargest class:
KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
 
Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
*/

 https://leetcode.com/problems/kth-largest-element-in-a-stream/description/


//------------------------------------------------------------   Solution    -----------------------------------------------------------------------


// Approch - 1 Using Priority Queue
// T.C. = O(Nlog(K))  N => size of the nums array 
// S.C. = O(K)
class KthLargest {
public:
    int K ;
    vector<int> num ;
    priority_queue<int, vector<int>, greater<int> > pq ; // Min Heap

    KthLargest(int k, vector<int>& nums) {
        K = k ;
        for(int i=0 ; i<nums.size() ; i++)
            num.push_back(nums[i]) ;

        for(int i=0 ; i<nums.size() ; i++){

            if(i<k){ // insert first k elements into min heap
                pq.push(num[i]) ;
            }

            else{
                // by this we are inserting k largest element form nums array into pq and now pq.top() gives the kth largest element in the nums array
                if(pq.top() < nums[i]){ 
                    pq.pop() ;
                    pq.push(nums[i]) ;
                }
            }
        }

    }
    
    int add(int val) {
    
        if(K > num.size()){ // K can at least 1 large then num.size() 
            num.push_back(val) ;
            pq.push(val) ;
        }

        else {
            if(pq.top() < val){
                pq.pop() ;
                pq.push(val) ;
            }
        }

        return pq.top() ;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */