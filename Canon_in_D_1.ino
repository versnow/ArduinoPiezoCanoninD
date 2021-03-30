#include "pitches_442.h" //use pitches_440.h for alternate tuning

//Syntax
//
//tone(pin, frequency) 
//tone(pin, frequency, duration)
//
//Parameters
//
//pin: the pin on which to generate the tone
//frequency: the frequency of the tone in hertz - unsigned int
//duration: the duration of the tone in milliseconds (optional) - unsigned long


// Canon in D - Pachelbel

// change this to make the song slower or faster
int tempo = 120;

// change this to the pin the buzzer is attached to
int buzzer = 8;

// notes of the melody, followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// negative numbers represent dotted notes.
// -4 means a dotted quarter note, that is, a quarter plus an eighteenth
int melody[] = {
  
  //holding 1
  NOTE_D4,8, NOTE_E4,8,
  NOTE_FS4,1, NOTE_E4,1,
  NOTE_D4,1, NOTE_CS4,1,
  NOTE_B3,1, NOTE_A3,1,
  NOTE_B3,1, NOTE_CS4,1,

  //holding 2
  NOTE_FS4,2, NOTE_E4,2,
  NOTE_D4,2, NOTE_CS4,2,
  NOTE_B3,2, NOTE_A3,2,
  NOTE_B3,2, NOTE_CS4,2,

  //chorus 1
  NOTE_A4,4, NOTE_FS4,8, NOTE_G4,8, NOTE_A4,4, NOTE_FS4,8, NOTE_G4,8, NOTE_A4,8, 
  NOTE_A3,8, NOTE_B3,8, NOTE_CS4,8, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,8, NOTE_G4,8,
  NOTE_FS4,4, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,4, NOTE_FS3,8, NOTE_G3,8,
  NOTE_A3,8, NOTE_B3,8, NOTE_A3,8, NOTE_G3,8, NOTE_A3,8, NOTE_D4,8, NOTE_CS4,8, NOTE_D4,8,
  NOTE_B3,4, NOTE_D4,8, NOTE_CS4,8, NOTE_B3,4, NOTE_A3,8, NOTE_G3,8,
  NOTE_A3,8, NOTE_G3,8, NOTE_FS3,8, NOTE_G3,8, NOTE_A3,8, NOTE_B3,8, NOTE_CS4,8, NOTE_D4,8,
  NOTE_B3,4, NOTE_D4,8, NOTE_CS4,8, NOTE_D4,4, NOTE_CS4,8, NOTE_D4,8,
  NOTE_A3,8, NOTE_B3,8, NOTE_CS4,8, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,8, NOTE_G4,8, NOTE_A4,8,

  //chorus 2
  NOTE_A4,4, NOTE_FS4,8, NOTE_G4,8, NOTE_A4,4, NOTE_FS4,8, NOTE_G4,8, NOTE_A4,8, 
  NOTE_A3,8, NOTE_B3,8, NOTE_CS4,8, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,8, NOTE_G4,8,
  NOTE_FS4,4, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,4, NOTE_FS3,8, NOTE_G3,8,
  NOTE_A3,8, NOTE_B3,8, NOTE_A3,8, NOTE_G3,8, NOTE_A3,8, NOTE_D4,8, NOTE_CS4,8, NOTE_D4,8,
  NOTE_B3,4, NOTE_D4,8, NOTE_CS4,8, NOTE_B3,4, NOTE_A3,8, NOTE_G3,8,
  NOTE_A3,8, NOTE_G3,8, NOTE_FS3,8, NOTE_G3,8, NOTE_A3,8, NOTE_B3,8, NOTE_CS4,8, NOTE_D4,8,
  NOTE_B3,4, NOTE_D4,8, NOTE_CS4,8, NOTE_D4,4, NOTE_CS4,8, NOTE_D4,8,
  NOTE_A3,8, NOTE_B3,8, NOTE_CS4,8, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,8, NOTE_G4,8, NOTE_A4,8,

  NOTE_A4,4, NOTE_FS4,8, NOTE_G4,8, NOTE_A4,4, NOTE_FS4,8, NOTE_G4,8, NOTE_A4,8, 
  NOTE_A3,8, NOTE_B3,8, NOTE_CS4,8, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,8, NOTE_G4,8,
  NOTE_FS4,4, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,4, NOTE_FS3,8, NOTE_G3,8,
  NOTE_A3,8, NOTE_B3,8, NOTE_A3,8, NOTE_G3,8, NOTE_A3,8, NOTE_D4,8, NOTE_CS4,8, NOTE_D4,8,
  NOTE_B3,4, NOTE_D4,8, NOTE_CS4,8, NOTE_B3,4, NOTE_A3,8, NOTE_G3,8,
  NOTE_A3,8, NOTE_G3,8, NOTE_FS3,8, NOTE_G3,8, NOTE_A3,8, NOTE_B3,8, NOTE_CS4,8, NOTE_D4,8,
  NOTE_B3,4, NOTE_D4,8, NOTE_CS4,8, NOTE_D4,4, NOTE_CS4,8, NOTE_D4,8,
  NOTE_A3,8, NOTE_B3,8, NOTE_CS4,8, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,8, NOTE_G4,8, NOTE_A4,8,
  
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void setup() {

}

void loop() {
  // looping melody
    // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    //no break between notes
    tone(buzzer, melody[thisNote], noteDuration);

    // Wait for the specfied duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}
