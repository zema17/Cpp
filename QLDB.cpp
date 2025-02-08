#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phone;
};

vector<Contact> contacts;

void addContact() {
    Contact newContact;
    cout << "Nhập tên: ";
    cin.ignore();
    getline(cin, newContact.name);
    cout << "Nhập số điện thoại: ";
    cin >> newContact.phone;
    contacts.push_back(newContact);
    cout << "Đã thêm thành công!\n";
}

void deleteContact() {
    string name;
    cout << "Nhập tên cần xóa: ";
    cin.ignore();
    getline(cin, name);

    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == name) {
            contacts.erase(it);
            cout << "Đã xóa liên hệ thành công!\n";
            return;
        }
    }
    cout << "Không tìm thấy tên trong danh bạ.\n";
}

void displayContacts() {
    if (contacts.empty()) {
        cout << "Danh bạ trống.\n";
        return;
    }
    cout << "\nDanh sách liên hệ:\n";
    for (size_t i = 0; i < contacts.size(); i++) {
        cout << i + 1 << ". " << contacts[i].name << " - " << contacts[i].phone << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- Quản lý Danh Bạ ---\n";
        cout << "1. Thêm liên hệ\n";
        cout << "2. Xóa liên hệ\n";
        cout << "3. Hiển thị danh bạ\n";
        cout << "4. Thoát\n";
        cout << "Chọn chức năng: ";
        cin >> choice;

        switch (choice) {
            case 1: addContact(); break;
            case 2: deleteContact(); break;
            case 3: displayContacts(); break;
            case 4: cout << "Thoát chương trình.\n"; return 0;
            default: cout << "Chọn sai, vui lòng nhập lại.\n";
        }
    }
}
