#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct note {
    // You may choose to add or change fields in this struct.
    int octave;
    int key;
    struct note *next;
};
struct player* createNote(int newOctave, int newKey, struct note* newNext);
struct note* insertNote(struct note* insersionPoint, int newOctave, int newKey);

int main(void){
    struct note* current = newNote;
    struct note* prev = NULL;
    while (current != NULL) {// < 0 st1 < st2; >0 st1 > st2;
        // Loops while newName > current->name
        prev = current;
        current = current->next;
    }//  current->name is the first string higher than the newName.
    scanf("%d %d"&octave, &key);
    struct note* insertPoint = insertNote(prev, octave, key);
    if (prev == NULL) {// Inserting at the beginning of the list.
        insertPoint->next = newNote;
        newNote = insertPoint;
    }
    return 0;
}

struct player* createNote(int newOctave, int newKey, struct note* newNext){
    struct player* newNote = malloc(sizeof(struct note));
    newNote->octave = newOctave;// newPlayer->name = newName; becuase we need to loop through these names.
    newNote->key = newKey;
    newNote->next = newNext;
    return newNote;
}

struct note* insertNote(struct note* insersionPoint, int newOctave, int newKey) {
    struct player* newNote = createNote(newOctave, newKey, NULL);
    if (insersionPoint == NULL) {// the list is NULL
        insersionPoint = newNote;
    } else{// the insersion point is a node
          newNote->next = insersionPoint->next;
          insersionPoint->next = newNote;
    }
    return insersionPoint;
}
