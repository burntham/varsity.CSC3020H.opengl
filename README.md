Daniel Burnham-King
Game Dev(CSC3022H) Assignment 2
Intro to openGL

Compilation:
	navigate to the folder in which the below mentioned .cpp files are stored (assuming that by you reading this, the tarball is already extracted). Typing make will compile and run the program, or make all (which will just compile the program into an executable called openTest. Also note, typing make run will just run the program (no compiling)

Execution: 
	This program is intended to be executed directly or via the make file.

FileList:
	Driver.cpp, Makefile, Readme.txt

Controls/Interface:
	Interface:
		The global Axis (World axis) are drawn as Green (Y axis), Blue (Z axis) and Red (X axis).

		The Teapot has 2 straight lines popping out of it, the Pink line (which shows the axis to which it should rotate about (These are localised to the teapot)) and the Light Blue line (This shows the direction the teapot will translate - this is parallel to relavant the global axis), 

	Controls:
		Camera:
			Numpad 2,4,6,8 
			-> 
				(rotate camera in its orbit, 4 and 6 go left and right, 8 and 2 go up and downs)

			Numpad +,- 
			-> 
				Zoom in and out.

			Numpad 5 
			-> 
				Reset Camera Position/orientation

		Teapot:
			Space 
			-> 
				Switch axis of action (the lightBlue and Pink line as explaned in interface relay to the user which axis is currently selected).

			W,S 
			-> 
				Rotate about pink line with a positive/negative angle (respectively)

			A,D 
			->
				Translate in the negative/positive (relatively) direction (will be in either X,Y,Z global axis direction)

			R 
			->
				Reset the teapot to it's default position/orientation

Note/Problems:
	Due to limitations in the way rotations are handled (x then y then Z), The order the rotations are carried out by the user can affect things differently. To insure proper results, rotate by x, then y, then Z. Any further rotations not on the z axis may apply on some arbitrary axis. ( note, the afor mentioned axis are local to the teapot).

	By default rotations occur on the teapots x-axis.
