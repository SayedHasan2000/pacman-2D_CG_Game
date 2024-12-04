The game involves a character controlled by the player
navigating through a maze-like environment to collect food items
while avoiding obstacles. Here's a breakdown of the code:

The program defines several boolean variables (rightface,
upface, downface, leftface, point1, repoint) and integer variables
(uer, usr, ueu, usu, uel, usl, ued, usd, x, px, py, y, x2, y2, score, flag) to
keep track of game state, player position, and other relevant
information.

The Map array represents the maze-like environment where the
game takes place. It is a 2D array of integers, where 0 represents
obstacles and 1 represents empty spaces.

The myInit() function sets up the OpenGL environment by
specifying the projection matrix and background color.

The circle, circleup, circleleft, and circledown functions draw
circular shapes using OpenGL. These functions are used to render
the player character facing different directions.

The circle2 and circle3 functions draw differently colored circles
used to represent food items and other elements in the game.
The dis() function calculates the distance between two points
using the distance formula.

The keyboardFunc() function is an event handler that handles
keyboard input. It checks the input key and updates the player's
position based on the key pressed, while also checking for collisions
with obstacles.
