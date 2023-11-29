#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <vector>
#include <memory>
#include <string>
#include "player.h"
#include "link.h"
#include "abilitycard.h"
#include "coords.h"
#include "edgecoord.h"
#include "serverport.h"
#include "abilitycards/firewall.h"
#include "textdisplay.h"
using namespace std;
class TextDisplay; 
class GameBoard {
    unique_ptr<TextDisplay> td;
    vector<Player> players;
    vector<unique_ptr<Link>> allBoardPieces;
    vector<unique_ptr<AbilityCard>> allAbilityCards;
    unique_ptr<Player> currPlayer;
    unique_ptr<Player>  winner;
    vector<Coords> boardBoundaries;
    vector<EdgeCoord> edgeCoords;
    vector<ServerPort> serverPorts;
    vector<FireWall> activeFirewalls;
    public:
    ~GameBoard();
    GameBoard();
    void init();
    void applyAbility(AbilityCard& ac, Player *player = nullptr);
    void movePiece(Link &link, Direction dir);
    void battlePieces(Link &linkp1, Link &linkp2);
    void startNewTurn();
    void downloadIdentity(Link &link1, Player *player);
    void updateIdentity(Link& link);
    Player& getWinner();
    string getAbilities(Player&); // maybe this shold return the vector of ability cards... 
    vector<Player>& getPlayers();
    vector<Link>& getAllBoardPieces();
    vector<AbilityCard>& getAllAbilityCards();
    Player& getCurrPlayer();
    vector<Coords>& getBoardBoundaries();
    vector<EdgeCoord>& getEdgeCoords();
    vector<ServerPort>& getServerPort();
    vector<FireWall>& getActiveFirewalls();
    friend std::ostream &operator<<(std::ostream &out, const GameBoard &gd);
};
#endif