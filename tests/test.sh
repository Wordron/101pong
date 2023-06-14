#!/bin/bash

make
clear

echo -e "\033[92mSimple test :\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "The velocity vector of the ball is:"; echo "(-8.10, 6.00, -3.00)"; echo "At time t + 4, ball coordinates will be:"; echo "(-39.40, 33.00, -10.00)"; echo "The incidence angle is:"; echo "16.57 degrees"
echo -e "\033[31mGot :\033[00m"
./101pong 1.1 3 5 -7 9 2 4

echo
echo -e "\033[92mSimple test don't reach the paddle :\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "The velocity vector of the ball is:"; echo "(6.00, 6.00, -7.00)"; echo "At time t + 4, ball coordinates will be:"; echo "(31.00, 33.00, -30.00)"; echo "The ball won't reach the paddle"
echo -e "\033[31mGot :\033[00m"
./101pong 1 3 5 7 9 -2 4

echo
echo -e "\033[92mSimple test velocity vector null :\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "The velocity vector of the ball is:"; echo "(3.00, 3.00, 0.00)"; echo "At time t + 8, ball coordinates will be:"; echo "(28.00, 29.00, 3.00)"; echo "The ball won't reach the paddle"
echo -e "\033[31mGot :\033[00m"
./101pong 1 2 3 4 5 3 8

echo
echo -e "\033[92mSimple test angle 90.00 :\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "The velocity vector of the ball is:"; echo "(0.00, 0.00, -1.00)"; echo "At time t + 3, ball coordinates will be:"; echo "(1.00, 2.00, -1.00)"; echo "The incidence angle is:"; echo "90.00 degrees"
echo -e "\033[31mGot :\033[00m"
./101pong 1 2 3 1 2 2 3


echo
echo -e "\033[92mSimple test already pass the paddle :\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "The velocity vector of the ball is:"; echo "(2.00, 2.00, 6.00)"; echo "At time t + 6, ball coordinates will be:"; echo "(15.00, 16.00, 41.00)"; echo "The ball won't reach the paddle"
echo -e "\033[31mGot :\033[00m"
./101pong 3 4 3 1 8 -2 3


echo
echo -e "\033[92mSimple test failure char coordinates :\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "84"
echo -e "\033[31mGot :\033[00m"
./101pong 1 3 y 7 9 -2 4
echo $?

echo
echo -e "\033[92mSimple test failure string coordinates :\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "84"
echo -e "\033[31mGot :\033[00m"
./101pong 1 3 yp 7 9 -2 4
echo $?

echo
echo -e "\033[92mSimple test failure char time shift :\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "84"
echo -e "\033[31mGot :\033[00m"
./101pong 1 3 5 7 9 -2 p
echo $?

echo
echo -e "\033[92mSimple test failure string time shift :\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "84"
echo -e "\033[31mGot :\033[00m"
./101pong 1 3 5 7 9 -2 py
echo $?

echo
echo -e "\033[92mSimple test failure negative time shift :\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "84"
echo -e "\033[31mGot :\033[00m"
./101pong 1 3 5 7 9 -2 -4
echo $?

echo
echo -e "\033[92mSimple test failure float time shift :\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "84"
echo -e "\033[31mGot :\033[00m"
./101pong 1 3 5 7 9 -2 4.3
echo $?
