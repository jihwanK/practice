def numberAmazonGoStores(rows, column, grid):
    # WRITE YOUR CODE HERE
    
    building = []
    visited = []
    several = []
    next_av = []
    
    num_stores = 0
    
    for r in range(rows):
        for c in range(column):
            if grid[r][c] == 1:
                building.append([r, c])
        
    idx = 0
        
        
    while len(visited) != len(building):
        
    
    
    while True:
        cur = building_pos[idx]
        visited.append(cur)
        
        if 0 <= cur[0]-1 < rows and 0 <= cur[1] < column and grid[cur[0]-1][cur[1]] == 1:
            next_av.append([cur[0]-1, cur[1]])
            pass
        if 0 <= cur[0]+1 < rows and 0 <= cur[1] < column and grid[cur[0]+1][cur[1]] == 1:
            next_av.append([cur[0]+1, cur[1]])
            pass
        if 0 <= cur[0] < rows and 0 <= cur[1]-1 < column and grid[cur[0]][cur[1]-1] == 1:
            next_av.append([cur[0], cur[1]-1])
            pass
        if 0 <= cur[0] < rows and 0 <= cur[1]+1 < column and grid[cur[0]][cur[1]+1] == 1:
            next_av.append([cur[0], cur[1]+1])
            pass
            