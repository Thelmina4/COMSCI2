# MULTITHREADED PROGRAMMING IN PYTHON

Source material : https://ptgmedia.pearsoncmg.com/images/9780132678209/samplepages/0132678209.pdf

Directions: 
In this lab, you should aim to cover the material up to section 4.7.2:
> 4.1 / 4.2 / 4.3 (reading) (pg 157 - 163)
> 4.4 can be skimmed. In reality you will not use the _thread directly.
> 4.5 / 4.6 / 4.7 (pg 170 - 186)

His notes on the labs:
1. An easy way to transform the examples (that include line number) is to use the cut tool in unix. i.e. 
cat copied_code.py | cut -c 6- >  code_with_6_chars_removed.py
By piping the contents of 'copied_code.py' into the cut tool, and redirecting the output to another file, we can remove the first few (6 of them) offending characters from each line.

You will also need to use a python 2to3 tool, like in week 2's lab.

2. Re "Example 4-3. Using thread and Locks (mtsleepB.py)" has some indentations error starting at line 14. You will need to fix these to run the code (and use 2to3).

3. Re "Example 4-9. Book Rankings “Screenscraper” (bookrank.py)". Due to a change in the amazon http, line 18 and 19 needs to be changed to:

"
req = urllib.request.Request( '%s%s' % (AMZN, isbn), 
data=None,
headers={'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.157 Safari/537.36'})

page = urllib.request.urlopen(req)
data = page.read().decode('utf-8')
"

also, do:
"import urllib.request" instead of "from urllib2 import urlopen as uopen"


Also, this line should be changed:
AMZN = 'http://amazon.in/dp/'
This uses amazon.in instead of amazon.com (see conditions of use: https://www.amazon.in/gp/help/customer/display.html?nodeId=GLSBYFE9MGKKQXXM )


Also, some of the books in the example no longer list where they are on the best sellers list. You could use this list (or generate your own!):

ISBNs = {
'9390166268': 'The Psychology of Money',
'9389053730': '1984',
'0857863517':'The True Adventures of the Rolling Stones'
}

and

change the REGEX line to:
REGEX = compile('#([\\d,]+) in Books ')

Note, amazon might refuse your request thinking that your a bot because you're in a lab with a lot of other people using the same request/user-agent! Print the content of data (and pipe to a file) if you are unsure.

You will need to remain "_main" to "main"

If stuck, I've placed a modified version of the code with the filename "4_9.py" on this week's Loop page.

4. Re "4.7.3. Locking Example", for the first example, you will have better success in getting errant behaviour from the program by having a shorter random sample of sleep times, like so:
"loops = (randrange(1,3)/1000. for x in range(randrange(5,7)))"
(and you should run it a number of times and carefully inspect the output to observe the variety of race conditions that happen)

If using python3, you will need to change xrange -> range
and
You will need to remain "_main" to "main"

Exercises:
I will freely conceive that some of the exercises below are contrived however they are designed as learning tools.

Threaded Factorial
the factorial of a given number is given by:

`n! = N*(n-1)!`

Or:

`Factorial of N is N * factorial(n-1)`

Write a program which calculates the factorial of a given number.  Once you are sure that it works, write a program which calculates the factorial of three different numbers.  You may do this initially as a single-threaded application, but then put each calculation into its own thread.  Using big numbers, check whether there is any noticeable increase or decrease in speed as a result of adding in the extra threads.

now think about this a bit. Supposing you wanted to calculate the factorial of a _very_ big number. You have multiple cores at your disposal.   think about the following:

1. Will a recursive solution work well for this situation if you need to use multiple threads?
2. If it does work, why?
3. If it doesn't work, why not and what would you do to overcome the issues you have identified?

A lot of this module isn't about coding, so work with someone in your class to identify the issues and arrive at a solution.


If you modify the code such that it uses the multi processing, rather than the multithreading  module, will there be a difference in running time? Why? How are you comparing efficiency?  (note that this is an optional exercise and you can feel free not to do it if you don't wish to).

# Order of Creation
As one program leads into the other, I need to note the order of creation

1. onethr.py
2. mtsleepA.py
3. mtsleepB.py
4. mtsleepC.py
5. mtsleepD.py
6. mtsleepE.py
7. myThread.py
8. mtfacfib.py
9. bookrank.py
Still to do
10. 
11. 
12. 