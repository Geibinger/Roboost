/**
 * @file simple_motor_controller.hpp
 * @author Jakob Friedl (friedl.jak@gmail.com)
 * @brief Implementation of MotorController, which sets the control output
 * directy to the motor driver without feedback loop.
 * @version 0.1
 * @date 2023-07-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "motor-control/simple_motor_controller.hpp"
#include <Arduino.h>
#include <algorithm>

SimpleMotorController::SimpleMotorController(MotorDriver& motor_driver,
                                             float max_rotation_speed)
    : MotorController(motor_driver), max_rotation_speed_(max_rotation_speed)
{
}

// TODO: change behavior and function of desired_rotation_speed
//? desired_rotation_speed is now a value between -1 and 1, which does not make
//? sense
void SimpleMotorController::set_rotation_speed(float desired_rotation_speed)
{
    desired_rotation_speed = std::clamp(
        desired_rotation_speed, -max_rotation_speed_, max_rotation_speed_);

    float control_value = desired_rotation_speed / max_rotation_speed_;

    motor_driver_.set_motor_control(control_value);
}
