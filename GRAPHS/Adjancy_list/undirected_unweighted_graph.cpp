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

    vector<int>AdjList[vertex];

    int u,v;

    //filling values
    cout<<"Enter the values of u & v \n";
    for(int i=0;i<edges;i++){
    cin >> u >> v;
    AdjList[u].push_back(v);
    AdjList[v].push_back(u);
    }

    //printing matix
    for(int i=0;i<vertex;i++){
      cout<<i<<"->";
      for(int j=0;j<AdjList[i].size();j++)
        cout<<AdjList[i][j]<<" ";
    cout<<endl;
    }
    return 0;
}
