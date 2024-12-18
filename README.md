# TE-6-HANGMAN

A comprehensive guide to playing and implementing the classic Hangman game.

## Game Overview

Hangman is a word-guessing game where one player (the "host") chooses a secret word, and other players attempt to guess it letter by letter. With each incorrect guess, part of a hangman figure is drawn, creating a countdown to game over.

## Playing Basic Hangman

### 1. Selecting the Host

One person must be designated as the "host." This person will:
- Choose the word or phrase for others to solve
- Keep track of correct and incorrect guesses
- Draw the hangman figure as needed

*Note: The host should be confident in their spelling abilities, as incorrect spelling would make the game impossible to win.*

### 2. Choosing the Secret Word

The host selects a word or phrase that players will need to guess. For a challenging game:
- Choose words with uncommon letters (like 'z', 'j', 'x')
- Select words with fewer vowels
- Consider using phrases for longer games
- Keep the word secret from all players

### 3. Setting Up the Game Board

The host must:
- Draw one blank line for each letter in the chosen word
- Space the lines evenly for clarity
- For phrases, include obvious spaces between words

Example: For the word "zipper", draw: _ _ _ _ _ _

### 4. Gameplay: Letter Guessing

Players take turns guessing letters that might appear in the word. Strategy tips:
- Begin with common letters (vowels, 's', 't', 'n')
- Pay attention to letter patterns and word structure
- Consider word length and possible categories

### 5. Handling Correct Guesses

When players guess correctly:
- Host fills in ALL instances of the guessed letter
- Letters must be written clearly in their correct positions
- Multiple occurrences of the same letter must all be revealed

Example progression for "zipper":
- After 'e' guess: _ _ _ _ e _
- After 'p' guess: _ _ p p e _

### 6. Drawing the Hangman

For incorrect guesses, the host draws the hangman in this sequence:

1. Gallows: Draw an upside-down "L"
2. Head: Add a circle below the horizontal line
3. Body: Draw a vertical line from the head
4. First arm: Add a line from the middle of the body
5. Second arm: Complete the pair of arms
6. First leg: Draw a diagonal line from the body's base
7. Second leg: Complete the pair of legs
8. Noose: Connect head to gallows (game over)

### 7. Winning and Losing Conditions

The game ends when either:
- Players win by:
  - Correctly guessing all letters in the word
  - Successfully guessing the complete word at once
- Players lose when:
  - The hangman drawing is completed
  - Note: Guessing an incorrect complete word counts as one wrong guess

## MINT program

```
// HANGMAN for MINT
// Variables used:
// w - word array
// g - guessed letters array
// t - tries left
// c - current letter
// i,j - loop counters
// s - success flag
// n - letter found flag

// Initialize word array with "MINT" as the word to guess
:I \[77 73 78 84] w! // "MINT" in ASCII
   \[0 0 0 0] g!     // Guessed letters array
   6 t!              // Number of tries
;

// Draw hangman based on tries left
:H t 6 = (`   +---+   ` /N
         `   |   |   ` /N
         `       |   ` /N
         `       |   ` /N
         `       |   ` /N
         `     =====` /N) /E
   t 5 = (`   +---+   ` /N
         `   |   |   ` /N
         `   O   |   ` /N
         `       |   ` /N
         `       |   ` /N
         `     =====` /N) /E
   t 4 = (`   +---+   ` /N
         `   |   |   ` /N
         `   O   |   ` /N
         `   |   |   ` /N
         `       |   ` /N
         `     =====` /N) /E
   t 3 = (`   +---+   ` /N
         `   |   |   ` /N
         `   O   |   ` /N
         `  /|   |   ` /N
         `       |   ` /N
         `     =====` /N) /E
   t 2 = (`   +---+   ` /N
         `   |   |   ` /N
         `   O   |   ` /N
         `  /|\  |   ` /N
         `       |   ` /N
         `     =====` /N) /E
   t 1 = (`   +---+   ` /N
         `   |   |   ` /N
         `   O   |   ` /N
         `  /|\  |   ` /N
         `  /    |   ` /N
         `     =====` /N) /E
   t 0 = (`   +---+   ` /N
         `   |   |   ` /N
         `   O   |   ` /N
         `  /|\  |   ` /N
         `  / \  |   ` /N
         `     =====` /N)
;

// Print word with guessed letters
:W 4( w /i \? c!      // Get current letter
      g /i \? 0 = (   // If not guessed
         `_` 
      ) /E (          // Else
         c /C         // Print the letter
      )
      ` `            // Space between letters
   )
   /N
;

// Check if letter is in word
:C 0 n!              // Reset found flag
   4( w /i \? c = (  // If letter matches
      c g /i \?!     // Store in guessed array
      1 n!           // Set found flag
   ))
;

// Check if word is complete
:F 1 s!              // Assume success
   4( g /i \? 0 = (  // If any letter not guessed
      0 s!           // Clear success flag
   ))
;

// Main game loop
:M `Welcome to Hangman!` /N
   `Guess the 4-letter word` /N
   /N
   I                 // Initialize game
   /U (             // Unlimited loop
      H             // Draw hangman
      /N
      W             // Show word status
      /N
      `Tries left: ` t . /N
      /N
      `Enter a letter: `
      /K c!         // Get input
      C             // Check letter
      n 0 = (       // If letter not found
         t 1 - t!   // Decrease tries
      )
      F             // Check if complete
      s /T = (      // If word complete
         /N
         `You won! The word was MINT` /N
         0 /W       // Break loop
      )
      t 0 = (       // If out of tries
         /N
         `Game Over! The word was MINT` /N
         0 /W       // Break loop
      )
   )
;

// Run game with M
```

1. Uses a fixed word "MINT" for demonstration (could be modified to use different words)
2. Displays ASCII art for the hangman based on remaining tries
3. Shows guessed letters and remaining tries
4. Takes keyboard input for guesses
5. Handles win/lose conditions

Key features:

1. Game state variables:
   - w: Word array (stores ASCII values)
   - g: Guessed letters array 
   - t: Tries remaining
   - c: Current input letter
   - s: Success flag
   - n: Letter found flag

2. Main functions:
   - I: Initializes the game
   - H: Draws the hangman ASCII art
   - W: Displays the word with guessed letters
   - C: Checks if a guessed letter is in the word
   - F: Checks if the word is complete
   - M: Main game loop

To play:

1. Type `M` and press Enter to start the game
2. Enter one letter at a time when prompted
3. You have 6 tries to guess the word "MINT"
4. The game ends when you either:
   - Successfully guess the word
   - Run out of tries

