#include <iostream>
#include <vector>

using namespace std;


double average(const vector<int>& arr) {
    if (arr.empty()) return 0;
    double s = 0;
    for (int x : arr) s += x;
    return s / arr.size();
}

int findMin(const vector<int>& arr) {
    int mn = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
        if (arr[i] < mn) mn = arr[i];
    return mn;
}

int findMax(const vector<int>& arr) {
    int mx = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

int sumEven(const vector<int>& arr) {
    int sum = 0;
    for (int x : arr) if (x % 2 == 0) sum += x;
    return sum;
}

int sumOdd(const vector<int>& arr) {
    int sum = 0;
    for (int x : arr) if (x % 2 != 0) sum += x;
    return sum;
}

vector<int> transform(const vector<int>& arr) {
    vector<int> res;
    for (int x : arr) res.push_back(x * x - 1);
    return res;
}

int sumPositive(const vector<int>& arr) {
    int sum = 0;
    for (int x : arr) if (x > 0) sum += x;
    return sum;
}

int sumNegative(const vector<int>& arr) {
    int sum = 0;
    for (int x : arr) if (x < 0) sum += x;
    return sum;
}

struct StackNode {
    int val;
    StackNode* next;
    StackNode(int v, StackNode* n = nullptr) : val(v), next(n) {}
};

class Stack {
    StackNode* top;
public:
    Stack() : top(nullptr) {}
    ~Stack() { while (!empty()) pop(); }

    void push(int x) {
        top = new StackNode(x, top);
    }

    int pop() {
        if (empty()) throw runtime_error("Стек пуст");
        int res = top->val;
        StackNode* old = top;
        top = top->next;
        delete old;
        return res;
    }

    bool empty() const { return top == nullptr; }

    // Вывод содержимого стека от вершины к дну
    void print() const {
        if (empty()) {
            cout << "(пусто)";
            return;
        }
        StackNode* cur = top;
        while (cur) {
            cout << cur->val;
            cur = cur->next;
            if (cur) cout << " -> ";
        }
    }
};

struct QueueNode {
    int val;
    QueueNode* next;
    QueueNode(int v, QueueNode* n = nullptr) : val(v), next(n) {}
};

class Queue {
    QueueNode* head;
    QueueNode* tail;
public:
    Queue() : head(nullptr), tail(nullptr) {}
    ~Queue() { while (!empty()) dequeue(); }

    void enqueue(int x) {
        QueueNode* node = new QueueNode(x);
        if (empty()) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    int dequeue() {
        if (empty()) throw runtime_error("Очередь пуста");
        int res = head->val;
        QueueNode* old = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete old;
        return res;
    }

    bool empty() const { return head == nullptr; }

    void print() const {
        if (empty()) {
            cout << "(пусто)";
            return;
        }
        QueueNode* cur = head;
        while (cur) {
            cout << cur->val;
            cur = cur->next;
            if (cur) cout << " <- ";
        }
    }
};


int main() {
    // Ввод списка
    int n;
    cout << "Введите количество элементов списка: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Введите " << n << " целых чисел через пробел или Enter:\n";
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "\nВведённый список: ";
    for (int x : nums) cout << x << " ";
    cout << "\n\n";

    cout << "1 Среднее арифметическое: " << average(nums) << "\n";

    cout << "2 Минимальный элемент: " << findMin(nums) << "\n";

    cout << "3 Максимальный элемент: " << findMax(nums) << "\n";

    cout << "\n4 Работа со стеком (LIFO)\n";
    Stack st;
    cout << "   Начальное состояние: "; st.print(); cout << "\n";

    for (size_t i = 0; i < nums.size(); i++) {
        cout << "   push(" << nums[i] << ") -> ";
        st.push(nums[i]);
        st.print();
        cout << "\n";
    }
   cout << "\n   Извлечение элементов (pop):\n";
    while (!st.empty()) {
        cout << "   pop() -> " << st.pop() << ", осталось: ";
        st.print();
        cout << "\n";
    }

    cout << "\n5 Работа с очередью (FIFO)\n";
    Queue q;
    cout << "   Начальное состояние: "; q.print(); cout << "\n";

    for (size_t i = 0; i < nums.size(); i++) {
        cout << "   enqueue(" << nums[i] << ") -> ";
        q.enqueue(nums[i]);
        q.print();
        cout << "\n";
    }

    cout << "\n   Извлечение элементов (dequeue):\n";
    while (!q.empty()) {
        cout << "   dequeue() -> " << q.dequeue() << ", осталось: ";
        q.print();
        cout << "\n";
    }

     cout << "\n6 Сумма чётных элементов: " << sumEven(nums) << "\n";

 
    cout << "7 Сумма нечётных элементов: " << sumOdd(nums) << "\n";

     vector<int> trans = transform(nums);
    cout << "8 Новый список (x^2 - 1): ";
    for (int t : trans) cout << t << " ";
    cout << "\n";

     cout << "9 Сумма положительных элементов: " << sumPositive(nums) << "\n";

     cout << "10 Сумма отрицательных элементов: " << sumNegative(nums) << "\n";

    return 0;
}