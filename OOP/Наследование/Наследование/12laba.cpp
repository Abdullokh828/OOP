#include <iostream>
#include <locale>

using namespace std;

// ������� �����: �����-���������-�����
class sterling {
protected:
    int pounds, shillings, pence;

public:
    // ����������� �� ���������
    sterling() : pounds(0), shillings(0), pence(0) {}

    // ����������� � �����������
    sterling(int p, int s, int pe) : pounds(p), shillings(s), pence(pe) {}

    // ����� ��� ����� ������
    void set() {
        cout << "������� ����� � ������� ?�.�.� (�����.��������.�����): ";
        char ch;
        cin >> pounds >> ch >> shillings >> ch >> pence;
    }

    // ����� ��� ������ ������
    void show() const {
        cout << "?" << pounds << "." << shillings << "." << pence;
    }
};

// ����������� �����: � �������� ������� �����
class sterfrac : public sterling {
private:
    int eighths; // ������� ���� �����

public:
    // ����������� �� ���������
    sterfrac() : sterling(), eighths(0) {}

    // ����������� � �����������
    sterfrac(int p, int s, int pe, int e) : sterling(p, s, pe), eighths(e) {}

    // ����� ��� ����� ����� � �������� ������� �����
    void set() {
        sterling::set();
        cout << "������� ������� ����� ����� (0, 1/8, 1/4, ... 7/8): ";
        char ch;
        cin >> eighths >> ch;
    }

    // ����� ��� ������ �����
    void show() const {
        sterling::show();
        cout << "-" << eighths << "/8";
    }

    // �������� ��������
    sterfrac operator+(const sterfrac& other) const {
        int total_eighths = (pence * 8 + eighths) + (other.pence * 8 + other.eighths);
        int new_pence = total_eighths / 8;
        int new_eighths = total_eighths % 8;
        return sterfrac(pounds + other.pounds, shillings + other.shillings, new_pence, new_eighths);
    }

    // �������� ���������
    sterfrac operator-(const sterfrac& other) const {
        int total_eighths = (pence * 8 + eighths) - (other.pence * 8 + other.eighths);
        int new_pence = total_eighths / 8;
        int new_eighths = total_eighths % 8;
        return sterfrac(pounds - other.pounds, shillings - other.shillings, new_pence, new_eighths);
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    sterfrac s1, s2, result;

    cout << "������� ������ �����:\n";
    s1.set();

    cout << "������� ������ �����:\n";
    s2.set();

    // ��������
    result = s1 + s2;
    cout << "��������� ��������: ";
    result.show();
    cout << endl;

    // ���������
    result = s1 - s2;
    cout << "��������� ���������: ";
    result.show();
    cout << endl;

    return 0;
}
