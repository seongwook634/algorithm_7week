#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Metal {
    string name;
    double weight;
    double value;
    double average;
};

// 비교 함수: average가 큰 순서대로
struct Compare {
    bool operator()(const Metal& a, const Metal& b) const {
        return a.average < b.average;
    }
};

int main() {
    double maxWeight = 200; // 배낭 최대 무게 

    vector<Metal> metals = {
        {"주석", 100.0, 50.0, 50.0 / 100.0},
        {"백금", 25.0, 100.0, 100.0 / 25.0},
        {"은", 200.0, 200.0, 200.0 / 200.0},
        {"금", 50.0, 200.0, 200.0 / 50.0}
    };

    priority_queue<Metal, vector<Metal>, Compare> pq;

    for (auto& m : metals) {
        pq.push(m);
    }

    double totalValue = 0.0;
    double totalWeight = 0.0;

    cout << "선택된 금속 목록\n";

    while (!pq.empty() && totalWeight < maxWeight) {
        Metal cur = pq.top();
        pq.pop();

        if (totalWeight + cur.weight <= maxWeight) {
            totalWeight += cur.weight;
            totalValue += cur.value;
            cout << cur.name << " 전체 선택 (" << cur.weight << "g, " << cur.value << "원)\n";
        }
        else {
            double remain = maxWeight - totalWeight;
            double fraction = remain / cur.weight;
            totalWeight += remain;
            totalValue += cur.value * fraction;
            cout << cur.name << " 일부 선택 (" << remain << "g, " << cur.value * fraction << "원)\n";
            break;
        }
    }

    cout << "\n총 무게: " << totalWeight << "g\n";
    cout << "총 가치: " << totalValue << "원\n";

    return 0;
}