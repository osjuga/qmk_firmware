#pragma once 

#define QWERTY DF(_QWERTY)
#define GAME DF(_GAME)

#define LAYER1 MO(_LAYER1)
#define LAYER2 MO(_LAYER2)

#define LAYESC1 LT(_LAYER1, KC_ESC)

enum osjuga_keycodes {
    GGWP = SAFE_RANGE,
    RAYEBAN,
    SELFFLSH,
    NEW_SAFE_RANGE,
};

enum osjuga_layers {
    _QWERTY = 0,
    _GAME,
    _LAYER1,
    _LAYER2,
};
