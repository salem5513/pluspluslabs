#include <iostream>

using namespace std;

struct Node {
    int info;
    Node* next;
    Node* prev;
};

typedef Node* pNode;  // typedef для вказівника на Node

void create2List(pNode* head, pNode* tail) {
    *head = *tail = NULL; //починаємо з порожнього
    pNode cur = NULL;
    int info;

    cout << "Enter numbers to add to the list (0 to stop): ";
    while (cin >> info && info != 0) {
        if (*head == NULL) { //якщо список порожній то створюємо перший вузел,
            *head = new Node;
            (*head)->info = info;               //вказівники head та tail обидва встановлюються на цей новий вузол.
            (*head)->prev = NULL;
            (*head)->next = NULL;
            *tail = *head;
            cur = *head;
        } else {
            cur->next = new Node;          //створюємо новий вузел після нашого
            cur->next->prev = cur;      //prev теперешнього тепер вказує на попередній cur
            cur->next->info = info;      //встановлюємо значення
            cur->next->next = NULL;      //новий вказівник на next = null
            *tail = cur->next;          //оновлюємо tail та cur
            cur = cur->next;
        }
    }
}

void printForward(pNode head) {
    pNode cur = head;
    while (cur) {
        cout << cur->info << " ";
        cur = cur->next;
    }
    cout << endl;
}

// Функція для виведення вмісту списку в зворотньому напрямку
void printBackward(pNode tail) {
    pNode cur = tail;
    while (cur) {
        cout << cur->info << " ";
        cur = cur->prev;
    }
    cout << endl;
}

int insert2Before(pNode* head, int info, int newInfo) {
    if (*head == NULL) {
        // Список порожній
        return 0;
    }

    // Шукаємо шуканий елемент
    pNode cur = *head;
    while (cur != NULL && cur->info != info) {
        cur = cur->next;
    }

    if (cur == NULL) {
        // Елемент не знайдено
        return 0;
    }

    // Створюємо новий вузол
    pNode newNode = new Node;
    newNode->info = newInfo;

    if (cur == *head) {
        // Якщо шуканий елемент є першим, оновлюємо голову
        newNode->next = *head;
        newNode->prev = NULL;
        (*head)->prev = newNode;
        *head = newNode;
    } else {
        // Інакше вставляємо перед знайденим елементом
        newNode->prev = cur->prev;
        newNode->next = cur;
        cur->prev->next = newNode;
        cur->prev = newNode;
    }

    return 1;
}
int insert2After(pNode* head, pNode* tail, int info, int newInfo) {
    if (*head == NULL) {
        // Список порожній
        return 0;
    }

    // Шукаємо шуканий елемент
    pNode cur = *head;
    while (cur != NULL && cur->info != info) {
        cur = cur->next;
    }

    if (cur == NULL) {
        // Елемент не знайдено
        return 0;
    }

    // Створюємо новий вузол
    pNode newNode = new Node;
    newNode->info = newInfo;
    newNode->next = cur->next;
    newNode->prev = cur;

    if (cur->next != NULL) {
        // Якщо не останній елемент
        //то встановлюється вказівник prev наступного вузла на новий вузол:
        cur->next->prev = newNode;
    } else {
        // Якщо останній, оновлюємо хвіст
        *tail = newNode;
    }
    //next вказівник cur вказівника оновлюється, щоб вказувати на новий вузел
    cur->next = newNode;

    return 1;
}
bool isSymmetric(pNode head, pNode tail) {
    if (!head) { // Якщо список порожній, він симетричний за визначенням
        return true;
    }

    pNode left = head;  //де початок там кінець...
    pNode right = tail;

    while (left != right && right->next != left) {
        if (left->info != right->info) {
            // Якщо знайдено елементи, які не співпадають, список не симетричний
            return false;
        }
        left = left->next;
        right = right->prev;
    }

    // Якщо пройшли весь список і не знайшли невідповідностей, список симетричний
    return true;
}



int main() {
    pNode head;
    pNode tail;
    int a, i;
    create2List(&head, &tail);
    cout << "Список у прямому порядку: ";
    printForward(head);
    cout << "Список у зворотньому порядку: ";
    printBackward(tail);
    cout << "Введить елемент a: ";
    cin >> a;
    cout << "Щоб вставити до елементу " << a << " введіть - 1, після - 2" << endl;
    cin >> i;
    if(i == 1){
        insert2Before(&head,a,66);
        printForward(head);
    } else if(i == 2){
        insert2After(&head,&tail,a, 66);
        printForward(head);
    } else{
        cout << "Error";
    }
    if(isSymmetric(head, tail)){
        cout << "Список симетричний";
    } else {
        cout << "Список не симетричний";
    }
    return 0;
}
