#include "LinkedList.h"
#include "PlayList.h"
int main() {

    //------------------------------------------------
    // LinkedList: 1 → 2 → 3
    LinkedList* list = new LinkedList(1);
    list->next = new LinkedList(2);
    list->next->next = new LinkedList(3);

    Iterator<int>* iterator1 = list->getIterator();

    cout << "LinkedList contents: ";

    while (iterator1->hasNext()) {
        cout << iterator1->next() << " ";
    }

    cout << "\n";

    //------------------------------------------------

    //------------------------------------------------

    // Playlist
    Playlist playlist;
    playlist.addSong(Song("Admirin You", "Karan Aujla"));
    playlist.addSong(Song("Husn", "Anuv Jain"));

    Iterator<Song>* iterator3 = playlist.getIterator();

    cout << "Playlist songs:\n";

    while (iterator3->hasNext()) {
        Song s = iterator3->next();
        cout << "  " << s.title << " by " << s.artist << "\n";
    }

    //------------------------------------------------

    // Cleanup
    delete list->next->next;
    delete list->next;
    delete list;

    return 0;
}
