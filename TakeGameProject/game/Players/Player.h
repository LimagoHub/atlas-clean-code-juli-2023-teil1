//
// Created by JoachimWagner on 04.07.2023.
//

#pragma once


#include <string>
template<class BOARD, class MOVE>
class Player {
public:
    virtual std::string getName() const = 0;
    virtual MOVE requestMove(const BOARD &board) const = 0;
};
