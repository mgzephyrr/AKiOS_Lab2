#pragma once

/// <summary>
/// Структура узла АВЛ-дерева
/// </summary>
struct AVLTreeNode {
	int value;
	unsigned char height;

	AVLTreeNode* left;
	AVLTreeNode* right;

	AVLTreeNode(int k) { value = k; left = right = nullptr; height = 1; } //конструктор узла АВЛ-дерева
};

// заголовки методов, обеспечивающие работу со множеством .cpp файлов
AVLTreeNode* MakeAVLTree();
AVLTreeNode* AddValue(AVLTreeNode*, int);
AVLTreeNode* RemoveValue(AVLTreeNode*, int);
void PrintTreeByAscending(AVLTreeNode*);
void PrintTreeByDescending(AVLTreeNode*);
int FindValue(AVLTreeNode*, int);
void DeleteTree(AVLTreeNode*);