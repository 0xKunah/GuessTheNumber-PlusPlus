#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Game {

private:
    static int generateRandNum(int n) {
        return (rand() % n) + 1;
    }
    static int askForMaxNumber() {
        int i;
        cout << "Nombre max: " << endl;
        cin >> i;
        return i;
    }
    static int askForMinNumber() {
        int i;
        cout << "Nombre min: " << endl;
        cin >> i;
        return i;
    }
    static int askForTriesNumber() {
        int i;
        cout << "Nombre d'essais: " << endl;
        cin >> i;
        return i;
    }
    int tryToGuess() {
        int i;
        cout << "A ton avis, quel nombre j'ai choisi ? (" << min << " - " << max << ")" << endl;
        cin >> i;
        return i;
    }

    void shouldRestart() {
        string str;
        cout << "On en refait une ? [y/n]" << endl;
        cin >> str;
        if (str == "y") {
            Game g = Game::setup();
            this->max = g.max;
            this->min = g.min;
            this->number = g.number;
            this->tries = g.tries;
            this->won = false;
            this->start();
        }
        else if (str == "n") {
            cout << "Ok bisous." << endl;
        }
        else shouldRestart();
    }

public:
    int max, min, tries, number;
    bool won = false;
    static Game setup() {
        Game g;
        g.max = g.askForMaxNumber();
        g.min = g.askForMinNumber();
        g.number = g.generateRandNum(g.max);
        g.tries = g.askForTriesNumber();
        return g;
    }
    void start() {
        while (tries > 0) {
            int x = tryToGuess();
            if (x == number) {
                cout << "T'as win gg." << endl;
                won = true;
            }
            else if (x > number) {
                max = x < max ? x : max;
                cout << "Plus petit." << endl;
            }
            else {
                min = x > min ? x : min;
                cout << "Plus grand." << endl;
            }
            tries--;
            cout << "Essais restants: " << tries << endl;
        }
        if (won) shouldRestart();
        else cout << "Bahaha t'as perdu, trop nul ! J'avais choisi " << number << endl;
    }
};

int main() {
    srand((unsigned)time(0));
    Game g = Game::setup();
    g.start();
    return 0;
}