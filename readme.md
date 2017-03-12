# hdump

Took an example simple program that creates a Hex and Ascii dump of a text file.

Original code from [modified from http://simplestcodings.blogspot.ca/2010/08/hex-dump-file-in-c.html](modified from http://simplestcodings.blogspot.ca/2010/08/hex-dump-file-in-c.html)

* I felt the code could be much more readable. I made changes to improve readability.
* tested on unbuntu linux. Used code::blocks to build code.

## Example Use on Linux System

~~~~bash
(tlxde)danp@localhost:~/project/hdump/bin/Release$ cat file.txt
This is a test file.
1234567890123456
end
(tlxde)danp@localhost:~/project/hdump/bin/Release$ ./hdump file.txt

	Hex dump of file.txt

 54 68 69 73 20 69 73 20 61 20 74 65 73 74 20 66   This is a test f
 69 6C 65 2E 0A 31 32 33 34 35 36 37 38 39 30 31   ile..12345678901
 32 33 34 35 36 0A 65 6E 64 0A                     23456.end.
(tlxde)danp@localhost:~/project/hdump/bin/Release$ 
~~~~
