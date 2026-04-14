#include <iostream>
#include <vector>
#include <string>
#include <limits> 

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

vector<int> inputIntVector() {
    vector<int> v;
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    if (n <= 0) {
        cout << "Вектор пуст.\n";
        return v;
    }
    cout << "Введите " << n << " целых чисел через пробел: ";
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    clearInputBuffer();
    return v;
}

vector<char> inputCharVector() {
    vector<char> v;
    int n;
    cout << "Введите количество символов: ";
    cin >> n;
    clearInputBuffer(); 
        if (n <= 0) {
        cout << "Вектор пуст.\n";
        return v;
    }
    cout << "Введите " << n << " символов подряд (без пробелов): ";
    string input;
    getline(cin, input);
    
    for (size_t i = 0; i < input.size() && i < (size_t)n; ++i) {
        v.push_back(input[i]);
    }
    return v;
}

template<typename T>
void printVector(const vector<T>& v, const string& label = "") {
    if (!label.empty()) cout << label << ": ";
    cout << "[ ";
    for (const auto& x : v) cout << x << " ";
    cout << "]";
    if (v.empty()) cout << " (пустой)";
    cout << endl;
}

int sumVector(const vector<int>& v) {
    int sum = 0;
    for (int x : v) sum += x;
    return sum;
}

vector<int> transformSquaredMinusOne(const vector<int>& v) {
    vector<int> res;
    res.reserve(v.size());
    for (int x : v) {
        res.push_back(x * x - 1);
    }
    return res;
}

void modifyVector(vector<int>& v, int frontVal, int backVal) {
    if (v.empty()) {
        cout << "   Вектор пуст, модификация невозможна.\n";
        return;
    }
    v.insert(v.begin(), frontVal);
    
    v.push_back(backVal);
    
    if (v.size() > 1) {
        v.erase(v.begin() + 1);
    }
}

void fillVectorConditionally(vector<int>& v) {
    if (v.empty()) {
        cout << "   Вектор пуст, добавляю 3 элемента: 100, 200, 300\n";
        v.push_back(100);
        v.push_back(200);
        v.push_back(300);
    } else {
        cout << "   Вектор не пуст, заполняю 10 элементами (1..10)\n";
        v.clear();
        for (int i = 1; i <= 10; ++i) {
            v.push_back(i);
        }
    }
}

string vectorToString(const vector<char>& chars) {
    return string(chars.begin(), chars.end());
}

vector<char> stringToVector(const string& str) {
    return vector<char>(str.begin(), str.end());
}

vector<int> addVectors(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    size_t n = min(a.size(), b.size());
    res.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        res.push_back(a[i] + b[i]);
    }
    return res;
}

vector<int> subtractVectors(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    size_t n = min(a.size(), b.size());
    res.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        res.push_back(a[i] - b[i]);
    }
    return res;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << " ЛР3 (std::vector) \n";

    int choice;
    do {
        cout << "\nВыберите пункт для выполнения:\n";
        cout << "1 Сумма элементов вектора\n";
        cout << "2 Преобразование вектора (y = x^2 - 1)\n";
        cout << "3 Модификация вектора (добавить в начало/конец, удалить второй)\n";
        cout << "4 Условное заполнение вектора\n";
        cout << "5 Вектор символов -> строка\n";
        cout << "6 Строка -> вектор символов\n";
        cout << "7 Сумма двух векторов\n";
        cout << "8 Разность двух векторов\n";
        cout << "0 Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        clearInputBuffer();

        switch (choice) {
            case 1: {
                cout << "\n 1. Сумма элементов вектора \n";
                vector<int> v = inputIntVector();
                printVector(v, "Введённый вектор");
                cout << "Сумма элементов: " << sumVector(v) << endl;
                break;
            }
            case 2: {
                cout << "\n 2. Преобразование y = x^2 - 1 \n";
                vector<int> v = inputIntVector();
                printVector(v, "Исходный вектор");
                vector<int> transformed = transformSquaredMinusOne(v);
                printVector(transformed, "Результат");
                break;
            }
            case 3: {
                cout << "\n 3. Модификация вектора \n";
                vector<int> v = inputIntVector();
                printVector(v, "Исходный вектор");
                int frontVal, backVal;
                cout << "Введите значение для вставки в начало: ";
                cin >> frontVal;
                cout << "Введите значение для вставки в конец: ";
                cin >> backVal;
                clearInputBuffer();
                modifyVector(v, frontVal, backVal);
                printVector(v, "Модифицированный вектор");
                break;
            }
            case 4: {
                cout << "\n 4. Условное заполнение \n";
                cout << "Создайте вектор (можно пустой, введя 0 элементов).\n";
                vector<int> v = inputIntVector();
                printVector(v, "Исходный вектор");
                fillVectorConditionally(v);
                printVector(v, "После обработки");
                break;
            }
            case 5: {
                cout << "\n 5 Вектор символов -> строка \n";
                vector<char> chars = inputCharVector();
                printVector(chars, "Вектор символов");
                string str = vectorToString(chars);
                cout << "Полученная строка: \"" << str << "\"\n";
                break;
            }
            case 6: {
                cout << "\n 6 Строка -> вектор символов \n";
                cout << "Введите строку: ";
                string str;
                getline(cin, str);
                vector<char> chars = stringToVector(str);
                printVector(chars, "Вектор символов");
                break;
            }
            case 7: {
                cout << "\n 7 Сумма двух векторов \n";
                cout << "Вектор A:\n";
                vector<int> a = inputIntVector();
                cout << "Вектор B:\n";
                vector<int> b = inputIntVector();
                printVector(a, "A");
                printVector(b, "B");
                vector<int> sum = addVectors(a, b);
                printVector(sum, "A + B (по минимальной длине)");
                break;
            }
            case 8: {
                cout << "\n 8 Разность двух векторов \n";
                cout << "Вектор A:\n";
                vector<int> a = inputIntVector();
                cout << "Вектор B:\n";
                vector<int> b = inputIntVector();
                printVector(a, "A");
                printVector(b, "B");
                vector<int> diff = subtractVectors(a, b);
                printVector(diff, "A - B (по минимальной длине)");
                break;
            }
            case 0:
                cout << "Выход из программы.\n";
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}