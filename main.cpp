#include <iostream>


typedef struct treeNode {
	int val;
	struct treeNode* left;
	struct treeNode* right;
}TreeNode_t;
class Tree
{
public:
	TreeNode_t* myTree ;
	Tree()
	{

	}
	~Tree()
	{
		delete myTree;
	}
	void insertNode(int val)
	{ 
		insert_Node(val, myTree);
	}
	void deleteNode(int val)
	{
		delete_Node(val, myTree);
	}
	void searchNode(int val)
	{
		TreeNode_t* node = myTree;
		while (node != nullptr)
		{
			if (node->val == val)
			{
				std::cout << "Found: " << val << std::endl;
				return;
			}
			else if (val > node->val)
			{
				node = node->right;
			}
			else
			{
				node = node->left;
			}
		}
		std::cout << "Not Found: " << val << std::endl;
		return;
	}
	void printTree()
	{
		std::cout << "Tree: ";
		print_tree(myTree);
		std::cout << std::endl;
	}
private:
	void insert_Node(int val, TreeNode_t* &node)
	{
		if (node == nullptr)
		{
			TreeNode_t* newNode = new TreeNode_t;
			newNode->val = val;
			newNode->left = nullptr;
			newNode->right = nullptr;
			node = newNode;
			return;
		}
		else
		{
			if (val > node->val)
			{
				insert_Node(val, node->right);
			}
			else
			{
				insert_Node(val, node->left);
			}
		}
	}
	void delete_Node(int val, TreeNode_t*& node)
	{
		if(node  == nullptr)
		{
			return;
		}
		else
		{
			if (node->val == val)
			{
				if (node->left == nullptr && node->right == nullptr)
				{
					delete node;
					node = nullptr;
				}
				else if (node->left == nullptr)
				{
					TreeNode_t* temp = node;
					node = node->right;
					delete temp;
				}
				else if (node->right == nullptr)
				{
					TreeNode_t* temp = node;
					node = node->left;
					delete temp;
				}
				else
				{
					TreeNode_t* temp = node->right;
					while (temp->left != nullptr)
					{
						temp = temp->left;
					}
					node->val = temp->val;
					delete_Node(temp->val, node->right);
				}
			}
			else if (val > node->val)
			{
				delete_Node(val, node->right);
			}
			else
			{
				delete_Node(val, node->left);
			}
		}
	}
	void print_tree(TreeNode_t* node)
	{
		if (node == nullptr)
		{
			return;
		}
		else
		{
			print_tree(node->right);
			std::cout << node->val << " ";
			print_tree(node->left);
		}
	}
};

int main() {
	Tree testTree; 
	testTree.insertNode(5);
	testTree.insertNode(3);
	testTree.insertNode(7);
	testTree.insertNode(2);
	testTree.insertNode(15);
	testTree.insertNode(1);
	testTree.insertNode(2);
	testTree.insertNode(4);
	testTree.insertNode(6);
	testTree.insertNode(8);
	testTree.insertNode(9);

	testTree.printTree();
}