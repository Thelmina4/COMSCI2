from atexit import register
from re import compile
from threading import Thread
from time import ctime
#from urllib2 import urlopen as uopen
import urllib.request


REGEX = compile('#([\\d,]+) in Books ')
AMZN = 'http://www.amazon.in/dp/'

ISBNs = {
'9390166268': 'The Psychology of Money',
'9389053730': '1984',
'0857863517':'The True Adventures of the Rolling Stones'
}

def getRanking(isbn):
    req = urllib.request.Request( '%s%s' % (AMZN, isbn), 
        data=None,
        headers={'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/14.0.3 Safari/605.1.15'})

    page = urllib.request.urlopen(req)
    data = page.read().decode('utf-8')
    #print("data is\n", data)

    page.close()
    return REGEX.findall(data)[0]

def _showRanking(isbn):
    print('- %r ranked %s' % (
        ISBNs[isbn], getRanking(isbn)) )

def main():
    print('At', ctime(), 'on Amazon...')
    for isbn in ISBNs:
        print("looking up", isbn)
        _showRanking(isbn)

@register
def _atexit():
    print('all DONE at:', ctime())

if __name__ == '__main__':
    main()