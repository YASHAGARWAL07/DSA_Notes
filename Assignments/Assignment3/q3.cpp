#include <iostream>
#include <string>
using namespace std;

struct MusicNode {
    string title;
    string album;
    float time; // in minutes
    MusicNode *next;
    MusicNode *prev;
};

struct Playlist {
private:
    MusicNode *head;
    MusicNode *current;

public:
    Playlist() {
        head = NULL;
        current = NULL;
    }

    // Add music at end of playlist
    void addMusic(string title, string album, float time) {
        MusicNode *temp = new MusicNode;
        temp->title = title;
        temp->album = album;
        temp->time = time;
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL) {
            head = temp;
            current = head;
        } else {
            MusicNode *temp2 = head;
            while (temp2->next != NULL)
                temp2 = temp2->next;
            temp2->next = temp;
            temp->prev = temp2;
        }
        cout << "Added: " << title << " (" << album << ", " << time << " mins)\n";
    }

    // Play next music
    void playNext() {
        if (current == NULL) {
            cout << "Playlist empty!\n";
            return;
        }
        if (current->next != NULL)
            current = current->next;
        cout << "Now Playing → " << current->title << " | " << current->album
             << " | " << current->time << " mins\n";
    }

    // Play previous music
    void playPrev() {
        if (current == NULL) {
            cout << "Playlist empty!\n";
            return;
        }
        if (current->prev != NULL)
            current = current->prev;
        cout << "Now Playing → " << current->title << " | " << current->album
             << " | " << current->time << " mins\n";
    }

    // Remove current music
    void remove() {
        if (current == NULL) {
            cout << "Playlist empty!\n";
            return;
        }
        MusicNode *temp = current;
        cout << "Removed: " << temp->title << "\n";

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        current = temp->next != NULL ? temp->next : temp->prev;

        delete temp;
    }

    // Display full playlist
    void display() {
        if (head == NULL) {
            cout << "Playlist empty!\n";
            return;
        }
        cout << "Playlist:\n";
        MusicNode *temp = head;
        while (temp != NULL) {
            cout << "  " << temp->title << " | " << temp->album
                 << " | " << temp->time << " mins\n";
            temp = temp->next;
        }
    }
};

int main() {
    Playlist pl;

    // Arijit Singh songs
    pl.addMusic("Tum Hi Ho", "Aashiqui 2", 4.2);
    pl.addMusic("Channa Mereya", "Ae Dil Hai Mushkil", 4.5);
    pl.addMusic("Kesariya", "Brahmastra", 3.5);

    // Mohammad Irfan songs
    pl.addMusic("Phir Mohabbat", "Murder 2", 5.0);
    pl.addMusic("Banjaara", "Ek Villain", 4.1);
    pl.addMusic("Baarish", "Yaariyan", 4.0);

    pl.display();

    pl.playNext();
    pl.playNext();
    pl.playPrev();

    pl.remove();
    pl.display();

    return 0;
}
