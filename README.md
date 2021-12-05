# peanutgrinder

(currently) brute-force-only solution to pnut-butta

## Installation

Compile `main.cpp` on Windows and run the executable.

## Context

pnut-butta is a two-player game revolving around substrings (idea by me and ceilingfans).

1. A set of symbols `s` (in this short example `{0, 1}`) and an integer `l` (in this example `2`) are set up.

2. Player 1 writes a symbol from the set to start the string.  
`0`

3. The next player writes another symbol at the end of the string. This has to be done in such a manner that the ending substring of length `l` has not appeared anywhere in the entire string before this change. For example, `011` is okay because the ending substring `11` does not appear anywhere before it. However `0111` is not okay because the substring `11` has appeared somewhere before in the string (0**11**1, 01**11**). (Having the same substring appear again but reversed does not break this rule so `0110` is okay.) Note that these are examples when `l = 2`. If `l = 3` this rule would apply to length `3` substrings.

4. Step 3 is repeated between alternating players until one of them has no legal moves or "trapped", in which case the player who played the last move wins. The game will always end in a finite number of steps; in fact there is an intrinsic maximum length for every finite size of `s` and finite `l`.

Here is an example with `{0, 1, 2}` and `l = 3`:

P1: `0` (P2 options: `0, 1, 2`)  
P2: `00` (P1 options: `0, 1, 2`)  
P1: `000` (P2 options: `1, 2`)  
P2: `0001` (P1 options: `0, 1, 2`)  
P1: `00012` (P2 options: `0, 1, 2`)  
P2: `000120` (P1 options: `0, 1, 2`)  
P1: `0001200` (P2 options: `2`)  
P2: `00012002` (P1 options: `0, 1, 2`)  
P1: `000120021` (P2 options: `0, 1, 2`)  
P2: `0001200210` (P1 options: `0, 1, 2`)  
P1: `00012002100` (P2 options: none)  
P1 wins.

Why there aren't any options for P2:  
`000120021000` is illegal since **000**120021**000**,  
`000120021001` is illegal since 0**001**20021**001**,  
`000120021002` is illegal since 00012**002**1**002**.

Side note: I like `{0, 1, 2}` and `l = 4` a lot and it just so happens to be one of the settings that leaves this AI completely stumped, so I guess on the bright side I can still have my fun and I recommend trying this out with a friend (may take around 5 minutes though).

## Program behaviour

The program has a built-in brute-force AI which will guarantee its win where possible, but can't yet delay or evade a loss where guaranteeing a win isn't possible. If it's not possible, it'll print a little "`:(`" as an indication that you still have a chance to win. The program also has a built-in assistant that shows you your options and a mechanism that prevents you from making illegal moves.

Unfortunately it doesn't allow human vs human games and the AI begins to break at pathetically low settings; for human vs human of any settings you'll have to go to https://github.com/ceilingfans/pnut-butta

## Future plans

* fix bug where when program receives character input when integer input is required an infinite loop starts consuming a substantial amount of CPU

* AI unable to delay or evade a loss where guaranteeing a win isn't possible; create a separate function where this is possible

* give AI customizable search depth limit, program currently may run almost indefinitely for higher settings

* create an actual machine learning AI using Python which might actually be of some use at higher settings

## Credits

* [ceilingfans](https://github.com/ceilingfans)

* [pnut-butta](https://github.com/ceilingfans/pnut-butta)
