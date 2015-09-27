# qShowDesigner
qShowDesigner is a Qt based cross platform application for controlling and monitoring Elation Show Designer 2 lighting controller using the serial/com port.

The Elation Show Designer 2 is an "Intelligent" lighting controller for controlling up to 1024 DMX channels.  It features a serial port that allows access to control, monitor, back up, and program features of the controller.  Elation provides a few different utilities to access these features but the utilities are windows only (although they do work under wine) and the user interface didn't fit my specific needs. 

I wrote qShowDesigner to be cross platform utlity to allow viewing fixtures, viewing scenes, and selecting scenes. 

 - Compact UI to allow "always on top" functionality without getting in the way of other programs
 - Ability to view all fixtures and channels of each fixture
 - Ability to view and select page and scenes 

## Install
At the moment, binary packages are not available.  To install, you must build from source.

1. Install Qt 5 development packages or download and install from the qt.io website
2. Clone this repository
3. Run qmake to generate source and Makefile
4. Build with make
5. Run the binary with the command "./qShowDesigner"

## Using
Development is still a work in progress.  The only implemented features are

 - Change Page Number
 - Select Scenes 1 - 12

To use the current version:

 - Choose File->Connect and select the serial port connected to the Show Designer.  
 - Click buttons 1 - 12 to select the scene
 - Double click the label next to the button to edit it






