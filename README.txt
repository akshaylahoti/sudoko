						   #Suduko#	
NAME-Akshay Lahoti	
MIS ID -111403065
						#Rules of game#
					
					1.Every row and coloumn should be filled with the numbers from 1 to 9 without repetition.
 					2.Every 3 * 3 grid should be filled with the number from 1 to 9 without repetition.

						#Description#
					
			1. The first screen comes with two option
				a)start game.
				b)end game.
			user can select any option as per his needs.
			
			2. second screen comes with three sub-options
				a)Easy.
				b)Medium.
				c)Hard.
			These are nothing but three difficulty levels which have being designed to test the user. 
			easy difficulty level has less number of blank spaces to be filled and only one correct number can be inserted in 
			the blank space.However in the hard difficulty level more number of blank spaces are present and more than one correct
			number can be entered in the space i.e more than one possible answers are possible
			
			3.Third screen contains the actual game and has a 3*3 suduko in it.
			It has 6 different options in it
				a)insert a value.
				b)delete a value.
				c)check a position.
				d)check complete suduko.
				e)solution.
				f)exit the game.
			with all those functions , user can play the game of suduko quite easily. third and fourth options are used to make 
			the game user friendly so that user can get some hints.

						
						#Algorithm#
			For this game, the program is maintaining three 2-D arrays for various operations.
			First array sudoko.a[10][10] is for interface, i.e the sudoku that the user is going to solve
			will be solved in the sudoko.a matrix. The user can insert, remove or check the elements in the matrix
			sudoko.a.
				The second array sudoko.b contains the sudoku to be solve as question in it. This requires 
			to check weather the user is removing the values given as question or not. If thats the case then it will
			gives warning to the user and retains the operation.
			another array used is sudoko.c. It consists of the complete(solved) sudoku from which we can check 
			the values entered by the user are correct or not. It is basically the most important and most useful array
			in complete matrix.
				When user starts game by entering desired difficulty level, generate function get called and a sudoku 
			get created in the sudoko.c array. The random function selects one of the fuctions [answer1 & answer2] to generate 
			sudoku. The two answer functions can create sudoku's in 2 different manner and get stored in sudoko.c array.
				Then the generate function creates a solvable sudoku in apropriate difficluty level(as given
	 		by the user) and store it in a 2-D array sudoko.b. Then this sudoku get copied in the sudoko.a array from which user  
			can access the real sudoku.
Thank You.
