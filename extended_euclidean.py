def ext(a, b, x, y):
    if b == 0:
        x[0] = 1
        y[0] = 0
        return
    ext(b, a % b, x, y)
    temp = x[0] - a // b * y[0]
    x[0] = y[0]
    y[0] = temp

def mod_inv(a, m):
    x = [0]
    y = [0]
    ext(a, m, x, y)
    return x[0] + m if x[0] < 0 else x[0]

