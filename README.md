# mbot
MBot Code

# Dev Environment
I use code blocks build a test harness that I can develop programs in and run easily from the mBlock IDE. 

Checkout demo video at: https://www.youtube.com/watch?v=Z7oJCq3xNSM

## Overview
This project provides a simple development harness for building mBot programs.
1. The harness starts up up with a distinctive tone and *flashing green lights* to let the user know it is ready to run.
2. Once the user pushes and releases the button the mBot, the *lights go blue* and the user's code is run
3. Once the user's code completes, the *lights go red*, all the motors are shutdown and a different distinctive tone is played.

Additionally, the user can debug and test his program in the mBlock IDE. In addition to the lights and sounds, the user will be able to monitor a variable called `state`. These different ways of giving the user feedback can help speed up development, diagnosis and debugging.

![alt text](https://github.com/jacbop/mbot/raw/master/src/common/images/20160217.code.png "Example Code")

The source for this test harness is under `src/scratch/botOS.sb2`

## Entry points
These are the two ways to launch the program you write:
* `when (green flag) clicked` - this is what I call dev mode. It lets me run the user program while still connected to the USB
* `mBot Program` - this is the code that will be uploaded to Arduino and run on the mBot

Note mBot programs can only use a subset of scratch commands. Things like `Motion` and `Looks` and `Pen` are just for desktop Scratch programs designed to run on your computer. It makes no sense, for example, to make the Panda say something in or move him across the screen when the program is meant to run on the mBot (which has no keyboard, no screen).

You can write hybrid programs, for instance, steering the mBot with arrows in the keyboard. But you will only be able to run in dev mode with a USB cable or Bluetooth connection. You will not be able to send these programs to Arduino and have them run independently on the mBot.

## Main Program
This code block gives the user feedback as it works through several steps to run the users program. Think of it as the worlds simplest operating system. The main program can be launched either in dev mode as an mBot program. There is a variable `state` that you can monitor in the staging area when running in dev mode. This will tell you where your program is at that moment. The values of `state` are:
0. started
1. intro routine started. Distinctive tone played and lights are flashing green. Waiting for the user to push the button on the mBot
2. user has pushed button on the mBot, but not released it yet. Light is a solid green.
3. user has released the button and the user program is being invoked. Light is solid blue.
4. user program has ended, running exit routine. Light is solid red. Motors have been stopped. Distinctive toned played.
5. main program has exited. Will need to hit reset on mBot to rerun.

## User Program
The user code goes here. It will be invoked as described above. It is important to only use the subset of Scratch together with the `Robots` library since the user program must run in dev mode as well as an mBot program.

The simplest user programs might have no loops, but rather using the block `wait n secs` command. For instance the program might make the robot drive forward at speed 100 for 5 seconds and then stop.

```
run forward at speed 100
wait 5 secs
run forward at speed 0
```

# Troubleshooting

## serial port connected?
Double check that the USB cable is plugged in and the serial port connected again before trying to run something in dev mode or upload an update to arduino. The head in the GUI should tell you if you are connected or not.

## bluetooth problems?
You cannot connect via bluetooth to run stuff in dev mode, but to reset the default program or upload your updated code, it seems you must use the USB cable.

## reset default program?
If you have uploaded your own software to arduino then you will need to `Reset Default Program` from the `Connect` menu.
You can not run in dev mode without doing this first. This can be very confusing the bot may appear to be running your latest program updates, but it is actually running that last version to uploaded to arduino. You most recent changes are not running and the bot is not responding to the green flag button in the IDE.
Also the IR remote will not work without the default program.

## is program still running?
Do you have a program that is still running on the bot? Perhaps you are in a loop and the bot is not responding. Hit the reset button on the bot to start your program over. Or reset the default program.

## is program done running?
Are you expecting the bot to respond but it is not; for instance not responding to a button press? Hit the reset button on the bot to make sure the your program is running from the beginning. Once the program finishes from one run, you must do this to run a second time.

## reboot needed?
If you just can't get the serial port working after power cycling the bot and swapping out your UBS cable, reboot your machine and then consider reinstalling the Arduino driver.
