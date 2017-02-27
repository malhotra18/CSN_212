#include<bits/stdc++.h>
using namespace std;

class ZigZag {
public: 
int longestZigZag(int arr[]) {
    
    int n = arr.size();

   	int dp1[n],dp2[n];
	
	for(int i=0;i<n;i++){
		dp1[i] = 0;
		dp2[i] = 0;
	}

	dp1[0]=1;  
	dp2[0]=1;    
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
		  if(arr[j]<arr[i]){       
			dp1[i]=max(dp2[j],dp1[i]);
		  }
		  if(arr[j]>arr[i]){
			dp2[i]=max(dp1[j],dp2[i]);
		  }
	}
	  dp1[i]++;
	  dp2[i]++;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans=max(ans,max(dp1[i],dp2[i]));
	}
	return ans;
 }
 
};

int main() {
  ZigZag problem;
  int input[] ={70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32};
  cout<<problem.longestZigZag(input)<<endl;
}