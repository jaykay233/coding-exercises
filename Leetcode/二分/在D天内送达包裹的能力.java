class Solution {
    public int shipWithinDays(int[] weights, int D) {
        int lo = 0, hi = Integer.MAX_VALUE;
        while (lo < hi) {
        	int mid = lo + (hi - lo) / 2;
        	if (canShip(weights, D, mid)) {
        		hi = mid;
        	} else {
        		lo = mid+1;
        	}
        }
        return lo;
    }
    private boolean canShip(int[] weights, int D, int K) {
    	int cur = K;  
    	for (int weight: weights) {
    		if (weight > K) return false;
    		if (cur < weight) {
    			cur = K;
    			D--;
    		}
    		cur -= weight;
    	}
    	return D > 0;  
    }
}