#include<bits/stdc++.h>

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

double getDist(pair<int, int> p0, pair<int, int> a, pair<int, int> b){
	double m = (double)((b.second-a.second)*1.0)/(b.first-a.first);
	double c = a.second-m*a.first;			//line eqn: mx-y+c = 0
	double dist = (abs(m*p0.first-p0.second+c))/sqrt(m*m+1);
	return dist;
}

void qhull(vector<pair<int,int> > p, pair<int, int> a, pair<int, int> b, vector<pair<int, int> >&hull){
	int n = p.size();
	if(n == 0) return;

	double dist = 0;
	int id;
	for(int i = 0;i < n;i++){
		if(dist < getDist(p[i],a,b)){
			id = i;
			dist = getDist(p[i],a,b);
		}
	}
	hull.push_back(p[id]);

	vector<pair<int, int> >p1, p2;
	for(int i = 0;i < n;i++){
		if(cycle(a, p[i], p[id]) == 2)
      p1.push_back(p[i]);
		else if(cycle(p[id], p[i], b) == 2)
     p2.push_back(p[i]);
	}
	qhull(p1,a,p[id],hull);
	qhull(p2,p[id],b,hull);
}

void convexHull(vector<pair<int,int> > points){
	int n = points.size();
	vector<pair<int, int> > hull, p1, p2;

	int id1 = 0, id2 = 0;
	for(int i = 1;i < n;i++){
		if(points[i].first < points[id1].first) id1 = i;
		else if(points[i].first > points[id2].first) id2 = i;
	}
	hull.push_back(points[id1]); hull.push_back(points[id2]);

	int f;
	for(int i = 0;i < n;i++){
		f = cycle(points[id1], points[i], points[id2]);
		if(f == 2)  p1.push_back(points[i]);
		else if(f == 1) p2.push_back(points[i]);
	}

	qhull(p1,points[id1],points[id2],hull);
	qhull(p2,points[id2],points[id1],hull);

  cout<<hull.size()<<endl;
	cout<<"Points on hull";
	for(int i = 0; i < hull.size();i++)
		cout<<hull[i].first<<" , "<<hull[i].second<<endl;
}


void inputData(){
  int n, x, y;
  vector<pair<int, int> > points;
  // ifstream input;
  // input.open("./input_data/10000.txt");
  // input>>n;
  // cout<<"n is "<<n<<endl;
  // for(int i=1;i<=n;i++){
  //   input>>x>>y;
  //   points.push_back(make_pair(x,y));
  // }

  //case: all points lie on Convex hull
  cout<<"enter size : ";
  cin>>n;
  points.push_back(make_pair(0,1));
  for(int i=1;i<n;i++){
    points.push_back(make_pair(i,i));
  }

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
