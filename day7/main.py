#Given the mping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
#For example, the message '111' would give 3, since it could be decoded as 'aaa, 'ka', and 'ak'.

m = {}
for i in range(1,27):
    m[str(i)] = str(chr(96+i))
indexMap = []
def countNumberofWays(s):

    for i in range(len(s)):
        if (m.get(s[i]) is not None):


def main():
    #a = input("Enter string: ")
    countNumberofWays("111")
    print(m)

main()


# 
#
