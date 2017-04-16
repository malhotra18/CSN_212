#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int cycle(pair<int,int> a, pair<int,int> b, pair<int,int> c){
	int temp = (b.first-a.first)*(c.second-b.second) - (c.first-b.first)*(b.second-a.second);
	if(temp == 0){
     return 0;
   }
	if(temp < 0){
    return 1;
  }
	return 2;
}

// int cycle(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
//   int temp;
//   temp = (p2.second - p1.second) * (p3.first - p2.first) -(p2.first - p1.first) * (p3.second - p2.second);
//   if(temp == 0){
//     return 0;
//   }else if(temp<0){
//     return 1;
//   }else{
//     return 2;
//   }
// }

void convexHull(vector<pair<int, int> > points ){
  // cout<<" aca "<<points.size();
  int n = points.size();
  if(n<3){
    return;
  }
  vector<pair<int, int> > hull;

  int l = 0;
  for(int i=1;i<n;i++){
    if(points[i].first<points[l].first)
      l = i;
  }

  // cout<<points[l].first<<"  l  "<<points[l].second<<endl;
  int a = l, b;
  do{
    hull.push_back(points[a]);

    b = (a+1)%n;
    for (int i = 0; i < n; i++) {
      if(cycle(points[a], points[i], points[b])==2){
        b = i;
      }
    }
    a=b;
  }while(a!=l);

  cout<<"no. of points on hull "<<hull.size()<<endl;
  // for(int i=0;i<hull.size();i++){
  //   cout<<hull[i].first<<" , "<<hull[i].second<<endl;
  // }
}

void inputData(){
  int n, x, y;
  vector<pair<int, int> > points;
  ifstream input;
  input.open("./input_data/10000.txt");
  input>>n;
  cout<<"n is "<<n<<endl;
  for(int i=1;i<=n;i++){
    input>>x>>y;
    points.push_back(make_pair(x,y));
  }

  //case: all points lie on Convex hull
  // cout<<"enter size : ";
  // cin>>n;
  // points.push_back(make_pair(0,1));
  // for(int i=1;i<n;i++){
  //   points.push_back(make_pair(i,i));
  // }

  convexHull(points);
}



int main() {
  /* code */
  clock_t st = clock();

  inputData();

  double executionTime = double(clock() - st) / (double) CLOCKS_PER_SEC ;
  cout<<"execution time"<<executionTime<<endl;
  return 0;
}
