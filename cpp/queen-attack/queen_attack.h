#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H

#include <utility>
#include <stdexcept>
#include <string>

namespace queen_attack{
    class chess_board{
        private:
            std::pair<int, int> white_queen;
            std::pair<int, int> black_queen;

        public:
            chess_board(): white_queen{std::make_pair(0, 3)}, 
                           black_queen{std::make_pair(7, 3)} {}
            chess_board(std::pair<int, int> white, std::pair<int, int> black):
                white_queen{white},
                black_queen{black} {
                if (white_queen == black_queen)
                    throw std::domain_error("Queen in the same position");
            }
            std::pair<int, int> white() const { return white_queen; }
            std::pair<int, int> black() const { return black_queen; }
            operator std::string() const; 
            bool can_attack() const;
    };
}

#endif /* !QUEEN_ATTACK_H */

