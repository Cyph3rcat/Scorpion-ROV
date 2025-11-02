# Scorpion-ROV

Scorpion-ROV is a small remotely operated vehicle (ROV) controller project that reads analog joystick inputs, maps them to PWM outputs for motors/ESCs, and applies transformations when the joystick's SW (switch) pin is detected.

## Features
- Read analog joystick axes (left and right sticks).
- Normalize and deadband joystick inputs.
- Map analog input ranges to PWM pulse widths (e.g., 1000–2000 µs) or duty cycles expected by ESCs/motor drivers.
- Detect joystick SW (switch) pin and apply transformations (invert axis, alternate control modes, output limiting, etc.).
- Simple wiring and configuration notes for common controllers and ESCs.

## How it works
1. Read analog values from joystick ADC pins for each axis.
2. Center and normalize readings (for example, scale to -1.0 … 1.0) and apply a deadband to avoid drift.
3. Convert normalized values to PWM pulse widths or duty cycles suitable for your motor controllers.
4. Monitor the SW (switch) pin on the joystick; when active, apply the configured transformation(s):
   - Invert axis
   - Switch to alternate mixing or control mode
   - Limit maximum output or enable an alternate mapping

## Wiring (example)
- Joystick A X axis -> MCU ADC pin (e.g., A0)
- Joystick A Y axis -> MCU ADC pin (e.g., A1)
- Joystick B X axis -> MCU ADC pin (e.g., A2)
- Joystick B Y axis -> MCU ADC pin (e.g., A3)
- Joystick SW (switch) -> MCU digital input with pull-up or pull-down resistor
- MCU PWM outputs -> ESC/motor driver signal pins
- Connect common ground between joystick, MCU, and ESCs

## Configuration tips
- Calibrate the joystick center and endpoints for each axis.
- Choose an appropriate deadband to prevent small analog noise from driving motors.
- Verify the PWM pulse range required by your ESCs (commonly 1000–2000 µs) and adjust mapping accordingly.
- Provide a configurable maximum output limit for safe testing.

## Safety
- Test with propellers/motors removed or disconnected when tuning controllers.
- Start with low maximum output values and increase gradually.
- Always ensure a solid common ground between all devices.
