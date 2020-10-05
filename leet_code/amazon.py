import pdb

def minimumDays(rows, columns, grid):
    # WRITE YOUR CODE HERE
    outdated = []
    updated = []
    days = 0
    
    for i in range(rows):
        for j in range(columns):
            if grid[i][j] == 0:
                outdated.append([i, j])
            else:
                updated.append([i, j])

    if len(updated) == 0:
        return -1

    while len(outdated) != 0:
        days += 1
        
        if days > 1000:
            return -1
        
        for o in outdated:
            if 0 <= o[0]-1 < rows and 0 <= o[1] < columns and grid[o[0]-1][o[1]] == 1:
                updated.append(o)
            if 0 <= o[0]+1 < rows and 0 <= o[1] < columns and grid[o[0]+1][o[1]] == 1:
                updated.append(o)
            if 0 <= o[0] < rows and 0 <= o[1]-1 < columns and grid[o[0]][o[1]-1] == 1:
                updated.append(o)
            if 0 <= o[0] < rows and 0 <= o[1]+1 < columns and grid[o[0]][o[1]+1] == 1:
                updated.append(o)
        
        for u in updated:
            grid[u[0]][u[1]] = 1
            if u in outdated:
                outdated.remove(u)
                
        print(grid)
    return days

g = [[0,1,1,0,1], [0,1,0,1,0], [0,0,0,0,1], [0,1,0,0,0]]
print(minimumDays(4,5,g))