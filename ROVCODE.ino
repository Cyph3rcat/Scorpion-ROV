


components: 
// COMPONENTS
// Thrusters: Back Left (D5), Back Right (D6), Pitch (D3)
// Servo (controls angle of back thrusters) → D9
// Joysticks: 
//   Left → (SW: D7, Y: A1, X: A2)
//   Right → (SW: D8, Y: A4, X: A5)

SETUP:
    Initialize digital output pins: D5, D6, D3, D9
    Initialize analog input pins: A0–A5
    Variables:
        thrusterSpeed = 0S
        servoAngle = 90  // default horizontal
    Set servo angle to horizontal (90°)

LOOP:
    // --- READ INPUTS ---
    leftX  = readAnalog(A2)  // left joystick X axis
    leftY  = readAnalog(A1)  // left joystick Y axis
    leftClick = readDigital(D7)

    rightX = readAnalog(A5)  // right joystick X axis
    rightY = readAnalog(A4)  // right joystick Y axis
    rightClick = readDigital(D8)

    // --- CONTROL LOGIC ---

    // LEFT JOYSTICK = main drive (back thrusters)
    if (leftX < thresholdLeft):
        set servoAngle = 90 (horizontal)
        motor(D5, forward, speed based on |leftX|) //modulus operator tSo measure magnitude while ignoring polarity
        motor(D6, backward, speed based on |leftX|)

    else if (leftX > thresholdRight):
        set servoAngle = 90
        motor(D5, backward, speed based on |leftX|)
        motor(D6, forward, speed based on |leftX|)

    if (leftY > thresholdUp):
        set servoAngle = 90
        motor(D5, forward, speed based on |leftY|)
        motor(D6, forward, speed based on |leftY|)

    else if (leftY < thresholdDown):
        set servoAngle = 90
        motor(D5, backward, speed based on |leftY|)
        motor(D6, backward, speed based on |leftY|)

    if (leftClick == pressed):
        set servoAngle = 0 (vertical)
        motor(D3, backward, constant speed)
        motor(D5, backward, constant speed)
        motor(D6, backward, constant speed)

    // RIGHT JOYSTICK = pitch thruster
    if (rightY > thresholdUp):
        motor(D3, forward, speed based on |rightY|)

    else if (rightY < thresholdDown):
        motor(D3, backward, speed based on |rightY|)

    if (rightClick == pressed):
        set servoAngle = 0 (vertical)
        motor(D3, forward, constant speed)
        motor(D5, forward, constant speed)
        motor(D6, forward, constant speed)

END LOOP