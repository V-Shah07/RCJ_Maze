#include "Direction.hpp"

Instruction dirDiff(Direction from, Direction to) {
    // difference between from and to
    int diff = (from - to);
    if (diff < 0) {
        diff += 4;
    }
    
    // Up:    0
    // Left:  1
    // Down:  2
    // Right: 3
    
    // (left turn) Right - Up = 3 
    // (left turn) Left - Down = -1 + 4 = 3
    // etc...
    switch (diff) {
    case 0: return Forward;
    case 1: return TurnRight;
    case 2: return Turn180;
    case 3: return TurnLeft;
    }
}

Direction dirTurn(Instruction instruction, Direction dir) {
    int d = dir;
    
    switch (instruction) {
    case Forward: break;
    case TurnLeft: d += 1; break;
    case TurnRight: d -= 1; break;
    case Turn180: d -= 2; break;
    }
    
    // keep d within the range 0..=3
    if (d > 3) {
        d -= 4;
    }
    if (d < 0) {
        d += 4;
    }
    
    return (Direction)d;
}

vector<Instruction> convertToInstruction(vector<Direction> directions, Direction heading) {
    vector<Instruction> out;
    
    // get the difference from our heading to the first direction
    out.push_back(dirDiff(heading, directions[0]));
    
    // get the difference between every direction after that
    for (int i = 1; i < directions.size(); i++) {
        Instruction instruction = dirDiff(directions[i - 1], directions[i]);
        out.push_back(instruction);
    }
    
    return out;
}