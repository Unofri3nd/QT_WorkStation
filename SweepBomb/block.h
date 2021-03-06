//
// Created by djf on 2016/12/25 0025.
//

#ifndef SWEEPBOMB_BLOCK_H
#define SWEEPBOMB_BLOCK_H

#include <vector>
#include <random>
#include <time.h>

using namespace std;

enum State{
    UNDIGGED,
    DIGGED,
    REDFLAG
};

enum gameState{
    PLAYING,
    WIN,
    LOSE
};
struct unit{
    State curState;
    int bombNum;
    bool isBomb;
    unit():curState(UNDIGGED),bombNum(0),isBomb(false) {}
    ~unit() = default;
};

class block {
public:
    block(int theRow = 8,int theCol = 15,int theTotalBomb = 20);
    ~block() = default;
public:
    //method
    void draw() const;
    void dig(int theRow,int theCol);
    void mark(int theRow, int theCol);
    bool isBomb(int theRow,int theCol) const;
    int getRow() const;
    int getCol() const;
    int getBombNum() const;
    gameState checkGame();
    vector<vector<unit>> map;
private:

    int row;//行
    int col;//列数
    int totalBomb;
    int restNum;
    gameState curGameState;
private:
    void calBombNum();
    int calBombnum(int theRow,int theCol) const;
};


#endif //SWEEPBOMB_BLOCK_H
