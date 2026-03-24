#include <iostream>
using namespace std;

struct Node
{
    string url;
    string title;
    Node* next;
    Node* prev;

    Node(string u, string t) : url(u), title(t), next(NULL), prev(NULL) {}
};


class Browser {
private:
    Node* head;
    Node* current;

public:
    Browser() {
        head = NULL;
        current = NULL;
    }

    void visit(string url, string title) {
        Node* newNode = new Node(url, title);

        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }
        cout << "Visited: " << title << endl;
    }

    void back() {
        if (current != NULL && current->prev != NULL) {
            current = current->prev;
            cout << "Moved Back to: " << current->title << endl;
        } else {
            cout << "No previous page!\n";
        }
    }

    void forward() {
        if (current != NULL && current->next != NULL) {
            current = current->next;
            cout << "Moved Forward to: " << current->title << endl;
        } else {
            cout << "No forward page!\n";
        }
    }

    void deletePage(string url) {
        Node* temp = head;

        while (temp != NULL && temp->url != url) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Page not found!\n";
            return;
        }

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        if (current == temp)
            current = temp->prev;

        delete temp;
        cout << "Page deleted successfully!\n";
    }

    void displayForward() {
        Node* temp = head;
        cout << "\nBrowsing History (Forward):\n";
        while (temp != NULL) {
            cout << temp->title << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
   }
    void displayReverse() {
        Node* temp = head;
        if (temp == NULL) return;

        while (temp->next != NULL)
            temp = temp->next;

        cout << "\nBrowsing History (Reverse):\n";
        while (temp != NULL) {
            cout << temp->title << " -> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
};
int main() {
    Browser browser;

    browser.visit("https://www.google.com", "Google");
    browser.visit("https://www.facebook.com", "Facebook");
    browser.visit("https://www.youtube.com", "YouTube");

    browser.displayForward();
    browser.displayReverse();

    browser.back();
    browser.back();
    browser.forward();

    browser.deletePage("https://www.facebook.com");
    browser.displayForward();

    return 0;
}