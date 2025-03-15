#include "TreePractice.h"
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<exception>
struct leaveNode {
	int left;
	int right;
};

void createTree(std::vector<leaveNode>& treeArray , int n) {
	std::istringstream is;
	const std::string NOSUB("-");
	std::string line;
	for (int i = 0; i < n; ++i) {
		getline(std::cin, line);
		leaveNode ln;
		is.str(line);
		std::string sub;
		is >> sub;
		if (sub == NOSUB) {
			ln.left = -1;
		}
		else {
			ln.left = stoi(sub);
		}
		is >> sub;
		if (sub == NOSUB) {
			ln.right = -1;
		}
		else {
			ln.right = stoi(sub);
		}
		treeArray.push_back(ln);
		is.clear();
	}
}

int getRoot(std::vector<leaveNode> treeArray, int n) {
	std::vector<bool> isRoot(n, true);
	for (int i = 0; i < n; ++i) {
		if (treeArray[i].left != -1) isRoot[treeArray[i].left] = false;
		if (treeArray[i].right != -1) isRoot[treeArray[i].right] = false;
	}
	// std::cout << std::endl;
	for (int i = 0; i < n; ++i) {
		// std::cout << treeArray[i].left << " " << treeArray[i].right << std::endl;
		if (isRoot[i] == true) {
			return i;
		}
	}
	return -1;
}

void printLeaveLtoR(const std::vector<leaveNode>& treeArray, int root) {
	std::stack<int> s;
	int p = root;
	while (1) {
		if (treeArray[p].left == -1 && treeArray[p].right == -1) {
			if (s.empty()) {
				std::cout << p << std::endl;
				return;
			}
			std::cout << p << " ";
			p = s.top();
			s.pop();
		}
		else {
			if (treeArray[p].right != -1) {
				s.push(treeArray[p].right);
			}
			if (treeArray[p].left != -1) {
				p = treeArray[p].left;
			}
		}
	}
}

void printLeaveUtoD(const std::vector<leaveNode>& treeArray, int root ) {
	std::queue<int> q;
	q.push(root);
	int p = root;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		if (treeArray[p].left != -1) {
			q.push(treeArray[p].left);
		}
		if (treeArray[p].right != -1) {
			q.push(treeArray[p].right);
		}
		if (treeArray[p].left == -1 && treeArray[p].right == -1) {
			std::cout << p;
			q.empty() ? std::cout << std::endl : std::cout << " ";
			
		}
		
	}
}

void printLeave() {
	std::string line;
	getline(std::cin, line);
	int n = stoi(line);
	if (!n) return;
	std::vector<leaveNode> treeArray;
	createTree(treeArray, n);
	int root = getRoot(treeArray, n);
	printLeaveUtoD(treeArray, root);
}


int createTreeByStackSeq(std::vector<leaveNode> &tree, int n) {
	int root; std::stack<int> s;
	std::string line;
	std::istringstream is;
	char prec = 'h';
	is.clear();
	getline(std::cin, line);
	is.str(line);
	std::string word;
	is >> word;
	try {
		if (word == "Push") {
			is >> word;
			root = stoi(word) - 1;
			s.push(root);
			
		}
		else {
			throw std::runtime_error("堆栈输入错误");
		}
	}
	catch (std::runtime_error e) {
	   std::cerr << e.what() << std::endl;
	}
	is.clear();
	int prei = root;
	while (word != "end") {
		getline(std::cin, line);
		is.str(line);
		is >> word;
		if (word == "end") {
			break;
		}
		else if (word == "Push") {
			is >> word;
			int curIndex = stoi(word) - 1;
			if (prec == 'h') {
				tree[prei].left = curIndex;
				
			}
			else if (prec == 'o') {
				tree[prei].right = curIndex;
			}
			s.push(curIndex);
			prec = 'h';
			prei = curIndex;
		}
		else if (word == "Pop") {
			if (prec == 'h') {
				tree[prei].left = -1;
				
			}
			else if (prec == 'o') {
				tree[prei].right = -1;
			}
			if (!s.empty()) prei = s.top();
			s.pop();
			
			prec = 'o';
		}
		is.clear();
	}
	return root;
}

/*** 后序非递归遍历静态链表表示的二叉树 ***/
void postOrderTraversal(const std::vector<leaveNode>& tree, int root) {
	std::stack<int> s;
	std::vector<bool> visited(tree.size(), false);
	s.push(root);
	while (!s.empty()) {
		bool tovisited = true;
		int cur = s.top();
		if (tree[cur].right != -1 && !visited[tree[cur].right]) {
			s.push(tree[cur].right);
			tovisited = false;
		}
		if (tree[cur].left != -1 && !visited[tree[cur].left]) {
			s.push(tree[cur].left);
			tovisited = false;
		}
		if (tovisited) {
			std::cout << cur + 1;
			visited[cur] = true;
			s.pop();
			!s.empty() ? std::cout << " " : std::cout << std::endl;
		}
	}
}



void TTA() {
	std::string line;
	getline(std::cin, line);
	int n = stoi(line);
	if (!n) return;
	std::vector<leaveNode> tree(n, {-1, -1});
	int root = createTreeByStackSeq(tree, n);
	/*for (int i = 0; i < n; ++i) {
		std::cout << tree[i].left << " " << tree[i].right << std::endl;
	}*/
	postOrderTraversal(tree, root);
}

void TTANoBuild(const std::vector<int>::iterator pre_b, const std::vector<int>::iterator mid_b, const std::vector<int>::iterator post_b, int n) {
	if (n == 0) return;
	int root = *pre_b;
	post_b[n - 1] = root;
	if (n == 1) return;
	// find 根节点在中序的位置，得到左子树和右子树各几个元素。
	int i = 0;
	while (i < n && mid_b[i] != root) ++i;
	try {
		if (i == n) throw std::logic_error("序列错误");
	}
	catch (std::logic_error e) {
		std::cerr << e.what() << std::endl;
	}
	int leftNum = i;
	TTANoBuild(pre_b + 1, mid_b, post_b, leftNum);
	TTANoBuild(pre_b + 1 + leftNum, mid_b + 1 + leftNum, post_b + leftNum, n - leftNum - 1);
}

void TTANoBuildTry() {
	int n = 6;
	// std::cin >> n;
	std::string line, word = "";
	std::stack<int> s;
	std::vector<int> preSeq, midSeq, postSeq(n, 0);
	// std::cin.clear();
	// std::cin.ignore();
	while(getline(std::cin, line)) {
		std::istringstream is(line);
		is >> word;
		if (word == "Push") {
			is >> word;
			int cur = stoi(word);
			s.push(cur);
			preSeq.push_back(cur);
		}
		else if (word == "Pop") {
			midSeq.push_back(s.top());
			s.pop();
		}
	}
	 /*for (auto i : midSeq) {
		std::cout << i << " ";
	}*/
	TTANoBuild(preSeq.begin(), midSeq.begin(), postSeq.begin(), n);
	for (auto iter = postSeq.begin(); iter != postSeq.end(); ++iter) {
		std::cout << *iter << " ";
	}
}

