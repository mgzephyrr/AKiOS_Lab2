#pragma once

/// <summary>
/// ��������� ���� ���-������
/// </summary>
struct AVLTreeNode {
	int value;
	unsigned char height;

	AVLTreeNode* left;
	AVLTreeNode* right;

	AVLTreeNode(int k) { value = k; left = right = nullptr; height = 1; } //����������� ���� ���-������
};

// ��������� �������, �������������� ������ �� ���������� .cpp ������
AVLTreeNode* MakeAVLTree();
AVLTreeNode* AddValue(AVLTreeNode*, int);
AVLTreeNode* RemoveValue(AVLTreeNode*, int);
void PrintTreeByAscending(AVLTreeNode*);
void PrintTreeByDescending(AVLTreeNode*);
int FindValue(AVLTreeNode*, int);
void DeleteTree(AVLTreeNode*);