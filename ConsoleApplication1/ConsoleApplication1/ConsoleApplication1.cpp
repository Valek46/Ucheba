#include <iostream>
#include <sstream> 
using namespace std;

int main() {
    string input; 
    double num1, num2; 
    char operation; 

  
    cout << "Введите выражение (например, 5 + 3): ";
    getline(cin, input); 

   
    stringstream ss(input);
    ss >> num1 >> operation >> num2;

    
    if (ss.fail()) {
        cout << "Ошибка: неверный формат ввода." << endl;
        return 1; 
    }

   
    switch (operation) {
    case '+':
        cout << "Результат: " << num1 + num2 << endl;
        break;
    case '-':
        cout << "Результат: " << num1 - num2 << endl;
        break;
    case '*':
        cout << "Результат: " << num1 * num2 << endl;
        break;
    case '/':
        if (num2 != 0) {
            cout << "Результат: " << num1 / num2 << endl;
        }
        else {
            cout << "Ошибка: деление на ноль невозможно." << endl;
        }
        break;
    default:
        cout << "Ошибка: неверная операция." << endl;
        break;
    }

    return 0;
}
