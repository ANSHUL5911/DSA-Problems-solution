class Solution {
	public:
	
	bool cowDist(vector<int> &stalls, int guess, int n, int k) {
		int count = 1;
		int j = 0;
		for (int i = 1; i<n; i++) {
			
			if (stalls[i]-stalls[j] >= guess) {
				count++;
				j = i;
				if (count == k) {
					return true;
				}
			}
		}
		return false;
	}
	
	int aggressiveCows(vector<int> &stalls, int k) {
		
		sort(stalls.begin(), stalls.end());
		
		int n = stalls.size();
		int low = 1, high = stalls[n-1] - stalls[0];
		int res = 0;
		
		while (low <= high) {
			int guess = (low + high)/2;
			
			bool d = cowDist(stalls, guess, n, k);
			
			if (d) {
				res = guess;
				low = guess + 1;
			}
			else {
				
				high = guess - 1;
			}
		}
		return res;
		
	}
};
