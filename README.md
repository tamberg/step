# Step
A simple slide stepper.

## Build the tool
On Mac or Linux.

```console
$ gcc -o step step.c
```

## Prepare slides.txt
A single text file with slides separated by '+'.

```console
+

   # Hello

   - I am @tamberg
   - Presenting slides
   - Using ./step file [dt]

+

   # Simplicity

   - This tool is minimal
   - Some lines of code
   - And a text file

+

   # ASCII-Art

   +---+    +---+
   | A |--->| B |
   +---+    +---+

+

   # Thanks

   - Seems to work
   - Get in touch :)

     @tamberg@quite.social

+
```

## Present slides.txt
In a terminal window.

> Consider increasing the font size.

```console
$ ./step slides.txt
```
