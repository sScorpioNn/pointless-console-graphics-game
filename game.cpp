/*
*   YO this is my first project on C++
*   Pointless Console Graphics Game by sScorpioNn (March 2023)
*/

#include <iostream>

using namespace std;

// Creating a game map
// 1 = wall, 0 = air
bool Map[] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1,
    1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

// Wall checker
bool isWall(int x, int y)
{
    return Map[(y - 1) * 32 + (x - 1)]; // Transforming coordinates
}

class Player
{
public:
    int x, y;

    // Move function with collision detection
    void Move(int xa, int ya)
    {
        if (!isWall(x + xa, y + ya))
        {
            x += xa;
            y += ya;
        }
    }
};

void control(Player& player, char key)
{
    switch (key)
    {
    case 'w':
        player.Move(0, -1); // Move up
        break;
    case 'a':
        player.Move(-1, 0); // Move left
        break;
    case 's':
        player.Move(0, 1);  // Move down
        break;
    case 'd':
        player.Move(1, 0);  // Move right
        break;
    default:
        break;
    }
}

void render(Player& player) // I think there's a better way to do it, but I'm bad at c++
{
    string frame;   // Text string that stores frame

    system("cls");  // Clearing the console

    // Loop that goes through all the values in the map
    for (int y = 0; y < 16; y++)
    {
        for (int x = 0; x < 32; x++)
        {
            // If player is on current coordinates add P to frame string
            if (player.x == x + 1 && player.y == y + 1)
            {
                frame.push_back('P');
                continue;   // Current block rendered, so skipping to the next
            }

            // If there's a wall on current coordinate add #, if there's no wall add space
            if (isWall(x + 1, y + 1)) {
                frame.push_back('#');
            }
            else {
                frame.push_back(' ');
            }
        }
        frame.push_back('\n');  // Line break
    }

    // Printing the frame
    cout << frame;
}

int main()
{
    // Creating player instance
    Player player;

    // Setting the player's starting coordinates
    player.x = 15;
    player.y = 9;

    // Game loop
    while (true) {
        render(player); // Rendering a frame

        char key;
        cin >> key; // Getting user input

        control(player, key); // Moving the player
    }

    return 0;
}