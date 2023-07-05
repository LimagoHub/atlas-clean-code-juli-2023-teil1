//
// Created by JoachimWagner on 30.06.2023.
//

#pragma once

namespace atlas::generators {
    template<class T>
    class generator {
    public:
        [[nodiscard ]] virtual auto next() -> T = 0;
    };
}
