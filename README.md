# Step
A simple slide stepper, to present text in your terminal.

## Build the tool
On Mac or Linux.

```console
$ gcc -o step step.c
```

## Prepare slides.txt
Create a single text file with slides separated by '+', e.g. [slides.txt](slides.txt)

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
Step through the slides, in a terminal window.

> Consider increasing the font size.

```console
$ ./step slides.txt
```

<img width="540" alt="A terminal window showing a single slide" src="https://github.com/user-attachments/assets/abc10410-3084-4fd3-9f3b-72a63b98d367" />

