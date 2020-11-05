// Assignment 2 20T1 COMP1511: CS bEats
// beats.c
//
// This program was written by Calvin Li (z5242094)
// on 10\04\2020
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Fix default return value of add_musical_note_to_beat.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
// Add any extra #includes your code needs here.

#include "beats.h"

// Add your own #defines here.

////////////////////////////////////////////////////////////////////////

// You don't have to use the provided struct track, you are free to
// make your own struct instead.
// If you use the provided struct track, you will have to add fields
// to store other information.

struct track {
    // TODO: You will have to add extra fields here in Stage 2.
    struct beat *beats;
    struct beat *next;
    struct beat *current;
};

// You don't have to use the provided struct beat, you are free to
// make your own struct instead.
// If you use the provided struct beat, you may add fields
// to it to store other information.

struct beat {
    // You may choose to add or change fields in this struct.
    struct note *notes;
    struct beat *next;
};

// You don't have to use the provided struct note, you are free to
// make your own struct instead.
// If you use the provided struct note, you add fields
// to it to store other information.

struct note {
    // You may choose to add or change fields in this struct.
    int octave;
    int key;
    struct note *next;
};

// Add any other structs you define here.

////////////////////////////////////////////////////////////////////////

// Add prototypes for any extra functi ons you create here.

// compare exsited note in beat and the new note inputed by user.
// return 0 if two notes are identical
// return 1 if notes are ascending
// return -1 if notes are not ascending
int noteCompare(Beat beat, int octave, int key) {
    struct note* current = beat->notes;
    if (current == NULL) {
        return 1;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }// curr->next = NULL;
        if (octave < current->octave) {
            return -1;
        } else if (current->octave == octave) {
            if (key < current->key) {
                return -1;
            }  else if (key == current->key) {
                return 0;
            } else {
                return 1;
            }
        } else {
            return 1;
        }
    }
}

// Loop through to find the last beat in a track.
struct beat* findLastBeat(Track track) {
    struct beat* head = track->beats;
    struct beat* current = head;
    if (head == NULL) {
        return head;
    }
    while (current->next != NULL) {
        current = current->next;
    }// curr->next = NULL;
    return current;
}

// Return a malloced Beat with fields initialized.
Beat create_beat(void) {
    Beat new_beat = malloc(sizeof (struct beat));
    assert(new_beat != NULL);

    new_beat->next = NULL;
    new_beat->notes = NULL;

    // You do not need to change this function, unless you change
    // the implementation of struct beat.

    return new_beat;
}

// You need to implement the following functions.
// You can find descriptions of what each function should do in beats.h

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add a note to the end of a beat.
int add_note_to_beat(Beat beat, int newOctave, int newKey) {
    if (newOctave < 0 || newOctave >= 10) {
        return INVALID_OCTAVE;
    } else if (newKey < 0 || newKey >= 12) {
        return INVALID_KEY;
    } else if (noteCompare(beat, newOctave, newKey) != 1) {
        return NOT_HIGHEST_NOTE;
    } else {
        // loop through to find the last element
        struct note* current = beat->notes;
        struct note* newNote = malloc(sizeof(struct note));
        newNote->octave = newOctave;
        newNote->key = newKey;
        newNote->next = NULL;
        if (current == NULL) {
            beat->notes = newNote;
            return VALID_NOTE;
        }
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNote;

        return VALID_NOTE;
    }
}

// Print the contents of a beat.
void print_beat(Beat beat) {
    struct note* head = beat->notes;
    struct note* current = head;
    if (head == NULL) {
        printf(" \n");
    } else {
        printf("%d %02d ", current->octave, current->key);
        current = current->next;

        while (current != NULL) {
            printf("| %d %02d ", current->octave, current->key);
            current = current->next;
        }
        printf("\n");
    }
}

// Count the number of notes in a beat that are in a given octave.
int count_notes_in_octave(Beat beat, int octave) {
    int counter = 0;
    struct note* current = beat->notes;
    while (current != NULL) {
        if (current->octave == octave) {
            counter++;
        }
        current = current->next;
    }
    return counter;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

// Return a malloced track with fields initialized.
Track create_track(void) {
    // Note: there is no fprintf in this function, as the
    // Stage 1 autotests call create_track but expect it to return NULL
    // (so this function should do nothing in Stage 1).
    Track new_track = malloc(sizeof (struct track));
    assert(new_track != NULL);
    new_track->next = NULL;
    new_track->beats = NULL;
    new_track->current = NULL;

    return new_track;
}

// Add a beat after the current beat in a track.
void add_beat_to_track(Track track, Beat beat) {
    struct beat* current = track->beats;
    if (track->current == NULL) {
        if (track->beats == NULL) { // No beats in track
            track->beats = beat;
        } else {
            current = track->beats;
            track->beats = beat;
            beat->next = current;
        }
    } else {
        current = track->current->next;
        track->current->next = beat;
        beat->next = current;
    }
}

// Set a track's current beat to the next beat.
int select_next_beat(Track track) {
    struct beat* head = track->beats;
    if (track->current == NULL) {
        if (head != NULL) {
            track->current = head;
            return TRACK_PLAYING;
        } else {
            return TRACK_STOPPED;
        }
    } else {
        if (track->current->next == NULL) {
            track->current = NULL;
            return TRACK_STOPPED;
        } else {
            track->current = track->current->next;
            return TRACK_PLAYING;
        }
    }
}

// Print the contents of a track.
void print_track(Track track) {
    int counter = 1;
    struct beat* head = track->beats;
    while (head != NULL) {
        if (track->current == head) {
            printf(">");
            printf("[%d] ",counter);
        }
        else {
            printf(" ");
            printf("[%d] ",counter);
        }
        print_beat(head);
        head = head->next;
        counter++;
    }
}

// Count beats after the current beat in a track.
int count_beats_left_in_track(Track track) {
    struct beat* head = track->beats;
    struct beat* last = findLastBeat(track);
    struct beat* curr = track->current;
    int counter = 0;
    if (head == NULL) {
        return 0;
    } else if (curr == NULL) {
        curr = head;
        while (curr != last) {
            counter++;
            curr = curr->next;
        }
        counter++;
    } else { // general case
        while (curr != last) {
        counter++;
        curr = curr->next;
        }
    }
    return counter;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

// Free the memory of a beat, and any memory it points to.
void free_beat(Beat beat) {
    // Note: there is no printf in this function, as the
    // Stage 1 & 2 autotests call free_beat but don't check whether
    // the memory has been freed (so this function should do nothing in
    // Stage 1 & 2, rather than exit).
    struct note* current = beat->notes;
    while (current != NULL) {
        // have freed all notes before current.
        struct note* remNode = current;
        current = current->next;
        free(remNode);
    }
    free(beat);
}

// Free the memory of a track, and any memory it points to.
void free_track(Track track) {
    // Note: there is no printf in this function, as the
    // Stage 1 & 2 autotests call free_track but don't check whether
    // the memory has been freed (so this function should do nothing in
    // Stage 1 & 2, rather than print an error).
    Beat current = track->beats;
    while (current != NULL) {
        // have freed all notes before current.
        Beat remNode = current;
        current = current->next;
        free(remNode);
    }
    free(track);
}

// Remove the currently selected beat from a track.
int remove_selected_beat(Track track) {
    struct beat* prev = NULL;
    struct beat* current = track->beats;
    if (track->beats == NULL) {
        // It is an empty track with no beats.
        return TRACK_STOPPED;
        free_beat(track->beats);
    } else {
        // It's Not an empty track
        if (track->current == NULL) {
            // No current track to be removed.
            return TRACK_STOPPED;
        } else {
            while (current != track->current) {
                prev = current;
                current = current->next;
            }
            if (track->current->next == NULL) {
                // either choosing the only one in track
                // or choosing the last one
                if (prev == NULL) {
                    // select the only one beat in track
                    free_beat(track->current);
                    track->beats = NULL;
                    track->current = NULL;
                    return TRACK_STOPPED;
                }
                // select the last one in track.
                prev->next = NULL;
                free_beat(track->current);
                track->current = NULL;
                current = NULL;
                return TRACK_STOPPED;
            }
            if (prev == NULL && track->current->next != NULL) {
                // select the first beat in track
                current = track->current->next;
                free_beat(track->current);
                track->beats = current;
                track->current = current;
                return TRACK_PLAYING;
            }
            prev->next = track->current->next;
            free_beat(track->current);
            track->current = prev->next;
            return TRACK_PLAYING;
        }
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add note to beat, given its 'musical notation'.
int add_musical_note_to_beat(Beat beat, char *musical_notation) {
    int i = 0;
    int keybase = 0;
    if (musical_notation[1] == 'A') {
        keybase = 0;
    }
    if (musical_notation[1] == 'B') {
        keybase = 2;
    }
    if (musical_notation[1] == 'C') {
        keybase = 3;
    }
    if (musical_notation[1] == 'D') {
        keybase = 5;
    }
    if (musical_notation[1] == 'E') {
        keybase = 7;
    }
    if (musical_notation[1] == 'F') {
        keybase = 8;
    }
    if (musical_notation[1] == 'G') {
        keybase = 10;
    }
    
    int octave = musical_notation[0];
    
    int addings = 0;
    while (musical_notation[i] != '\0') {
        if (musical_notation[i] == '#') {
            addings++;
        }
        i++;
    }
    int key = keybase + addings;
    if (key - 11 > 0) {
        octave++;
        key = key - 12;
    }
    return add_note_to_beat(beat, octave, key);
}


////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

// Cut a range of beats to the end of a track.
void cut_range_to_end(Track track, int range_length) {
    printf("cut_range_to_end not implemented yet.");
    return;
}

// Reverse a list of beats within a range of a track.
int reverse_range(Track track, int range_length) {
    printf("reverse_range not implemented yet.");
    return 0;
}
