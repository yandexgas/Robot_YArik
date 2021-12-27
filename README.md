# Robot_YArik
Interpreter for a simple cellular robot programming language.


A system for controlling a robot moving through a labyrinth. The maze cell is in the shape of a square. (can be formally used as a programming language).
The robot can move to an adjacent cell if there is no obstacle in it.
# File structure:
1) ".yar" files
  - Files containing executable code. The program is written in files with this extension.
2) ".vkl" files
  - Inclusion files. The names of the .yar files (paths to them) that will be attached to the main program file are listed here. File names can be listed with newlines or spaces.
#### Note: in fact, no check has been added yet that this file contains .yar files. In fact, both its structure and implementation at this stage are very mediocre and primitive, but for now this is enough to implement the main functionality.
3) ".env " files (example of file formatting: see "Area.env")
- Robot and maze configuration files. The first line contains 2 non-negative integers separated by commas, without spaces - the dimensions of the maze.
After that, from the next line, a map of the maze is drawn using the following symbols:
- \# — is an obstacle.
- . — an empty cell (in fact, it can be designated in the file by any unoccupied character, including a space);
- O — exit from the maze (should be 1);
- ^ — initial position of the robot (initial rotation is always forward)
#### Note:
All cells of the maze must be filled. That is, if the maze is 12x10
then you should have 12 lines containing 10 characters each.
#### ATTENTION:
At the moment, it is not provided to check the correctness of filling the maze, and in case of deviation from the established rules, the cells may move out and the result will be different. If the position of the robot is not specified, then by default its coordinates are 0, 0 (upper left corner).

4) .temp.yar.vkl files
- Temporary files are the result of building a project with inclusions.After the end of the program is deleted, (if not deleted it will be overwritten the next time you start)
#### Note: 
In the near future these files will no longer be temporary and will be converted to .sbor files containing information about the main program, inclusions and maze. This will solve 2 problems: you will not need to write 3 arguments each time on the command line, if you have already built the program in the required configuration once; will make it easier to find errors, because at the moment the line number containing the syntax error or run-time error is exactly the line number in this temporary file. If the program contains inclusions, then naturally, the line will not coincide in number with the corresponding line in one of the source files.
# How to start.
- Build an .exe file from a Visual studio project (you just need to clone the repository, open the project in Visual Studio and build in Release mode.)
- Build the project using the Make build system (Make - the file will be attached to the repository later, the one that is there now is outdated, they will soon get their hands on and I will fix it.)
> ## Attention: at the moment the interpreter is supported only for OS Windows. So far, the project cannot be built for Linux. As soon as the main work is completed, the code will be adapted to run on Linux.
- The launch can be in several modes:
1) Development environment mode
Just run the .exe file from the console, or by mouse click.
You will see a menu with a proposal to enter the name of the program file and then the text of the program. When finished, enter ctrl + Z. The program text will be saved in the \<name>.yar file.
Then you will be prompted to select an existing .vkl file (a file that contains the names of the program files that should be included in the current one. There may be function declarations or executable code.) The files are included in that order. If there is no such file, but you want to create it, press ctrl + Z and enter the names of the files that you want to include in the project (along with the .yar extensions) separated by a space, press ctrl + Z when finished;
Attention: multiple inclusion of files will cause a collector error, a message about which will be displayed in the console.

2) Startup mode without switching on
Start the interpreter through the console and supply the name of the .yar file (without extension) that you want to execute in the command line parameters

3) Startup mode with inclusions
Similar to the second mode, pass one more command line parameter - the name of the .vkl file (without the extension).
#### Note: In case of any errors in the startup arguments, you will be prompted to re-enter them. Don't worry, no files will be overwritten without your consent (probably :))

4) Launch mode with maze
Pass the name of the .env file (no extension) as the third command line parameter. The IDE does not support the creation of .env files, so in case of any error, the program will not start, but will display a warning message.
#### Note: It is obvious that the need to write some kind of .vkl file in order to connect the maze later, even if you do not need .vkl, is a logical design error. It will be fixed soon.
#### Note 2: all included programs are located in the same scope. Empty files can also be "included".
# Formal language for describing the robot's actions:
(formally it can be used as a programming language)

# The following literals are supported
- Boolean "istino" and "lozhno", boolean constants and expressions are converted to signed integers as 1 and 0, respectively. 0 converts to "lozhno", any other number to "istiono".
- Signed integer literals in decimal format
- Floating point numbers (exponential format not supported yet)
- Character literals '\<character>', such as 'a' or '\ n'
- String literals "\<string>". Special characters such as '\ n' in string literals are not yet supported. The string literal is converted to a one-dimensional character array terminated with '\ 0'


# Variable declarations in the following format:
Variable names must start with a letter or an underscore, after which they can contain numbers, letters and underscores in any number, the names must not coincide with the reserved words of the language, variables and functions declared with the same name in the same scope. The names can be the same as variables and functions declared in the wider global scope, but in this case, the corresponding members of the global scope will not be accessed from the current scope.
- Signed integer variable tseloye \<variable name> [= \<arithmetic expression>]
 > Example: tseloe i_ = 5 + 5
- Variable of type floating point drobnoye \<variable name> [= \<arithmetic expression>]
> Example: drobnoye i_ = 5.0 / 2
- Boolean variable logicheskoye \<variable name> [= \<logical expression>]
> Example: logicheskoye i_ = istino
- One-byte signed variable simvol \<variable name> [= <arithmetic expression>]
> Example: simvol i_ = 'a' + 2
  > #### Note: all arithmetic types can be converted to each other (possibly with loss of precision). During operations, if at least one operand is a fractional number, then  all              operands are converted to the "drobnoye" type, otherwise to the "tseloye" type.

- Square cell of space
yacheyka \<variable name> = {\<arithmetic expression X-coordinate>, \<arithmetic expression Y-coordinate>, \<logical expression sign of being occupied by an obstacle>}
yacheyka \<variable name> = \<expression like "yacheyka" (copy initialization)>
  #### Example:
              yacheyka y1 = {1, 2, lozhno};
              yacheyka y2 = y1;
- Cell properties can be accessed using the "=>" operator
\<expression of cell type> => \<cell field name (x, y, busy)>
  #### Example:
                y1 => x = 5;
                y2 => y = y2 => x;

- Array
massiv \<array name> = {\<arithmetic expression: dimension in space 1>, \<arithmetic expression: dimension in space 2>, .....>}
massiv \<array name> = \<expression that is an array> (copy initialization, new array and copied are independent)
  #### Example:
              massiv m1 = {1,2,55,1};
              massiv m2 = m1;
> #### Note: An array is polymorphic and can simultaneously store elements of any type, including other arrays.
- Accessing an element of an array:
\<array type expression> [element index in space 1, element index in space 2, ...]
  #### Example:
            m [1, 2, 4] = "2atw"; // We enter a string into an element of the array (it is represented by an array).
            m [1,2,4] [1] = 'g'; // We get the input string from the same array element and replace the first character of the string.
> #### Note: Array elements are not initialized when declared. An attempt to read an uninitialized value will generate an error.
- Operator for getting the dimension of an array:
(determines the number of dimensions in the array)
razmer \<expression - array>.
- Pointer
  
ukazatel \<type name> \<variable name> [= \<expression of type pointer to a given type>]
  #### Example:
            ukazatel tseloye u;
            ukazatel tseloye y = u;
            ukazatel drobnoye z = y; // Error! pointer types do not match.
> #### Note: if a value was not assigned to the pointer during initialization, then memory is dynamically allocated for the required element type. (it is cleared if the pointer value is subsequently changed).
> #### Note 2: it is not possible to create a pointer to a pointer, this will be an error.
> #### Note 3: it is not possible to create a pointer to an array element. Since pointers are strongly typed, and in the general case it is impossible to know in advance what type of element will be in the array, the possibility of creating a pointer to an array would give a chance to bypass the strict typing of a pointer if a different type is subsequently introduced into the array element.

>> Strong typing is applied. If no conversion is defined, then it is an error.
# Language operators:

- Type comparison operator: proverka \<type name>/\<variable name>/\<expression> \<type name>/\<variable name>/\<expression>
#### Example:
      proverka i slovo;
      proverka 5 tseloye;
- The assignment operator '=' (copies data.Converts to desired type if conversion is defined)

- Arithmetic operators (defined only for arithmetic and boolean types): +, -, *, /, unary minus
-Logic operators (defined only for arithmetic and boolean types): &&, ||, <,>, ~ (inversion)

## Loop operators:
- Loop with constant step
tsikl (\<expression 1>: \<expression 2>) nachalo \<set of language sentences> konets
tsikl (\<variable declaration>: \<expression 2>) nachalo \<set of language sentences> konets
> #### Note: if there is only one sentence in the body of the cycle, then the beginning and the end can be omitted. The right-hand expression of the loop is evaluated at the initialization stage of the loop and cannot be changed.
#### Example:
        tsikl (5: 8); // will run for 5, 6, 7 and 8
        tsikl (y: 9); // if y is an arithmetic type it will be executed for y, ... 9
        tsikl (tseloye y = 5: 10) // the body of the loop is a separate scope, variables declared in the loop invariant can be overridden in it.

- Loop with condition
poka (\<boolean expression>) nachalo \<set of language sentences> konets
> #### Note: if there is only one sentence in the body of the loop, then the beginning and end can be omitted.
#### Example:
        poka (x <5);
        poka (5) // endless loop
> #### Note: The body of the loop is a separate scope.

- Conditional operator 
    ##### DECLARATION:
          esli (<boolean expression>)
          nachalo
          <set of language suggestions>
          konets
          [inache (<boolean expression>) nachalo
          <set of language suggestions>
          konets ]
  
> #### Note: if there is only one sentence between the beginning and the end, then the beginning and the end can be omitted. The bodies of both operator branches are separate scopes.
## ROBOT CONTROL OPERATORS
- Moving one cell in a given direction relative to the current "idi-> pered" - forward, "idi -> zad" - backward, "idi-> left" - to the left, "idi-> pravo" - right. If the robot encounters an obstacle, then it breaks down and the program ends (there is no one to execute it :))
- Turn relative to the current direction "poverni -> levo" - turn left,
"poverni -> pravo" - turn right. The reversal back and forth is undefined and is an error.
- Measuring the distance to the first obstacle in the given direction "smotri -> \<direction>". Returns the length - an integer.
> #### Note: the robot's actions can be specified by a sequence of operators separated by the "->" symbol. (If the last operator in the chain is a distance measurement, then the            whole chain returns an integer - the distance).

- The robot can take off and fly over one obstacle operator "vzleti -> \<robot control operator>". When the robot is in flight, the distance measurement ignores the obstacle in the cage next to the robot. When performing a movement in the air, the robot will move 1 cell if there are no obstacles in the given direction and 2 if there are any. (keep in mind that if there are two obstacles in a row, then having flown over the first, he will crash into the second).
After making a movement, the robot lands.
#### Example:
        vzleti-> poverni-> levo-> smotri-> pered-> idi-> pered;
> #### Note: instead of the words "pered, zad, levo, pravo" their analogs with the prefixes "v" and "on" can be used

- An operator is defined to interrupt a sequence of operators, if the operator of the survey has found an obstacle in an adjacent cell. "ostanov"
#### Example:
        idi-> vpered-> smotri-> nalevo-> ostanov-> idi-> nalevo; // if smotri-> levo returned 0, then the chain will be interrupted, otherwise it will continue and the robot             will take a step to the left.

- The operator for getting the current location of the robot "gdeya?" - returns an object - a cell of space with the coordinates of the robot. It also clears the console and prints the current state of the maze.
# FUNCTIONS:
- Function descriptor
[\<return type>] funktsiya <function name> (\<first argument type> \<first argument name>, [\<second argument type> \<second argument name> ,....]) nachalo \ <function body> konets
 > The function is in its own scope. Parameters are passed by value (however, parameters can be pointers), the result is returned by value (however, a pointer to the memory        allocated inside the function can be returned.)
            
 > A function can be declared anywhere in the program, including inside the body of a loop or other function, then this function will be local.
            
 > If the types of the parameters passed to the function do not exactly match the types of the arguments when declared, they will be automatically converted to the required   types, if possible, otherwise - an error: There are no functions that accept such parameters.
            
 > If the function returns a value, then the built-in variable "rezultat" has the type of the function's result defined in it. Inside a function, you can work with it as with a regular variable, and upon completion of the function, the value of this variable will be returned (the function is not interrupted when using this variable, so that temporary results of calculations can be stored there). If this variable has not been assigned a value inside the function, then it will return the default value for the corresponding data type. (A little later, I think to still make it a mistake to protect against inattentive errors.)
> Recursive function calls allowed.
> Function names must start with a letter or an underscore, after which they can contain numbers, letters and underscores in any number, the names must not coincide with the reserved words of the language, variables and functions declared with the same name in the same scope .The names can be the same as variables and functions declared in the wider global scope, but in this case, the corresponding members of the global scope will not be accessed from the current scope.
  # Function decklaration examples: 
       
            simvol funktsiya f1(ukazatel tseloye i) nachalo
              tsikl(*i : 10) nachalo
                  rezultat = rezultat + *i;  // a result variable is declared by default for functions that return a value and cannot be overridden.
              konets
              rezultat = rezultat - 'a';
            konets
            
           funktsiya f1(tseloye i) nachalo
              tsikl(i : 10) nachalo
                  rezultat = rezultat + *i;  // In this case, the function does not return a value, the result variable is not declared by default, 
                                            //so an error will occur. 
                                           //The result variable can be declared explicitly, but it will be the most common variable and the function will not return its value.
              konets
              rezultat = rezultat - 'a';
            konets
            
#### Note: the name of the variable declared in the body of the function, as well as the name of the function parameter, may coincide with the name of the function, but in this case, it will be impossible to call this function or any of its overloads inside this function by name.
### Function overloading is defined according to the following rules:
1. In the local scope, a function with a prototype EXACTLY matching the passed parameters is searched for.- In a more global scope, a function with a prototype EXACTLY matching the passed parameters is searched for until a function is found, or the global scope is checked.
2. In the local scope, a function with a prototype is searched for from parameters into which the passed types can be converted. (attention! if there are several such functions, then this will result in undefined behavior, however, if you delve into the implementation of the interpreter, you can understand that the most recent function declared in this scope with a suitable prototype will take precedence.)
3. Similar rules are used to search for a function in more global scopes sequentially.
4. If the required prototype was not found, it is an error.

### Function call operator: 
\<function name> (\<expression 1>, ....) 
 - The function call can be anywhere in the program (including before the declaration).
> #### ATTENTION: Program execution starts from the first executable command. It should be noted that when declared, the function is not executed and is not the point of entry into the program.
## Standard library functions:
At the moment, the standard library is under development and it will be split into 2 parts:
- A compiled part written in C ++ (to provide the language with access to those functions that are not included in it, for example, working with the console and files)
- An interpreted part written in this language, connected via ".vkl file" for the necessary functions for which performance is not important and there is everything you need to implement in the language.(temporarily functions for working with strings will be implemented here, but later will be rewritten in C ++)

### == Current standard library functions ==

- logicheskoye chitaem (\<pointer to cell or arithmetic type expression>)
 > Reads an expression of the specified type from the console. To read a cell, the text in the console must be entered in accordance with a regular expression
"[{][ \t]*([0-9]+)[ \t]*,[ \t]*([0-9]+)[ \t]*,[ \t]*(istino|lozhno)[ \t]*[}]"
Returns "lozhno" if there was an error while typing.

- void pechataem (\<expression of arithmetic type or cell>)
> Displays the value of the passed expression. Expressions like simvol are output according to the ascii table
