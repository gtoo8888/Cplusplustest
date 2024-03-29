#include <iostream> 
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
		vector<int> ans;
		queue<TreeNode*> que;
		if(root != nullptr)
			que.push(root);

		while(!que.empty()){
			int size = que.size();
			for(int i = 0;i < size;i++){
				TreeNode* tmp = que.front();que.pop();
				ans.push_back(tmp->val);
				if(tmp->left != nullptr) 
					que.push(tmp->left);
				if(tmp->right != nullptr) 
					que.push(tmp->right);
			}
		}
		return ans;
    }
};


int main(){
	Solution solution;
	// vector<int> data = {3,9,20,null,null,15,7};
	// TreeNode* root = NULL;
	// root = CreateBinaryTree(data);

	TreeNode* root = nullptr;
			
	auto ans = solution.levelOrder(root);
	PrintVector(ans);

	return 0;
}



