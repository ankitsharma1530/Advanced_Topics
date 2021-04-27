vector<int> singleNumber(vector<int>& nums) {
     int xors = 0;
	for(int num : nums) xors ^= num;
    int setbit = 1;
	while((setbit & xors) == 0)
		setbit <<= 1;
	vector<int> res(2,0);
	for(int num : nums)
		if(num & setbit)
			res[0] ^= num;
		else
			res[1] ^= num;
	return res;   
    }
