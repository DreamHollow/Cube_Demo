# Cube Demo

BRANCHES
----

There is only one branch, the master branch.
This project may get infrequently updated but is mostly promised in it's as-is form.

IMPORTANT NOTICE
----

The terms for the SFML library and this project differ.
*SFML 2.5.1 is licensed under the zlib license and the copyright belongs to Laurent Gomilla.*

HOW IT WORKS
----

This program isn't incredibly complicated.
This is a low-res rendering demonstration using polygonal shapes to render a 3D cube.

You will need SFML 2.5.1 or later for this program to work; though I cannot guarantee that it works with newer versions of SFML as some classes and operations have changed.

Because this program uses SFML's interface with a user's actual graphics card, it should work universally.

DOCUMENTATION
----

Everything you should need to understand this project is in the code itself.

BUILDING (Linux)
----

Building with Linux is incredibly easy.
As long as you have SFML installed to your computer proper, you should be able to run the
`./build` command and allow the system to create a working version of the program there.

Then it's as easy as using the `./run` command to start the execution.

BUILDING (Windows)
----

What you'll need to do is make sure your compiler is linked up with SFML properly and make sure that the 'Cube Demo' program is able to find your SFML library so that it compiles.

This can be a bit more complicated with Visual Studio.

If you're having trouble compiling this program with any version of Visual Studio, feel free to physically copy the entire SFML folder to the 'Cube_Demo' directory and try linkiing everything up that way. It usually works much better that way, for whatever reason.

Please let the developers know if you encounter any serious bugs on the Windows version.