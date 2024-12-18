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

## Implementation Files

