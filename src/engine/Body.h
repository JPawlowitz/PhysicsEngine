//
// Created by Jan Pawlowitz on 16.04.23.
//

import math;

#ifndef PHYSICSENGINE_BODY_H
#define PHYSICSENGINE_BODY_H

class Body {
protected:
    math::Vec2 m_position;
    math::Vec2 m_prev_position;
    math::Vec2 m_acceleration;
};


#endif //PHYSICSENGINE_BODY_H
