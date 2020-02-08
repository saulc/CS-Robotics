
import time
from math import pi, cos, sin, tan

#test program to visulaize led sequences.

class leds:
    num = 33
    mindelay = 3
    modedelay = 333

    def test(self, c):

        temp = ''
        for i in range(0, self.num):
            for n in c:
                if i == n:
                    temp += 'X'
                else: temp +='.'
        print(temp)


def deg(rad):
    return rad/pi

def rad(deg):
    return pi * deg/180



l = leds()

r = 1 * 180
mid = l.num//2
mid = int(mid)
for i in range(0, r):
    v = -sin(rad(i)) * mid + mid
    v = int(v)
    x = sin(rad(i)) * mid + mid
    x = int(x)
    # print( str(i) + " : cos: " + str(cos(rad(i)) ) + " v: " + str(v) )
    l.test([v, x])
    time.sleep(.01)


#
# mid = l.num/2 - 1
# mid = int(mid)
# for i in range(0, mid+2):
#     l.test([mid - i, mid+i])
#     time.sleep(.1)

# for i in range(0, l.num):
#     l.test(i)
#     time.sleep(.3)
#
# for i in range(0, l.num):
#     l.test(l.num - i)
#     time.sleep(.3)


#
# void setColor(uint32_t c, uint8_t wait) {
#   int mid = strip.numPixels()/2;
#   for(uint16_t i=0; i<mid; i++) {
#     strip.setPixelColor(mid + i, c);
#     strip.setPixelColor(mid - i, c);
#     strip.show();
#     delay(wait);
#   }
# }
