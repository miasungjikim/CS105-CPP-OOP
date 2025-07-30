//
// Created by MiaKim on 30/07/2025.
//
#include <iostream>
#include <vector>
using namespace std;

class Enemy {
private:
    string name{};

public:
    Enemy(string s) {
        name = s;
    }

    void getName() {
        cout << "I am" << name;
    }

    void pauseEnemy() {
        cout << name << " paused " << endl;
    }

    void restartEnemy() {
        cout << name << " restarted " << endl;
    }

};

void pauseAllEnemies(vector<Enemy>&ec) {
    for (auto item:ec) {
        item.pauseEnemy();
    }
}


int main() {
    char test;
    Enemy ork("Ork");
    Enemy human("Human");
    Enemy godzilla("Godzilla");

    vector<Enemy>enemiesCollections;

    enemiesCollections.push_back(ork);
    enemiesCollections.push_back(human);
    enemiesCollections.push_back(godzilla);

    cout << "there are " << enemiesCollections.size() << "enemies" << endl;

    pauseAllEnemies(enemiesCollections);

    for (Enemy item : enemiesCollections) {
        item.restartEnemy();
    }

    cout << ">>>>> end ?";
    cin.get(test);


    return 0;

}