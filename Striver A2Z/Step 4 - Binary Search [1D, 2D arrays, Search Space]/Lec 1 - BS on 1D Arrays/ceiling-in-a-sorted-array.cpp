
// https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401?leftPanelTabValue=SUBMISSION&count=25&page=1&search=&sort_entity=order&sort_order=ASC

pair<int, int> getFloorAndCeil(vector<int> &nums, int n, int x) {
	int maxEle = INT_MAX;
	int minEle = INT_MIN;
	for(auto ele : nums){
		if(ele >= x && ele < maxEle) maxEle = ele;
		if(ele <= x && ele > minEle) minEle = ele;
	}
	minEle = (minEle == INT_MIN) ? -1 : minEle;
	maxEle = (maxEle == INT_MAX) ? -1 : maxEle;
	return {minEle, maxEle};
}