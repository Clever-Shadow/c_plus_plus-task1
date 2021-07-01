#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //инициализация
    vector <char> snow, result; 
    int k, n;
    
    //ввод
    cin >> n;
    for (int i = 0; i < n; i++) {
        char temp;
        cin >> temp;
        snow.push_back(temp);
    }
    cin >> k;
    
    //обработка
    
    //пройтись по массиву и найти лучший снег
    char frend, best;
    int old = (int) snow[0];
    int in_best = 0;
    for (int i = 1; i < snow.size(); i++) {
        if ((int) snow[i] < old) {
            old = snow[i];
            in_best = i;
        }
    }
    
    best = snow[in_best];
    
    //найти лучшего ближайшего соседа к нему
    if (in_best == 0) {
        // катаем 1
        frend = snow[1];
    }
    else if (in_best == snow.size() - 1) {
        // катаем snow.size() - 2
        frend = snow[snow.size() - 2];
    }
    else {
        // ищем лучшего
        if ((int) snow[in_best - 1] < (int) snow[in_best + 1]) {
            frend = snow[in_best - 1];
        }
        else {
            frend = snow[in_best + 1];
        }
    }
    
    //катать k раз
    for (int i = 0; i < k; i++) {
        if (i % 2 == 0) {
            result.push_back(best);
        }
        else {
            result.push_back(frend);
        }
    }
    
    //вывод
    cout << endl;
    for (auto i : result) {
        cout << i << " ";
    }
    return 0;
}