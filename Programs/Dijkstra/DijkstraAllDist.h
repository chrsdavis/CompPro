#include <bits/stdc++.h>

#define MAX 100000

using namespace std;

typedef pair<int,int> Pair;


template<size_t vertNum>
void add_DirEdge (array<vector<Pair>,vertNum>& edges,const int& a, const int& b, const int& cost)
{
  edges[a].push_back(make_pair(b,cost));
}

template<size_t vertNum>
void add_Edge (array<vector<Pair>,vertNum>& edges,const int& a, const int& b, const int& cost)
{
  add_DirEdge(edges, a, b, cost);
  add_DirEdge(edges, b, a, cost);
  //edges[a].push_back(make_pair(b,cost));
  //edges[b].push_back(make_pair(a,cost));
}


template<size_t vertNum>
array<double,vertNum> search (const array<vector<Pair>,vertNum>& edges,const int& start)
{//calculates dist from start -> every other node
  //min heap
  priority_queue<Pair, vector<Pair>, greater<Pair>> mh;

  double dist[vertNum];
  memset(dist, MAX, sizeof(dist));
  mh.emplace(0,start);
  dist[start] = 0;
  
  int v;
  while(!mh.empty())
  {
    v = mh.top().second;
    mh.pop();

    int v_;
    int wt;
    for(Pair p : edges[v])
    {
      wt = p.second;
      v_ = p.first;

      if (dist[v_] > dist[v] + wt)
      {
        dist[v_] = dist[v] + wt;
        mh.emplace(dist[v_],v_);
      }
    }
  }
  return dist;
}