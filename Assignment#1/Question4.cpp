#include <iostream>
using namespace std;

struct Song
{
    int id;
    string name;
    string artist;
    Song* next;

    Song(int i, string n, string a) : id(i), name(n), artist(a), next(NULL) {}
};


class Playlist {
private:
    Song* head;
    Song* current;

public:
    Playlist() {
        head = NULL;
        current = NULL;
    }


    void insertSong(int id, string name, string artist) {
        Song* newSong = new Song(id, name, artist);

        if (head == NULL) {
            head = newSong;
            newSong->next = head;   
            current = head;
        } else {
            Song* temp = head;
            while (temp->next != head)
                temp = temp->next;

            temp->next = newSong;
            newSong->next = head;   
        }

        cout << "Song added: " << name << endl;
    }

    void displaySongs() {
        if (head == NULL) {
            cout << "Playlist is empty!\n";
            return;
        }

        Song* temp = head;
        cout << "\nPlaylist Songs:\n";
        do {
            cout << temp->id << " - " 
                 << temp->name << " by " 
                 << temp->artist << endl;
            temp = temp->next;
        } while (temp != head);
    }

    void playNext() {
        if (current == NULL) {
            cout << "No songs available!\n";
            return;
        }

        cout << "Now Playing: " << current->name << endl;
        current = current->next;  
    }

    void deleteSong(int id) {
        if (head == NULL) return;

        Song* temp = head;
        Song* prev = NULL;

        if (head->next == head && head->id == id) {
            delete head;
            head = NULL;
            current = NULL;
            cout << "Song deleted!\n";
            return;
        }

        if (head->id == id) {
            Song* last = head;
            while (last->next != head)
                last = last->next;

            head = head->next;
            last->next = head;
            delete temp;
            cout << "Song deleted!\n";
            return;
        }

        prev = head;
        temp = head->next;

        while (temp != head && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp->id == id) {
            prev->next = temp->next;
            delete temp;
            cout << "Song deleted!\n";
        } else {
            cout << "Song not found!\n";
        }
    }

    void searchSong(string name) {
        if (head == NULL) return;

        Song* temp = head;
        do {
            if (temp->name == name) {
                cout << "Found: " << temp->name 
                     << " by " << temp->artist << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Song not found!\n";
    }
};
int main() {
    Playlist myPlaylist;

    myPlaylist.insertSong(1, "Shape of You", "Ed Sheeran");
    myPlaylist.insertSong(2, "Blinding Lights", "The Weeknd");
    myPlaylist.insertSong(3, "Levitating", "Dua Lipa");

    myPlaylist.displaySongs();

    myPlaylist.playNext();
    myPlaylist.playNext();

    myPlaylist.searchSong("Levitating");

    myPlaylist.deleteSong(2);
    myPlaylist.displaySongs();

    return 0;
}