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

    vector<vector<bool>>AdjMat(vertex,vector<bool>(vertex,0));

    int u,v;

    //filling values
    cout<<"Enter the values of u & v \n";
    for(int i=0;i<edges;i++){
    cin >> u >> v;
    AdjMat[u][v] = 1;
    }

    //printing matix
    for(int i=0;i<vertex;i++){
      for(int j=0;j<vertex;j++)
        cout<<AdjMat[i][j]<<" ";
    cout<<endl;
    }

    return 0;
}