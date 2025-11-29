#include <iostream>
#include <string>
using namespace std;

class Song {
public:
    string name;
    Song* next;
    Song(string n) {
        name = n;
        next = nullptr;
    }
};
class MusicPlaylist {
private:
    Song* head;
    Song* current;
public:
    MusicPlaylist() {
        head = nullptr;
        current = nullptr;
    }
    
    void addSong(string name) {
        Song* newSong = new Song(name);
        if (head == nullptr) {
            head = newSong;
            newSong->next = head;
            current = head;
        } else {
            Song* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newSong;
            newSong->next = head;
        }
    }
    
    void playNext() {
        if (current == nullptr) {
            return;
        }else {
        current = current->next;
        cout << "playing: " << current->name << endl;
        }
    }
    
    void print() {
        if (head == nullptr) {
            return;
        }
        Song* temp = head;
        cout << "Playlist: ";
        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(repeat)" << endl;
    }
};

int main() {
    MusicPlaylist playlist;
    
    playlist.addSong("i love u so");
    playlist.addSong("glue song");
    playlist.addSong("sienna");
    playlist.addSong("valetina");
    playlist.print();
    playlist.playNext();
    playlist.playNext();
    playlist.playNext();
    playlist.playNext();
    playlist.playNext();
    
    return 0;
}
