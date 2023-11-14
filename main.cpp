#include <iostream>
#include <cmath> // Для функції std::floor

using namespace std;

struct t_tree {
    double info; // тут дійсні
    t_tree * left;
    t_tree * right;
};

typedef t_tree * ptree;

// Формування з клавіатури
ptree formTree() {
    ptree t;
    double info;
    cin >> info;
    if (info == 0)
        return NULL;
    t = new t_tree;
    t->info = info;
    t->left = formTree();
    t->right = formTree();
    return t;
}

//симетрично вивести
void displaySymetric(ptree tree) {
    if (tree) {
        displaySymetric(tree->left);
        cout << tree->info << " ";
        displaySymetric(tree->right);
    }
}


void insert(ptree &tree, double info) { //прийняли значення і newTree
    if (!tree) { //перевірка чи існує корінь дерева
        tree = new t_tree{info, NULL, NULL}; //створили його
    } else if (info < tree->info) { //якщо значення менше ніж в поточному, вставляємо ліворуч
        insert(tree->left, info);
    } else if (info > tree->info) { //якщо більше то вставляємо праворуч
        insert(tree->right, info);
    }
}

bool isEven(double value) { //перевірка на парність
    if (value == std::floor(value) && (int)value % 2 == 0) { //округлили вниз і перевірили на цілість та парність
        return true;
    }
    return false;
}

void findEvenNumbersAndInsert(ptree &sourceTree, ptree &newTree) {
    if (sourceTree) { //перевірка поточного узла на null
        findEvenNumbersAndInsert(sourceTree->left, newTree); //йдемо в ліво
        if (isEven(sourceTree->info)) { //якщо значення вузла парне
            insert(newTree, sourceTree->info); //забираємо це значення в нове дерево
        }
        findEvenNumbersAndInsert(sourceTree->right, newTree); //йдемо в право
    }
}

int main() {
    cout << "Enter numbers to create a tree (0 to finish):" << endl;
    ptree originalTree = formTree();

    ptree evenTree = NULL; // Створюємо пусте дерево для чисел, які є цілими та парними
    findEvenNumbersAndInsert(originalTree, evenTree); // Заповнюємо дерево

    cout << "Displaying the tree of even numbers" << endl;
    displaySymetric(evenTree); // Виводимо нове дерево

    return 0;
}
