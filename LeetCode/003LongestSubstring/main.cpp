#include "string"
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
	unordered_map<char, int> mapChar2ID;
	int beginId = 0;
	int currentId = 0;

	int maxCount = 0;
	for (char c : s) {
		if (mapChar2ID.find(c) != mapChar2ID.end()) {
			beginId = max(beginId, mapChar2ID[c]);
		}
		mapChar2ID[c] = currentId + 1;
		maxCount = max(maxCount, currentId - beginId + 1);
		++currentId;
	}
	return maxCount;
}

int main()
{
	int length = lengthOfLongestSubstring("bziuwnklhqzrxnb");
	//int length = lengthOfLongestSubstring("abcabcbb");
	//int length = lengthOfLongestSubstring("bbbb");
	return 0;
}