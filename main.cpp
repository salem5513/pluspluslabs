#include <iostream>

using namespace std;

struct t_tree {
    int info; //Елементи можуть бути будь-якого типу
    t_tree * left;
    t_tree * right;
};

typedef t_tree * ptree;

// Формування з клавіатури
ptree formTree() {
    ptree t;
    int info;
    cin >> info;
    if (info == 0)
        return NULL;
    t = new t_tree;
    t->info = info;
    t->left = formTree();
    t->right = formTree();
    return t;
}

// Обхід у прямому порядку
void displayTopDown(ptree tree) {
    if (tree) {
        cout << tree->info << " ";
        displayTopDown(tree->left);
        displayTopDown(tree->right);
    }

}
void displayReverse(ptree tree) {
    if (tree) {
        displayReverse(tree->left);
        displayReverse(tree->right);
        cout << tree->info << " ";

    }
}

void displaySymetric(ptree tree) {
    if (tree) {
        displaySymetric(tree->left);
        cout << tree->info << " ";
        displaySymetric(tree->right);

    }
}
int Counter(ptree tree, int target) {
    int count = 0;
    if (!tree) return count;
    if (tree->info == target) count++;
    count += Counter(tree->left, target);
    count += Counter(tree->right, target);
    return count;
}
void insert(ptree &tree, int info) {
    if (!tree) {
        tree = new t_tree{info, NULL, NULL};
    } else if (info < tree->info) {
        insert(tree->left, info);
    } else if (info > tree->info) {
        insert(tree->right, info);
    }
}
void findEvenNumbersAndInsert(ptree &sourceTree, ptree &newTree) {
    if (sourceTree) {
        findEvenNumbersAndInsert(sourceTree->left, newTree);
        if (sourceTree->info % 2 == 0) {
            insert(newTree, sourceTree->info);
        }
        findEvenNumbersAndInsert(sourceTree->right, newTree);
    }
}

int main() {
    cout << "Enter numbers to create a binary tree (0 to finish):" << endl;
    ptree originalTree = formTree();

    ptree evenTree = NULL; // Створюємо пусте дерево для парних чисел
    findEvenNumbersAndInsert(originalTree, evenTree); // Заповнюємо дерево парними числами

    cout << "Displaying the even numbers tree in in-order:" << endl;
    displayTopDown(evenTree); // Виводимо нове дерево у симетричному порядку

    return 0;
}

