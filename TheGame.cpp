 #include "TheGame.h"

TheGame::TheGame()
{
    initGame();
    ghosts[0] = new Ghost(39, 12);
    ghosts[1] = new Ghost(40, 12);
}

void TheGame::start()
{
    Utilities::clearInputBuffer();

    bool winner = false;
    int time = 0;
    bool pause_game = false;
    system("cls");
    board.print(pacman.getLives(), pacman.getPoints());
    
    while (pacman.getLives() > 0)
    {
        int curr_lives = pacman.getLives();
        pause_game = movePacman();
        if (curr_lives != pacman.getLives())
        {
            if (isLooser())
                break;
            startAfterDeath();
        }

        if (pause_game)
        {
            pauseGame();
            pause_game = false;
        }

        if (time % 2 == 0)
        {
            curr_lives = pacman.getLives();
            moveGhosts(time);
            if (curr_lives != pacman.getLives())
            {
                Utilities::updateInfoLine(0, pacman.getLives());
                if (isLooser())
                    break;
                startAfterDeath();
            }
        }
        time++;

        if (isWinner())
        {
            winner = true;
            break;
        }
        else if (isLooser())
        {
            break;
        }

        Sleep(30);
    }

    system("cls");

    if (winner)
    {
        cout << "you win!";
    }
    else
    {
        cout << "GameOver, you lost!";
    }

    cout  << endl << "Press ESC to return to the menu";
    Utilities::waitForESC();
    showMenu();
}

void TheGame::startAfterDeath()
{
    board.set(pacman.getPlace(), Utilities::SPACE_SIGN);
    pacman.initPlace();
    board.set(pacman.getPlace(), Utilities::PAC_SIGN);

    bool wasPac = false;
    int start_x_ghost1 = 39;

    for (Ghost* ghost : ghosts)
    {
        if (ghost->getOnDot())
            board.set(ghost->getPlace(), Utilities::DOT_SIGN);
        else
            board.set(ghost->getPlace(), Utilities::SPACE_SIGN);

        ghost->setPlace(Point(start_x_ghost1++, 12), board, wasPac);

        board.set(ghost->getPlace(), Utilities::GHOST_SIGN);
    }
}

void TheGame::startAnotherTime()
{
    pacman.init();

    startAfterDeath();

    initGame();

    board = original_board;
    start();
}

void TheGame::pauseGame()
{
    system("cls");

    std::cout << "Game paused, press ESC again to continue" << std::endl;

    Utilities::clearInputBuffer();

    Utilities::waitForESC();

    std::cout << "Resuming game..." << std::endl;

    Sleep(450);

    system("cls");

    board.print(pacman.getLives(), pacman.getPoints());
}

bool TheGame::movePacman()
{
    bool wasDot = false, wasGhost = false, pause = false;

    board.set(pacman.getPlace(), Utilities::SPACE_SIGN);
    pause = pacman.move(board, wasDot, wasGhost);
    board.set(pacman.getPlace(), Utilities::GHOST_SIGN);

    if (wasDot)
        breadcrums--;

    return pause;
}

void TheGame::moveGhosts(int time)
{
    bool wasPac = false;

    for (Ghost* ghost : ghosts)
    {
        if (ghost->getOnDot())
            board.set(ghost->getPlace(), Utilities::DOT_SIGN);
        else
            board.set(ghost->getPlace(), Utilities::SPACE_SIGN);

        ghost->move(pacman.getPlace(), board, time, wasPac);

        board.set(ghost->getPlace(), Utilities::GHOST_SIGN);

        if (wasPac)
        {
            pacman.getEaten();
        }
        wasPac = false;
    }
}

void TheGame::instructions()
{
    system("cls");

    cout << "1. Press Keys to move the pac-man." << endl <<
        "2. Eat the dots to gain points." << endl <<
        "3. Don't get caught by the ghosts." << endl;

    cout << endl;

    cout << "Keys:" << endl <<
        "Left = A or a, " << "Right = D or d, " << "UP = W or w, " << "Down = X or x, " << "Stay = S or s" << endl;

    cout << endl << endl << "Press ESC to return to the menu" << endl;

    Utilities::waitForESC();
    showMenu();
}

void TheGame::exitGame() const
{
    exit(0);
}

void TheGame::showMenu()
{
    system("cls");
    Utilities::hideCursor();


    cout << "1 for Start a new game." << endl << "8 for Present instructionsand keys." << endl << "9 for EXIT." << endl;
    int choice;

    cin >> choice;
    while (choice != 1 && choice != 8 && choice != 9)
    {
        cout << "Invalid choice! Try again." << endl;
        cin >> choice;
    }

    switch (choice)
    {
    case 1:
        startAnotherTime();
        start();
        break;
    case 8:
        instructions();
        break;
    case 9:
        exit(0);
        break;
    }
}

bool TheGame::isWinner() const
{
    return (breadcrums == 0);
}

bool TheGame::isLooser() const
{
    return (pacman.getLives() == 0);
}

void TheGame::initGame()
{
    breadcrums = 0;

    for (int i = 0; i < Utilities::HEIGHT_OF_BOARD * Utilities::WIDTH_OF_BOARD; i++)
    {
        if ((original_board.getBoard())[i] == '.')
        {
            breadcrums++;
        }
    }
}

TheGame::~TheGame()
{
    for (int i = 0; i < NOG; i++)
    {
        delete ghosts[i];
    }
    
}