#include "vector"
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> vect;
	for (int i = 0, j = nums.size() - 1; i < j; ++i) {
		for (unsigned m = i + 1; m < nums.size(); ++m) {
			if (nums[i] + nums[m] == target) {
				vect.push_back(i);
				vect.push_back(m);
				break;
			}
		}
	}
	return vect;
}

vector<int> twoSumHash(vector<int>& nums, int target) {
	vector<int> vect;
	std::unordered_map<int, int> val2Id;
	for (int i = 0, j = nums.size(); i < j; ++i) {
		int complement = target - nums[i];
		if (val2Id.find(nums[i]) == val2Id.end()) {
			val2Id[complement] = i;
		}
		else {
			vect.push_back(val2Id[nums[i]]);
			vect.push_back(i);
		}
	}
	return vect;
}

int main()
{
	vector<int> inNum{ 3,2,4 };
	vector<int> retVect = twoSumHash(inNum, 6);
	while (1);
	return 0;
}