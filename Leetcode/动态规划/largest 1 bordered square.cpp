#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class Solution{
public: 
    int res = 0;
    int largest1BorderedSquare(vector<vector<int>>& grid){
        int res= 0;
        for(int k =0;k<min(grid.size(),grid[0].size());k++){
            for(int i =0;i<grid.size()-k;i++){
                for(int j =0;j<grid[0].size()-k;j++){
                    if(isValidSquare(grid,i,j,k)){
                        res = (k+1)*(k+1);
                    }
                }
            }
        }
        return res;
    }

    bool isValidSquare(vector<vector<int>>& grid, int x, int y, int w){
        for(int i=x;i<=x+w;i++){
            if(!grid[i][y])
                return false;
        }

        for(int i=x;i<=x+w;i++){
            if(!grid[i][y+w])
                return false;
        }

        for(int i=y;i<=y+w;i++){
            if(!grid[x][i])
                return false;
        }

        for(int i=y;i<=y+w;i++){
            if(!grid[x+w][i])
                return false;
        }
        return true;
    }
};