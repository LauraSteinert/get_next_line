### get_next_line
Reading a line on a fd is way too tedious. Made for 42sp.

This project reads a file, line by line, putting a '\n' at the end of each line.
For instance, if you try the first page of "Harry Potter and The Philosopher Stone", it will work perfectly. 

Now, the code itself. 

## How does it work?

The function's main use is the "read" funcion. It is with the read function that the whole program works, and it's vital to the survival of the get_next_line function. 
Basically, the read function reads whatever file you ask it to. The catch is that it reads the way it wants to. If you are planning to read the whole book of Harry Potter with the "read" function, I urge you to reconsider.

Then, what get_next_line does is to make it readable! It puts the string in a correct manner and finishes lines with the "\n".

First, we need a BUFFER_SIZE passed as a parameter. It is crucial to our function to have it, as we will call a memory allocation based on it.
The function basically copies whatever exists on the buffer (that the read passed the information to) to another variable, joins it with the rest of the strings, and then displays it at the end. 

This is a brief overview, but the core is here. 
