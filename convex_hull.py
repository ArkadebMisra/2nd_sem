
import pylab, random, math

def func_y(a, b, c):
    res = (b[1]-a[1])*(c[0]-b[0]) - (c[1]-b[1])*(b[0]-a[0]) 
  
    if res == 0:
        return 0 
    if res > 0: 
        return 1 
    return -1


def merge(left, right):
    
    i=0
    j=0
    l_s = len(left)
    r_s = len(right)
    start_i=0
    start_j=0

    for i in range(1, l_s): 
        if left[i][0] > left[start_i][0]: 
            start_i = i
    
    for i in range(1, r_s):
        if right[i][0] < right[start_j][0]: 
            start_j=i

            


    i = start_i
    j = start_j
    while func_y(left[i],right[j], right[(j+1)%r_s])<=0 or \
    func_y(right[j],left[i],left[(i-1)%l_s])>=0:
        if func_y(left[i],right[j], right[(j+1)%r_s])<=0:
            j = (j+1)%r_s
        else:
            i = (i-1)%l_s


    upper_a = i 
    upper_b = j
    

    
    i = start_i 
    j =start_j
    while func_y(left[i],right[j], right[(j-1)%r_s])>=0 or \
    func_y(right[j],left[i],left[(i+1)%l_s])<=0:
        if func_y(left[i],right[j], right[(j-1)%r_s])>=0:
            j = (j-1)%r_s
        else:
            i = (i+1)%l_s
    lower_a = i
    lower_b = j        
    
    ret = []
    ind = lower_a
    ret.append(left[lower_a]) 
    while ind != upper_a: 
        ind = (ind+1)%l_s
        ret.append(left[ind])
  
    ind = upper_b
    ret.append(right[upper_b]) 
    while ind != lower_b:
        ind = (ind+1)%r_s 
        ret.append(right[ind]) 
    return ret
    

def devide(a):
    if len(a) <= 5: 
        return brute_hull(a) 
        
    left = a[:len(a)//2]
    right = a[len(a)//2:]    

    left_hull = devide(left)
    right_hull = devide(right)
  
    return merge(left_hull, right_hull) 

def brute_hull(p):
    s = set()
    hull = []
    c_hull = []
    l_hull = []
    for i in range(len(p)):
        for j in range(i+1, len(p)):
            x1 = p[i][0]  
            y1 = p[i][1]
            x2 = p[j][0] 
            y2 = p[j][1]

            a = y2-y1 
            b = x1-x2
            c = x1*y2-y1*x2
            
            pos = 0 
            neg = 0 
            for k in range(0,len(p)):
                 
                if a*p[k][0]+b*p[k][1] <= c: 
                    neg+=1 
                if a*p[k][0]+b*p[k][1] >= c:
                    pos+=1 

            if pos == len(p) or neg == len(p): 
                s.add(p[i]) 
                s.add(p[j]) 
    for ele in s:
        hull.append(ele)
    hull.sort()
    check_y = hull[0][1]
    for e in hull:
        if e[1]>=check_y:
            c_hull.append(e)
        else:
            l_hull.append(e)
    l_hull.reverse()
    c_hull.extend(l_hull)
    return c_hull

def reorder(hull):
    c_hull = []
    l_hull = []    
    hull.sort()
    check_y = hull[0][1]
    for e in hull:
        if e[1]>=check_y:
            c_hull.append(e)
        else:
            l_hull.append(e)
    l_hull.reverse()
    c_hull.extend(l_hull)
    return c_hull

def random_points(n, r):
    low = -r
    high = r
    points = []
    p_set = set()
    for i in range(n):
        x = random.randint(low, high)
        y = random.randint(low, high)
        p = (x, y)
        p_set.add(p)
    for e in p_set:
        points.append(e)
    return points
    
# main for generated random input    
if __name__ == '__main__':
    # ~ points = random_points(100, 100)
    points = [(38, -53), (-30, 34), (80, -23), (43, -33), (45, -16), (-21, 85), (19, 51), (51, -33), (-60, -53), (45, -76), (13, 51), (84, 2), (-59, 92), (-33, 76), (26, 41), (39, -24), (66, 71), (-14, 15), (-3, 14), (-71, -61), (-97, -28), (83, -54), (30, -49), (-29, 84), (-18, 83), (-86, -21), (-58, 23), (52, -17), (90, -67), (65, -65), (-27, 41), (24, -74), (-33, -86), (41, 5), (1, -72), (-6, -58), (19, -56), (-49, -50), (84, 69), (31, 10), (68, -100), (75, 91), (-10, -46), (-100, -71), (-76, -56), (-45, 55), (-54, 73), (34, -33), (-1, -59), (-89, -98), (-68, -2), (91, 0), (4, 76), (-84, -94), (25, 91), (-15, -67), (50, -22), (48, 76), (29, -50), (31, -33), (90, -22), (14, -32), (-55, -8), (19, 100), (-39, -23), (-76, -1), (-18, 60), (-59, -16), (23, 10), (11, 44), (-73, 35), (-67, 86), (-29, 52), (8, 66), (-18, 21), (92, -19), (37, 67), (68, -30), (72, 47), (71, -93), (-25, 10), (94, -62), (87, 53), (-27, 64), (-20, -81), (-42, -78), (-51, -44), (-6, -31), (-8, -74), (-1, -44), (-95, 75), (-68, -68), (-6, -27), (8, -88), (1, -54), (80, -91), (-29, -47), (-88, -24), (43, -20), (93, -58)]
    
    print("points",points)
    n = len(points)
    points.sort()
    hull = devide(points)
    hull = reorder(hull)
    print(hull)
    pylab.figure(1)
    x = []
    y = []
    for h in hull:
        x.append(h[0])
        y.append(h[1])
    x.append(hull[0][0])
    y.append(hull[0][1])
    for p in points:
        pylab.scatter(p[0], p[1])
    pylab.plot(x, y)
    pylab.show()
    
#main for manuall input of points    
# ~ if __name__ == '__main__':
    # ~ points = []
    # ~ n = int(input())
    # ~ for i in range(n):
        # ~ p = tuple(map(int, input().rstrip().split()))
        # ~ points.append(p)
    # ~ points.sort()
    # ~ hull = devide(points)
    # ~ hull = reorder(hull)
    # ~ print(hull)
    # ~ pylab.figure(1)
    # ~ x = []
    # ~ y = []
    # ~ for h in hull:
        # ~ x.append(h[0])
        # ~ y.append(h[1])
    # ~ x.append(hull[0][0])
    # ~ y.append(hull[0][1])
    # ~ for p in points:
        # ~ pylab.scatter(p[0], p[1])
    # ~ pylab.plot(x, y)
    # ~ pylab.show()

# ~ 16 
# ~ 7 7 
# ~ 7 -7 
# ~ -7 -7 
# ~ -7 7 
# ~ 9 0 
# ~ -9 0 
# ~ 0 9 
# ~ 0 -9 
# ~ 0 0 
# ~ 1 2 
# ~ -2 1 
# ~ -1 -1 
# ~ 3 4 
# ~ 4 3 
# ~ -5 4 
# ~ 6 5
    

            
        
        
        
        
            
             

                
            
                
            
