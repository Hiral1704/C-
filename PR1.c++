#include <iostream>
using namespace std;

class TimeConverter {
public:
    
    void secondsToTime(int totalSeconds) {
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;

        cout << "HH:MM:SS\t"<< hours << ":" << minutes << ":" << seconds << endl;
    }

    
    void timeToSeconds(int h, int m, int s) {
        int totalSeconds = (h * 3600) + (m * 60) + s;
        cout << "Total seconds: " << totalSeconds << endl;
    }
};

int main() {
    TimeConverter t;
    int choice;

    cout << "1. Seconds to HH:MM:SS\n";
    cout << "2. HH:MM:SS to Seconds\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int sec;
        cout << "Enter total seconds: ";
        cin >> sec;
        t.secondsToTime(sec);
    }
    else if (choice == 2) {
        int h, m, s;
        cout << "Enter hours: ";
        cin >> h;
        cout << "Enter minutes: ";
        cin >> m;
        cout << "Enter seconds: ";
        cin >> s;
        t.timeToSeconds(h, m, s);
    }
    else {
        cout << "Invalid choice!";
    }

    return 0;
}