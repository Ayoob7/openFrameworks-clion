## CLion
Version: 2020.1

System: Linux pop-os 5.4.0-7626-generic

GCC Version: gcc (Ubuntu 9.3.0-10ubuntu2) 9.3.0

This template builds on the work done by https://github.com/ika-musuko.

## Dependencies
- install OpenFrameworks as mentioned in the guide https://openframeworks.cc/setup/linux-install/ 
- install Clion as mentioned in this guide https://www.jetbrains.com/help/clion/installation-guide.html#silent
- makefile support https://plugins.jetbrains.com/plugin/9333-makefile-support (you can  install this from the built in plugin manager in CLion settings)

## Renaming the project
!!! don't delete .project_name !!! <br/>
<code>./rename_project.sh your-project-name</code>

## Setup instructions 
this guide assumes you already know how to use CLion and have the above dependencies installed in CLion.
1. clone this
2. <code>rm -rf .git</code>
3. open CLion and **Import** the folder (don't just open). click "open existing project" in the subsequent popup
4. go to <code>CMakeLists.txt</code> and change <code>OF_DIRECTORY</code> argument to your openFrameworks root path under the <code>===================== oF Directory =====================</code> section
5. go to <code>Makefile</code> and change <code>OF_ROOT</code> to the absolute root path of openFrameworks
5. run the <code>oFDebug</code> build mode
    - the normal clion build mode via CMake will **not** work. use my oFDebug build mode which has gnumake build the project instead
6.  I have made 2 branches for each of the tasks. branch names are **task1 and task2**

## Existing OpenFrameworks project
follow the above steps and then replace everything in src/ with your files. modify the Source Files section of CMakeLists.txt accordingly. 

if you have addons, add them to:
  - addons.make
  - cmake/addons.cmake
    - just look at what i did for ofxGui and repeat the same thing in the # includes section. in the ##### section, add your other addons as extra arguments like i did to the set() calls.
