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

// �� �Լ�: average�� ū �������
struct Compare {
    bool operator()(const Metal& a, const Metal& b) const {
        return a.average < b.average;
    }
};

int main() {
    double maxWeight = 200; // �賶 �ִ� ���� 

    vector<Metal> metals = {
        {"�ּ�", 100.0, 50.0, 50.0 / 100.0},
        {"���", 25.0, 100.0, 100.0 / 25.0},
        {"��", 200.0, 200.0, 200.0 / 200.0},
        {"��", 50.0, 200.0, 200.0 / 50.0}
    };

    priority_queue<Metal, vector<Metal>, Compare> pq;

    for (auto& m : metals) {
        pq.push(m);
    }

    double totalValue = 0.0;
    double totalWeight = 0.0;

    cout << "���õ� �ݼ� ���\n";

    while (!pq.empty() && totalWeight < maxWeight) {
        Metal cur = pq.top();
        pq.pop();

        if (totalWeight + cur.weight <= maxWeight) {
            totalWeight += cur.weight;
            totalValue += cur.value;
            cout << cur.name << " ��ü ���� (" << cur.weight << "g, " << cur.value << "��)\n";
        }
        else {
            double remain = maxWeight - totalWeight;
            double fraction = remain / cur.weight;
            totalWeight += remain;
            totalValue += cur.value * fraction;
            cout << cur.name << " �Ϻ� ���� (" << remain << "g, " << cur.value * fraction << "��)\n";
            break;
        }
    }

    cout << "\n�� ����: " << totalWeight << "g\n";
    cout << "�� ��ġ: " << totalValue << "��\n";

    return 0;
}