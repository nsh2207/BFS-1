#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

bool dfs(int node,bool white[],bool grey[],bool black[],vector<int>prerequisiteGraph[]){
    if(grey[node]) return false;
    if(black[node]) return true;
    white[node]=false;
    grey[node] = true;
    bool isPossible = true;
    for(auto nei:prerequisiteGraph[node]){
        isPossible = isPossible&&dfs(nei,white,grey,black,prerequisiteGraph);
    }
    grey[node]=false;
    black[node]=true;
    return isPossible;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int>prerequisiteGraph[numCourses];
    for(auto edge:prerequisites) prerequisiteGraph[edge[1]].push_back(edge[0]);
    
    bool white[numCourses],grey[numCourses], black[numCourses];
    memset(white,true,sizeof(white));
    memset(grey,false,sizeof(grey));
    memset(black,false,sizeof(black));
    bool isPossible = true;
    for(int i=0;i<=numCourses-1;i++){
        isPossible = isPossible&&dfs(i,white,grey,black,prerequisiteGraph);
    }
    return isPossible;
}

int main(){
    vector<vector<int>> prerequisites = {{1,0},{0,1}};
    cout<<canFinish(2,prerequisites);
    return 0;
}
// Time Complexity: O(V+E)
// Space Complexity: O(V+E)
// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There is a cycle in the graph.