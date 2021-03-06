

[comment]: # (ifndef SRC_MAINPAGE_H_)
[comment]: # (define SRC_MAINPAGE_H_)
\mainpage My Bus Simulator

# User Guide
## Introduction
The purpose of this project was to create a simulation for the buses and their
routes on campus. There are many components to the entire simulator, such  as
Routes, Stops, Buses, and Passengers. Altogether, they will represent passengers
that get on a bus at a certain stop, where the bus will bring them to their desired
stop on a specific route.

To begin, it is important to ensure that the user is working on a CSE Lab machine.
What this means is that the user needs to access a computer that is designated as
one of the University of Minnesota's computer lab that belongs to the College of
Science and Engineering (CSE). These computers are special because they are Linux
machines. Just like other computers use Windows or MacOS, Linux is another type
of an operating system. Using these computers ensures that all the proper files and
libraries that the compiler (which creates the programs) uses are already installed.

If access to one of these machines is not available, the user can remotely access
the school's computers using a Virtual Online Linux Environment (VOLE) through
the University of Minnesota through this [link] (https://vole.cse.umn.edu/#page-top "VOLE").
To get access to VOLE, contact the CSE-IT Department [here] (https://cseit.umn.edu/ "CSE-IT")
to know how to get login access VOLE. The user can also request access to the
computers through the CSE-IT Department as well.

Once access to either a CSE Lab Machine or VOLE is achieved, the user should then
download a copy of the project file. This can be done by going to GitHub and
essentially cloning a copy of the entire project onto the current device. To do
so, follow these steps.
1. Search through applications and find the **Terminal**. Open the terminal, which
is a window that allows you to type commands.
2. In the terminal, you can type things into the **command line**. This is the
space that allows you to type specific commands that the computer can process. To
begin, type
```
git clone https://github.umn.edu/umn-csci-3081-f19/repo-xuxx1130.git
```
This will create a folder called "umn-csci-3081-f19" that will have another folder
called "repo-xuxx1130", which will have all the contents for the user to be able
to run the programs.

Once the folder is downloaded, the user can navigate the program using the
**terminal**. There are many different commands that can be typed into the **terminal**
that can access different folders and files. To begin accessing this project,
type these commands into the **terminal** and hit enter after each line.
```
cd umn-csci-3081-f19
```
**cd** is a command that changes the current directory to whatever is typed after.
In this case, it will change the current directory to "umn-csci-3081-f19".
Then, type this command into the terminal
```
cd repo-xuxx1130
```
and then
```
cd project
```
This will bring you to the project folder that contains all the files that is used
to create the visualization and the bus simulator. You can enter the command
```
ls
```
in the command line to see what the current directory contains and use **cd** to
navigate through the different folders. To go to the previous folder, you can type
```
cd ..
```
to go into the parent directory (basically go back to the previous directory).

Now that the project folder is set up and access to all the files of the
simulator are available, the user can begin the execution of the different
programs in this project.

## Explanation of System
There are three main programs that this project can create and run. They are
1. Transit Simulation:
This program will essentially run the entire simulation and print the output into
a text file that will have information of the simulation as it ran.
2. Visualization Simulation:
This program will run the entire simulation and create visualizer through a link
that will allow the user to visualize the simulation as it runs.
3. Configuration Simulation:
This program will allow the user to create their own files that can set up a
variety of routes and stops that can be reused and slightly modified.

### Transit Simulation
This is the basic simulator that can be run. This program will run the same as
the other two programs but will print all of the output into a .txt file that will
have all of the information of the simulator printed out throughout the program
when it is running. This is useful because it contains data on the passengers and
the different buses and specific information on these components during each time
step of the execution of the program. For the passenger, it will have information
on how long each passenger at each stop and on each bus has waited on the bus or
stop. For the bus, it will have information on when a bus reaches a stop and
how many passengers each bus contains.

To compile or create the program, there are a few steps to follow that will
allow the computer to create the "executable" - essentially, the  program will
be created based off the code of the different files in the project folder. To
create the program that will print all the information into a text file, follow
these steps.
1. Navigate to the project directory by typing this into the **command line**.
To see what your current directory is, type
```
pwd
```
into the terminal to "print working directory". If it shows
```
umn-csci-3081-f19/repo-xuxx1130/project
```
then you are in the correct folder. Other type
```
cd umn-csci-3081-f19/repo-xuxx1130/project
```
to navigate to the correct directory.
2. Next, the goal is to tell the computer to create the program file by looking
at all the code in the src directory inside the project folder. To do this, type
```
make
```
which will essentially create all of the programs that are needed to run
the different simulations. After this completes successfully, you can navigate by
typing into the terminal
```
cd build/bin
```
to see all of the **executables** that the computer has created. There will be
three items inside the bin directory: capture_transit_sim*, vis_sim*, and config_sim*.
The one important for the basic transit simulator is the capture_transit_sim* file.
3. To run this program, you will type
```
./capture_transit_sim filename.txt
```
The ** filename** portion can be replaced with any name that the user desires;
this will be the name of the file where all of the output will be printed to. If
you want to name the output file as **output.txt** simply type
```
./capture_transit_sim output.txt
```
You will see a bunch of data being printed out into the same terminal as program
is running. Once it is finished, you can see the output in the same directory, in
the **bin** directory. When you type **ls** into the terminal to see all of the
contents inside the **bin** directory, you will now see a file called **output.txt**.

This program is now complete and now you have ran the simulation. You can access
the results of this program with the .txt file that you have named and created
and use that information.

### Visualization Simulation
This simulator will create a program that essentially runs the same as the
Transit Simulation, except now, you are able to visualize the simulation as it
is running.
1. To begin, follow steps 1-2 from the **Transit Simulation** section above.
This time, the important program to look at is the **vis_sim** file that is created.
To run this program, follow these next steps after steps 1 and 2 from the
**Transit Simulation** are complete.
2. For this program, you need to run it from a different working directory. To
do this, type into the terminal
```
cd ../..
```
This will bring you back to the **project** folder, which is where you need to be
to be able to run the visualizer.
3. Once you are in the correct directory, you will need to pick a number that is
greater than 8000 and not a multiple of 10. This number will be the number that
will help establish a connection to a web page. Next, type into the terminal
```
./build/bin/vis_sim port_number
```
where you substitute the number you chose for the **port_number** portion.
You will see the computer print to the terminal:
```
Usage: ./build/bin/ExampleServer 8011
Using default config file: config.txt
starting server...
```
This means that the program is waiting for you to open a connection on the web.
4. Open a Web Browser from the applications of the computer, like Google Chrome.
In the URL space, type the following into the URL bar:
```
http://127.0.0.1:port_number/web_graphics/project.html
```
where you substitute the port_number portion of the link with the same number that
you put into the terminal. This will then establish the connection between the
program and the web. You will then be able to visualize the simulation.
. On the left side of the web page, there is the section **Sim Info** which
contains two sliders where you can change the corresponding settings, such as
the number of time steps you want to run the simulation, and how long between
each bus you want the visualization to create a new bus. You can adjust those
settings as you like.
6. Once the settings for the Sim Info are adjusted, you can run the visualizer
by clicking **Start**. You will then see a route on the simulator with different
numbered stops and start to see red buses moving along the route and stopping at
stops. You can hover over the visualization to get information about each component;
for example, you can hover over the stop with your mouse cursor to get information
on how many passengers are at the stop and same thing for the buses.
7. Once the buses stop moving after the designated amount of time steps have passed,
you can exit out of the visualizer by going back to the same terminal window and
typing into the command line the keys **Ctrl-C** together. This will cause the
visualizer to stop running.

This program is now complete and you have successfully ran the visualizer for the
simulation. To see the visualization again, you can follow steps 1-7 again.

### Configuration Simulation
This simulator will run the same as the basic transit simulator, except you can
pass in different "configuration files", which are files where you can set up a
variety of route and stop configurations.

To access the config files, you can begin by starting from the project directory
and then type into the terminal
```
cd config
```
then type into the terminal
```
ls
```
to see the config files.

There is a default config file that is already there, called **config.txt** and
you can open it with a text editor to see the contents of this file. It will have
different labels, such as ROUTE and STOP, followed by names of certain aspect of
each component.  

Follow these steps to run the Configuration Simulator and to create new config
files if desired.
1. To create new configuration files, you can essentially create a new file in a
text editor such as the application Atom, and name it anything besides "config.txt"
to create a different configuration of routes and stops. Make sure to name it
ending with **.txt** ensure that a text file is created. You can copy the contents
of **config.txt** into the new file and change elements like the names of the stops,
the coordinates for the stops, and more, as long as it follows the same format
as the **config.txt** file. Save the file and go back to the terminal window.
2. To create the configuration simulator program, follow steps 1-2 in the
**Transit Simulation** section. This will create all the programs but the one
important one for the configuration simuatlion is the **config_sim** file.
3. Type into the terminal:
```
./build/bin/config_sim conifguration_file
```
where the **configuration_file** portion of the command is the name of the config
file you want to use. If you didn't create any new configuration files, you will
use the default and this is done so by typing into the terminal:
```
./build/bin/config_sim config.txt
```
This will run the configuration simulation and all of the information will be
printed to the terminal as it runs.
The purpose of the configuration simulation is to enable you to manipulate the
stop and route data for the simulation that you want to run. This is useful if
you want to run the simulation program with more stops and/or a different route
or or testing out the simulation with different stops and route data.

## Conclusion
You have successfully created and ran the three different programs that enable you
to run the simulation of the transit simulation. This is especially useful if you
want to visualize how the buses at the University of Minnesota function. You can
use the configuration simulator to potentially change the current transit system
on campus and see how the outcome is through the information printed out to the
terminal.

# Developer Guide
## Introduction
This project was meant simulate the campus Buses. There are many components
to the entire simulator, like the classes of Route, Stops, Buses, and classes.
My implementation of the project is that there is a Route that a specific Bus
takes. It has a list of Stops going in one direction (the outgoing) and
another Route coming back (incoming). These Route may not have the same Stops
as one another. A Passenger will get generated when the Route updates. They
will get generated at a random Stop, with a unique destination id.

The first bus will be placed at the first Stop and determine if there are
any Passengers that need to get on; if yes, then those Passengers at that
Stop will load onto the Bus. If not, no Passengers will get on and the Bus
will head to the next Stop and update the distance to the next Stop as well
as the pointer to the next Stop.

Every time a Bus is updated, it will either a.) move if the Bus is not at a Stop
or b.) unload/load and readjust the pointers of the Bus for the next Stop.

There are lots of checks during update that check whether the Bus is
1. at the end of the trip
2. at the end of the outgoing Route or
3. at a Stop.

These checks are established through boolean methods and variables that get accessed,
updated, and set throughout the execution of the code as Update() is called.

If the Bus is at a Stop, it will first unload any Passengers that need to get
off, then load any Passenger that needs to get on, then in my design implementation
I would adjust the member variables of the current Stop to the next Stop and
adjust the distance remaining to the distance to the next Stop.

If the Bus is at the last Stop of the outgoing Route, it will call the Bus to
call a method to change direction that would readjust the current Stop to the
first Stop of the incoming Route; in the next Bus update, it will then unload
and load any Passengers at the first Stop of the incoming Route and readjust
as well.

Going into more detail about the unloading and loading of Passengers, the Bus
is the class that calls them and interacts with the Stop class. If the Bus has
Passengers that need to get off, it will simply delete that Passenger from its
list of Passengers. If any Passengers need to get on the Bus at the current
Stop, it will then check to see if the Bus is not at capacity, then add the
Passengers to the end of the Bus' Passenger list.

If the Bus is at the last Stop of the incoming Route, it will simply mean that
the trip is complete and it'll adjust the speed of the Bus to 0 and the
distance remaining to a high number so that the bus can essentially be deleted.

## Description of System
For a more in-depth guide on how to compile and execute the 3 programs, refer
to the User Guide for more information.

Essentially, there are three execuatables that can be created when **make**
is typed to the terminal from the project/ directory. If the developer wants to
create the vis_sim and config_sim separately, you can do so by **cd** into the
src/ directory and typing
```
make <simulator>
```
where the <simulator> is the target for either vis_sim or config_sim that is defined
in the Makefile. You can execute these programs from the project/ directory
following the same steps as defined in the user guide.

## Reconfigure The System
To change and add any new configuration files can allow you to add or change the
information of the Routes and Stops that the simulator uses. You can create a new
config file by adding a new .txt file into the config/ directory. To create a file
with different Route and Stop information, you can follow the same format as the
default config file called **config.txt** which has the default information for
configuration simulation to run. Make sure to save any new configuration files
as .txt files and to execute the config_sim by typing
```
./build/bin/config_sim new_file.txt
```
from the porject/ directory in the terminal and where new_file can be replaced
with whatever name you choose for the new file.

## Creating Variant of System
Throughout the project, it is possible to create variant of systems that are already
in the project. For example, the original developer wanted to create a variant of
the local_simulator.cc and local_simulator.h called **capture_local_simulator.cc**
with the corresponding header file in the src/ directory. To do so, make sure to
include the derived function in the **include** statements in the derived class.
Make sure that any functions that you would like to be override or overloaded are
defined and declared in the .cc and header files, respectively.

## Conclusion
The purpose of this simulation is to allow a user to run a simulation of the
buses that are present at the UMN. Any changes or variants can be done, but it
is important to follow  the Developer Guide to ensure that it can still working
prpoerly after any changes. Make sure to always **make clean** from the project/
directory to ensure that all object files and executables created from previous
**make** commands are removed and does not interfere with any new changes.

[comment]: # (endif  // SRC_MAINPAGE_H_)
