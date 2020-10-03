class Solution {
int res = 0;
    public int treeDiameter(int[][] edges) {
        List<Integer>[] map = new ArrayList[edges.length+1];
        
        for(int i=0 ; i<map.length ; i++){
            map[i] = new ArrayList<>();
        }
        for(int[] edge : edges){
            map[edge[0]].add(edge[1]);
            map[edge[1]].add(edge[0]);
        }
        
        dfs(map,0,new boolean[edges.length+1]);
        return res;
    }
    
    public int dfs(List<Integer>[] map,int index,boolean[] visited){
        visited[index] = true;
        List<Integer> list = map[index];
        int max1 = 0;   // 第一大
        int max2 = 0;   // 第二大
        for(int next : list){
            if(!visited[next]){               
                int num = dfs(map,next,visited);
                if(num>max1){
                    max2 = max1;
                    max1 = num;
                } else if(num>max2){
                    max2 = num;
                }
            }
        }
        res = Math.max(res,max1+max2);
        
        return Math.max(max1,max2)+1;
        
    }
}
