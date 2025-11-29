#include <iostream>
#include <string>
using namespace std;

class Page {
public:
    string url;
    Page* next;
    Page* prev; 
    Page(string u) {
        url = u;
        next = nullptr;
        prev = nullptr;
    }
};
class BrowserHistory {
private:
    Page* current;
    
public:
    BrowserHistory() {
        current = nullptr;
    }
    void visit(string url) {
        Page* newPage = new Page(url);
        if (current != nullptr) {
            current->next = newPage;
            newPage->prev = current;
        }
        current = newPage;
        cout << url << endl;
    }
    void back() {
        if (current == nullptr || current->prev == nullptr) {
            return;
        }
        current = current->prev;
        cout << "Back " << current->url << endl;
    }
    
    void forward() {
        if (current == nullptr || current->next == nullptr) {
            return;
        }
        current = current->next;
        cout << "Forward" << current->url << endl;
    }
    
    void show() {
        if (current == nullptr) {
            return;
        } else {
            cout << current->url << endl;
        }
    }
};

int main() {
    BrowserHistory browser;
    browser.visit("google.com");
    browser.visit("youtube.com");
    browser.visit("ig.com");
    browser.back();
    browser.back();
    browser.forward();
    browser.show();
    
    return 0;
}
