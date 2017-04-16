#include <iostream>
#include <bits/stdc++.h>

using namespace std;

pair<int, int> p0;//for sorting

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

bool compare(pair<int,int> p1, pair<int,int> p2){
	int o = cycle(p0,p1,p2);

	if(o == 0)  return (((p0.first - p1.first)*(p0.first - p1.first)+(p0.second - p1.second)*(p0.second - p1.second)) <= ((p0.first - p2.first)*(p0.first - p2.first)+(p0.second - p2.second)*(p0.second - p2.second)));

	return (o == 1)?0:1;
}

pair<int,int> next2top(stack<pair<int,int> > &st){
	pair<int,int> temp = st.top();
	st.pop();
	pair<int,int> temp2 = st.top();
	st.push(temp);
	return temp2;
}


void convexHull(vector<pair<int, int> > points ){
  // cout<<" aca "<<points.size();
  int n = points.size();

  vector<pair<int, int> > hull;

  int l = 0;
  for(int i=1;i<n;i++){
    if(points[i].second<points[l].second)
      l = i;
    else if(points[i].second == points[l].second && points[i].first <points[l].first)
      l = i;
  }
  swap(points[0], points[l]);
  p0 = points[0];

  sort(points.begin()+1,points.end(), compare);

  int m = 1;
  for(int i = 1;i < n-1;i++){
    if(cycle(p0,points[i],points[i+1]) != 0)  points[m++] = points[i];
  }
  points[m++] = points[n-1];

  if(m < 3) return;

  stack<pair<int,int> > st;
  st.push(points[0]);
  st.push(points[1]);
  st.push(points[2]);
  for(int i = 3;i < m;i++){
    while(cycle(next2top(st),st.top(),points[i]) != 2) st.pop();
    st.push(points[i]);
  }

  int count = 0;
  // cout<<"Points on the convex hull :"<<endl;
  while(!st.empty()){
    // cout<<st.top().first<<" , "<<st.top().second<<endl;
    count++;
    st.pop();
}
cout<<endl<<"points required for convex hull "<<count<<endl;
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
