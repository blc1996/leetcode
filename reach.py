def reach(sx, sy, tx, ty):
    """
    :type sx: int
    :type sy: int
    :type tx: int
    :type ty: int
    :rtype: bool
    """
    store = [[True for i in range(ty + 1)] for j in range(tx + 1)]

    def solve(tx,ty):    
        if tx<sx or ty<sy: 
            return False
        if not store[tx][ty]: return False
        if tx==sx: 
            if (ty-sy)%sx==0:
                return True
            else:
                store[tx][ty] = False
                return False
        if ty==sy: 
            if (tx-sx)%sy ==0:
                return True
            else:
                store[tx][ty] = False
                return False
        partialRes = solve(tx-ty,ty) or solve(tx,ty-tx)
        store[tx][ty] = partialRes
        return partialRes

    return solve(tx,ty)


# print(reach(1,1,3,5))
# print(reach(1,1,2,2))
print(reach(1,4,5,9))
