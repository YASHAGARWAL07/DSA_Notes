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

    vector<vector<int>>AdjMat(vertex,vector<int>(vertex,0));

    int u,v,weight;

    //filling values
    cout<<"Enter the values of u & v & weight \n";
    for(int i=0;i<edges;i++){
    cin >> u >> v >> weight;
    AdjMat[u][v] = weight;
    }

    //printing matix
    for(int i=0;i<vertex;i++){
      for(int j=0;j<vertex;j++)
        cout<<AdjMat[i][j]<<" ";
    cout<<endl;
    }

    return 0;
}