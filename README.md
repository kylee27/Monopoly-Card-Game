# ENGG1340 Group 77 Proposal
## A C++ Text-Based Implementation of the Monopoly DEAL Card Game

### Members
Lee, Ka Ying (3035926344)  
Ng, Churk Hin Jeremy (3035928160)

------------
### Introduction
This is a one-player C++ text-based implementation of the Monopoly DEAL card game. The user will play against the computer, which is at this stage proposed to make completely random moves throughout the game. For better understanding, the following describes the general game play and rules with physical cards. Technical approaches and details specifically referring to the game implementation are addressed in the Features section. Information in the Description section mostly comes from [Monoply Deal Rule (https://monopolydealrules.com/index.php)](https://monopolydealrules.com/index.php) by Two Game Enthusiasts with very slight amendments. 

------------
### Description 
#### 1. Cards Content
The deck consists of 107 cards.
<ol type='a'><li>35 action cards (rent cards excluded) - 
Deal Breaker (2), Just Say No (3), Sly Deal (3), Force Deal (3), Debt Collector (3), It&apos;s My Birthday (3), Pass Go (10), House (3), Hotel (3), and Double The Rent (2); </li><!--
--><li>28 property cards - 
Green Set (3), Dark Blue Set (2), Light Blue Set (3), Red Set (3), Utility Set (2), Yellow Set (3), Orange Set (3), Brown Set (2), Purple Set (3), and Railroad Set (4); </li><!--
--><li>11 property wildcards - 
Purple/Orange (2), Light Blue/Brown (1), Light Blue/Railroad (1), Dark Blue/Green (1), Railroad/Green (1), Red/Yellow (2), Utility/Railroad (1), and multi-coloured Property Wildcard (2); </li><!--
--><li>13 rent cards - 
Purple/Orange (2), Railroad/Utility (2), Green/Dark Blue (2), Brown/Light Blue (2), Red/Yellow (2), and Wild Rent card (3); and</li><!--
--><li>20 money cards - 
$10M (1), $5M (2), $4M (3), $3M (3), $2M (5), and $1M (6). </li></ol>

#### 2. General Game Play and Description
<ol type='a'><li>The objective of the game is to be the first player to complete 3 full property sets (not necessarily in different colours) and have them down on the table. Each set of property requires a different number of cards to be considered complete, for example the Green Set needs 3 while the Railroad Set needs 4 (see 1(b)). The property wildcards can be used as a property card of one of its colours. The multi-coloured Property Wildcards includes all colours, and hence can be used as any of the property cards.   </li><!--
--><li>Each player is randomly assigned 5 cards at the start of the game, the remaining shuffled cards form the draw pile. </li
><li>For each new turn, if the player of the turn has 0 cards in hand, they pick up 5 new cards from the draw pile; otherwise they pick up 2 new cards. (2); </li><!--
--><li>In each turn, after picking up new cards, the player can make at most three moves, including: 
	<ol type='i'><li>placing one money card or action card into their bank pile, </li><!--
	--><li>playing one action card in the discard pile, </li><!--
	--><li>playing one property card in their property section, and </li><!--
	--><li>When the turn ends, if the player has more than 7 cards in hand, they have to discard the excess cards into the discard pile until they are left with exactly 7 cards.  </li><!--
--><li>In case the draw pile runs out of cards while playing, the discard pile will be shuffled and become the new draw pile. The game continues. </li></ol>

#### 3. Property Cards
<ol type='a'><li>Property cards cannot be put into the bank, but can be used for payment.</li><!--
--><li>Property cards must be put into the player&apos;s property section, which is visible to all players, before rents can be charged on that.</li><!--
--><li>Rent cannot be charged against a single multi-coloured Property Wildcard. The card has to be played together with another single or dual coloured property card for rent to be charged. </li><!--
--><li>The multi-coloured Property Wildcard does not have any monetary value, and hence cannot be used for payment. However, it can be stolen or taken by other players with action cards (see 4. Action Cards), same as the other property cards.</li><!--
--><li>The maximum allowed number of each set of property cards is the number required for the set to be considered complete (the value in brackets in 1(b)). </li><!--
--><li>When the number of a set of property cards exceeds the maximum, the extra cards must be used to create a new set. For example, when the player has 3 yellow property cards and 2 wild property cards used as yellow cards, they have to be divided into two different property sets, because the maximum allowed number of property cards for a yellow set is 3, there cannot exist a yellow set with more than 3 property cards.</li><!--
--><li>Monetary values of each of the property cards, and rent collectable by the set of them:
((monetary value of one card) Colour: rent collectable by one card in the set, two cards in the set, …, full set)
	<ol type='i'><li>($4M) Green: $2M, $4M, $7M</li><!--
	--><li>($4M) Dark Blue: $3M, $8M</li><!--</li><!--
	--><li>($1M) Light Blue: $1M, $2M, $3M</li><!--
	--><li>($3M) Red: $2M, $3M, $6M</li><!--
	--><li>($2M) Utility: $1M, $2M</li><!--
	--><li>($3M) Yellow: $2M, $4M, $6M</li><!--
	--><li>($2M) Orange: $1M, $3M, $5M</li><!--
	--><li>($1M) Brown: $1M, $2M</li><!--
	--><li>($2M) Purple: $1M, $2M, $4M</li><!--
	--><li>($1M) Railroad: $1M, $2M, $3M, $4M</li><!--
	--><li>[wild] ($2M) Purple/Orange: depends on the colour chosen</li><!--
	--><li>[wild] ($1M) Light Blue/Brown: depends on the colour chosen</li><!--
	--><li>[wild] ($4M) Light Blue/Railroad: depends on the colour chosen</li><!--
    --><li>[wild] ($4M) Dark Blue/Green: depends on the colour chosen</li><!--
    --><li>[wild] ($4M) Railroad/Green: depends on the colour chosen</li><!--
    --><li>[wild] ($3M) Red/Yellow: depends on the colour chosen</li><!--
    --><li>[wild] ($2M) Utility/Railroad: depends on the colour chosen</li><!--
    --><li>[wild] (no monetary value) Multi-coloured Property Wildcard: depends on the colour chosen</li></ol></li></ol>

#### 4. Action Cards
All action cards can be banked as money. Rent cards are excluded from this section and are addressed in the next section. 
((monetary value) Name of card: function of card when played by you)
<ol type='a'><li>($5M) Deal Breaker: 
Steal a full set of properties from any other player and add it into your property section, including any buildings (houses and hotels). </li><!--
--><li>($4M) Just Say No: 
Use any time when an action card is played against you to cancel the effect. The cancellation effect of this card can be cancelled by another Just Say No card played by the opponent. It does not count as a card move. It is discarded into the discard pile after being played.  </li><!--
--><li>($3M) Sly Deal: 
Steal a property from any other player and add it into your property section. The property card stolen cannot be from a full set. </li><!--
--><li>($3M) Force Deal: 
Swap another player&apos;s property card with one from your property section. </li><!--
--><li>($3M) Debt Collector: 
Demand $5M from one other player. </li><!--
--><li>($2M) It&apos;s My Birthday: 
Demand $2M from all other players. </li><!--
--><li>($1M) Pass Go: 
Pick up two extra cards from the draw pile. More than one Pass Go can be played per turn. </li><!--
--><li>($3M) House: 
Add a House card to a completed set of properties to add $3M to the rent value. Only one House card can be added to a set. It cannot be added to Railroads or Utilities Sets. </li><!--
--><li>($4M) Hotel: 
Add a Hotel card to a completed set of properties to add $4M to the rent value, i.e. a total of $7M added (with the House previously added). A Hotel card can only be added after a House card is added to the same set of properties. Only one Hotel card can be added to a set. It cannot be added to Railroads or Utilities Sets. </li><!--
--><li>($1M) Double The Rent: 
Played before a Rent card to double the amount of rent collectable by that card. Note that playing a Double The Rent card itself is counted as a move, and playing a Rent card is another move. More than one Double The Rent card can be played for one Rent card. If the opponent plays a Just Say No card, they cancel the doubling effect of the card but still have to pay the original rent value. </li></ol>

#### 5. Rent Cards
All Rent cards can be banked as money. 
<ol type='a'><li>The player can only choose one set of property to charge rent against for each Rent card played. </li><!--
--><li>For Wild Rent cards, the player can specify only one other player to pay them rent for properties they own in any colour. </li><!--
--><li>For other Rent cards, all other players have to pay the rent for properties the player owns in one of the colours on the Rent card. </li><!--
--><li>Monetary values of each of the property cards:
    <ol type='i'><li>Purple/Orange: $1M</li><!--
    --><li>Railroad/Utility: $1M</li><!--
    --><li>Green/Dark Blue: $1M</li><!--
    --><li>Brown/Light Blue: $1M</li><!--
    --><li>Red/Yellow: $1M</li><!--
    --><li>Wild Rent card: $3M</li></ol></li></ol>

#### 6. Payment
<ol type='a'><li>Cards in hand cannot be used for payment. Only property cards and cards in the player&apos;s bank pile can be used. </li><!--
--><li>Change is not given. If a player is charged $2M and they only have $3M to pay, they do not get a change. </li><!--
--><li>If property cards are used for payment, they must go into the property section of the payee. </li><!--
--><li>If action, rent or money cards are used for payment, they must go into the bank pile of the payee. </li><!--
--><li>If the payer cannot pay the full amount required, the remaining amount does not have to be paid. </li><!--
--><li>If the payer has no cards in their bank pile and property section, they do not pay anything. </li></ol>

------------
### Features
#### 1. Generation of random game sets or events
The cards user drew are all randomly generated to make the game different every time. Users have to draw cards from a shuffled deck during the game. Therefore, the program should generate a random card every time the user draws a card. <br>
This feature can be done by a random number generator (RNG). 
Every card in the deck is first represented by a number (from 0 to 106). The RNG is then initialized according to the time. Every time a player draws a card, the RNG will give a number and the program will assign the corresponding card to the player. The number generated will also be saved in an array. If the RNG returns a number appearing in the array (i.e. a card not in the deck), the RNG is required to regenerate a new number until the number is not in the array (i.e. a card in the deck).

#### 2. Data structures for storing game status
Each player&apos;s game data and status, including properties and money in the bank, are stored in the program. Money cards and property cards are further divided into different categories in terms of monetary value and property colour. It will be lengthy and confusing to store all information of one player in an array. It will also be confusing if the information of one player is stored in different arrays.<br>
This problem can be solved by using appropriate data structures. First, a data structure &apos;card&apos; is set including id(integer), name(string), value(integer), colour(string) and a pointer of card pointing to the address of the next card. A list of card can be saved in a linked list. Then, a data structure &apos;player&apos; is set including two pointers of card pointing to the first element of two linked list representing hand and bank respectively. &apos;player&apos; also includes a vector of cards that saves the first card of each property of the player. Note that each property itself is a linked list and therefore the vecotr saves all the property the player has. &apos;player&apos; includes two booleans representing if the player has just say no or uses double rent, and an integer represent the total wealth of the player. All cards will be initailize by assigning them to three vectors, &apos;cardPool&apos; representing the deck, &apos;draw&apos; representing the cards that are drew, and &apos;discarded&apos; representing the cards that player discarded. Therefore, it stores the game status.

#### 3. Dynamic memory management
The used cards (i.e. the discard pile) have to be shuffled again and be the new deck (i.e. the draw pile) when the deck is empty. The game has to save down the list of where the cards are. Therefore it has to save the discarded cards, undrawn cards, cards that are drew. Since the total number of cards is quite high, it is not desirable to assign three arrays with the length of the total number of cards while part of the array is empty most of the time.<br>
This problem can be solved by using dynamic memory management. The program sets three vecots for saving the information. When some information is not needed at some time (for example, when the deck is empty and the discarded cards are shuffled and become a new deck, the vector for discarded cards should be empty as the discard pile is emptied), the memories should be released to lower the use of memory. It can be done by shrinking the vector.  When there is new elements for one vector (for example, drawing a card from deck), there must be a card that should be removed from another vector. Vector can increase its memory when there is a new element, and shrink down if the memory is larger that the numbers of elements. Therefore, it can ensure the total momery allocated for three vectors will not be changed greatly as they can always release unused memory.

#### 4. File input/output 
This game allows users to save the progress of the current game and load in the same game file even if the users leave the game. <br>
This feature can be done by file input/output. When the user requires to save the game status, the game status is output to a game file. The game file includes the elements in the current game, such as id of the cards in hand, money in bank, property of players, discarded and undrawn cards. The game file is saved as a .txt file. 
When the program runs next time, the user can choose to load data from an existing game file. The .txt file that saved the game status is input to the program. Then the program will generate the exact same game status as saved by the user.

#### 5. Program codes in multiple files
The program consists of different parts, mainpage, game and file input/output. It will be too lengthy if the codes are kept in one file. Readability will decrease and it will be difficult to modify.
Therefore, we can put codes in multiple files. Bugs and errors can be more easily corrected. Lines of code can be more easily reused as well.

------------
### Special Notes About This Implementation
#### 1. Just Say No
In this implementation, players cannot play 'Just Say No' to another 'Just Say No' action card.

#### 2. Action Cards Validity
If the actions are invalid (e.g. demanding $5M from opponent but they only have $3M), the action card will automatically be appended into the player's bank. However, if the actions are valid (e.g. demanding $2M from opponent while they have $3M), the action card cannot be put into bank; the card will be played.

#### 3. Rearrange
Players are not allowed to rearrange the property by themselves.

------------
### How to Start
Simply enter "main main" and then "./main" in the project directory. Required inputs at different stages are clearly stated by screen output. 

------------
### Sample i/o Files
You may use the given game file to start the game. It allows you to start at the middle of the game rather than starting it all. To use this file, after executing the main program, you should choose to "load data" from "file 1". 
