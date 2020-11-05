// Assignment 2 20T1 COMP1511: CS bEats
// test_beats.c
//
// This program was written by Calvin Li (z5242094)
// on April 18 2020
//
// Version 1.0.0: Assignment released.
#include <stdio.h>
#include <stdlib.h>

#include "test_beats.h"
#include "beats.h"

struct note {
    // You may choose to add or change fields in this struct.
    int octave;
    int key;
    struct note *next;
};

// Test function for `add_note_to_beat`
int test_add_note_to_beat(void) {
    // Test 1: Rejecting negative inputs.
    Beat test_beat = create_beat();
    if (add_note_to_beat(test_beat, -1, -1) != INVALID_OCTAVE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, -1, 0) != INVALID_OCTAVE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, 1, -1) != INVALID_KEY) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 2: Rejecting identical inputs.
    if (add_note_to_beat(test_beat, 2, 2) != VALID_NOTE) {
        return DOES_NOT_MEET_SPEC;
    } if (add_note_to_beat(test_beat, 2, 2) != NOT_HIGHEST_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }


    // Test 3: Rejecting non ascending notes
    if (add_note_to_beat(test_beat, 2, 5) != VALID_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, 2, 1) != NOT_HIGHEST_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, 3, 1) != VALID_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, 3, 5) != VALID_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }
    else {
        return MEETS_SPEC;
    }
}

// Test function for `count_notes_in_octave`
int test_count_notes_in_octave(void){
    // Test 1: Counting invalid octaves.
    Beat test_beat = create_beat();
    add_note_to_beat(test_beat, 1, 1);
    if (count_notes_in_octave(test_beat, -1) != 0) {
        return DOES_NOT_MEET_SPEC;
    }
    if (count_notes_in_octave(test_beat, 11) != 0) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 2: given a Beat with
    //    no Notes of the right octave.
    add_note_to_beat(test_beat, 1, 1);
    if (count_notes_in_octave(test_beat, 1) != 1) {
        return DOES_NOT_MEET_SPEC;
    }
    if (count_notes_in_octave(test_beat, 2) != 0) {
        return DOES_NOT_MEET_SPEC;
    }
    
    
    // Test 3: given a beat with no notes
    // TODO: Write Test 3
    Beat test_beat_1 = create_beat();
    if (count_notes_in_octave(test_beat_1, 2) != 0) {
        return DOES_NOT_MEET_SPEC;
    }
    else {
        return MEETS_SPEC;
    }
}

// Test function for `add_beat_to_track`
int test_add_beat_to_track(void){
    // Test 1: ???
    // TODO: Write Test 1

    // Test 2: ???
    // TODO: Write Test 2

    // Test 3: ???
    // TODO: Write Test 3

    return MEETS_SPEC;
}

// Test function for `remove_selected_beat`
int test_remove_selected_beat(void){
    // Test 1: ???
    // TODO: Write Test 1

    // Test 2: ???
    // TODO: Write Test 2

    // Test 3: ???
    // TODO: Write Test 3

    return MEETS_SPEC;
}

// Test function for `add_musical_note_to_beat`
int test_add_musical_note_to_beat(void){
    // Test 1: ???
    // TODO: Write Test 1

    // Test 2: ???
    // TODO: Write Test 2

    // Test 3: ???
    // TODO: Write Test 3

    return MEETS_SPEC;
}
