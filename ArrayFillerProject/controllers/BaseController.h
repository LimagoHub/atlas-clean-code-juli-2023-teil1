//
// Created by JoachimWagner on 05.07.2023.
//

#pragma once

namespace atlas::controllers {

    class BaseController {
    public:
        virtual auto run() -> void = 0;
    };
}
