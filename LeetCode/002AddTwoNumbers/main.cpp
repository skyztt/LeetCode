struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* pRetNode = nullptr;
	ListNode* pTailNode = nullptr;
	int carryVal = 0;
	int tmpVal = 0;
	for (; l1 || l2; l1 = l1 ? l1->next : l1, l2 = l2 ? l2->next : l2) {
		tmpVal = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carryVal;
		if (tmpVal >= 10) {
			tmpVal -= 10;
			carryVal = 1;
		}
		else {
			carryVal = 0;
		}
		if (!pRetNode) {
			pRetNode = new ListNode(tmpVal);
			pTailNode = pRetNode;
		}
		else {
			pTailNode->next = new ListNode(tmpVal);
			pTailNode = pTailNode->next;
		}
	}
	if (carryVal) {
		if (!pRetNode) {
			pRetNode = new ListNode(carryVal);
		}
		else {
			pTailNode->next = new ListNode(carryVal);
			pTailNode = pTailNode->next;
		}
	}
	return pRetNode;
}

int main()
{

	return 0;
}