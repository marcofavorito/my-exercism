#include "queen_attack.h"


queen_attack::chess_board::operator std::string() const{
    std::string result = "";
    std::string line = "_ _ _ _ _ _ _ _\n";
    auto white = this->white();
    auto black = this->black();

    for (int i = 0; i < 8; i++){
        std::string current_line = line;
        if (white.first == i){
            current_line.replace(white.second * 2, 1, "W");
        }
        if (black.first == i){
            current_line.replace(black.second * 2, 1, "B");
        }
        result += current_line;
    }
    return result;
}

bool queen_attack::chess_board::can_attack() const{
    auto white = this->white();
    auto black = this->black();

    return white.first == black.first ||
           white.second == black.second ||
           white.first - white.second == black.first - black.second ||
           white.second - white.first == black.second - black.first ||
           (white.second == black.first && white.first == black.second);
}


