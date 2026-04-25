#include<iostream>
#include<vector>
using namespace std;
int main(){
    int vertex, edges;
    cout<<"Enter the no. of vertices and edges\n";
    cout << "vertices : ";
    cin >> vertex;
    cout << "Edges : ";
    cin >> edges;

    vector<pair<int,int>>AdjList[vertex];

    int u,v,weight;

    //filling values
    cout<<"Enter the values of u & v \n";
    for(int i=0;i<edges;i++){
    cin >> u >> v >> weight;
    AdjList[u].push_back(make_pair(v,weight));
    AdjList[v].push_back(make_pair(u,weight));
    }

    //printing matix
    for(int i=0;i<vertex;i++){
      cout<<i<<"->";
      for(int j=0;j<AdjList[i].size();j++)
        cout<<"("<<AdjList[i][j].first<<" "<<AdjList[i][j].second<<")";
    cout<<endl;
    }
    return 0;
}
