/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/


// Approch 1 
// T.C. = O(n^2) 
// S.C. = O(1)
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       for(int i=0 ; i<n ; i++){
           int balance = p[i].petrol ;
           int count = 0 ;
           int j = i ;
           
           while(count < n){
               balance = balance - p[j].distance ;
               
               if(balance < 0){
                   break ;
               }
               
               j++ ;
                if(j==n){
                   j = 0 ;
               }
               balance = balance + p[j].petrol ;
               count++ ;
           }
           
           if(balance >= 0){
               return i ;
           }
       }
       
       return -1 ;
    }
};

// Approch 2
// T.C. = O(n) 
// S.C. = O(1)
// In this approch deficit store data of that petrolPump which is travers apreviouly by us so we don't want to travers them again
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int deficit = 0 ;
       int balance = 0 ;
       int start = 0 ;
       
       for(int i=0 ; i<n ; i++){
           balance += p[i].petrol - p[i].distance ;
           if(balance < 0){
               deficit += balance ;
               start = i+1 ;
               balance = 0 ;
           }
       }
       
       if(deficit + balance >=0)
        return start ;
        
        return -1 ;
    }
};

// Approch 3
// without deficit variable 


class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int balance ;
       int front = 0 ;
       int rear = 0 ;
       int count = 0 ;
       
       while(count<=n){
           // current petrolPump se next petrolPump tak travel possilbe h to
           if(balance - p[rear].petrol >= 0){
               balance = balance - p[rear].distance + p[rear++].petrol ;
           }
           
           else{
               front = rear + 1 ;
               rear = front ;
               balance = p[rear].petrol ;
           }
           
           if(rear == n){
               rear = 0 ;
           }
           
       }
       
       if(front == rear){
           return front ;
       }
       
       return -1 ;
    }
};


