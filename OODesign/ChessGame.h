/*************************
* @file ChessGame.h
*
* Copyright (c) 2016 NHQ.
*
* @brief
*   Design a chess game using object oriented principles
*************************/
#include <utility> //pair
#include <string>
#include <unordered_map>
#include <set>
#include <memory> //smart ptrs
#include <iostream>

typedef std::pair<int, int> PosType;
class Piece
{
public:
    Piece();
    ~Piece();
    virtual bool move(const PosType& rNewPos) = 0;
protected:
    std::pair<int, int> mPos;
    std::string mName;
};

class Pawn : public Piece
{
    Pawn();
    ~Pawn();
    virtual bool move(const PosType& rNewPos) override final
    {
        return true;
    }
};
class Knight : public Piece
{
    Knight();
    ~Knight();
    virtual bool move(const PosType& rNewPos) override final
    {
        return true;
    }
};
class Bishop : public Piece
{
    Bishop();
    ~Bishop();
    virtual bool move(const PosType& rNewPos) override final
    {
        return true;
    }
};

typedef std::shared_ptr<Piece> PiecePtr;

static std::set<std::string> gPieceName{
    "Pawn1", "Pawn2", "Pawn3",
    "Rook1", "Knight1", "Bishop1", "Queen", "King" };

class Player
{
public:
    Player(int id);
    ~Player();
    void Init();
    bool play(const std::string& rPieceName, const PosType& rNewPos);

private:
    int mId;
    std::unordered_map<std::string, PiecePtr> mSet;
};

class ChessManager
{
public:
    ChessManager():
        mWhite(new Player(0)),
        mBlack(new Player(1)),
        mStop(false),
        mToken(0)
    {
    }
    ~ChessManager();

    void run()
    {
        //switch turns between two players
        int row, col;
        std::string piece_name;
        std::shared_ptr<Player> cur_player;
        std::string cur_name;
        bool finish_turn = false;
        while (!mStop)
        {
            if (mToken == 0)
            {
                cur_player = mWhite;
                cur_name = "White";
            }
            else
            {
                cur_player = mBlack;
                cur_name = "Black";
            }
            finish_turn = false;
            while (!finish_turn)
            {
                std::cout << "Get " << cur_name << " Move:" << std::endl;
                std::cout << "Piece name: "; std::cin >> piece_name;
                std::cout << "Row: "; std::cin >> row;
                std::cout << "Col: "; std::cin >> col;

                //check validity of inputs:
                if ((row > 0) && (row<8) &&
                    (col > 0) && (col < 8) &&
                    (gPieceName.find(piece_name) != gPieceName.end()))
                {
                    finish_turn = cur_player->play(piece_name, std::make_pair(row, col));
                    if (!finish_turn)
                    {
                        std::cout << "Invalid move" << std::endl;
                    }
                }
                else
                {
                    std::cout << "Invalid inputs! Please retype" << std::endl;
                }
            }

            //check stop condition here: chessmate, out of time,.... 
            //If stops, mStop = true;
        }
    }
private:
    std::shared_ptr<Player> mWhite;
    std::shared_ptr<Player> mBlack;
    bool mStop;
    int mToken;
};