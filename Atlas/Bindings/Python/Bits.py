import string

def bits2string(str):
    """convert binary digit string "0 10000100 11010100000000000000000"
       into actual binary format "Bj  " 
    """
    #remove space
    str = string.replace(str," ","")
    mod8 = len(str)%8
    if mod8:
        str = str + "0" * (8 - mod8)
    res = ""
    #handle one byte at time
    #use reverse order for Intel
    #for 32 bit numerbs i will have values from this list: [24, 16, 8, 0]
    for i in range(len(str)-8,-8,-8):
        byte = 0 #as integer now
        multiple = 1 #start from 2**0
        segment = list(str[i:i+8])
        segment.reverse()
        for digit in segment:
            byte = byte + multiple * int(digit)
            multiple = multiple * 2
        res = res + chr(byte)
    return res

def string2bits(str):
    """convert machine string represenation to string digit reperesentation"""
    res = ""
    byte_lst = list(str)
    byte_lst.reverse()
    for byte in byte_lst:
        num = ord(byte)
        for i in range(8-1,-1,-1):
            bit = num & 2**i
            if bit: bit = 1
            res = res + `bit`
    return res

class Bits:
    def __init__(self, bits=[]):
        self.bits=bits[:]
    def append(self, bit):
        self.bits.append(bit)
    def __add__(self, other):
        return Bits(self.bits + other.bits)
    def __str__(self):
        return string.join(map(str,self.bits),"")
    def __repr__(self):
        return bits2string(str(self))

if __name__=="__main__":
    b = Bits()
    b.append(0)
    b.append(1)
    b.append(0)
    b.append(0)
    b.append(1)
    b.append(0)
    b.append(1)
    b.append(0)
    b.append(1)
    b.append(0)
    b.append(1)
    b.append(0)
    b.append(1)
