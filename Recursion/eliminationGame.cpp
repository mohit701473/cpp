// Leet Code   Que: 390. Elimination Game

// T.C. = O(log(n)) ;

// This is Recursive Code and no MLE
class Solution {
public:

    int solve(int data, int head, int diff, bool left) {
        if(data == 1)
            return head ;

        int ans ;
        if(left || data&1 ){
            head = head + diff ;
        }
        data = data/2 ;
        diff = diff*2 ;
        left = !left ;
        ans = solve(data, head, diff, left) ;
        return ans ;
    }
    int lastRemaining(int n) {

        bool left = 1 ;
        int head = 1, diff = 1, data = n ;
        head = solve(data, head, diff, left) ;
        return head ;
    }
};

// This is Itrative code and no MLE 
class Solution {
public:
    int lastRemaining(int n) {
        bool left = 1 ;
        int head = 1, diff = 1, data = n ;

        while(data > 1){
            if(left || data&1 ){
                head = head + diff ;
            }

            diff = diff * 2 ;
            data = data/2 ;
            left = !left ;
        }

        return head ;
    }
};

// In this code Memory Limit Exceed  size of n at max is 10^9 and in code we create a vector & store data in it so this type of error is occured
class Solution {
public:
    int solve(vector<int> number, int index){
        if(number.size() == 1)
            return number[0] ;

        int ans ;
        int i = 0 ;
        int size = number.size() ;
        vector<int> temp ;
        if(index == 0) {
            i = 1 ;
            while(i<size) {
                temp.push_back(number[i]) ;
                i = i+2 ;
            }
            ans = solve(temp, size/2) ;
        }

        else{
            if(index%2 == 0){
                i = 0 ;
                while(i<size) {
                    temp.push_back(number[i]) ;
                    i = i+2 ;
                }
            }

            else{
                i = 1 ;
                while(i<size) {
                    temp.push_back(number[i]) ;
                    i = i+2 ;
                }
            }
            ans = solve(temp, 0) ;
        }

        return ans ;
    }

    int lastRemaining(int n) {
        if(n==1) 
            return 1 ;

            cout<<"int size "<<sizeof(int)<<endl;

        vector<int> number ;
        for(int i=0 ; i<n ; i++) 
            number.push_back(i+1) ;

        int ans = solve(number, 0) ;

        return ans ;
    }
};

