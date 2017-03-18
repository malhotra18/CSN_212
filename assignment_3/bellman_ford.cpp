#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Read input from STDIN. Print output to STDOUT */
    int t, nodes, edges, u, v, w, s;
    cin>>t;//enter number of test cases
    for(int l=0;l<t;l++){
        cin>>nodes>>edges;//enter number of nodes and edges
        vector<int> distance(nodes+1, INT_MAX);
        vector<vector<pair<int, int> > > adj(nodes+1);
        vector<bool> qpresence(nodes+1, false);
        for(int i=0;i<edges;i++){
            cin>>u>>v>>w;//enter values of 2 nodes and weight of edge connecting them
            //storing the values in adjacency list
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        //implementation of algorithm
        queue<int> q;
        cin>>s;//enter the source node
        distance[s]=0;
        q.push(s);
        qpresence[s]=true;

        while(!q.empty()){
            u = q.front();
            q.pop();
            qpresence[u] = false;
            for(int i=0;i<adj[u].size();i++){
                v = get<0>(adj[u][i]);
                int d = distance[u] + get<1>(adj[u][i]);
                if(d<distance[v]){
                    distance[v] = d;
                    if(qpresence[v]==false){
                        q.push(v);
                        qpresence[v]=true;
                    }
                }
            }
        }
        //print shortest path for each node
        for(int i=1;i<=nodes;i++){
            if(i==s){

            }else{
                if(distance[i]==INT_MAX){
                    cout<<"for node: "<<i<<" "<<-1<<endl;
                }else{
                    cout<<"for node: "<<i<<" "<<distance[i]<<endl;
                }
            }
        }
        cout<<endl;

    }
    return 0;
}
