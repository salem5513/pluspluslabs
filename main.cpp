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

int main() {
    cout << "Enter numbers to create a binary tree (0 to finish):" << endl;
    ptree tree = formTree();

    cout << "\nDisplaying the tree in pre-order:" << endl;
    displayTopDown(tree);
    cout << endl;

    // Call the function to display the tree in in-order (which is actually named displayReverse here)
    cout << "Displaying the tree in in-order (reverse):" << endl;
    displayReverse(tree);
    cout << endl;

    // Call the function to display the tree in post-order (which is actually named displaySymetric here)
    cout << "Displaying the tree in post-order (symmetric):" << endl;
    displaySymetric(tree);
    cout << endl;

    // Now we can test the Counter function.
    int target;
    cout << "Enter a number to count in the tree: ";
    cin >> target;
    int count = Counter(tree, target);
    cout << "The number " << target << " appears in the tree " << count << " times." << endl;

    return 0;
}
