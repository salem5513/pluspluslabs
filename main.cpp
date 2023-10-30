#include <iostream>
using namespace std;


//структура для формування
struct Node{
    int info;
    Node* next;
};
typedef Node* pNode;


//формування списку
pNode formFIFO(){
    pNode head = NULL, cur = NULL;
    int a;
    cout << "Enter: ";
    cin >> a;
    if(!a)
        return head;

    head = new Node;
    head->info = a;
    head->next = NULL;
    cur = head;

    cout << "Enter: ";
    cin >> a;
    while(a){
        cur->next = new Node;
        cur = cur->next;
        cur->info = a;
        cur->next = NULL;
        cout << "Enter: ";
        cin >> a;
    }
    return head;
}


//вивід списку
void print(pNode list){
    if(!list)
        return;
    while (list) {
        cout << list->info << "  ";
        list = list->next;
    }
    cout << endl;
}

bool checker(pNode list1, pNode list2){
    // Go through each list as long as both current nodes are not NULL
    while(list1 != NULL && list2 != NULL) {
        // If the current data of both lists are not equal, return false
        if(list1->info != list2->info) {
            return false;
        }
        // Move to the next elements in both lists
        list1 = list1->next;
        list2 = list2->next;
    }

    // If either of the lists has more elements than the other, return false
    if(list1 != NULL || list2 != NULL) {
        return false;
    }

    // If the code reaches here, the lists are equal
    return true;
}

void adder(pNode list1, pNode list2, int el){
    pNode cur;
    if (!list1)  //чи пустий лист
        return;

    for (cur = list1; cur && cur->info != el; cur = cur->next); //проходимось по елементах, поки не знайдемо таргет, або закінчився

    if(!cur)  //якщо немає нашого елементу
        return;

    pNode newNode;
    newNode = cur->next;
    cur->next = list2;

    while (list2->next != NULL){
        list2 = list2->next;
    }
    list2->next = newNode;
    print(list1);
//якщо не потрібно зберигати елемнети, тоді видаляємо їх з останнього елементу до e
}



int main() {

    pNode L1 = nullptr, L2 = nullptr;

    L1 = formFIFO();
    print(L1);

    L2 = formFIFO();
    print(L2);



    if (checker(L1,L2)) {
        // block of code to be executed if the condition is true
        cout << endl;
        cout << "Списки однакові";
    }
    else {
        int n;
        cout << "Спискі не однакові, введить позицію E:";
        cin >> n;
        adder(L1,L2,n);
    }
};