#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
    string surname;
    int course;
    string specialty;

    union {
        struct
        {
            double physics;
            double math;
            double informatics;
        };
    } o;
};
void Create(Student* s, int N) {
    for (int i = 0; i < N; i++) {
        cout << "Student #" << i + 1 << ":" << endl;
        cout << " Surname: ";
        cin >> s[i].surname;
        cout << " Course: ";
        cin >> s[i].course;
        cout << " Specialty: ";
        cin >> s[i].specialty;
        cout << " Physics grade: ";
        cin >> s[i].o.physics;
        cout << " Math grade: ";
        cin >> s[i].o.math;
        cout << " Informatics grade: ";
        cin >> s[i].o.informatics;
    }
}

void Print(Student* s, int N) {
    cout << "======================================================================================" << endl;
    cout << "| No. | Surname        | Course | Specialty          | Physics |  Math | Informatics |" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(2) << right << i + 1 << "  ";
        cout << "| " << setw(13) << left << s[i].surname;
        cout << "  | " << setw(6) << right << s[i].course;
        cout << " | " << setw(18) << left << s[i].specialty;
        cout << " | " << setw(7) << right << fixed << setprecision(2) << s[i].o.physics;
        cout << " | " << setw(5) << right << fixed << setprecision(2) << s[i].o.math;
        cout << " | " << setw(10) << right << fixed << setprecision(2) << s[i].o.informatics;
        cout << "  |" << endl;
    }

    cout << "======================================================================================" << endl;
}

double CountHighGradeStudents(Student* s, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        double avg = (s[i].o.physics + s[i].o.math + s[i].o.informatics) / 3;
        if (avg > 4.5) count++;
    }
    return (double(count) / N) * 100;  
}

void Sort(Student* s, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (s[j].course > s[j + 1].course) {
                swap(s[j], s[j + 1]);
            }
        }
    }
    cout << "Students sorted by course successfully!" << endl;
}

int main() {
    int N;
    cout << "Enter number of students: ";
    cin >> N;

    Student* p = new Student[N];
    int menuItem;
    double proc;

    do {
        cout << endl << endl << endl;
        cout << "================ MENU ==================" << endl;
        cout << "1 - Create students" << endl;
        cout << "2 - Print students" << endl;
        cout << "3 - Count percentage of students with avg grade > 4.5" << endl;
        cout << "4 - Sort students by course" << endl;
        cout << "0 - Exit" << endl;
        cout << "========================================" << endl;
        cout << "Choose an option: ";
        cin >> menuItem;

        switch (menuItem) {
        case 1:
            Create(p, N);
            break;
        case 2:
            Print(p, N);
            break;
        case 3:
            proc = CountHighGradeStudents(p, N);
            cout << "Percentage of students with average grade > 4.5: " << proc << "%" << endl;
            break;
        case 4:
            Sort(p, N);
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (menuItem != 0);

    delete[] p;
    return 0;
}
