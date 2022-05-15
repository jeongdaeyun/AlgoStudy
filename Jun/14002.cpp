#include<iostream>
#include<iomanip>
using namespace std;
int dp[1001];
int arr[1001];

int main(){
   int N;
   cin>>N;
   for(int i=0; i<N; i++){
      cin>>arr[i];
   }
   int max=0;
   int j=1;
   dp[0]=arr[0];
   for(int i=1; i<N; i++){
      if(dp[j-1]<arr[i]){
         dp[j++]=arr[i];
      }
      else{
         dp[lower_bound(dp,dp+j,arr[i])-dp]=arr[i];
      }

   }
   cout<<j<<endl;
   for(int i=0; i<j; i++){
      if(i==j-1){
         cout<<dp[i];
      }
      else{
         cout<<dp[i]<<" ";   
      }
      
   }
   return 0;
   
}